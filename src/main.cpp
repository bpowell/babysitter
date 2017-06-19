#include <string.h>
#include <ctime>
#include <iostream>

#include "babysitter.h"

int main(int argc, char* argv[]) {
    struct tm starttime, endtime, bedtime;
    std::string buffer;

    do {
        std::cout << "Enter start time in 24 hour format (17:25): ";
        std::cin >> buffer;
    } while (gettime(&starttime, buffer) != true);

    for (;;) {
        std::cout << "Enter bed time in 24 hour format (22:30): ";
        std::cin >> buffer;
        if (gettime(&bedtime, buffer) == true &&
            std::difftime(mktime(&bedtime), mktime(&starttime)) > 0) {
            break;
        }
    }

    for (;;) {
        std::cout << "Enter leave time in 24 hour format (23:30): ";
        std::cin >> buffer;
        if (gettime(&endtime, buffer) == true &&
            std::difftime(mktime(&endtime), mktime(&bedtime)) > 0) {
            break;
        }
    }

    std::cout << calculatepay(starttime, bedtime, endtime) << std::endl;
    return 0;
}
