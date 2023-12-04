#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40]; // entre colhetes o 40 criando uma string do tipo 40
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário(nome do arquivo vai ser o cpf)
	scanf("%s", cpf); // %s refere-se a string (Armazenando dentro da string cpf)
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo na pasta onde esta salvo o sistema "w" significa escrever
	fprintf(file,cpf); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
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
	scanf("%s",sobrenome);
	
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

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem - ler acentos
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // r = ler
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
		
	while(fgets(conteudo, 200, file) != NULL)	//while = enquanto
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");	
		
	}		
	
	system("pause");
		
}
		
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); // remove:função que acessa automaticamente a pasta principal e deleta o arquivo que foi pedido.
	
	FILE *file; //FILE (consultar):"acessar a fução FILE na biblioteca" - *file: acessar o parametro "arquivo"
	file = fopen(cpf,"r"); // fopen=> função de abrir - "r"=> ler
	
	if(file == NULL) // NULL=> NULO
	{
		printf("O usuário não se encontra no sistema!.\n");
		printf("Deletado com sucesso!.\n");
     	system("pause");
		}	
}

int main()
{
	int opcao=0;//Definição variáveis
	int laco=1;//Definição variáveis
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo da linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("opcao:\n\n"); //fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
		
		
		switch(opcao) //inpicio da seleção do menu
		{
			case 1:
		    registro(); //chamada de funções
			break;
			
			case 2:
			consultar(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			default:
			printf("essa opcão não está disponível\n");
			system("pause");
			break;
			// fim da seleção
		}
	
	}

}

