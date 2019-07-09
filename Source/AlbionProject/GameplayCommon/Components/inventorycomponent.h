#pragma once

#include "Progression/Inventory/stockcontainer.h"

#include "inventorycomponent.generated.h"

UCLASS()
class UInventoryComponent : public UActorComponent
{
    GENERATED_UCLASS_BODY()
public:
    virtual void OnRegister() override;

private:
    UStockContainer m_StockContainer;
};