#include "babysitter.h"
#include "gtest/gtest.h"

#include <ctime>

TEST(ValidTime, SetTimeBefore5PM) {
    struct tm t;
    memset(&t, 0, sizeof(struct tm));
    t.tm_hour = 15;

    ASSERT_FALSE(validtime(t));
}

TEST(ValidTime, SetTimeBefore4AM) {
    struct tm t;
    memset(&t, 0, sizeof(struct tm));
    t.tm_hour = 7;

    ASSERT_FALSE(validtime(t));
}

TEST(ValidTime, SetTimeHourLargerThan23) {
    struct tm t;
    memset(&t, 0, sizeof(struct tm));
    t.tm_hour = 25;

    ASSERT_FALSE(validtime(t));
}

TEST(ValidTime, SetTimeHourSmallerThan0) {
    struct tm t;
    memset(&t, 0, sizeof(struct tm));
    t.tm_hour = -01;

    ASSERT_FALSE(validtime(t));
}

TEST(ValidTime, SetTimeMinuteLargerThan59) {
    struct tm t;
    memset(&t, 0, sizeof(struct tm));
    t.tm_min = 61;

    ASSERT_FALSE(validtime(t));
}

TEST(ValidTime, SetTimeMinuteSmallerThan0) {
    struct tm t;
    memset(&t, 0, sizeof(struct tm));
    t.tm_min = -01;

    ASSERT_FALSE(validtime(t));
}

TEST(ValidTime, TimeInProperRange5PMto4AM) {
    struct tm t;
    memset(&t, 0, sizeof(struct tm));
    t.tm_min = 01;
    t.tm_hour = 17;

    ASSERT_TRUE(validtime(t));
}

TEST(ValidTime, NotSetTMStruct) {
    struct tm t;
    ASSERT_FALSE(validtime(t));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}