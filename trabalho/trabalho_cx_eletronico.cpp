/**
 * Caixa Eletrônico
 * \Alunos
 * Sérgio Rafael Siqueira <sergiorsiqueira9@gmail.com>
 * Marlon Luciano da Silva <marlonluciano.silva@gmail.com>
 */

#include <iostream>

using namespace std;

/** \brief Informa ao usuário sua conta e saldo atual
 * \param conta Número da conta do usuário
 * \param saldo Atual saldo do usuário
 * \return void
 */
void saldo(int conta, float saldo)
{
    cout << "A conta " << conta << " contém R$" << saldo << endl;
}

/** \brief Informa ao usuário suas últimas transãções
 * \param conta Número da conta do usuário
 * \param sal1 Saldo atual
 * \param sal2
 * \param sal3
 * \return void
 */
void historico(int conta, float sal1, float sal2, float sal3)
{
    cout << "Últimas 3 transações da conta " << conta << endl
        << "R$" << sal1 << " - saldo atual" << endl
        << "R$" << sal2 << endl
        << "R$" << sal3 << endl;
}

/** \brief Efetua um deposito
 * \param saldo Saldo atual do usuário
 * \param valor Valor que será depositado
 * \return Novo saldo
 */
float deposito(float saldo, float valor)
{
    return saldo + valor;
}

/** \brief Efetua um saque
 * \param saldo
 * \param valor
 * \return Novo saldo
 */
float saque(float saldo, float valor)
{
    saldo = saldo - valor;

    if (saldo < 1)
    {
        cout << "Não é possivel sacar essa quantia." << endl;
        return 0;
    }

    return saldo;
}

int main()
{
    int tmpAcao, // ação que o usuário escolhe executar
        conta, // conta
        conUmNum,
        conDoisNum;

    float
        // vars para histórico de transações da conta um
        conUmSal,
        conUmSal2,
        conUmSal3,

        // vars para histórico das transações da conta dois
        conDoisSal,
        conDoisSal2,
        conDoisSal3,

        // vars para controle de valores temporarios
        tmpValor,
        tmpSaldo,
        tmpConta;

    // declara os valores iniciais das contas
    conUmNum = 001;
    conUmSal = 100.0;
    conUmSal2 = conUmSal3 = 0;

    conDoisNum = 002;
    conDoisSal = 10;
    conDoisSal2 = conDoisSal3 = 0;

    conta = 0;

    // entra em um loop foréva (.. até que o usuário o quebre)
    while (true)
    {
        // solicita a conta do usuário
        if (conta == 0)
        {
            ChangeAccount:
            cout << "Digite o número de sua conta: ";
            cin >> conta;

            if ((conta != conUmNum) and (conta != conDoisNum))
            {
                cout << "Conta inválida!" << endl;
                goto ChangeAccount;
            }

        }

        cout << "[0] Alterar a conta" << endl
            << "[1] Saldo" << endl
            << "[2] Histórico" << endl
            << "[3] Depósito" << endl
            << "[4] Saque" << endl
            << "[5] Transfêrencia" << endl
            << "[6] Encerrar sessão" << endl;

        cin >> tmpAcao;

        switch (tmpAcao)
        {
            case 0:
                goto ChangeAccount;
                break;

            // saldo
            case 1:
                Balance:
                if (conta == conUmNum)
                {
                    tmpValor = conUmSal;
                }
                else
                {
                     tmpValor = conDoisSal;
                }

                saldo(conta, tmpValor);

                break;

            // histórico
            case 2:
                if (conta == conUmNum)
                {
                    historico(conta, conUmSal, conUmSal2, conUmSal3);
                }
                else
                {
                    historico(conta, conDoisSal, conDoisSal2, conDoisSal3);
                }
                break;

            // deposito
            case 3:
                cout << "Digite o valor que deseja depositar: ";
                cin >> tmpValor;

                if (tmpValor > 0)
                {
                    if (conta == conUmNum)
                    {
                        // salva o histórico
                        conUmSal3 = conUmSal2;
                        conUmSal2 = conUmSal;
                        conUmSal  = deposito(conUmSal, tmpValor);
                    }
                    else
                    {

                        conDoisSal3 = conDoisSal2;
                        conDoisSal2 = conDoisSal;
                        conDoisSal  = deposito(conDoisSal, tmpValor);
                    }
                }

                goto Balance;
                break;

            // saque
            case 4:
                cout << "Digite o valor que deseja sacar: ";
                cin >> tmpValor;

                if (tmpValor > 0)
                {
                    if (conta == conUmNum)
                    {
                        tmpValor = saque(conUmSal, tmpValor);
                        // não quemos ninguém sem R$
                        if (tmpValor)
                        {
                            // salva o histórico
                            conUmSal3 = conUmSal2;
                            conUmSal2 = conUmSal;
                            conUmSal  = tmpValor;
                        }
                    }
                    else
                    {
                        tmpValor = saque(conDoisSal, tmpValor);
                        // não quemos ninguém sem R$
                        if (tmpValor)
                        {
                            // salva o histórico
                            conDoisSal3 = conDoisSal2;
                            conDoisSal2 = conDoisSal;
                            conDoisSal  = tmpValor;
                        }
                    }
                }

                goto Balance;
                break;

            // transferência
            case 5:
                cout << "Digite a número da conta de destino: ";
                cin >> tmpConta;


                cout << "Qual valor que seja transferir: ";
                cin >> tmpValor;

                if ((tmpValor > 0) and (tmpConta != conta))
                {
                    // se o destino for a conta 001
                    if (tmpConta == conUmNum)
                    {
                        // atualiza o histórico e deposita o valor
                        conUmSal3 = conUmSal2;
                        conUmSal2 = conUmSal;
                        conUmSal  = deposito(conUmSal, tmpValor);

                        // atualiza o histórica da conta 002 e remove o valor
                        conDoisSal3 = conDoisSal2;
                        conDoisSal2 = conDoisSal;
                        conDoisSal  = saque(conDoisSal, tmpValor);
                    }
                    else
                    {
                        // atualiza o histórica da conta 001 e remove o valor
                        conUmSal3 = conUmSal2;
                        conUmSal2 = conUmSal;
                        conUmSal  = saque(conUmSal, tmpValor);

                        // atualiza o histórico e deposita o valor
                        conDoisSal3 = conDoisSal2;
                        conDoisSal2 = conDoisSal;
                        conDoisSal  = deposito(conDoisSal, tmpValor);
                    }

                    goto Balance;
                }

                break;

            default:
                cout << "Opção inválida." << endl;
        }

        // queba o loop
        if (tmpAcao == 6)
        {
            cout << "Obrigado, volte sempre!!" << endl;
            break;
        }

        // pra deixar mais bunitinho
        cout << endl << "--Escolha uma nova opção--" << endl << endl;
    }

    return 0;
}
