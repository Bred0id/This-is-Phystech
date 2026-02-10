#ifndef UNTITLED17_VECTOR_H
#define UNTITLED17_VECTOR_H

#define VECTOR_MEMORY_IMPLEMENTED

#include <iterator>
#include <initializer_list>
#include <algorithm>
#include <stdexcept>
#include <new>
#include <utility>
#include <cstddef>

class IndexOutOfRange : public std::out_of_range
{
public:
    IndexOutOfRange() : std::out_of_range("IndexOutOfRange") {}
};

class LengthError : public std::length_error
{
public:
    LengthError() : std::length_error("LengthError") {}
};

template <class T>
class Vector
{
    T *data_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

    T *Allocate(size_t n)
    {
        if (n == 0)
        {
            return nullptr;
        }
        void *raw = ::operator new(n * sizeof(T));
        return static_cast<T *>(raw);
    }

    void Deallocate(T *p)
    {
        ::operator delete(p);
    }

    void Destroy(T *p, size_t n)
    {
        if (p == nullptr)
        {
            return;
        }
        for (size_t i = 0; i < n; ++i)
        {
            (p + i)->~T();
        }
    }

public:
    using ValueType = T;
    using Pointer = T *;
    using ConstPointer = const T *;
    using Reference = T &;
    using ConstReference = const T &;
    using SizeType = size_t;
    using Iterator = T *;
    using ConstIterator = const T *;
    using ReverseIterator = std::reverse_iterator<Iterator>;
    using ConstReverseIterator = std::reverse_iterator<ConstIterator>;

    Vector()
    {
        data_ = nullptr;
        size_ = 0;
        capacity_ = 0;
    }

    explicit Vector(size_t n)
    {
        data_ = nullptr;
        size_ = 0;
        capacity_ = 0;
        if (n == 0)
        {
            return;
        }
        T *new_data = Allocate(n);
        size_t built = 0;
        try
        {
            for (size_t i = 0; i < n; ++i)
            {
                new (new_data + i) T();
                ++built;
            }
        }
        catch (...)
        {
            Destroy(new_data, built);
            Deallocate(new_data);
            throw;
        }
        data_ = new_data;
        size_ = n;
        capacity_ = n;
    }

    Vector(size_t n, const T &value)
    {
        data_ = nullptr;
        size_ = 0;
        capacity_ = 0;
        if (n == 0)
        {
            return;
        }
        T *new_data = Allocate(n);
        size_t built = 0;
        try
        {
            for (size_t i = 0; i < n; ++i)
            {
                new (new_data + i) T(value);
                ++built;
            }
        }
        catch (...)
        {
            Destroy(new_data, built);
            Deallocate(new_data);
            throw;
        }
        data_ = new_data;
        size_ = n;
        capacity_ = n;
    }

    template <std::forward_iterator Iterator>
    Vector(Iterator first, Iterator last)
    {
        data_ = nullptr;
        size_ = 0;
        capacity_ = 0;
        size_t count = 0;
        for (Iterator it = first; it != last; ++it)
        {
            ++count;
        }
        if (count == 0)
        {
            return;
        }
        T *new_data = Allocate(count);
        size_t built = 0;
        try
        {
            size_t index = 0;
            for (Iterator it = first; it != last; ++it)
            {
                new (new_data + index) T(*it);
                ++built;
                ++index;
            }
        }
        catch (...)
        {
            Destroy(new_data, built);
            Deallocate(new_data);
            throw;
        }
        data_ = new_data;
        size_ = count;
        capacity_ = count;
    }

    Vector(std::initializer_list<T> init) : Vector(init.begin(), init.end())
    {
    }

    Vector(const Vector &other)
    {
        data_ = nullptr;
        size_ = 0;
        capacity_ = 0;
        if (other.size_ == 0)
        {
            return;
        }
        T *new_data = Allocate(other.size_);
        size_t built = 0;
        try
        {
            for (size_t i = 0; i < other.size_; ++i)
            {
                new (new_data + i) T(other.data_[i]);
                ++built;
            }
        }
        catch (...)
        {
            Destroy(new_data, built);
            Deallocate(new_data);
            throw;
        }
        data_ = new_data;
        size_ = other.size_;
        capacity_ = other.size_;
    }

    Vector &operator=(const Vector &other)
    {
        if (this == &other)
        {
            return *this;
        }
        Vector tmp(other);
        Swap(tmp);
        return *this;
    }

    Vector(Vector &&other)
    {
        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    Vector &operator=(Vector &&other)
    {
        if (this == &other)
        {
            return *this;
        }
        Destroy(data_, size_);
        Deallocate(data_);
        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
        return *this;
    }

    ~Vector()
    {
        Destroy(data_, size_);
        Deallocate(data_);
    }

    bool Empty() const
    {
        bool result = (size_ == 0);
        return result;
    }

    size_t Size() const
    {
        size_t result = size_;
        return result;
    }

    size_t Capacity() const
    {
        size_t result = capacity_;
        return result;
    }

    T &operator[](size_t i)
    {
        return data_[i];
    }

    const T &operator[](size_t i) const
    {
        return data_[i];
    }

    T &At(size_t i)
    {
        if (i >= size_)
        {
            throw IndexOutOfRange();
        }
        return data_[i];
    }

    const T &At(size_t i) const
    {
        if (i >= size_)
        {
            throw IndexOutOfRange();
        }
        return data_[i];
    }

    T &Front()
    {
        if (Empty())
        {
            throw IndexOutOfRange();
        }
        return data_[0];
    }

    const T &Front() const
    {
        if (Empty())
        {
            throw IndexOutOfRange();
        }
        return data_[0];
    }

    T &Back()
    {
        if (Empty())
        {
            throw IndexOutOfRange();
        }
        return data_[size_ - 1];
    }

    const T &Back() const
    {
        if (Empty())
        {
            throw IndexOutOfRange();
        }
        return data_[size_ - 1];
    }

    T *Data()
    {
        return data_;
    }

    const T *Data() const
    {
        return data_;
    }

    void Swap(Vector &other)
    {
        T *tmp_data = data_;
        data_ = other.data_;
        other.data_ = tmp_data;
        size_t tmp_size = size_;
        size_ = other.size_;
        other.size_ = tmp_size;
        size_t tmp_cap = capacity_;
        capacity_ = other.capacity_;
        other.capacity_ = tmp_cap;
    }

    void Clear()
    {
        Destroy(data_, size_);
        size_ = 0;
    }

    void Reserve(size_t new_cap)
    {
        if (new_cap <= capacity_)
        {
            return;
        }
        T *new_data = Allocate(new_cap);
        size_t built = 0;
        try
        {
            for (size_t i = 0; i < size_; ++i)
            {
                new (new_data + i) T(std::move(data_[i]));
                ++built;
            }
        }
        catch (...)
        {
            Destroy(new_data, built);
            Deallocate(new_data);
            throw;
        }
        Destroy(data_, size_);
        Deallocate(data_);
        data_ = new_data;
        capacity_ = new_cap;
    }

    void ShrinkToFit()
    {
        if (capacity_ == size_)
        {
            return;
        }
        if (size_ == 0)
        {
            Deallocate(data_);
            data_ = nullptr;
            capacity_ = 0;
            return;
        }
        T *new_data = Allocate(size_);
        size_t built = 0;
        try
        {
            for (size_t i = 0; i < size_; ++i)
            {
                new (new_data + i) T(std::move(data_[i]));
                ++built;
            }
        }
        catch (...)
        {
            Destroy(new_data, built);
            Deallocate(new_data);
            throw;
        }
        Destroy(data_, size_);
        Deallocate(data_);
        data_ = new_data;
        capacity_ = size_;
    }

    void Resize(size_t new_size)
    {
        if (new_size == size_)
        {
            return;
        }
        if (new_size < size_)
        {
            for (size_t i = new_size; i < size_; ++i)
            {
                (data_ + i)->~T();
            }
            size_ = new_size;
            return;
        }
        if (new_size <= capacity_)
        {
            size_t built = 0;
            try
            {
                for (size_t i = size_; i < new_size; ++i)
                {
                    new (data_ + i) T();
                    ++built;
                }
            }
            catch (...)
            {
                for (size_t j = 0; j < built; ++j)
                {
                    (data_ + size_ + j)->~T();
                }
                throw;
            }
            size_ = new_size;
            return;
        }
        T *new_data = Allocate(new_size);
        size_t tail_built = 0;
        try
        {
            for (size_t i = size_; i < new_size; ++i)
            {
                new (new_data + i) T();
                ++tail_built;
            }
        }
        catch (...)
        {
            for (size_t j = 0; j < tail_built; ++j)
            {
                (new_data + size_ + j)->~T();
            }
            Deallocate(new_data);
            throw;
        }
        size_t head_built = 0;
        try
        {
            for (size_t i = 0; i < size_; ++i)
            {
                new (new_data + i) T(std::move(data_[i]));
                ++head_built;
            }
        }
        catch (...)
        {
            for (size_t j = 0; j < head_built; ++j)
            {
                (new_data + j)->~T();
            }
            for (size_t j = 0; j < tail_built; ++j)
            {
                (new_data + size_ + j)->~T();
            }
            Deallocate(new_data);
            throw;
        }
        Destroy(data_, size_);
        Deallocate(data_);
        data_ = new_data;
        size_ = new_size;
        capacity_ = new_size;
    }

    void Resize(size_t new_size, const T &value)
    {
        if (new_size == size_)
        {
            return;
        }
        if (new_size < size_)
        {
            for (size_t i = new_size; i < size_; ++i)
            {
                (data_ + i)->~T();
            }
            size_ = new_size;
            return;
        }
        if (new_size <= capacity_)
        {
            size_t built = 0;
            try
            {
                for (size_t i = size_; i < new_size; ++i)
                {
                    new (data_ + i) T(value);
                    ++built;
                }
            }
            catch (...)
            {
                for (size_t j = 0; j < built; ++j)
                {
                    (data_ + size_ + j)->~T();
                }
                throw;
            }
            size_ = new_size;
            return;
        }
        T *new_data = Allocate(new_size);
        size_t tail_built = 0;
        try
        {
            for (size_t i = size_; i < new_size; ++i)
            {
                new (new_data + i) T(value);
                ++tail_built;
            }
        }
        catch (...)
        {
            for (size_t j = 0; j < tail_built; ++j)
            {
                (new_data + size_ + j)->~T();
            }
            Deallocate(new_data);
            throw;
        }
        size_t head_built = 0;
        try
        {
            for (size_t i = 0; i < size_; ++i)
            {
                new (new_data + i) T(std::move(data_[i]));
                ++head_built;
            }
        }
        catch (...)
        {
            for (size_t j = 0; j < head_built; ++j)
            {
                (new_data + j)->~T();
            }
            for (size_t j = 0; j < tail_built; ++j)
            {
                (new_data + size_ + j)->~T();
            }
            Deallocate(new_data);
            throw;
        }
        Destroy(data_, size_);
        Deallocate(data_);
        data_ = new_data;
        size_ = new_size;
        capacity_ = new_size;
    }

    void PushBack(const T &value)
    {
        if (size_ < capacity_)
        {
            new (data_ + size_) T(value);
            ++size_;
            return;
        }
        size_t new_cap = 0;
        if (capacity_ == 0)
        {
            new_cap = 1;
        }
        else
        {
            new_cap = capacity_ * 2;
        }
        T *new_data = Allocate(new_cap);
        bool new_elem_ok = false;
        try
        {
            new (new_data + size_) T(value);
            new_elem_ok = true;
        }
        catch (...)
        {
            Deallocate(new_data);
            throw;
        }
        size_t built = 0;
        try
        {
            for (size_t i = 0; i < size_; ++i)
            {
                new (new_data + i) T(std::move(data_[i]));
                ++built;
            }
        }
        catch (...)
        {
            Destroy(new_data, built);
            if (new_elem_ok)
            {
                (new_data + size_)->~T();
            }
            Deallocate(new_data);
            throw;
        }
        Destroy(data_, size_);
        Deallocate(data_);
        data_ = new_data;
        capacity_ = new_cap;
        ++size_;
    }

    void PushBack(T &&value)
    {
        if (size_ < capacity_)
        {
            new (data_ + size_) T(std::move(value));
            ++size_;
            return;
        }
        size_t new_cap = 0;
        if (capacity_ == 0)
        {
            new_cap = 1;
        }
        else
        {
            new_cap = capacity_ * 2;
        }
        T *new_data = Allocate(new_cap);
        bool new_elem_ok = false;
        try
        {
            new (new_data + size_) T(std::move(value));
            new_elem_ok = true;
        }
        catch (...)
        {
            Deallocate(new_data);
            throw;
        }
        size_t built = 0;
        try
        {
            for (size_t i = 0; i < size_; ++i)
            {
                new (new_data + i) T(std::move(data_[i]));
                ++built;
            }
        }
        catch (...)
        {
            Destroy(new_data, built);
            if (new_elem_ok)
            {
                (new_data + size_)->~T();
            }
            Deallocate(new_data);
            throw;
        }
        Destroy(data_, size_);
        Deallocate(data_);
        data_ = new_data;
        capacity_ = new_cap;
        ++size_;
    }

    template <class... Args>
    T &EmplaceBack(Args &&...args)
    {
        if (size_ < capacity_)
        {
            new (data_ + size_) T(std::forward<Args>(args)...);
            ++size_;
            return data_[size_ - 1];
        }
        size_t new_cap = 0;
        if (capacity_ == 0)
        {
            new_cap = 1;
        }
        else
        {
            new_cap = capacity_ * 2;
        }
        T *new_data = Allocate(new_cap);
        bool new_elem_ok = false;
        try
        {
            new (new_data + size_) T(std::forward<Args>(args)...);
            new_elem_ok = true;
        }
        catch (...)
        {
            Deallocate(new_data);
            throw;
        }
        size_t built = 0;
        try
        {
            for (size_t i = 0; i < size_; ++i)
            {
                new (new_data + i) T(std::move(data_[i]));
                ++built;
            }
        }
        catch (...)
        {
            Destroy(new_data, built);
            if (new_elem_ok)
            {
                (new_data + size_)->~T();
            }
            Deallocate(new_data);
            throw;
        }
        Destroy(data_, size_);
        Deallocate(data_);
        data_ = new_data;
        capacity_ = new_cap;
        ++size_;
        return data_[size_ - 1];
    }

    void PopBack()
    {
        if (size_ == 0)
        {
            return;
        }
        (data_ + (size_ - 1))->~T();
        --size_;
    }

    Iterator begin()
    {
        return data_;
    }

    Iterator end()
    {
        if (data_ == nullptr)
        {
            return nullptr;
        }
        return data_ + size_;
    }

    ConstIterator begin() const
    {
        return data_;
    }

    ConstIterator end() const
    {
        if (data_ == nullptr)
        {
            return nullptr;
        }
        return data_ + size_;
    }

    ConstIterator cbegin() const
    {
        return data_;
    }

    ConstIterator cend() const
    {
        if (data_ == nullptr)
        {
            return nullptr;
        }
        return data_ + size_;
    }

    ReverseIterator rbegin()
    {
        return ReverseIterator(end());
    }

    ReverseIterator rend()
    {
        return ReverseIterator(begin());
    }

    ConstReverseIterator rbegin() const
    {
        return ConstReverseIterator(end());
    }

    ConstReverseIterator rend() const
    {
        return ConstReverseIterator(begin());
    }

    ConstReverseIterator crbegin() const
    {
        return ConstReverseIterator(cend());
    }

    ConstReverseIterator crend() const
    {
        return ConstReverseIterator(cbegin());
    }
};

template <typename T>
bool operator==(const Vector<T> &left, const Vector<T> &right)
{
    if (left.Size() != right.Size())
    {
        return false;
    }
    return std::equal(left.begin(), left.end(), right.begin());
}

template <typename T>
bool operator!=(const Vector<T> &left, const Vector<T> &right)
{
    return !(left == right);
}

template <typename T>
bool operator<(const Vector<T> &left, const Vector<T> &right)
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

template <typename T>
bool operator<=(const Vector<T> &left, const Vector<T> &right)
{
    return !(right < left);
}

template <typename T>
bool operator>(const Vector<T> &left, const Vector<T> &right)
{
    return right < left;
}

template <typename T>
bool operator>=(const Vector<T> &left, const Vector<T> &right)
{
    return !(left < right);
}

#endif