#pragma once

#include "GameplayCommon/Manager/managerbase.h"

class UStockContainer;

class StockManager : public TManagerBase<StockManager>
{
public:
    StockManager() = default;
    virtual ~StockManager() {}

    void Init();
    void OnTick(float deltaTime);
    void Shutdown();

    void RegisterContainer(UStockContainer* container);

private:
    TArray<UStockContainer*> m_StockContainers;
};