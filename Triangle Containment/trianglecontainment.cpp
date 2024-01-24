#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define trav(a, x) for(auto &a : x)
typedef long long ll;
typedef vector<string> vs;
typedef vector<int> vi;

struct Point {
    ll x, y;
     Point(ll x, ll y) : x(x), y(y) {}
};

struct Value {
    Point point;
    ll weight;
    ll total;
    Value(const Point point, ll weight, ll total) : point(point), weight(weight), total(total) {}
};

double triangle_area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool is_point_inside_triangle(int n, Point big_point, Point small_point) {
    int x1 = big_point.x;
    int y1 = big_point.y;
    int x2 = small_point.x;
    int y2 = small_point.y;

    double main_triangle_area = triangle_area(0, 0, n, 0, x1, y1);
    double sub_triangle1_area = triangle_area(0, 0, n, 0, x2, y2);
    double sub_triangle2_area = triangle_area(0, 0, x1, y1, x2, y2);
    double sub_triangle3_area = triangle_area(n, 0, x1, y1, x2, y2);

    return main_triangle_area == sub_triangle1_area + sub_triangle2_area + sub_triangle3_area;
}

struct greater_than_y
{
    inline bool operator() (const Value& struct1, const Value& struct2)
    {
        return (struct1.point.y > struct2.point.y);
    }
};

int main() {
    int n, right_x_value;
    cin >> n >> right_x_value;

    Point left = Point(0, 0);
    Point right = Point(right_x_value, 0);

    vector<Value> values;
    rep(i, 0, n) {
        ll x, y, weight;
        cin >> x >> y >> weight;
        values.push_back(Value(Point(x, y), weight, 0));
    }

    vector<Value> copy = values;
    // std::sort(values.begin(), values.end(), greater_than_y());

    rep(i, 0, values.size()) {
        ll total = 0;
        Value current = values[i];
        rep(j, 0, values.size()) { // i + 1
            Value next = values[j];
            if (next.point.y > current.point.y || 
                i == j ||
                current.point.y > 0 && next.point.y < 0 ||
                current.point.y < 0 && next.point.y > 0) {
                continue;
            }
            if (is_point_inside_triangle(right_x_value, current.point, next.point)) {
                total += next.weight;
            }
        }
        values[i].total = total;
        cout << total << "\n";
    }

    // for (const Value &value : values) {
    //     cout << value.total << "\n";
    // }

    return 0;
}
