#include <iostream>

int main()
{
    unsigned nElement = 0, nMax = 0, nMaxCount = 0;
    for (std::cin >> nElement; nElement != 0; std::cin >> nElement)
    {
        if (nElement > nMax)
        {
            nMax = nElement;
            nMaxCount = 1;
        }
        else if (nElement == nMax)
        {
            nMaxCount++;
        }
    }
    std::cout << nMaxCount;
    return 0;
}
