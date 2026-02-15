#include <iomanip>
#include <iostream>

const int cOst = 10;
const long double cLeft = -4000;
const long double cRight = 4000;
const long double cEps = 1e-10;

long double Answer(int a, int b, int c, int d)
{
    long double l = cLeft;
    long double r = cRight;
    long double x = l;
    while (r - l >= cEps)
    {
        x = (l + r) / 2;
        long double value = a * x * x * x + b * x * x + c * x + d;
        if (a > 0)
        {
            if (value < 0)
            {
                l = x;
            }
            else
            {
                r = x;
            }
        }
        else
        {
            if (value < 0)
            {
                r = x;
            }
            else
            {
                l = x;
            }
        }
    }
    return x;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    std::cin >> a >> b >> c >> d;
    std::cout << std::fixed << std::setprecision(cOst);
    std::cout << Answer(a, b, c, d) << "\n";
}