#include "TextFile.h"
#include <fstream>
using namespace std;

void TextFile::write(string filename, vector<Film*> repo)
{
    ofstream f;
    f.open(filename, ofstream::out | ofstream::trunc);

    for (auto m : repo)
        f << m->getTitle() << ',' << m->getGenre() << ',' << m->getTrailer() << ", " << m->getYear() << ", " << m->getLikes() << '\n';

    f.close();
}
