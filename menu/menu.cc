#include "menu.h"
#include <iostream>
using namespace std;
Menu::Menu()
{
    this->start=start;
    this->shouldGameStart=shouldGameStart;
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

}

bool Menu::getStart(){
    cout << "Would you like to play? y/n ";
    cin >> start;

    if(start=='N'||start=='n'){
        shouldGameStart=false;
    }
    return shouldGameStart;
}
