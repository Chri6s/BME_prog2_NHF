#ifndef FOOTBALL_H
#define FOOTBALL_H

#include "team.h"

class Football : public Team {
        String coach1;
        String coach2;
    public:
        Football();
        String getCoach1() const;
        bool setCoach1(const String& newCoach1);
        String getCoach2() const;
        bool setCoach2(const String& newCoach2);
        void print();
};

#endif
