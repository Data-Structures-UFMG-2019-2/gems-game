#ifndef GEMS_GAME_H
#define GEMS_GAME_H

#include<string>

class GemsGame{
    private:
        int* gems = NULL;
        int size = 0;
        int half_sum = 0;
    public:
        GemsGame(std::string filename);
        ~GemsGame();
        int get_size();
        int get_half_sum();
        int knapsack(); // O(nm)
        int read_input(std::string filename); // O(n)
};

#endif