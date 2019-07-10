#pragma once

namespace TypeUtils
{
    template<class T1, class T2>
    bool IsEqual(T1 t1, T2 t2)
    {
        return T1 == T2;
    }
}