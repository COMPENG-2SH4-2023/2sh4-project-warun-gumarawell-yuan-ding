#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player {
public:
    enum Dir { UP, DOWN, LEFT, RIGHT, STOP };

    Player(GameMechs* thisGMRef);
    ~Player();

    void getPlayerPosList(objPosArrayList*& returnList); // Updated to return list
    void updatePlayerDir();
    void movePlayer();

private:
    objPosArrayList* playerPosList; // Replaced playerPos with playerPosList
    Dir myDir;
    GameMechs* mainGameMechsRef;
};

#endif
