#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <string>

bool IsSuspectNumberMatched(const std::set<char>& sortedSymbolsFromWitnessNumber, const std::set<char>& sortedSymbolsFromTestSuspectNumber)
{
    std::set<char> intersectionOfSymbols;
    std::set_intersection(sortedSymbolsFromWitnessNumber.begin(), sortedSymbolsFromWitnessNumber.end()
            , sortedSymbolsFromTestSuspectNumber.begin(), sortedSymbolsFromTestSuspectNumber.end()
            , std::inserter(intersectionOfSymbols, intersectionOfSymbols.end()));
    return intersectionOfSymbols.size() == sortedSymbolsFromWitnessNumber.size();
}

int GetCountOfMatches(const std::vector<std::set<char>>& sortedSymbolsFromWitnessNumbers
        , const std::string& testSuspectNumber)
{
    std::set<char> sortedSymbolsFromTestSuspectNumber(testSuspectNumber.begin(), testSuspectNumber.end());
    int nCountOfMatches = 0;
    for (auto& sortedSymbolsFromWitnessNumber : sortedSymbolsFromWitnessNumbers)
    {
        if (IsSuspectNumberMatched(sortedSymbolsFromWitnessNumber, sortedSymbolsFromTestSuspectNumber))
            ++nCountOfMatches;
    }
    return nCountOfMatches;
}

int main()
{
    int m = 0;
    std::cin >> m;
    std::vector<std::set<char>> sortedSymbolsFromWitnessNumbers(m);
    for (int i = 0; i < m; ++i)
    {
        std::string witnessNumber;
        std::cin >> witnessNumber;
        sortedSymbolsFromWitnessNumbers[i] = std::set<char>(witnessNumber.begin(), witnessNumber.end());
    }
    int n = 0;
    std::cin >> n;
    std::list<std::string> resultSuspectNumbers;
    int resultCountOfMatches = 0;
    for (int i = 0; i < n; ++i)
    {
        std::string testSuspectNumber;
        std::cin >> testSuspectNumber;
        auto countOfMatches = GetCountOfMatches(sortedSymbolsFromWitnessNumbers, testSuspectNumber);
        if (countOfMatches > resultCountOfMatches)
        {
            resultSuspectNumbers.assign({testSuspectNumber});
            resultCountOfMatches = countOfMatches;
        }
        else if (countOfMatches == resultCountOfMatches)
            resultSuspectNumbers.push_back(testSuspectNumber);
    }
    for (auto& resultSuspectNumber : resultSuspectNumbers)
        std::cout << resultSuspectNumber << std::endl;
    return 0;
}
