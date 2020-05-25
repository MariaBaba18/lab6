#pragma once
#include <string>
#include <vector>
#include "Film.h"
using std::string;
using std::vector;

class BaseFile
{
public:
    virtual void write(string filename, vector<Film*> repo) {}

    virtual void write(string filename, vector<Film> watchlist) {}

    virtual void display(string filename) {}
};