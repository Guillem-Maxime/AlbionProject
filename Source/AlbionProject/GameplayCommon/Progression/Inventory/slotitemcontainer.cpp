#include "Progression/Inventory/slotitemcontainer.h"

#include "Progression/Inventory/item.h"
#include "Progression/Inventory/stockcontainer.h"

USlotItemContainer::USlotItemContainer(const FObjectInitializer& ObjectInitializer)
    : m_Item(nullptr)
    , m_StockContainer(nullptr)
{
}

EItemType USlotItemContainer::GetItemType() const
{ 
    return m_Item->GetItemType(); 
}

bool USlotItemContainer::IsStockFull() const
{
    return m_Item->Stockable_IsFull();
}

void USlotItemContainer::GiveToStock(UItem& item)
{
    m_Item->TStockable_GiveToStock(item);
}

void USlotItemContainer::TakeFromStock(UItem& item)
{
    m_Item->TStockable_TakeFromStock(item);
}

void USlotItemContainer::TakeItem(UItem& value)
{ 
    m_Item = &value;
}

UItem* USlotItemContainer::GiveItem()
{
    UItem* result{ m_Item };
    EmptySlot();
    return result;
}

void USlotItemContainer::EmptySlot()
{
    m_Item = nullptr;
    m_StockContainer->OnSlotEmptied();
}