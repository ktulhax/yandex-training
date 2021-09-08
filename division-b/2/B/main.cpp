#include <iostream>
#include <map>

int main()
{
    const int nMaxDistance = 10;
    std::map<int, int> distances;
    int nCurrentType = 0;
    std::optional<int> indexOfLastMarket;
    std::cin >> nCurrentType;
    for (int i = 0; i < 10; std::cin >> nCurrentType, ++i)
    {
        if (nCurrentType == 1)
        {
            if (indexOfLastMarket)
                distances[i] = (i - *indexOfLastMarket);
            else
                distances[i] = nMaxDistance;
        }
        else if (nCurrentType == 2)
        {
            indexOfLastMarket = i;
            for (auto& [nHouseIndex, nDistance] : distances)
            {
                if (i - nHouseIndex < nDistance)
                    nDistance = i - nHouseIndex;
            }
        }
    }
    int nResultMaxDistance = 0;
    for (auto& [_, nDistance] : distances)
        if (nDistance > nResultMaxDistance)
            nResultMaxDistance = nDistance;
    std::cout << nResultMaxDistance;
    return 0;
}
