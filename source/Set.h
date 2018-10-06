
#ifndef LESSON2_SET_H
#define LESSON2_SET_H
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

class Set {
private:
    static int N;
    int n;
    char S, *A;
public:
    Set operator | (const Set&) const;
    Set operator & (const Set&) const;
    Set & operator |= (const Set&);
    Set & operator &= (const Set&);
    Set operator ~ ( ) const;
    void Show( );
    int power( ) { return n; }
    explicit Set(char);
    Set( );
    Set(const Set &);
    Set(Set &&);
    Set & operator = (const Set &);
    Set &  operator = (Set &&);
    ~Set( ) { delete [ ] A; }
};
//constructors
//default
Set :: Set( ): n(0), S ('0'), A(new char[ N+1 ])
{ A[ 0 ] = 0; }
//random
Set :: Set(char s): S(s), n(0), A(new char[ N+1 ])
{
    for (int i = 0; i < N; i++)
        if (rand() % 2) A[ n++ ] = i + 'A';
    A[n] = 0;
    cout << '\n' << S << " = [" << A << "]";
}
// init with copy
Set :: Set(const Set & B) : S(B.S), n(B.n), A(new char[N+1])
{ char *s(B.A), *t(A);
    while(*t++ = *s++); //!   ?
}
// C++ 11 constructor
Set :: Set(Set && B) : S(B.S), n(B.n), A(B.A) //Копирование с переносом
{
    B.A = nullptr;
}

//operators
Set& Set :: operator &= (const Set & B)
{ Set C(*this);
    n = 0;
    for (int i = 0; i < C.n; ++i) {
        for (int j = 0; j < B.n; j++)
            if (C.A[ i ] == B.A[ j ]) A[ n++ ] = C.A[ i ];
    }
    A[ n ] = 0;
    return *this;
}
Set Set :: operator & (const Set & B) const
{ Set C(*this);
    return (C &= B);
}

Set & Set :: operator |= (const Set & B)
{ for(int i = 0; i < B.n; ++i) {
        bool f = true;
        for (int j = 0; j < n; ++j)
            if (B.A[ i ] == A[ j ]) f = false;
        if (f) A[ n++ ] = B.A[ i ];
    }
    A[ n ] = 0;
    return *this;
}
Set Set :: operator | (const Set & B) const
{ Set C(*this);
    return (C |= B);
}

Set Set :: operator ~ ( ) const
{ Set C;
    for (char c = 'A'; c <= 'Z'; ++c) {
        bool f = true;
        for (int j = 0; j < n; ++j)
            if (c == A[ j ]) { f = false; break; }
        if (f) C.A[ C.n++ ] = c;
    }
    C.A[ C.n ] = 0;
    return C;
}



void Set :: Show()
{ cout << "\n" << S << " = [" << A << "]"; }



Set & Set :: operator = (const Set& B)
{ if (this != &B)
    { char *s(B.A), *t(A); n = B.n; S = 'R';
        while(*t++ = *s++); }
    return *this;
}
//C++ operator
Set & Set :: operator = (Set&& B) //Присваивание с переносом
{ if (this != &B)
    { n = B.n; A = B.A; S = 'R'; B.A = nullptr; }
    return *this;
}
#endif //LESSON2_SET_H
