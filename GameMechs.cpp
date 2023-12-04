#include "GameMechs.h"

// Default constructor
GameMechs::GameMechs() : boardSizeX(30), boardSizeY(15), input('\0'), exitFlag(false) {
    // Default board size set to 30x15
    // Default input set to null character
    // Default exitFlag set to false
}

// Constructor with board size parameters
GameMechs::GameMechs(int boardX, int boardY) : boardSizeX(boardX), boardSizeY(boardY), input('\0'), exitFlag(false) {
    // Initialize other members
}

// Destructor (not needed unless you allocate dynamic memory)
// GameMechs::~GameMechs() {
// Perform cleanup if necessary
// }

bool GameMechs::getExitFlagStatus() {
    return exitFlag;
}

void GameMechs::setExitTrue() {
    exitFlag = true;
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

