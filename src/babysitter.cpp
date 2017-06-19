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
