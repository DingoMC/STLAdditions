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
    delete a1;

    int **a2 = new int*[3];
    for (int i = 0; i < 3; i++) {
        a2[i] = new int[3];
        for (int j = 0; j < 3; j++) a2[i][j] = i + j;
    }
    cout<<"2D Dynamic Array: ";
    astl::show(a2, 3, 3, true);
    for (int i = 0; i < 3; i++) delete a2[i];
    delete [] a2;

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
    m.insert(make_pair('B', 66));
    m.insert(make_pair('C', 67));
    m.insert(make_pair('A', 65));
    cout<<"STL Map: ";
    astl::show(m, true);

    cin.ignore();
    cin.get();
    return 0;
}