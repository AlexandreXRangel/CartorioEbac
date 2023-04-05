#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h>	//Biblioteca para armazezar var string
int registro()
//Cria função para chamar posteriormente
//função reponsavel por cadastrar os usuários no sistema			
{
	//Criação de variaveis string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado \t ");// coletando informações do usuário 
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
		printf("Arquivo não localizado \n");
	}
	
	while(fgets(conteudo,200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	}
int deletar()
{
	char cpf[40];
	
	printf("\n Digite o CPF do usuário a ser Deletado");
	scanf("%s",cpf);//le o que o usuario colocou e armazena como (%s)string 
	remove(cpf);//Deleta a parte escolhida
	
	FILE *file;//Usa a Biblioteca FILE para usar o arquivo file
	file = fopen(cpf,"r");//usa o arquivo file para abrir o proprio e ler (read)
	
	if (file != NULL);//se o cpf informado for igual a NULL faça isso
	{
		fclose(file);
		remove(cpf);
		printf("\n");
		printf("O usuário foi deletado com sucesso \n");//Avisa pro usuario /n(Da espaço)
		printf("____________________________________\n\n\n");
		system("pause");//Pausa o sistema para o usuario ler			
	}
		
	}	
int main()
{
	int opcao=0;//Definindo variavel
	int laco=1;
	char senhadigitada[10]="a";
	
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de ADM!\n\nDigite a sua senha:");
	scanf("%s",senhadigitada);
	if(senhadigitada == "admin");
	{
	for(laco=1;laco=1;)
	{
		system("cls");//limpa a tela
		
		setlocale(LC_ALL, "Portuguese");
		printf("### Cartório da EBAC ###\n\n");//(##) Foi utilizado para dar um espaço  (/n) Foi utilizado para pular linha 
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registar nomes\n");// (\t) foi utilizado para que o programa de um espaço
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - -Deletar nomes\n");
		printf("\t4 - Sair do sistema\n");
		printf("Opção: ");
	
		scanf("%d", &opcao);//Le o que o usuario disse e armazena na variavel %d=int
		system("cls");//Limpa a tela do usuario
		
		switch(opcao)//switch permite criar opções 
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

            case 4:
            printf("Obrigado por usar esse sistema\n");
            return 0;//Quebra o sistema (Fecha)
            break;
            			
			default:
			printf("Voçe digitou Essa opção não esta disponivel\n");
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
		
		
