#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

double polygonPerimeter(const vector<Point>& pts) {
    double perimeter = 0;
    int n = pts.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        perimeter += hypot(pts[j].x - pts[i].x, pts[j].y - pts[i].y);
    }
    return perimeter;
}

double polygonArea(const vector<Point>& pts) {
    double area = 0;
    int n = pts.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += pts[i].x * pts[j].y - pts[j].x * pts[i].y;
    }
    return fabs(area) / 2.0;
}

bool isValidPolygon(const vector<Point>& pts) {
    return pts.size() >= 3;
}

int main() {
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;

    if (!isValidPolygon(pts)) {
        cout << "Not a valid polygon";
        return 0;
    }

    cout << "Perimeter: " << polygonPerimeter(pts)
         << "\nArea: " << polygonArea(pts);
    return 0;
}
