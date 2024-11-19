#include <stdio.h>
#include <string.h>

void login();
void esperarTecla();
void menuinicial();
void menuprincipal();
void menuUsuario();
void menuEmpresa();
void menuEmpresa_cadastro();
void menuUsuario_Reserva();
void cadastrarEmpresa();
void cadastrarAcomodacao();
void cadastrarUsuario();
void listarAcomodacoes();
void realizarReserva();
void limparTelaSimulada();
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Consome até o '\n'
}

typedef struct {
    int id;
    int id_cliente;
    int id_empresa;
    int id_local;
    int dias;
}Registro_locacao;


typedef struct {
    int id;
    char nome[50];
    char uf[50];
    float diaria;
    char cidade[50];
    int disponivel;
}Locacao;

typedef struct {
    char nome[50];
    char email[50];
    char cpf[12];
    char login[50];
    char senha[50];
    int id;
}Usuario;


typedef struct {
    int id;
    int n_locais;
    char nome[50];
    char senha[50];
    char email[50];
    char login[50];
    Locacao locacao[50];
}Empresa ;

Empresa matrizempresa[50];
Usuario matrizusuario[50];
Registro_locacao matrizlocacao[50];







int n_usuarios=1;
int n_locais=1;
int n_empresas=1;
int n_registros_locacoes=1;


int main()
{
 
     
     while(1)
     {
         
     
     menuinicial();
     }
}


void cadastrarEmpresa() {
    matrizempresa[n_empresas-1].id=n_empresas;
    printf("Digite o nome da empresa:");
    fgets(matrizempresa[n_empresas-1].nome,50,stdin);
    fflush(stdin);

    printf("Digite o e-mail:");
    fgets(matrizempresa[n_empresas-1].email,50,stdin);
    fflush(stdin);

    printf("Digite o nome login:");
    fgets(matrizempresa[n_empresas-1].login,50,stdin);
    fflush(stdin);
    
    printf("Digite o nome a senha:");
    fgets(matrizempresa[n_empresas-1].senha,50,stdin);
    fflush(stdin);
    matrizempresa[n_empresas-1].n_locais=0;
    
    
    printf("Cadastro completo\nEmpresa:%sID:%i",matrizempresa[n_empresas-1].nome,matrizempresa[n_empresas-1].id);
    printf("\n");
    n_empresas++;
    menuEmpresa();
}
void cadastrarAcomodacao(int idem,int n_local) {
    char resposta[4];
    int n_local1=n_local;
    int decisao;
    do{
    limparBuffer();
    printf("\nDigite o nome da acomodacao:");
    fgets(matrizempresa[idem-1].locacao[n_local1].nome,50,stdin);
    fflush(stdin);

    printf("\nDigite o UF:");
    fgets(matrizempresa[idem-1].locacao[n_local1].uf,4,stdin);
    fflush(stdin);
    
    printf("\nDigite a cidade:");
    fgets(matrizempresa[idem-1].locacao[n_local1].cidade,50,stdin);
    fflush(stdin);
    
    printf("\nDigite o valor da diária:");
    scanf("%2f",&matrizempresa[idem-1].locacao[n_local1].diaria);
    fflush(stdin);
    
    
    
    matrizempresa[idem-1].locacao[n_local1].disponivel=0;
    
    printf("cadastro concluído!\nAcomodacao:%s\n",matrizempresa[idem-1].locacao[n_local1].nome);
       matrizempresa[idem-1].locacao[n_local1].id=n_local1+1;
    n_local1++;
    matrizempresa[idem-1].n_locais=n_local1;
    
    printf("N_locais %i\n",matrizempresa[idem-1].n_locais);
    printf("Deseja realizar mais um cadastro?:");
    fgets(resposta,4,stdin);
    decisao=(strcmp(resposta,"sim"));
    printf("\n");
    if(decisao)
    {
        menuEmpresa();
    }
    else
    {
        continue;
    }
    }while(1);
    
}

void cadastrarUsuario() {
    
    matrizusuario[n_usuarios-1].id=n_usuarios;

    printf("Digite o nome do usuário(Máximo de 49 caracteres): ");
    fgets(matrizusuario[n_usuarios-1].nome,50,stdin);
    fflush(stdin);

    printf("Digite o e-mail do usuário(Máximo de 49 caracteres): ");
    fgets(matrizusuario[n_usuarios-1].email,50,stdin);
    fflush(stdin);
    
    printf("Digite o CPF(sem símbolos)(Máximo de 49 caracteres): ");
    fgets(matrizusuario[n_usuarios-1].cpf,11,stdin);
    fflush(stdin);
    
    printf("Digite Login(Máximo de 49 caracteres): ");
    fgets(matrizusuario[n_usuarios-1].login,50,stdin);
    fflush(stdin);
    
    printf("Digite senha(Máximo de 49 caracteres): ");
    fgets(matrizusuario[n_usuarios-1].senha,50,stdin);
    fflush(stdin);
    
    printf("cadastrado com sucesso!\nUsuário:%sId:%i\n", matrizusuario[n_usuarios-1].nome,matrizusuario[n_usuarios-1].id);
    n_usuarios++;
    
    menuUsuario();

    
}

void listarAcomodacoes() {
    int i=0;
    int j=0;
    while (matrizempresa[i].nome[0] !='\0') {
        j=0;
        printf("Possui as seguintes acomodações a Empresa %s\n",matrizempresa[i].nome);
        while (matrizempresa[i].locacao[j].nome[0] !='\0'){
        printf("local:%s",matrizempresa[i].locacao[j].nome);
        printf("UF:%s",matrizempresa[i].locacao[j].uf);
        printf("Cidade:%s",matrizempresa[i].locacao[j].cidade);
        printf("diaria:%f\n",matrizempresa[i].locacao[j].diaria);
        printf("ID local:%i\n",matrizempresa[i].locacao[j].id);
        
        matrizempresa[i].locacao[j].disponivel==0 ?printf("disponivel\n\n"):printf("Ocupado\n\n");
        j++;
        }
        i++;
    }
    menuEmpresa();
    
}

void realizarReserva(int idcliente,int idempresa, int idlocal,int q_dias) {
    
   
    
    matrizlocacao[n_registros_locacoes-1].id=n_registros_locacoes;
    matrizlocacao[n_registros_locacoes-1].id_cliente=idcliente;
    matrizlocacao[n_registros_locacoes-1].id_empresa= idempresa;
    matrizlocacao[n_registros_locacoes-1].id_local=idlocal;
    matrizlocacao[n_registros_locacoes-1].dias=q_dias;
    matrizempresa[idempresa-1].locacao[idlocal-1].disponivel=1;
    printf("Parabéns usuário %s, você acaba de alugar local:%s da empresa %s por %i dias\n",matrizusuario[idcliente-1].nome,matrizempresa[idempresa-1].locacao[idlocal-1].nome,matrizempresa[idempresa-1].nome,q_dias);
    
    menuUsuario_Reserva();
    }

 
    

    void menuinicial()
    {
    printf("========================================\n");
    printf("        Bem-vindo ao Booking.com        \n");
    printf("========================================\n");
    printf("         Sistema de Reserva Online      \n");
    

    menuprincipal();
        
    }
    void menuprincipal() {
    int decisao;
    printf("Sistema de Reserva Booking.com\n");
    printf("1. Área do usuário\n");
    printf("2. Área Empresas\n");
    printf("3. Sair\n");
    printf("Escolha uma opção:");
    scanf("%i",&decisao);
    limparBuffer();
        
    switch(decisao)
    {
        case 1:
            menuUsuario();
        break;
        case 2:
            menuEmpresa();
        break;
        case 3:
            printf("Obrigado pelo acesso\n");
            menuinicial();
        break;
        default:
        printf("\nEntrada nao compatível com as opções\n");
        menuprincipal();
        break;
    
    }
    
    }
    void menuUsuario() {
        int decisao;
        printf("Sistema de Reserva Booking.com\n");
        printf("1. Cadastrar Usuário\n");
        printf("2. Área Usuário\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%i",&decisao);
         limparBuffer();
        switch(decisao)
    {
        case 1:
            cadastrarUsuario();
        break;
        case 2:
        menuUsuario_Reserva();
        break;
        case 3:
            printf("Obrigado pelo acesso\n");
        break;
        default:
        printf("\nEntrada nao compatível com as opções\n");
        menuUsuario();
        break;
    
    }
}
    void menuEmpresa() {
        int decisao;
        int id;
        int qlocal;
        printf("Sistema de Reserva Booking.com\n");
        printf("1. Cadastrar Empresa\n");
        printf("2. Cadastrar Acomodações para Empresa\n");
        printf("3.Listar Acomodações\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        
        scanf("%i",&decisao);
         limparBuffer();
        switch(decisao)
    {
        case 1:
            cadastrarEmpresa();
        break;
        case 2:
        
            printf("Informe ID válido:");
            scanf("%i",&id);
            qlocal=matrizempresa[id-1].n_locais;
            cadastrarAcomodacao(id,qlocal);
        break;
        case 3:
            listarAcomodacoes();
        break;
        
        case 4:
            printf("\nObrigado pelo acesso\n");
            menuprincipal();
        break;
        default:
            printf("\nEntrada nao compatível com as opções\n");
            menuEmpresa();
        break;
    
    }
    
    
}
    
    void menuUsuario_Reserva() {
        int decisao;
        printf("Sistema de Reserva Booking.com\n");
        printf("1. Realizar Reserva\n");
        printf("2. Sair\n");
        printf("Escolha uma opção:\n");
        scanf("%i", &decisao);
         limparBuffer();
            switch(decisao)
    {
        case 1:
        int id_empresa,id_local,id_cliente,dias;
        printf("Informe ID do cliente:");
        scanf("%i",&id_cliente);
        printf("Informe ID da Empresa:");
        scanf("%i",&id_empresa);
        printf("Informe ID do Local:");
        scanf("%i",&id_local);
             if(matrizempresa[id_empresa-1].locacao[id_local-1].disponivel==1)
            {
                printf("Local já reservado\n");
                menuUsuario_Reserva();
            }
        printf("Informe quantidade de dias:");
        scanf("%i",&dias);
             realizarReserva(id_cliente,id_empresa,id_local,dias);
        break;
        case 2:
            menuUsuario();
        break;
        default:
            printf("\nEntrada nao compatível com as opções\n");
            menuUsuario_Reserva();
        break;
    }
    
    }
