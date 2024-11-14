#ifndef SHIP_H
#define SHIP_H
using namespace std;
class Ship
{
private:
    int x;
    int y;
    char r;
    int n;
    bool canShipBePlaced;
    bool isShipHit;
    int shipsLeft;
    int hits;

public:
    
    Ship(/* args */);
    ~Ship();
    void getShipInfo(char tab1[10][10], Ship *ship);
    void placeShip(char tab1[10][10], Ship *ship);
    bool checkBuffer(char tab1[10][10], Ship *ship);
    bool shootShip(char tab1[10][10],char tab2[10][10],char tab3[10][10],Ship *ship[10],string playerName);
    void surroundDestroyedShip(char tab1[10][10],char tab2[10][10],Ship *ship[10], int x, int y);
    bool areAllShipsDestroyed(Ship *ship[10]);
};
#endif