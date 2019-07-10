#pragma once

#include "GameplayCommon/Utils/crtp.h"
#include "GameplayCommon/Utils/singleton.h"

#include "Runtime/Engine/Public/Tickable.h"

template<class Derived>
struct TManagerBase : public FTickableObjectBase, public TSingleton<TManagerBase<Derived>>, TCrtp<Derived, TManagerBase>
{
    TManagerBase() = default;
    virtual ~TManagerBase() {};

    void Init()
    {
        this->Underlying().Init();
    }

    virtual void Tick(float deltaTime) override
    {
        this->Underlying().OnTick(deltaTime);
    }

    void Shutdown()
    {
        this->Underlying().Shutdown();
    }

    virtual TStatId GetStatId() const
    {
        return m_StatId;
    }

protected:
    TStatId m_StatId;
};