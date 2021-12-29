#pragma once

#include "include/std.h"
#include <signal.h>

void SignalTest()
{
    signal(SIGINT, SIG_IGN);
    while (true) {}
}