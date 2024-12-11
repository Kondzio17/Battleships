#include "board.h"

#include<iostream>
#include<string>
using namespace std;

Board::Board(){
    this->letter;
}

Board::~Board(){

}

void Board::showBoard(char playerShipBoard[10][10], char playerEnemyBoard[10][10]){
    
    cout<<"\t\t      Your board\t\t\t\t\t\t\t     Enemy board"<<endl;
    cout << "         ";
    for(short c=0;c<10;c++){
        
        cout << char(letter + c) << "   ";
    }
    cout << "\t\t\t         ";
    for(short c=0;c<10;c++){
        cout << char(letter + c) << "   ";
    }    
    cout<<endl;  
            cout << "       +";
        for(int j = 0; j < 10 ; j++ ){
            cout << "---+";
        }
        cout << "\t\t\t       +";

        for(int j = 0; j < 10 ; j++ ){
            cout << "---+";
        }
        cout<<endl;
    
    for(int i=0;i<=9;i++)
    {  
        if(i+1==10){
            cout<<"   "<<i+1<<"  |"; 
        }else{
            cout<<"   "<<i+1<<"   |"; 
        }
        
        for(int j=0; j<10; j++){
            cout<<' '<<playerShipBoard[i][j]<<" |";
        }

        cout << "\t\t\t";

        if(i+1==10){
            cout<<"   "<<i+1<<"  |"; 
        }else{
            cout<<"   "<<i+1<<"   |"; 
        }

        for(int j=0; j<10; j++){
            cout<<' '<<playerEnemyBoard[i][j]<<" |";
        }
        cout <<endl;

        cout << "       +";
        for(int j = 0; j < 10 ; j++ ){
            cout << "---+";
        }
        cout << "\t\t\t       +";

        for(int j = 0; j < 10 ; j++ ){
            cout << "---+";
        }
        cout<<endl;
    }
}