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
}