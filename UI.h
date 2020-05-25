#pragma once
#include <iostream>

using std::cout;
using std::cin;

class UI
{
public:

    virtual void menu();

    int input();

    virtual bool valid(int input);

    virtual void execute(int option) {}

    virtual void begin() {}

    virtual bool end() { return false; }
};
