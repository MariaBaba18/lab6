#include "User.h"
#include "BaseFile.h"
#include "CSVFile.h"
#include "HtmlFile.h"

void User::printFilmsByGenre()
{
    string genre;
    cout << "Genre: "; cin >> genre;

    vector<Film*> movies = this->ctrl.findFilmByGenre(genre);

    if (movies.empty())
        cout << "There are no movies with the given genre: " << genre << '\n';
    else
        for (auto it : movies)
            cout << it->toString() << '\n';
}

void User::addToWatchlist()
{
    string title;
    int year;
    bool aux;

    do {
        try {
            cout << "Title: ";
            // getline instead of normal cin so input doesn't stop at whitespaces
            cin.ignore();
            getline(cin, title);
            cout << "Year: "; cin >> year;
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

    if (this->ctrl.addToWlist(title, year))
        cout << "Film successfully added!\n";
    else
        cout << "This movie does not exist or it is already in the watchlist.\n";
}

void User::removeFromWatchlist()
{
    bool aux = true;
    string title;
    int year;
    do {
        try {
            cout << "Title: ";
            // getline instead of normal cin so input doesn't stop at whitespaces
            cin.ignore();
            getline(cin, title);
            cout << "Year: "; cin >> year;
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

    string answer;
    cout << R"(Did you enjoy the movie? Type "Yes" or "No": )";
    cin >> answer;
    if (answer == "Yes")
        this->ctrl.addLike(title, year);

    if (this->ctrl.removeFromWlist(title, year))
        cout << "Film removed from the watchlist!\n";
    else
        cout << "This movie does not exist in watchlist.\n";
}

void User::showWatchlist()
{
    if (this->ctrl.getWatchlist().empty())
        cout << "There are no movies in the watchlist.\n";
    else
    {
        cout << "Movies in the watchlist: \n";
        for (auto it : this->ctrl.getWatchlist())
            cout << it.toString() << '\n';
    }
}

void User::displayWatchlist()
{
    BaseFile* filetype;
    CSVFile csv;
    HtmlFile html;

    int n;
    string filename;
    bool aux = true;

    do {
        try {
            cout << "1.Html\n2.Csv\nType the number of the format: ";
            cin >> n;
            aux = true;
            if (std::cin.fail() or (n != 1 && n != 2))
                throw 1;
        }
        catch (int err) {
            aux = false;
            cout << "PLEASE INSERT A VALID INFORMATION." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
    } while (!aux);

    if (n == 1)
    {
        filetype = &html;
        filename = "WatchlistPage.html";
    }
    else
    {
        filetype = &csv;
        filename = "WatchlistExcel.csv";
    }

    filetype->write(filename, this->ctrl.getWatchlist());
    filetype->display(filename);
}

void User::menu()
{
    cout << "\nThis is the user mode! \n\n"
            "Choose one of the following options:\n"
            "1. See the available films in a certain genre\n"
            "2. Add a movie to your watchlist\n"
            "3. Remove a movie from your watchlist\n"
            "4. See your watchlist\n"
            "5. Display watchlist in browser or CSV file\n"
            "6. Return to the select mode menu\n";
}

bool User::valid(int input)
{
    // in case input is not int
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        return false;
    }
    return (1 <= input && input <= 6);
}

void User::execute(int option)
{
    switch (option)
    {
        case 1:
            this->printFilmsByGenre();
            break;
        case 2:
            this->addToWatchlist();
            break;
        case 3:
            this->removeFromWatchlist();
            break;
        case 4:
            this->showWatchlist();
            break;
        case 5:
            this->displayWatchlist();
            break;
        case 6:
            this->exit = true;
            break;
    }
}

void User::begin()
{
    this->exit = false;
}

bool User::end()
{
    return this->exit;
}

void User::init()
{
    this->ctrl.init();
}