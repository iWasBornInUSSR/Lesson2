#ifndef BitSet_H
#define BitSet_H

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

class BitSet {
public:
    explicit BitSet(char S);

    void show();

    int power();

    BitSet operator|(BitSet);

    BitSet operator&(const BitSet);

    BitSet operator~();

    BitSet &operator=(const BitSet);

    BitSet();

    BitSet(const BitSet &);

    ~BitSet() { delete[](value); }

private:
    int *value;
    static int N;
};

BitSet::BitSet() : value(new int[N]) { value[0] = 0; }

BitSet::BitSet(const BitSet &B) : value(new int[N]) {
    for (int i = 0; i < N; ++i) {
        value[i] = B.value[i];
    }
}

BitSet &BitSet::operator=(const BitSet B) {
    for (int i = 0; i < 26; i++)
        value[i] = B.value[i];
    return *this;
}


BitSet BitSet::operator~() {
    BitSet C(*this);
    for (int i = 0; i < 26; i++)
        C.value[i] = ~value[i];
    return C;
}


BitSet BitSet::operator&(const BitSet B) {
    BitSet C(*this);
    for (int i = 0; i < 26; i++)
        C.value[i] = value[i] & B.value[i];
    return C;
}


BitSet BitSet::operator|(const BitSet B) {
    BitSet C(*this);
    for (int i = 0; i < 26; i++)
        C.value[i] = value[i] | B.value[i];
    return C;
}


BitSet::BitSet(char S) : value(new int[N]) {
    for (int i = 0; i < 26; i++) {
        value[i] = (rand() % 2) & (rand() % 2);
    }

};

void BitSet::show() {
    char arr[52] = {0};
    for (int i = 0, k = 0; i < N; ++i)
        if (value[i] & 1)
            arr[k++] = i + 'A';
    for (int k = 0; arr[k]; ++k) {
        cout << arr[k] << " ";
    }
    cout << endl;
};

int BitSet::power() {
    int n = 0;
    for (int i = 0; i < N; ++i) {
        if (value[i]) n++;
    }

    return n;
}


#endif
