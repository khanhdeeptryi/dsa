#include <iostream>
#include <cmath>

int main()
{
    double a;
    int n;
    std::cin >> a >> n;

    double step = 1.0 / n;
    double rounded = std::round(a / step) * step;

    std::cout.precision(10);
    std::cout << rounded << std::endl;
    return 0;
}
