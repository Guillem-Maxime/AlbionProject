#pragma once

template<class Derived, template<typename> class TCrtpClass>
struct TCrtp
{
    Derived& Underlying() { static_cast<Derived&>(this*); }
    const Derived& Underlying() const { static_cast<const Derived&>(this*); }

private:
    TCrtp() {}
    friend TCrtpClass<Derived>;
};