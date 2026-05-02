#ifndef SPORTCLUB_H
#define SPORTCLUB_H

#include "team.h"
#include "vector.hpp"

class SportClub {
    Vector<Team*> teams;
    public:
    SportClub();
    bool addTeam(Team* team);
    bool deleteTeam(int index);
    void listTeams() const;
    Team* getTeam(int index) const;
    ~SportClub();
};


#endif