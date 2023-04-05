#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h>	//Biblioteca para armazezar var string
int registro()
//Cria fun��o para chamar posteriormente
//fun��o reponsavel por cadastrar os usu�rios no sistema			
{
	//Cria��o de variaveis string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado \t ");// coletando informa��es do usu�rio 
	scanf("%s", cpf);//%s armazena a variavel string
	
	strcpy(arquivo, cpf);//Copia valores das strings
	
	FILE *file;// Cria um arquivo 
	file = fopen(arquivo, "w");// cria um arquivo na pasta do sistema  do tipo (write)
	fprintf(file, cpf);//salva o valor da variavel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza o sistema (a)
	fprintf(file,",");
	fclose(file);
	
	printf("\t Digite o nome a ser cadastrado: ");
	scanf("%s" ,nome);
	
	file = fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\t Digite um sobrenome a ser cadastrado: ");
	scanf("%s" , sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite um cargo a ser cadastrado: ");
	scanf("%s" ,cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);




	system("pause");	
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Arquivo n�o localizado \n");
	}
	
	while(fgets(conteudo,200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	}
int deletar()
{
	char cpf[40];
	
	printf("\n Digite o CPF do usu�rio a ser Deletado");
	scanf("%s",cpf);//le o que o usuario colocou e armazena como (%s)string 
	remove(cpf);//Deleta a parte escolhida
	
	FILE *file;//Usa a Biblioteca FILE para usar o arquivo file
	file = fopen(cpf,"r");//usa o arquivo file para abrir o proprio e ler (read)
	
	if (file != NULL);//se o cpf informado for igual a NULL fa�a isso
	{
		fclose(file);
		remove(cpf);
		printf("\n");
		printf("O usu�rio foi deletado com sucesso \n");//Avisa pro usuario /n(Da espa�o)
		printf("____________________________________\n\n\n");
		system("pause");//Pausa o sistema para o usuario ler			
	}
		
	}	
int main()
{
	int opcao=0;//Definindo variavel
	int laco=1;
	char senhadigitada[10]="a";
	
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de ADM!\n\nDigite a sua senha:");
	scanf("%s",senhadigitada);
	if(senhadigitada == "admin");
	{
	for(laco=1;laco=1;)
	{
		system("cls");//limpa a tela
		
		setlocale(LC_ALL, "Portuguese");
		printf("### Cart�rio da EBAC ###\n\n");//(##) Foi utilizado para dar um espa�o  (/n) Foi utilizado para pular linha 
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registar nomes\n");// (\t) foi utilizado para que o programa de um espa�o
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - -Deletar nomes\n");
		printf("\t4 - Sair do sistema\n");
		printf("Op��o: ");
	
		scanf("%d", &opcao);//Le o que o usuario disse e armazena na variavel %d=int
		system("cls");//Limpa a tela do usuario
		
		switch(opcao)//switch permite criar op��es 
		{
			case 1:
			registro();//chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;

            case 4:
            printf("Obrigado por usar esse sistema\n");
            return 0;//Quebra o sistema (Fecha)
            break;
            			
			default:
			printf("Vo�e digitou Essa op��o n�o esta disponivel\n");
			system("pause");
			break;
				
		
			}
			printf("\nEsse Softare foi feito por Alexandre Rangel De Souza");
		}
	}
	if(senhadigitada  != "admin");
	{
		printf("Senha incorreta");
	}
	
}	
		
		
