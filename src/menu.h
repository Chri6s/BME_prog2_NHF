#ifndef MENU_H
#define MENU_H

#include "db_controller.h"
#include "sportclub.h"
#include "string5.h"

class Menu {
        DatabaseController database;
        SportClub currentClub;
        bool isRunning;

        void printOptions();
        void processChoice();
        void uiAddTeam();
        void uiDeleteTeam();
        void uiListTeams();
        void uiSave();
        void uiLoad();
        void cleanBuffer();
        void gracefulExit();

    public:
        Menu(const String& startupFile);
        void run();
};

#endif
