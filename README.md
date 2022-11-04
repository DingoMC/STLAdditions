# STL Additions

## Overview

STL Additions is a library designed to contain all necessary functions for Arrays and STL containers.

## Code Documentation

### `show()` - Functions displaying containers

- **Global show function parameters**

    `bool showType` - Default to false. If true, it displays container type before values

    `bool fromRecursion` - Default to false. Set to true when function has been initiated by recurision. Used for nested containers to prevent adding new line character.

- **Show single non-iterable element.**

    `template<class T> void astl::show(T Elem, bool showType = false, bool fromRecursion = false)`

    `T Elem` - Non-iterable element

- **Show Dynamic Array.**

    `template<class T> void astl::show(T *Array, int arraySize, bool showType, bool fromRecursion = false)`

    `T *Array` - Array to show

    `int arraySize` - Length of an array. If negative, function throws an exception

- **Show 2D Dynamic Array.**

    `template<class T> void astl::show(T **Array, int arraySize1, int arraySize2, bool showType, bool fromRecursion = false)`

    `T **Array` - Array to show

    `int arraySize1` - 1st Length (Number of Sub-Arrays). If negative, function throws an exception

    `int arraySize2` - 2nd Length (Length of Sub-Arrays). If negative, function throws an exception

- **Show STL Vector**

    `template<class T> void astl::show(const std::vector<T> &STL_Vec, bool showType, bool fromRecursion = false)`

    `const std::vector<T> &STL_Vec` - Vector to show

- **Show STL List**

    `template<class T> void astl::show(const std::list<T> &STL_List, bool showType, bool fromRecursion = false)`

    `const std::list<T> &STL_List` - List to show

- **Show STL Set**

    `template<class T> void astl::show(const std::set<T> &STL_Set, bool showType, bool fromRecursion = false)`

    `const std::set<T> &STL_Set` - Set to show

- **Show STL Map**

    `template<class T, class U> void astl::show(const std::map<T, U> &Map, bool showType, bool fromRecursion = false)`

    `const std::map<T, U> &Map` - Map to show

### `add()` - Functions adding container values

- **Add 1D Arrays**

    `template<class T, class U> T *astl::add(const T *A1, int size_A1, const U *A2, int size_A2, int &new_size)`

    `const T *A1` - 1st Array

    `int size_A1` - 1st Array Size. If negative, function throws an exception

    `const U *A2` - 2nd Array

    `int size_A2` - 2nd Array Size. If negative, function throws an exception

    `int &new_size` - Value to store new array size, passed through reference

- **Add 2D Arrays**

    `template<class T, class U> T **astl::add(T **A1, int A1_size1, int A1_size2, U **A2, int A2_size1, int A2_size2, int &new_size1, int &new_size2)`

    `T **A1` - 1st 2D Array

    `int A1_size1`, `int A1_size2` - 1st Array length and sub-array length. If negative, function throws an exception

    `U **A2` - 2nd 2D Array

    `int A2_size1`, `int A2_size2` - 2nd Array length and sub-array length. If negative, function throws an exception

    `int &new_size1`, `int &new_size2` - Values to store new array length and sub-array length, passed through reference

- **Add Vectors**

    `template<class T, class U> std::vector<T> astl::add(const std::vector<T> &A1, const std::vector<U> &A2)`

    `const std::vector<T> &A1`, `const std::vector<U> &A2` - Vectors to add

- **Add Lists**

    `template<class T, class U> std::list<T> astl::add(const std::list<T> &A1, const std::list<U> &A2)`

    `const std::list<T> &A1`, `const std::list<U> &A2` - Lists to add

- **Add Sets**

    `template<class T> std::set<T> astl::add(const std::set<T> &A1, const std::set<T> &A2)`

    `const std::set<T> &A1`, `const std::set<T> &A2` - Sets to add

- **Add Maps**

    `template<class T, class U> std::map<T, U> astl::add(const std::map<T, U> &A1, const std::map<T, U> &A2)`

    `const std::map<T, U> &A1`, `const std::map<T, U> &A2` - Maps to add

### `opr()` - Functions to make arithmetic operations on all container elements

- **Math operations definitions**

  - `op::add` = 0 - Addition
  - `op::subtract` = 1 - Subtraction
  - `op::multiply` = 2 - Multiplication
  - `op::divide` = 3 - Division
  - `op::power` = 4 - Exponentiation
  - `op::mod` = 5 - Modulo

- **Global `opr()` function parameters**

    `op Operation` - Arithmetic operation to execute

    `T Constant` - Value as a second argument of operation

- **Operation on 1D Array**

    `template<class T> T *astl::opr(const T *Array, int ArraySize, op Operation, T Constant)`

    `T *Array` - Dynamic Array

    `int ArraySize` - Length of an array. If negative, function throws an exception

- **Operation on 2D Array**

    `template<class T> T **astl::opr(T **Array, int ArraySize1, int ArraySize2, op Operation, T Constant)`

    `T **Array` - Dynamic Array

    `int ArraySize1`, `int ArraySize2` - Length of an array and sub-array. If negative, function throws an exception

- **Operation on vector**

    `template<class T> std::vector<T> astl::opr(std::vector<T> STL_Vec, op Operation, T Constant)`

    `std::vector<T> STL_Vec` - Vector

- **Operation on list**

    `template<class T> std::list<T> astl::opr(std::list<T> STL_List, op Operation, T Constant)`

    `std::list<T> STL_List` - List

- **Operation on set**

    `template<class T> std::set<T> astl::opr(std::set<T> STL_Set, op Operation, T Constant)`

    `std::set<T> STL_Set` - Set

- **Operation on map**

    `template<class T, class U> std::map<T, U> astl::opr(std::map<T, U> STL_Map, op Operation, U Constant)`

    `std::map<T, U> STL_Map` - Map

## Changelog

### Pre-release 0.3.0

- Added functions to make arithmetic operations on all values using constant value
- Supported containers: 1D and 2D dynamic array, vector, list, set, map
- Supported operations: add, subtract, multiply, divide, power, mod

> NOTE: operation functions does not support recursive containers.

#### Operation Examples

- Operations on 1D Dynamic Arrays / vectors / lists:

    Input: `Array [1, 2, 3]`, `Value 2`

    Output: Add: `[3, 4, 5]`, Subtract `[-1, 0, 1]`, Multiply `[2, 4, 6]`, Divide `[0, 1, 1]`, Power `[1, 4, 9]`, Mod `[1, 0, 1]`
- Operations on 2D Dynamic Arrays:

    Input: `Array [[0, 1], [1, 2]]`, `Value 2`

    Output: Add: `[[2, 3], [3, 4]]`, Subtract `[[-2, -1], [-1, 0]]`, Multiply `[[0, 2], [2, 4]]`, Divide `[[0, 0], [0, 1]]`, Power `[[0, 1], [1, 4]]`, Mod `[[0, 1], [1, 0]]`
- Operations on sets

    Input: `Set {0, 1, 2, 3}`, `Value 2`

    Output: Add: `{2, 3, 4, 5}`, Subtract `{-2, -1, 0, 1}`, Multiply `{0, 2, 4, 6}`, Divide `{0, 1}`, Power `{0, 1, 4, 9}`, Mod `{0, 1}`
- Operations on maps

    Input: `Map {A: 0, B: 1, C: 2}`, `Value:2`

    Output: Add: `{A: 2, B: 3, C: 4}`, Subtract `{A: -2, B: -1, C: 0}`, Multiply `{A: 0, B: 2, C: 4}`, Divide `{A: 0, B: 0, C: 1}`, Power `{A: 0, B: 1, C: 4}`, Mod `{A: 0, B: 1, C: 0}`

### Pre-release 0.2.0

- Added functions to add values in containers (no recursion supported).
- Supported containers: 1D and 2D dynamic array, vector, list, set, map

> NOTE: Adding does not support adding two different containers. Sizes of input containers can be differentm, result container fits to biggest size of input containers.

#### Adding Examples

- Adding 1D Dynamic Arrays / vectors / lists:

    Input: `[1, 2, 3, 4]`, `[1, 2, 3, 4, 5]`

    Output: `[2, 4, 6, 8, 5]`
- Adding 2D Dynamic Arrays:

    Input: `[[0, 0, 0], [1, 1, 1], [2, 2, 2]]`, `[[0, 0, 0, 0], [1, 1, 1, 1], [2, 2, 2, 2]]`

    Output: `[[0, 0, 0, 0], [2, 2, 2, 1], [4, 4, 4, 2]]`
- Adding sets:

    Input: `{0, 1, 2, 3}`, `{2, 3, 4, 5}`

    Output: `{0, 1, 2, 3, 4, 5}`
- Adding maps:

    Input: `{A: 0, B: 1, C: 2}`, `{C: 2, D: 3, E: 4}`

    Output: `{A: 0, B: 1, C: 4, D: 3, E: 4}`

### Pre-release 0.1.0

- Added functions to show dyncamic arrays and STL containers
- Functions can show nested containers' elements recursively
- Supported containers: 1D and 2D dynamic array, vector, list, set, map
