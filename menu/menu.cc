#include "menu.h"
#include <iostream>
using namespace std;
Menu::Menu()
{
    this->start=start;
}
Menu::~Menu()
{
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
    getStart();
}

void Menu::getStart(){
    cout << "Would you like to play? y/n ";
    cin >> start;

    if(start=='Y'||start=='y'){

    }else{
        cout<<"Bye bye";
    }
}
