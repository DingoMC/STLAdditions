#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include "stl_additions.h"
using namespace std;
int main() {
    int *a1 = new int[5];
    for (int i = 0; i < 5; i++) a1[i] = i;
    cout<<"1D Dynamic Array: ";
    astl::show(a1, 5, true);
    
    int **a2 = new int*[3];
    for (int i = 0; i < 3; i++) {
        a2[i] = new int[3];
        for (int j = 0; j < 3; j++) a2[i][j] = i + j;
    }
    cout<<"2D Dynamic Array: ";
    astl::show(a2, 3, 3, true);

    vector < int > v1 = {1, 2, 3, 4};
    cout<<"1D Vector: ";
    astl::show(v1, true);

    vector < vector < double > > v2 = {{1.5, 2.07}, {3.058, 4.7}};
    cout<<"2D Vector: ";
    astl::show(v2, true);

    vector < int > *dv = new vector < int >[3];
    for (int i = 0; i < 3; i++) {
        dv[i] = {i, i+1, i+2};
    }
    cout<<"1D Dynamic Array of Vectors: ";
    astl::show(dv, 3, true);

    list<string> l;
    l.push_back("Red");
    l.push_back("Green");
    l.push_back("Blue");
    cout<<"STL List: ";
    astl::show(l, true);

    set <char> s;
    s.insert('C');
    s.insert('B');
    s.insert('A');
    cout<<"STL Set: ";
    astl::show(s, true);

    map <char, int> m;
    m.insert(make_pair('B', 1));
    m.insert(make_pair('C', 2));
    m.insert(make_pair('A', 0));
    cout<<"STL Map: ";
    astl::show(m, true);

    int *a3 = new int[8];
    for (int i = 0; i < 8; i++) a3[i] = i * 2;
    int as_size;
    int *as = astl::add(a1, 5, a3, 8, as_size);
    cout<<"Adding arrays: ";
    astl::show(as, as_size);

    int **a4 = new int*[5];
    for (int i = 0; i < 5; i++) {
        a4[i] = new int[4];
        for (int j = 0; j < 4; j++) a4[i][j] = i * j;
    }
    int as_size1, as_size2;
    int **as2 = astl::add(a2, 3, 3, a4, 5, 4, as_size1, as_size2);
    cout<<"Adding 2D arrays: ";
    astl::show(as2, as_size1, as_size2);

    vector < double > v3 = {4, 3, 2, 1, 5};
    cout<<"Adding vectors: ";
    astl::show(astl::add(v1, v3));

    list <int> l1;
    for (int i = 0; i < 4; i++) l1.push_back(i);
    list <int> l2;
    for (int i = 0; i < 3; i++) l2.push_back((i+1) * 10);
    cout<<"Adding lists: ";
    astl::show(astl::add(l1, l2));

    set <int> s1;
    for (int i = 0; i < 5; i++) s1.insert(i);
    set <int> s2;
    for (int i = 2; i < 10; i++) s2.insert(i);
    cout<<"Adding sets: ";
    astl::show(astl::add(s1, s2));

    map <char, int> m2;
    m2.insert(make_pair('C', 3));
    m2.insert(make_pair('D', 4));
    m2.insert(make_pair('E', 5));
    cout<<"Adding maps: ";
    astl::show(astl::add(m, m2));

    delete[] a1;
    for (int i = 0; i < 3; i++) delete a2[i];
    delete[] a2;
    delete[] a3;
    delete[] as;
    cin.ignore();
    cin.get();
    return 0;
}
