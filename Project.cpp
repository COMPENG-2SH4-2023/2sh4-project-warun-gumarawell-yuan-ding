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

<<<<<<< HEAD
//    while(!exitFlag)
//    {
=======
    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
>>>>>>> c60b4632cdf69a7c8db27804c8c85692b5fd863c
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
<<<<<<< HEAD
    exitFlag = false;
    game = new GameMechs();
    player = new Player(game);
=======
    MacUILib_clearScreen();

    myGM = new GameMechs(26, 13);//make board size 26x13
    myPlayer = new Player(myGM);

>>>>>>> c60b4632cdf69a7c8db27804c8c85692b5fd863c
}

void GetInput(void)
{
<<<<<<< HEAD

=======
   myGM->getInput();
>>>>>>> c60b4632cdf69a7c8db27804c8c85692b5fd863c
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    myGM->clearInput(); 
}

void DrawScreen()
{
<<<<<<< HEAD
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
=======
    MacUILib_clearScreen();  
    
    objPos tempPos;
    myPlayer->getPlayerPos(tempPos); // get the player pos.

    int i;
    for(i = 0; i < myGM->getBoardSizeY(); i++)
    {
        int j;
        for(j = 0; j < myGM->getBoardSizeX(); j++)
        {
            if(i == 0||i == myGM->getBoardSizeY()-1||j == 0||j == myGM->getBoardSizeX()-1)
            {
                MacUILib_printf("#");
            }
            else if(j == tempPos.x && i == tempPos.y)
            {
                MacUILib_printf("%c",tempPos.symbol);
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("BoardSize:%dx%d, PlayerPos(%c):(%d,%d)\n", myGM->getBoardSizeX(), myGM->getBoardSizeY(), tempPos.symbol,tempPos.x, tempPos.y);

>>>>>>> c60b4632cdf69a7c8db27804c8c85692b5fd863c
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    MacUILib_uninit();

    delete myGM;
    delete myPlayer;
}
