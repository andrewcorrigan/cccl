#include <cub/device/device_merge_sort.cuh>

#include <nvbench_helper.cuh>

// %RANGE% TUNE_TRANSPOSE trp 0:1:1
// %RANGE% TUNE_LOAD ld 0:2:1
// %RANGE% TUNE_ITEMS_PER_THREAD ipt 7:24:1
// %RANGE% TUNE_THREADS_PER_BLOCK_POW2 tpb 6:10:1

#ifndef TUNE_BASE
#define TUNE_THREADS_PER_BLOCK (1 << TUNE_THREADS_PER_BLOCK_POW2)
#endif // TUNE_BASE

using value_t = cub::NullType;

#if !TUNE_BASE

#if TUNE_TRANSPOSE == 0
#define TUNE_LOAD_ALGORITHM cub::BLOCK_LOAD_DIRECT
#define TUNE_STORE_ALGORITHM cub::BLOCK_STORE_DIRECT
#else // TUNE_TRANSPOSE == 1
#define TUNE_LOAD_ALGORITHM cub::BLOCK_LOAD_WARP_TRANSPOSE
#define TUNE_STORE_ALGORITHM cub::BLOCK_STORE_WARP_TRANSPOSE
#endif // TUNE_TRANSPOSE

#if TUNE_LOAD == 0
#define TUNE_LOAD_MODIFIER cub::LOAD_DEFAULT
#elif TUNE_LOAD == 1
#define TUNE_LOAD_MODIFIER cub::LOAD_LDG
#else // TUNE_LOAD == 2
#define TUNE_LOAD_MODIFIER cub::LOAD_CA
#endif // TUNE_LOAD 

template <typename KeyT>
struct policy_hub_t
{
  struct policy_t : cub::ChainedPolicy<300, policy_t, policy_t>
  {
    using MergeSortPolicy =
      cub::AgentMergeSortPolicy<TUNE_THREADS_PER_BLOCK,
                                cub::Nominal4BItemsToItems<KeyT>(TUNE_ITEMS_PER_THREAD),
                                TUNE_LOAD_ALGORITHM,
                                TUNE_LOAD_MODIFIER,
                                TUNE_STORE_ALGORITHM>;
  };

  using MaxPolicy = policy_t;
};
#endif // !TUNE_BASE

template <typename T, typename OffsetT>
void merge_sort_keys(nvbench::state &state, nvbench::type_list<T, OffsetT>)
{
  using key_t            = T;
  using value_t          = cub::NullType;
  using key_input_it_t   = key_t *;
  using value_input_it_t = value_t *;
  using key_it_t         = key_t *;
  using value_it_t       = value_t *;
  using offset_t         = OffsetT;
  using compare_op_t     = less_t;

#if !TUNE_BASE
  using policy_t   = policy_hub_t<key_t>;
  using dispatch_t = cub::DispatchMergeSort<key_input_it_t,
                                            value_input_it_t,
                                            key_it_t,
                                            value_it_t,
                                            offset_t,
                                            compare_op_t,
                                            policy_t>;
#else // TUNE_BASE
  using dispatch_t = cub::
    DispatchMergeSort<key_input_it_t, value_input_it_t, key_it_t, value_it_t, offset_t, compare_op_t>;
#endif // TUNE_BASE

  // Retrieve axis parameters
  const auto elements       = static_cast<std::size_t>(state.get_int64("Elements{io}"));
  const bit_entropy entropy = str_to_entropy(state.get_string("Entropy"));

  thrust::device_vector<T> buffer_1(elements);
  thrust::device_vector<T> buffer_2(elements);

  gen(seed_t{}, buffer_1, entropy);

  key_t *d_buffer_1 = thrust::raw_pointer_cast(buffer_1.data());
  key_t *d_buffer_2 = thrust::raw_pointer_cast(buffer_2.data());

  // Enable throughput calculations and add "Size" column to results.
  state.add_element_count(elements);
  state.add_global_memory_reads<T>(elements, "Size");
  state.add_global_memory_writes<T>(elements);

  // Allocate temporary storage:
  std::size_t temp_size{};
  dispatch_t::Dispatch(nullptr,
                       temp_size,
                       d_buffer_1,
                       nullptr,
                       d_buffer_2,
                       nullptr,
                       static_cast<offset_t>(elements),
                       compare_op_t{},
                       0 /* stream */);

  thrust::device_vector<nvbench::uint8_t> temp(temp_size);
  auto *temp_storage = thrust::raw_pointer_cast(temp.data());

  report_entropy(buffer_1, entropy);

  state.exec([&](nvbench::launch &launch) {
    dispatch_t::Dispatch(temp_storage,
                         temp_size,
                         d_buffer_1,
                         nullptr,
                         d_buffer_2,
                         nullptr,
                         static_cast<offset_t>(elements),
                         compare_op_t{},
                         launch.get_stream());
  });
}

NVBENCH_BENCH_TYPES(merge_sort_keys, NVBENCH_TYPE_AXES(all_types, offset_types))
  .set_name("cub::DeviceMergeSort::SortKeys")
  .set_type_axes_names({"T{ct}", "OffsetT{ct}"})
  .add_int64_power_of_two_axis("Elements{io}", nvbench::range(16, 28, 4))
  .add_string_axis("Entropy", {"1.000", "0.201"});
