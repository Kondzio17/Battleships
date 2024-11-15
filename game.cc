#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <limits>
#include <windows.h>

#include "game.h"
#include "board/board.cc"
#include "player/player.cc"
#include "menu/menu.cc"
#include "ship/ship.cc"

using namespace std;
Game::Game()
{
    this->player1=player1;
    this->player2=player2;

}
Game::~Game()
{
}

void Game::clear()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Game::sleep(int milliseconds)
{
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}



void Game::startGame(

){
    //Menu newMenu;
    //newMenu.showMenu();
    //clear();   
    Game newPlayer1;
    Player player1Name;
    player1=player1Name.getPlayerName();
    
    sleep(500);

    Game newPlayer2;
    Player player2Name;
    player2=player2Name.getPlayerName();
    
    
    newPlayer1.getPlayerOneInfo(player1, player2);
    
    sleep(500);


}

void Game::getPlayerOneInfo(string player1, string player2)
{
    Board newBoard;
    Ship newShip;
    cout <<player1<<"'s turn, don't peak!"<<endl;
    newBoard.showBoard(tab1,tab2);
    Ship* ship1[2];
    Ship* p1ShipTab[2];
    for (int i=0;i<1;i++) {
        ship1[i] = new Ship;
        ship1[i]->getShipInfo(tab1,ship1[i]);
        p1ShipTab[i]=ship1[i];
        newBoard.showBoard(tab1,tab2);  

    }
    Game newPlayer2;
    newPlayer2.getPlayerTwoInfo(tab1,p1ShipTab,player1,player2);
}

void Game::getPlayerTwoInfo(char tab1[10][10],Ship *p1ShipTab[10], string player1, string player2)
{
    Board newBoard;
    Ship newShip;
    cout <<"'s turn, don't peak!"<<endl;
    newBoard.showBoard(tab3,tab4);
    Ship* ship2[2];
    Ship* p2ShipTab[2];
    for (int i=0;i<1;i++) {
        ship2[i] = new Ship;
        ship2[i]->getShipInfo(tab3,ship2[i]);
        p2ShipTab[i]=ship2[i];
        newBoard.showBoard(tab3,tab4);
    }
    shoot(tab1,tab2,tab3,tab4,p1ShipTab,p2ShipTab,player1,player2);
}

int Game::shoot(char tab1[10][10],char tab2[10][10],char tab3[10][10],char tab4[10][10],Ship *shipTab1[10], Ship *shipTab2[10], string playerName1, string playerName2)
{
    Board newBoard;
    Ship newShip;
    Ship newShip2;
    bool nextshoot=true;
    bool nextRound=true;
    
    while(true){
        nextshoot=true;
        while(nextshoot==true){
            nextshoot=newShip.shootShip(tab1,tab2,tab3,shipTab2,playerName1);
            nextRound=newShip.areAllShipsDestroyed(shipTab2);
            if(nextRound==false){
                Player newPlayer;
                bool playAgain;
                playAgain=newPlayer.showEndScore(playerName1,playerName2,1);
                if(playAgain==true){
                    Game newGame;
                    newGame.getPlayerOneInfo(player1,player2);
                }else{
                    return 0;
                }
                break;
                
            }
        }
        nextshoot=true;
        while(nextshoot==true){
            nextshoot=newShip2.shootShip(tab3,tab4,tab1,shipTab1,playerName2);
            nextRound=newShip2.areAllShipsDestroyed(shipTab1);
            if(nextRound==false){
                Player newPlayer;
                bool playAgain;
                playAgain=newPlayer.showEndScore(playerName1,playerName2,2);
                if(playAgain==true){
                    Game newGame;
                    newGame.startGame();
                }
                break;
            }
        }
    }       
}
