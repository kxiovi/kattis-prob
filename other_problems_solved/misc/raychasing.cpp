#include <bits/stdc++.h>
using namespace std;

int main() {
    double X1 = 0.0, X2 = 0.0, Y1 = 0.0, Y2 = 0.0;
    double Xs = 0.0, Ys = 0.0, Xr = 0.0, Yr = 0.0;
    cin >> X1 >> X2 >> Y1 >> Y2;
    cin >> Xs >> Ys >> Xr >> Yr;
    
    double x_diff = (Xr - Xs);
    double y_diff = (Yr - Ys);

    string hort = (x_diff > 0) ? "right" : "left";
    string vert = (y_diff > 0) ? "top" : "bottom"; 

    if (x_diff == 0) {
        cout << vert << endl;
        return 0;
    } 
    if (y_diff == 0) {
        cout << hort << endl;
        return 0;
    }

    double xWall = (x_diff > 0) ? (X2 - Xs) / x_diff : (X1 - Xs) / x_diff;
    double yWall = (y_diff > 0) ? (Y2 - Ys) / y_diff : (Y1 - Ys) / y_diff;

    if ((std::abs(yWall - xWall)) == 0)  {
        cout << vert << "-" << hort;
    } else 
    if (xWall < yWall) {
        cout << hort;
    } else {
        cout << vert;
    }
}