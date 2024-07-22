
#include <iostream>
#include <iomanip>
using namespace std;

double f(double x) {
    return (x * x * x * x) - 13;
}

int main() {
    double Xl = 1.5, Xr = 2, X = 0;
    //1e-6 หรือ 0.000001
    while ((Xr - Xl) / 2 > 1e-6)
    {
        double fXl = f(Xl);
        double fXr = f(Xr);
        X = ((Xl * fXr) -  (Xr * fXl)) / (fXr - fXl);
        double fX = f(X);
        if(fX == 0) {
            break;
        }
        if(fX * fXr < 0) {
            Xl = X;
        } else {
            Xr = X;
        }
    }
    cout << "XM root: " << setprecision(7) << X << "\n";
    
    return 0;

}