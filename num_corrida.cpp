#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int randNum,
        userNum,
        attempts;

    srand(time(NULL));
    randNum = rand() % 100;

    cout << "Vamos tentar a sorte! Digite seu número!" << endl;

    tryAgain:
    cin >> userNum;
    attempts++;

    if (userNum > randNum)
    {
        cout << "Não foi dessa vez! Tente novamente com um número menor!" << endl;
        goto tryAgain;

    }
    else if (userNum < randNum)
    {
        cout << "Não foi dessa vez! Tente novamente com um número maior!" << endl;
        goto tryAgain;
    }
    else
    {
        cout << "Yeahhh você acertou, na " << attempts << "a tentativa!" << endl;
    }

    return 0;
}
