#include <stdio.h>

void cadastra_hospetagem(){
    
}

void remover_hospetagem(){
 
}

consultar_hospetagem(){
    
}


void administracao(){
    int escolha;
    
    do {
        printf("===== ADMINISTRAÇÂO ===== \n");
        printf("1. Cadastra Hotel \n");
        printf("2. Remover Hotel \n");
        printf("3. Consultar Hotel \n");
        printf("4. Sair \n");
        scanf("%d", &escolha);
        
        switch(escolha){
            case 1: 
                cadastra_hospetagem();
                break;
            case 2:
                remover_hospetagem();
                break;
            case 3: 
                consultar_hospetagem();
                break;
        }
        
    }while (escolha != 4);
    
}


void usuario(){
    
}

void menu_principal(){
    int escolha;

    do
    {
        printf("===== BOOKING ===== \n");
        printf("1. Administração \n");
        printf("2. Usuario \n");
        printf("4. Sair \n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            administracao();
            break;
        case 2:
            usuario();
            break;
        case 3: 
            consultar_hospetagem();
            break;
            
        }
    } while (&escolha != 4);
}

int main() {
    menu_principal();
    return 0;
}