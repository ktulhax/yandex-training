#include <iostream>
#include <array>

struct Point
{
    int x = 0;
    int y = 0;
};

std::pair<int, int> GetKB(int x1, int y1, int x2, int y2)
{
    int k = (y2 - y1) / (x2 - x1);
    int b = (x2 * y1 - x1 * y2) / (x2 - x1);
    return {k, b};
}

bool IsParallel(const Point& a, const Point& b, const Point& c, const Point& d)
{
    auto [k1, b1] = GetKB(a.x, a.y, b.x, b.y);
    auto [k2, b2] = GetKB(c.x, c.y, d.x, d.y);
    return k1 == k2 && b1 != b2;
}

bool IsParallelogram(const std::array<Point, 4>& points)
{
    return IsParallel(points[0], points[1], points[2], points[3]) && IsParallel(points[0], points[2], points[1], points[3])
            || IsParallel(points[0], points[1], points[2], points[3]) && IsParallel(points[0], points[3], points[1], points[2])
            || IsParallel(points[0], points[3], points[1], points[2]) && IsParallel(points[0], points[2], points[1], points[3]);
}

int main()
{
    std::array<Point, 4> points;
    int N = 0;
    std::cin >> N;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> points[0].x >> points[0].y
                >> points[1].x >> points[1].y
                >> points[2].x >> points[2].y
                >> points[3].x >> points[3].y;
        std::cout << (IsParallelogram(points) ? "YES" : "NO") << std::endl;
    }
    return 0;
}
