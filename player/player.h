#ifndef PLAYER_H
#define PLAYER_H
class Player
{
private:
    string playerName;
    static int p1score;
    static int p2score;
public:
    Player();
    ~Player();
    string getPlayerName();
    bool showEndScore(string playerName1, string playerName2, int winner);
    void showSwitchMenu(string playerName);
};
#endif