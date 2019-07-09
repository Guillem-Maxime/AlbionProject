#pragma once

#include <iostream>

#include "System/Error/errorhandling.h"


#define LogInfo(str, channel) Log(str, ELogType::LogInfo , channel)
#define LogError(str, channel) Log(str, ELogType::LogError , channel)
#define LogDebug(str, channel) Log(str, ELogType::LogDebug , channel)

std::string d_ELogChannelNames[];
std::string d_ELogTypeNames[];

enum class ELogChannel
{
    LogEngine,
    LogGameplay,
    LogGraphics,
    LogSound,
    Count,
    Invalid
};

enum class ELogType
{
    LogInfo,
    LogError,
    LogDebug,
    Count,
    Invalid
};

std::string GetLogChannelName(ELogChannel channel);
std::string GetLogTypeName(ELogType logType);

inline void Log(char* str, ELogType logType, ELogChannel channel)
{
    std::cout << GetLogTypeName(logType) << "[" << GetLogChannelName(channel) << "] : " << str << std::endl;
}

inline void Log(std::string str, ELogType logType, ELogChannel channel)
{
    std::cout << GetLogTypeName(logType) << "[" << GetLogChannelName(channel) << "] : " << str << std::endl;
}