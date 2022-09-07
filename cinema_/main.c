#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct poltronas{

    //se 0 disponivel, se 1 indisponivel
    char disponivel;

    //cpf de quem reservou
    int reservada;

    //cpf de quem comprou
    int comprada;

    //posicao
    int coluna;
    char linha;

};

void zeraSala(struct poltronas x[][10]);
void printPoltrona(struct poltronas x[][10], int sala);
void cancelar(struct poltronas x[][10], char letra, int numero);
void reservar(struct poltronas x[][10], char letra, int numero);
void comprar(struct poltronas x[][10], char letra, int numero);
void rodartudo(struct poltronas x[][10], int sala);
int cinemin();
void rodarCinema(struct poltronas x[][10]);
void comprarIngressos(struct poltronas x[][10]);
void filmesCartaz();

int main()
{
    struct poltronas cinema[8][10];
    rodarCinema(cinema);
    return 0;
}

void rodartudo(struct poltronas x[][10], int sala)
{
    zeraSala(x);
    int roda=0;
    while(roda != 4){
        char linha;
        int coluna;
        system("pause");
        system("cls");
        printPoltrona(x, sala);
        roda=menu();
        fflush(stdin);
        switch(roda){
            case 1:
                printf("\nInsira a letra do corredor:");
                scanf("%c", &linha);
                fflush(stdin);
                printf("Insira o numero da poltrona:");
                scanf("%d", &coluna);
                fflush(stdin);
                reservar(x, linha, coluna);
                break;
            case 2:
                printf("\nInsira a letra do corredor:");
                scanf("%c", &linha);
                fflush(stdin);
                printf("Insira o numero da poltrona:");
                scanf("%d", &coluna);
                fflush(stdin);
                comprar(x, linha, coluna);
                break;
            case 3:
                printf("\nInsira a letra do corredor:");
                scanf("%c", &linha);
                fflush(stdin);
                printf("Insira o numero da poltrona:");
                scanf("%d", &coluna);
                fflush(stdin);
                cancelar(x, linha, coluna);
                break;
            case 4:
                printf("\nSaindo\n");
                break;
            default:
                printf("\nOpcao incorreta\n");
        }
    }
}
void printPoltrona(struct poltronas x[][10], int sala)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    SetConsoleTextAttribute(hConsole, 79);
    printf("                            --------Sala %d---------                            \n", sala);
    printf("                            -----------------------                            \n");
    printf("                            -------Poltronas-------                            \n\n");
    SetConsoleTextAttribute(hConsole, 7);
    int linha=0;
    for(int i=65;i<73;i++){
            printf("%c: ", i);
        for(int j=1;j<=10;j++){
                if(j==6){
                    SetConsoleTextAttribute(hConsole, 7);
                    printf("      ");
                    SetConsoleTextAttribute(hConsole, 7);
                }
                if(x[linha][j-1].disponivel=='L'){
                    SetConsoleTextAttribute(hConsole, 160);
                    printf("%d[ %c ]", j, x[linha][j-1].disponivel);
                    SetConsoleTextAttribute(hConsole, 7);
                    printf(" ");
                } else if(x[linha][j-1].disponivel=='R'){
                    SetConsoleTextAttribute(hConsole, 96);
                    printf("%d[ %c ]", j, x[linha][j-1].disponivel);
                    SetConsoleTextAttribute(hConsole, 7);
                    printf(" ");
                } else if(x[linha][j-1].disponivel=='X'){
                    SetConsoleTextAttribute(hConsole, 64);
                    printf("%d[ %c ]", j, x[linha][j-1].disponivel);
                    SetConsoleTextAttribute(hConsole, 7);
                    printf(" ");
                }
        }
        printf("\n\n");
        linha++;
    }
}
void zeraSala(struct poltronas x[][10])
{
    int linha=0;
    for(int i=65;i<73;i++){
        for(int j=1;j<=10;j++){
            x[linha][j-1].disponivel='L';
            x[linha][j-1].coluna=j;
            x[linha][j-1].linha=i;
        }
        linha++;
    }
}
int menu()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    SetConsoleTextAttribute(hConsole, 79);
    printf("                            ----1 - Reservar------------                        \n");
    printf("                            ----2 - Comprar-------------                        \n");
    printf("                            ----3 - Cancelar reserva----                        \n");
    printf("                            ----4 - Sair----------------                        \n");
    SetConsoleTextAttribute(hConsole, 7);
    int escolha=0;
    printf("                            Escolha uma opcao:");
    scanf("%d", &escolha);
    return escolha;

}
void comprar(struct poltronas x[][10], char letra, int numero)
{
    int linha=0;
    int cpf;
    printf("Insira seu cpf:");
    scanf("%d", &cpf);
    for(int i=65;i<73;i++){
        for(int j=0;j<10;j++){
            if(letra == x[linha][j].linha && numero == x[linha][j].coluna)
               x[linha][j].disponivel='X';
               x[linha][j].comprada=cpf;
        }
        linha++;
    }
}
void reservar(struct poltronas x[][10], char letra, int numero)
{
    int linha=0;
    for(int i=65;i<73;i++){
        for(int j=0;j<10;j++){
            if(letra == x[linha][j].linha && numero == x[linha][j].coluna)
               x[linha][j].disponivel='R';
        }
        linha++;
    }
}
void cancelar(struct poltronas x[][10], char letra, int numero)
{
    int linha=0;
    for(int i=65;i<73;i++){
        for(int j=0;j<10;j++){
            if(letra == x[linha][j].linha && numero == x[linha][j].coluna)
                if(x[linha][j].disponivel=='R')
                    x[linha][j].disponivel='L';
                else
                    printf("Cancelamos apenas reservas! Bom filme!\n");
        }
        linha++;
    }
}
int cinemin()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    SetConsoleTextAttribute(hConsole, 7);
    printf("------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------\n");
    printf("-----|||||||||   oo   |||    ||   ||||||||||  |||       |||  oo  |||    ||----\n");
    printf("-----||               || |   ||   ||          || |     | ||      || |   ||----\n");
    printf("-----||          ||   ||  |  ||   |||||||||   ||  |   |  ||  ||  ||  |  ||----\n");
    printf("-----||          ||   ||   | ||   ||          ||   | |   ||  ||  ||   | ||----\n");
    printf("-----||||||||||  ||   ||    |||   ||||||||||  ||    |    ||  ||  ||    |||----\n");
    printf("------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------\n");
    SetConsoleTextAttribute(hConsole, 7);
    printf("------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------\n");
    printf("-----------------------------1 - Comprar imgressos----------------------------\n");
    printf("-----------------------------2 - Proximos lancamentos-------------------------\n");
    printf("-----------------------------3 - Pipoca e refri-------------------------------\n");
    printf("-----------------------------4 - Sair-----------------------------------------\n");
    printf("------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------\n");
    SetConsoleTextAttribute(hConsole, 7);
    int a;
    printf("Insira a opcao desejada:");
    scanf("%d", &a);
    return a;
}
void filmesCartaz()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    SetConsoleTextAttribute(hConsole, 79);
    printf("---------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
    printf("---------------------------FILMES EM CARTAZ--------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
    printf("--------------------------|SALA|---|FILME|--------------|Horario|----------\n");
    printf("--------------------------- 1 ---- Kung fu panda--------16:00-as-18:00-----\n");
    printf("--------------------------- 2 ---- Player One-----------18:00-as-21:00-----\n");
    printf("--------------------------- 3 ---- Pulp Fiction---------19:30-as-21:00-----\n");
    printf("--------------------------- 4 ---- Furia de titas-------21:00-as-23:00-----\n");
    printf("---------------------------------------------------------------------------\n");
    SetConsoleTextAttribute(hConsole, 7);
}
void comprarIngressos(struct poltronas x[][10])
{
    filmesCartaz();
    int filme;
    printf("Qual a sala do filme desejado:");
    scanf("%d", &filme);
    rodartudo(x, filme);
}
void rodarCinema(struct poltronas x[][10])
{
    int roda=0;
    while(roda != 4){
        system("cls");
        roda=cinemin();
        fflush(stdin);
        switch(roda){
            case 1:
                system("cls");
                comprarIngressos(x);
                break;
            case 2:
                system("cls");
                printf("\nEm manutencao\n");
                break;
            case 3:
                system("cls");
                printf("\nEm manutencao\n");
                break;
            case 4:
                printf("\nSaindo\n");
                break;
            default:
                printf("\nOpcao incorreta\n");
        }
        system("pause");
    }
}


