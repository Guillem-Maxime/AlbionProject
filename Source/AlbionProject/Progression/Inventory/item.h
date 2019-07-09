#pragma once

#include "Progression/Inventory/itemtype.h"
#include "Utils/stockable.h"

#include "item.generated.h"

UCLASS()
class UItem : public UObject, public TStockable<UItem> 
{
    GENERATED_UCLASS_BODY()

public:
    UItem();

    inline EItemType GetItemType() const { return m_ItemType; }

private:
    UPROPERTY(EditAnywhere, Category = Type)
    EItemType m_ItemType;

    //Stockable member
    UPROPERTY(VisibleAnywhere, Category = Stock)
    int m_Amount;

    UPROPERTY(EditAnywhere, Category = Stock)
    int m_MaxAmount;


    //Stockable Interface
    int GetMaxAmount() const { return m_MaxAmount; }
    void SetMaxAmount(const int value) { m_MaxAmount = value; }
    int GetAmount() const { return m_Amount; }
    void SetAmount(const int value) { m_Amount = value; }
    void OnStockEmpty();

    friend TStockable<UItem>;
};