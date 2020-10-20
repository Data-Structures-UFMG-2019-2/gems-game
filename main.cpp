#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<chrono>

#include"./include/gems_game.hpp"

int main(int argc, char const *argv[]){
    GemsGame* game;
    
    if(argc > 1){
        try{
            game = new GemsGame(argv[1]);

            auto start = std::chrono::high_resolution_clock::now();
            std::cout << game->knapsack() << std::endl;
            auto end = std::chrono::high_resolution_clock::now(); 
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            
            if(argc>2){
                std::ofstream time_log_file;
                time_log_file.open("./output/time_log.csv", std::ios_base::app);
                time_log_file << game->get_size() << "," << game->get_half_sum() << "," << duration.count() << std::endl;
                time_log_file.close();
            }
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

    delete game;
    return 0;
}
