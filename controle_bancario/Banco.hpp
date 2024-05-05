#include <iostream>
#include "ContaBancaria.hpp"

using namespace std;


struct Banco{
    int num_contas;
    ContaBancaria* list_contas[20];

    Banco();

    ContaBancaria* criaConta(int id, string cliente);
    
    ContaBancaria* pesquisa(int id);

    void listaContas();
};