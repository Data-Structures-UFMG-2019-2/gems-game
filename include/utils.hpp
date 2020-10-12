#ifndef UTILS_H
#define UTILS_H

int sum(int array[], int n); // O(n)

namespace Matrix {
    bool** create(int m, int n); // O(nm)
    void free(bool** matrix, int m); // O(m)
    void print(bool** matrix, int m, int n); // O(nm)
}

#endif