#pragma once

#include "Progression/Inventory/item.h"
#include "Utils/notcopyable.h"

class SlotItemContainer : public TNotCopyable<SlotItemContainer>
{
public:
    SlotItemContainer();
    ~SlotItemContainer() {}

    inline const UItem* GetItemView() const { return m_Item; }
    inline bool IsEmpty() const { return m_Item == nullptr; }

    void GiveItem(UItem*& value);
    UItem* TakeItem();

private:
    UItem* m_Item;
};