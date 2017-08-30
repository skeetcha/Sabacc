#include "player.h"

Player::Player()
{
    money = 0;
    fold = false;
    bombedOut = false;
    score = 0;
    hand = new Card[50];
}

void Player::setName(char n[], int n_size)
{
    for (int i = 0; i < n_size; i++)
    {
	   name[i] = n[i];
    }
}

bool Player::getBombedOut()
{
    return bombedOut;
}

bool Player::getFold()
{
    return fold;
}

char* Player::getName()
{
    return name;
}

int Player::getMoney()
{
    return money;
}

void Player::setMoney(int m)
{
    money = m;
}