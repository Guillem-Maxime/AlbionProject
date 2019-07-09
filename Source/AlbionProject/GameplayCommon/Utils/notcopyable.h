#pragma once

#include "GameplayCommon/Utils/crtp.h"

template<class Derived>
struct TNotCopyable : TCrtp<Derived, TNotCopyable>
{
    TNotCopyable() = default;
    TNotCopyable(const TNotCopyable& other) = delete;
    Derived& operator=(const Derived& other) = delete;
};