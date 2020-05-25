#include "Watchlist.h"

int Watchlist::getPosition(int id) const
{
    for (int i = 0; i < this->watchlist.size(); i++)
        if (this->watchlist[i] == id)
            return i;
    return -1;
}

Watchlist::Watchlist(Repository* repository)
{
    this->repo = repository;
}

bool Watchlist::addFilm(Film movie)
{
    if (this->getPosition(movie.getId()) != -1)
        return false;

    this->watchlist.push_back(movie.getId());
    return true;
}

bool Watchlist::removeFilm(Film movie)
{
    int indx = this->getPosition(movie.getId());
    if(indx == -1)
        return false;

    this->watchlist.erase(this->watchlist.begin() + indx);
    return true;
}

std::vector<Film> Watchlist::getWatchlist()
{
    vector<Film> movies;
    for (auto i : this->watchlist)
        movies.push_back(this->repo->getMovieById(i));
    return movies;
}
