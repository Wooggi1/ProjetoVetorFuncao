#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_USUARIOS 1000

int numUsuarios = 0;
int globalId[MAX_USUARIOS];
char globalNomeCompleto[MAX_USUARIOS][100];
char globalEmail[MAX_USUARIOS][100];
char globalSexo[MAX_USUARIOS][10];
char globalEndereco[MAX_USUARIOS][100];
double globalAltura[MAX_USUARIOS];
int globalVacina[MAX_USUARIOS];

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
            if(globalId[i] == id){
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

    globalId[numUsuarios] = id;
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

            printf("id: %d\n", globalId[i]);
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
/*
int ExcluirUsuario(){
    char email[100];
    int validacao = 1, certeza = 0;

    printf("Digite o email do usuario: ");
    scanf(" %[^\n]", email);

    for(int i = 0; i < numUsuarios; i++){
        if(strcmp(users[i].email, email) == 0){

            printf("nome: %s\n", users[i].nomeCompleto);
            printf("sexo: %s\n", users[i].sexo);
            printf("endereco: %s\n", users[i].endereco);
            printf("altura: %.2lf\n", users[i].altura);
            printf("status de vacinacao: %d\n", users[i].vacina);

            printf("Tem certeza que deseja excluir esse usuario?\n1 - sim 2 - nao\n");
            scanf("%d", &certeza);

            if(certeza == 1){
                users[i].id = 0;
                memset(users[i].email, 0, sizeof(users[i].email));
                memset(users[i].nomeCompleto, 0, sizeof(users[i].nomeCompleto));
                memset(users[i].sexo, 0, sizeof(users[i].sexo));
                memset(users[i].endereco, 0, sizeof(users[i].endereco));
                users[i].altura = 0;
                users[i].vacina = 0;
                numUsuarios--;
                
                for (int j = i + 1; j < numUsuarios; j++){
                    users[j - 1] = users [j];
                }
                return 0;
            }
            else if(certeza == 2){
                return 0;
            }
        }
    }
    printf("Usuario nao encontrado\n");
    return -1;
}

int BuscarPorEmail(){
    char email[100];

    printf("Digite o email do usuario: ");
    scanf(" %[^\n]", email);

    for(int i = 0; i < numUsuarios; i++){
        if(strcmp(users[i].email, email) == 0){

            printf("nome: %s\n", users[i].nomeCompleto);
            printf("email: %s\n", users[i].email);
            printf("sexo: %s\n", users[i].sexo);
            printf("endereco: %s\n", users[i].endereco);
            printf("altura: %.2lf\n", users[i].altura);
            printf("status de vacinacao: %d\n", users[i].vacina);

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
        printf("\n\n----------USUARIO %d----------\n", i+1);
        printf("id:  %d\n", users[i].id);
        printf("nome: %s\n", users[i].nomeCompleto);
        printf("email: %s\n", users[i].email);
        printf("sexo: %s\n", users[i].sexo);
        printf("endereco: %s\n", users[i].endereco);
        printf("altura: %.2lf\n", users[i].altura);
        printf("status de vacinacao: %d\n", users[i].vacina);
    }
}

int BackUp(){
    int certeza;

    printf("tem certeza que deseja fazer backup?\n1 - sim 2 - nao\n");
    scanf("%d", &certeza);

    if(certeza == 1){
        for(int i = 0; i < numUsuarios; i++){
            usersBackup[i].id = users[i].id;
            strcpy(usersBackup[i].nomeCompleto, users[i].nomeCompleto);
            strcpy(usersBackup[i].email, users[i].email);
            strcpy(usersBackup[i].sexo, users[i].sexo);
            strcpy(usersBackup[i].endereco, users[i].endereco);
            usersBackup[i].altura = users[i].altura;
            usersBackup[i].vacina = users[i].vacina;
        }
        
        printf("BackUp concluido com sucesso\n");
       
        return 0;
    }
    else if(certeza == 2){
        return 0;
    }
    else {
        printf("Opcao invalida\n");
        return -1;
    }
}

int RestaurarDados(){
    int certeza;

    printf("tem certeza que deseja restaurar dados?\n1 - sim 2 - nao\n");
    scanf("%d", &certeza);

    if(certeza == 1){
        for(int i = 0; i < numUsuarios; i++){
            users[i].id = usersBackup[i].id;
            strcpy(users[i].nomeCompleto, usersBackup[i].nomeCompleto);
            strcpy(users[i].email, usersBackup[i].email);
            strcpy(users[i].sexo, usersBackup[i].sexo);
            strcpy(users[i].endereco, usersBackup[i].endereco);
            users[i].altura = usersBackup[i].altura;
            users[i].vacina = usersBackup[i].vacina;
        }
        
        printf("Restauracao concluido com sucesso\n");
       
        return 0;
    }
    else if(certeza == 2){
        return 0;
    }
    else {
        printf("Opcao invalida\n");
        return -1;
    }
}*/