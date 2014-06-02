#include <iostream>

using namespace std;

/**
 * Questão 2
 * @Aluno Sérgio R Siqueira <sergiorsiqueira9@gmail.com>
 */
int main()
{
    int n;

    for (int tent = 1; tent <= 10; tent++)
    {
        tryAgain:
        cout << "Digite um valor: ";
        cin >> n;

        // Válida o valor do usuário
        if (n < 1)
        {
            cout << "Digite um valor inteiro e maior que 1" << endl;
            goto tryAgain;
        }

        // Multiplica de 1~n
        for (int i = 1; i <= n; i++)
        {
            cout << i << "x" << n << "=" << i * n << endl;
        }
        cout << endl;
    }

    return 0;
}
