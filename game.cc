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
Game::Game(){
    this->player1;
    this->player2;
}

Game::~Game(){
}

void Game::clear(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Game::sleep(int milliseconds){
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void Game::startGame(){
    clear();   
    Game newPlayer1;
    Player player1Name;
    player1=player1Name.getPlayerName();
    
    sleep(500);

    Game newPlayer2;
    Player player2Name;
    player2=player2Name.getPlayerName();
    
    sleep(500);
    newPlayer1.getPlayerOneInfo(player1, player2);
}

void Game::getPlayerOneInfo(string player1, string player2){
    clear();
    Player newPlayer;
    newPlayer.showSwitchMenu(player1);
    
    clear();

    Board newBoard;
    Ship newShip;
    newShip.resetNumberOfShips();
    cout <<player1<<"'s turn, don't peak!"<<endl;
    newBoard.showBoard(playerOneShipBoard,playerOneEnemyBoard);
    Ship* ship1[10];
    Ship* p1ShipTab[10];
    for (int i=0;i<10;i++) {
        if(i!=0){
            newBoard.showBoard(playerOneShipBoard,playerOneEnemyBoard);
        }
        ship1[i] = new Ship;
        ship1[i]->getShipInfo(playerOneShipBoard,ship1[i]);
        p1ShipTab[i]=ship1[i];
        sleep(1000);
        clear();
    }
    
    newPlayer.showSwitchMenu(player2);
    clear();
    Game newPlayer2;
    newPlayer2.getPlayerTwoInfo(playerOneShipBoard,p1ShipTab,player1,player2);

}

void Game::getPlayerTwoInfo(char playerOneShipBoard[10][10],Ship *p1ShipTab[10], string player1, string player2){
    Board newBoard;
    Ship newShip;
    newShip.resetNumberOfShips();
    cout <<player2<<"'s turn, don't peak!"<<endl;
    newBoard.showBoard(playerTwoShipBoard,playerTwoEnemyBoard);
    Ship* ship2[10];
    Ship* p2ShipTab[10];
    for (int i=0;i<10;i++) {
        if(i!=0){
            newBoard.showBoard(playerTwoShipBoard,playerTwoEnemyBoard);
        }
        ship2[i] = new Ship;
        ship2[i]->getShipInfo(playerTwoShipBoard,ship2[i]);
        p2ShipTab[i]=ship2[i];
        sleep(1000);
        clear();
    }
    shoot(playerOneShipBoard,playerOneEnemyBoard,playerTwoShipBoard,playerTwoEnemyBoard,p1ShipTab,p2ShipTab,player1,player2);
}

int Game::shoot(char playerOneShipBoard[10][10],char playerOneEnemyBoard[10][10],char playerTwoShipBoard[10][10],char playerTwoEnemyBoard[10][10],Ship *shipTab1[10], Ship *shipTab2[10], string playerName1, string playerName2){
    Board newBoard;
    Ship newShip;
    Ship newShip2;
    bool nextshoot=true;
    bool nextRound=true;
    Player newPlayer;
    while(true){
        clear();
        cout<<"It's time to shoot!"<<endl;
        newPlayer.showSwitchMenu(playerName1);
        clear();
        nextshoot=true;
        while(nextshoot==true){
            nextshoot=newShip.shootShip(playerOneShipBoard,playerOneEnemyBoard,playerTwoShipBoard,shipTab2,playerName1);
            nextRound=newShip.areAllShipsDestroyed(shipTab2);
            sleep(1000);
            clear();
            if(nextRound==false){
                newBoard.showBoard(playerOneShipBoard,playerOneEnemyBoard);
                clear();
                Player newPlayer;
                bool playAgain;
                playAgain=newPlayer.showEndScore(playerName1,playerName2,1);
                if(playAgain==true){
                    Game newGame;
                    newGame.getPlayerOneInfo(playerName1,playerName2);
                }else{
                    exit(0);
                }  
            }
        }

        clear();
        cout<<"It's time to shoot!";
        newPlayer.showSwitchMenu(playerName2);
        clear();
        nextshoot=true;
        while(nextshoot==true){
            nextshoot=newShip2.shootShip(playerTwoShipBoard,playerTwoEnemyBoard,playerOneShipBoard,shipTab1,playerName2);
            nextRound=newShip2.areAllShipsDestroyed(shipTab1);
            sleep(1000);
            clear();
            if(nextRound==false){
                newBoard.showBoard(playerTwoShipBoard,playerTwoEnemyBoard);
                clear();
                Player newPlayer;
                bool playAgain;
                playAgain=newPlayer.showEndScore(playerName1,playerName2,2);
                if(playAgain==true){
                    Game newGame;
                    newGame.getPlayerOneInfo(playerName1,playerName2);
                }else{
                    exit(0);
                }
            }
        }
    }       
}