#pragma once

#include "Runtime/CoreUObject/Public/UObject/Object.h"

#include "Utils/stockable.h"

#include "item.generated.h"

UCLASS()
class Item : public UObject, public Stockable<Item> 
{
    GENERATED_UCLASS_BODY()

public:
    //Stockable Interface
    int GetMaxAmount() const { return m_MaxAmount; }
    void SetMaxAmount(const int value) { m_MaxAmount = value; }
    void RequestDestroy();

private:

    //Stockable member
    UPROPERTY(EditAnywhere, Category = Stock)
    int m_MaxAmount;
};