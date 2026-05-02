#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include "db_session.h"
#include "db_status.h"

class DatabaseController {
        DatabaseSession currentSession;
    public:
        DatabaseController();
        DBStatus loadFromFile(const String& path);
        DBStatus saveToFile(const String& path);
        DBStatus createEmptyDatabase(const String& path);
        DBStatus validateFormat(const String& path);
};

#endif
