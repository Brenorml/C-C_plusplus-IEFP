#include <stdio.h>

int Levantamento(int valor, int valores[4][3])
{
    //Valor do total contido no multbanco não pode ser 540 exatos por questões de arredondamentos do processador
    static int total = 543;
    if(valor % 10 != 0)
    {
        return 2;
    }
    if(total < 10)
    {
        return 0;
    }
    else if(valor > total)
    {
        return 1;
    }
    else if (valor > 0 && total > valor)
    {
        //ciclo para verificação dos valores contidos no array bidimensional
        while (valor > 0)
        {
            if (valor % valores[0][0] == 0 && valores[0][2] != 0)
            {
                valor -= valores[0][0];
                valores[0][1]++;
                valores[0][2]--;
                total -= valores[0][0];
            }
            else if (valor % valores[1][0] == 0 && valores[1][2] != 0)
            {
                valor -= valores[1][0];
                valores[1][1]++;
                valores[1][2]--;
                total -= valores[1][0];
            }
            else if (valor % valores[2][0] == 0 && valores[2][2] != 0)
            {
                valor -= valores[2][0];
                valores[2][1]++;
                valores[2][2]--;
                total -= valores[2][0];
            }
            else if (valor % valores[3][0] == 0 && valores[3][2] != 0)
            {
                valor -= valores[3][0];
                valores[3][1]++;
                valores[3][2]--;
                total -= valores[3][0];
            }
            else if(valores[0][2] == 0 && valores[1][2] == 0 && valores[2][2] == 0 && valores[3][2] == 0)
            {
                return 0;
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
    int valor = 0, resultado;

    //Em cada linha do array o indice 0 contem os valores para levantamento, indice 1 a contagem das cédulas , indice 2 a quantidade disponível no multibanco
    int valores[4][3] = {{100, 0, 3}, {50, 0, 3}, {20, 0, 3}, {10, 0, 3}};

    printf("Insira o valor: ");
    scanf("%d", &valor);
    fflush(stdin); //Limpeza do buffer de entrada para retirar o enter

    do
    {
        resultado = Levantamento(valor, valores);
        if (resultado == 0)
        {
            printf("Nao ha mais notas no multibanco\nA aplicacao sera encerrada.\nAdeus...");
            break;
        }
        else if (resultado == 1)
        {
            printf("Nao ha notas para este valor\n");
        }
        else if (resultado == 2)
        {
            printf("Nao tem notas com valor menor do que 10.\n");
        }
        else
        {
            //imppressão das cédulas e suas respectivas quantidades
            for (int i = 0; i < 4; i++)
            {
                if (valores[i][2] >= 0 && valores[i][1] > 0)
                {
                    printf("%d nota(s) de %d\n", valores[i][1], valores[i][0]);
                    //Impressão de validação
                    //printf("contagem: %d quantidade: %d\n", valores[i][1], valores[i][2]);
                }
            }
        }
        printf("Deseja levantar outro valor? (s/n) ");
            scanf("%c", &opcao);
            fflush(stdin);

            //Ciclo para controle de entradas diferentes do s e n
            while(opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N'){
                printf("opcao invalida! Escolha 's' para sim ou n para 'n'... ");
                scanf("%c", &opcao);
                fflush(stdin);
            }
            if(opcao == 's' || opcao == 'S'){
                //Ciclo para zerar o contador de cédulas no array.
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
