#ifndef ASSERT_H
#define ASSERT_H
#include <signal.h>

//TODO Make this also work on windows
#ifndef AIR_DISABLE_ASSERT
#define ASSERT(x) if (x) { } else { raise(SIGTRAP); }
#else
#define ASSERT(x) x
#endif

#endif //ASSERT_H
