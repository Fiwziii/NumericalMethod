
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x,double n,double xm) {
    return pow(xm,x) - n;
}

int main() {
    double Xl = 0, Xr = 0, X ;
    int n = 0, x = 0;
    cin >> n >> x;
    cin >> Xl >> Xr;
    if(n < 2 || x < 2 || n > 2000000 || x > 2000000) {
        return 0;
    }
    if (Xl > Xr || Xl < 0 || Xr < 0 || Xl > 1000000 || Xr > 1000000)
    {
        return 0;
    }
    
    while (fabs(f(x, n, X)) > 0.000001)
    {
        double fXl = f(x,n,Xl);
        double fXr = f(x,n,Xr);
        X = ((Xl * fXr )- (Xr * fXl)) / (fXr - fXl);
        double fX = f(x,n,X);
        if(X == 0) {
            break;
        }
        if (fX * fXr < 0) {
            Xl = X;
        } else {
            Xr = X;
        }
    }
    cout << setprecision(5) << X << "\n";
    return 0;

}