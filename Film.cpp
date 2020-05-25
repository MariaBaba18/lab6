#include "Film.h"

Film::Film(int id, string title, string genre, string trailer, int year, int likes)
{
    this->id = id;
    this->title = title;
    this->genre = genre;
    this->trailer = trailer;
    this->year = year;
    this->likes = likes;
}

int Film::getId()
{
    return this->id;
}

void Film::setId(int id) {
    this->id = id;
}

string Film::getTitle()
{
    return this->title;
}

void Film::setTitle(string title)
{
    this->title = title;
}

string Film::getGenre()
{
    return this->genre;
}

void Film::setGenre(string genre)
{
    this->genre = genre;
}

string Film::getTrailer()
{
    return this->trailer;
}

void Film::setTrailer(string trailer)
{
    this->trailer = trailer;
}

int Film::getYear()
{
    return this->year;
}

void Film::setYear(int year)
{
    this->year = year;
}

int Film::getLikes()
{
    return this->likes;
}

void Film::setLikes(int likes)
{
    this->likes = likes;
}

bool Film::operator==(Film movie2) const
{
    return (this->title == movie2.getTitle() && this->year == movie2.getYear());
}

string Film::toString()
{
    string s = this->title + ": " + this->genre + ", " + this->trailer + ", " + std::to_string(this->year) + ", " + std::to_string(this->likes);
    return s;
}