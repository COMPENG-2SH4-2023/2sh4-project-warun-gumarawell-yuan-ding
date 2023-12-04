#include <iostream>
#include "MacUILib.h"
#include "objPos.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(26, 13);//make board size 26x13
    myPlayer = new Player(myGM);

}

void GetInput(void)
{
   myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    myGM->clearInput(); 
}

void DrawScreen(void)
{
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
