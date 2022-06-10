#include <iostream>

using namespace std;

int sum(int l, int r)
{
    return l+r;
}

double sum(double l, double r)
{
    return l+r;
}

int main()
{
    cout << "sum(1, 2): " << sum(1, 2) << endl;
    cout << "sum(1.55, 2.5666): " << sum(1.55, 2.5666) << endl;
    return 0;
}
