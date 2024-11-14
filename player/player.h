#ifndef PLAYER_H
#define PLAYER_H
class Player
{
private:
    string playerName;
    int score=0;
public:
    Player(/* args */);
    ~Player();
    string getPlayerName();
    bool showEndScore(string playerName1, string playerName2, int winner);

};
#endif