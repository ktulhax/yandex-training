#include <iostream>

std::pair<int, int> GetIJ(const std::string& sInputString)
{
    int nCenter = int(sInputString.size() / 2);
    return sInputString.size() % 2 == 0 ? std::pair(nCenter - 1, nCenter) : std::pair(nCenter - 1, nCenter + 1);
}

int main()
{
    std::string sInputString;
    std::cin >> sInputString;
    size_t nResult = 0;
    for (auto [i, j] = GetIJ(sInputString); i >= 0 && j < sInputString.size(); --i, ++j)
        if (sInputString[i] != sInputString[j])
            ++nResult;
    std::cout << nResult;
    return 0;
}
