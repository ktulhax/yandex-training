#include <iostream>
#include <map>

int main()
{
    std::map<std::string, unsigned> votes;
    std::string participant;
    unsigned countOfVotes = 0;
    while (std::cin >> participant && std::cin >> countOfVotes)
        votes[participant] += countOfVotes;
    for (auto& [p, c] : votes)
        std::cout << p << " " << c << std::endl;
    return 0;
}
