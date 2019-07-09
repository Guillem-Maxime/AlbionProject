#pragma once

#include "GameplayCommon/Utils/notcopyable.h"

#include "slotitemcontainer.generated.h"

class UItem;
class UStockContainer;

enum class EItemType : uint8;

UCLASS()
class USlotItemContainer : public UObject, public TNotCopyable<USlotItemContainer>
{
    GENERATED_UCLASS_BODY()

public:
    USlotItemContainer();

    inline const UItem* GetItem() const { return m_Item; }
    inline bool IsEmpty() const { return m_Item == nullptr; }
    EItemType GetItemType() const;

    inline const UStockContainer* GetStockContainer() const { return m_StockContainer; }
    inline UStockContainer* GetStockContainer() { return m_StockContainer; }
    inline void SetStockContainer(UStockContainer* stockContainer) { m_StockContainer = stockContainer; }

    bool IsStockFull() const;
    void GiveToStock(UItem& item);
    void TakeFromStock(UItem& item);

    void TakeItem(UItem& value);
    UItem* GiveItem();

private:
    UPROPERTY()
    UStockContainer* m_StockContainer;
    UPROPERTY()
    UItem* m_Item;

    void EmptySlot();
};