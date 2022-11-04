# STL Additions

## Overview

STL Additions is a library designed to contain all necessary functions for Arrays and STL containers.

## Code Documentation

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

`template<class T> void astl::show(const std::vector<T> &Vec, bool showType, bool fromRecursion = false)`

`const std::vector<T> &Vec` - Vector to show

- **Show STL List**

`template<class T> void astl::show(const std::list<T> &List, bool showType, bool fromRecursion = false)`

`const std::list<T> &List` - List to show

- **Show STL Set**

`template<class T> void astl::show(const std::set<T> &Set, bool showType, bool fromRecursion = false)`

`const std::set<T> &Set` - Set to show

- **Show STL Map**

`template<class T, class U> void astl::show(const std::map<T, U> &Map, bool showType, bool fromRecursion = false)`

`const std::map<T, U> &Map` - Map to show

## Changelog

### Pre-release 0.1.0

- Added functions to show dyncamic arrays and STL containers
- Functions can show nested containers' elements recursively
- Supported containers: 1D and 2D dynamic array, vector, list, set, map
