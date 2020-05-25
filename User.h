#pragma once
#include "UI.h"
#include "UserController.h"

class User : public UI
{
private:
    bool exit;
    UserController ctrl;

    void printFilmsByGenre();

    void addToWatchlist();

    void removeFromWatchlist();

    void showWatchlist();

    // displays the watchlist in csv- or html-format
    void displayWatchlist();

public:

    virtual void menu() override;

    virtual bool valid(int input) override;

    virtual void execute(int option) override;

    virtual void begin() override;

    virtual bool end() override;

    void init();
};
