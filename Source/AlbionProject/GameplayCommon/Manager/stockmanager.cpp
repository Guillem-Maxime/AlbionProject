#include "GameplayCommon/Manager/stockmanager.h"

void StockManager::RegisterContainer(UStockContainer* container)
{
    m_StockContainers.Add(container);
}