#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;

        bool loseFlag;
        int score;

        int boardSizeX;
        int boardSizeY;
        objPos foodPos;  // For tracking food position


public:
        GameMechs();
        GameMechs(int boardX, int boardY);

        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);
        bool getExitFlagStatus();
        void setExitTrue();

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX();
        int getBoardSizeY();

        bool getLoseFlagStatus();//added
        int getScore();//added
        void incrementScore();//added      
        void setLoseFlag(); //added



};

void GameMechs::generateFood(objPos blockOff) {
    srand(time(NULL)); // Seed the random number generator
    do {
        foodPos.x = rand() % boardSizeX;
        foodPos.y = rand() % boardSizeY;
    } while (foodPos.x == blockOff.x && foodPos.y == blockOff.y);
    foodPos.symbol = '*'; // Set the food symbol
}

void GameMechs::getFoodPos(objPos &returnPos) {
    returnPos = foodPos;
}


#endif