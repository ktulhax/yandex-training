#include <iostream>

int GetStationsCount(int N, int i, int j)
{
    auto jiDifference = std::abs(j-i);
    return jiDifference <= N / 2 ? jiDifference - 1 : N - jiDifference - 1;
}

int main()
{
    int N, i, j;
    std::cin >> N >> i >> j;
    std::cout << GetStationsCount(N, i, j) << std::endl;
    return 0;
}
