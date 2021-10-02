#include <iostream>
#include <map>
#include <cstdint>

int main()
{
    int n;
    std::cin >> n;
    std::map<int64_t, int64_t> result;
    for (int i = 0; i < n; ++i)
    {
        int64_t a, d;
        std::cin >> d >> a;
        result[d] += a;
    }
    for (auto& [d, a] : result)
        std::cout << d << " " << a << std::endl;
    return 0;
}
