#include "Progression/Inventory/stockmanager.h"

void StockManager::RegisterContainer(UStockContainer* container)
{
    m_StockContainers.Add(container);
}