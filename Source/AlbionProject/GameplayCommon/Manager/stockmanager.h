#pragma once

//#include "stockmanager.generated.h"

class UStockContainer;

class StockManager
{
public:
    void RegisterContainer(UStockContainer* container);

private:
    TArray<UStockContainer*> m_StockContainers;
};