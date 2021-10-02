#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int number = 0;
    std::unordered_set<int> prevNumbers;
    while (iss >> number)
    {
        std::cout << (prevNumbers.count(number) != 0 ? "YES" : "NO") << std::endl;
        prevNumbers.insert(number);
    }
    return 0;
}
