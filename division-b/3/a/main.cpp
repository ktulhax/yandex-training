#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>

std::unordered_set<int> GetLineNumbers()
{
    std::unordered_set<int> result;
    std::string line;
    std::getline(std::cin, line);
    std::stringstream splitter(line);
    while (!splitter.eof())
    {
        int number;
        splitter >> number;
        result.insert(number);
    }
    return result;
}

int main()
{
    auto firstLineNumbers = GetLineNumbers();
    auto secondLineNumbers = GetLineNumbers();
    size_t interSectionCount = 0;
    for (auto& secondLineNumber : secondLineNumbers)
    {
        if (firstLineNumbers.count(secondLineNumber) != 0)
            ++interSectionCount;
    }
    std::cout << interSectionCount;
    return 0;
}
