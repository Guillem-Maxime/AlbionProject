#include "Progression/Inventory/Item.h"

UItem::UItem(const FObjectInitializer& ObjectInitializer)
    : m_MaxAmount(99)
    , m_Amount(0)
{
}

void UItem::RequestDestroy()
{
    
}
