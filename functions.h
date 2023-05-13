#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_USUARIOS 1000

int numUsuarios = 0;
//dados do usuario
int globalID[MAX_USUARIOS];
char globalNomeCompleto[MAX_USUARIOS][100];
char globalEmail[MAX_USUARIOS][100];
char globalSexo[MAX_USUARIOS][10];
char globalEndereco[MAX_USUARIOS][100];
double globalAltura[MAX_USUARIOS];
int globalVacina[MAX_USUARIOS];
//backup
int backupID[MAX_USUARIOS];
char backupNomeCompleto[MAX_USUARIOS][100];
char backupEmail[MAX_USUARIOS][100];
char backupSexo[MAX_USUARIOS][10];
char backupEndereco[MAX_USUARIOS][100];
double backupAltura[MAX_USUARIOS];
int backupVacina[MAX_USUARIOS];

void AbrirMenu(){

    printf("1 - Adicionar Usuario\n");
    printf("2 - Editar Usuario\n");
    printf("3 - Excluir usuario\n");
    printf("4 - Buscar por Email\n");
    printf("5 - Imprimir todos os usuarios\n");
    printf("6 - Fazer Backup dos usuarios\n");
    printf("7 - Restaurar os dados\n");
    printf("0 - Fechar programa\n");
    printf("Digite a opcao escolhida: ");
}

int AdicionarUsuario(){
    int id, vacina, validacao, encontrado = 0;
    char nome[100], email[100], sexo[10], endereco[100];
    double altura;

    if (numUsuarios >= MAX_USUARIOS){
        printf("Numero de usuarios alcançou o limite D:\n");
        return -1;
    }
    
    srand(time(NULL));
    do{
        id = rand() % 100000;

        for(int i = 0; i < numUsuarios; i++)
        {
            if(globalID[i] == id){
                printf("Usuario ja existe\n");
                id = 00000;
                validacao = 1;
                break;
            }
            else{
                validacao = 0;
            }
        }
    }while (validacao == 1);

    printf("Digite seu nome completo: ");
    scanf(" %[^\n]", nome);

    printf("Digite seu email: ");
    scanf(" %[^\n]", email);

    do{
        validacao = 1;
        for (int i = 0; i < strlen(email); i++)
        {
            if (email[i] == '@'){
                validacao = 0;
                break;
            }
        }

        if(validacao == 1){
            printf("Email invalido, tente novamente: ");
            scanf(" %[^\n]", email);
        }
    }
    while(validacao == 1);

    printf("Digite seu sexo(Masculino/Feminino/Indefinido): ");
    scanf(" %[^\n]", sexo);
    sexo[0] = toupper(sexo[0]);

    while(!(strcmp(sexo, "Masculino") == 0 || strcmp(sexo, "Feminino") == 0 || strcmp(sexo, "Indefinido") == 0)){
            printf("Sexo invalido tente novamente: ");
            scanf(" %[^\n]", sexo);
            sexo[0] = toupper(sexo[0]);
    }

    printf("Digite seu endereco: ");
    scanf(" %[^\n]", endereco);

    printf("Digite sua altura: ");
    scanf("%lf", &altura);
    while(altura > 2 || altura < 1){
            printf("Altura invalida, lembre-se a medida esta em metros\n");
            printf("Tente novamente: ");
            scanf("%lf", &altura);
    }

    printf("Digite o estado de sua vacinacao (1 = Vacinado/ 0 = Nao vacinado): ");
    scanf("%d", &vacina);
    
    while(!(vacina == 1 || vacina == 0)){
            printf("So sao aceitos 1 e 0 como valor\n");
            printf("Tente novamente: ");
            scanf("%d", &vacina);
    }

    globalID[numUsuarios] = id;
    strcpy(globalNomeCompleto[numUsuarios], nome);
    strcpy(globalEmail[numUsuarios], email);
    strcpy(globalSexo[numUsuarios], sexo);
    strcpy(globalEndereco[numUsuarios], endereco);
    globalAltura[numUsuarios] = altura;
    globalVacina[numUsuarios] = vacina;
    numUsuarios++;

    return 0;
}

int EditarUsuario(){
    int id, vacina, validacao, encontrado = 0;
    char nome[100], email[100], sexo[10], endereco[100];
    double altura;

    printf("Digite o email do usuario: ");
    scanf(" %[^\n]", email);

    for(int i = 0; i < numUsuarios + 1; i++){
        if(strcmp(globalEmail[i], email) == 0){

            printf("id: %d\n", globalID[i]);
            printf("nome: %s\n", globalNomeCompleto[i]);
            printf("sexo: %s\n", globalSexo[i]);
            printf("endereco: %s\n", globalEndereco[i]);
            printf("altura: %.2lf\n", globalAltura[i]);
            printf("status de vacinacao: %d\n", globalVacina[i]);

            printf("Digite seu nome completo: ");
            scanf(" %[^\n]", nome);

            printf("Digite seu sexo(Masculino/Feminino/Indefinido): ");
            scanf(" %[^\n]", sexo);
            sexo[0] = toupper(sexo[0]);

            while(!(strcmp(sexo, "Masculino") == 0 || strcmp(sexo, "Feminino") == 0 || strcmp(sexo, "Indefinido") == 0)){
                printf("Sexo invalido tente novamente: ");
                scanf(" %[^\n]", sexo);
                sexo[0] = toupper(sexo[0]);
            }

            printf("Digite seu endereco: ");
            scanf(" %[^\n]", endereco);

            printf("Digite sua altura: ");
            scanf("%lf", &altura);

            while(altura > 2 || altura < 1){
                printf("Altura invalida, lembre-se a medida esta em metros\n");
                printf("Tente novamente: ");
                scanf("%lf", &altura);
            }

            printf("Digite o estado de sua vacinacao (1 = Vacinado/ 0 = Nao vacinado): ");
            scanf("%d", &vacina);
    
            while(!(vacina == 1 || vacina == 0)){
                printf("So sao aceitos 1 e 0 como valor\n");
                printf("Tente novamente: ");
                scanf("%d", &vacina);
            }

            strcpy(globalNomeCompleto[i], nome);
            strcpy(globalEmail[i], email);
            strcpy(globalSexo[i], sexo);
            strcpy(globalEndereco[i], endereco);
            globalAltura[i] = altura;
            globalVacina[i] = vacina;

            printf("novo nome: %s\n", globalNomeCompleto[i]);
            printf("novo sexo: %s\n", globalSexo[i]);
            printf("novo endereco: %s\n", globalEndereco[i]);
            printf("nova altura: %.2lf\n", globalAltura[i]);
            printf("novo status de vacinacao: %d\n", globalVacina[i]);

            return 0;
        }
    }
    printf("Usuario nao encontrado.\n");
    return -1;
}

int ExcluirUsuario() {
    char email[100];
    int certeza;

    printf("Digite o email do usuario: ");
    scanf("%99[^\n]", email); 

    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(globalEmail[i], email) == 0) {
            printf("id: %d\n", globalID[i]);
            printf("nome: %s\n", globalNomeCompleto[i]);
            printf("sexo: %s\n", globalSexo[i]);
            printf("endereco: %s\n", globalEndereco[i]);
            printf("altura: %.2lf\n", globalAltura[i]);
            printf("status de vacinacao: %d\n", globalVacina[i]);

            printf("Tem certeza que deseja excluir esse usuario?\n1 - sim 0 - nao\n");
            scanf("%d", &certeza);

            if (certeza == 1) {
                for (int j = i + 1; j < numUsuarios; j++) {
                    globalID[j - 1] = globalID[j];
                    strcpy(globalEmail[j - 1], globalEmail[j]);
                    strcpy(globalNomeCompleto[j - 1], globalNomeCompleto[j]);
                    strcpy(globalSexo[j - 1], globalSexo[j]);
                    strcpy(globalEndereco[j - 1], globalEndereco[j]);
                    globalAltura[j - 1] = globalAltura[j];
                    globalVacina[j - 1] = globalVacina[j];
                }

                globalID[numUsuarios - 1] = 0;
                memset(globalEmail[numUsuarios - 1], 0, sizeof(globalEmail[numUsuarios - 1]));
                memset(globalNomeCompleto[numUsuarios - 1], 0, sizeof(globalNomeCompleto[numUsuarios - 1]));
                memset(globalSexo[numUsuarios - 1], 0, sizeof(globalSexo[numUsuarios - 1]));
                memset(globalEndereco[numUsuarios - 1], 0, sizeof(globalEndereco[numUsuarios - 1]));
                globalAltura[numUsuarios - 1] = 0;
                globalVacina[numUsuarios - 1] = 0;
                numUsuarios--;

                printf("Usuario excluido com sucesso!\n");
                return 0;
            }
            else if (certeza == 0) {
                printf("Finalizando funcao ExcluirUsuario!\n");
                return 0;
            }
        }
    }
    printf("Usuario nao encontrado\n");
    return -2; 
}


int BuscarPorEmail(){
    char email[100];

    printf("Digite o email do usuario: ");
    scanf(" %[^\n]", email);

    for(int i = 0; i < numUsuarios + 1; i++){
        if(strcmp(globalEmail[i], email) == 0){

            printf("id: %d\n", globalID[i]);
            printf("nome: %s\n", globalNomeCompleto[i]);
            printf("sexo: %s\n", globalSexo[i]);
            printf("endereco: %s\n", globalEndereco[i]);
            printf("altura: %.2lf\n", globalAltura[i]);
            printf("status de vacinacao: %d\n", globalVacina[i]);

            return 0;
        }
        else{
            printf("Usuario nao encontrado\n");
            return -1;
        }
    }
}

int ImprimirUsuarios(){
    for(int i = 0; i < numUsuarios; i++){
        printf("\n----------USUARIO %d----------\n", i+1);
        printf("id: %d\n", globalID[i]);
        printf("email: %s\n", globalEmail[i]);
        printf("nome: %s\n", globalNomeCompleto[i]);
        printf("sexo: %s\n", globalSexo[i]);
        printf("endereco: %s\n", globalEndereco[i]);
        printf("altura: %.2lf\n", globalAltura[i]);
        printf("status de vacinacao: %d\n\n", globalVacina[i]);
    }
}

int BackUp(){
    int certeza;

    printf("tem certeza que deseja fazer backup?\n1 - sim 0 - nao\n");
    scanf("%d", &certeza);

    if(certeza == 1){
        for(int i = 0; i < numUsuarios; i++){
            backupID[i] = globalID[i];
            strcpy(backupNomeCompleto[i], globalNomeCompleto[i]);
            strcpy(backupEmail[i], globalEmail[i]);
            strcpy(backupSexo[i], globalSexo[i]);
            strcpy(backupEndereco[i], globalEndereco[i]);
            backupAltura[i] = globalAltura[i];
            backupVacina[i] = globalVacina[i];
        }
        
        printf("BackUp concluido com sucesso!\n\n");
       
        return 0;
    }
    else if(certeza == 0){
        printf("Backup cancelado!\n\n");
        return 0;
    }
    else {
        printf("Opcao invalida!\n\n");
        return -1;
    }
}

int RestaurarDados(){
    int certeza;

    printf("tem certeza que deseja restaurar dados?\n1 - sim 0 - nao\n");
    scanf("%d", &certeza);

    if(certeza == 1){
        for(int i = 0; i < numUsuarios; i++){
            globalID[i] = backupID[i];
            strcpy(globalNomeCompleto[i], backupNomeCompleto[i]);
            strcpy(globalEmail[i], backupEmail[i]);
            strcpy(globalSexo[i], backupSexo[i]);
            strcpy(globalEndereco[i], backupEndereco[i]);
            globalAltura[i] = backupAltura[i];
            globalVacina[i] = backupVacina[i];
        }
        
        printf("Restauracao concluida com sucesso!\n\n");
       
        return 0;
    }
    else if(certeza == 0){
        printf("Saindo da função de restaurar dados!\n\n");
        return 0;
    }
    else {
        printf("Opcao invalida\n");
        return -1;
    }
}