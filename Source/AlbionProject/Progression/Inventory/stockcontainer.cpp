#include "Progression/Inventory/stockcontainer.h"

StockContainer::StockContainer(const int numberOfSlots)
    : m_NumberOfSlots(numberOfSlots)
{
    m_Items.Reserve(m_NumberOfSlots);
}