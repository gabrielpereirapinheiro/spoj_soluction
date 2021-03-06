/*PROJETO E ANALISE DE ALGORITMOS 2017-1
 *ALUNO:GABRIEL PEREIRA PINHEIRO
 *MATRICULA: 14/0020764
*/

# include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


//Funcao que ira ordenadr
void quick_sort(long int vetor[],long int primeiro,long int ultimo)
{	
	//Iniciando variaveis
	long int inicio,fim;
	long int pivo,aux;
	//Definir parametros variaveis inferior
	inicio = primeiro;
	//Definir parametro variavel superior
	fim = ultimo;
	//Pivo e a metade
	pivo = vetor[(inicio+fim)/2];

	//Pecorrer limite delimitado
	while(inicio<=fim)
	{
		//	
		while(vetor[inicio] < pivo)
		{
			inicio=inicio+1;
		}
		while(vetor[fim]>pivo)
		{
			fim=fim-1;
		}
		if(inicio<=fim)
		{
			aux = vetor[inicio];
			vetor[inicio]=vetor[fim];
			vetor[fim]=aux;
			inicio = inicio + 1;
			fim = fim - 1;
		}
	}
	if (fim>primeiro)	
	{
		quick_sort(vetor,primeiro,fim);
	}
	if (inicio<ultimo)
	{
		quick_sort(vetor,fim+1,ultimo);
	}
}

//Funcao que ira mostrar vetor na tela
void show_vector(long int vetor[],int tamanho)
{	//Contador
	int i=0;
	//Pecorrer todo o vetor
	while(tamanho>i)
	{
		//Imprime
		printf("%ld\n",vetor[i]);
		//Incremente contador
		i++;
	}
}
void gera_vetor(long int vetor[],long int tamanho,int opcao)
{
	if (opcao==1)
	{
		for (long int i = 0; i < tamanho; ++i)
		{
			vetor[i]=tamanho-i;
		}
	}
	if(opcao==2)
	{
		for (long int i= 0; i < tamanho; ++i)
		{
			//O numero 5 foi escolhido ao acaso
			vetor[i]=1;
		}
	}
}

void inicio_tela()
{
	printf("\n===================");
	printf("\n  QUICK SORT");
	printf("\n==================\n");
}
int recebe_opcao()
{
	int opcao;

	printf("\nEscolha o estado do vetor inicial:");
	printf("\n1 - Decrescente\n");
	printf("2 - Todo preenchido com um numero\n");
	printf("-> ");
	scanf("%d",&opcao);

	while(opcao!=1 && opcao!=2)
	{
		printf("Escolha entre 1 ou 2\n");
		scanf("%d",&opcao);
	}
	return opcao;
}

void show_time(clock_t inicio,clock_t fim)
{	
	printf("\n\n============================================\n");
	printf("O tempo de execucao foi : %f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
	printf("============================================\n");
}

//Funcao principal
int main()
{
	//Tamanho maximo do vetor
	long int vetor[1000000];

	int size = 1000000;

	inicio_tela();

	int opcao = recebe_opcao();
	
	gera_vetor(vetor,size-1,opcao);
	//Tamanho e t-1 para nao acessar possicoes invalidas

	double last = size-1;
	clock_t inicio = clock();

	//Ordena vetor
	quick_sort(vetor,0,last);
		//Variavel para fim do tempo
	clock_t fim = clock();

	//Mostra o tempo
	show_time(inicio,fim);
	
	//Mostra vetor ordenado
	//show_vector(vetor,size);

}