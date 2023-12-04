#include "GameMechs.h"
#include "MacUILib.h"


// Default constructor
GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    boardSizeX = 30; //default board size
    boardSizeY = 15;
}

// Constructor with board size parameters
GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
}

// Destructor (not needed unless you allocate dynamic memory)
// GameMechs::~GameMechs() {
// Perform cleanup if necessary
// }

bool GameMechs::getExitFlagStatus() {
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

void GameMechs::setExitTrue() {
    exitFlag = true;
}

char GameMechs::getInput() {
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    if(input == 27)
    {
        exitFlag = true;
    }
    return input;
}

void GameMechs::setInput(char this_input) {
    input = this_input;
}

void GameMechs::clearInput() {
    input = 0; // Reset input to the null character
}

int GameMechs::getBoardSizeX() {
    return boardSizeX;
}

int GameMechs::getBoardSizeY() {
    return boardSizeY;
}
void GameMechs::setLoseFlag()
{
    loseFlag = true;
}
int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}