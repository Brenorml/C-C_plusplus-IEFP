#include <stdio.h>

int Levantamento(int valor, int valores[4][3])
{
    if (valor > 0)
    {
        while (valor > 0)
        {
            if (valor >= valores[0][0] && valores[0][2] != 0)
            {
                valor -= valores[0][0];
                valores[0][1]++;
                valores[0][2]--;
            }
            else if (valor >= valores[1][0] && valores[1][2] != 0)
            {
                valor -= valores[1][0];
                valores[1][1]++;
                valores[1][2]--;
            }
            else if (valor >= valores[2][0] && valores[2][2] != 0)
            {
                valor -= valores[2][0];
                valores[2][1]++;
                valores[2][2]--;
            }
            else if (valor >= valores[3][0] && valores[3][2] != 0)
            {
                valor -= valores[3][0];
                valores[3][1]++;
                valores[3][2]--;
            }
            else
            {
                return 1;
            }
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    char opcao;
    int valor = 0;
    int valores[4][3] = {{100, 0, 3}, {50, 0, 3}, {20, 0, 3}, {10, 0, 3}};
    printf("Insira o valor: ");
    scanf("%d", &valor);
    fflush(stdin);

    if (valor % 10 == 0)
    {
        do
        {
            if (Levantamento(valor, valores) == 1)
            {
                printf("Nao ha notas para este valor\n");                
            }
            else if (valores[0][2] != 0 || valores[1][2] != 0 || valores[2][2] != 0 || valores[3][2] != 0)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (valores[i][2] >= 0 && valores[i][1] > 0)
                    {
                        printf("%d nota(s) de %d\n", valores[i][1], valores[i][0]);
                        printf("contagem: %d quantidade: %d\n", valores[i][1], valores[i][2]);
                    }
                }                
            }
            else
            {
                printf("Nao ha mais notas no multibanco\nA aplicacao sera encerrada.\nAdeus...");
                break;
            }
            printf("Deseja levantar outro valor? (s/n) ");                
                scanf("%c", &opcao);
                fflush(stdin);
                while(opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N'){
                    printf("opcao invalida! Escolha 's' para sim ou n para 'n'... ");
                    scanf("%c", &opcao);
                    fflush(stdin);
                }
                if(opcao == 's' || opcao == 'S'){
                    //Ciclo para zerar o contador de notas no array.
                    for (int i = 0; i < 4; i++){
                        valores[i][1] = 0;
                    }
                    printf("Insira o valor: ");
                    scanf("%d[^\n]", &valor);
                    fflush(stdin);
                }
                else{
                    printf("Obrigado pela preferencia!!! Adeus...");
                }
        } while (opcao == 's');
    }
    else
    {
        printf("Nao tem notas com valor menor que 10.");
    }
}