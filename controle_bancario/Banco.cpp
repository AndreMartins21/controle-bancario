#include "Banco.hpp"


int QTD_MAX_CONTAS = 20;


Banco::Banco(){
    this->num_contas = 0;
    
    for (int i = 0; i<QTD_MAX_CONTAS; i++){
        this->list_contas[i] = nullptr;
    }
}


ContaBancaria* Banco::criaConta(int id, string cliente){
    ContaBancaria* id_existente = this->pesquisa(id);

    if (id_existente != nullptr){
        // Conta já existente
        return nullptr;
    }

    ContaBancaria* nova_conta = new ContaBancaria(id, cliente);
    
    list_contas[num_contas] = nova_conta;
    num_contas ++;

    // cout << "CRIOU A CONTA! Num de contas: " << num_contas << endl;
    return nova_conta;
}

ContaBancaria* Banco::pesquisa(int id){
    for (int i = 0; i<num_contas; i++){
        if(id == this->list_contas[i]->id) return this->list_contas[i];
    }
    return nullptr;
}

void Banco::listaContas(){
    // cout << "NUM_CONTAS: " << num_contas << endl;
    for (int i = 0; i<num_contas; i++){
        this->list_contas[i]->imprimirConta();
    }
}


// int main(){
//     Banco* banco = new Banco();

//     banco->criaConta(1, "Andrew Martins");
//     banco->criaConta(1, "Jose Maria");
//     banco->criaConta(2, "Jose Maria");
//     banco->criaConta(3, "Cleber");

//     banco->listaContas();
//     // banco->list_contas[0]->imprimirConta();

//     return 0;
// }