#include <iostream>
#include <string>
using namespace std;

//criar sistema de emprestimos
//criar sistema para excluir um cliente
//adicionar se a parcela foi paga e junto a data de pagamento
//adicionar data de vencimento junto com a criação da parcela
//adicionar checagem de limites para seleção de clientes e outras partes
//corrigir alguns detalhes
// teste


struct emprestimo {

    bool parcela_paga;
    string data_vencimento =  "nao cadastrado";
    string data_pagamento = "nao cadastrado";

};

struct cliente {

    string nome = "cliente nao cadastrado";
    string cpf = "cliente nao cadastrado";
    string endereco = "cliente nao cadastrado";
    string data_nascimento = "cliente nao cadastrado"; 
    string data_emprestimo = "cliente nao cadastrado";
    float valortotal_emprestimo = 0;
    int parcelas_mensais = 0;
    int parcelas = 0;
    emprestimo emprestimo;
};

int count_clientes = 0;
const int max_num_of_clientes = 10;
cliente clientes[max_num_of_clientes];

void adicionar_cliente(){

    if(count_clientes > max_num_of_clientes){

      cout << "Nao foi possivel adicionar mais clientes" << endl;  
    }

    else {

    cout << endl;
    cout << "Digite o nome do novo cliente: " << endl;
    cin.ignore();
    getline(cin, clientes[count_clientes].nome);
    
    cout << "Digite o CPF do novo cliente: " << endl;
    getline(cin, clientes[count_clientes].cpf);
    
    cout << "Digite o endereco do novo cliente: " << endl;
    getline(cin, clientes[count_clientes].endereco);
    
    cout << "Digite a data de nascimento do novo cliente: " << endl;
    getline(cin, clientes[count_clientes].data_nascimento);

    cout << endl;
     
    cout << "O cliente " << clientes[count_clientes].nome << " foi armazenado no indice " << count_clientes  << endl;
    cout << "Cadastro do cliente foi concluido com sucesso." << endl << endl;

    count_clientes++;

    }
    
}

int main(){

int escolha_menu, index_clientes, menu_editar, aceite_parcelas, parcelas;
float valor_emprestado;
string data_vencimento_parcela;

while (escolha_menu != 8){

cout << endl;
cout << " 1) Cadastrar cliente" << endl;
cout << " 2) Visualizar as informacoes de um cliente" << endl;
cout << " 3) Editar as informacoes de um cliente" << endl;
cout << " 4) Cadastrar parcela paga" << endl;
cout << " 5) Cadastrar emprestimo" << endl;
cout << " 6) Gerenciar parcelas" << endl;
cout << " 7) Excluir cliente" << endl;
cout << " 8) Sair" << endl;
cout << endl;
cin >> escolha_menu;

switch(escolha_menu){

case 1:

adicionar_cliente();

break;

case 2:
    
cout << endl;
cout << "Selecione o indice do cliente a ser visualizado: " << endl;
cin >> index_clientes;

cout << endl;
cout << "O nome cadastrado eh: " << clientes[index_clientes].nome << endl;
cout << "O CPF cadastrado eh: " << clientes[index_clientes].cpf << endl;
cout << "O endereco cadastrado eh: " << clientes[index_clientes].endereco << endl;
cout << "A data de nascimento cadastrada eh: " << clientes[index_clientes].data_nascimento << endl;
cout << "O valor total de emprestimo eh de: " << clientes[index_clientes].valortotal_emprestimo << endl;
cout << "O parcelamento do emprestimo ficou em " << clientes[index_clientes].parcelas << "x de R$ " << clientes[index_clientes].parcelas_mensais << endl;
cout << clientes[index_clientes].emprestimo.data_vencimento << endl;
cout << endl;
    
break;

case 3:

cout << endl;
cout << "Selecione o indice do cliente que deseja editar os dados: " << endl;
cin >> index_clientes;
cout << "Cliente selecionado: " << clientes[index_clientes].nome << endl;
cout << endl;

    while(menu_editar != 5){
    cout << " 1) Editar nome" << endl;
    cout << " 2) Editar CPF" << endl;
    cout << " 3) Editar endereco" << endl;
    cout << " 4) Editar data de nascimento" << endl;
    cout << " 5) Voltar para o menu principal" << endl;
    cin >> menu_editar;
    cout << endl;
    
    switch(menu_editar){

      case 1:

      cout << "Edite o nome do cliente: " << endl;
      cin.ignore();
      getline(cin, clientes[index_clientes].nome);
      cout << endl;
      break;
    
      case 2:

      cout << "Edite o CPF do cliente: " << endl;
      cin.ignore();
      getline(cin, clientes[index_clientes].cpf);
      cout << endl;
      break;
    
      case 3:

      cout << "Edite o endereco do cliente: " << endl;
      cin.ignore();
      getline(cin, clientes[index_clientes].endereco);
      cout << endl;
      break;

      case 4:
    
      cout << "Edite a data de nascimento do cliente: " << endl;
      cin.ignore();
      getline(cin, clientes[index_clientes].data_nascimento);
      cout << endl;
      break;

      }
   }

break;

case 4:




break;

case 5:

cout << endl;
cout << "Selecione o indice do cliente que deseja cadastrar um emprestimo: " << endl << endl;
cin >> index_clientes;
cout << "Cliente selecionado: " << clientes[index_clientes].nome << endl;
cout << endl << endl;

cout << "Insira o valor do emprestimo" << endl;
cin >> valor_emprestado;

clientes[index_clientes].valortotal_emprestimo = valor_emprestado;
cout << "Valor de emprestimo cadastrado com sucesso para o cliente " << clientes[index_clientes].nome << endl << endl;

cout << "Deseja parcelar o valor do emprestimo?" << endl;
cout << "1) - Sim" << endl;
cout << "2) - Nao" << endl;
cin >> aceite_parcelas;

if(aceite_parcelas == 1){

      

    cout << "Digite a quantidade de vezes que deseja parcelar o emprestimo" << endl;
    cin >>  clientes[index_clientes].parcelas;
    if (clientes[index_clientes].parcelas > 12) {

        clientes[index_clientes].parcelas = 0;
        clientes[index_clientes].valortotal_emprestimo = 0;

        cout << "Nao eh permitido realizar mais que 12 parcelas em um emprestimo" << endl;
    
    }
      else {

         clientes[index_clientes].parcelas_mensais = (valor_emprestado /  clientes[index_clientes].parcelas);
         cout << endl;
         cout << "Insira a data de vencimento da parcela: " << endl;
         cin >> clientes[index_clientes].emprestimo.data_vencimento;
         cout << "O emprestimo foi dividido em " << clientes[index_clientes].parcelas << "x com sucesso" << " e com data de vencimento para " << 
         clientes[index_clientes].emprestimo.data_vencimento << endl;
        
    }
}

break;

case 6:

cout << endl;
cout << "Selecione o indice do cliente que deseja gerenciar as parcelas: " << endl;
cin >> index_clientes;
cout << "Cliente selecionado: " << clientes[index_clientes].nome << endl;
cout << endl;

    while(menu_editar != 6){
    cout << " 1) Gerenciar quantidade de parcelas" << endl;
    cout << " 2) Verificar se a parcela foi paga" << endl;
    cout << " 3) Valor atual da parcela" << endl;
    cout << " 4) Visualizar data(s) de pagamento do parcela" << endl;
    cout << " 5) Visualizar data(s) de vencimento da parcela" << endl;
    cout << " 6) Voltar para o menu principal" << endl;
    cin >> menu_editar;
    cout << endl;

       switch (menu_editar){

        case 1: 

        cout << "Quantidade de parcelas cadastradas: " << clientes[index_clientes].parcelas << endl;

        break;

        case 2: 

        if(clientes[index_clientes].emprestimo.parcela_paga == true){

            cout << "A parcela foi paga" << endl;
        }
         else {

            cout << "A parcela nao foi paga" << endl;

         }

         break;

         case 3:

         cout << "O valor atual da parcela eh de: R$" << clientes[index_clientes].parcelas_mensais << endl;

         break;

         case 4:

        if(clientes[index_clientes].emprestimo.parcela_paga == true){

            cout << "A(s) data(s) de pagamento da parcela(s): " << clientes[index_clientes].emprestimo.data_pagamento << endl;
        }
        else {
            cout << "Parcela ainda nao foi paga" << endl;
        }
                   
        break;

        case 5:

        cout << "A(s) data(s) de vencimento da parcela(s): " << clientes[index_clientes].emprestimo.data_vencimento << endl;

        break;
    }
      }


break;

case 7:


break;

case 8:

cout << endl;
cout << "Tenha um bom dia !" << endl;
cout << endl;

break;

}

}

return 0;

}































