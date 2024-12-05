#include "game.cc"

#include <iostream>

using namespace std;
int main(){

    Menu newMenu;
    bool shouldGameStart=newMenu.getStart();
    if(shouldGameStart==true){
        Game newGame;
        newGame.startGame();  
    }else{
        cout<<"Bye";
    }

}
