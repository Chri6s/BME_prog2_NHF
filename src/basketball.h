#ifndef BASKETBALL_H
#define BASKETBALL_H

#include "team.h"

class Basketball : public Team {
        int cheerleadersCount;
    public:
        Basketball();
        int getCheerleadersCount() const;
        bool setCheerleadersCount(int newCheerleadersCount);
        void print();
};

#endif
