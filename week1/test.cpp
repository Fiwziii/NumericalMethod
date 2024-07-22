#include<iostream>
#include<iomanip>
using namespace std;

double f(double x){
    return (x * x * x * x)-13;
}

void bisection(double xl , double xr){
    double xm = 0;
    double error = 0.000001;
    while(xr - xl >= error){
        
        xm = ((xl + xr) / 2);

        if(f(xm) == 0){
            break;
        }else if(f(xm) * f(xr) < 0){
            xl = xm;
        }else{
            xr = xm;
        }
    }
    // cout << "XL = " << setprecision(7) << xl << endl;
    // cout << "XR = " << setprecision(7) << xr << endl;
    cout << "XM = " << setprecision(7) << xm << endl;
}

int main(){
    double xl = 1.5 , xr = 2;
    bisection(xl,xr);
    return 0;
}