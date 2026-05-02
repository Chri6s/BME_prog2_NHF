#include "gtest_lite.h"

#include "basketball.h"
#include "db_controller.h"
#include "db_session.h"
#include "db_status.h"
#include "football.h"
#include "handball.h"
#include "menu.h"
#include "sportclub.h"
#include "team.h"

#include <type_traits>

int main() {
    TEST(Relationships, Inheritance)
        EXPECT_TRUE((std::is_base_of<Team, Basketball>::value));
        EXPECT_TRUE((std::is_base_of<Team, Football>::value));
        EXPECT_TRUE((std::is_base_of<Team, Handball>::value));
    END

    TEST(Interfaces, Signatures)
        EXPECT_TRUE((std::is_same<decltype(&Team::setName), bool (Team::*)(const String&)>::value));
        EXPECT_TRUE((std::is_same<decltype(&Team::setPlayerCount), bool (Team::*)(int)>::value));
        EXPECT_TRUE((std::is_same<decltype(&DatabaseController::loadFromFile), DBStatus (DatabaseController::*)(const String&)>::value));
        EXPECT_TRUE((std::is_same<decltype(&DatabaseSession::setDirty), bool (DatabaseSession::*)(bool)>::value));
    END

    TEST(Types, Existence)
        EXPECT_TRUE((std::is_enum<DBStatus>::value));
        EXPECT_TRUE((std::is_class<Menu>::value));
        EXPECT_TRUE((std::is_class<SportClub>::value));
    END

    return 0;
}
