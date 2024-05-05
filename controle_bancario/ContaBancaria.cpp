#include "ContaBancaria.hpp"
#include <iomanip>


using namespace std;


ContaBancaria::ContaBancaria(int new_id, string new_cliente){
    id = new_id;
    cliente = new_cliente;
    saldo = 0.00;
}

void ContaBancaria::depositar(float valor){
    this->saldo += valor;
}

void ContaBancaria::saque(float valor){
    this->saldo -= valor;
}

void ContaBancaria::transferirPix(ContaBancaria* outra_conta, float valor){
    this->saque(valor);
    outra_conta->depositar(valor);
}

void ContaBancaria::imprimirConta(){
    cout << this->id << " " << this->cliente << " " << std::fixed << std::setprecision(2 ) << this->saldo << endl;
}

// int main(){
//     ContaBancaria* conta1 = new ContaBancaria(1, "Andrew Martins");
//     ContaBancaria* conta2 = new ContaBancaria(2, "Clodoveu");

//     conta1->depositar(100);
//     conta1->saque(80);

//     conta2->depositar(50);

//     conta1->transferirPix(conta2, 100);

//     conta1->imprimirConta();
//     conta2->imprimirConta();
//     // cout << "Conta1 depois (pix): " << conta1->saldo << endl;
//     // cout << "Conta2 depois (pix): " << conta2->saldo << endl;
// }