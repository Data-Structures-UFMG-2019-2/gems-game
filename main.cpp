#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cmath>

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

int knapsack(int array[], int size){ // O(nm)
    int array_sum = sum(array, size);
    int m = (size+1), n = floor(((float)array_sum)/2.0) + 1;
    bool** occurences = Matrix::create(m, n);

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(occurences[i-1][j]){
                occurences[i][j] = true;
            }
            else if(j >= array[i-1] && occurences[i-1][j-array[i-1]]){
                occurences[i][j] = true;
            }
        }
    }
    Matrix::print(occurences, m, n);

    for(int i = n-1; i >= 0; i--){
        if(occurences[m-1][i]){
            Matrix::free(occurences, m);
            return array_sum - (2*i);
        }
    }
    Matrix::free(occurences, m);
    return -1;
}

int read_input(int** array_ref, std::string filename){
    int n = 0;
    std::ifstream file = std::ifstream(filename);
    if(!file.is_open()){
        throw "File not found";
    }

    file >> n;
    *array_ref = (int*) malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        file >> (*array_ref)[i];
    }
    return n;
}

int main(int argc, char const *argv[]){
    int* gems = NULL;
    int n;
    
    if(argc > 1){
        try{
            n = read_input(&gems, argv[1]);
        }
        catch(char const* e){
            std::cerr << e << std::endl;
            exit(404);
        }
    }
    else{
        std::cout << "Not enough arguments" << std::endl;
        exit(1);
    }
    std::cout << knapsack(gems, n) << std::endl;

    free(gems);
    return 0;
}
