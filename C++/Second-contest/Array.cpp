#ifndef UNTITLED22_ARRAY_H
#define UNTITLED22_ARRAY_H
#define ARRAY_TRAITS_IMPLEMENTED

template <class T, size_t N>
struct Array
{
    T data[N];

    T &operator[](size_t i)
    {
        return data[i];
    }

    const T &operator[](size_t i) const
    {
        return data[i];
    }

    T &Front()
    {
        return data[0];
    }

    const T &Front() const
    {
        return data[0];
    }

    T &Back()
    {
        return data[N - 1];
    }

    const T &Back() const
    {
        return data[N - 1];
    }

    T *Data()
    {
        return data;
    }

    const T *Data() const
    {
        return data;
    }

    size_t Size() const
    {
        return N;
    }

    bool Empty() const
    {
        return N == 0;
    }

    void Fill(const T &value)
    {
        for (size_t i = 0; i < N; i++)
        {
            data[i] = value;
        }
    }

    void Swap(Array<T, N> &other)
    {
        for (size_t i = 0; i < N; i++)
        {
            std::swap(data[i], other[i]);
        }
    }
};

template <class T>
size_t GetSize(const T &)
{
    return 0;
}

template <class T, size_t N>
size_t GetSize(T (&)[N])
{
    return N;
}

template <class T>
size_t GetRank(const T &)
{
    return 0;
}

template <class T, size_t N>
size_t GetRank(T (&array)[N])
{
    return 1 + GetRank(array[0]);
}

template <class T>
size_t GetNumElements(const T &)
{
    return 1;
}

template <class T, size_t N>
size_t GetNumElements(T (&array)[N])
{
    return N * GetNumElements(array[0]);
}

#endif