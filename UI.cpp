#include "UI.h"

void UI::menu()
{
    cout << "\nWELCOME!\n\n"
            "Please select a mode\n"
            "1. Administrator\n"
            "2. User\n"
            "3. Exit\n";
}

int UI::input()
{
    int n;
    cout << "Option nr: ";
    cin >> n;
    return n;
}

bool UI::valid(int input)
{
    // in case input is not int
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        return false;
    }

    // in case input is other than the available options
    return (1 <= input && input <= 3);
}
