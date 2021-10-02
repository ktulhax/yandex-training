#include <iostream>
#include <unordered_map>
#include <set>
#include <map>

int main()
{
    std::string inWord;
    std::unordered_map<std::string, unsigned> mapOfWords;
    while (std::cin >> inWord)
        mapOfWords[inWord]++;
    std::map<unsigned, std::set<std::string>, std::greater<>> wordsSortedByCount;
    for (auto& [word, wordCount] : mapOfWords)
        wordsSortedByCount[wordCount].insert(word);
    for (auto& [_, words] : wordsSortedByCount)
    {
        for (auto& word : words)
            std::cout << word << std::endl;
    }
    return 0;
}
