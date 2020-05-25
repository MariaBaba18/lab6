#pragma once
#include <string>

using std::string;

class Film
{
private:
    string title, genre, trailer;
    int year, likes, id;

public:
    // Constructor
    Film(int id, string title, string genre, string trailer, int year, int likes);

    int getId();
    void setId(int id);

    string getTitle();
    void setTitle(string title);

    string getGenre();
    void setGenre(string genre);

    string getTrailer();
    void setTrailer(string trailer);

    int getYear();
    void setYear(int year);

    int getLikes();
    void setLikes(int likes);


    bool operator==(Film movie2) const;

    string toString();
};