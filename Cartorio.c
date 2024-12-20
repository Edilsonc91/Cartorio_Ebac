#include <stdio.h> //Biblioteca de comunicação do usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastrar usuários no sistema
{
	//Inicio de criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variável
	
	printf("Digite CPF a ser cadastro: "); //Coletando informação do usuário
	scanf("%s", cpf); // %S refere-se a string
	
	strcpy(arquivo, cpf); // Reponsável por copiar valores da string
	
	FILE *file; //Cria o arquivo no banco
	file = fopen(arquivo, "w"); // criar o arquivo na pasta do sistema e o "W" siginifica escrever(write)
	fprintf(file,cpf); // Salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	
	setlocale (LC_ALL, "Portuguese"); //Definido a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s:", conteudo);
		printf("\n\n");		
	} 
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		
		
	}
	
	
	
}
	
int main()
{
	int opcao=0; //Definindo as variavés
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
	  setlocale (LC_ALL, "Portuguese"); //Definido a linguagem
	
	  printf("### Cartório da EBAC ###\n\n"); //Inicio do Menu
	  printf("Escolha a opção desejada do Menu:\n\n");
	  printf("\t1 - Registrar Nomes\n");
	  printf("\t2 - Consultar Nomes\n");
	  printf("\t3 - Deletar Nomes\n\n"); 
	  printf("Opção que você deseja: ");//Final do menu
	
		scanf("%d", &opcao); //Scanf: escanear o que o usuário coloca. Armazenar variavel do tipo inteiro-'%d'. "&" local onde vai ser armazenado a informação.
	
		system("cls"); // Comando de sistema. Comando "CLS" - limpar a tela
		
		
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro();//chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			
			default:
			printf("Opção não está disponível!\n");
			system("pause");
			break;	
				
		}
		
   }	
}
