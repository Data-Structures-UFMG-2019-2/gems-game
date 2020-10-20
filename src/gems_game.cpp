#include<fstream>
#include<string>
#include<cstdlib>
#include<cmath>

#include"../include/gems_game.hpp"
#include"../include/utils.hpp"

GemsGame::GemsGame(std::string filename){
    this->read_input(filename);
}

GemsGame::~GemsGame(){
    free(this->gems);
}

int GemsGame::get_size(){
    return this->size;
}

int GemsGame::get_half_sum(){
    return this->half_sum;
}

int GemsGame::knapsack(){
    int array_sum = sum(this->gems, this->size);
    int m = (this->size+1), n = this->half_sum;
    bool** occurences = Matrix::create(m, n);

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(occurences[i-1][j]){
                occurences[i][j] = true;
            }
            else if(j >= this->gems[i-1] && occurences[i-1][j-this->gems[i-1]]){
                occurences[i][j] = true;
            }
        }
    }
    // Matrix::print(occurences, m, n);

    for(int i = n-1; i >= 0; i--){
        if(occurences[m-1][i]){
            Matrix::free(occurences, m);
            return array_sum - (2*i);
        }
    }
    Matrix::free(occurences, m);
    return -1;
}

int GemsGame::read_input(std::string filename){
    int sum = 0;

    std::ifstream file = std::ifstream(filename);
    if(!file.is_open()){
        throw "File not found";
    }

    file >> this->size;
    this->gems = (int*) malloc(this->size*sizeof(int));
    for(int i = 0; i < this->size; i++){
        file >> this->gems[i];
        sum += this->gems[i];
    }
    this->half_sum = floor(((float)sum)/2.0) + 1;
    return this->size;
}