#include <iostream>

int main()
{
    size_t N = 0, nSum = 0, nMax = 0, a = 0;
    std::cin >> N;
    for (size_t i = 0; i < N; ++i)
    {
        std::cin >> a;
        nSum += a;
        if (a > nMax)
            nMax = a;
    }
    std::cout << nSum - nMax;
    return 0;
}
