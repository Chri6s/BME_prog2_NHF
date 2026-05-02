#ifndef TEAM_H
#define TEAM_H

#include "string5.h"

class Team {
        String teamName;
        int teamPlayerCount;
    public:
        Team() : teamName(""), teamPlayerCount(0) {}
        String getName() const;
        int getPlayerCount() const;
        bool setName(const String& newName);
        bool setPlayerCount(int newPlayerCount);
        virtual void print();
        virtual ~Team() {}
};

#endif