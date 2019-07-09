#include "System/Error/errorhandling.h"

#include <iostream>
#include <cassert>

#include "System/Log/Log.h"
#include "System/SystemHelper/stringformat.h"

void StopIntoDebugger(ELogChannel channel, char* file, int32 line)
{
    LogError( StringFormat("Assert in %s(%d).", file, line), channel);
    assert(false);
}

void PauseIntoDebugger(char* message, ELogChannel channel, char* file, int32 line)
{
    LogError( StringFormat("SoftAssert in %s(%d) %s.", file, line, message), channel);
    __debugbreak();
}