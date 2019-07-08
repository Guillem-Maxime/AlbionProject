#pragma once

#include "Progression/Inventory/item.h"
#include "Utils/notcopyable.h"

class SlotItemContainer : public TNotCopyable<SlotItemContainer>
{
public:
    SlotItemContainer();
    SlotItemContainer(UItem* item);
    ~SlotItemContainer() {}

    UItem* GetItem() { return m_Item; }
    const UItem* GetItem() const { return m_Item; }
    void SetItem(UItem* value) { m_Item = value; }

private:
    UItem* m_Item;
};