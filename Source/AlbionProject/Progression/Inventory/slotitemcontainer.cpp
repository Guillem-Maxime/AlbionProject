#include "Progression/Inventory/slotitemcontainer.h"

SlotItemContainer::SlotItemContainer()
    : m_Item(nullptr)
{
}

void SlotItemContainer::GiveItem(UItem*& value)
{ 
    m_Item = value;
    value = nullptr;
}

UItem* SlotItemContainer::TakeItem()
{
    UItem* tmp{ m_Item };
    m_Item = nullptr;
    return tmp;
}