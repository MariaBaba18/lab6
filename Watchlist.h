#pragma once
#include <vector>
#include "Film.h"
#include "Repository.h"

class Watchlist
{
private:
    std::vector<int> watchlist;
    Repository *repo;

    int getPosition(int id) const;

    Watchlist():repo{ new Repository() }
    {
    }

public:

    Watchlist(Repository* repository);


    bool addFilm(Film movie);

    bool removeFilm(Film movie);

    std::vector<Film> getWatchlist();
};
