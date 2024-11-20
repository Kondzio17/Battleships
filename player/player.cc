#include "player.h"
#include <iostream>
#include <map>
using namespace std;
Player::Player()
{
    this->playerName=playerName;
    this->p1score=p1score;
    this->p2score=p2score;
}

int Player::p1score = 0;
int Player::p2score = 0;

Player::~Player()
{
}

string Player::getPlayerName(){
    cout<<"Enter your name: ";
    cin>>playerName;
    cout<< "Hello "<<playerName<<endl;
    return playerName;
}

bool Player::showEndScore(string playerName1, string playerName2, int winner){    
    Player newPlayer1;
    Player newPlayer2;
    if(winner==1){
    p1score++;  
    }else{
    p2score++; 
    }

    cout<<"Player 1 wins: "<<p1score<<endl;
    cout<<"Player 2 wins: "<<p2score<<endl;

    bool nextGame;
    char continueGame;
    cout<<"Would you like to play again? ";
    cin>>continueGame;
    if(continueGame=='y'){
        nextGame=true;
    }else{
        nextGame=false;
    }
    return nextGame;
}