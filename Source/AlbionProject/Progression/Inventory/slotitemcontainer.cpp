#include "Progression/Inventory/slotitemcontainer.h"

USlotItemContainer::USlotItemContainer(const FObjectInitializer& ObjectInitializer)
    : m_Item(nullptr)
{
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

void USlotItemContainer::GiveItem(UItem& value)
{ 
    m_Item = &value;
}

UItem& USlotItemContainer::TakeItem()
{
    return *m_Item;
}