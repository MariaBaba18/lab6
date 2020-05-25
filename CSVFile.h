#pragma once
#include "BaseFile.h"

class CSVFile : public BaseFile
{
public:
    // writes the elements from watchlist to a csv-file
    virtual void write(string filename, vector<Film> watchlist) override;

    // displays the content of  the file in excel
    virtual void display(string filename) override;
};
