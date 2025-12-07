#include <stdio.h>

// Criando uma estrutura para representar um jogo
struct Game{
    char name[50];
    char genre[30];
    int year;
};

#define MAX 5
struct Game games[MAX]; // Array para armazenar os jogos
int qtdGames = 0; // Variável para controlar os indices do array

int main(){
    return 0;
}

// Função para adiconar um novo jogo
void insertGame(struct Game games[], char name[], char genre[], int year){
    if(qtdGames < MAX){
        printf("Digite o nome do jogo: ");
        scanf("%s", games[qtdGames].name);
        printf("Digite o gênero do jogo: ");
        scanf("%s", games[qtdGames].genre);
        printf("Digite o ano de lançamento do jogo: ");
        scanf("%d", &games[qtdGames].year);
        qtdGames++;
        printf("Jogo adicionado com sucesso!\n");
    } else {
        printf("Capacidade máxima de jogos atingida!\n");
    }
}

// Função para listar todos os jogos
void listGames(struct Game games[]){
    if(qtdGames == 0){
        printf("Nenhum jogo cadastrado!\n");
    } else {
        for(int i = 0; i < qtdGames; i++){
            printf("Jogo %d:\n", i + 1);
            printf("Nome: %s\n", games[i].name);
            printf("Gênero: %s\n", games[i].genre);
            printf("Ano de lançamento: %d\n", games[i].year);
            printf("-----------------------\n");
        }
    }
}

//Função para buscar um jogo de usando a busca linear
void searchGame(struct Game games[], char name[]){
    int found = 0;
    for(int i = 0; i < qtdGames; i++){
        if(strcmp(games[i].name, name) == 0){
            printf("Jogo encontrado:\n");
            printf("Nome: %s\n", games[i].name);
            printf("Gênero: %s\n", games[i].genre);
            printf("Ano de lançamento: %d\n", games[i].year);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Jogo não encontrado!\n");
    }
}

//Função para remover um jogo pelo nome
void removeGame(struct Game games[], char name[]){
    int found = 0;
    for(int i = 0; i < qtdGames; i++){
        if(strcmp(games[i].name, name) == 0){
            for(int j = i; j < qtdGames - 1; j++){
                games[j] = games[j + 1];
            }
            qtdGames--;
            printf("Jogo removido com sucesso!\n");
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Jogo não encontrado!\n");
    }
}   

//Função para buscar um jogo de usando a busca binária
void binarySearchGame(struct Game games[], char name[]){
    int left = 0;
    int right = qtdGames - 1;
    int found = 0;  
    while(left <= right){
        int mid = left + (right - left) / 2;
        int cmp = strcmp(games[mid].name, name);
        if(cmp == 0){
            printf("Jogo encontrado:\n");
            printf("Nome: %s\n", games[mid].name);
            printf("Gênero: %s\n", games[mid].genre);
            printf("Ano de lançamento: %d\n", games[mid].year);
            found = 1;
            break;
        }
        if(cmp < 0){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if(!found){
        printf("Jogo não encontrado!\n");
    }
}

//Função para buscar um jogo usando a busca interpolada
void interpolationSearchGame(struct Game games[], char name[]){
    int left = 0;
    int right = qtdGames - 1;
    int found = 0;  
    while(left <= right && strcmp(name, games[left].name) >= 0 && strcmp(name, games[right].name) <= 0){
        if(left == right){
            if(strcmp(games[left].name, name) == 0){
                printf("Jogo encontrado:\n");       
                printf("Nome: %s\n", games[left].name);
                printf("Gênero: %s\n", games[left].genre);
                printf("Ano de lançamento: %d\n", games[left].year);
                found = 1;
            }
            break;      
        }
        int pos = left + ((strcmp(name, games[left].name) * (right - left)) / (strcmp(games[right].name, games[left].name)));
        int cmp = strcmp(games[pos].name, name);
        if(cmp == 0){
            printf("Jogo encontrado:\n");
            printf("Nome: %s\n", games[pos].name);
            printf("Gênero: %s\n", games[pos].genre);
            printf("Ano de lançamento: %d\n", games[pos].year);
            found = 1;
            break;
        }
        if(cmp < 0){
            right = pos - 1;
        } else {
            left = pos + 1;
        }
    }
    if(!found){
        printf("Jogo não encontrado!\n");
    }
}

//Função para ordenar os jogos pelo nome usando o Bubble Sort
void bubbleSortGames(struct Game games[]){
    for(int i = 0; i < qtdGames - 1; i++){
        for(int j = 0; j < qtdGames - i - 1; j++){
            if(strcmp(games[j].name, games[j + 1].name) > 0){
                struct Game temp = games[j];
                games[j] = games[j + 1];
                games[j + 1] = temp;
            }
        }
    }
}

//Função para ordenar os jogos pelo nome usando o Selection Sort
void selectionSortGames(struct Game games[]){
    for(int i = 0; i < qtdGames - 1; i++){
        int minIndex = i;       
        for(int j = i + 1; j < qtdGames; j++){
            if(strcmp(games[j].name, games[minIndex].name) < 0){
                minIndex = j;
            }
        }
        struct Game temp = games[i];
        games[i] = games[minIndex];
        games[minIndex] = temp;
    }
}

//Função para ordenar os jogos pelo nome usando o Insertion Sort
void insertionSortGames(struct Game games[]){
    for(int i = 1; i < qtdGames; i++){
        struct Game key = games[i];
        int j = i - 1;      
        while(j >= 0 && strcmp(games[j].name, key.name) > 0){
            games[j + 1] = games[j];
            j--;
        }
        games[j + 1] = key;
    }
}   

//Menu para testar as funções
void menu(){
    int choice;
    char name[50];
    do{
        printf("Menu:\n");
        printf("1. Adicionar jogo\n");
        printf("2. Listar jogos\n");
        printf("3. Buscar jogo (Busca Linear)\n");      
        printf("4. Remover jogo\n");
        printf("5. Buscar jogo (Busca Binária)\n");
        printf("6. Buscar jogo (Busca Interpolada)\n");
        printf("7. Ordenar jogos (Bubble Sort)\n");
        printf("8. Ordenar jogos (Selection Sort)\n");
        printf("9. Ordenar jogos (Insertion Sort)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");  
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insertGame(games, name, "", 0);
                break;
            case 2:
                listGames(games);
                break;      
            case 3:
                printf("Digite o nome do jogo para buscar: ");
                scanf("%s", name);
                searchGame(games, name);
                break;
            case 4:
                printf("Digite o nome do jogo para remover: ");
                scanf("%s", name);
                removeGame(games, name);
                break;
            case 5:
                printf("Digite o nome do jogo para buscar: ");
                scanf("%s", name);
                bubbleSortGames(games); // Garantir que os jogos estão ordenados
                binarySearchGame(games, name);
                break;
            case 6:
                printf("Digite o nome do jogo para buscar: ");
                scanf("%s", name);
                bubbleSortGames(games); // Garantir que os jogos estão ordenados
                interpolationSearchGame(games, name);
                break;
            case 7: 
                bubbleSortGames(games);
                printf("Jogos ordenados usando Bubble Sort!\n");
                break;
            case 8:
                selectionSortGames(games);
                printf("Jogos ordenados usando Selection Sort!\n");
                break;
            case 9:
                insertionSortGames(games);
                printf("Jogos ordenados usando Insertion Sort!\n");
                break;
            case 0: 
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(choice != 0);
}