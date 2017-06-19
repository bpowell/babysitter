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

TEST(GetTime, EmptyString) {
    struct tm t;
    ASSERT_FALSE(gettime(&t, ""));
}

TEST(GetTime, TimeAfter5PM) {
    struct tm t;
    ASSERT_TRUE(gettime(&t, "17:25"));
}

TEST(GetTime, TimeBefore4AM) {
    struct tm t;
    ASSERT_TRUE(gettime(&t, "03:25"));
}

TEST(GetTime, TimeOutSideWindow) {
    struct tm t;
    ASSERT_FALSE(gettime(&t, "13:25"));
}

TEST(GetTime, JunkData) {
    struct tm t;
    ASSERT_FALSE(gettime(&t, "fsfhdsjkfhskd"));
}

TEST(CalculatePay, StartAt5BedAt7HomeBy10) {
    struct tm start, bed, end;
    gettime(&start, "17:00");
    gettime(&bed, "19:00");
    gettime(&end, "22:00");

    ASSERT_EQ(calculatepay(start, bed, end), 48.00);
}

TEST(CalculatePay, StartAt5BedAt7HomeBy930) {
    struct tm start, bed, end;
    gettime(&start, "17:00");
    gettime(&bed, "19:00");
    gettime(&end, "21:30");

    ASSERT_EQ(calculatepay(start, bed, end), 40.00);
}

TEST(CalculatePay, StartAt5BedAt7HomeBy1AM) {
    struct tm start, bed, end;
    gettime(&start, "17:00");
    gettime(&bed, "19:00");
    gettime(&end, "01:00");

    ASSERT_EQ(calculatepay(start, bed, end), 80.00);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
