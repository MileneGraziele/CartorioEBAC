#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar dos string

int registro() //Função responsável por cadastrar os usuarios
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuario
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
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
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	char cpf[40];
    char conteudo[200];
	
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
  	
    FILE *file;
    file = fopen(cpf,"r");
  	
    if(file == NULL)
    {
    	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
    }
	
    while(fgets(conteudo, 200, file) != NULL)
{
	printf("\n Essas são as informações do usuario: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
system ("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!. \n");
		system("pause");	
	}
}



int main()
    {
    int opcao=0; //Definindo variáveis
    int laco=1;

    for(laco=1;laco=1;)
    {
    	
   	    system("cls"); // responsável por limpar a tela
   	  
	    setlocale(LC_ALL, "Portuguese"); //Definindo a Liínguagem
	
	    printf("\t CARTÓRIO DA EBAC \n\n"); //Início do menu
	    printf(" Como podemos te ajudar ?\n\n");
	    printf("\t1 - Quero registrar nomes\n");
 	    printf("\t2 - Quero consultar nomes\n");
	    printf("\t3 - Quero deletar nomes \n\n"); 
	    printf("Opcao: "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	    system("cls");
	  
	    switch(opcao)//inicio da opção
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
        printf("Está opção não está disponivel!\n");
	    system("pause");
	    break;
	  }	
	    
	  
	    
	  
    
	}
}

