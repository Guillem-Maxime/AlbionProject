#pragma once

#include "GameplayCommon/Manager/managerbase.h"

class UStockContainer;

class StockManager : public TManagerBase<StockManager>
{
public:
    StockManager() = default;
    virtual ~StockManager() {}

    void Init();
    void Shutdown();

    //TManagerBase Interface
    void OnTick(float deltaTime);

    void RegisterContainer(UStockContainer* container);

private:
    TArray<UStockContainer*> m_StockContainers;
};