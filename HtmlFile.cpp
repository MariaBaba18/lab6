#include "HtmlFile.h"
#include <fstream>

using namespace std;

void HtmlFile::write(string filename, vector<Film> watchlist)
{
    ofstream html;
    html.open(filename, ofstream::out | ofstream::trunc);

    //header
    ifstream file("header.html");
    string str;
    while (getline(file, str))
        html << str << '\n';
    file.close();


    // write each movie from watchlist
    for (auto m : watchlist)
        html << "<tr><td>" << m.getTitle() << "</td><td>" << m.getGenre() << "</td><td>" << m.getYear() << " </td><td>" << m.getLikes() << "</td><td> <a href = " << m.getTrailer() << ">Link</a></td></tr>";

    //footerul
    ifstream file2("footer.html");
    while (getline(file2, str))
        html << str << '\n';
    file2.close();

    html.close();
}

void HtmlFile::display(string filename)
{
    string str = "start " + filename;
    system(str.c_str());  // convert str to const char*
}