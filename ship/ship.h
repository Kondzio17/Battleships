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
    int hits=0;
public:
    
    Ship();
    ~Ship();
    void resetNumberOfShips();
    bool checkShipLenght(char playerShipBoard[10][10],Ship *ship);
    void addShipAmmount(Ship *ship);
    void getShipInfo(char playerShipBoard[10][10], Ship *ship);
    void placeShip(char playerShipBoard[10][10], Ship *ship);
    bool checkBuffer(char playerShipBoard[10][10], Ship *ship);
    bool shootShip(char playerShipBoard[10][10],char playerEnemyBoard[10][10],char enemyShipBoard[10][10],Ship *ship[10],string playerName);
    void surroundDestroyedShip(char playerEnemyBoard[10][10],char enemyShipBoard[10][10],Ship *ship);
    bool areAllShipsDestroyed(Ship *ship[10]);
};
#endif