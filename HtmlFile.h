#pragma once
#include "BaseFile.h"

class HtmlFile : public BaseFile
{
public:
    // writes the elements of watchlist to a html-file
    virtual void write(string filename, vector<Film> watchlist) override;

    // displays the content of the file in a browser
    virtual void display(string filename) override;
};
