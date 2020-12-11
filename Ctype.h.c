#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int i;

    //FUN��O GR�FICO E ALFANUM�RICA
    printf("\t||##### GR�FICO E ALFANUM #####||\n\n");
    printf("Em linguagem C, todos os caracteres "     //Exemplo utilizando os n�meros da tabela ASCII.
           "gr�ficos s�o: \n\n");

    for (i = 0; i <= 127; ++i)   //Percorre os 127 caracteres da tabela ASCII.
        if (isgraph(i) != 0)     //Todas as fun��es retornam 0 (zero) caso a compara��o n�o seja verdadeira.
            printf("%c ", i);    //Cada n�mero representa um caractere na tabela ASCII, neste caso � mostrado
    //de i=33 que equivale ao ! at� o i=126 que equivale ao ~ .

    printf("\n\nAlfanum�ricos: \n\n");

    for (i = 0; i <= 127; ++i)
        if (isalnum(i) != 0)    //O mesmo exemplo por�m agora mostrando somente os alfanum�ricos.
            printf("%c ", i);

    printf("\n");

    printf("\n----------------------------------------------------------------------------------------\n");

    char c;
    int exemplo_retorno;       //Exemplo demonstrando a difiren�a nos valores de retorno das fun��es da biblioteca ctype.h

    //FUN��O CONTROLE
    printf("\t||##### CONTROLE #####||\n\n");

    c = 'Q';
    exemplo_retorno = iscntrl(c);
    printf("Quando %c � passado o iscntrl() = %d\n", c, exemplo_retorno);   //Mostra que quando a verifica o caractere caso n�o
    //seja do tipo comparado retorna o valor 0.

    c = '\n';
    exemplo_retorno = iscntrl(c);
    printf("Quando 'quebra de linha' � passado o iscntrl() = %d", c, exemplo_retorno);   //Caso seja verdadeiro retorna um valor diferente de 0.

    printf("\n----------------------------------------------------------------------------------------\n");

    char exemplo[]="3x3mpL0...3x3mpL0\n";   //� possivel com essas fun��es separar e mostrar cada tipo de caractere.

    //ALFANUM, LETRAS, MAIUSC/MINUSC, IMPRIME, PONTUA��O E D�GITOS
    printf("\t||##### VERIFICA ALFANUM, LETRAS, MAIUSC/MINUSC, IMPRIME, PONTUA��O E D�GITOS #####||\n\n");

    for(i=0; i<19; i++)
        if(isalnum(exemplo[i]))             //Verifica se os caracteres s�o alfanumericos.
            printf ("%c ",exemplo[i]);

    printf("\n\n");

    for(i=0; i<19; i++)
        if(isalpha(exemplo[i]))             //Verifica se s�o letras.
            printf ("%c ",exemplo[i]);

    printf("\n\n");

    for(i=0; i<19; i++)
        if(islower(exemplo[i]))             //Verifica se s�o letras min�sculas
            printf ("%c ",exemplo[i]);

    printf("\n\n");

    for(i=0; i<19; i++)
        if(isprint(exemplo[i]))             //Verifica se s�o caracteres imprimiveis.
            printf ("%c ",exemplo[i]);

    printf("\n\n");

    for(i=0; i<19; i++)
        if(ispunct(exemplo[i]))             //Verifica se s�o caracteres de pontua��o.
            printf ("%c ",exemplo[i]);

    printf("\n\n");

    for(i=0; i<19; i++)
        if(isupper(exemplo[i]))             //Verifica se s�o letras mai�sculas.
            printf ("%c ",exemplo[i]);

    printf("\n\n");

    for(i=0; i<19; i++)
        if(isdigit(exemplo[i]))             //Verifica se os caracteres s�o d�gitos decimais.
            printf ("%c ",exemplo[i]);

    printf("\n");

    printf("\n----------------------------------------------------------------------------------------\n");

    char exem_minuscula, exem_maiuscula;

    //CONVERTE MAIUSC/MINUSC
    printf("\t||##### CONVERTE MAIUSC/MINUSC #####||\n\n");

    exem_minuscula = 'a';
    exem_maiuscula = 'B';

    exem_minuscula = toupper(exem_minuscula);  //Converte o caracter em mai�sculo
    exem_maiuscula = tolower(exem_maiuscula);  //Converte o caracter em min�sculo
    printf("%c %c\n", exem_minuscula, exem_maiuscula);

    exem_minuscula = tolower(exem_minuscula);
    exem_maiuscula = toupper(exem_maiuscula);
    printf("%c %c\n", exem_minuscula, exem_maiuscula);

    printf("\n----------------------------------------------------------------------------------------\n");

    char d;
    int y=0;
    char str_exem[]="Testando a fun��o isspace\n";

    //FUN��O ISSPACE
    //printf("\t||##### ISSPACE #####||\n\n");

    while (str_exem[y])
    {
        d=str_exem[y]; //O caractere 'c' serve como auxiliar para fazer o teste dos caracteres recebidos da str_exem
        if(isspace(d)) //Verifica se o caractere 'c' � espa�o
            d='\n'; //Faz 'c' receber uma quebra de linha caso seja um espa�o
        putchar(d); //Coloca na tela o caractere 'c'
        y++; //Passa para a pr�xima letra da string
    }
    printf("\n----------------------------------------------------------------------------------------\n");

    char str_exem1, str_exem2, str_exem3;

    //HEXADECIMAL
    printf("\t||##### HEXADECIMAL #####||\n\n");

    str_exem1 = '2';        //Ser� considerado como um caractere hexadecimal.
    str_exem2 = 'a';        //Ser� considerado como um caractere hexadecimal.
    str_exem3 = 'x';        //N�o ser� considerado como um caractere hexadecimal.

    if (isxdigit(str_exem1))                            //� feita a verifica��o de todos os exemplos.
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

    //EXEMPLO PR�TICO
    printf("\t||##### EXEMPLO SENHA #####||\n\n");
    int aux_nume = 0, aux_maiuscula = 0, aux_minuscula = 0, aux_pont = 0;
    char senha[25];

    while(aux_maiuscula==0 || aux_minuscula==0 || aux_nume==0 || aux_pont==0)
    {
        printf("Digite a nova senha (Deve conter uma letra mai�scula, uma min�scula, um n�mero e um caractere especial: ");
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
            printf("\nSenha v�lida.\n");
        else if(aux_maiuscula==0 || aux_minuscula==0 || aux_nume==0 || aux_pont==0)
            printf("\n\nSenha inv�lida. Digite novamente.\n\n");
    }

    return 0;
}

