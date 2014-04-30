#include <iostream>

using namespace std;

int main()
{
    int t1, r, tn, n = 1;

    cout << "Digite o primeiro termo: ";
    cin >> t1;

    cout << "Digite a razao: ";
    cin >> r;

    while (n <= 5)
    {
        tn = t1 + ( (n-1) * r);
        cout << "T" << n << " = " << tn << endl;
        n = n + 1;
    }

    return 0;
}
