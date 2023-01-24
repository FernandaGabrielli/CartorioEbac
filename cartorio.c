#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema 
{
	//Inic�o da cria��o das variav�is/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//Fim da cria��o das variav�is/string

	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf ("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Abre e w escreve no arquivo, refere-se a write
	fprintf(file,cpf); //salva  valor da variavel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,",");  //salva  valor da variavel
	fclose(file);   //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf ("%s", nome);
	
	file = fopen(arquivo, "a"); //Abre o arquivo 
	fprintf(file, nome);  //salva  valor da variavel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //Abre o arquivo
	fprintf(file,","); //salva  valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf ("%s", sobrenome);
	
	file = fopen(arquivo, "a");  //Abre o arquivo
	fprintf(file, sobrenome);  //salva  valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,","); //salva  valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf ("%s", cargo);
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file, cargo); //salva  valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,","); //salva  valor da variavel
	fclose(file); //fecha o arquivo
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

	char cpf[40]; //Armazenar um caractere
	char conteudo[200];//Armazenar um caractere
	
	printf("Digite o CPF  a se consultado: "); //Solicitar os dados
	scanf("%s", cpf); //Ler os dados
	
	FILE *file; //Cria o arquivo
	file  = fopen(cpf,"r");//Abre o arquivo
	
	if(file == NULL) //Mensagem caso haja erro
	{
		printf ("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Mensagem de retorno positivo
{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
}
	system("pause"); //Pausa para aparecer as mensagens
}

int deletar()
{
	char cpf[40];//Armazenar um caractere
	
	printf("Digite  CPF a ser deletado: ");//Solicitar os dados
	scanf("%s",cpf);//Ler os caracteres
		
	remove(cpf); //Apagar o dado que foi informado
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo
	
	if(file == NULL) //Mensagem caso 
	{
		printf("O usu�rio n�o se encontra no sistema!. \n");
		system("pause");
	}
	
	
}

int main()
{
	
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("###Cart�rio da EBAC###\n\n"); //Inicio do menu
		printf("Escolha a op��o que voc� deseja hoje:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");  
		printf("Op��o: "); //Fim do menu
		
		scanf("%d", &opcao);  //Armazenando a escolha do usu�rio 
	
		system("cls");
		
		switch(opcao) //Inicio da Selecao
	{
			case 1:
			registro();
			break;
				
			case 2:
			consulta();			
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");	
			break;
			
		} //Fim da Sele��o
		
	}
	
}
