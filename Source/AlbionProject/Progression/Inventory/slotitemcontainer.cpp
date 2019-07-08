#include "Progression/Inventory/slotitemcontainer.h"

USlotItemContainer::USlotItemContainer(const FObjectInitializer& ObjectInitializer)
    : m_Item(nullptr)
{
}

void USlotItemContainer::GiveItem(UItem*& value)
{ 
    m_Item = value;
    value = nullptr;
}

UItem* USlotItemContainer::TakeItem()
{
    UItem* tmp{ m_Item };
    m_Item = nullptr;
    return tmp;
}