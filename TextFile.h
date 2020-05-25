#pragma once
#include "BaseFile.h"

class TextFile :public BaseFile
{
public:
    // writes the elements of the repository to a txt-file
    virtual void write(string filename, vector<Film*> repo) override;
};

