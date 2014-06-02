#include <iostream>

using namespace std;


/**
 * Questão 3
 * @Aluno Sérgio R Siqueira <sergiorsiqueira9@gmail.com>
 */
int main()
{
    float gusAlt = 1.40;
    float julAlt = 1.10;

    int year = 0;

    do
    {
        year++;

        gusAlt = gusAlt + 0.15;
        julAlt = julAlt + 0.30;
    }
    while (gusAlt >= julAlt);

    cout << "Juliano levou " << year << " anos para ultrapassar Gustavo." << endl << endl;
    cout << "Juliano agora tem " << julAlt << "m" << endl;
    cout << "Gustavo agora tem " << gusAlt << "m" << endl;

    return 0;
}
