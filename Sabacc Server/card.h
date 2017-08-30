#pragma once

class Card
{
private:
    char name[50];
    int value;
    int suit;
    int copy;
    bool face;
public:
    Card(const char*, int, int, int, int, bool);
    Card();
};