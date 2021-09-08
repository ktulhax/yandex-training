#include <iostream>

int main()
{
    long N;
    std::cin >> N;
    long nSchoolIndex = N % 2 == 0 ? N / 2 : N / 2 + 1;
    long nSchoolCoordinate = 0;
    for (long i = 1; i <= N; ++i)
    {
        long input;
        std::cin >> input;
        if (i == nSchoolIndex)
            nSchoolCoordinate = input;
    }
    std::cout << nSchoolCoordinate;
    return 0;
}
