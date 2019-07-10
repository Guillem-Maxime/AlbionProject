#include "GameplayCommon/Manager/managerfactory.h"

#include "GameplayCommon/Manager/stockmanager.h"
#include "GameplayCommon/Utils/typeutils.h"

void ManagerFactory::Init()
{
    CreateManager<StockManager>();
}

void ManagerFactory::Shutdown()
{
    for (const FTickableObjectBase* manager : m_ManagerList)
    {
        delete manager;
        manager = nullptr;
    }
    m_ManagerList.Empty();
}

//TManagerBase Interface
void ManagerFactory::OnTick(float deltaTime)
{

}

template<class ManagerName>
void ManagerFactory::CreateManager()
{
    ManagerName* manager{ new ManagerName };
    m_ManagerList.Add(manager);
}