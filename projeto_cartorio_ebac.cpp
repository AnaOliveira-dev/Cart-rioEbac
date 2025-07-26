#include <stdio.h>//Biblioteca de comunicação com o usuário
#include <stddef.h>// biblioteca que valida nulo 
#include <stdlib.h>//biblioteca de alocação em espaço de memória
#include <string.h>//biblioteca de alocação de texto por região- lingua
#include <locale.h>//biblioteca responsável por criação de strings - sequencia de caracteres alfanuméricos

int adicionar()// função responsável por registro de nomes
{	
	setlocale(LC_ALL,"Portuguese");

	printf("Você escolheu Adicionar Cadastro!\n");
	system("pause");
	
	//inicio das strings
	char cpf[20];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char telefone[20];
	char arquivo[40];
	
	printf("Digite o CPF do novo cadastro:\n");// Coletando informações do usuário
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf);// Igualando o CPF ao arquivo, pois ele será a nossa primer key
	
	FILE*file;
	file=fopen(arquivo,"w");// "w" = write, pois o dado deve ser escrito
	fprintf(file,cpf);
	fclose(file);
	
	file=fopen(arquivo,"a");//"a"= add, uma informação vai ser adicionada
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
	
	
	
	system("pause");// pausar a tela para o usuário conseguir ler.
	
}
int consultar()
{ 	
	setlocale(LC_ALL,"Portuguese");//Definindo linguagem em português novamente
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE*file;
	file=fopen(cpf,"r");// r= read, pois irá apenas ler os dados já salvos
	
	if(file==0)// caso não encontre nenhum arquivo com o cpf a ser consultado
	{ 
	printf("Cadastro não localizado\n");
	}
	
	while(fgets(conteudo,200,file)!=0) // enquanto se encontrar dados sobre o cadastro consultado, esses dados serão mostrados abaixo, após a mensagem
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
		
		remove(cpf);// irá apagar o cpf  arquivado no banco de dados
		
		FILE*file;
		file=fopen(cpf,"r");
		
		if (file== 0);
		{ 
			printf ("O usuário não se encontra no sistema!\n");
			system("pause");
		}
	
}

int main ()// chama a função principal e parenteses mostra para o computador que isso é uma função. Letras minúsculas
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
 		setlocale(LC_ALL,"Portuguese");// define Português como lingua padrão. Sempre colocar ; para encerrar o comando. O espaço antes de cada função dentro da intmain se chama Identação e serve para deixar o código mais limpo

 		printf ("\tBem vindo ao Registro EBAC.\n\n");// Printf traz o texto pro usuário.Os " determinam o que é o texto.\t dá um espaço.\n pula linha
 		printf ("Para iniciar, escolha o que deseja fazer:\n");
 		printf ("\t1.Adicionar cadastro\n");
 		printf ("\t2.Consultar cadastro\n");
 		printf ("\t3.Excluir cadastro \n");
 		printf ("\t4.Sair do sistema\n\n");
 		printf ("\tEscolha uma das opções: ");
 			scanf ("%d",&opcao);// armazenar as variáveis no computador	
 			system ("cls"); // comunica com o windows para limpar a tela para o usuário
 
 				switch (opcao)// início da seleção
 				{	case 1:
 					adicionar();//chamada de função
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
			
					default://prevenção caso o usuário escolha uma opção errada;
					printf ("Essa opção não é valida. Por favor, escolha uma das opções disponíveis.\n");
					system ("pause");
				}
		}
	}
	else
	printf("Senha incorreta!");	
}
