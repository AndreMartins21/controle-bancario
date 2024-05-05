#include <iostream>

using namespace std;


struct ContaBancaria{
    int id;
    string cliente;
    float saldo;

    ContaBancaria(int id, string cliente);

    void depositar(float valor);

    void saque(float valor);

    void transferirPix(ContaBancaria* outra_conta, float valor);

    void imprimirConta();
};