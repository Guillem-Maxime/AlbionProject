#pragma once

#include "Progression/Inventory/item.h"
#include "Utils/notcopyable.h"

#include "slotitemcontainer.generated.h"

UCLASS()
class USlotItemContainer : public UObject, public TNotCopyable<USlotItemContainer>
{
    GENERATED_UCLASS_BODY()

public:
    USlotItemContainer();

    inline const UItem* GetItemView() const { return m_Item; }
    inline bool IsEmpty() const { return m_Item == nullptr; }
    inline EItemType GetItemType() const { return m_Item->GetItemType(); }

    bool IsStockFull() const;
    void GiveToStock(UItem& item);
    void TakeFromStock(UItem& item);

    void GiveItem(UItem& value);
    UItem& TakeItem();

private:
    UPROPERTY()
    UItem* m_Item;
};