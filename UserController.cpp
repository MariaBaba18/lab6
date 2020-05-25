#include "UserController.h"

vector<Film*> UserController::findFilmByGenre(string genre)
{
    return this->repo.listFilmsByGenre(genre);
}

bool UserController::addToWlist(string title, int year)
{
    Film* movie = this->repo.find(title, year);
    if(movie != nullptr)
        return this->watch->addFilm(*movie);
    return false;
}

bool UserController::removeFromWlist(string title, int year)
{
    Film* movie = this->repo.find(title, year);
    if (movie != nullptr)
        return this->watch->removeFilm(*movie);
    return false;
}

vector<Film> UserController::getWatchlist()
{
    return this->watch->getWatchlist();
}

void UserController::init()
{
    this->repo.initialize("List_of_movies.txt");
}

void UserController::addLike(string title, int year)
{
    Film* movie = this->repo.find(title, year);
    if (movie != nullptr)
        this->repo.update(movie, "", 1);

}
