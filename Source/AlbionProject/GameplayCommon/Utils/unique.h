#pragma once

#include "GameplayCommon/Utils/crtp.h"

#include "System/Error/errorhandling.h"

template<class T>
struct TUnique : TCrtp<T, TUnique>
{
public:

protected:
    TUnique()
    {
        CreateUnique();
    }

    ~TUnique()
    {
        ms_Instance = nullptr;
    }

    static T& GetUniqueInstance() 
    { 
        if (ms_Instance == nullptr)
        {
            CreateUnique();
        }
        return *(static_cast<T*> (ms_Instance));
    }

    static const T& GetUniqueInstance()
    {
        if (ms_Instance == nullptr)
        {
            CreateUnique();
        }
        return *(static_cast<const T*> (ms_Instance));
    }

    static void CreateUnique()
    {
        ASSERT(ms_Instance == nullptr, ELogChannel::LogGameplay);
        ms_Instance = new T;
    }

    static void DestroyUnique()
    {
        delete ms_Instance;
        ms_Instance = nullptr;
    }

private:
    static T* ms_Instance;
};

template<class T>
T* TUnique<T>::ms_Instance{ nullptr };