#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <cstdint>
#include <stdexcept>

class RationalDivisionByZero : public std::runtime_error
{
public:
    RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {}
};

class Rational
{
    int32_t numerator_ = 0;
    int32_t denominator_ = 1;
    void MakeIncredible();

public:
    Rational();
    ~Rational();
    Rational(int32_t numerator, int32_t denominator);
    Rational(int number); // NOLINT
    int32_t GetNumerator() const;
    int32_t GetDenominator() const;
    void SetNumerator(const int32_t &numerator);
    void SetDenominator(const int32_t &denominator);
    Rational operator+() const;
    Rational operator-() const;
    Rational &operator++();
    Rational &operator--();
    Rational operator++(int);
    Rational operator--(int);
};

Rational operator+(const Rational &left, const Rational &right);
Rational operator-(const Rational &left, const Rational &right);
Rational operator*(const Rational &left, const Rational &right);
Rational operator/(const Rational &left, const Rational &right);
Rational &operator+=(Rational &left, const Rational &right);
Rational &operator-=(Rational &left, const Rational &right);
Rational &operator*=(Rational &left, const Rational &right);
Rational &operator/=(Rational &left, const Rational &right);
bool operator>(const Rational &left, const Rational &right);
bool operator<(const Rational &left, const Rational &right);
bool operator<=(const Rational &left, const Rational &right);
bool operator>=(const Rational &left, const Rational &right);
bool operator==(const Rational &left, const Rational &right);
bool operator!=(const Rational &left, const Rational &right);
std::ostream &operator<<(std::ostream &operation, const Rational &number);
std::istream &operator>>(std::istream &operation, Rational &number);

#endif