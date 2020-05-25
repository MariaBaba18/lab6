#pragma once
#include "Watchlist.h"
#include "Repository.h"

class UserController
{
private:
    Watchlist* watch;
    Repository repo;

public:
    UserController()
    {
        this->watch = new Watchlist(&repo);
    }

    vector <Film*> findFilmByGenre(string genre);

    bool addToWlist(string title, int year);

    bool removeFromWlist(string title, int year);

    vector<Film> getWatchlist();

    void init();

    void addLike(string title, int year);

    ~UserController()
    {
        delete this->watch;
    }
};
