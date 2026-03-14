# C++ Syntax

C++ syntaxes used in my practice, including STL containers, pointers, functions, arrays, references, dynamic memory, and common rules.

## Vector

- `v.push_back(x)` : add `x` to the end
- `v.pop_back()` : remove the last element
- `v.back()` : get the last element
- `v.front()` : get the first element
- `v[i]` : access element at index `i`
- `v.at(i)` : access element at index `i` with bounds checking
- `v.size()` : return the number of elements
- `v.empty()` : check whether the vector is empty
- `v.begin()` : iterator to the first element
- `v.end()` : iterator to one position after the last element
- `v.insert(pos, x)` : insert `x` at iterator position `pos`
- `v.erase(pos)` : remove element at iterator position `pos`
- `v.clear()` : remove all elements

Example:

```cpp
vector<int> v;
v.push_back(5);
v.push_back(8);
cout << v.front();   // 5
cout << v.back();    // 8
v.pop_back();        // removes 8
```

## Stack

- `st.push(x)` : put `x` on top of the stack
- `st.pop()` : remove the top element
- `st.top()` : read the top element
- `st.size()` : return the number of elements
- `st.empty()` : check whether the stack is empty

Example:

```cpp
stack<int> st;
st.push(10);
st.push(20);
cout << st.top(); // 20
st.pop();         // removes 20
```

## Queue

- `q.push(x)` : add `x` to the back
- `q.pop()` : remove the front element
- `q.front()` : read the front element
- `q.back()` : read the back element
- `q.size()` : return the number of elements
- `q.empty()` : check whether the queue is empty

Example:

```cpp
queue<int> q;
q.push(1);
q.push(2);
cout << q.front(); // 1
q.pop();           // removes 1
```

## Deque

- `dq.push_back(x)` : add `x` to the back
- `dq.push_front(x)` : add `x` to the front
- `dq.pop_back()` : remove from the back
- `dq.pop_front()` : remove from the front
- `dq.back()` : read the last element
- `dq.front()` : read the first element
- `dq[i]` : access element by index
- `dq.size()` : return the number of elements
- `dq.empty()` : check whether the deque is empty

Example:

```cpp
deque<int> dq;
dq.push_front(3);
dq.push_back(7);
cout << dq.front(); // 3
cout << dq.back();  // 7
```

## Priority Queue

- `pq.push(x)` : insert an element
- `pq.pop()` : remove the highest-priority element
- `pq.top()` : read the highest-priority element
- `pq.size()` : return the number of elements
- `pq.empty()` : check whether the priority queue is empty

Example:

```cpp
priority_queue<int> pq;
pq.push(10);
pq.push(30);
pq.push(20);
cout << pq.top(); // 30
```

## Iterators

- `it = v.begin()` : iterator to the first element
- `it != v.end()` : loop until reaching the end
- `++it` : move iterator forward
- `*it` : get the value pointed to by the iterator

Example:

```cpp
for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    cout << *it << ' ';
}
```

## Pair

- `make_pair(a, b)` : create a pair with two values
- `p.first` : access the first value
- `p.second` : access the second value

Example:

```cpp
pair<int, string> p = make_pair(1, "A");
cout << p.first;   // 1
cout << p.second;  // A
```

## Important Differences

- `push()` is used by `stack`, `queue`, and `priority_queue`
- `push_back()` is used by `vector` and `deque`
- `top()` is used by `stack` and `priority_queue`
- `front()` is used by `queue` and `deque`
- `back()` is used by `vector`, `queue`, and `deque`

## Pointers

- `int* p;` : declare a pointer to an `int`
- `p = &x;` : store the address of `x` in `p`
- `*p` : access or change the value pointed to by `p`
- `&x` : get the address of variable `x`
- `p == nullptr` : check whether pointer points to nothing
- `p + 1` : move pointer to the next element in an array
- `*(p + i)` : access array element using pointer arithmetic

Example:

```cpp
int x = 10;
int* p = &x;
cout << *p; // 10
*p = 20;
cout << x;  // 20
```

## Pointer Rules

- A pointer stores an address
- `*p` means dereference, which reads the value at that address
- `&x` means address-of, which gets the memory address of `x`
- Do not dereference `nullptr`
- Pointer arithmetic is safe only when pointing inside the same array
- If a pointer points to one variable, changing `*p` changes that variable

## Arrays

- `int arr[5];` : fixed-size array of 5 integers
- `arr[i]` : access element at index `i`
- `int* p = arr;` : array name acts like pointer to first element
- `*(arr + i)` : same as `arr[i]`

Example:

```cpp
int arr[3] = {10, 20, 30};
cout << arr[1];      // 20
cout << *(arr + 2);  // 30
```

## Functions

- `int add(int a, int b)` : function declaration and definition
- `return x;` : send a value back from a function
- `void show()` : function with no return value
- `f(x)` : call function `f` with argument `x`

Example:

```cpp
int add(int a, int b) {
    return a + b;
}

cout << add(2, 3); // 5
```

## Pass by Value vs Reference

- `void f(int x)` : pass by value, original variable is not changed
- `void f(int& x)` : pass by reference, original variable can be changed
- `void f(const int& x)` : pass by reference without allowing modification

Example:

```cpp
void change(int& x) {
    x = 100;
}

int a = 5;
change(a);
cout << a; // 100
```

## References

- `int& ref = x;` : `ref` becomes another name for `x`
- changing `ref` changes `x`
- a reference must refer to something when it is created

Example:

```cpp
int x = 7;
int& ref = x;
ref = 20;
cout << x; // 20
```

## Const Rules

- `const int x = 5;` : `x` cannot be changed
- `const int* p` : pointer can move, but value cannot be changed through `p`
- `int* const p = &x` : pointer cannot move, but value can be changed
- `const int& ref = x` : read-only reference

Example:

```cpp
int x = 10;
const int* p = &x;
// *p = 20; // not allowed
```

## Dynamic Memory

- `new int` : allocate one integer on heap
- `new int[n]` : allocate array of `n` integers on heap
- `delete p` : free memory allocated by `new`
- `delete[] arr` : free memory allocated by `new[]`

Example:

```cpp
int* arr = new int[3];
arr[0] = 1;
arr[1] = 2;
arr[2] = 3;
delete[] arr;
```

## Function Pointers

- `int (*op)(int, int);` : pointer to a function returning `int`
- `op = add;` : store function address
- `op(2, 3)` : call function through pointer

Example:

```cpp
int add(int a, int b) {
    return a + b;
}

int (*op)(int, int) = add;
cout << op(2, 3); // 5
```

## Struct and Class Access

- `obj.value` : access member from an object
- `ptr->value` : access member through a pointer

Example:

```cpp
struct Node {
    int data;
};

Node n;
n.data = 5;

Node* p = &n;
cout << p->data; // 5
```

## Type Conversion

- `static_cast<int>(x)` : explicitly convert `x` to `int`
- often used when converting `size_t` to `int`

Example:

```cpp
vector<int> v = {1, 2, 3};
int n = static_cast<int>(v.size());
```

## Input and Output

- `cin >> x` : input value into variable `x`
- `cout << x` : output value
- `'\n'` : new line

Example:

```cpp
int x;
cin >> x;
cout << x << '\n';
```

## Control Flow

- `if (condition)` : run code if condition is true
- `else` : run code if condition is false
- `for (...)` : repeat with counter
- `while (...)` : repeat while condition is true
- `break` : stop loop
- `continue` : skip current iteration

Example:

```cpp
for (int i = 0; i < 5; ++i) {
    if (i == 3) {
        break;
    }
    cout << i << ' ';
}
```

## Common Mistakes

- using `top()`, `front()`, or `back()` when container is empty
- using `pop()` on an empty stack, queue, or priority queue
- forgetting `delete` or `delete[]` after `new`
- using `delete` instead of `delete[]` for arrays
- dereferencing a null pointer
- confusing `*p` with `p`
- mixing signed and unsigned types like `int` and `size_t`
- expecting pass-by-value to change the original variable
- forgetting that array index starts from `0`

## When to Use What

- Use `.` when you have a normal object
- Use `->` when you have a pointer to an object

Example:

```cpp
Node node;
Node* ptr = &node;

node.data = 10;  // .
ptr->data = 20;  // ->
```

- Use `push(x)` for `stack`, `queue`, and `priority_queue`
- Use `push_back(x)` for `vector` and `deque`
- Use `push_front(x)` only when the container supports front insertion, such as `deque`

- Use `top()` for `stack` and `priority_queue`
- Use `front()` for `queue` and `deque`
- Use `back()` when you need the last element of `vector`, `queue`, or `deque`

- Use a pointer when you need an address, dynamic memory, array traversal, or linked structure access
- Use a reference when you want an easier alias to an existing variable
- Use `const int&` when you want efficiency without allowing modification

- Use pass-by-value for small data or when the function should not affect the original variable
- Use pass-by-reference when the function should modify the original variable
- Use pass-by-const-reference for large objects like `vector` when you only want to read them

Example:

```cpp
void printVector(const vector<int>& v) { }
void changeValue(int& x) { x = 5; }
void copyValue(int x) { x = 5; }
```

- Use `new` and `delete` only when manual dynamic memory is really needed
- Prefer `vector` over manual `new[]` and `delete[]` in most normal cases

- Use `arr[i]` when you want clearer array access
- Use `*(arr + i)` when practicing pointer arithmetic or when working directly with pointers

- Use `static_cast<int>(x)` when you want explicit and safe conversion
- Common case: converting `size()` result into `int`

- Use `empty()` before `top()`, `front()`, `back()`, or `pop()` if there is any chance the container has no elements

## Quick Memory Rules

- `p` is the address
- `*p` is the value at that address
- `&x` is the address of `x`
- `ref` is another name for the same variable
- `arr` acts like pointer to the first element in many expressions
