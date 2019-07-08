#pragma once

#include "Utils/crtp.h"

template<class Derived>
struct TNotCopyable : TCrtp<Derived, TNotCopyable>
{
    TNotCopyable(const TNotCopyable& other) = delete;
    Derived& operator=(const Derived& other) = delete;
};