#include "GameplayCommon/Manager/stockmanager.h"

void StockManager::Init()
{

}

void StockManager::Shutdown()
{

}

//TManagerBase Interface
void StockManager::OnTick(float deltaTime)
{

}

void StockManager::RegisterContainer(UStockContainer* container)
{
    m_StockContainers.Add(container);
}