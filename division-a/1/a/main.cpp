#include <iostream>

std::string SolveEquation(int a, int b, int c, int d)
{
    if (a == 0)
        return b == 0 ? "INF" : "NO";
    if (b % a != 0)
        return "NO";
    auto x = - b / a;
    if (c * x + d == 0)
        return "NO";
    return std::to_string(x);
}

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << SolveEquation(a, b, c, d);
    return 0;
}
