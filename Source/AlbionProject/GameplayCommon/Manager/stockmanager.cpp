#include "GameplayCommon/Manager/stockmanager.h"

void StockManager::Init()
{

}

void StockManager::OnTick(float deltaTime)
{

}

void StockManager::Shutdown()
{

}

void StockManager::RegisterContainer(UStockContainer* container)
{
    m_StockContainers.Add(container);
}