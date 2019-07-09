#include "GameplayCommon/Progression/Inventory/stockcontainer.h"

#include "GameplayCommon/Progression/Inventory/item.h"
#include "GameplayCommon/Progression/Inventory/slotitemcontainer.h"

UStockContainer::UStockContainer(const FObjectInitializer& ObjectInitializer)
    : m_NumberOfSlots(5)
{
    m_ItemSlots.Reserve(m_NumberOfSlots);
    for (int32 i{ 0 }; i < m_NumberOfSlots; i++)
    {
        FString Name{ "StockContainer" };
        Name.AppendInt(i);

        USlotItemContainer* slot{ NewObject<USlotItemContainer>(this, FName(*Name)) };
        slot->SetStockContainer(this);
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

void UStockContainer::OnSlotEmptied()
{
    SetNextEmptySlot();
}

USlotItemContainer* UStockContainer::FindNextAvailableSlotByType(EItemType itemType)
{
    const auto closure = [itemType](USlotItemContainer*& slotItem) { return (slotItem->GetItemType() == itemType) && (!slotItem->IsStockFull()); };
    return *m_ItemSlots.FindByPredicate(closure);
}

void UStockContainer::AddToEmptySlot(UItem& item)
{
    m_NextEmptySlot->TakeItem(item);
    SetNextEmptySlot();
}

void UStockContainer::SetNextEmptySlot()
{
    const auto closure = [](USlotItemContainer*& slotItem) { return slotItem->GetItem() == nullptr; };
    USlotItemContainer* foundSlot{ *m_ItemSlots.FindByPredicate(closure) };
    m_NextEmptySlot = foundSlot;
}