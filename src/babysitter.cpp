#include <string.h>
#include <ctime>
#include <iostream>

#include "babysitter.h"

bool validtime(const struct tm t) {
    if ((t.tm_hour < 17 && t.tm_hour > 4) || t.tm_hour > 23 || t.tm_min > 59 ||
        t.tm_hour < 0 || t.tm_min < 0) {
        return false;
    }

    return true;
}

bool gettime(struct tm* t, const std::string time) {
    memset(t, 0, sizeof(struct tm));
    //Need to set the year to make std::difftime work correctly on macOS
    //  We don't really care what year it is.
    t->tm_year = 1970;

    //The best way to do this would be to write a parser or find some library to
    //  get time in any format.
    try {
        t->tm_hour = std::stoi(time.substr(0, 2), NULL);
        t->tm_min = std::stoi(time.substr(3, 5), NULL);

        //If the time is between midnight and 4am, increase the day by 1 to make diffing time work
        if (t->tm_hour <= 4) {
            t->tm_mday++;
        }
    } catch (const std::exception& e) {
        return false;
    }

    return validtime(*t);
}
