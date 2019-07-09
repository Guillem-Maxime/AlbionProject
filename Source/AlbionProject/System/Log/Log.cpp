#include "System/Log/log.h"

#include "System/SystemHelper/arrayhelper.h"

std::string d_ELogChannelNames[]
{
    "LogEngine",
    "LogGameplay",
    "LogGraphics",
    "LogSound"
};

static_assert(ArrayHelper::ArraySize(d_ELogChannelNames) == static_cast<int32>(ELogChannel::Count), "Size mismatch between ELogChannel and d_ELogChannelNames did you changed the enum without changing the names ?");

std::string GetLogChannelName(ELogChannel channel)
{
    Assert(static_cast<int32>(channel) < static_cast<int32>(ELogChannel::Count), ELogChannel::LogEngine);
    return d_ELogChannelNames[static_cast<int32>(channel)];
}

std::string d_ELogTypeNames[]
{
    "LogInfo",
    "LogError",
    "LogDebug"
};

static_assert(ArrayHelper::ArraySize(d_ELogTypeNames) == static_cast<int32>(ELogType::Count), "Size mismatch between ELogType and d_ELogChannelNames did you changed the enum without changing the names ?");

std::string GetLogTypeName(ELogType logType)
{
    Assert(static_cast<int32>(logType) < static_cast<int32>(ELogType::Count), ELogChannel::LogEngine);
    return d_ELogTypeNames[static_cast<int32>(logType)];
}