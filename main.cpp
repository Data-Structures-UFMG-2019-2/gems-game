#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cmath>

#include"./include/gems_game.hpp"

int main(int argc, char const *argv[]){
    GemsGame* game;
    
    if(argc > 1){
        try{
            game = new GemsGame(argv[1]);
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
    std::cout << game->knapsack() << std::endl;

    delete game;
    return 0;
}
