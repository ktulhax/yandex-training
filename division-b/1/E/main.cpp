#include <iostream>
#include <cmath>

int GetResult(int d, int xX, int yX)
{
    double x = double(d) * double(xX) / double (xX + yX);
    double y = double(d) * double(yX) / double (xX + yX);
    if (xX >= 0 && yX >= 0 && xX <= x && yX <= y)
        return 0;
    double aDistance = std::sqrt(xX*xX + yX*yX);
    double bDistance = std::sqrt((xX - d)*(xX - d) + yX*yX);
    double cDistance = std::sqrt(xX*xX + (yX - d)*(yX - d));
    if (aDistance <= bDistance && aDistance <= cDistance)
        return 1;
    if (bDistance <= aDistance && bDistance <= cDistance)
        return 2;
    return 3;
}

int main()
{
    int d, xX, yX;
    std::cin >> d >> xX >> yX;
    std::cout << GetResult(d, xX, yX);
    return 0;
}
