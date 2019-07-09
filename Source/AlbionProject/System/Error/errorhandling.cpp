#include "System/Error/errorhandling.h"

#include <iostream>
#include <cassert>
#include <sstream>

#include "System/Log/Log.h"
#include "System/SystemHelper/stringformat.h"

void StopIntoDebugger(ELogChannel channel, const char* file, int line)
{
    std::ostringstream strStream{};
    strStream << "Assert in " << file << "(" << line << ")." << std::endl;
    LogError(strStream.str(), channel);
    assert(false);
}

void PauseIntoDebugger(const char* message, ELogChannel channel, const char* file, int line)
{
    std::ostringstream strStream{};
    strStream << "SoftAssert in " << file << "(" << line << ") " << message << std::endl;
    LogError( strStream.str(), channel);
    __debugbreak();
}