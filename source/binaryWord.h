#ifndef BINARYWORD_H
#define BINARYWORD_H

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;


class BinarySet {
public:
    BinarySet() : value(0) {};

    explicit BinarySet(char S);

    int generateTestBinary(int alphabet);

    void show();

    int power();

    BinarySet operator|(const BinarySet) const;

    BinarySet operator&(const BinarySet) const;

    BinarySet operator~();

    BinarySet &operator=(const BinarySet);

    ~BinarySet() = default;

private:
    int value;
    static int N;
};


BinarySet::BinarySet(char S) {
    value = generateTestBinary(N);
};

BinarySet BinarySet::operator~() {
    BinarySet C = *this;
    C.value = ~value;
    return C;
}

BinarySet BinarySet::operator&(const BinarySet B) const {
    BinarySet C = *this;
    C.value = value & B.value;
    return C;
}

BinarySet BinarySet::operator|(const BinarySet B) const {
    BinarySet C = *this;
    C.value = value | B.value;
    return C;
}

BinarySet &BinarySet::operator=(const BinarySet B) {
    value = B.value;
    return *this;
}

int BinarySet::generateTestBinary(int alphabet) {
    int w = 0;
    for (int i = 0; i < alphabet; ++i) {
        if (rand() % 2)
            w = w | ((rand() % 2) << i);
    }
    return w;
};


void BinarySet::show() {
    int val = value;
    char arr[26] = {0};
    for (int i = 0, k = 0; i < N; ++i)
        if (val & (1 << i))
            arr[k++] = i + 'A';
    for (int k = 0; arr[k]; ++k) {
        cout << arr[k] << " ";
    }
    cout << endl;
};

int BinarySet::power() {
    int n = 0;
    for (int i = 0; i < N; ++i) {
        if (value & (1 << i)) n++;
    }

    return n;
}


#endif // BINARYWORD_H
