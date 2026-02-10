#include "rational.hpp"
#include <numeric>

void Rational::MakeIncredible()
{
    if (denominator_ == 0)
    {
        throw RationalDivisionByZero{};
    }
    int32_t d = std::gcd(numerator_, denominator_);
    numerator_ /= d;
    denominator_ /= d;
    if (denominator_ < 0)
    {
        numerator_ = -numerator_;
        denominator_ = -denominator_;
    }
}

Rational::Rational() = default;

Rational::~Rational() = default;

Rational::Rational(int32_t numerator, int32_t denominator)
{
    if (denominator == 0)
    {
        throw RationalDivisionByZero{};
    }
    numerator_ = numerator;
    denominator_ = denominator;
    MakeIncredible();
}

Rational::Rational(int number)
{ // NOLINT
    numerator_ = number;
    denominator_ = 1;
}

int32_t Rational::GetNumerator() const
{
    return numerator_;
}

int32_t Rational::GetDenominator() const
{
    return denominator_;
}

void Rational::SetNumerator(const int32_t &numerator)
{
    numerator_ = numerator;
    MakeIncredible();
}

void Rational::SetDenominator(const int32_t &denominator)
{
    if (denominator == 0)
    {
        throw RationalDivisionByZero{};
    }
    denominator_ = denominator;
    MakeIncredible();
}

Rational Rational::operator+() const
{
    return *this;
}

Rational Rational::operator-() const
{
    return {-numerator_, denominator_};
}

Rational &Rational::operator++()
{
    numerator_ += denominator_;
    MakeIncredible();
    return *this;
}

Rational &Rational::operator--()
{
    numerator_ -= denominator_;
    MakeIncredible();
    return *this;
}

Rational Rational::operator++(int)
{
    Rational temp = *this;
    ++(*this);
    return temp;
}

Rational Rational::operator--(int)
{
    Rational temp = *this;
    --(*this);
    return temp;
}

Rational operator+(const Rational &left, const Rational &right)
{
    int32_t new_num = left.GetNumerator() * right.GetDenominator() + right.GetNumerator() * left.GetDenominator();
    int32_t new_den = left.GetDenominator() * right.GetDenominator();
    return {new_num, new_den};
}

Rational operator-(const Rational &left, const Rational &right)
{
    int32_t new_num = left.GetNumerator() * right.GetDenominator() - right.GetNumerator() * left.GetDenominator();
    int32_t new_den = left.GetDenominator() * right.GetDenominator();
    return {new_num, new_den};
}

Rational operator*(const Rational &left, const Rational &right)
{
    int32_t new_num = left.GetNumerator() * right.GetNumerator();
    int32_t new_den = left.GetDenominator() * right.GetDenominator();
    return {new_num, new_den};
}

Rational operator/(const Rational &left, const Rational &right)
{
    if (right.GetNumerator() == 0)
    {
        throw RationalDivisionByZero{};
    }
    int32_t new_num = left.GetNumerator() * right.GetDenominator();
    int32_t new_den = left.GetDenominator() * right.GetNumerator();
    return {new_num, new_den};
}

Rational &operator+=(Rational &left, const Rational &right)
{
    left = left + right;
    return left;
}

Rational &operator-=(Rational &left, const Rational &right)
{
    left = left - right;
    return left;
}

Rational &operator*=(Rational &left, const Rational &right)
{
    left = left * right;
    return left;
}

Rational &operator/=(Rational &left, const Rational &right)
{
    left = left / right;
    return left;
}

bool operator>(const Rational &left, const Rational &right)
{
    return (left.GetNumerator() * right.GetDenominator()) > (right.GetNumerator() * left.GetDenominator());
}

bool operator<(const Rational &left, const Rational &right)
{
    return (left.GetNumerator() * right.GetDenominator()) < (right.GetNumerator() * left.GetDenominator());
}

bool operator<=(const Rational &left, const Rational &right)
{
    return !(left > right);
}

bool operator>=(const Rational &left, const Rational &right)
{
    return !(left < right);
}

bool operator==(const Rational &left, const Rational &right)
{
    return left.GetNumerator() == right.GetNumerator() && left.GetDenominator() == right.GetDenominator();
}

bool operator!=(const Rational &left, const Rational &right)
{
    return !(left == right);
}

std::ostream &operator<<(std::ostream &operation, const Rational &number)
{
    if (number.GetDenominator() == 1)
    {
        operation << number.GetNumerator();
    }
    else
    {
        operation << number.GetNumerator() << "/" << number.GetDenominator();
    }
    return operation;
}

std::istream &operator>>(std::istream &operation, Rational &number)
{
    int32_t numerator = 0;
    int32_t denominator = 1;
    operation >> numerator;
    if (operation.peek() == '/')
    {
        char slash = '/';
        operation >> slash >> denominator;
    }
    number = Rational(numerator, denominator);
    return operation;
}