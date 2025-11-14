//
// Created by SpaceShipStar星飞船 on 25-11-10.
//
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    double x1, y1, x2, y2, x3, y3;


    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;


    double side1 = distance(x1, y1, x2, y2);
    double side2 = distance(x2, y2, x3, y3);
    double side3 = distance(x1, y1, x3, y3);


    double zhouchang = side1 + side2 + side3;

    cout << fixed << setprecision(2) << zhouchang << endl;

    return 0;
}
//
// Created by SpaceShipStar星飞船 on 25-11-10.
//
