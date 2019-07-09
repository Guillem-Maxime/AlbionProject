#pragma once

#include "Utils/crtp.h"

template<class Derived>
struct TStockable : TCrtp<Derived, TStockable>
{
public:
    bool Stockable_IsFull() { return TStockable_GetAmount() == TStockable_GetMaxAmount(); }

    void TStockable_GiveToStock(TStockable& otherStock) { TStockable_TransferStock(*this, otherStock); }
    void TStockable_TakeFromStock(TStockable& otherStock) { TStockable_TransferStock(otherStock, *this); }

    void TStockable_EmptyStock() { TStockable_SetAmount(0); }

private:
    TStockable() {}
    friend Derived;

    int32 TStockable_GetAmount() const { return this->Underlying().GetAmount(); }
    int32 TStockable_GetMaxAmount() const { return this->Underlying().GetMaxAmount(); }
    void TStockable_SetAmount(const int32 value);

    void TStockable_AddAmount(const int32 value) { TStockable_SetAmount(TStockable_GetAmount() + value); }
    void TStockable_RemoveAmount(const int32 value) { TStockable_SetAmount(TStockable_GetAmount() - value); }

    void TStockable_TransferStock(TStockable& fromStock, TStockable& toStock) const;
};

template<class Derived>
void TStockable<Derived>::TStockable_SetAmount(const int32 value)
{
    Derived& thisUnderlying{ this->Underlying() };
    if (value <= 0)
    {
        thisUnderlying.SetAmount(0);
        thisUnderlying.OnStockEmpty();
    }

    const int maxAmount{ TStockable_GetMaxAmount() };
    if (TStockable_GetAmount() > maxAmount)
    {
        thisUnderlying.SetAmount(maxAmount);
    }
}

template<class Derived>
void TStockable<Derived>::TStockable_TransferStock(TStockable& fromStock, TStockable& toStock) const
{
    const int32 maxToStockAmount{ toStock.TStockable_GetMaxAmount() };
    const int32 newToStockAmount{ toStock.TStockable_GetAmount() + fromStock.TStockable_GetAmount() };

    toStock.TStockable_SetAmount(newToStockAmount);

    if (newToStockAmount > maxToStockAmount)
    {
        fromStock.TStockable_SetAmount(newToStockAmount - maxToStockAmount);
    }
    else
    {
        fromStock.TStockable_EmptyStock();
    }
}