#include<cstdlib>
#include<iostream>

#include"../include/utils.hpp"

int sum(int array[], int n){ // O(n)
    int sum = 0;
    for(int i = 0; i < n; sum += array[i], i++);
    return sum;
}

namespace Matrix {
    bool** create(int m, int n){ // O(nm)
        bool** matrix = (bool**) malloc(m * sizeof(bool*));
        for(int i = 0; i < m; i++){
            matrix[i] = (bool*) calloc(n, sizeof(bool));
            matrix[i][0] = true;
        }
        return matrix;
    }

    void free(bool** matrix, int m){ // O(m)
        for(int i = 0; i < m; i++){
            std::free(matrix[i]);
        }
        std::free(matrix);
    }

    void print(bool** matrix, int m, int n){ // O(nm)
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                std::cout << matrix[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
}