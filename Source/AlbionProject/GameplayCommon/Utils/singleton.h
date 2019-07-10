#pragma once

#include "GameplayCommon/Utils/unique.h"

template<class T>
struct TSingleton : TCrtp<TUnique<T>, TSingleton>
{
    static T& GetInstance()
    {
        return this->Underlying().GetUniqueInstance();
    }
};