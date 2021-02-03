# Pointer Declaration
A header-only C++11 "library" providing an alias template `ptrdecl::Ptr` for pointer declarations.

## Features

- Use angle brackets instead of star symbols
- Declare all kinds of pointers with uniform syntax
- Clearer sematic, especially when it comes to multi-level pointers and pointers with cv-qualifiers

## How to use
```cpp
#include "ptrdecl.hpp"
using ptrdecl::Ptr;
```

### Pointers to objects
Declare pointers to objects with `Ptr<T>`.

```cpp
// int *p1;
Ptr<int> p1;

// void *p2;
Ptr<void> p2;

// const int *p3;
// int const *p3;
Ptr<const int> p3;

// int *const p4 = nullptr;
const Ptr<int> p4 = nullptr;

// const int *const p5 = nullptr;
// int const *const p5 = nullptr;
const Ptr<const int> p5 = nullptr;

// int *const *p6;
Ptr<const Ptr<int>> p6;

//const int **const p7 = nullptr;
const Ptr<Ptr<const int>> p7 = nullptr;

//int *const *const p8 = nullptr;
const Ptr<const Ptr<int>> p8 = nullptr;
```

### Pointers to functions
Declare pointers to functions with `Ptr<Signature>`.

```cpp
// int (*p1)(int, int);
Ptr<int(int, int)> p1;

// void (*p2)();
Ptr<void()> p2;

// int *(*p3)();
Ptr<Ptr<int>()> p3;

// int (*(*p4)())();
Ptr<Ptr<int()>()> p4;

// int *(*callbacks[5])();
Ptr<Ptr<int>()> callbacks[5];
```

### Pointers to data members
Declare pointers to data members with `Ptr<Class, T>`.

```cpp
struct C { int m; };

// int C::*p = &C::m;
Ptr<C, int> p = &C::m;
```

### Pointers to member functions
Declare pointers to member functions with `Ptr<Class, Signature>`.

```cpp
struct C
{
    int f(int a) { return a + 1; }
};

// int (C::*p)(int) = &C::f;
Ptr<C, int(int)> p = &C::f;
```
