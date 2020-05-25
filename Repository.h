#include "Film.h"
#include "TextFile.h"
#include <vector>
#include <iostream>
#include <functional>
using namespace std;
#pragma once

class Repository
{
private:
    vector <Film*> movies;
    TextFile file = TextFile();
    int count;

public:
    Repository()
    {
        this->count = 0;
    }

    int getCount() { return this->count; }

    Film getMovieById(int id);

    bool add(Film* movie);

    bool remove(Film* movie);

    vector <Film*> listFilmsByGenre(string genre);

    bool update(Film* movie, string trailer, int likes);

    bool exists(Film* movie);

    vector<Film*> search(function<bool(Film*)> condition);

    Film* find(string title, int year);

    void initialize(string filename);

    ~Repository();
};