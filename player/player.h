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
    int saveScore1(Player p1);
    int saveScore2(Player p2);

};
#endif