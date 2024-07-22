
#include <iostream>
#include <iomanip>
using namespace std;

double f(double x) {
    return (x * x * x * x) - 13;
}

int main() {
    double Xl = 1.5, Xr = 2, Xm = 0;
    //1e-6 หรือ 0.000001
    while ((Xr - Xl) / 2 > 1e-6)
    {
        Xm = (Xl + Xr) / 2;
        if(f(Xm) == 0) {
            break;
        }
        double fXm = f(Xm);
        double fXr = f(Xr);
        if(fXm * fXr < 0) {
            Xl = Xm;
        } else {
            Xr = Xm;
        }
    }
    cout << "XM root: " << setprecision(7) << Xm << "\n";
    
    return 0;

}