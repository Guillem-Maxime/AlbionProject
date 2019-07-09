#pragma once

namespace ArrayHelper
{
    template<typename T, int32 N>
    constexpr int32 ArraySize(T (&)[N]) noexcept
    {
        return N;
    }
}