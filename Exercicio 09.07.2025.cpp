#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos string

int registro() //Fun��o respons�vel por cadastrar os usuarios
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usuario
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
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
    }
	
    while(fgets(conteudo, 200, file) != NULL)
{
	printf("\n Essas s�o as informa��es do usuario: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
system ("pause");
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
    	
   	    system("cls"); // respons�vel por limpar a tela
   	  
	    setlocale(LC_ALL, "Portuguese"); //Definindo a Li�nguagem
	
	    printf("\t CART�RIO DA EBAC \n\n"); //In�cio do menu
	    printf(" Como podemos te ajudar ?\n\n");
	    printf("\t1 - Quero registrar nomes\n");
 	    printf("\t2 - Quero consultar nomes\n");
	    printf("\t3 - Quero deletar nomes \n\n"); 
	    printf("Opcao: "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	    system("cls");
	  
	    switch(opcao)//inicio da op��o
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
        printf("Est� op��o n�o est� disponivel!\n");
	    system("pause");
	    break;
	  }	
	    
	  
	    
	  
    
	}
}

