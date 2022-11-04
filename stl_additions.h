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
enum op {add = 0, subtract = 1, multiply = 2, divide = 3, power = 4, mod = 5};
namespace astl {
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
        switch (Operation) {
            case op::add: {
                for (unsigned i = 0; i < ArraySize; i++) NewArray[i] = Array[i] + Constant;
                break;
            }
            case op::subtract: {
                for (unsigned i = 0; i < ArraySize; i++) NewArray[i] = Array[i] - Constant;
                break;
            }
            case op::multiply: {
                for (unsigned i = 0; i < ArraySize; i++) NewArray[i] = Array[i] * Constant;
                break;
            }
            case op::divide: {
                if (Constant == 0) throw std::invalid_argument("Cannot divide by 0!");
                for (unsigned i = 0; i < ArraySize; i++) NewArray[i] = Array[i] / Constant;
                break;
            }
            case op::power: {
                for (unsigned i = 0; i < ArraySize; i++) NewArray[i] = pow(Array[i], Constant);
                break;
            }
            case op::mod: {
                if (Constant <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                for (unsigned i = 0; i < ArraySize; i++) NewArray[i] = Array[i] % Constant;
                break;
            }
            default: {throw std::invalid_argument("Unknown operation!");}
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
    template <class T> vector < T > opr (const vector < T > STL_Vec, op Operation, T Constant) {
        vector < T > NewVector;
        int ArraySize = STL_Vec.size();
        NewVector.resize(ArraySize);
        switch (Operation) {
            case op::add: {
                for (unsigned i = 0; i < ArraySize; i++) NewVector[i] = STL_Vec[i] + Constant;
                break;
            }
            case op::subtract: {
                for (unsigned i = 0; i < ArraySize; i++) NewVector[i] = STL_Vec[i] - Constant;
                break;
            }
            case op::multiply: {
                for (unsigned i = 0; i < ArraySize; i++) NewVector[i] = STL_Vec[i] * Constant;
                break;
            }
            case op::divide: {
                if (Constant == 0) throw std::invalid_argument("Cannot divide by 0!");
                for (unsigned i = 0; i < ArraySize; i++) NewVector[i] = STL_Vec[i] / Constant;
                break;
            }
            case op::power: {
                for (unsigned i = 0; i < ArraySize; i++) NewVector[i] = pow(STL_Vec[i], Constant);
                break;
            }
            case op::mod: {
                if (Constant <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                for (unsigned i = 0; i < ArraySize; i++) NewVector[i] = STL_Vec[i] % Constant;
                break;
            }
            default: {throw std::invalid_argument("Unknown operation!");}
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
    template <class T> list < T > opr (const list < T > STL_List, op Operation, T Constant) {
        list < T > NewList;
        switch (Operation) {
            case op::add: {
                for (auto it = STL_List.cbegin(); it != STL_List.cend(); it++) NewList.push_back(*it + Constant);
                break;
            }
            case op::subtract: {
                for (auto it = STL_List.cbegin(); it != STL_List.cend(); it++) NewList.push_back(*it - Constant);
                break;
            }
            case op::multiply: {
                for (auto it = STL_List.cbegin(); it != STL_List.cend(); it++) NewList.push_back(*it * Constant);
                break;
            }
            case op::divide: {
                if (Constant == 0) throw std::invalid_argument("Cannot divide by 0!");
                for (auto it = STL_List.cbegin(); it != STL_List.cend(); it++) NewList.push_back(*it / Constant);
                break;
            }
            case op::power: {
                for (auto it = STL_List.cbegin(); it != STL_List.cend(); it++) NewList.push_back(pow(*it, Constant));
                break;
            }
            case op::mod: {
                if (Constant <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                for (auto it = STL_List.cbegin(); it != STL_List.cend(); it++) NewList.push_back(*it % Constant);
                break;
            }
            default: {throw std::invalid_argument("Unknown operation!");}
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
    template <class T> set < T > opr (const set < T > STL_Set, op Operation, T Constant) {
        set < T > NewSet;
        switch (Operation) {
            case op::add: {
                for (auto it = STL_Set.cbegin(); it != STL_Set.cend(); it++) NewSet.insert(*it + Constant);
                break;
            }
            case op::subtract: {
                for (auto it = STL_Set.cbegin(); it != STL_Set.cend(); it++) NewSet.insert(*it - Constant);
                break;
            }
            case op::multiply: {
                for (auto it = STL_Set.cbegin(); it != STL_Set.cend(); it++) NewSet.insert(*it * Constant);
                break;
            }
            case op::divide: {
                if (Constant == 0) throw std::invalid_argument("Cannot divide by 0!");
                for (auto it = STL_Set.cbegin(); it != STL_Set.cend(); it++) NewSet.insert(*it / Constant);
                break;
            }
            case op::power: {
                for (auto it = STL_Set.cbegin(); it != STL_Set.cend(); it++) NewSet.insert(pow(*it, Constant));
                break;
            }
            case op::mod: {
                if (Constant <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                for (auto it = STL_Set.cbegin(); it != STL_Set.cend(); it++) NewSet.insert(*it % Constant);
                break;
            }
            default: {throw std::invalid_argument("Unknown operation!");}
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
    template <class T, class U> map < T, U > opr (const map < T, U > STL_Map, op Operation, U Constant) {
        map < T, U > NewMap;
        switch (Operation) {
            case op::add: {
                for (typename map<T, U>::const_iterator it = STL_Map.begin(); it != STL_Map.end(); ++it) NewMap.insert(make_pair(it->first, it->second + Constant));
                break;
            }
            case op::subtract: {
                for (typename map<T, U>::const_iterator it = STL_Map.begin(); it != STL_Map.end(); ++it) NewMap.insert(make_pair(it->first, it->second - Constant));
                break;
            }
            case op::multiply: {
                for (typename map<T, U>::const_iterator it = STL_Map.begin(); it != STL_Map.end(); ++it) NewMap.insert(make_pair(it->first, it->second * Constant));
                break;
            }
            case op::divide: {
                if (Constant == 0) throw std::invalid_argument("Cannot divide by 0!");
                for (typename map<T, U>::const_iterator it = STL_Map.begin(); it != STL_Map.end(); ++it) NewMap.insert(make_pair(it->first, it->second / Constant));
                break;
            }
            case op::power: {
                for (typename map<T, U>::const_iterator it = STL_Map.begin(); it != STL_Map.end(); ++it) NewMap.insert(make_pair(it->first, pow(it->second, Constant)));
                break;
            }
            case op::mod: {
                if (Constant <= 0) throw std::invalid_argument("Cannot do modulo less or equal 0!");
                for (typename map<T, U>::const_iterator it = STL_Map.begin(); it != STL_Map.end(); ++it) NewMap.insert(make_pair(it->first, it->second % Constant));
                break;
            }
            default: {throw std::invalid_argument("Unknown operation!");}
        }
        return NewMap;
    }

    /**
     * @brief Adds two 1D Arrays
     * 
     * @tparam T Number
     * @tparam U Number
     * @param A1 1st Array
     * @param size_A1 1st Array size
     * @param A2 2nd Array
     * @param size_A2 2nd Array size
     * @param new_size Array size passed by reference
     * @return T* 1D Array
     */
    template <class T, class U> T* add (const T* A1, int size_A1, const U* A2, int size_A2, int &new_size) {
        if (size_A1 < 0 || size_A2 < 0) throw std::invalid_argument("arraySize must be a positive integer!");
        new_size = MAX_I(size_A1, size_A2);
        T* A3 = new T[new_size];
        for (unsigned i = 0; i < new_size; i++) A3[i] = 0;
        for (unsigned i = 0; i < size_A1; i++) A3[i] += A1[i];
        for (unsigned i = 0; i < size_A2; i++) A3[i] += A2[i];
        return A3;
    }

    /**
     * @brief Adds two 2D Arrays
     * 
     * @tparam T Number
     * @tparam U Number
     * @param A1 1st 2D Array
     * @param A1_size1 1st Array length
     * @param A1_size2 1st Array sub-length
     * @param A2 2nd 2D Array
     * @param A2_size1 2nd Array length
     * @param A2_size2 2nd Array sub-length
     * @param new_size1 Array length passed by reference
     * @param new_size2 Sub-array length passed by reference
     * @return T** 2D Array
     */
    template <class T, class U> T** add (T** A1, int A1_size1, int A1_size2, U** A2, int A2_size1, int A2_size2, int &new_size1, int &new_size2) {
        if (A1_size1 < 0 || A1_size2 < 0 || A2_size1 < 0 || A2_size2 < 0) throw std::invalid_argument("arraySize must be a positive integer!");
        new_size1 = MAX_I(A1_size1, A2_size1);
        new_size2 = MAX_I(A1_size2, A2_size2);
        T** A3 = new T*[new_size1];
        for (unsigned i = 0; i < new_size1; i++) A3[i] = new T[new_size2];
        for (unsigned i = 0; i < new_size1; i++) for (unsigned j = 0; j < new_size2; j++) A3[i][j] = 0;
        for (unsigned i = 0; i < A1_size1; i++) for (unsigned j = 0; j < A1_size2; j++) A3[i][j] += A1[i][j];
        for (unsigned i = 0; i < A2_size1; i++) for (unsigned j = 0; j < A2_size2; j++) A3[i][j] += A2[i][j];
        return A3;
    }

    /**
     * @brief Adds two vectors
     * 
     * @tparam T Number
     * @tparam U Number
     * @param A1 1st Vector
     * @param A2 2nd Vector
     * @return vector < T > 
     */
    template <class T, class U> vector < T > add (const vector < T > &A1, const vector < U > &A2) {
        vector < T > A3;
        unsigned A1_s = A1.size();
        unsigned A2_s = A2.size();
        unsigned A3_s = MAX_I(A1_s, A2_s);
        A3.resize(A3_s);
        for (unsigned i = 0; i < A3_s; i++) A3[i] = 0;
        for (unsigned i = 0; i < A1_s; i++) A3[i] += A1[i];
        for (unsigned i = 0; i < A2_s; i++) A3[i] += A2[i];
        return A3;
    }

    /**
     * @brief Adds two lists
     * 
     * @tparam T Number
     * @tparam U Number
     * @param A1 1st List
     * @param A2 2nd List
     * @return list < T > 
     */
    template <class T, class U> list < T > add (const list < T > &A1, const list < U > &A2) {
        list < T > A3;
        unsigned A1_s = A1.size();
        unsigned A2_s = A2.size();
        if (A1_s > A2_s) {
            auto it2 = A2.cbegin();
            for (auto it = A1.cbegin(); it != A1.cend(); it++) {
                if (it2 != A2.cend()) {
                    A3.push_back(*it + *it2);
                    it2++;
                }
                else A3.push_back(*it);
            }
            return A3;
        }
        auto it1 = A1.cbegin();
        for (auto it = A2.cbegin(); it != A2.cend(); it++) {
            if (it1 != A1.cend()) {
                A3.push_back(*it + *it1);
                it1++;
            }
            else A3.push_back(*it);
        }
        return A3;
    }

    /**
     * @brief Adds two sets (union)
     * 
     * @tparam T Any
     * @param A1 1st Set
     * @param A2 2nd Set
     * @return set < T > 
     */
    template <class T> set < T > add (const set < T > &A1, const set < T > &A2) {
        set < T > A3;
        for (auto it = A1.cbegin(); it != A1.cend(); it++) A3.insert(*it);
        for (auto it = A2.cbegin(); it != A2.cend(); it++) A3.insert(*it);
        return A3;
    }

    /**
     * @brief Adds two maps (repeated keys will result in adding two values)
     * 
     * @tparam T Key
     * @tparam U Value
     * @param A1 1st Map
     * @param A2 2nd Map
     * @return map < T, U > 
     */
    template <class T, class U> map < T, U > add (const map < T, U > &A1, const map < T, U > &A2) {
        map < T, U > A3; 
        for (typename map<T, U>::const_iterator it = A1.begin(); it != A1.end(); ++it) {
            auto it2 = A2.find(it->first);
            if (it2 == A2.end()) A3.insert(make_pair(it->first, it->second));
            else A3.insert(make_pair(it->first, (it->second + it2->second)));
        }
        for (typename map<T, U>::const_iterator it = A2.begin(); it != A2.end(); ++it) {
            auto it2 = A3.find(it->first);
            if (it2 == A3.end()) A3.insert(make_pair(it->first, it->second));
        }
        return A3;
    }
}
#endif // !STL_ADDITIONS_H
