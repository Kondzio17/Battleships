#ifndef MENU_H
#define MENU_H
class Menu
{
private:
    char start;
    bool shouldGameStart = true;
public:
    Menu();
    ~Menu();
    void showMenu();
    bool getStart();
};
#endif