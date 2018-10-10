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
//    srand(time(nullptr));
//    Set A('A'), B('B'), C('C'), D('D'), E;
//    auto begin = clock();
//    for (long q = 0; q < q0; ++q) { E = ((A & ~B) & ~C) | D; }
//    auto end = clock();
//    E.Show();
//    cout << " Middle power =" <<
//    (A.power() + B.power( ) + C.power( ) + D.power( ) + E.power( )) / 5 << " Time=" << end - begin << " / " << q0 << endl;
    srand(time(nullptr));
    SetAsList A('A'), B('B'), C('C'), D('D');
    A.show();
    B.show();
    A &= B;
    A.show();

    return 0;
}
