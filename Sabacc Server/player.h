#pragma once
#include "card.h"
#include <SFML/Network.hpp>
using namespace sf;

class Player
{
private:
    int money;
    char name[50];
    bool fold;
    bool bombedOut;
    int score;
    Card * hand;
public:
    Player();
    TcpSocket socket;
    void setName(char[], int);
    bool getBombedOut();
    bool getFold();
    char* getName();
    int getMoney();
    void setMoney(int);
};