#ifndef HANDBALL_H
#define HANDBALL_H

#include "team.h"

class Handball : public Team {
        int donation;
    public:
        Handball();
        int getDonation() const;
        bool setDonation(int newDonation);
        void print();
};

#endif
