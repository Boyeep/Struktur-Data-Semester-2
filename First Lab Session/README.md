# First Lab Session Notes

This file summarizes `Soal_1.cpp` until `Soal_6.cpp`.

For each problem, this README explains:
- what the problem is asking
- what data structure is used
- how the solution works
- the main idea behind the approach

## Soal 1

File: [Soal_1.cpp](/c:/Users/asus/OneDrive/Desktop/Data%20Structure%20Practice/First%20Lab%20Session/Soal_1.cpp)

### Problem summary

The program simulates a simple text editor with three commands:
- `WRITE kata`: add a word to the sentence
- `BACKSPACE`: remove the last written word
- `PRINT`: print the current sentence

### Data structure used

- `vector<string>`

### Why this works

This problem behaves like a growing and shrinking container:
- adding a word happens at the end
- deleting also happens at the end

A `vector` fits this well because:
- `push_back` adds a new word quickly
- `pop_back` removes the last word quickly

### Solution idea

The code stores each written word inside `Kalimat`.

When:
- `WRITE` appears, the new word is pushed into the vector
- `BACKSPACE` appears, the last word is removed if the vector is not empty
- `PRINT` appears, all stored words are printed in order

### Thought process

The first question is: what part of the sentence changes?  
Only the last inserted word is removed by `BACKSPACE`, so this is an "add at end, remove at end" pattern.

That immediately suggests using:
- `vector`
- or `stack`

The implementation uses `vector` because it is simple and still preserves the original order for printing.

## Soal 2

File: [Soal_2.cpp](/c:/Users/asus/OneDrive/Desktop/Data%20Structure%20Practice/First%20Lab%20Session/Soal_2.cpp)

### Problem summary

Based on the code, the input contains:
- a priority number
- an activity string

If the activity contains `"seru-seruan"`, it is ignored.  
Otherwise, the activity is stored and later printed from highest priority to lowest priority.

### Data structure used

- `priority_queue<pair<int, string>>`

### Why this works

The problem needs the activities to come out in priority order, not in input order.

A `priority_queue` is appropriate because:
- inserting is easy
- taking the highest priority item is direct through `top()`

### Solution idea

For each activity:
- read the priority number
- read the full activity text
- check whether it contains the banned substring `"seru-seruan"`
- if it does not, push `(priority, activity)` into the heap

Then:
- while the heap is not empty
- print the activity at the top

### Thought process

The main clue is the priority value.  
Whenever a problem asks for "largest first" or "highest priority first", `priority_queue` is usually the cleanest tool.

The code also needs substring filtering, so `string::find` is used before the data is inserted into the heap.

## Soal 3

File: [Soal_3.cpp](/c:/Users/asus/OneDrive/Desktop/Data%20Structure%20Practice/First%20Lab%20Session/Soal_3.cpp)

### Problem summary

There are two macaron stacks:
- the main stack
- the second stack

Commands:
- `PULL x`: take the `x`-th macaron from the top of the main stack and move it to the second stack
- `PUT`: return all macarons from the second stack back to the main stack
- any unknown command prints an error message

At the end, both stacks are printed from bottom to top.

### Data structures used

- `stack<char>` for the main stack
- `stack<char>` for the second stack
- `queue<char>` as temporary storage during `PULL`

### Why this works

This problem is naturally about stacks:
- only the top is directly accessible
- `PULL x` requires lifting some items from the top
- `PUT` returns items from the top of the second stack back to the main stack

The temporary `queue` is used to restore the lifted macarons in the same removal order, which causes their order on the main stack to become reversed.

### Solution idea

For `PULL x`:
1. Check whether `x` is larger than the current size of the main stack.
2. If yes, print the message `"Macaron Furina tidak sebanyak itu pls!"`
3. Otherwise, move the top `x - 1` macarons into a temporary queue.
4. Move the next macaron into the second stack.
5. Return the temporary macarons back to the main stack.

For `PUT`:
- move everything from the second stack back into the main stack

For printing:
- copy the stack
- pop all items into a vector
- print the vector backwards so the output becomes bottom to top

### Thought process

The tricky part here is not the stacks themselves, but the exact order after `PULL`.

The important observation is:
- the problem statement says the items above the target are put back in reversed order

That means we cannot simply pop and push them back with another stack.  
Using a queue preserves the removal order, and when those items are pushed back onto the main stack, the resulting stack order becomes reversed exactly as required.

## Soal 4

File: [Soal_4.cpp](/c:/Users/asus/OneDrive/Desktop/Data%20Structure%20Practice/First%20Lab%20Session/Soal_4.cpp)

### Problem summary

This is the food-weight problem:
- repeatedly take the 2 heaviest food items
- if their weights are equal, both disappear
- if different, push back the difference
- continue until at most 1 item remains

If no item remains, print `0`.

### Data structure used

- `priority_queue<long long>`

### Why this works

Each step always needs the two heaviest values.  
A max-heap gives direct access to:
- the largest element
- then the next largest element

### Solution idea

1. Insert all food weights into a max-heap.
2. While the heap has at least 2 items:
   - take the heaviest
   - take the second heaviest
   - if they are different, push their difference back
3. At the end:
   - if empty, print `0`
   - otherwise print the only remaining weight

### Thought process

This is a classic repeated "take largest two" problem.  
Sorting once is not enough, because after each operation a new value may be inserted.

So the structure must support:
- fast largest extraction
- fast reinsertion

That is exactly what a `priority_queue` is for.

## Soal 5

File: [Soal_5.cpp](/c:/Users/asus/OneDrive/Desktop/Data%20Structure%20Practice/First%20Lab%20Session/Soal_5.cpp)

### Problem summary

The program simulates several operations on a dynamic array:
- `1 x`: add `x` to the end
- `2 x`: add `x` to every element
- `3`: remove the last element, or print `"kosong woe"` if empty
- `4`: print all elements, or print `"gaada isinya :("` if empty
- `5 y x`: insert `x` at index `y`

### Data structure used

- manual dynamic array with `new[]` and `delete[]`

### Why this works

The problem explicitly asks for a dynamic array, so using `vector` would go against the stated requirement.

The implementation manages:
- current size
- current capacity
- resizing when the array becomes full

### Solution idea

The code starts with capacity `1`.

Whenever the array is full:
- create a new array with double capacity
- copy old elements
- delete the old array

Then each operation is handled directly:
- append at the back
- loop through all items for add-to-all
- reduce size for delete
- shift elements right for insertion at index `y`

### Thought process

This problem is about understanding what a dynamic array really is under the hood.

The key idea is:
- size = how many elements are currently used
- capacity = how many elements the allocated memory can hold

Once that is clear, the operations become mechanical:
- append may require resize
- insertion requires shifting
- delete just decreases the logical size

## Soal 6

File: [Soal_6.cpp](/c:/Users/asus/OneDrive/Desktop/Data%20Structure%20Practice/First%20Lab%20Session/Soal_6.cpp)

### Problem summary

There is a queue of customers and a sequence of payment results:
- if a customer's payment is `BERHASIL`, that customer leaves the queue
- if the payment is `GAGAL`, that customer goes to the back of the queue

After all statuses are processed, print the remaining queue.  
If no customer remains, print `KOSONG`.

### Data structure used

- `queue<int>`

### Why this works

This is exactly a queue simulation:
- payment is always done by the customer at the front
- failed customers go to the back

That is the direct behavior of a queue.

### Solution idea

1. Push all customer IDs into a queue.
2. For each payment status:
   - if the queue is empty, stop
   - remove the front customer
   - if the status is `GAGAL`, push that customer back
   - if the status is `BERHASIL`, do nothing more because that customer leaves
3. Print the remaining queue, or `KOSONG` if empty

### Thought process

The moment the statement says:
- "front of the line pays"
- "failed customer goes to the back"

the correct model is already determined: this is a queue.

There is no need for a more complicated structure because every operation happens only at:
- the front
- the back

## Overall pattern

Across `Soal 1` to `Soal 6`, the main skill being trained is matching the problem behavior to the correct data structure:

- end insertion and deletion -> `vector`
- highest priority first -> `priority_queue`
- top-only access -> `stack`
- line simulation -> `queue`
- manual resizable storage -> dynamic array

That is the main thought process behind all six solutions:
1. identify how data moves
2. identify where insertion/removal happens
3. choose the structure that naturally matches that behavior
