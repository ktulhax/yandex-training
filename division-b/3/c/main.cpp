#include <iostream>
#include <sstream>
#include <unordered_set>
#include <algorithm>
#include <vector>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> numbers;
    std::unordered_set<int> moreThanOneTimeNumbers;
    int inNumber = 0;
    while (iss >> inNumber)
    {
        if (moreThanOneTimeNumbers.count(inNumber) != 0)
            continue;
        auto it = std::find(numbers.begin(), numbers.end(), inNumber);
        if (it != numbers.end())
        {
            numbers.erase(it);
            moreThanOneTimeNumbers.insert(inNumber);
            continue;
        }
        numbers.push_back(inNumber);
    }
    for (auto& outNumber : numbers)
        std::cout << outNumber << " ";
    return 0;
}
