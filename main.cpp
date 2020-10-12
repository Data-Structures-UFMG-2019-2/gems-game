#include<iostream>
#include<cstdlib>
#include<cmath>

int sum(int array[], int n){ // O(n)
    int sum = 0;
    for(int i = 0; i < n; sum += array[i], i++);
    return sum;
}

int** knapsack(int array[], int n){
    bool** occurences = (bool**) malloc((n+1) * sizeof(bool*));
    int array_sum = sum(array, n);
    for(int i = 0; i < n; i++){
        occurences[i] = (bool*) malloc(ceil(array_sum/2) * sizeof(bool));
        occurences[i][0] = true;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < ceil(array_sum/2); j++){
            if(occurences[i-1][j]){
                occurences[i][j] = true;
            }
            else{
                
            }
        }
    }
    return NULL;
}

int main(int argc, char const *argv[]){
    int array[6] = {1, 4, 8, 1, 2, 7};
    knapsack(array, 6);
    return 0;
}
