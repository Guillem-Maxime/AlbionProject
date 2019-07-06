#pragma once

#include "Utils/crtp.h"

template<class Derived>
struct TStockable : TCrtp<Derived, TStockable>
{
public:
    int TStockable_GetAmount() const { return this->Underlying().GetAmount(); }
    int TStockable_GetMaxAmount()
    {
        return this->Underlying().GetMaxAmount();
    }
    void TStockable_SetAmount(const int value)
    {
        this->Underlying().SetValue(value);
        TStockable_CheckAmount();
    }

    void TStockable_AddAmount(const int value) { TStockable_SetAmount(TStockable_GetAmount() + value); }
    void TStockable_RemoveAmount(const int value) { TStockable_SetAmount(TStockable_GetAmount() - value); }

    void TStockable_GiveToStock(TStockable& stock)
    {
        const int maxAmount{ stock.TStockable_GetMaxAmount() };
        stock.TStockable_AddAmount(TStockable_GetAmount());

        const int newStockAmount{ TStockable_GetAmount()() + stock.TStockable_GetAmount()() };
        TStockable_SetAmount(maxAmount - newStockAmount);
        TStockable_CheckAmount();
    }

    void TStockable_TakeFromStock(TStockable& stock, const int amountToGet)
    {
        const int stockAmount{ stock.TStockable_GetAmount()() };
        if (stockAmount > amountToGet)
        {
            TStockable_SetAmount(amountToGet);
            stock.TStockable_RemoveAmount(amountToGet);
        }
    }

private:

    void TStockable_CheckAmount()
    {
        if (TStockable_GetAmount < 1)
        {
            this->Underlying().RequestDestroy();
        }

        const int maxAmount{ TStockable_GetMaxAmount() };
        if (TStockable_GetAmount > maxAmount)
        {
            this->Underlying().SetValue(value);
        }
    }

    TStockable() {}
    friend Derived;
};