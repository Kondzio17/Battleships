#ifndef MENU_H
#define MENU_H
class Menu
{
private:
    char start;
public:
    Menu();
    ~Menu();
    void showMenu();
    bool startGame();
};
#endif