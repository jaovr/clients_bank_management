// Nome: João Victor Rocha. RA: 2177268

#include <iostream>
#include <string>
using namespace std;

struct emprestimo {

    bool parcela_paga;
    string data_vencimento = "nao cadastrado";
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
    bool emprestimo_ativo = false;
    emprestimo emprestimo;
};

int count_clientes = 0;
const int max_num_of_clientes = 10;
cliente clientes[max_num_of_clientes];

int main(){

int escolha_menu = 0, index_clientes = 0, menu_editar = 0, aceite_parcelas = 0, parcelas = 0, sub_menu_editar = 0;
float valor_emprestado = 0.0;


 while(escolha_menu != 9) {

cout << endl;
cout << " 1) Cadastrar cliente" << endl;
cout << " 2) Recadastro de cliente" << endl;
cout << " 3) Visualizar as informacoes de um cliente" << endl;
cout << " 4) Editar as informacoes de um cliente" << endl;
cout << " 5) Cadastrar parcela paga" << endl;
cout << " 6) Cadastrar emprestimo" << endl;
cout << " 7) Gerenciar parcelas" << endl;
cout << " 8) Excluir cliente" << endl;
cout << " 9) Sair" << endl;
cout << endl;
cin >> escolha_menu;    

switch(escolha_menu){

case 1:

    if(count_clientes < max_num_of_clientes){

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


    } else {

       cout << "Nao foi possivel adicionar mais clientes" << endl;

    }

break;

case 2:

    cout << endl;
    cout << "Digite o numero do indice que esta disponivel para utilizacao: " << endl << endl;
    cin >> index_clientes;
    cout << "Digite o nome do novo cliente: " << endl;
    cin.ignore();
    getline(cin, clientes[index_clientes].nome);
    
    cout << "Digite o CPF do novo cliente: " << endl;
    getline(cin, clientes[index_clientes].cpf);
    
    cout << "Digite o endereco do novo cliente: " << endl;
    getline(cin, clientes[index_clientes].endereco);
    
    cout << "Digite a data de nascimento do novo cliente: " << endl;
    getline(cin, clientes[index_clientes].data_nascimento);

    cout << endl;
    cout << "O cliente " << clientes[count_clientes].nome << " foi armazenado no indice " << count_clientes  << endl;
    cout << "Cadastro do cliente foi concluido com sucesso." << endl << endl;

break;

case 3:
    
cout << endl;
cout << "Selecione o indice do cliente a ser visualizado: " << endl << endl;
cin >> index_clientes;

cout << endl;
cout << "O nome cadastrado eh: " << clientes[index_clientes].nome << endl;
cout << "O CPF cadastrado eh: " << clientes[index_clientes].cpf << endl;
cout << "O endereco cadastrado eh: " << clientes[index_clientes].endereco << endl;
cout << "A data de nascimento cadastrada eh: " << clientes[index_clientes].data_nascimento << endl;
cout << "O valor total de emprestimo eh de: R$ " << clientes[index_clientes].valortotal_emprestimo << endl;
cout << "O parcelamento do emprestimo ficou em " << clientes[index_clientes].parcelas << "x de R$ " << clientes[index_clientes].parcelas_mensais << endl;
cout << "A data de vencimento da parcela eh no dia: " << clientes[index_clientes].emprestimo.data_vencimento << endl;
cout << endl;
    
break;

case 4:

cout << endl;
cout << "Selecione o indice do cliente que deseja editar os dados: " << endl << endl;
cin >> index_clientes;
cout << "Cliente selecionado: " << clientes[index_clientes].nome << endl;
cout << endl;

    while(menu_editar != 5){
    cout << " 1) Editar nome" << endl;
    cout << " 2) Editar CPF" << endl;
    cout << " 3) Editar endereco" << endl;
    cout << " 4) Editar data de nascimento" << endl;
    cout << " 5) Voltar para o menu principal" << endl << endl;
    cin >> menu_editar;
    cout << endl << endl;
    
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

case 5:

cout << endl;
cout << "Selecione o indice do cliente que deseja confirmar o pagamento da parcela: " << endl << endl;
cin >> index_clientes;
cout << "Cliente selecionado: " << clientes[index_clientes].nome << endl;
cout << endl;

    while(sub_menu_editar != 3){
    cout << " 1) Cadastrar parcela paga" << endl;
    cout << " 2) Cadastrar data de vencimento da proxima parcela" << endl;
    cout << " 3) Voltar para o menu principal" << endl;
    cin >> sub_menu_editar;
    cout << endl;

       switch(sub_menu_editar){

        case 1:
    
        if(clientes[index_clientes].parcelas == 0){
            
            cout << "O cliente pagou todas as parcelas" << endl;
            clientes[index_clientes].emprestimo.data_vencimento = "Todas as parcelas foram pagas";
            clientes[index_clientes].emprestimo.parcela_paga = true;
            clientes[index_clientes].emprestimo_ativo = false;

        } else if (clientes[index_clientes].parcelas > 0) {

            clientes[index_clientes].parcelas -= 1;
            clientes[index_clientes].emprestimo.parcela_paga = true;
            cout << "Digite a data de pagamento desta parcela" << endl;
            cin >> clientes[index_clientes].emprestimo.data_pagamento;
            clientes[index_clientes].emprestimo.data_vencimento == "Parcela paga, por favor adicione uma nova data";
        
          }

        break;

        case 2:

        if(clientes[index_clientes].parcelas == 0){
           
           clientes[index_clientes].emprestimo.data_pagamento = "Todas as parcelas foram pagas";
           cout << "O cliente pagou todas as parcelas" << endl;

        } else if (clientes[index_clientes].parcelas > 0) {

            clientes[index_clientes].emprestimo.parcela_paga = false;
            cout << "Digite a data de vencimento da proxima parcela" << endl;
            cin >> clientes[index_clientes].emprestimo.data_vencimento;

          }

        break;

       }
    }

break;

case 6:

cout << endl;
cout << "Selecione o indice do cliente que deseja cadastrar um emprestimo: " << endl << endl;
cin >> index_clientes;

 if(clientes[index_clientes].emprestimo_ativo == false){

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
            clientes[index_clientes].emprestimo_ativo = true;

          cout << "Nao eh permitido realizar mais que 12 parcelas em um emprestimo" << endl;
    
        }
          else {

         clientes[index_clientes].parcelas_mensais = (valor_emprestado /  clientes[index_clientes].parcelas);
         cout << endl;
         cout << "Insira a data de vencimento da parcela: " << endl;
         cin >> clientes[index_clientes].emprestimo.data_vencimento;
         cout << "O emprestimo foi dividido em " << clientes[index_clientes].parcelas << "x com sucesso" << " e com data de vencimento da primeira parcela para " << 
         clientes[index_clientes].emprestimo.data_vencimento << endl;
        
        }
    }  
       } else {

              cout << "Cliente possui emprestimo ativo" << endl;
        }

break;

case 7:

cout << endl;
cout << "Selecione o indice do(a) cliente que deseja gerenciar a(s) parcela(s): " << endl << endl;
cin >> index_clientes;
cout << "Cliente selecionado: " << clientes[index_clientes].nome << endl;
cout << endl;

    while(sub_menu_editar != 6){
    cout << " 1) Visualizar a quantidade de parcelas" << endl;
    cout << " 2) Verificar se a parcela foi paga" << endl;
    cout << " 3) Valor atual da parcela" << endl;
    cout << " 4) Visualizar data(s) de pagamento do parcela" << endl;
    cout << " 5) Visualizar data(s) de vencimento da parcela" << endl;
    cout << " 6) Voltar para o menu principal" << endl;
    cin >> sub_menu_editar;
    cout << endl;

       switch (sub_menu_editar){

        case 1: 

        cout << "Quantidade de parcelas cadastradas: " << clientes[index_clientes].parcelas << endl;

        break;

        case 2: 

        if(clientes[index_clientes].emprestimo.parcela_paga == true){

            clientes[index_clientes].emprestimo.parcela_paga = false;

            cout << "A(s) parcela(s) foi(foram) paga(s)" << endl;

        }
         else {

            cout << "A(s) parcelas(s) nao foi(foram) paga(s)" << endl;

         }

         break;

         case 3:
         
         if(clientes[index_clientes].parcelas == 0){

           clientes[index_clientes].parcelas_mensais = 0;
           cout << "O valor atual da(s) parcela(s) eh de: R$" << clientes[index_clientes].parcelas_mensais << endl;

         }
         else {

            cout << "O valor atual das parcela(s) eh de: R$" << clientes[index_clientes].parcelas_mensais << endl;

         }
         
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

case 8:

cout << endl;
cout << "Selecione o indice do(a) cliente a ser deletado(a): " << endl << endl;
cin >> index_clientes;

cout << endl;
cout << "Cliente: " << clientes[index_clientes].nome << " deletado(a) com sucesso !" << endl;
cout << "O indice " << index_clientes << " esta pronto para ser reutilizado" << endl;
cout << "Se deseja cadastrar um novo cliente neste indice, digite 2 no menu principal" << endl;

 clientes[index_clientes].nome = "cliente nao cadastrado";
 clientes[index_clientes].cpf = "cliente nao cadastrado";
 clientes[index_clientes].endereco = "cliente nao cadastrado";
 clientes[index_clientes].data_nascimento = "cliente nao cadastrado";
 clientes[index_clientes].valortotal_emprestimo = 0;
 clientes[index_clientes].parcelas = 0;
 clientes[index_clientes].parcelas_mensais = 0;
 clientes[index_clientes].emprestimo.data_vencimento =  "nao cadastrado";
 clientes[index_clientes].emprestimo.data_pagamento =  "nao cadastrado";
 clientes[index_clientes].emprestimo_ativo = false;

 cout << endl;

break;

case 9:

cout << endl;
cout << "Tenha um bom dia !" << endl;
cout << endl;

break;

}

} 

return 0;

}































