#include "ship.h"

#include <iostream>
using namespace std;

static int numberOf4x1 = 1;
static int numberOf3x1 = 2;
static int numberOf2x1 = 3;
static int numberOf1x1 = 4;

Ship::Ship(){
    this->r;
    this->x;
    this->y;
    this->n;
    this->hits;
}

Ship::~Ship(){
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

bool Ship::checkShipLenght(char playerEnemyBoard[10][10],Ship *ship){
    bool isShipLeft=true;
    switch (ship->n)
    {
    case 4:
        if(numberOf4x1<=0){
            cout<<"\nYou don't have any 4x1 ships left!"<<endl;
            isShipLeft = false;
            break;
        }else{
            numberOf4x1--;    
        }
        break;

    case 3:
        if(numberOf3x1<=0){
            cout<<"\nYou don't have any 3x1 ships left!"<<endl;
            isShipLeft = false;
        }else{
            numberOf3x1--;  
        }
        break;
    

    case 2:
        if(numberOf2x1<=0){
            cout<<"\nYou don't have any 2x1 ships left!"<<endl;
            isShipLeft = false;
        }else{
            numberOf2x1--;
        }
        break;
    

    case 1:
        if(numberOf1x1<=0){
            cout<<"\nYou don't have any 1x1 ships left!"<<endl;
            isShipLeft = false;
        }else{
            numberOf1x1--;
        }
        
        break;
    
    default:
        break;
    }
    return isShipLeft;
}

void Ship::getShipInfo(char playerShipBoard[10][10], Ship *ship){ 
    cout<<"Enter ship lenght (1 - 4): ";
    cin>>ship->n;
    while(ship->n>4||ship->n<1){
    if (cin.fail()){
        cin.clear();
        cin.ignore();
    }        
        cout<<"\nInvalid ship length! Enter length from 1 to 4!"<<endl;
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
        cout<<"\nInvalid ship x coordinates! Enter x from A to J, please use CAPS!"<<endl;
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
        cout<<"\nInvalid ship y coordinates! Enter y from 1 to 10!"<<endl;
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
        cout<<"\nInvalid ship rotation! Enter rotation such as 'n','s','e','w'!"<<endl;
        cout<<"Enter ship rotation ('n','s','e','w'): ";
        cin>>ship->r;
    }
    bool canShipBePlaced=checkShipLenght(playerShipBoard,ship);
    if(canShipBePlaced==true){
        placeShip(playerShipBoard,ship);
    }else{
        getShipInfo(playerShipBoard, ship);
    }
}

void Ship::placeShip(char playerShipBoard[10][10], Ship *ship){
    bool canShipBePlaced;
    for(int i=0;i<n;i++)
    {
        if(i==0){
                canShipBePlaced=checkBuffer(playerShipBoard, ship);
            }
        if(canShipBePlaced==true){    
        switch (r){
        case 'e':
            while(x-1+n>10){
                cout<<"\nCannot place ship with 'e' orientation, ship would be placed outside the board"<<endl;
                addShipAmmount(ship);
                getShipInfo(playerShipBoard, ship);
                break;
            }

            if(x-1+n<=10&&canShipBePlaced==true){
                playerShipBoard[y-1][x+i-1]='#'; 
            }
        break;

        case 'w':
            while(x-n<0){
                cout<<"\nCannot place ship with 'w' orientation, ship would be placed outside the board"<<endl;
                addShipAmmount(ship);
                getShipInfo(playerShipBoard, ship);
                break;
            }
         if(x-n>=0&&canShipBePlaced==true){
            playerShipBoard[y-1][x-i-1]='#';
        }
        break;

        case 'n':
        while(y-n<0){
            cout<<"\nCannot place ship with 'n' orientation, ship would be placed outside the board"<<endl;
                addShipAmmount(ship);
                getShipInfo(playerShipBoard, ship);
                break;
        }
        if(y-n>=0&&canShipBePlaced==true){
            playerShipBoard[y-i-1][x-1]='#';
        }
        break;

        case 's':
        while(y-1+n>10){
            cout<<"\nCannot place ship with 's' orientation, ship would be placed outside the board"<<endl;
                addShipAmmount(ship);
                getShipInfo(playerShipBoard, ship);
                break;
        }
        if(y-1+n<=10&&canShipBePlaced==true){
            playerShipBoard[y+i-1][x-1]='#';
        }
        break;

        default:
            break;
        }
    }else{
        getShipInfo(playerShipBoard,ship);
        break;
    }
    }
}

bool Ship::checkBuffer(char playerShipBoard[10][10], Ship *ship){
    bool buffer=true;
    switch (r)
    {
    case 'e':
        for(int i=0;i>=-2;i--){
            for(int j=-2;j<n;j++){
                if((y+i<10)&&(y+i>=0)&&(x+j>=0)&&(x+j<10)){
                    if(playerShipBoard[y+i][x+j]=='#'){
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
                if(playerShipBoard[y+i][x+j-n+1]=='#'){
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
            if(playerShipBoard[y+i-n+1][x+j]=='#'){
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
            if(playerShipBoard[y+i][x+j]=='#'){
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

bool Ship::shootShip(char playerShipBoard[10][10],char playerEnemyBoard[10][10],char enemyShipBoard[10][10],Ship *ship[10],string playerName){
    Board newBoard;
    cout<<playerName<<" it's your turn to shoot! "<<endl;
    newBoard.showBoard(playerShipBoard,playerEnemyBoard); 
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
        cout<<"Invalid ship x coordinates! Enter y from 1 to 10"<<endl;
        cout<<"Enter ship x coordinates (1 - 10): ";
        cin>>y;
    } 

    bool isShipHit;
    if(playerEnemyBoard[y-1][x-1]=='~'||playerEnemyBoard[y-1][x-1]=='x'){
        cout<<"You can't shot this field again"<<endl;
        shootShip(playerShipBoard,playerEnemyBoard,enemyShipBoard,ship,playerName);
    }
    else if(enemyShipBoard[y-1][x-1]=='#'){
        cout<<"Hit!  "<<endl;
        playerEnemyBoard[y-1][x-1]='x';
        enemyShipBoard[y-1][x-1]='x';
        
            for(int i=0;i<10;i++){   
                switch(ship[i]->r){
                    case 'e':

                    for(int j=0; j<4;j++){
                        if(x==ship[i]->x+j&&y==ship[i]->y){
                            ship[i]->hits++;
                            isShipHit=true;
                            if(ship[i]->hits>=ship[i]->n){
                                isShipHit=true;
                                surroundDestroyedShip(playerEnemyBoard,enemyShipBoard,ship[i]);
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
                                surroundDestroyedShip(playerEnemyBoard,enemyShipBoard,ship[i]);
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
                                surroundDestroyedShip(playerEnemyBoard,enemyShipBoard,ship[i]);
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
                                surroundDestroyedShip(playerEnemyBoard,enemyShipBoard,ship[i]);
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
        enemyShipBoard[y-1][x-1]='~';
        playerEnemyBoard[y-1][x-1]='~';
        isShipHit=false;
    }
    return isShipHit;
}

void Ship::surroundDestroyedShip(char playerEnemyBoard[10][10],char enemyShipBoard[10][10],Ship *ship){
    switch (ship->r)
    {
    case 'e':
        for(int i=0;i>=-2;i--){
            for(int j=-2;j<ship->n;j++){
                if((ship->y+i<10)&&(ship->y+i>=0)&&ship->x+j>=0&&ship->x+j<10){
                    if(enemyShipBoard[ship->y+i][ship->x+j]=='x'){
                        playerEnemyBoard[ship->y+i][ship->x+j]='x';
                    }else{
                        playerEnemyBoard[ship->y+i][ship->x+j]='~';
                        enemyShipBoard[ship->y+i][ship->x+j]='~';
                    }
                } 
            }
        }
        break;

    case 'w':   
        for(int i=0;i>=-2;i--){
            for(int j=-2;j<ship->n;j++){
                if((ship->y+i<10)&&(ship->y+i>=0)&&ship->x+j-ship->n+1>=0&&ship->x+j-ship->n+1<10){
                    if(enemyShipBoard[ship->y+i][ship->x+j-ship->n+1]=='x'){
                        playerEnemyBoard[ship->y+i][ship->x+j-ship->n+1]='x';
                    }else{
                        playerEnemyBoard[ship->y+i][ship->x+j-ship->n+1]='~';
                        enemyShipBoard[ship->y+i][ship->x+j-ship->n+1]='~';
                    }               
                } 
            }
        }
        break;


    case 'n':
        for(int i=-2;i<ship->n;i++){
            for(int j=0;j>=-2;j--){
                if((ship->y+i-ship->n+1<10)&&(ship->y+i-ship->n+1>=0)&&ship->x+j>=0&&ship->x+j<10){
                    if(enemyShipBoard[ship->y+i-ship->n+1][ship->x+j]=='x'){
                        playerEnemyBoard[ship->y+i-ship->n+1][ship->x+j]='x';
                    }else{
                        playerEnemyBoard[ship->y+i-ship->n+1][ship->x+j]='~';
                        enemyShipBoard[ship->y+i-ship->n+1][ship->x+j]='~';
                    }               
                } 
            }
        }
        break;

    case 's':
        for(int i=-2;i<ship->n;i++){
            for(int j=0;j>=-2;j--){
                if((ship->y+i<10)&&(ship->y+i>=0)&&ship->x+j>=0&&ship->x+j<10){
                    if(enemyShipBoard[ship->y+i][ship->x+j]=='x'){
                        playerEnemyBoard[ship->y+i][ship->x+j]='x';
                    }else{
                        playerEnemyBoard[ship->y+i][ship->x+j]='~';
                        enemyShipBoard[ship->y+i][ship->x+j]='~';
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
                  cout<<"All ships have been destroyed!"<<endl;
                }
            } 
        }
    return !areAllShipsDestroyed;
}