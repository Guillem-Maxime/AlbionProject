#pragma once

template<class Derived, template<typename> class TCrtpClass>
struct TCrtp
{
    Derived& Underlying() { return static_cast<Derived&>(*this); }
    const Derived& Underlying() const { return static_cast<const Derived&>(*this); }

private:
    TCrtp() {}
    friend TCrtpClass<Derived>;
};