#include <iostream>

using namespace std;

int main()
{
    int year;

    backAgain:
    
    cout << "Digite um ano: ";
    cin >> year;

    if (year == 0)
    {
        goto backAgain;
    }

    if (((year % 4) == 0) && ((year % 100) != 0) || ((year % 400) == 0))
    {
        cout << "O ano " << year << " é bissexto" << endl;
    }
    else
    {
        cout << "O ano " << year << " não é bissexto" << endl;
    }

    return 0;
}
