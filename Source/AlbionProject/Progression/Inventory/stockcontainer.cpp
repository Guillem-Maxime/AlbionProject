#include "Progression/Inventory/stockcontainer.h"

UStockContainer::UStockContainer(const FObjectInitializer& ObjectInitializer)
    : m_NumberOfSlots(5)
{
    m_ItemSlots.Reserve(m_NumberOfSlots);
    for (int32 i{ 0 }; i < m_NumberOfSlots; i++)
    {
        FString Name{ "StockContainer" };
        Name.AppendInt(i);

        USlotItemContainer* slot{ NewObject<USlotItemContainer>(this, FName(*Name)) };
        m_ItemSlots.Add(slot);
    }
    SetNextEmptySlot();
}

UStockContainer::UStockContainer(const int32 numberOfSlots)
    : m_NumberOfSlots(numberOfSlots)
{
    m_ItemSlots.Reserve(m_NumberOfSlots);
    for (int32 i{ 0 }; i < m_NumberOfSlots; i++)
    {
        FString Name{ "StockContainer" };
        Name.AppendInt(i);

        USlotItemContainer* slot{ NewObject<USlotItemContainer>(this, FName(*Name)) };
        m_ItemSlots.Add(slot);
    }
    SetNextEmptySlot();
}

USlotItemContainer* UStockContainer::FindNextAvailableSlotByType(EItemType itemType)
{
    const auto closure = [itemType](USlotItemContainer*& slotItem) { return (slotItem->GetItemType() == itemType) && (!slotItem->IsStockFull()); };
    return *m_ItemSlots.FindByPredicate(closure);
}

void UStockContainer::AddToContainer(UItem& item)
{
    USlotItemContainer* slotItemContainer{ FindNextAvailableSlotByType(item.GetItemType()) };
    while (slotItemContainer != nullptr)
    {
        slotItemContainer->TakeFromStock(item);
    }
    if (slotItemContainer == nullptr)
    {
        AddToEmptySlot(item);
    }
}

void UStockContainer::AddToEmptySlot(UItem& item)
{
    m_NextEmptySlot->GiveItem(item);
    SetNextEmptySlot();
}

void UStockContainer::SetNextEmptySlot()
{
    const auto closure = [](USlotItemContainer*& slotItem) { return slotItem->GetItemView() == nullptr; };
    USlotItemContainer* foundSlot{ *m_ItemSlots.FindByPredicate(closure) };
    m_NextEmptySlot = foundSlot;
}