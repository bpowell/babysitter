#ifndef _BABYSITTER_H_
#define _BABYSITTER_H_

#include <ctime>
#include <string>

bool validtime(const struct tm t);
bool gettime(struct tm *t, const std::string time);

#endif
