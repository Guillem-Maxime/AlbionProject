#pragma once

#include "GameplayCommon/Utils/singleton.h"
#include "GameplayCommon/Manager/managerbase.h"

#include "Runtime/Engine/Public/Tickable.h"

class ManagerFactory : public TManagerBase<ManagerFactory>
{
public:
    ManagerFactory() = default;
    virtual ~ManagerFactory() {}

    void Init();
    void Shutdown();

    //TManagerBase Interface
    void OnTick(float deltaTime);

private:
    TArray<FTickableObjectBase*> m_ManagerList;
    TStatId m_StatId;

    template<class ManagerName>
    void CreateManager();
};