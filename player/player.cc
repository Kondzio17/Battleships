#include "player.h"
#include <iostream>
#include <conio.h>

int Player::p1score = 0;
int Player::p2score = 0;

using namespace std;
Player::Player(){
    this->playerName;
    this->p1score;
    this->p2score;
}

Player::~Player(){
}

string Player::getPlayerName(){
    cout<<"Enter your name: ";
    cin>>playerName;
    cout<< "Hello "<<playerName<<endl;
    return playerName;
}

void Player::showSwitchMenu(string playerName){
    cout<<"                                     # #  ( )"<<endl;
    cout<<"                                  ___#_#___|__"<<endl;
    cout<<"                              _  |____________|  _"<<endl;
    cout<<"                       _=====| | |            | | |==== _"<<endl;
    cout<<"                 =====| |.---------------------------. | |===="<<endl;
    cout<<"   <--------------------'   .  .  .  .  .  .  .  .   '--------------/"<<endl;
    cout<<"     \\                           BATTLE SHIPS                      /"<<endl;
    cout<<"      \\___________________________________________________________/"<<endl;
    string enteredKey;
    cout<<playerName<<" press any key to continue...";
    _getch();
}

bool Player::showEndScore(string playerName1, string playerName2, int winner){    
    Player newPlayer1;
    Player newPlayer2;
    if(winner==1){
    p1score++;  
    }else{
    p2score++; 
    }
    
    cout<<playerName1<<" wins: "<<p1score<<endl;
    cout<<playerName2<<" wins: "<<p2score<<endl;

    bool nextGame;
    char continueGame;
    cout<<"Would you like to play again? y/n ";
    cin>>continueGame;
    return continueGame=='y';
}