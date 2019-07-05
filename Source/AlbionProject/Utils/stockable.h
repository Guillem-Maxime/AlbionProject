#pragma once

template<class Derived>
class Stockable
{
public:
    int GetAmount() const { return m_Amount; }
    void SetAmount(const int value) 
    { 
        m_Amount = value;
        CheckAmount();
    }

    void AddAmount(const int value) { SetAmount(m_Amount + value); }
    void RemoveAmount(const int value) { SetAmount(m_Amount - value); }

    int GetMaxAmount()
    {
        Derived& derived = static_cast<Derived&>(*this);
        return derived.GetMaxAmount();
    }

    void GiveToStock(Stockable& stock)
    {
        const int maxAmount{ stock.GetMaxAmount() };
        stock.AddAmount(m_Amount);

        const int newStockAmount{ GetAmount() + stock.GetAmount() };
        SetAmount(maxAmount - newStockAmount);
        CheckAmount();
    }

    void TakeFromStock(Stockable& stock, const int amountToGet)
    {
        const int stockAmount{ stock.GetAmount() };
        if (stockAmount > amountToGet)
        {
            SetAmount(amountToGet);
            stock.RemoveAmount(amountToGet);
        }
    }

private:
    int m_Amount{ 1 };

    void CheckAmount()
    {
        if (m_Amount < 1)
        {
            Derived& derived = static_cast<Derived&>(*this);
            derived.RequestDestroy();
        }

        const int maxAmount{ GetMaxAmount() };
        if (m_Amount > maxAmount)
        {
            m_Amount = maxAmount;
        }
    }

    Stockable() {}
    friend Derived;
};