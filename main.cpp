#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "source/SetAsList.h"
using namespace std;
int SetAsList::N = 26;
const long q0 = 100000; // количество повторений цикла времени
int main() {
    /*srand(time(nullptr));
    Set A('A'), B('B'), C('C'), D('D'), E;
    auto begin = clock();
    for (long q = 0; q < q0; ++q) { E = ((A & ~B) & ~C) | D; }
    auto end = clock();
    E.show();
    cout << " Middle power =" <<
         (A.power() + B.power( ) + C.power( ) + D.power( ) + E.power( )) / 5 << " Time=" << end - begin << " / " << q0 << endl;
    return 0;*/
    srand(time(nullptr));
    SetAsList A('A'), B('B'), C('C'), D('D'), E;
    auto begin = clock();
    for (long q = 0; q < q0; ++q) { E = ((A & ~B) & ~C) | D; }
    auto end = clock();
    A.show();
    B.show();
    C.show();
    D.show();
    E.show();
    cout << " Middle power =" <<
         (A.power() + B.power() + C.power() + D.power() + E.power()) / 5 << " Time=" << end - begin << " / " << q0
         << endl;
    return 0;
}
