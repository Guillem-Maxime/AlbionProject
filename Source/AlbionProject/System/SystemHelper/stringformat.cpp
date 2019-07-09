#include "stringformat.h"

#include <memory>
#include <cstdarg>

#include "arrayhelper.h"

std::string StringFormat(const char* str, ...)
{
    char buffer[256];

    va_list args;
    va_start(args, str);
    const auto r = std::vsnprintf(buffer, sizeof buffer, str, args);
    va_end(args);

    if (r < 0)
        // conversion failed
        return {};

    const size_t lenght = r;
    if (lenght < sizeof buffer)
    {
        // we fit in the buffer
        return { buffer, lenght };
    }

    auto vbuf = std::unique_ptr<char[]>(new char[lenght + 1]);
    va_start(args, str);
    std::vsnprintf(vbuf.get(), lenght + 1, str, args);
    va_end(args);

    return { vbuf.get(), lenght };
}