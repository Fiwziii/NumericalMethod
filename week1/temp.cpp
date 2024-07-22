#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x, double n, double value) {
    return pow(x, n) - value;
}
int main() {
    float x, n, xl, xr,x1;
    cin >> x >> n;
    cin >> xl >> xr;
    while (true) {
        x1 = (xl * f(xr, n, x) - xr * f(xl, n, x)) / (f(xr, n, x) - f(xl, n, x));
        if (fabs(f(x1, n, x)) < 1e-5) {
            break; 
        }
        if (f(xl, n, x) * f(x1, n, x) < 0) {
            xr = x1;
        } else {
            xl = x1;
        }
    }
    cout << setprecision(5) << x1 << endl;

    return 0;
}
