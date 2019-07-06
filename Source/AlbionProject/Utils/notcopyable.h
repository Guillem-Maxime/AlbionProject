#pragma once

template<class T>
struct TNotCopyable
{
    T& operator=(const T& other) = delete;
    T(const T& other) = delete;
}