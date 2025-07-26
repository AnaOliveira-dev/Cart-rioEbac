#include <stdio.h>//Biblioteca de comunica��o com o usu�rio
#include <stddef.h>// biblioteca que valida nulo 
#include <stdlib.h>//biblioteca de aloca��o em espa�o de mem�ria
#include <string.h>//biblioteca de aloca��o de texto por regi�o- lingua
#include <locale.h>//biblioteca respons�vel por cria��o de strings - sequencia de caracteres alfanum�ricos

int adicionar()// fun��o respons�vel por registro de nomes
{	
	setlocale(LC_ALL,"Portuguese");

	printf("Voc� escolheu Adicionar Cadastro!\n");
	system("pause");
	
	//inicio das strings
	char cpf[20];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char telefone[20];
	char arquivo[40];
	
	printf("Digite o CPF do novo cadastro:\n");// Coletando informa��es do usu�rio
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf);// Igualando o CPF ao arquivo, pois ele ser� a nossa primer key
	
	FILE*file;
	file=fopen(arquivo,"w");// "w" = write, pois o dado deve ser escrito
	fprintf(file,cpf);
	fclose(file);
	
	file=fopen(arquivo,"a");//"a"= add, uma informa��o vai ser adicionada
	fprintf(file, "\n nome:");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:\n");
	scanf("%s",nome);
	
	file=fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:\n");
	scanf("%s",sobrenome);
	
	file=fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file, "\n cargo:");
	fclose(file);
	
	printf("Digite o cargo do cadastrado:\n ");
	scanf("%s",cargo);
	
	file=fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	printf("Digite o contato do novo cadastro:");
	scanf("%s", telefone);
	
	file=fopen(arquivo,"a");
	fprintf(file, "\n telefone:");
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,telefone);
	fclose(file);
	
	
	
	system("pause");// pausar a tela para o usu�rio conseguir ler.
	
}
int consultar()
{ 	
	setlocale(LC_ALL,"Portuguese");//Definindo linguagem em portugu�s novamente
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE*file;
	file=fopen(cpf,"r");// r= read, pois ir� apenas ler os dados j� salvos
	
	if(file==0)// caso n�o encontre nenhum arquivo com o cpf a ser consultado
	{ 
	printf("Cadastro n�o localizado\n");
	}
	
	while(fgets(conteudo,200,file)!=0) // enquanto se encontrar dados sobre o cadastro consultado, esses dados ser�o mostrados abaixo, ap�s a mensagem
	{	
		printf("\n");
		printf("%s",conteudo);
		printf("\n\n");
	
	}

	system("pause");
}
int excluir()
{		char cpf[20];
		printf("Digite o CPF a ser deletado: \n");
		scanf("%s", cpf);
		
		remove(cpf);// ir� apagar o cpf  arquivado no banco de dados
		
		FILE*file;
		file=fopen(cpf,"r");
		
		if (file== 0);
		{ 
			printf ("O usu�rio n�o se encontra no sistema!\n");
			system("pause");
		}
	
}

int main ()// chama a fun��o principal e parenteses mostra para o computador que isso � uma fun��o. Letras min�sculas
{
		int laco=1;
		char senhadigitada[15]= "a";
		int comparacao;
		
		printf("\t Registro EBAC\n\n");
		printf("\tLogin de administrador\n\nDigite sua senha: ");
		scanf("%s",senhadigitada);
		
		comparacao= strcmp(senhadigitada, "admin");
		
	if(comparacao == 0)
	{
		system ("cls");
		for (laco=1; laco=1;)
		{		
		int opcao=0;
 		setlocale(LC_ALL,"Portuguese");// define Portugu�s como lingua padr�o. Sempre colocar ; para encerrar o comando. O espa�o antes de cada fun��o dentro da intmain se chama Identa��o e serve para deixar o c�digo mais limpo

 		printf ("\tBem vindo ao Registro EBAC.\n\n");// Printf traz o texto pro usu�rio.Os " determinam o que � o texto.\t d� um espa�o.\n pula linha
 		printf ("Para iniciar, escolha o que deseja fazer:\n");
 		printf ("\t1.Adicionar cadastro\n");
 		printf ("\t2.Consultar cadastro\n");
 		printf ("\t3.Excluir cadastro \n");
 		printf ("\t4.Sair do sistema\n\n");
 		printf ("\tEscolha uma das op��es: ");
 			scanf ("%d",&opcao);// armazenar as vari�veis no computador	
 			system ("cls"); // comunica com o windows para limpar a tela para o usu�rio
 
 				switch (opcao)// in�cio da sele��o
 				{	case 1:
 					adicionar();//chamada de fun��o
		 			break;
		 	
		 			case 2:
		 			consultar();
					break;
			
					case 3:
					excluir();
					break;
					
					case 4:
					printf("Obrigado por utilizar o sistema.");
					return 0;
					break;
			
					default://preven��o caso o usu�rio escolha uma op��o errada;
					printf ("Essa op��o n�o � valida. Por favor, escolha uma das op��es dispon�veis.\n");
					system ("pause");
				}
		}
	}
	else
	printf("Senha incorreta!");	
}
