#include "GameplayCommon/Manager/managerfactory.h"

#include "GameplayCommon/Utils/typeutils.h"

void ManagerFactory::Init()
{

}

void ManagerFactory::OnTick(float deltaTime)
{

}

void ManagerFactory::Shutdown()
{

}

template<class ManagerName>
void ManagerFactory::CreateManager()
{
    ManagerName* manager{ new ManagerName };
    m_ManagerList.Add(manager);
}

template<class ManagerName>
void ManagerFactory::DestroyManager()
{
    template<class RegisteredManager>
    const closure predicate = [](const RegisteredManager* registered) {TypeUtils::IsSame<ManagerName, RegisteredManager>()};
    ManagerName* manager{ m_ManagerList.FindByPredicate(predicate) };
}