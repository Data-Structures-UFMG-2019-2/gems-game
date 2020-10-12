#include<fstream>
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

int main(int argc, char* argv[]){
    if(argc < 3){
        std::cout << "Not enough arguments" << std::endl;
        exit(1);
    }

    int n = atoi(argv[1]);
    std::ofstream file;
    file.open(argv[2]);
    srand(time(NULL));

    file << n << std::endl;
    for(int i = 0; i < n; i++){
        file << 1+(rand()%128) << " ";
    }
    file.close();
}