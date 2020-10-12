#ifndef GEMS_GAME_H
#define GEMS_GAME_H

#include<string>

class GemsGame{
    private:
        int* gems = NULL;
        int size = 0;
    public:
        GemsGame(std::string filename);
        ~GemsGame();
        int knapsack(); // O(nm)
        int read_input(std::string filename); // O(1)
};

#endif