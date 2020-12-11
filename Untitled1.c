#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int i;

    //FUNÇÃO GRÁFICO E ALFANUMÉRICA
    printf("\t||##### GRÁFICO E ALFANUM #####||\n\n");
    printf("Em linguagem C, todos os caracteres "     //Exemplo utilizando os números da tabela ASCII.
           "gráficos são: \n\n");

    for (i = 0; i <= 127; ++i)   //Percorre os 127 caracteres da tabela ASCII.
        if (isgraph(i) != 0)     //Todas as funções retornam 0 (zero) caso a comparação não seja verdadeira.
            printf("%c ", i);    //Cada número representa um caractere na tabela ASCII, neste caso é mostrado
    //de i=33 que equivale ao ! até o i=126 que equivale ao ~ .

    printf("\n\nAlfanuméricos: \n\n");

    for (i = 0; i <= 127; ++i)
        if (isalnum(i) != 0)    //O mesmo exemplo porém agora mostrando somente os alfanuméricos.
            printf("%c ", i);

    printf("\n");

    printf("\n----------------------------------------------------------------------------------------\n");

    char c;
    int exemplo_retorno;       //Exemplo demonstrando a difirença nos valores de retorno das funções da biblioteca ctype.h

    //FUNÇÃO CONTROLE
    printf("\t||##### CONTROLE #####||\n\n");

    c = 'Q';
    exemplo_retorno = iscntrl(c);
    printf("Quando %c é passado o iscntrl() = %d\n", c, exemplo_retorno);   //Mostra que quando a verifica o caractere caso não
    //seja do tipo comparado retorna o valor 0.

    c = '\n';
    exemplo_retorno = iscntrl(c);
    printf("Quando 'quebra de linha' é passado o iscntrl() = %d", c, exemplo_retorno);   //Caso seja verdadeiro retorna um valor diferente de 0.

    printf("\n----------------------------------------------------------------------------------------\n");

    char exemplo[]="3x3mpL0...3x3mpL0\n";   //É possivel com essas funções separar e mostrar cada tipo de caractere.

    //ALFANUM, LETRAS, MAIUSC/MINUSC, IMPRIME, PONTUAÇÃO E DÍGITOS
    printf("\t||##### VERIFICA ALFANUM, LETRAS, MAIUSC/MINUSC, IMPRIME, PONTUAÇÃO E DÍGITOS #####||\n\n");

    for(i=0; i<19; i++)
        if(isalnum(exemplo[i]))             //Verifica se os caracteres são alfanumericos.
            printf ("%c ",exemplo[i]);

    printf("\n\n");

    for(i=0; i<19; i++)
        if(isalpha(exemplo[i]))             //Verifica se são letras.
            printf ("%c ",exemplo[i]);

    printf("\n\n");

    for(i=0; i<19; i++)
        if(islower(exemplo[i]))             //Verifica se são letras minúsculas
            printf ("%c ",exemplo[i]);

    printf("\n\n");

    for(i=0; i<19; i++)
        if(isprint(exemplo[i]))             //Verifica se são caracteres imprimiveis.
            printf ("%c ",exemplo[i]);

    printf("\n\n");

    for(i=0; i<19; i++)
        if(ispunct(exemplo[i]))             //Verifica se são caracteres de pontuação.
            printf ("%c ",exemplo[i]);

    printf("\n\n");

    for(i=0; i<19; i++)
        if(isupper(exemplo[i]))             //Verifica se são letras maiúsculas.
            printf ("%c ",exemplo[i]);

    printf("\n\n");

    for(i=0; i<19; i++)
        if(isdigit(exemplo[i]))             //Verifica se os caracteres são dígitos decimais.
            printf ("%c ",exemplo[i]);

    printf("\n");

    printf("\n----------------------------------------------------------------------------------------\n");

    char exem_minuscula, exem_maiuscula;

    //CONVERTE MAIUSC/MINUSC
    printf("\t||##### CONVERTE MAIUSC/MINUSC #####||\n\n");

    exem_minuscula = 'a';
    exem_maiuscula = 'B';

    exem_minuscula = toupper(exem_minuscula);  //Converte o caracter em maiúsculo
    exem_maiuscula = tolower(exem_maiuscula);  //Converte o caracter em minúsculo
    printf("%c %c\n", exem_minuscula, exem_maiuscula);

    exem_minuscula = tolower(exem_minuscula);
    exem_maiuscula = toupper(exem_maiuscula);
    printf("%c %c\n", exem_minuscula, exem_maiuscula);

    printf("\n----------------------------------------------------------------------------------------\n");

    char d;
    int y=0;
    char str_exem[]="Testando a função isspace\n";

    //FUNÇÃO ISSPACE
    //printf("\t||##### ISSPACE #####||\n\n");

    while (str_exem[y])
    {
        d=str_exem[y]; //O caractere 'c' serve como auxiliar para fazer o teste dos caracteres recebidos da str_exem
        if(isspace(d)) //Verifica se o caractere 'c' é espaço
            d='\n'; //Faz 'c' receber uma quebra de linha caso seja um espaço
        putchar(d); //Coloca na tela o caractere 'c'
        y++; //Passa para a próxima letra da string
    }
    printf("\n----------------------------------------------------------------------------------------\n");

    char str_exem1, str_exem2, str_exem3;

    //HEXADECIMAL
    printf("\t||##### HEXADECIMAL #####||\n\n");

    str_exem1 = '2';        //Será considerado como um caractere hexadecimal.
    str_exem2 = 'a';        //Será considerado como um caractere hexadecimal.
    str_exem3 = 'x';        //Não será considerado como um caractere hexadecimal.

    if (isxdigit(str_exem1))                            //É feita a verificação de todos os exemplos.
        printf("%c e hexadecimal.\n", str_exem1);
    else
        printf("%c nao e hexadecimal.\n", str_exem1);

    if (isxdigit(str_exem2))
        printf("%c e hexadecimal.\n", str_exem2);
    else
        printf("%c nao e hexadecimal.\n", str_exem2);

    if (isxdigit(str_exem3))
        printf("%c e hexadecimal.\n", str_exem3);
    else
        printf("%c nao e hexadecimal.\n", str_exem3);

    printf("\n----------------------------------------------------------------------------------------\n");

    //EXEMPLO PRÁTICO
    printf("\t||##### EXEMPLO SENHA #####||\n\n");
    int aux_nume = 0, aux_maiuscula = 0, aux_minuscula = 0, aux_pont = 0;
    char senha[25];

    while(aux_maiuscula==0 || aux_minuscula==0 || aux_nume==0 || aux_pont==0)
    {
        printf("Digite a nova senha (Deve conter uma letra maiúscula, uma minúscula, um número e um caractere especial: ");
        fgets(senha,25,stdin);

        if (aux_nume == 0)
        {
            for(i=0; i<strlen(senha); i++)
                if (isdigit(senha[i]))
                    aux_nume = 1;
        }
        if (aux_maiuscula == 0)
        {
            for(i=0; i<strlen(senha); i++)
                if (isupper(senha[i]))
                    aux_maiuscula = 1;
        }
        if (aux_minuscula == 0)
        {
            for(i=0; i<strlen(senha); i++)
                if (islower(senha[i]))
                    aux_minuscula = 1;
        }
        if (aux_pont == 0)
        {
            for(i=0; i<strlen(senha); i++)
                if (ispunct(senha[i]))
                    aux_pont = 1;
        }
        if(aux_maiuscula==1 && aux_minuscula==1 && aux_nume==1 && aux_pont==1)
            printf("\nSenha válida.\n");
        else if(aux_maiuscula==0 || aux_minuscula==0 || aux_nume==0 || aux_pont==0)
            printf("\n\nSenha inválida. Digite novamente.\n\n");
    }

    return 0;
}

