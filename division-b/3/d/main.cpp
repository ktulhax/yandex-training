#include <iostream>
#include <set>
#include <sstream>
#include <algorithm>
#include <string>

std::set<int> GetLineNumbers(const std::string& line)
{
    std::set<int> result;
    std::istringstream splitter(line);
    while (!splitter.eof())
    {
        int number;
        splitter >> number;
        result.insert(number);
    }
    return result;
}

std::string Trim(const std::string& str)
{
    auto nFirst = str.find_first_not_of(' '), nLast = str.find_last_not_of(' ');
    if (nFirst == std::string::npos || nLast == std::string::npos)
        return "";
    return str.substr(nFirst, nLast + 1 - nFirst);
}

std::string GetTrimmedLineFromCin()
{
    std::string line;
    std::getline(std::cin, line);
    return Trim(line);
}

int main()
{
    std::string line = GetTrimmedLineFromCin();
    int maxNumber = std::stoi(line);
    std::optional<std::set<int>> yesNumbers;
    std::set<int> noNumbers;
    while (true)
    {
        line = GetTrimmedLineFromCin();
        if (line == "HELP")
            break;
        auto lineNumbers = GetLineNumbers(line);
        line = GetTrimmedLineFromCin();
        if (line == "YES")
        {
            if (!yesNumbers)
            {
                yesNumbers.emplace(lineNumbers);
            }
            else
            {
                std::set<int> intersectionResult;
                std::set_intersection(yesNumbers->begin(), yesNumbers->end(), lineNumbers.begin(), lineNumbers.end()
                        , std::inserter(intersectionResult, intersectionResult.end()));
                yesNumbers = intersectionResult;
            }
        }
        else
            noNumbers.insert(lineNumbers.begin(), lineNumbers.end());
    }
    if (yesNumbers)
    {
        std::set<int> resultNumbers;
        std::set_difference(yesNumbers->begin(), yesNumbers->end(), noNumbers.begin(), noNumbers.end()
                , std::inserter(resultNumbers, resultNumbers.end()));
        for (auto& resultNumber : resultNumbers)
            std::cout << resultNumber << " ";
    }
    else
    {
        bool lPrintedEarlier = false;
        for (int testNumber = 1; testNumber <= maxNumber; ++testNumber)
        {
            if (noNumbers.count(testNumber) == 0)
                std::cout << testNumber << " ";
        }
    }
    return 0;
}
