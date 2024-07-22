
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f(float x,float n,float xm) {
    return pow(xm,x) - n;
}

int main() {
    float Xl = 0, Xr = 0, Xm = 0;
    int n = 0, x = 0;
    cin >> n >> x;
    cin >> Xl >> Xr;
    if (n < 2 || x < 2 || n > 2000000 || x > 2000000) {
        return 0;
    }
    if (Xl > Xr || Xl < 0 || Xr < 0 || Xl > 1000000 || Xr > 1000000) {
        return 0;
    }
    while (fabs(f(x, n, Xm)) > 0.000001)
    {
        Xm = (Xl + Xr) / 2;
        if(f(x,n,Xm) == 0) {
            break;
        }
        float fXm = f(x,n,Xm);
        float fXr = f(x,n,Xr);    
        if(fXm * fXr < 0) {
            Xl = Xm;
        } else {
            Xr = Xm;
        }
    }
    cout << setprecision(5) << Xm << "\n";
    return 0;

}