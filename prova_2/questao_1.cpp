#include <iostream>

using namespace std;

/**
 * Quest�o 1
 * @Aluno S�rgio R Siqueira <sergiorsiqueira9@gmail.com>
 */
int main()
{
    int m;

    float fact;
    int soma;
    int divide;

    while (true)
    {
        cout << "Digite um valor: ";
        cin >> m;

        if ((m % 2) == 0)
        {
            divide = 0; // Reseta a vari�vel

            for (int i = 2; i <= m; i++)
            {
                if ((m % i) == 0)
                {
                    divide++;
                    cout << m << "/" << i << "=" << m / i << endl;
                }
            }

            cout << "O valor " << m << " foi dividido " << divide << "x" << endl;
        }
        else
        {
            if (m < 12)
            {

                /**
                 * timeout
                 * acabou o tempo! n�o fiz xD
                 */
                fact = 0; // Reseta a vari�vel

                for (int i = 1; i <= m; i++)
                {
                }

            }
            else
            {
                soma = 0; // Reseta a vari�vel

                for (int i = 1; i <= m; i++)
                {
                    soma += i;
                }

                cout << "Soma dos valores: " << soma << endl;
            }
        }

        // V�lida o valor do usu�rio, se for negativo, finaliza
        if (m < 0)
        {
            break;
        }
    }

    return 0;
}
