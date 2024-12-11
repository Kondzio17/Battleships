#include "game.cc"

#include <iostream>

using namespace std;
int main(){
    Menu newMenu;
    Game newGame;

    newMenu.showMenu();
    if(newMenu.startGame()){
        newGame.startGame(); 
    }else{
        cout<<"Bye bye";
        newGame.sleep(2000);
    }
}