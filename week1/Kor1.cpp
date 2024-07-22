#include <iostream>
#include <iomanip>

using namespace std;

double f(double x) {
    return (43 * (x)) - 180;
}

int main()
{
    for (int i = 0; i <= 10; i++)
    {
        double y = f(i);
        if(y > 0) {
            for (double h = i-1; h < i; h += 0.000001)
            {
                y = f(h);
                if(y == 0) {
                    cout << "range: [" << i -1 << "," << i << "]\n";
                    cout << "f("  << setprecision(7) << h << ") = " << y << "\n";
                    break;
                }
            }
            break;
        }
    }
    return 0;
}