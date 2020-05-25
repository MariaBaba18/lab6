#include "Administrator.h"
#include <iostream>
using namespace std;

void Administrator::menu()
{
    cout << "\nThis is the administrator mode! \n\n"
            "Choose one of the following options:\n"
            "1. Update trailer or likes\n"
            "2. Add movie to database\n"
            "3. Remove movie from database\n"
            "4. List all movies from database\n"
            "5. Return to the select mode menu\n";
}

bool Administrator::valid(int input)
{
    // in case input is not int
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        return false;
    }
    return (1 <= input && input <= 5);
}

void Administrator::begin()
{
    this->exit = false;
}

void Administrator::addMovie()
{
    string title, genre, trailer;
    int likes, year;
    bool aux;


    do {
        try {
            cout << "Title: ";
            // getline instead of normal cin so input doesn't stop at whitespaces
            cin.ignore();
            getline(cin, title);
            cout << "Year: "; cin >> year;
            if (std::cin.fail())
                throw 1;

            cout << "Trailer: ";
            // getline instead of normal cin so input doesn't stop at whitespaces
            cin.ignore();
            getline(cin, title);

            cout << "Likes: "; cin >> likes;
            if (std::cin.fail())
                throw 1;

            cout << "Genre: "; cin >> genre;
            aux = true;
            if (std::cin.fail())
                throw 1;
        }
        catch (int err) {
            aux = false;
            cout << "PLEASE INSERT VALID INFORMATION." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
    } while (!aux);

    Film* movie = new Film(repo.getCount(), title, genre, trailer, year, likes);
    repo.add(movie);
}

void Administrator::removeMovie()
{
    string title, genre, trailer;
    int year;
    bool aux;
    cout << "Please type the movie you want to remove"<<endl;
    do {
        try {
            cout << "Title: ";
            // getline instead of normal cin so input doesn't stop at whitespaces
            cin.ignore();
            getline(cin, title);

            cout << "Year: ";
            cin >> year;
            aux = true;
            if (std::cin.fail())
                throw 1;
        }
        catch (int err) {
            aux = false;
            cout << "PLEASE INSERT VALID INFORMATION." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
    } while (!aux);
    Film* movie = this->repo.find(title, year);

    if (movie != nullptr && repo.remove(movie))
        cout << "Film successfully deleted!\n";
    else
        cout << "There is no such movie in the database.\n";
}

void Administrator::updateMovie()
{
    string title, newtrailer;
    int year, newnrlikes, answer;
    bool aux;
    do {
        try {
            cout << "Title: ";
            // getline instead of normal cin so input doesn't stop at whitespaces
            cin.ignore();
            getline(cin, title);

            cout << "Year: ";
            cin >> year;
            aux = true;
            if (std::cin.fail())
                throw 1;
        }
        catch (int err) {
            aux = false;
            cout << "PLEASE INSERT VALID INFORMATION." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
    } while (!aux);

    Film* movie = this->repo.find(title, year);
    if (movie == nullptr)
        cout << "There is no such movie in the database.";

    else
    {
        cout << "What do you want to update: number of likes, trailer or both?\n";
        do {
            try {
                cout << "Type 1 for changing the nr of likes, 2 for changing the trailer, 3 otherwise: ";
                cin >> answer;
                aux = true;
                if (std::cin.fail())
                    throw 1;
            }
            catch (int err) {
                aux = false;
                cout << "PLEASE INSERT VALID INFORMATION." << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            }
        } while (!aux);


        if (answer == 1)
        {
            cout << "Increase the number of likes with: ";
            cin >> newnrlikes;
            repo.update(movie, "", newnrlikes);
        }
        else if (answer == 2)
        {
            cout << "Give the new link for the trailer: ";
            cin >> newtrailer;
            repo.update(movie, newtrailer, 0);
        }
        else
        {
            cout << "Increase the number of likes with: ";
            cin >> newnrlikes;
            cout << "Give the new link for the trailer: ";
            cin >> newtrailer;
            repo.update(movie, newtrailer, newnrlikes);
        }
    }
}

void Administrator::allMovies()
{
    vector <Film*> movies = repo.listFilmsByGenre("");
    if (movies.empty())
        cout << "There are no movies." << endl;
    else
        for (int i = 0; i < movies.size(); i++)
            cout << movies[i]->toString() << endl;
}

void Administrator::execute(int n)
{
    switch (n)
    {
        case 1:
            updateMovie();
            break;

        case 2:
            addMovie();
            break;

        case 3:
            removeMovie();
            break;

        case 4:
            allMovies();
            break;

        case 5:
            exit = true;
            break;
    }
}

void Administrator::init()
{
    this->repo.initialize("List_of_movies.txt");
}

bool Administrator::end()
{
    return this->exit;
}