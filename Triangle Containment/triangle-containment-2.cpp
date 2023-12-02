#include <iostream>
#include <vector>

using namespace std;

struct Point {
    long long x, y;
    Point(long long x, long long y) : x(x), y(y) {}
};

struct Value {
    Point point;
    long long weight;
    long long total;
    Value(const Point point, long long weight, long long total) : point(point), weight(weight), total(total) {}
};

bool is_inside_triangle(const Point& p, const Point& p1, const Point& p2, const Point& p3) {
    // Check if point p is inside the triangle formed by p1, p2, and p3 using cross product method.
    long long d1 = (p1.x - p.x) * (p2.y - p.y) - (p2.x - p.x) * (p1.y - p.y);
    long long d2 = (p2.x - p.x) * (p3.y - p.y) - (p3.x - p.x) * (p2.y - p.y);
    long long d3 = (p3.x - p.x) * (p1.y - p.y) - (p1.x - p.x) * (p3.y - p.y);

    return (d1 >= 0 && d2 >= 0 && d3 >= 0) || (d1 <= 0 && d2 <= 0 && d3 <= 0);
}

int main() {
    int n, right_x_value;
    cin >> n >> right_x_value;

    Point left = Point(0, 0);
    Point right = Point(right_x_value, 0);

    vector<Value> values;
    for (int i = 0; i < n; i++) {
        long long x, y, weight;
        cin >> x >> y >> weight;
        values.push_back(Value(Point(x, y), weight, 0));
    }

    for (int i = 0; i < n; i++) {
        long long total = 0;
        Value current = values[i];
        for (int j = 0; j < n; j++) {
            Value next = values[j];
            if (next.point.y > current.point.y ||
                i == j ||
                (current.point.y > 0 && next.point.y < 0) ||
                (current.point.y < 0 && next.point.y > 0)) {
                continue;
            }
            if (is_inside_triangle(right, left, current.point, next.point)) {
                total += next.weight;
            }
        }
        values[i].total = total;
        cout << total << "\n";
    }

    return 0;
}
