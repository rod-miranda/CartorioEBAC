#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{	
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo e o "w" = escrever
	fprintf(file,"CPF: ");
	fprintf(file,cpf); // Salva o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,"\nNome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\nSobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\nCargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Defini��o da linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: \n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	printf("\nInforma��es do usu�rio: \n\n");
		
	if(file == NULL)
	{
		printf("\nN�o foi poss�vel localizar essa informa��o no banco de dados.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s",conteudo);
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Defini��o das vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //respons�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //defini��o da linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o:\n\n"); //T�rmino do menu
	
		scanf("%d", &opcao); //Armazenamento da escolha do usu�rio
	
		system("cls");
		
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n\n");
			system("pause");
			break;
		}	//fim da sele��o
	}
}
