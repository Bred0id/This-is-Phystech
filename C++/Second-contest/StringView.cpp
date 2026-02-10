#ifndef UNTITLED22_STRING_VIEW_HPP
#define UNTITLED22_STRING_VIEW_HPP

struct StringView
{
    const char *data = nullptr;
    size_t N = 0;

    StringView() = default;

    StringView(const char *str)
    { // NOLINT
        data = str;
        if (str)
        {
            N = 0;
            while (str[N] != '\0')
            {
                N += 1;
            }
        }
    }

    StringView(const char *str, size_t size)
    {
        data = str;
        N = size;
    }

    char operator[](size_t i)
    {
        return data[i];
    }

    const char &operator[](size_t i) const
    {
        return data[i];
    }

    char Front()
    {
        return data[0];
    }

    const char &Front() const
    {
        return data[0];
    }

    char Back()
    {
        return data[N - 1];
    }

    const char &Back() const
    {
        return data[N - 1];
    }

    const char *Data() const
    {
        return data;
    }

    size_t Size() const
    {
        return N;
    }

    size_t Length() const
    {
        return N;
    }

    bool Empty() const
    {
        return N == 0;
    }

    void Swap(StringView &other)
    {
        const char *temp_data = data;
        size_t temp_size = N;
        data = other.data;
        N = other.N;
        other.data = temp_data;
        other.N = temp_size;
    }

    void RemovePrefix(size_t prefix_size)
    {
        if (prefix_size > N)
        {
            prefix_size = N;
        }
        N -= prefix_size;
        data += prefix_size;
    }

    void RemoveSuffix(size_t suffix_size)
    {
        if (suffix_size > N)
        {
            suffix_size = N;
        }
        N -= suffix_size;
    }

    StringView Substr(size_t pos, size_t count = -1) const
    {
        if (pos > N)
        {
            throw "StringViewOutOfRange";
        }
        if (count > N - pos)
        {
            count = N - pos;
        }
        return {data + pos, count};
    }
};

#endif
