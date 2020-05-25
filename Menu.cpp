#include "Menu.h"
#include "UI.h"
#include "Administrator.h"
#include "User.h"

void Menu::mainmenu()
{
    UI interface = UI(), *ui;
    ui = &interface;

    Administrator admin;
    User user;
    admin.init();
    user.init();

    while (true)
    {
        ui->menu();
        int n = ui->input();

        if (ui->valid(n))
        {
            if (n == 1)
                ui = &admin;
            else if (n == 2)
                ui = &user;
            else
                break;

            ui->begin();

            while (!ui->end())
            {
                ui->menu();
                int op = ui->input();
                if (ui->valid(op))
                    ui->execute(op);
            }
        }
        else
            cout << "Please type a valid number!\n";

        ui = &interface;
    }

}
