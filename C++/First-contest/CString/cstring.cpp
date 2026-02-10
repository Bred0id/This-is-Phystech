#include "cstring.hpp"

size_t Strlen(const char *str)
{
    size_t i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int Strcmp(const char *first, const char *second)
{
    size_t i = 0;
    while (first[i] != '\0' && second[i] != '\0' && first[i] == second[i])
    {
        i++;
    }
    if (first[i] > second[i])
    {
        return 1;
    }
    if (first[i] < second[i])
    {
        return -1;
    }
    return 0;
}

int Strncmp(const char *first, const char *second, size_t count)
{
    size_t i = 0;
    if (count == 0)
    {
        return 0;
    }
    while (first[i] != '\0' && second[i] != '\0' && first[i] == second[i] && i < count - 1)
    {
        i++;
    }
    if (first[i] > second[i])
    {
        return 1;
    }
    if (first[i] < second[i])
    {
        return -1;
    }
    return 0;
}

const char *Strchr(const char *str, char symbol)
{
    size_t i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == symbol)
        {
            return str + i;
        }
        i++;
    }
    if (str[i] == symbol)
    {
        return str + i;
    }
    return nullptr;
}

const char *Strrchr(const char *str, char symbol)
{
    size_t i = Strlen(str);
    while (i > 0)
    {
        if (str[i] == symbol)
        {
            return str + i;
        }
        i--;
    }
    if (str[i] == symbol)
    {
        return str + i;
    }
    return nullptr;
}

size_t Strspn(const char *dest, const char *src)
{
    size_t i = 0;
    while (dest[i] != '\0')
    {
        size_t j = 0;
        while (src[j] != '\0' && dest[i] != src[j])
        {
            j++;
        }
        if (src[j] == '\0')
        {
            return i;
        }
        i++;
    }
    return i;
}

size_t Strcspn(const char *dest, const char *src)
{
    size_t i = 0;
    while (dest[i] != '\0')
    {
        size_t j = 0;
        while (src[j] != '\0')
        {
            if (dest[i] == src[j])
            {
                return i;
            }
            j++;
        }
        i++;
    }
    return i;
}

const char *Strpbrk(const char *dest, const char *breakset)
{
    size_t i = 0;
    while (dest[i] != '\0')
    {
        size_t j = 0;
        while (breakset[j] != '\0' && dest[i] != breakset[j])
        {
            j++;
        }
        if (breakset[j] != '\0')
        {
            return dest + i;
        }
        i++;
    }
    return nullptr;
}

const char *Strstr(const char *str, const char *pattern)
{
    if (*pattern == '\0')
    {
        return str;
    }
    size_t i = 0;
    while (str[i] != '\0')
    {
        size_t j = 0;
        while (pattern[j] != '\0' && str[i + j] != '\0' && str[i + j] == pattern[j])
        {
            j++;
        }
        if (pattern[j] == '\0')
        {
            return str + i;
        }
        i++;
    }
    return nullptr;
}

char *Strcpy(char *dest, const char *src)
{
    size_t i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *Strncpy(char *dest, const char *src, size_t count)
{
    size_t i = 0;
    while (src[i] != '\0' && i < count)
    {
        dest[i] = src[i];
        i++;
    }
    while (i < count)
    {
        dest[i] = '\0';
        i++;
    }
    return dest;
}

char *Strcat(char *dest, const char *src)
{
    size_t i = 0;
    size_t j = Strlen(dest);
    while (src[i] != '\0')
    {
        dest[i + j] = src[i];
        i++;
    }
    dest[i + j] = '\0';
    return dest;
}

char *Strncat(char *dest, const char *src, size_t count)
{
    size_t i = 0;
    size_t j = Strlen(dest);
    while (src[i] != '\0' && i < count)
    {
        dest[i + j] = src[i];
        i++;
    }
    dest[i + j] = '\0';
    return dest;
}