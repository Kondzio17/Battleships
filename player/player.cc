#include "player.h"
#include <iostream>
#include <map>
using namespace std;
Player::Player()
{
    this->playerName=playerName;
    this->score=score;
    score=0;

}

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
      newPlayer1.score++;  
    }else{
        newPlayer2.score++;
    }



    map<string, int> playerWins;
    string player;
    char continueGame;

    do {
        if(winner==1){
            cout<<playerName1<<" has won"<<endl;
            playerWins[player]++;
        }else{
            cout<<playerName2<<" has won"<<endl;
            playerWins[player]++;
        }

        cout << "Would you like to continue? y/n: ";
        cin >> continueGame;
        if(continueGame=='y'){
            return true;
        }
    } while (continueGame == 'y');

    cout << "\nScores:\n";
    for (const auto& entry : playerWins) {
        cout << entry.first << ": " << entry.second << " Wins\n";
    }return 0;
}