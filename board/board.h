#ifndef BOARD_H
#define BOARD_H
class Board
{
private:
    char letter= 65;
public:
    Board();
    ~Board();
    void showBoard(char tab1[10][10], char tab2[10][10]);
};
#endif