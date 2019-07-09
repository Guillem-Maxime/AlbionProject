#pragma once

#include "Progression/Inventory/slotitemcontainer.h"
#include "Utils/notcopyable.h"

#include "stockcontainer.generated.h"

enum class EItemType : uint8;

UCLASS()
class UStockContainer : public UObject, public TNotCopyable<UStockContainer>
{
    GENERATED_UCLASS_BODY()

public:
    UStockContainer(const int32 numberOfSlots);

    void AddToContainer(UItem& item);

private:
    UPROPERTY()
    TArray<USlotItemContainer*> m_ItemSlots;
    USlotItemContainer* m_NextEmptySlot;
    UPROPERTY()
    int32 m_NumberOfSlots;

    USlotItemContainer* FindNextAvailableSlotByType(EItemType itemType);
    void AddToEmptySlot(UItem& item);
    void SetNextEmptySlot();
};