#include <iostream>

using namespace std;

int main()
{
    int userNum;
    bool numPrime;

    cout << "Vamos lá! Digite um número e irei dizer se ele é primo." << endl;

    tryAgain:
    numPrime = true;
    cin >> userNum;

    for (int i = 2; i < userNum; i++)
    {
        if (userNum % i == 0)
        {
            numPrime = false;
            break;
        }
    }

    if (userNum > 0)
    {
        if (numPrime)
        {
            cout << "O número " << userNum << " é primo!" << endl;
        }
        else
        {
            cout << "O número " << userNum << " não é primo!" << endl;
        }

        goto tryAgain;
    }

    return 0;
}
