#include <iostream>
#include <vector>

int main()
{
    int nL, nK;
    std::cin >> nL >> nK;
    const int nLeftLegLimit = nL % 2 == 0 ? nL / 2 - 1 : nL / 2;
    int nLeftLeg = 0, nRightLeg = 0, nCurrentLeg = 0;
    for (int i = 0; i < nK; ++i)
    {
        std::cin >> nCurrentLeg;
        if (nCurrentLeg < nLeftLegLimit)
        {
            nLeftLeg = nCurrentLeg;
            continue;
        }
        if (nCurrentLeg > nLeftLegLimit)
        {
            nRightLeg = nCurrentLeg;
            break;
        }
        nLeftLeg = nCurrentLeg;
        if (nL % 2 == 1)
        {
            nRightLeg = nCurrentLeg;
        }
        else
        {
            std::cin >> nRightLeg;
            ++i;
        }
        break;
    }
    if (nLeftLeg == nRightLeg)
        std::cout << nLeftLeg;
    else
        std::cout << nLeftLeg << " " << nRightLeg;
    return 0;
}
