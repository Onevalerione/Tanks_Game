#include "doctest.h"
#include "tanks.cpp"


TEST_SUITE_BEGIN("tests");

TEST_CASE ("doctest works properly") {
            REQUIRE(true);
}

TEST_CASE ("doctest works properl1") {
            REQUIRE(1 +3 == 4);
}

TEST_CASE ("creating vertical tank") {
        Ttank tank(1,11);
        REQUIRE(!tank.IsHoriz());
}

TEST_CASE ("check starting position") {
        Ttank tank(1,11);
            REQUIRE(((tank.sX == 1)&&(tank.sY == 11)));
}


TEST_CASE ("Crossing objects") {
            RECT a = {0, 0, 10, 10};
            RECT b = {5, 5, 15, 15};
            REQUIRE(IsCross(a, b));

}

TEST_SUITE_END();

