#include "Banco.hpp"
#include <sstream>
#include <functional>
#include <map>


struct Input{
    char tipo;
    int id, id_dest;
    string nome;
    float valor;
};


void read_input(Input &input){
    string line_input;
    getline(cin, line_input);

    istringstream iss(line_input);
    
    iss >> input.tipo;

    switch (input.tipo){
        case 'C':
            iss >> input.id;
            iss >> input.nome;
            break;
        case 'D':
            iss >> input.id;
            iss >> input.valor;
            break;
        case 'S':
            iss >> input.id;
            iss >> input.valor;
            break;
        case 'P':
            iss >> input.id;
            iss >> input.id_dest;
            iss >> input.valor;
            break;
        default:
            break;
    }
}

class ControleBancario{
    private:
        Input input;
        Banco* banco;

    public:
        ControleBancario(){
            this->banco = new Banco();
        }

        void run(Input input_){
            this->input = input_;

            map<char, function<void()>> map_funcoes = {
                {'C', [this](){ return criar_conta(); }},
                {'D', [this](){ return depositar(); }},
                {'S', [this](){ return saque(); }},
                {'P', [this](){ return pix(); }},
                {'I', [this](){ return informacoes(); }}
            };

            if (map_funcoes.find(input.tipo) != map_funcoes.end()) {
                map_funcoes[input.tipo]();
            } else {
                cout << "Tipo '"<< input.tipo << "' inválido!" << endl;
            } 
        }

        void criar_conta(){
            ContaBancaria* conta = banco->criaConta(input.id, input.nome);
            
            if (conta == nullptr) cout << "ERRO: conta repetida" << endl;
            else cout << "conta criada" << endl;
        }

        void depositar(){
            ContaBancaria* conta = banco->pesquisa(input.id);

            if (conta==nullptr) cout<< "ERRO: conta inexistente" << endl;
            else{
                conta->depositar(input.valor);
                cout << "deposito efetuado" << endl;
            }
        }

        void saque(){
            ContaBancaria* conta = banco->pesquisa(input.id);
            
            if (conta==nullptr) cout<< "ERRO: conta inexistente" << endl;
            else{
                conta->saque(input.valor);
                cout << "saque efetuado" << endl;
            }
        }

        void pix(){
            ContaBancaria* conta_origem = banco->pesquisa(input.id);
            ContaBancaria* conta_destino = banco->pesquisa(input.id_dest);

            if (conta_origem==nullptr || conta_destino==nullptr) cout<< "ERRO: conta inexistente" << endl;
            else{
                conta_origem->transferirPix(conta_destino, input.valor);        
                cout << "pix efetuado" << endl;
            }
        }

        void informacoes(){
            banco->listaContas();
        }
};


int main(){
    Input input; 
    ControleBancario* controle_bancario = new ControleBancario();

    while (true){
        read_input(input);

        if (input.tipo == 'T'){
            break;
        }

        controle_bancario->run(input);
    }

    return 0;
}