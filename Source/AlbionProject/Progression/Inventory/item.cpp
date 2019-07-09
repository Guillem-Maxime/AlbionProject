#include "Progression/Inventory/Item.h"

UItem::UItem(const FObjectInitializer& ObjectInitializer)
    : m_MaxAmount(99)
    , m_Amount(0)
    , m_ItemType(EItemType::ET_Invalid)
{
}

void UItem::OnStockEmpty()
{
    
}
