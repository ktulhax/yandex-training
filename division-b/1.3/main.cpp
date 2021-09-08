#include <iostream>

bool IsUnambiguously(int x, int y, int z)
{
    return x > 12 || y > 12 || x == y;
}

int main()
{
    int x, y, z;
    std::cin >> x >> y >> z;
    std::cout << IsUnambiguously(x, y, z) << std::endl;
    return 0;
}
