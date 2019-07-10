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
    void OnTick(float deltaTime);
    void Shutdown();

private:
    TArray<FTickableObjectBase*> m_ManagerList;

    template<class ManagerName>
    void CreateManager();
    
    template<class ManagerName>
    void DestroyManager();
};