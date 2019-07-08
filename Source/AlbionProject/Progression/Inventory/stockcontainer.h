#pragma once

#include "Progression/Inventory/slotitemcontainer.h"
#include "Utils/notcopyable.h"

class StockContainer : TNotCopyable<StockContainer>
{
public:
    StockContainer(const int numberOfSlots);

private:
    TArray<SlotItemContainer> m_Items;
    int m_NumberOfSlots;
};