#include "Player.h"

Player::Player(GameMechs* thisGMRef) {
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPosList = new objPosArrayList(); // Initialize the list
    // Insert the initial position
    objPos initialPos(10, 10, '*');
    playerPosList->insertHead(initialPos);
}

Player::~Player() {
    delete playerPosList; // Free the list
}

void Player::getPlayerPosList(objPosArrayList*& returnList) {
    returnList = playerPosList;
}

void Player::updatePlayerDir() {
    // Existing implementation
}

int Player::getScore() {
    return playerPosList->getSize() - 1;
}

void Player::movePlayer() {
    objPos newHead;
    playerPosList->getHeadElement(newHead);


    // Update new head position based on current direction
    switch (myDir) {
        case UP:    newHead.y--; break;
        case DOWN:  newHead.y++; break;
        case LEFT:  newHead.x--; break;
        case RIGHT: newHead.x++; break;
        case STOP:
            // Handle STOP case if needed
            break;
        default:
            // Optional: handle unknown direction
            break;
    }


    // Check for boundary conditions (game over if it hits the wall)
    if (newHead.x < 0 || newHead.x >= mainGameMechsRef->getBoardSizeX() ||
        newHead.y < 0 || newHead.y >= mainGameMechsRef->getBoardSizeY()) {
        mainGameMechsRef->setExitTrue();
        return; // End the function early as the game is over
    }

    // Check for food consumption
    objPos foodPos;
    mainGameMechsRef->getFoodPos(foodPos); // Assuming getFoodPos is implemented in GameMechs
    bool hasEatenFood = (newHead.x == foodPos.x && newHead.y == foodPos.y);

    // Insert new head position
    playerPosList->insertHead(newHead);

    if (hasEatenFood) {
        // If food is consumed, generate new food and don't remove the tail (snake grows)
        mainGameMechsRef->generateFood(playerPosList); // Assuming generateFood method accepts playerPosList
    } else {
        // If no food is consumed, remove the tail to keep the snake the same length
        playerPosList->removeTail();
    }

    // Check for collision with itself (game over condition)
    for (int i = 1; i < playerPosList->getSize(); i++) {
        objPos segment;
        playerPosList->getElement(segment, i);
        if (newHead.x == segment.x && newHead.y == segment.y) {
            mainGameMechsRef->setExitTrue();
            break;
        }
    }
}

