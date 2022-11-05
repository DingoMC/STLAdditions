/**
 * @file stl_additions.h
 * @author DingoMC (www.dingomc.net)
 * @brief STL Additions is a library to support operating on arrays and STL containers
 * It provides variety of functions that can be applied to containers in astl namespace.
 * @warning Library made in C++11! Lower C++ versions may cause malfunction!
 * @version 0.5.0
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef STL_ADDITIONS_H
#define STL_ADDITIONS_H
#include <iostream>
#include <typeinfo>
#include <stdexcept>
#include <math.h>
#include <vector>
#include <list>
#include <set>
#include <map>
#define MAX_I(a, b) (a > b ? a : b)
#pragma GCC optimize("O3")
using namespace std;
// Arithmetic ooperations
enum op {add = 0, subtract = 1, multiply = 2, divide = 3, power = 4, mod = 5};
// Set operations
enum set_op {sum = 0, diff = 1, intersect = 2, ex_or = 3};
namespace astl {
    /*
        showing Functions
        Added in 0.1.0
    */
    // Function prototypes
    template<class T> void show(T Elem, bool = false, bool = false);
    template<class T> void show(T* Array, int, bool showType = false, bool = false);
    template<class T> void show(T** Array, int, int, bool showType = false, bool = false);
    template<class T> void show(const vector < T > &STL_Vec, bool showType = false, bool = false);
    template<class T> void show(const list < T > &STL_List, bool showType = false, bool = false);
    template<class T> void show(const set < T > &STL_Set, bool showType = false, bool = false);
    template<class T, class U> void show(const map<T, U> &Map, bool showType = false, bool = false);

    /**
     * @brief Show Single Element
     * 
     * @tparam T Element Type
     * @param Elem Non-iterable element
     */
    template <class T> void show (T Elem, bool showType, bool fromRecursion) {
        cout<<Elem;
    }

    /**
     * @brief Show 1D Dynamic Array
     * 
     * @tparam T Array Element Type
     * @param Array Dynamic Array
     * @param arraySize Array Length
     */
    template <class T> void show (T* Array, int arraySize, bool showType, bool fromRecursion) {
        if (arraySize < 0) throw std::invalid_argument("arraySize must be a positive integer!");
        if (showType) cout<<"`Array` ";
        cout<<"[";
        for (unsigned i = 0; i < arraySize; i++) {
            show(Array[i], showType, true);
            if (i < arraySize - 1) cout<<", ";
        }
        cout<<"]";
        if (!fromRecursion) cout<<endl;
    }
    
    /**
     * @brief Show 2D Dynamic Array
     * 
     * @tparam T Array Element Type
     * @param Array 2D Dynamic Array
     * @param arraySize1 1st Length (Number of Sub-Arrays)
     * @param arraySize2 2nd Length (Length of Sub-Arrays)
     * @param showType Default to false. When true it also shows type of iterable element.
     */
    template<class T> void show (T** Array, int arraySize1, int arraySize2, bool showType, bool fromRecursion) {
        if (arraySize1 < 0 || arraySize2 < 0) throw std::invalid_argument("arraySize must be a positive integer!");
        if (showType) cout<<"`Array` ";
        cout<<"[";
        for (unsigned i = 0; i < arraySize1; i++) {
            show(Array[i], arraySize2, showType, true);
            if (i < arraySize1 - 1) cout<<", ";
        }
        cout<<"]";
        if (!fromRecursion) cout<<endl;
    }
    
    /**
     * @brief Show STL Vector
     * 
     * @tparam T Vector Element Type
     * @param STL_Vec STL Vector
     * @param showType Default to false. When true it also shows type of iterable element.
     */
    template<class T> void show (const vector < T > &STL_Vec, bool showType, bool fromRecursion) {
        unsigned V_size = STL_Vec.size();
        if (showType) cout<<"`Vector` ";
        cout<<"[";
        for (unsigned i = 0; i < V_size; i++) {
            show(STL_Vec[i], showType, true);
            if (i < V_size - 1) cout<<", ";
        }
        cout<<"]";
        if (!fromRecursion) cout<<endl;
    }

    /**
     * @brief Show STL List
     * 
     * @tparam T List Element Type
     * @param STL_List STL List
     * @param showType Default to false. When true it also shows type of iterable element.
     */
    template<class T> void show (const list < T > &STL_List, bool showType, bool fromRecursion) {
        if (showType) cout<<"`List` ";
        cout<<"[";
        for (auto it = STL_List.cbegin(); it != STL_List.cend(); it++) {
            if (it != STL_List.cbegin()) cout<<", ";
            show(*it, showType, true);
        }
        cout<<"]";
        if (!fromRecursion) cout<<endl;
    }

    /**
     * @brief Show STL Set
     * 
     * @tparam T Set Element Type
     * @param STL_Set STL Set
     * @param showType Default to false. When true it also shows type of iterable element.
     */
    template<class T> void show (const set < T > &STL_Set, bool showType, bool fromRecursion) {
        if (showType) cout<<"`Set` ";
        cout<<"{";
        for (auto it = STL_Set.cbegin(); it != STL_Set.cend(); it++) {
            if (it != STL_Set.cbegin()) cout<<", ";
            show(*it, showType, true);
        }
        cout<<"}";
        if (!fromRecursion) cout<<endl;
    }

    /**
     * @brief Show STL Map
     * 
     * @tparam T Map Key Type
     * @tparam U Map Value Type
     * @param Map STL Map
     * @param showType Default to false. When true it also shows type of iterable element.
     */
    template<class T, class U> void show(const map<T, U> &Map, bool showType, bool fromRecursion) {
        if (showType) cout<<"`Map` ";
        cout<<"{";
        for (typename map<T, U>::const_iterator it = Map.begin(); it != Map.end(); ++it) {
            if (it != Map.cbegin()) cout<<", ";
            show(it->first, showType, true);
            cout<<": ";
            show(it->second, showType, true);
        }
        cout<<"}";
        if (!fromRecursion) cout<<endl;
    }

    /*
        opr() - operations with constants
        Added in 0.3.0
    */

    /**
     * @brief Execute operation with a constant on dynamic array
     * 
     * @tparam T Number
     * @param Array Dynamic Array
     * @param ArraySize Array Size
     * @param Operation Math operation
     * @param Constant Constant value
     * @return T* 
     */
    template <class T> T* opr (const T* Array, int ArraySize, op Operation, T Constant) {
        if (ArraySize < 0) throw std::invalid_argument("arraySize must be a positive integer!");
        T* NewArray = new T[ArraySize];
        for (unsigned i = 0; i < ArraySize; i++) {
            switch (Operation) {
                case op::add: {NewArray[i] = Array[i] + Constant; break;}
                case op::subtract: {NewArray[i] = Array[i] - Constant; break;}
                case op::multiply: {NewArray[i] = Array[i] * Constant; break;}
                case op::divide: {
                    if (Constant == 0) throw std::invalid_argument("Cannot divide by 0!");
                    NewArray[i] = Array[i] / Constant;
                    break;
                }
                case op::power: {NewArray[i] = pow(Array[i], Constant); break;}
                case op::mod: {
                    if (Constant <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                    NewArray[i] = Array[i] % Constant;
                    break;
                }
                default: {throw std::invalid_argument("Unknown operation!");}
            }
        }
        return NewArray;
    }

    /**
     * @brief Execute operation with a constant on 2D dynamic array
     * 
     * @tparam T Number
     * @param Array 2D Array
     * @param ArraySize1 Array Length
     * @param ArraySize2 Sub-Array Length
     * @param Operation Math operation
     * @param Constant Constant value
     * @return T** 
     */
    template <class T> T** opr (T** Array, int ArraySize1, int ArraySize2, op Operation, T Constant) {
        if (ArraySize1 < 0 || ArraySize2 < 0) throw std::invalid_argument("arraySize must be a positive integer!");
        T** NewArray = new T*[ArraySize1];
        for (int i = 0; i < ArraySize1; i++) NewArray[i] = new T[ArraySize2];
        for (int i = 0; i < ArraySize1; i++) NewArray[i] = opr(Array[i], ArraySize2, Operation, Constant);
        return NewArray;
    }

    /**
     * @brief Execute operation with a constant on vector
     * 
     * @tparam T Number
     * @param STL_Vec Vector
     * @param Operation Math operation
     * @param Constant Constant value
     * @return vector < T > 
     */
    template <class T> vector < T > opr (const vector < T > &STL_Vec, op Operation, T Constant) {
        vector < T > NewVector;
        int ArraySize = STL_Vec.size();
        NewVector.resize(ArraySize);
        for (unsigned i = 0; i < ArraySize; i++) {
            switch (Operation) {
                case op::add: {NewVector[i] = STL_Vec[i] + Constant; break;}
                case op::subtract: {NewVector[i] = STL_Vec[i] - Constant; break;}
                case op::multiply: {NewVector[i] = STL_Vec[i] * Constant; break;}
                case op::divide: {
                    if (Constant == 0) throw std::invalid_argument("Cannot divide by 0!");
                    NewVector[i] = STL_Vec[i] / Constant;
                    break;
                }
                case op::power: {NewVector[i] = pow(STL_Vec[i], Constant); break;}
                case op::mod: {
                    if (Constant <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                    NewVector[i] = STL_Vec[i] % Constant;
                    break;
                }
                default: {throw std::invalid_argument("Unknown operation!");}
            }
        }
        return NewVector;
    }

    /**
     * @brief Execute operation with a constant on list
     * 
     * @tparam T 
     * @param STL_List List
     * @param Operation Math operation
     * @param Constant Constant value
     * @return list < T > 
     */
    template <class T> list < T > opr (const list < T > &STL_List, op Operation, T Constant) {
        list < T > NewList;
        for (auto it = STL_List.cbegin(); it != STL_List.cend(); it++) {
            switch (Operation) {
                case op::add: {NewList.push_back(*it + Constant); break;}
                case op::subtract: {NewList.push_back(*it - Constant); break;}
                case op::multiply: {NewList.push_back(*it * Constant); break;}
                case op::divide: {
                    if (Constant == 0) throw std::invalid_argument("Cannot divide by 0!");
                    NewList.push_back(*it / Constant);
                    break;
                }
                case op::power: {NewList.push_back(pow(*it, Constant)); break;}
                case op::mod: {
                    if (Constant <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                    NewList.push_back(*it % Constant);
                    break;
                }
                default: {throw std::invalid_argument("Unknown operation!");}
            }
        }
        return NewList;
    }

    /**
     * @brief Execute operation with a constant on set
     * 
     * @tparam T Number
     * @param STL_Set Set
     * @param Operation Math opertaion
     * @param Constant Constant value
     * @return set < T > 
     */
    template <class T> set < T > opr (const set < T > &STL_Set, op Operation, T Constant) {
        set < T > NewSet;
        for (auto it = STL_Set.cbegin(); it != STL_Set.cend(); it++) {
            switch (Operation) {
                case op::add: {NewSet.insert(*it + Constant); break;}
                case op::subtract: {NewSet.insert(*it - Constant); break;}
                case op::multiply: {NewSet.insert(*it * Constant); break;}
                case op::divide: {
                    if (Constant == 0) throw std::invalid_argument("Cannot divide by 0!");
                    NewSet.insert(*it / Constant);
                    break;
                }
                case op::power: {NewSet.insert(pow(*it, Constant)); break;}
                case op::mod: {
                    if (Constant <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                    NewSet.insert(*it % Constant);
                    break;
                }
                default: {throw std::invalid_argument("Unknown operation!");}
            }
        }
        return NewSet;
    }

    /**
     * @brief Execute operation with a constant on map
     * 
     * @tparam T Key Type
     * @tparam U Value Type (Number)
     * @param STL_Map Map
     * @param Operation Math Operation
     * @param Constant Constant value
     * @return map < T, U > 
     */
    template <class T, class U> map < T, U > opr (const map < T, U > &STL_Map, op Operation, U Constant) {
        map < T, U > NewMap;
        for (typename map<T, U>::const_iterator it = STL_Map.begin(); it != STL_Map.end(); ++it) {
            switch (Operation) {
                case op::add: {NewMap.insert(make_pair(it->first, it->second + Constant)); break;}
                case op::subtract: {NewMap.insert(make_pair(it->first, it->second - Constant)); break;}
                case op::multiply: {NewMap.insert(make_pair(it->first, it->second * Constant)); break;}
                case op::divide: {
                    if (Constant == 0) throw std::invalid_argument("Cannot divide by 0!");
                    NewMap.insert(make_pair(it->first, it->second / Constant));
                    break;
                }
                case op::power: {
                    NewMap.insert(make_pair(it->first, pow(it->second, Constant)));
                    break;
                }
                case op::mod: {
                    if (Constant <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                    NewMap.insert(make_pair(it->first, it->second % Constant));
                    break;
                }
                default: {throw std::invalid_argument("Unknown operation!");}
            }
        }
        return NewMap;
    }

    /*
        opr() type 2 - operations on two containers
        Added in 0.4.0
    */

    /**
     * @brief Execute operation on two dynamic arrays
     * 
     * @tparam T Number
     * @tparam U Number
     * @param A1 1st Array
     * @param size_A1 1st Array Size
     * @param Operation Math Operation
     * @param A2 2nd Array
     * @param size_A2 2nd Array Size
     * @param new_size Result Array length returned by reference
     * @return T* Result Array
     */
    template <class T, class U> T* opr (const T* A1, int size_A1, op Operation, const U* A2, int size_A2, int &new_size) {
        if (size_A1 < 0 || size_A2 < 0) throw std::invalid_argument("arraySize must be a positive integer!");
        new_size = MAX_I(size_A1, size_A2);
        T* A3 = new T[new_size];
        for (unsigned i = 0; i < new_size; i++) A3[i] = 0;
        for (unsigned i = 0; i < size_A1; i++) A3[i] += A1[i];
        for (unsigned i = 0; i < size_A2; i++) {
            switch (Operation) {
                case op::add: {A3[i] += A2[i]; break;}
                case op::subtract: {A3[i] -= A2[i]; break;}
                case op::multiply: {A3[i] *= A2[i]; break;}
                case op::divide: {
                    if (A2[i] == 0) throw std::invalid_argument("Cannot divide by 0!");
                    A3[i] /= A2[i];
                    break;
                }
                case op::power: {A3[i] = pow(A3[i], A2[i]); break;}
                case op::mod: {
                    if (A2[i] <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                    A3[i] %= A2[i];
                    break;
                }
                default: {throw std::invalid_argument("Unknown operation!");}
            }
        }
        return A3;
    }

    /**
     * @brief Execute operation on two 2D dynamic arrays
     * 
     * @tparam T Number
     * @tparam U Number
     * @param A1 1st 2D Array
     * @param A1_size1 1st Array length
     * @param A1_size2 1st Array sub-length
     * @param Operation Math Operation
     * @param A2 2nd 2D Array
     * @param A2_size1 2nd Array length
     * @param A2_size2 2nd Array sub-length
     * @param new_size1 Array length passed by reference
     * @param new_size2 Sub-array length passed by reference
     * @return T** 2D Array
     */
    template <class T, class U> T** opr (T** A1, int A1_size1, int A1_size2, op Operation, U** A2, int A2_size1, int A2_size2, int &new_size1, int &new_size2) {
        if (A1_size1 < 0 || A1_size2 < 0 || A2_size1 < 0 || A2_size2 < 0) throw std::invalid_argument("arraySize must be a positive integer!");
        new_size1 = MAX_I(A1_size1, A2_size1);
        new_size2 = MAX_I(A1_size2, A2_size2);
        T** A3 = new T*[new_size1];
        for (unsigned i = 0; i < new_size1; i++) A3[i] = new T[new_size2];
        for (unsigned i = 0; i < new_size1; i++) for (unsigned j = 0; j < new_size2; j++) A3[i][j] = 0;
        for (unsigned i = 0; i < A1_size1; i++) for (unsigned j = 0; j < A1_size2; j++) A3[i][j] += A1[i][j];
        for (unsigned i = 0; i < A2_size1; i++) {
            for (unsigned j = 0; j < A2_size2; j++) {
                switch (Operation) {
                    case op::add: {A3[i][j] += A2[i][j]; break;}
                    case op::subtract: {A3[i][j] -= A2[i][j]; break;}
                    case op::multiply: {A3[i][j] *= A2[i][j]; break;}
                    case op::divide: {
                        if (A2[i][j] == 0) throw std::invalid_argument("Cannot divide by 0!");
                        A3[i][j] /= A2[i][j];
                        break;
                    }
                    case op::power: {A3[i][j] = pow(A3[i][j], A2[i][j]); break;}
                    case op::mod: {
                        if (A2[i][j] <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                        A3[i][j] %= A2[i][j];
                        break;
                    }
                    default: {throw std::invalid_argument("Unknown operation!");}
                }
            }
        }
        return A3;
    }

    /**
     * @brief Execute operation on two vectors
     * 
     * @tparam T Number
     * @tparam U Number
     * @param A1 1st Vector
     * @param Operation Math Operation
     * @param A2 2nd Vector
     * @return vector < T > 
     */
    template <class T, class U> vector < T > opr (const vector < T > &A1, op Operation, const vector < U > &A2) {
        vector < T > A3;
        unsigned A1_s = A1.size();
        unsigned A2_s = A2.size();
        unsigned A3_s = MAX_I(A1_s, A2_s);
        A3.resize(A3_s);
        for (unsigned i = 0; i < A3_s; i++) A3[i] = 0;
        for (unsigned i = 0; i < A1_s; i++) A3[i] += A1[i];
        for (unsigned i = 0; i < A2_s; i++) {
            switch (Operation) {
                case op::add: {A3[i] += A2[i]; break;}
                case op::subtract: {A3[i] -= A2[i]; break;}
                case op::multiply: {A3[i] *= A2[i]; break;}
                case op::divide: {
                    if (A2[i] == 0) throw std::invalid_argument("Cannot divide by 0!");
                    A3[i] /= A2[i];
                    break;
                }
                case op::power: {A3[i] = pow(A3[i], A2[i]); break;}
                case op::mod: {
                    if (A2[i] <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                    A3[i] %= A2[i];
                    break;
                }
                default: {throw std::invalid_argument("Unknown operation!");}
            }
        }
        return A3;
    }

    /**
     * @brief Execute operation on two lists
     * 
     * @tparam T Number
     * @tparam U Number
     * @param A1 1st List
     * @param Operation Math Operation
     * @param A2 2nd List
     * @return list < T > 
     */
    template <class T, class U> list < T > opr (const list < T > &A1, op Operation, const list < U > &A2) {
        list < T > A3;
        unsigned A1_s = A1.size();
        unsigned A2_s = A2.size();
        if (A1_s > A2_s) {
            auto it2 = A2.cbegin();
            for (auto it = A1.cbegin(); it != A1.cend(); it++) {
                T v1 = *it;
                U v2 = 0;
                if (it2 != A2.cend()) {
                    v2 = *it2;
                    it2++;
                }
                switch (Operation) {
                    case op::add: {A3.push_back(v1 + v2); break;}
                    case op::subtract: {A3.push_back(v1 - v2); break;}
                    case op::multiply: {A3.push_back(v1 * v2); break;}
                    case op::divide: {
                        if (v2 == 0) throw std::invalid_argument("Cannot divide by 0!");
                        A3.push_back(v1 / v2);
                        break;
                    }
                    case op::power: {A3.push_back(pow(v1, v2)); break;}
                    case op::mod: {
                        if (v2 <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                        A3.push_back(v1 % v2);
                        break;
                    }
                    default: {throw std::invalid_argument("Unknown operation!");}
                }
            }
            return A3;
        }
        auto it1 = A1.cbegin();
        for (auto it = A2.cbegin(); it != A2.cend(); it++) {
            U v1 = *it;
            T v2 = 0;
            if (it1 != A1.cend()) {
                v2 = *it1;
                it1++;
            }
            switch (Operation) {
                case op::add: {A3.push_back(v2 + v1); break;}
                case op::subtract: {A3.push_back(v2 - v1); break;}
                case op::multiply: {A3.push_back(v2 * v1); break;}
                case op::divide: {
                    if (v1 == 0) throw std::invalid_argument("Cannot divide by 0!");
                    A3.push_back(v2 / v1);
                    break;
                }
                case op::power: {A3.push_back(pow(v2, v1)); break;}
                case op::mod: {
                    if (v1 <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                    A3.push_back(v2 % v1);
                    break;
                }
                default: {throw std::invalid_argument("Unknown operation!");}
            }
        }
        return A3;
    }

    /**
     * @brief Execute operation on two sets
     * 
     * @tparam T Any
     * @param A1 1st Set
     * @param SetOperation Set Operation
     * @param A2 2nd Set
     * @return set < T > 
     */
    template <class T> set < T > opr (const set < T > &A1, set_op SetOperation, const set < T > &A2) {
        set < T > A3;
        switch (SetOperation) {
            case set_op::sum: {
                for (auto it = A1.cbegin(); it != A1.cend(); it++) A3.insert(*it);
                for (auto it = A2.cbegin(); it != A2.cend(); it++) A3.insert(*it);
                break;
            }
            case set_op::diff: {
                for (auto it = A1.cbegin(); it != A1.cend(); it++) A3.insert(*it);
                for (auto it = A2.cbegin(); it != A2.cend(); it++) {
                    if (A1.find(*it) != A1.cend()) {
                        auto f = A3.find(*it);
                        A3.erase(f);
                    }
                }
                break;
            }
            case set_op::intersect: {
                for (auto it = A1.cbegin(); it != A1.cend(); it++) A3.insert(*it);
                for (auto it = A2.cbegin(); it != A2.cend(); it++) A3.insert(*it);
                for (auto it = A1.cbegin(); it != A1.cend(); it++) {
                    if (A2.find(*it) == A2.cend()) {
                        auto f = A3.find(*it);
                        A3.erase(f);
                    }
                }
                for (auto it = A2.cbegin(); it != A2.cend(); it++) {
                    if (A1.find(*it) == A1.cend()) {
                        auto f = A3.find(*it);
                        A3.erase(f);
                    }
                }
                break;
            }
            case set_op::ex_or: {
                set < T > A1_notA2;
                for (auto it = A1.cbegin(); it != A1.cend(); it++) A1_notA2.insert(*it);
                for (auto it = A2.cbegin(); it != A2.cend(); it++) {
                    if (A1.find(*it) != A1.cend()) {
                        auto f = A1_notA2.find(*it);
                        A1_notA2.erase(f);
                    }
                }
                set < T > A2_notA1;
                for (auto it = A2.cbegin(); it != A2.cend(); it++) A2_notA1.insert(*it);
                for (auto it = A1.cbegin(); it != A1.cend(); it++) {
                    if (A2.find(*it) != A2.cend()) {
                        auto f = A2_notA1.find(*it);
                        A2_notA1.erase(f);
                    }
                }
                for (auto it = A1_notA2.cbegin(); it != A1_notA2.cend(); it++) A3.insert(*it);
                for (auto it = A2_notA1.cbegin(); it != A2_notA1.cend(); it++) A3.insert(*it);
                break;
            }
            default: {throw std::invalid_argument("Unknown operation!");}
        }
        return A3;
    }

    /*
        opr() type 3 - cross-container operations
        Added in 0.5.0
    */
    
    /**
     * @brief Execute operation on dynamic array and vector
     * 
     * @tparam T Number 
     * @tparam U Number
     * @param Array Dynamic Array
     * @param ArraySize Array Size
     * @param Operation Math Operation
     * @param Vec STL Vector
     * @param new_size Result Array length returned by reference
     * @return T* Result Array
     */
    template <class T, class U> T* opr (const T* Array, int ArraySize, op Operation, const vector < U > &STL_Vec, int &new_size) {
        if (ArraySize < 0) throw std::invalid_argument("arraySize must be a positive integer!");
        int VecSize = STL_Vec.size();
        new_size = MAX_I(ArraySize, VecSize);
        T* NewArray = new T[new_size];
        for (unsigned i = 0; i < new_size; i++) NewArray[i] = 0;
        for (unsigned i = 0; i < ArraySize; i++) NewArray[i] += Array[i];
        for (unsigned i = 0; i < VecSize; i++) {
            switch (Operation) {
                case op::add: {NewArray[i] += STL_Vec[i]; break;}
                case op::subtract: {NewArray[i] -= STL_Vec[i]; break;}
                case op::multiply: {NewArray[i] *= STL_Vec[i]; break;}
                case op::divide: {
                    if (STL_Vec[i] == 0) throw std::invalid_argument("Cannot divide by 0!");
                    NewArray[i] /= STL_Vec[i];
                    break;
                }
                case op::power: {NewArray[i] = pow(NewArray[i], STL_Vec[i]); break;}
                case op::mod: {
                    if (STL_Vec[i] <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                    NewArray[i] %= STL_Vec[i];
                    break;
                }
                default: {throw std::invalid_argument("Unknown operation!");}
            }
        }
        return NewArray;
    }

    /**
     * @brief Execute operation on dynamic array and list
     * 
     * @tparam T Number
     * @tparam U Number
     * @param Array Dynamic Array
     * @param ArraySize Array Size
     * @param Operation Math Operation
     * @param STL_List STL List
     * @param new_size Result Array length returned by reference
     * @return T* Result Array
     */
    template <class T, class U> T* opr (const T* Array, int ArraySize, op Operation, const list < U > &STL_List, int &new_size) {
        if (ArraySize < 0) throw std::invalid_argument("arraySize must be a positive integer!");
        int ListSize = STL_List.size();
        new_size = MAX_I(ArraySize, ListSize);
        T* NewArray = new T[new_size];
        for (unsigned i = 0; i < new_size; i++) NewArray[i] = 0;
        for (unsigned i = 0; i < ArraySize; i++) NewArray[i] += Array[i];
        unsigned iter = 0;
        for (auto it = STL_List.cbegin(); it != STL_List.cend(); it++) {
            switch (Operation) {
                case op::add: {NewArray[iter] += *it; break;}
                case op::subtract: {NewArray[iter] -= *it; break;}
                case op::multiply: {NewArray[iter] *= *it; break;}
                case op::divide: {
                    if (*it == 0) throw std::invalid_argument("Cannot divide by 0!");
                    NewArray[iter] /= *it;
                    break;
                }
                case op::power: {NewArray[iter] = pow(NewArray[iter], *it); break;}
                case op::mod: {
                    if (*it <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                    NewArray[iter] %= *it;
                    break;
                }
                default: {throw std::invalid_argument("Unknown operation!");}
            }
            iter++;
        }
        return NewArray;
    }

    /**
     * @brief Execute operation on vector and dynamic array
     * 
     * @tparam T Number
     * @tparam U Number
     * @param STL_Vec STL Vector
     * @param Operation Math Operation
     * @param Array Dynamic Array
     * @param ArraySize Array Size
     * @return vector < T > Result Vector
     */
    template <class T, class U> vector < T > opr (const vector < T > &STL_Vec, op Operation, const U* Array, int ArraySize) {
        if (ArraySize < 0) throw std::invalid_argument("arraySize must be a positive integer!");
        int VecSize = STL_Vec.size();
        int new_size = MAX_I(ArraySize, VecSize);
        vector < T > NewVector;
        NewVector.resize(new_size);
        for (unsigned i = 0; i < new_size; i++) NewVector[i] = 0;
        for (unsigned i = 0; i < VecSize; i++) NewVector[i] += STL_Vec[i];
        for (unsigned i = 0; i < ArraySize; i++) {
            switch (Operation) {
                case op::add: {NewVector[i] += Array[i]; break;}
                case op::subtract: {NewVector[i] -= Array[i]; break;}
                case op::multiply: {NewVector[i] *= Array[i]; break;}
                case op::divide: {
                    if (Array[i] == 0) throw std::invalid_argument("Cannot divide by 0!");
                    NewVector[i] /= Array[i];
                    break;
                }
                case op::power: {NewVector[i] = pow(NewVector[i], Array[i]); break;}
                case op::mod: {
                    if (Array[i] <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                    NewVector[i] %= Array[i];
                    break;
                }
                default: {throw std::invalid_argument("Unknown operation!");}
            }
        }
        return NewVector;
    }

    /**
     * @brief Execute operation on vector and list
     * 
     * @tparam T Number
     * @tparam U Number
     * @param STL_Vec STL Vector
     * @param Operation Math Operation
     * @param STL_List STL List
     * @return vector < T > Result Vector
     */
    template <class T, class U> vector < T > opr (const vector < T > &STL_Vec, op Operation, const list < U > &STL_List) {
        int ListSize = STL_List.size();
        int VecSize = STL_Vec.size();
        int new_size = MAX_I(VecSize, ListSize);
        vector < T > NewVector;
        NewVector.resize(new_size);
        for (unsigned i = 0; i < new_size; i++) NewVector[i] = 0;
        for (unsigned i = 0; i < VecSize; i++) NewVector[i] += STL_Vec[i];
        unsigned iter = 0;
        for (auto it = STL_List.cbegin(); it != STL_List.cend(); it++) {
            switch (Operation) {
                case op::add: {NewVector[iter] += *it; break;}
                case op::subtract: {NewVector[iter] -= *it; break;}
                case op::multiply: {NewVector[iter] *= *it; break;}
                case op::divide: {
                    if (*it == 0) throw std::invalid_argument("Cannot divide by 0!");
                    NewVector[iter] /= *it;
                    break;
                }
                case op::power: {NewVector[iter] = pow(NewVector[iter], *it); break;}
                case op::mod: {
                    if (*it <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                    NewVector[iter] %= *it;
                    break;
                }
                default: {throw std::invalid_argument("Unknown operation!");}
            }
            iter++;
        }
        return NewVector;
    }

    /**
     * @brief Execute operation on list and array
     * 
     * @tparam T Number
     * @tparam U Number
     * @param STL_List STL List
     * @param Operation Math Operation
     * @param Array Dynamic Array
     * @param ArraySize Array size
     * @return list < T > Result List
     */
    template <class T, class U> list < T > opr (const list < T > &STL_List, op Operation, const U* Array, int ArraySize) {
        int ListSize = STL_List.size();
        if (ArraySize < 0) throw std::invalid_argument("arraySize must be a positive integer!");
        int new_size = MAX_I(ListSize, ArraySize);
        list < T > NewList;
        auto it = STL_List.cbegin();
        for (unsigned i = 0; i < new_size; i++) {
            T v1 = 0;
            U v2 = 0;
            if (it != STL_List.cend()) {
                v1 = *it;
                it++;
            }
            if (i < ArraySize) v2 = Array[i];
            switch (Operation) {
                case op::add: {NewList.push_back(v1 + v2); break;}
                case op::subtract: {NewList.push_back(v1 - v2); break;}
                case op::multiply: {NewList.push_back(v1 * v2); break;}
                case op::divide: {
                    if (v2 == 0) throw std::invalid_argument("Cannot divide by 0!");
                    NewList.push_back(v1 / v2);
                    break;
                }
                case op::power: {NewList.push_back(pow(v1, v2)); break;}
                case op::mod: {
                    if (v2 <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                    NewList.push_back(v1 % v2);
                    break;
                }
                default: {throw std::invalid_argument("Unknown operation!");}
            }
        }
        return NewList;
    }

    /**
     * @brief Execute operation on list and vector
     * 
     * @tparam T Number
     * @tparam U Number
     * @param STL_List STL List
     * @param Operation Math operation
     * @param STL_Vec STL Vector
     * @return list < T > Result List
     */
    template <class T, class U> list < T > opr (const list < T > &STL_List, op Operation, const vector < U > &STL_Vec) {
        int ListSize = STL_List.size();
        int VecSize = STL_Vec.size();
        int new_size = MAX_I(ListSize, VecSize);
        list < T > NewList;
        auto it = STL_List.cbegin();
        for (unsigned i = 0; i < new_size; i++) {
            T v1 = 0;
            U v2 = 0;
            if (it != STL_List.cend()) {
                v1 = *it;
                it++;
            }
            if (i < VecSize) v2 = STL_Vec[i];
            switch (Operation) {
                case op::add: {NewList.push_back(v1 + v2); break;}
                case op::subtract: {NewList.push_back(v1 - v2); break;}
                case op::multiply: {NewList.push_back(v1 * v2); break;}
                case op::divide: {
                    if (v2 == 0) throw std::invalid_argument("Cannot divide by 0!");
                    NewList.push_back(v1 / v2);
                    break;
                }
                case op::power: {NewList.push_back(pow(v1, v2)); break;}
                case op::mod: {
                    if (v2 <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                    NewList.push_back(v1 % v2);
                    break;
                }
                default: {throw std::invalid_argument("Unknown operation!");}
            }
        }
        return NewList;
    }
}
#endif // !STL_ADDITIONS_H
