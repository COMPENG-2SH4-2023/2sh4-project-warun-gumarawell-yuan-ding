#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

GameMechs* game;
Player* player;

int main()
{

    Initialize();

//    while(!exitFlag)
//    {
        DrawScreen();
//        GetInput();
//        RunLogic();
//        LoopDelay();
//    }

//    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    exitFlag = false;
    game = new GameMechs();
    player = new Player(game);
}

void GetInput(void)
{

}

void RunLogic(void)
{
    
}

void DrawScreen()
{
    for (int i = 0; i < game->getBoardSizeX(); i++)
    {
        cout << "#";
    }
    cout << "\n";
    for (int i = 0; i < game->getBoardSizeY(); i++)
    {
        for (int j = 0; j < game->getBoardSizeX(); j++)
        {
            if (j == 0)
            {
                cout << "#";
                cout << " ";
            }
            if (j == game->getBoardSizeX() - 1)
            {
                cout << "#";
            }
        }
        cout << "\n";
    }
    for (int i = 0; i < game->getBoardSizeX() + 2; i++)
        cout << "#";
    cout << "\n";
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
