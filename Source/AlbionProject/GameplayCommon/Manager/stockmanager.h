#pragma once

class UStockContainer;

class StockManager
{
public:
    void RegisterContainer(UStockContainer* container);

private:
    TArray<UStockContainer*> m_StockContainers;
};