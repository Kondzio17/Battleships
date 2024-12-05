#ifndef SHIP_H
#define SHIP_H
using namespace std;
class Ship
{
private:
    char x;
    int y;
    char r;
    int n;
    bool canShipBePlaced;
    bool isShipHit;
    bool buffer=false;
    int hits=0;
    static int numberOf4x1;
    static int numberOf3x1;    
    static int numberOf2x1;
    static int numberOf1x1;

public:
    
    Ship();
    ~Ship();
    void resetNumberOfShips();
    bool checkShipLenght(char tab1[10][10],Ship *ship);
    void addShipAmmount(Ship *ship);
    void getShipInfo(char tab1[10][10], Ship *ship);
    void placeShip(char tab1[10][10], Ship *ship);
    bool checkBuffer(char tab1[10][10], Ship *ship);
    bool shootShip(char tab1[10][10],char tab2[10][10],char tab3[10][10],Ship *ship[10],string playerName);
    void surroundDestroyedShip(char tab1[10][10],char tab2[10][10],Ship *ship);
    bool areAllShipsDestroyed(Ship *ship[10]);
};
#endif