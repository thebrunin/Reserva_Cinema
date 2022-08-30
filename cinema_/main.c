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
void printPoltrona(struct poltronas x[][10]);
void cancelar(struct poltronas x[][10], char letra, int numero);
void reservar(struct poltronas x[][10], char letra, int numero);
void comprar(struct poltronas x[][10], char letra, int numero);
void rodartudo(struct poltronas x[][10]);

int main()
{
    struct poltronas cinema[8][10];
    rodartudo(cinema);
    return 0;
}

void rodartudo(struct poltronas x[][10])
{
    zeraSala(x);
    int roda=0;
    while(roda != 4){
        char linha;
        int coluna;
        system("cls");
        printPoltrona(x);
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
void printPoltrona(struct poltronas x[][10])
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    SetConsoleTextAttribute(hConsole, 70);
    printf("                            --------Sala 01--------                            \n");
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

    SetConsoleTextAttribute(hConsole, 70);
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
    for(int i=65;i<73;i++){
        for(int j=0;j<10;j++){
            if(letra == x[linha][j].linha && numero == x[linha][j].coluna)
               x[linha][j].disponivel='X';
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


