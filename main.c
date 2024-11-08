#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

const int MAX_HOSPEDAGENS = 10;
const int MAX_NOME = 50;

struct Hospedagem {
    char nome[50];
    char cidade[50];
    int quartos;
    int quartos_reservados;
};

struct Hospedagem hospedagens[10];
int contador_hospedagens = 0;

// Função auxiliar para adicionar uma hospedagem
void adicionar_hospedagem(const char *nome, const char *cidade, int quartos, int quartos_reservados) {
    if (contador_hospedagens < MAX_HOSPEDAGENS) {
        strcpy(hospedagens[contador_hospedagens].nome, nome);
        strcpy(hospedagens[contador_hospedagens].cidade, cidade);
        hospedagens[contador_hospedagens].quartos = quartos;
        hospedagens[contador_hospedagens].quartos_reservados = quartos_reservados;
        contador_hospedagens++;
    }
}

// Função para inicializar algumas hospedagens pré-cadastradas
void inicializar_hospedagens() {
    adicionar_hospedagem("Hotel Paraíso", "Rio de Janeiro", 20, 5);
    adicionar_hospedagem("Pousada do Sol", "Salvador", 15, 3);
    adicionar_hospedagem("Alvorada Inn", "São Paulo", 30, 10);
}

void cadastra_hospetagem() {
    if (contador_hospedagens >= MAX_HOSPEDAGENS) {
        printf("Limite de hospedagens atingido!\n");
        return;
    }

    printf("Digite o nome da hospedagem: ");
    getchar();
    fgets(hospedagens[contador_hospedagens].nome, MAX_NOME, stdin);
    hospedagens[contador_hospedagens].nome[strcspn(hospedagens[contador_hospedagens].nome, "\n")] = '\0';

    printf("Digite a cidade da hospedagem: ");
    fgets(hospedagens[contador_hospedagens].cidade, MAX_NOME, stdin);
    hospedagens[contador_hospedagens].cidade[strcspn(hospedagens[contador_hospedagens].cidade, "\n")] = '\0';

    printf("Digite o número de quartos disponíveis: ");
    scanf("%d", &hospedagens[contador_hospedagens].quartos);

    hospedagens[contador_hospedagens].quartos_reservados = 0;
    contador_hospedagens++;

    printf("Hospedagem cadastrada com sucesso!\n");
}

// Função para remover hospedagem
void remover_hospetagem() {
    char nome[MAX_NOME];
    int i, encontrado = 0;

    printf("Digite o nome da hospedagem a ser removida: ");
    getchar();  // Limpa o buffer do teclado
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remover o '\n'

    for (i = 0; i < contador_hospedagens; i++) {
        if (strcmp(hospedagens[i].nome, nome) == 0) {
            encontrado = 1;
            // Move as hospedagens restantes uma posição para cima
            for (int j = i; j < contador_hospedagens - 1; j++) {
                hospedagens[j] = hospedagens[j + 1];
            }
            contador_hospedagens--;
            printf("Hospedagem '%s' removida com sucesso!\n", nome);
            break;
        }
    }

    if (!encontrado) {
        printf("Hospedagem não encontrada!\n");
    }
}

// Função para consultar hospedagens
void consultar_hospetagem() {
    if (contador_hospedagens == 0) {
        printf("Nenhuma hospedagem cadastrada.\n");
        return;
    }

    printf("\n===== HOSPEDAGENS CADASTRADAS =====\n");
    for (int i = 0; i < contador_hospedagens; i++) {
        printf("ID: %d\n", i);  // Exibe o ID (índice do vetor)
        printf("Nome: %s\n", hospedagens[i].nome);
        printf("Cidade: %s\n", hospedagens[i].cidade);
        printf("Quartos Disponíveis: %d\n", hospedagens[i].quartos - hospedagens[i].quartos_reservados);
        printf("Quartos Reservados: %d\n\n", hospedagens[i].quartos_reservados);
    }
}

// Função para o usuário reservar hospedagem
void reservar_hospedagem() {
    int id, quartos_a_reservar;

    printf("Digite o ID da hospedagem que deseja reservar: ");
    scanf("%d", &id);

    if (id < 0 || id >= contador_hospedagens) {
        printf("ID inválido! Tente novamente.\n");
        return;
    }

    // Exibe a hospedagem escolhida e o número de quartos disponíveis
    printf("Você escolheu a hospedagem '%s' localizada em '%s'.\n", hospedagens[id].nome, hospedagens[id].cidade);
    printf("Quartos disponíveis: %d\n", hospedagens[id].quartos - hospedagens[id].quartos_reservados);
    printf("Digite o número de quartos a reservar: ");
    scanf("%d", &quartos_a_reservar);

    if (quartos_a_reservar <= 0) {
        printf("Número de quartos inválido!\n");
        return;
    }

    if (quartos_a_reservar > (hospedagens[id].quartos - hospedagens[id].quartos_reservados)) {
        printf("Não há quartos suficientes disponíveis para reserva.\n");
        return;
    }

    hospedagens[id].quartos_reservados += quartos_a_reservar;
    printf("Reserva de %d quartos realizada com sucesso na hospedagem '%s'.\n", quartos_a_reservar, hospedagens[id].nome);
}

// Função para o usuário cancelar uma reserva
void cancelar_reserva() {
    int id, quartos_a_cancelar;

    printf("Digite o ID da hospedagem onde deseja cancelar a reserva: ");
    scanf("%d", &id);

    if (id < 0 || id >= contador_hospedagens) {
        printf("ID inválido! Tente novamente.\n");
        return;
    }

    printf("Você escolheu a hospedagem '%s'.\n", hospedagens[id].nome);
    printf("Quartos reservados: %d\n", hospedagens[id].quartos_reservados);
    printf("Digite o número de quartos a cancelar: ");
    scanf("%d", &quartos_a_cancelar);

    if (quartos_a_cancelar <= 0 || quartos_a_cancelar > hospedagens[id].quartos_reservados) {
        printf("Número de quartos inválido ou nenhum quarto reservado.\n");
        return;
    }

    hospedagens[id].quartos_reservados -= quartos_a_cancelar;
    printf("Reserva de %d quartos cancelada com sucesso na hospedagem '%s'.\n", quartos_a_cancelar, hospedagens[id].nome);
}

// Função do menu de administração
void administracao() {
    int escolha;
    do {
        printf("===== ADMINISTRAÇÃO =====\n");
        printf("1. Cadastrar Hospedagem\n");
        printf("2. Remover Hospedagem\n");
        printf("3. Consultar Hospedagens\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: 
                cadastra_hospetagem();
                break;
            case 2:
                remover_hospetagem();
                break;
            case 3:
                consultar_hospetagem();
                break;
            case 4:
                printf("Saindo do menu de administração...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 4);
}

// Função do menu do usuário
void usuario() {
    int escolha;
    do {
        printf("===== MENU DO USUÁRIO =====\n");
        printf("1. Reservar Hospedagem\n");
        printf("2. Cancelar Reserva\n");
        printf("3. Consultar Hospedagens\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                consultar_hospetagem();  // Exibe as hospedagens para escolher o ID
                reservar_hospedagem();
                break;
            case 2:
                consultar_hospetagem();  // Exibe as hospedagens para escolher o ID
                cancelar_reserva();
                break;
            case 3:
                consultar_hospetagem();
                break;
            case 4:
                printf("Saindo do menu do usuário...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 4);
}

// Função principal do menu
void menu_principal() {
    int escolha;
    do {
        printf("\n===== BOOKING =====\n");
        printf("1. Administração\n");
        printf("2. Usuário\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                administracao();
                break;
            case 2:
                usuario();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 3);
}

int main() {
    // Inicializa algumas hospedagens antes de iniciar o programa
    inicializar_hospedagens();
    
    // Inicia o menu principal
    menu_principal();
    
    return 0;
}
