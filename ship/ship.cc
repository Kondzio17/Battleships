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
    this->buffer=buffer;
    this->hits=hits;
    this->numberOf4x1=numberOf4x1;
    this->numberOf3x1=numberOf3x1;    
    this->numberOf2x1=numberOf2x1;
    this->numberOf1x1=numberOf1x1;
}
int Ship::numberOf4x1 = 1;
int Ship::numberOf3x1 = 2;
int Ship::numberOf2x1 = 3;
int Ship::numberOf1x1 = 4;

Ship::~Ship()
{
}

void Ship::resetNumberOfShips(){
    numberOf4x1 = 1;
    numberOf3x1 = 2;
    numberOf2x1 = 3;
    numberOf1x1 = 4;
}

void Ship::addShipAmmount(Ship *ship){
    switch (ship->n)
    {
    case 4:
        numberOf4x1++;
        break;
    case 3:
        numberOf3x1++;
        break;
    case 2:
        numberOf2x1++;
        break;
    case 1:
        numberOf1x1++;
        break;
    
    default:
        break;
    }
}

bool Ship::checkShipLenght(char tab1[10][10],Ship *ship){
    bool isShipLeft=true;
    switch (ship->n)
    {
    case 4:
        if(numberOf4x1<=0){
            cout<<"You don't have any 4x1 ships left!"<<endl;
            isShipLeft = false;
            break;
        }
            numberOf4x1--;    
        
        break;

    case 3:
        if(numberOf3x1<=0){
            cout<<"You don't have any 3x1 ships left!"<<endl;
            isShipLeft = false;
        }
            numberOf3x1--;  
        
        break;
    

    case 2:
        if(numberOf2x1<=0){
            cout<<"You don't have any 2x1 ships left!"<<endl;
            isShipLeft = false;
        }
            numberOf2x1--;
        
        break;
    

    case 1:
        if(numberOf1x1<=0){
            cout<<"You don't have any 1x1 ships left!"<<endl;
            isShipLeft = false;
        }
            numberOf1x1--;
        
        
        break;
    
    default:
        break;
    }
    return isShipLeft;
}

void Ship::getShipInfo(char tab1[10][10], Ship *ship){ 
    cout<<"Enter ship lenght (1 - 4): ";
    cin>>ship->n;
    while(ship->n>4||ship->n<1){
    if (cin.fail()){
        cin.clear();
        cin.ignore();
    }        
        cout<<"Invalid ship length! Enter length from 1 to 4!"<<endl;
        cout<<"Enter ship lenght (1 - 4): ";
        cin>>ship->n;
    }

    cout<<"Enter ship x coordinates (A - J, please use CAPS): ";
    cin>>ship->x;
    ship->x=ship->x-64;
    while(ship->x>10||ship->x<1){
    if (cin.fail()){
        cin.clear();
        cin.ignore();
    }        
        cout<<"Invalid ship x coordinates! Enter x from A to J, please use CAPS!"<<endl;
        cout<<"Enter ship x coordinates (A - J, please use CAPS): ";
        cin>>ship->x;
        ship->x=ship->x-64;
    }

    cout<<"Enter ship y coordinates (1 - 10): ";
    cin>>ship->y;
    while(ship->y>10||ship->y<1){
    if (cin.fail()){
        cin.clear();
        cin.ignore();
    }        
        cout<<"Invalid ship y coordinates! Enter y from 1 to 10!"<<endl;
        cout<<"Enter ship y coordinates (1 - 10): ";
        cin>>ship->y;
    }

    cout<<"Enter ship rotation ('n','s','e','w'): ";
    cin>>ship->r;
    while(ship->r!='n'&&ship->r!='s'&&ship->r!='e'&&ship->r!='w'){
    if (cin.fail()){
        cin.clear();
        cin.ignore();
    }        
        cout<<"Invalid ship rotation! Enter rotation such as 'n','s','e','w'!"<<endl;
        cout<<"Enter ship rotation ('n','s','e','w'): ";
        cin>>ship->r;
    }
    canShipBePlaced=checkShipLenght(tab1,ship);
    if(canShipBePlaced==true){
        placeShip(tab1,ship);
    }else{
        getShipInfo(tab1, ship);
    }
}

void Ship::placeShip(char tab1[10][10], Ship *ship){
    
    for(int i=0;i<n;i++)
    {
        if(i==0){
                canShipBePlaced=checkBuffer(tab1, ship);
            }
        if(canShipBePlaced==true){    
        switch (r){
        case 'e':
            while(x-1+n>10){
                cout<<"Cannot place ship with 'e' orientation"<<endl;
                cout<<"Enter ship x coordinates (A - J, please use CAPS): ";
                cin>>x;
                x=x-64;
            }

            if(x-1+n<=10&&canShipBePlaced==true){
                tab1[y-1][x+i-1]='#'; 
            }
        break;

        case 'w':
            while(x-n<0){
                cout<<"Cannot place ship with 'w' orientation"<<endl;
                cout<<"Enter ship x coordinates (A - J, please use CAPS): ";
                cin>>x;
                x=x-64;
            }
         if(x-n>=0&&canShipBePlaced==true){
            tab1[y-1][x-i-1]='#';
        }
        break;

        case 'n':
        while(y-n<0){
            cout<<"Cannot place ship with 'n' orientation"<<endl;
            cout<<"Enter ship y coordinates (1 - 10): ";
            cin>>y;
        }
        if(y-n>=0&&canShipBePlaced==true){
            tab1[y-i-1][x-1]='#';
        }
        break;

        case 's':
        while(y-1+n>10){
            cout<<"Cannot place ship with 's' orientation"<<endl;
            cout<<"Enter ship y coordinates (1 - 10): ";
            cin>>y;
        }
        if(y-1+n<=10&&canShipBePlaced==true){
            tab1[y+i-1][x-1]='#';
        }
        break;

        default:
            break;
        }
    }else{
        getShipInfo(tab1,ship);
    }
    }
}

bool Ship::checkBuffer(char tab1[10][10], Ship *ship){
    buffer=true;
    switch (r)
    {
    case 'e':
        for(int i=0;i>=-2;i--){
            for(int j=-2;j<n;j++){
                if((y+i<10)&&(y+i>=0)&&(x+j>=0)&&(x+j<10)){
                    if(tab1[y+i][x+j]=='#'){
                        cout<<"Cannot place ship. Ship is too close to another ship"<<endl;
                        buffer=false;
                        addShipAmmount(ship);
                        break;
                    }
                } 
            }
        }
        break;

    case 'w':
        for(int i=0;i>=-2;i--){
            for(int j=-2;j<n;j++){
                if((y+i<10)&&(y+i>=0)&&x+j-n+1>=0&&x+j-n+1<10){
                if(tab1[y+i][x+j-n+1]=='#'){
                    cout<<"Cannot place ship. Ship is too close to another ship"<<endl;
                    buffer=false;
                    addShipAmmount(ship);
                    break;
                }              
        } 
    }
    }
        break;
    case 'n':
        for(int i=-2;i<n;i++){
        for(int j=0;j>=-2;j--){
            if((y+i-n+1<10)&&(y+i-n+1>=0)&&x+j>=0&&x+j<10){
            if(tab1[y+i-n+1][x+j]=='#'){
                cout<<"Cannot place ship. Ship is too close to another ship"<<endl;
                buffer=false;
                addShipAmmount(ship);
                break;
            }               
        } 
        }
    }
        break;
    case 's':
        for(int i=-2;i<n;i++){
        for(int j=0;j>=-2;j--){
            if((y+i<10)&&(y+i>=0)&&x+j>=0&&x+j<10){
            if(tab1[y+i][x+j]=='#'){
                cout<<"Cannot place ship. Ship is too close to another ship"<<endl;
                buffer=false;
                addShipAmmount(ship);
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
    cout<<playerName<<" it's your turn to shoot! "<<endl;
    newBoard.showBoard(tab1,tab2); 
    cout<<"Enter x coordinates (A - J, please use CAPS!): ";
    cin>>x;
    x=x-64;
    while(x<0||x>10){
    if (cin.fail()){
        cin.clear();
        cin.ignore();
    }        
        cout<<"Invalid ship x coordinates! Enter x from A to J, please use CAPS!"<<endl;
        cout<<"Enter ship x coordinates (A - J, please use CAPS): ";
        cin>>x;
        x=x-64;
    }

    
    cout<<"Enter y coordinates (1 - 10): ";
    cin>>y;
    while(y<0||y>10){
    if (cin.fail()){
        cin.clear();
        cin.ignore();
    }        
        cout<<"Invalid ship x coordinates! Enter x from 1 to 10"<<endl;
        cout<<"Enter ship x coordinates (1 - 10): ";
        cin>>y;
    } 

    if(tab2[y-1][x-1]=='~'||tab2[y-1][x-1]=='x'){
        cout<<"You can't shot this field again"<<endl;
        shootShip(tab1,tab2,tab3,ship,playerName);
    }
    else if(tab3[y-1][x-1]=='#'){
        cout<<"Hit!  "<<endl;
        tab2[y-1][x-1]='x';
        tab3[y-1][x-1]='x';
        
            for(int i=0;i<10;i++){   
                switch(ship[i]->r){
                    case 'e':

                    for(int j=0; j<4;j++){
                        if(x==ship[i]->x+j&&y==ship[i]->y){
                            ship[i]->hits++;
                            isShipHit=true;
                            if(ship[i]->hits>=ship[i]->n){
                                isShipHit=true;
                                surroundDestroyedShip(tab2,tab3,ship[i]);
                                break;
                            }
                        break;
                        }
                    }
                    break;

                    case 'w':
                    for(int j=0; j<4;j++){
                    if(x==ship[i]->x-j&&y==ship[i]->y){
                            ship[i]->hits++;
                            isShipHit=true;
                            if(ship[i]->hits>=ship[i]->n){
                                isShipHit=true;
                                surroundDestroyedShip(tab2,tab3,ship[i]);
                                break;
                            }
                    break;
                    }
                    }    
                    break;


                    case 'n':
                    for(int j=0; j<4;j++){
                    if(x==ship[i]->x&&y==ship[i]->y-j){
                            ship[i]->hits++;
                            isShipHit=true;
                            if(ship[i]->hits>=ship[i]->n){
                                isShipHit=true;
                                surroundDestroyedShip(tab2,tab3,ship[i]);
                                break;
                            }
                    break;
                    }
                    }
                    break;

                    case 's':
                    for(int j=0; j<4;j++){
                    if(x==ship[i]->x&&y==ship[i]->y+j){
                            ship[i]->hits++;
                            isShipHit=true;
                            if(ship[i]->hits>=ship[i]->n){
                                isShipHit=true;
                                surroundDestroyedShip(tab2,tab3,ship[i]);
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
        tab3[y-1][x-1]='~';
        tab2[y-1][x-1]='~';
        isShipHit=false;

    }
    return isShipHit;
}

void Ship::surroundDestroyedShip(char tab1[10][10],char tab2[10][10],Ship *ship){
    switch (ship->r)
    {
    case 'e':
        for(int i=0;i>=-2;i--){
            for(int j=-2;j<ship->n;j++){
                if((ship->y+i<10)&&(ship->y+i>=0)&&ship->x+j>=0&&ship->x+j<10){
                    if(tab2[ship->y+i][ship->x+j]=='x'){
                        tab1[ship->y+i][ship->x+j]='x';
                    }else{
                        tab1[ship->y+i][ship->x+j]='~';
                        tab2[ship->y+i][ship->x+j]='~';
                    }
                } 
            }
        }
        break;

    case 'w':   
        for(int i=0;i>=-2;i--){
            for(int j=-2;j<ship->n;j++){
                if((ship->y+i<10)&&(ship->y+i>=0)&&ship->x+j-ship->n+1>=0&&ship->x+j-ship->n+1<10){
                    if(tab2[ship->y+i][ship->x+j-ship->n+1]=='x'){
                        tab1[ship->y+i][ship->x+j-ship->n+1]='x';
                    }else{
                        tab1[ship->y+i][ship->x+j-ship->n+1]='~';
                        tab2[ship->y+i][ship->x+j-ship->n+1]='~';
                    }               
                } 
            }
        }
        break;


    case 'n':
        for(int i=-2;i<ship->n;i++){
            for(int j=0;j>=-2;j--){
                if((ship->y+i-ship->n+1<10)&&(ship->y+i-ship->n+1>=0)&&ship->x+j>=0&&ship->x+j<10){
                    if(tab2[ship->y+i-ship->n+1][ship->x+j]=='x'){
                        tab1[ship->y+i-ship->n+1][ship->x+j]='x';
                    }else{
                        tab1[ship->y+i-ship->n+1][ship->x+j]='~';
                        tab2[ship->y+i-ship->n+1][ship->x+j]='~';
                    }               
                } 
            }
        }
        break;

    case 's':
        for(int i=-2;i<ship->n;i++){
            for(int j=0;j>=-2;j--){
                if((ship->y+i<10)&&(ship->y+i>=0)&&ship->x+j>=0&&ship->x+j<10){
                    if(tab2[ship->y+i][ship->x+j]=='x'){
                        tab1[ship->y+i][ship->x+j]='x';
                    }else{
                        tab1[ship->y+i][ship->x+j]='~';
                        tab2[ship->y+i][ship->x+j]='~';
                    }
                } 
            }
        }
        break;

    default:
        break;
    }
}

bool Ship::areAllShipsDestroyed(Ship *ship[10]){
    bool areAllShipsDestroyed=false;
    int shipsLeft=10;
        for(int i=0;i<10;i++){
            if(ship[i]->hits>=ship[i]->n){
                shipsLeft--;
                if(shipsLeft<=0){
                  areAllShipsDestroyed=true;  
                }
            } 
        }
    return !areAllShipsDestroyed;
}