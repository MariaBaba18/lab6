#include "CSVFile.h"
#include <fstream>
using namespace std;

void CSVFile::write(string filename, vector<Film> watchlist)
{
    ofstream csv;
    csv.open(filename, ofstream::out | ofstream::trunc);

    csv << "Title,Genre,Year,Likes,Trailer\n";

    for (auto m : watchlist)
        csv << m.getTitle() << ',' << m.getGenre() << ',' << m.getYear() << ',' << m.getLikes() << ',' << m.getTrailer() << '\n';

    csv.close();
}

void CSVFile::display(string filename)
{
    string str = "start " + filename;
    system(str.c_str());
}
