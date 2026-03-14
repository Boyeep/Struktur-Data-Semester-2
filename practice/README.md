# Practice Folder

Focusing on Modul 1 topics that includes both basic and harder practice.

Basic files:
- `01_pointers_basics.cpp`: pointer declaration, dereference, address printing
- `02_pass_by_value_vs_reference.cpp`: value vs reference in C++
- `04_vector_basics.cpp`: vector operations and basic data handling
- `13_manual_dynamic_array.cpp`: dynamic array implementation using `new[]` and `delete[]`
- `15_iterator_basics.cpp`: forward, reverse, and const iterator usage on `vector`
- `16_singly_linked_list.cpp`: singly linked list with insert, delete, search, print
- `09_text_editor_simulation.cpp`: stack-based command simulation
- `11_macaron_stack_simulation.cpp`: stack manipulation exercise
- `14_customer_queue_simulation.cpp`: queue rotation simulation
- `17_deque_basics.cpp`: deque commands using front and back operations
- `18_priority_queue_list_based.cpp`: priority queue built with a linked list
- `10_activity_priority_queue.cpp`: priority queue usage with filtering and ordering
- `12_food_collision_priority_queue.cpp`: repeated max-priority processing

Harder files:
- `19_pointer_array_reverse.cpp`: reverse an array using only pointers and helper functions
- `20_function_pointer_calculator.cpp`: function-pointer based calculator dispatch
- `30_pointer_with_function.cpp`: pointer parameters, pointer arithmetic, and array processing through functions
- `21_linked_list_advanced.cpp`: delete by value, reverse list, find middle node
- `22_deque_reversal_simulation.cpp`: deque operations with lazy reverse logic
- `23_stack_balanced_brackets.cpp`: balanced bracket checking with stack
- `24_queue_two_lines_simulation.cpp`: two-queue service simulation
- `25_priority_queue_list_advanced.cpp`: list-based priority queue with priority updates
- `26_doubly_linked_list.cpp`: doubly linked list with forward/backward traversal
- `27_circular_queue.cpp`: fixed-size circular queue implementation
- `28_infix_to_postfix.cpp`: operator stack conversion from infix to postfix
- `29_browser_history_simulation.cpp`: back/forward navigation using two stacks

Focused stack, queue, deque files:
- `31_stack_min_query.cpp`: stack with constant-time minimum queries
- `32_queue_using_two_stacks.cpp`: queue implementation using two stacks
- `33_deque_sliding_window_max.cpp`: deque for sliding window maximum
- `34_deque_service_simulation.cpp`: double-ended service simulation with lazy reverse
- `35_queue_priority_line_simulation.cpp`: two-level queue simulation with normal and priority lines

Supporting files:
- `03_array_sum_with_pointers.cpp`: array traversal using pointer arithmetic
- `05_recursive_factorial.cpp`: recursion practice
- `06_recursive_power.cpp`: recursion practice
- `07_prime_numbers_in_range.cpp`: looping and helper functions
- `08_binary_search.cpp`: searching on sorted data

All files are standalone and can be compiled individually.
Example:
`g++ practice/28_infix_to_postfix.cpp -std=c++17 -o practice/infix_postfix`
