#ifndef SPORTCLUB_H
#define SPORTCLUB_H

#include "team.h"

class Sportclub {
        Team teams;
    public:
        Sportclub();
        bool addTeam();
        bool deleteTeam();
        void listTeam();
        Team getTeam();
        ~Sportclub();
};


#endif