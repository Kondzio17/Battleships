#ifndef BOARD_H
#define BOARD_H
class Board
{
private:
    char letter=65;
public:
    Board();
    ~Board();
    void showBoard(char playerShipBoard[10][10], char playerEnemyBoard[10][10]);
};
#endif