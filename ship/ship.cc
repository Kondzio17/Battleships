#include "ship.h"
#include <iostream>
using namespace std;
Ship::Ship()
{
    this->r=r;
    this->x=x;
    this->y=y;
    this->n=n;
    this->canShipBePlaced=canShipBePlaced;
    this->isShipHit=isShipHit;
    this->hits=hits;
    hits=0;
    isShipHit=true;
}

Ship::~Ship()
{
}

void Ship::getShipInfo(char tab1[10][10], Ship *ship){ 
    cout<<"Enter ship length: ";
    cin >> ship->n;
    cout<<"Enter ship x coordinates (ex. 1): ";
    cin>>ship->x;
    cout<<"Enter ship y coordinates (ex. 1): ";
    cin>>ship->y;
    cout<<"enter: ";
    cin >> ship->r;

    placeShip(tab1,ship);
}

void Ship::placeShip(char tab1[10][10], Ship *ship){
    
    for(int i=0;i<n;i++)
    {
        if(i==0){
                canShipBePlaced=checkBuffer(tab1, ship);
            }
        switch (r){
        case 'e':
            if(x-1+n>10&&i==0){
                cout<<"Cannot place ship with 'e' orientation"<<endl;
            }else if(x-1+n<=10&&canShipBePlaced==true){
                tab1[y-1][x+i-1]='#'; 
            }
        break;

        case 'w':
        if(x-n<0&&i==0){
            cout<<"Cannot place ship with 'w' orientation"<<endl;
        }else if(x-n>=0&&canShipBePlaced==true){
            tab1[y-1][x-i-1]='#';
        }
        break;

        case 'n':
        if(y-n<0&&i==0){
            cout<<"Cannot place ship with 'n' orientation"<<endl;
            shipsLeft++;
        }else if(y-n>=0&&canShipBePlaced==true){
            tab1[y-i-1][x-1]='#';
        }
        break;

        case 's':
        if(y-1+n>10&&i==0){
            cout<<"Cannot place ship with 's' orientation"<<endl;
            break;
        }else if(y-1+n<=10&&canShipBePlaced==true){
            tab1[y+i-1][x-1]='#';
        }
        break;

        default:
            cout<<"Wrong ship orientation"<<endl;
            getShipInfo(tab1,ship);
            break;
        }
    }
}


bool Ship::checkBuffer(char tab1[10][10], Ship *ship){
    bool buffer=true;
    
    switch (r)
    {
    case 'e':
        for(int i=0;i>=-2;i--){
            for(int j=-2;j<n;j++){
                if((y+i>10)||(y+i<10)&&x+j>=0&&x+j<10){
                    if(tab1[y+i][x+j]=='#'){
                        cout<<"Cannot place ship. Ship is too close to another ship"<<endl;
                        getShipInfo(tab1,ship);
                        buffer=false;
                        break;
                    }     
                } 
            }
        }
        break;

    case 'w':
        for(int i=0;i>=-2;i--){
            for(int j=-2;j<n;j++){
                if((y+i>10)||(y+i<10)&&x+j-n+1>=0&&x+j-n+1<10){
                if(tab1[y+i][x+j-n+1]=='#'){
                    cout<<"Cannot place ship. Ship is too close to another ship"<<endl;
                    getShipInfo(tab1,ship);
                    buffer=false;
                    break;
                }              
        } 
    }
    }
        break;
    case 'n':
        for(int i=-2;i<n;i++){
        for(int j=0;j>=-2;j--){
            if((y+i-n+1>10)||(y+i-n+1<10)&&x+j>=0&&x+j<10){
            if(tab1[y+i-n+1][x+j]=='#'){
                cout<<"Cannot place ship. Ship is too close to another ship"<<endl;
                getShipInfo(tab1,ship);
                buffer=false;
                break;
            }               
        } 
        }
    }
        break;
    case 's':
        for(int i=-2;i<n;i++){
        for(int j=0;j>=-2;j--){
            if((y+i>10)||(y+i<10)&&x+j>=0&&x+j<10){
            if(tab1[y+i][x+j]=='#'){
                cout<<"Cannot place ship. Ship is too close to another ship"<<endl;
                getShipInfo(tab1,ship);
                buffer=false;
                break;
            }               
        } 
        }
    }
        break;

    default:
        break;
    }

    return buffer;
}

bool Ship::shootShip(char tab1[10][10],char tab2[10][10],char tab3[10][10],Ship *ship[10],string playerName){
    Board newBoard;
    newBoard.showBoard(tab1,tab2); 
    cout<<playerName<<" it's your turn to shoot! "<<endl;
    cout<<"Enter x coordinates";
    cin>>x;
    cout<<"Enter y coordinates";
    cin>>y; 

    if(tab2[y-1][x-1]=='~'||tab2[y-1][x-1]=='x'){
        cout<<"You can't shot this field again"<<endl;
        shootShip(tab1,tab2,tab3,ship,playerName);
    }
    else if(tab3[y-1][x-1]=='#'){
        cout<<"Hit!  "<<endl;
        tab2[y-1][x-1]='x';
        tab3[y-1][x-1]='x';
        
            for(int i=0;i<1;i++){   
                switch(ship[i]->r){
                    case 'e':

                    for(int j=0; j<4;j++){
                        if(x==ship[i]->x+j&&y==ship[i]->y){
                            cout<<"Works"<<endl;
                            ship[i]->hits++;
                            isShipHit=true;
                            if(ship[i]->hits>=ship[i]->n){
                                isShipHit=true;
                                cout<<"SHIP DESTROYED"<<endl;
                                i++;
                                surroundDestroyedShip(tab2,tab3,ship,x,y);
                                break;
                            }
                        break;
                        }
                    }
                    break;

                    case 'w':
                    for(int j=0; j<4;j++){
                    if(x==ship[i]->x-j&&y==ship[i]->y){
                       cout<<"Works"<<endl;
                            ship[i]->hits++;
                            isShipHit=true;
                            if(ship[i]->hits>=ship[i]->n){
                                isShipHit=true;
                                cout<<"SHIP DESTROYED"<<endl;
                                i++;
                                surroundDestroyedShip(tab2,tab3,ship,x,y);
                                break;
                            }
                    break;
                    }
                    }    
                    break;


                    case 'n':
                    for(int j=0; j<4;j++){
                    if(x==ship[i]->x&&y==ship[i]->y-j){
                        cout<<"Works"<<endl;
                            ship[i]->hits++;
                            isShipHit=true;
                            if(ship[i]->hits>=ship[i]->n){
                                isShipHit=true;
                                cout<<"SHIP DESTROYED"<<endl;
                                i++;
                                surroundDestroyedShip(tab2,tab3,ship,x,y);
                                break;
                            }
                    break;
                    }
                    }
                    break;

                    case 's':
                    for(int j=0; j<4;j++){
                    if(x==ship[i]->x&&y==ship[i]->y+j){
                        cout<<"Works"<<endl;
                            ship[i]->hits++;
                            isShipHit=true;
                            if(ship[i]->hits>=ship[i]->n){
                                isShipHit=true;
                                cout<<"SHIP DESTROYED"<<endl;
                                i++;
                                surroundDestroyedShip(tab2,tab3,ship,x,y);
                                break;
                            }
                    break;
                    }
                    }    
                    break;
                }
            }

    }else{
        cout<<"Miss!"<<endl;
        tab3[y-1][x-1]='@';
        tab2[y-1][x-1]='@';
        isShipHit=false;

    }
    return isShipHit;
}

void Ship::surroundDestroyedShip(char tab1[10][10],char tab2[10][10],Ship *ship[10], int x, int y){
    for(int s=0;s<9;s++){ 
    switch (ship[s]->r)
    {
    case 'e':
        for(int i=0;i>=-2;i--){
            for(int j=-2;j<ship[s]->n;j++){
                if((ship[s]->y+i>10)||(ship[s]->y+i<10)&&ship[s]->x+j>=0&&ship[s]->x+j<10){
                    if(tab2[ship[s]->y+i][ship[s]->x+j]=='x'){
                        tab1[ship[s]->y+i][ship[s]->x+j]='x';
                    }else{
                        tab1[ship[s]->y+i][ship[s]->x+j]='~';
                        tab2[ship[s]->y+i][ship[s]->x+j]='~';
                    }
                } 
            }
        }
        s=0;
        break;

    case 'w':   
        for(int i=0;i>=-2;i--){
            for(int j=-2;j<ship[s]->n;j++){
                if((ship[s]->y+i>10)||(ship[s]->y+i<10)&&ship[s]->x+j-ship[s]->n+1>=0&&ship[s]->x+j-ship[s]->n+1<10){
                    if(tab2[ship[s]->y+i][ship[s]->x+j-ship[s]->n+1]=='x'){
                        tab1[ship[s]->y+i][ship[s]->x+j-ship[s]->n+1]='x';
                    }else{
                        tab1[ship[s]->y+i][ship[s]->x+j-ship[s]->n+1]='~';
                        tab2[ship[s]->y+i][ship[s]->x+j-ship[s]->n+1]='~';
                    }               
                } 
            }
        }
        break;


    case 'n':
        for(int i=-2;i<ship[s]->n;i++){
            for(int j=0;j>=-2;j--){
                if((ship[s]->y+i-ship[s]->n+1>10)||(ship[s]->y+i-ship[s]->n+1<10)&&ship[s]->x+j>=0&&ship[s]->x+j<10){
                    if(tab2[ship[s]->y+i-ship[s]->n+1][ship[s]->x+j]=='x'){
                        tab1[ship[s]->y+i-ship[s]->n+1][ship[s]->x+j]='x';
                    }else{
                        tab1[ship[s]->y+i-ship[s]->n+1][ship[s]->x+j]='~';
                        tab2[ship[s]->y+i-ship[s]->n+1][ship[s]->x+j]='~';
                    }               
                } 
            }
        }
        break;

    case 's':
        for(int i=-2;i<ship[s]->n;i++){
            for(int j=0;j>=-2;j--){
                if((ship[s]->y+i>10)||(ship[s]->y+i<10)&&ship[s]->x+j>=0&&ship[s]->x+j<10){
                    if(tab2[ship[s]->y+i][ship[s]->x+j]=='x'){
                        tab1[ship[s]->y+i][ship[s]->x+j]='x';
                    }else{
                        tab1[ship[s]->y+i][ship[s]->x+j]='~';
                        tab2[ship[s]->y+i][ship[s]->x+j]='~';
                    }
                } 
            }
        }
        break;

    default:
        break;
    }
}
}

bool Ship::areAllShipsDestroyed(Ship *ship[10]){
    bool areAllShipsDestroyed=false;
        for(int i=0;i<1;i++){
            if(ship[i]->hits>=ship[i]->n){
                areAllShipsDestroyed=true;
            } 
        }
    return !areAllShipsDestroyed;
}