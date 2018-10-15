#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
//#include "source/SetAsList.h"
//#include "source/Set.h"
#include "source/BitSet.h"
//#include "source/binaryWord.h"
using namespace std;
int BitSet::N = 26;
const long q0 = 100000; // количество повторений цикла времени
int main() {
//    srand(time(nullptr));
//    BitSet A('A'), B('B'), C('C'), D('D'), E;
//    auto begin = clock();
//    for (long q = 0; q < q0; ++q) { E = ((A & ~B) & ~C) | D; }
//    auto end = clock();
//    E.show();
//    cout << " Middle power =" <<
//         (A.power() + B.power( ) + C.power( ) + D.power( ) + E.power( )) / 5 << " Time=" << end - begin << " / " << q0 << endl;
//    return 0;
    srand(time(nullptr));
    BitSet A('A'), B('B'), C('C'), D('D'), E;
    A.show();
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
