#include "menu.h"
#include <iostream>
using namespace std;

Menu::Menu(){
    this->start;
}

Menu::~Menu(){
}

void Menu::showMenu(){
    cout<<"                                     # #  ( )"<<endl;
    cout<<"                                  ___#_#___|__"<<endl;
    cout<<"                              _  |____________|  _"<<endl;
    cout<<"                       _=====| | |            | | |==== _"<<endl;
    cout<<"                 =====| |.---------------------------. | |===="<<endl;
    cout<<"   <--------------------'   .  .  .  .  .  .  .  .   '--------------/"<<endl;
    cout<<"     \\                           BATTLE SHIPS                      /"<<endl;
    cout<<"      \\___________________________________________________________/"<<endl;
}

bool Menu::startGame(){
    cout << "Would you like to play? y/n ";
    cin >> start;
    while(start!='y'&&start!='n'){
    if (cin.fail()){
        cin.clear();
        cin.ignore();
    }        
        cout<<"That is...well..not an option..."<<endl;
        cout <<"\nWould you like to play? y/n ";
        cin >> start;
    }
    return (start=='y'||start=='Y');
}