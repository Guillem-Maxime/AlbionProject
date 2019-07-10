#pragma once

#include "GameplayCommon/Utils/unique.h"

template<class T>
struct TSingleton : public TUnique<T>
{
    static T& GetInstance()
    {
        return static_cast<TUnique<T>>(*this).GetUniqueInstance();
    }
};