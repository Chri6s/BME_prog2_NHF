#include "team.h"


const String& Team::getName() const {
    return teamName;
}

int Team::getPlayerCount() const {
    return teamPlayerCount;
}

bool Team::setName(const String& newName) {
    teamName = newName;
    return true;
}

bool Team::setPlayerCount(int newPlayerCount) {
    if (newPlayerCount < 0) return false;
    teamPlayerCount = newPlayerCount;
    return true;
}
