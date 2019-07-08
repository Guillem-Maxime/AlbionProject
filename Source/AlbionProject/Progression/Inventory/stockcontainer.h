#pragma once

#include "Progression/Inventory/slotitemcontainer.h"
#include "Utils/notcopyable.h"

#include "stockcontainer.generated.h"

UCLASS()
class UStockContainer : public UObject, public TNotCopyable<UStockContainer>
{
    GENERATED_UCLASS_BODY()

public:
    UStockContainer(const int32 numberOfSlots);

private:
    UPROPERTY()
    TArray<USlotItemContainer*> m_ItemSlots;

    UPROPERTY()
    int32 m_NumberOfSlots;
};