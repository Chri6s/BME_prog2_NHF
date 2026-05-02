#ifndef DATABASESESSION_H
#define DATABASESESSION_H

#include "string5.h"

class DatabaseSession {
        String activePath;
        bool hasActiveFile;
        bool dirty;
    public:
        DatabaseSession();
        DatabaseSession(const String& activePath);
        String getActivePath() const;
        bool getDirty() const;
        bool setDirty(bool isDirty);
};

#endif
