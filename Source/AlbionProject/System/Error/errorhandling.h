#pragma once

#include <string>

enum class ELogChannel;

#if NDEBUG

#define Assert(expr, channel) if(!(expr)) { StopIntoDebugger(channel, __FILE__, __LINE__); }

#define SoftAssert(expr, channel, message) if(!(expr)) { PauseIntoDebugger(message, channel, __FILE__, __LINE__); }

void StopIntoDebugger(ELogChannel channel, const char* file, int line);

void PauseIntoDebugger(const char* message, ELogChannel channel, const char* file, int line);

#else

#define Assert(expr) //evaluate to nothing

#define SoftAssert(expr) //evaluate to nothing

#endif //ERRORHANDLING_ENABLED