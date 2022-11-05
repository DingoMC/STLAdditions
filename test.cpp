#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include "stl_additions.h"
using namespace std;
int main() {
    // Example data
    int *array_1D = new int[5];                         // array_1D = [0, 1, 2, 3, 4]
    for (int i = 0; i < 5; i++) array_1D[i] = i;
    int *array_1D_2 = new int[8];                       // array_1D_2 = [2, 4, 6, 8, 10, 12, 14, 16]
    for (int i = 0; i < 8; i++) array_1D_2[i] = (i + 1) * 2;
    int **array_2D = new int*[3];                       // array_2D = [[0, 1], [1, 2], [2, 3]]
    for (int i = 0; i < 3; i++) array_2D[i] = new int[2];
    for (int i = 0; i < 3; i++) for (int j = 0; j < 2; j++) array_2D[i][j] = i + j;
    int **array_2D_2 = new int*[4];                     // array_2D_2 = [[1, 1, 1, 1], [2, 4, 6, 8], [3, 6, 9, 12], [4, 8, 12, 16]]
    for (int i = 0; i < 4; i++) array_2D_2[i] = new int[4];
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) array_2D_2[i][j] = (i + 1) * (j + 1);
    vector < int > vec_1 = {1, 3, 5, 7, 9, 11};
    vector < int > vec_2 = {0, 2, 4, 6, 8};
    list < int > list_1;                                // list_1 = [3, 6, 9, 12, 15]
    for (int i = 0; i < 5; i++) list_1.push_back((i + 1) * 3);
    list < int > list_2;                                // list_2 = [3, 4, 5, 6]
    for (int i = 0; i < 4; i++) list_2.push_back(i + 3);
    set < int > set_1;                                  // set_1 = {1, 2, 3, 4}
    for (int i = 0; i < 4; i++) set_1.insert(i + 1);
    set < int > set_2;                                  // set_2 = {3, 4, 5, 6, 7, 8, 9}
    for (int i = 0; i < 7; i++) set_2.insert(i + 3);
    map <char, int> map_1;                              // map_1 = {A: 0, B: 1, C: 2}
    for (int i = 0; i < 3; i++) map_1.insert(make_pair((char) (i + 65), i));
    map <char, int> map_2;                              // map_2 = {C: 1, D: 2, E: 3, F: 4}
    for (int i = 0; i < 4; i++) map_2.insert(make_pair((char) (i + 67), i + 1));

    // Show functions
    /*
    astl::show(array_1D, 5, true);
    astl::show(array_2D, 3, 2, true);
    astl::show(vec_1, true);
    astl::show(list_1, true);
    astl::show(set_1, true);
    astl::show(map_1, true);*/

    // Test operations on two conatiners
    /*int aa_size;
    int *array_added = astl::opr(array_1D, 5, op::add, array_1D_2, 8, aa_size);
    astl::show(array_added, aa_size, true);
    int aa2_size1, aa2_size2;
    int **array2D_added = astl::opr(array_2D, 3, 2, op::add, array_2D_2, 4, 4, aa2_size1, aa2_size2);
    astl::show(array2D_added, aa2_size1, aa2_size2, true);
    astl::show(astl::opr(vec_2, op::add, vec_1), true);
    astl::show(astl::opr(list_2, op::add, list_1), true);
    astl::show(astl::opr(set_1, set_op::sum, set_2), true);*/

    // Test operation with constants on containers
    /*
    astl::show(astl::opr(array_1D, 5, op::add, 2), 5, true);
    astl::show(astl::opr(array_2D, 3, 2, op::add, 2), 3, 2, true);
    astl::show(astl::opr(vec_1, op::add, 2), true);
    astl::show(astl::opr(list_1, op::add, 2), true);
    astl::show(astl::opr(set_1, op::add, 2), true);
    astl::show(astl::opr(map_1, op::add, 2), true);*/

    // Test cross-container operations
    /*
    int aa_size;
    int *array_added = astl::opr(array_1D, 5, op::add, vec_2, aa_size);
    astl::show(array_added, aa_size, true);
    array_added = astl::opr(array_1D, 5, op::add, list_1, aa_size);
    astl::show(array_added, aa_size, true);
    astl::show(astl::opr(vec_1, op::add, array_1D_2, 8));
    astl::show(astl::opr(vec_1, op::add, list_1));
    astl::show(astl::opr(list_1, op::add, array_1D, 5));
    astl::show(astl::opr(list_1, op::add, vec_2));*/
    
    // Free memory to prevent leaks
    delete[] array_1D;
    delete[] array_1D_2;
    for (int i = 0; i < 3; i++) delete[] array_2D[i];
    delete[] array_2D;
    for (int i = 0; i < 4; i++) delete[] array_2D_2[i];
    delete[] array_2D_2;
    cin.ignore();
    cin.get();
    return 0;
}
