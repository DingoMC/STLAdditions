#ifndef STL_ADDITIONS_H
#define STL_ADDITIONS_H
#include <iostream>
#include <typeinfo>
#include <stdexcept>
#include <vector>
#include <list>
#include <set>
#include <map>
#pragma GCC optimize("O3")
using namespace std;
namespace astl {
    // Function prototypes
    template<class T> void show(T Elem, bool = false, bool = false);
    template<class T> void show(T* Array, int, bool showType = false, bool = false);
    template<class T> void show(T** Array, int, int, bool showType = false, bool = false);
    template<class T> void show(const vector<T> &Vec, bool showType = false, bool = false);
    template<class T> void show(const list<T> &List, bool showType = false, bool = false);
    template<class T> void show(const set<T> &Set, bool showType = false, bool = false);
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
        if (arraySize < 0) {
            throw std::invalid_argument("arraySize must be a positive integer!");
        }
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
        if (arraySize1 < 0 || arraySize2 < 0) {
            throw std::invalid_argument("arraySize must be a positive integer!");
        }
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
     * @param Vec STL Vector
     * @param showType Default to false. When true it also shows type of iterable element.
     */
    template<class T> void show (const vector < T > &Vec, bool showType, bool fromRecursion) {
        unsigned V_size = Vec.size();
        if (showType) cout<<"`Vector` ";
        cout<<"[";
        for (unsigned i = 0; i < V_size; i++) {
            show(Vec[i], showType, true);
            if (i < V_size - 1) cout<<", ";
        }
        cout<<"]";
        if (!fromRecursion) cout<<endl;
    }

    /**
     * @brief Show STL List
     * 
     * @tparam T List Element Type
     * @param List STL List
     * @param showType Default to false. When true it also shows type of iterable element.
     */
    template<class T> void show (const list < T > &List, bool showType, bool fromRecursion) {
        if (showType) cout<<"`List` ";
        cout<<"[";
        for (auto it = List.cbegin(); it != List.cend(); it++) {
            if (it != List.cbegin()) cout<<", ";
            show(*it, showType, true);
        }
        cout<<"]";
        if (!fromRecursion) cout<<endl;
    }

    /**
     * @brief Show STL Set
     * 
     * @tparam T Set Element Type
     * @param Set STL Set
     * @param showType Default to false. When true it also shows type of iterable element.
     */
    template<class T> void show (const set < T > &Set, bool showType, bool fromRecursion) {
        if (showType) cout<<"`Set` ";
        cout<<"{";
        for (auto it = Set.cbegin(); it != Set.cend(); it++) {
            if (it != Set.cbegin()) cout<<", ";
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
}
#endif // !STL_ADDITIONS_H