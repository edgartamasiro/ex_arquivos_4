/*---------------------------------------------------------------------------------------------------------------------------------------------------------------
	T�tulo: Exerc�cios sobre manipula��o de arquivos bin�rios (abertura, leitura, escrita e fechamento)

	Autor: Edgar Hideo Tamasiro
	Data: fevereiro de 2022
	Vers�o: 1.0
	
---------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

/* Constantes */
/*const*/
/*#define*/

/* Macros */
/*#define*/

/* Declara��o de vari�veis globais */

/* Prot�tipo das fun��es secund�rias */
void gerarDelay();


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* In�cio da fun��o principal */
main(int argc, char *argv[])
{
	FILE *arqCelsius;
	register int i;
	float vetorLog[10];

	/* execu��o do programa pela primeira vez, onde ele verifica se o arquivo existe, e se n�o existir cria-o */
	arqCelsius = fopen("celsius.dat", "rb");
	if (arqCelsius == NULL)
		{
			fclose(arqCelsius);
			printf("Arquivo de log inexistente. Gerando o arquivo e gravando 10 primeiros valores.\n");
			gerarDelay();
			arqCelsius = fopen("celsius.dat", "wb");
			if (arqCelsius == NULL)
				{
					printf("Erro_wb\n");
					gerarDelay();
					exit(1);
				}
			for (i = 0; i < 10; i++)
				{
					printf("Valor %d em Celsius: ", i+1);
					scanf("%f", &vetorLog[i]);
				}
			fwrite(vetorLog, sizeof(float), 10, arqCelsius);
			fclose(arqCelsius);
			gerarDelay();
			printf("OK\n");
			exit(2);
		}
	/* execu��o do programa a partir da segunda vez */
	/* o arq datalogger existe, ir� abri-lo, ler valores anteriores */
	fread(vetorLog, sizeof(float), 10, arqCelsius);
	printf("Valores anteriores:\n");
	for (i = 0; i < 10; i++)
		printf("%.2f graus Celsius\n", vetorLog[i]);
	putchar('\n');
	fclose(arqCelsius);
	
	/* ir� atualizar com dez valores novos */
	arqCelsius = fopen("celsius.dat", "wb");
	if (arqCelsius == NULL)
		{
			printf("Erro_wb2\n");
			gerarDelay();
			exit(3);
		}
	for (i = 0; i < 10; i++)
		{
			printf("Valor %d em Celsius: ", i+1);
			scanf("%f", &vetorLog[i]);
		}
	fwrite(vetorLog, sizeof(float), 10, arqCelsius);
	fclose(arqCelsius);
	printf("Novos valores adicionados\n");
	
	system("PAUSE");					/*pausa execu��o*/
	return 0;						/*retorna 0, se main() for executada*/
	
	
}
/* Fim da fun��o principal */

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Desenvolvimento das fun��es secund�rias */

/* --- Fun��o para... --- */

/* --- Fun��o para gerar delay --- */
void gerarDelay()
{
	register long timer;
	for (timer = 0; timer < 1E9; timer++);
}

/*-------------------------------------------------------------------------------

                                                              
                                       _                      
                                      / \                     
                                     |oo >                    
                                     _\=/_                    
                    ___         #   /  _  \   #               
                   /<> \         \\//|/.\|\\//                
                 _|_____|_        \/  \_/  \/                 
                | | === | |          |\ /|                    
                |_|  0  |_|          \_ _/                    
                 ||  0  ||           | | |                    
                 ||__*__||           | | |                    
                |* \___/ *|          []|[]                    
                /=\ /=\ /=\          | | |                    
________________[_]_[_]_[_]_________/_]_[_\_______________________________
                                                              
MAY THE FORCE BE WITH YOU! :)
-------------------------------------------------------------------------------*/
/* Final do projeto */

/* Rascunho */

	/*fflush(stdin);*/		/* esta fun��o limpa a buffer do teclado, semelhante ao 'espa�o antes do %c' */
	/*scanf(" %c", &opcao);*/
	/*getchar();*/			/* esta fun��o capta um caractere do teclado, semelhante ao scanf' */

	/*printf("Digite o primeiro numero: ");
	scanf("%d", &numero1);
	printf("\n");*/

	/*for( ; ; )*/				/*loop*/

	/*register long timer;*/						/*vari�vel para delay p/ ser poss�vel visualizar a msg*/
	/*for(timer = 0; timer < 1E8; timer++);*/		/*delay*/

