# STL Additions

## Overview

STL Additions is a library designed to contain all necessary functions for Arrays and STL containers.

## Code Documentation

### `show()` - Functions displaying containers

- **Global show function parameters**

    `bool showType` - Default to false. If true, it displays container type before values

    `bool fromRecursion` - Default to false. Set to true when function has been initiated by recurision. Used for nested containers to prevent adding new line character.

- **Show single non-iterable element.**

    `astl::show(T Elem, bool showType = false, bool fromRecursion = false)`

    `T Elem` - Non-iterable element

- **Show Dynamic Array.**

    `astl::show(T *Array, int arraySize, bool showType, bool fromRecursion = false)`

    `T *Array` - Array to show

    `int arraySize` - Length of an array. If negative, function throws an exception

- **Show 2D Dynamic Array.**

    `astl::show(T **Array, int arraySize1, int arraySize2, bool showType, bool fromRecursion = false)`

    `T **Array` - Array to show

    `int arraySize1` - 1st Length (Number of Sub-Arrays). If negative, function throws an exception

    `int arraySize2` - 2nd Length (Length of Sub-Arrays). If negative, function throws an exception

- **Show STL Vector**

    `astl::show(const std::vector<T> &STL_Vec, bool showType, bool fromRecursion = false)`

    `const std::vector<T> &STL_Vec` - Vector to show

- **Show STL List**

    `void astl::show(const std::list<T> &STL_List, bool showType, bool fromRecursion = false)`

    `const std::list<T> &STL_List` - List to show

- **Show STL Set**

    `astl::show(const std::set<T> &STL_Set, bool showType, bool fromRecursion = false)`

    `const std::set<T> &STL_Set` - Set to show

- **Show STL Map**

    `astl::show(const std::map<T, U> &Map, bool showType, bool fromRecursion = false)`

    `const std::map<T, U> &Map` - Map to show

### `opr() type 1` - Functions to make arithmetic operations on all container elements

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

    `astl::opr(const T *Array, int ArraySize, op Operation, T Constant)`

    `T *Array` - Dynamic Array

    `int ArraySize` - Length of an array. If negative, function throws an exception

- **Operation on 2D Array**

    `astl::opr(T **Array, int ArraySize1, int ArraySize2, op Operation, T Constant)`

    `T **Array` - Dynamic Array

    `int ArraySize1`, `int ArraySize2` - Length of an array and sub-array. If negative, function throws an exception

- **Operation on vector**

    `astl::opr(std::vector<T> STL_Vec, op Operation, T Constant)`

    `std::vector<T> STL_Vec` - Vector

- **Operation on list**

    `astl::opr(std::list<T> STL_List, op Operation, T Constant)`

    `std::list<T> STL_List` - List

- **Operation on set**

    `astl::opr(std::set<T> STL_Set, op Operation, T Constant)`

    `std::set<T> STL_Set` - Set

- **Operation on map**

    `astl::opr(std::map<T, U> STL_Map, op Operation, U Constant)`

    `std::map<T, U> STL_Map` - Map

### `opr() type 2` - Functions executing operations on two containers

- **Operation on two dynamic Arrays**

    `astl::opr(const T *A1, int size_A1, op Operation, const U *A2, int size_A2, int &new_size)`

    `const T *A1` - 1st Array

    `int size_A1` - 1st Array Size. If negative, function throws an exception

    `const U *A2` - 2nd Array

    `int size_A2` - 2nd Array Size. If negative, function throws an exception

    `int &new_size` - Value to store new array size, passed through reference

- **Operation on two 2D dynamic Arrays**

    `astl::opr(T **A1, int A1_size1, int A1_size2, op Operation, U **A2, int A2_size1, int A2_size2, int &new_size1, int &new_size2)`

    `T **A1` - 1st 2D Array

    `int A1_size1`, `int A1_size2` - 1st Array length and sub-array length. If negative, function throws an exception

    `U **A2` - 2nd 2D Array

    `int A2_size1`, `int A2_size2` - 2nd Array length and sub-array length. If negative, function throws an exception

    `int &new_size1`, `int &new_size2` - Values to store new array length and sub-array length, passed through reference

- **Operation on two vectors**

    `astl::opr(const std::vector<T> &A1, op Operation, const std::vector<U> &A2)`

    `const std::vector<T> &A1`, `const std::vector<U> &A2` - STL Vectors

- **Operation on two lists**

    `astl::opr(const std::list<T> &A1, op Operation, const std::list<U> &A2)`

    `const std::list<T> &A1`, `const std::list<U> &A2` - STL Lists

- **Set Operations**

  - `set_op::sum` = 0 - Set Sum (All values from first set and second set)
  - `set_op::diff` = 1 - Set Difference (All values from first set except those that occur in second set)
  - `set_op::intersect` = 2 - Set Intersect (All values that occur in both sets)
  - `set_op::ex_or` = 3 - Set Exclusive-OR (values that occur **only** in one set and not the other)

- **Operation on two sets**

    `astl::opr(const std::set<T> &A1, set_op SetOperation, const std::set<T> &A2)`

    `const std::set<T> &A1`, `const std::set<T> &A2` - STL Sets

    `set_op SetOperation` - Set Operation

### `opr() type 3` - Functions executing cross-container operations

- **Operation on Dynamic Array and Vector**

  - Returning Array:

    `astl::opr(const T *Array, int ArraySize, op Operation, const std::vector<U> &STL_Vec, int &new_size)`

    `int &new_size` - Returns new array size by reference

  - Returning Vector:

    `astl::opr(const std::vector<T> &STL_Vec, op Operation, const U *Array, int ArraySize)`

- **Operation on Dynamic Array and List**

  - Returning Array:

    `astl::opr(const T *Array, int ArraySize, op Operation, const std::list<U> &STL_List, int &new_size)`

    `int &new_size` - Returns new array size by reference

  - Returning List:

    `astl::opr(const std::list<T> &STL_List, op Operation, const U *Array, int ArraySize)`

- **Operation on Vector and List**

  - Returning Vector:

    `astl::opr(const std::vector<T> &STL_Vec, op Operation, const std::list<U> &STL_List)`

  - Returning List:

    `astl::opr(const std::list<T> &STL_List, op Operation, const std::vector<U> &STL_Vec)`

## Changelog

### Pre-release 0.5.0

- Added cross-container opr() functions to provide calculations between arrays
- Supported containers: Dynamic array, vector, list

> NOTE: Container order matters. Executing operation on vector and list returns vector, but operation on list and vector returns list.

### Pre-release 0.4.0

- add() functions have been replaced with opr() to provide variety of arithmetic operations
- Supported containers: 1D and 2D dynamic array, vector, list, set
- Supported arithmetic operations: add, subtract, multiply, divide, power, mod
- Supported set operations: sum, diff, intersect, ex_or

> NOTE: Cross-container operations are not allowed (i.e. execute operation on vector and list)

#### Container operation examples

- Operations on two 1D Dynamic Arrays / vectors / lists:

    Input: `[3, 5, 7]`, `[2, 4, 6, 8]`

    Output: Add: `[5, 9, 13, 8]`, Subtract: `[1, 1, 1, -8]`, Multiply: `[6, 20, 42, 0]`, Divide: `[1, 1, 1, 0]`, Power: `[9, 625, 117649, 0]`, Mod: `[1, 1, 1, 0]`

- Operations on two 2D Dynamic Arrays:

    Input: `[[2, 3], [1, 2]]`, `[[2, 2, 2], [3, 3, 3], [4, 4, 4]]`

    Output: Add: `[[4, 5, 2], [4, 5, 3], [4, 4, 4]]`, Subtract: `[[0, 1, -2], [-2, -1, -3], [-4, -4, -4]]`, Multiply: `[[4, 6, 0], [3, 6, 0], [0, 0, 0]]`, Divide: `[[1, 1, 0], [0, 0, 0], [0, 0, 0]]`, Power: `[[4, 9, 0], [1, 8, 0], [0, 0, 0]]`, Mod: `[[0, 1, 0], [1, 2, 0], [0, 0, 0]]`

- Operations on Sets:

    Input: `{1, 2, 4, 5, 6, 8}`, `{1, 4, 5, 7, 9}`

    Output: Sum: `{1, 2, 4, 5, 6, 7, 8, 9}`, Diff: `{2, 6, 8}`, Intersect: `{1, 4, 5}`, Exclusive-OR: `{2, 6, 8, 7, 9}`

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

### Pre-release 0.2.0 (deprecated)

- Added functions to add values in containers (no recursion supported).
- Supported containers: 1D and 2D dynamic array, vector, list, set, map

> NOTE: Adding does not support adding two different containers. Sizes of input containers can be differentm, result container fits to biggest size of input containers.

#### Adding Examples (deprecated)

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
