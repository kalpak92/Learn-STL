# Containers Library

The containers library is a generic collection of class templates and algorithms that allow programmers to easily implement common data structures like queues, lists and stacks.

There are 3 classes of containers :

-  Sequence Containers
- Associative Containers
- Unordered Associative Containers

The containers manages the storage spaces that is allocated for its elements and provides member functions to access them, either directly or through iterators.

### Sequence Containers

Sequence containers implement data structures which can be accessed sequentially. Represents linear data structures.

| Name                                                         | Type                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [array](https://en.cppreference.com/w/cpp/container/array)   | static contiguous array. Fixed Size. Direct access to any element. |
| [vector](https://en.cppreference.com/w/cpp/container/vector) | dynamic contiguous array. Rapid insertions and deletions anywhere. Direct access to any element. |
| [deque](https://en.cppreference.com/w/cpp/container/deque)   | double-ended queue. Direct access to any element.            |
| [forward_list](https://en.cppreference.com/w/cpp/container/forward_list) | singly-linked list. Rapid insertions and deletions anywhere. |
| [list](https://en.cppreference.com/w/cpp/container/list)     | doubly-linked list. Rapid insertions and deletions anywhere. |

### Associative Containers

Associative containers implement **sorted data structures** that can be quickly searched (*O(log n)* complexity). Typically represents non-linear data structures that can locate elements stored in the containers quickly. These containers store sets of values in **key-value pairs** in which each key has an ***associated*** value.

The keys in associative containers are ***immutable*** as of C++11.

| Name                                                         | Type                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [set](https://en.cppreference.com/w/cpp/container/set)       | collection of **unique** keys, sorted by keys                |
| [map](https://en.cppreference.com/w/cpp/container/map)       | collection of key-value pairs, sorted by keys, keys are **unique** |
| [multiset](https://en.cppreference.com/w/cpp/container/multiset) | collection of keys, sorted by keys                           |
| [multimap](https://en.cppreference.com/w/cpp/container/multimap) | collection of key-value pairs, sorted by keys                |

The sequence containers and associative containers are collectively called referred to as the **first-class containers.**

### Unordered Associative Containers

Unordered associative containers implement **unsorted (hashed)** data structures that can be quickly searched (*O(1)* amortized, *O(n)* worst-case complexity).

| Name                                                         | Type                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [unordered_set](https://en.cppreference.com/w/cpp/container/unordered_set)(C++11) | collection of **unique** keys, hashed by keys                |
| [unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map)(C++11) | collection of key-value pairs, hashed by keys, keys are **unique** |
| [unordered_multiset](https://en.cppreference.com/w/cpp/container/unordered_multiset)(C++11) | collection of keys, hashed by keys                           |
| [unordered_multimap](https://en.cppreference.com/w/cpp/container/unordered_multimap)(C++11) | collection of key-value pairs, hashed by keys                |

### Container Adapters

Container adaptors provide a different interface for sequential containers.

| Name                                                         | Type                                                      |
| ------------------------------------------------------------ | --------------------------------------------------------- |
| [stack](https://en.cppreference.com/w/cpp/container/stack)   | adapts a container to provide stack (LIFO data structure) |
| [queue](https://en.cppreference.com/w/cpp/container/queue)   | adapts a container to provide queue (FIFO data structure) |
| [priority_queue](https://en.cppreference.com/w/cpp/container/priority_queue) | adapts a container to provide priority queue              |

### Before we begin

When the program is using STL, it should `#include` the appropriate standard headers. For most containers the title of standard header matches the name of the container, and no extension is required. For example, if you are going to use stack, just add the following line at the beginning of your program:

```c++
#include <stack>
```

Container types (and algorithms, functors and all STL as well) are defined not in global namespace, but in special namespace called `std`. Add the following line after your includes and before the code begin:

```c++
using namespace std;
```

Another important thing to remember is that the ***type of a container is the template parameter***. Template parameters are specified with the ‘<’/’>’ “brackets” in code. For example:

```c++
vector< int > N;
```

When making nested constructions, make sure that the “brackets” are not directly following one another – ***leave a blank between them***.

```c++
vector< vector< int > > CorrectDefinition;
vector<vector<int>> WrongDefinition; // Wrong: compiler may be confused by 'operator > >'
```

## Vector

The simplest STL container is vector. Vector is just an array with extended functionality. 

By the way, vector is the only container that is *backward-compatible to native C code* – this means that vector actually IS the array, but with some additional features.

```c++
vector< int > v(10);
for(int i = 0; i < 10; i++) 
{
	v[i] = (i+1)*(i+1);
}
for(int i = 9; i > 0; i--) 
{
	v[i] -= v[i-1];
}
```

Actually, when you type:

```c++
vector< int > v;
```

The empty vector is created. 

Be careful with constructions like this:

```c++
vector< int > v[10];
```

Here we declare ‘v’ as an array of 10 vector< int >’s, which are initially empty. In most cases, this is not that we want. ***Use parentheses instead of brackets here***. 

The most frequently used feature of vector is that it can report its **size**.

```c++
int elements_count = v.size();
```

```c++
bool is_nonempty_notgood = (v.size() >= 0); // Try to avoid this
bool is_nonempty_ok = !v.empty();
```

Another very popular function to use in vector is **push_back**. Push_back adds an element to the end of vector, increasing its size by one. Consider the following example:

```c++
vector< int > v;
for(int i = 1; i < 1000000; i *= 2) 
{
	v.push_back(i);
}
int elements_count = v.size();
```

Don’t worry about memory allocation — vector will not allocate just one element each time. Instead, vector allocates more memory then it actually needs when adding new elements with push_back.

When you need to resize vector, use the **resize()** function:

```c++
vector< int > v(20);
for(int i = 0; i < 20; i++) 
{
  v[i] = i+1;
}
v.resize(25);
for(int i = 20; i < 25; i++) 
{
  v[i] = i*2;
}
```

The resize() function makes vector contain the required number of elements. If you require less elements than vector already contain, the last ones will be deleted. If you ask vector to grow, it will enlarge its size and fill the newly created elements with zeroes.

***Note that if you use push_back() after resize(), it will add elements AFTER the newly allocated size, but not INTO it.*** In the example above the size of the resulting vector is 25, while if we use push_back() in a second loop, it would be 30.

```c++
vector< int > v(20);
for(int i = 0; i < 20; i++) 
{
  v[i] = i+1;
}
v.resize(25);
for(int i = 20; i < 25; i++) 
{
  v.push_back(i*2); // Writes to elements with indices [25..30), not [20..25)
}
```

To clear a vector use **clear()** member function. This function makes vector to contain 0 elements. It does not make elements zeroes -- watch out -- it completely erases the container.

### Initialization

There are many ways to initialize vector. You may create vector from another vector:

```c++
vector< int > v1;
// ...
vector< int > v2 = v1;
vector< int > v3(v1);
```

The initialization of v2 and v3 in the example above are exactly the same.

If you want to create a vector of specific size, use the following constructor:

```c++
vector< int > Data(1000);
```

In the example above, the data will contain 1,000 zeroes after creation. Remember to use parentheses, not brackets. 

If you want vector to be initialized with something else, write it in such manner:

```c++
 vector< string > names(20, "Unknown");
```

Remember that you can create vectors of any type.

Multidimensional arrays are very important. The simplest way to create the two-dimensional array via vector is to create a vector of vectors.

```c++
vector< vector< int > > Matrix;
```

It should be clear to you now how to create the two-dimensional vector of given size:

```c++
int N, M;// ...
vector< vector< int > > Matrix(N, vector< int >(M, -1));
```

Here we create a matrix of size N*M and fill it with -1.

The simplest way to add data to vector is to use **push_back().** But what if we want to add data somewhere other than the end? There is the **insert()** member function for this purpose. And there is also the **erase()** member function to erase elements, as well. But first we need to say a few words about iterators.

You should remember one more very important thing: When vector is passed as a parameter to some function, *a copy of vector is actually created*. It may take a lot of time and memory to create new vectors when they are not really needed. Actually, it’s hard to find a task where the copying of vector is REALLY needed when passing it as a parameter. So, you should never write:

```c++
void some_function(vector< int > v) 
{ 
  // Never do it unless you’re sure what you do!// ...
}
```

Instead, use the following construction:

```c++
 void some_function(const vector< int >& v) 
 { 
   // OK// ...
 }
```

If you are going to change the contents of vector in the function, just omit the ‘const’ modifier.

```c++
void modify_vector(vector< int >& v) 
{ 
  // Correct
  v[0]++;
}
```

