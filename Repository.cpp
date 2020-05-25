#include "Repository.h"
#include <fstream>
#include <sstream>


bool Repository::update(Film* movie, string trailer, int likes)
{
    if (!exists(movie))
        return false;

    movie->setLikes(movie->getLikes() + likes);
    if (trailer != "")
        movie->setTrailer(trailer);
    this->file.write("List_of_movies.txt", this->movies);
    return true;
}

bool Repository::exists(Film* movie)
{
    for (int i = 0; i < movies.size(); i++)
        if (*movies[i] == *movie)
            return true;
    return false;
}

vector<Film*> Repository::search(function<bool(Film*)> condition)
{
    vector <Film*> list;
    for (auto m : this->movies)
        if (condition(m))
            list.push_back(m);
    return list;
}

Film* Repository::find(string title, int year)
{
    for (auto m : this->movies)
        if (m->getTitle() == title && m->getYear() == year)
            return m;
    return nullptr;
}

void Repository::initialize(string filename)
{
    ifstream f(filename);
    string str;

    // read every line from file
    while (getline(f, str))
    {
        istringstream csvStr(str);
        vector<string> line;
        string element;

        // read every element from the line that is seperated by commas
        // and put it into the vector or strings
        while (getline(csvStr, element, ','))
            line.push_back(element);

        string title = line[0];
        string genre = line[1];
        string trailer = line[2];
        int year = stoi(line[3]);
        int likes = stoi(line[4]);
        Film* m = new Film(this->count, title, genre, trailer, year, likes);

        movies.push_back(m);
        this->count++;
    }
    f.close();
}

Repository::~Repository()
{
    for (auto m : this->movies)
        delete m;
    this->movies.clear();
}

Film Repository::getMovieById(int id)
{
    for (auto m : this->movies)
        if (m->getId() == id)
            return *m;
}

bool Repository::add(Film* movie)
{
    if (exists(movie))
        return false;
    else
    {
        movies.push_back(movie);
        this->file.write("List_of_movies.txt", this->movies);
        this->count++;
    }
    return true;
}

bool Repository::remove(Film* movie)
{

    for (int i = 0; i < movies.size(); i++)
        if (*movies[i] == *movie)
        {
            movies.erase(movies.begin() + i);
            this->file.write("List_of_movies.txt", this->movies);
            return true;
        }
    return false;
}

vector<Film*> Repository::listFilmsByGenre(string genre)
{
    if(genre.empty())
        return movies;

    vector<Film*> list;
    for (auto m : this->movies)
        if (m->getGenre() == genre)
            list.push_back(m);
    return list;
}
