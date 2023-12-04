#include "GameMechs.h"
#include "MacUILib.h"

<<<<<<< HEAD
// Default constructor
GameMechs::GameMechs() : boardSizeX(30), boardSizeY(15), input('\0'), exitFlag(false) {
    // Default board size set to 30x15
    // Default input set to null character
    // Default exitFlag set to false
}

// Constructor with board size parameters
GameMechs::GameMechs(int boardX, int boardY) : boardSizeX(boardX), boardSizeY(boardY), input('\0'), exitFlag(false) {
    // Initialize other members
=======

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
>>>>>>> c60b4632cdf69a7c8db27804c8c85692b5fd863c
}

// Destructor (not needed unless you allocate dynamic memory)
// GameMechs::~GameMechs() {
// Perform cleanup if necessary
// }

bool GameMechs::getExitFlagStatus() {
    return exitFlag;
<<<<<<< HEAD
=======
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
>>>>>>> c60b4632cdf69a7c8db27804c8c85692b5fd863c
}

void GameMechs::setExitTrue() {
    exitFlag = true;
<<<<<<< HEAD
}

char GameMechs::getInput() {
    return input;
}

void GameMechs::setInput(char this_input) {
    input = this_input;
}

void GameMechs::clearInput() {
    input = '\0'; // Reset input to the null character
}

int GameMechs::getBoardSizeX() {
    return boardSizeX;
}

int GameMechs::getBoardSizeY() {
    return boardSizeY;
}

void GameMechs::generateFood(objPosArrayList* snakeBody) {
    srand(time(NULL)); // Seed the random number generator
    bool positionOK;
    do {
        positionOK = true;
        foodPos.x = rand() % boardSizeX;
        foodPos.y = rand() % boardSizeY;

        // Ensure food is not generated on the snake's body
        for (int i = 0; i < snakeBody->getSize(); i++) {
            objPos segment;
            snakeBody->getElement(segment, i);
            if (segment.x == foodPos.x && segment.y == foodPos.y) {
                positionOK = false;
                break;
            }
        }
    } while (!positionOK);
    foodPos.symbol = '*'; // Set the food symbol
}

void GameMechs::getFoodPos(objPos &returnPos) {
    returnPos = foodPos;
}

=======
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
>>>>>>> c60b4632cdf69a7c8db27804c8c85692b5fd863c
