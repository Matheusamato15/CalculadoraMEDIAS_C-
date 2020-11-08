#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>

#define TAM_MATERIA 30
#define TAM_NOTAS 50
#define TAM_LOGIN 10

using namespace std;

void entrada()
{
	cout << endl;
	cout << "		BEM VINDO(A), CALCULADORA DE NOTAS DA UEG CRIADA POR MATHEUS AMATO, VERSÃO 5 :) " << endl;
	cout << "					Pressione Enter para continuar.\n" << endl;
	system("pause>>null");
	system("cls");
}
//---------------------------------------FUNÇÃO DO MENU
int menu()
{
	int Opcao;
	
	cout << endl;
	cout << "					O que você deseja?" << endl << endl;
	cout << "1-) Calcular Restante de nota" << endl;
	cout << "2-) Calcular Média final" << endl;
	cout << "3-) Apresentar arquivo Restante" << endl;
	cout << "4-) Apresentar arquivo Media Final" << endl;
	cout << "5-) Sair" << endl;
	cout << "> ";	
	cin >> Opcao;
	
	return Opcao;
}

//---------------------------------------FUNÇÃO PARA CALCULAR RESTANTE DE NOTA
void restante(FILE *ArquivoRestante)
{
	float Restante, PrimeiraNota;
	char Materia[TAM_MATERIA], Opcao;
	
	ArquivoRestante=fopen("Restante.txt", "a"); fflush (stdin);
	
	do
	{	
		cout << "--------------------------------" << endl;
		cout <<" Ambiente 1: Restante de nota" << endl;
		cout << "--------------------------------" << endl; fflush (stdin);
		
		//ENTRADA DE DADOS
		fprintf(ArquivoRestante, "Matéria\t\tPrimeira VA\tNota necessária\n\n");
		cout << "\nDigite o nome da matéria desejada: ";
		gets(Materia); fflush (stdin);
	
		cout << "\nDigite sua nota da Primeira VA (Utilize '.' ao invés de ','): ";
		cin >> PrimeiraNota;
	
		//CALCULO DO RESTANTE DE NOTA
		Restante=(30.0-(PrimeiraNota*2.0))/3.0;
	
		//SAÍDA DE DADOS PARA A TELA DO COMPUTADOR
		printf("\nVocê precisa de %.1f para passar em %s.\n", Restante, Materia);
		
		//SAÍDA DE DADOS PARA CALCULADOS PARA O ARQUIVO
		fprintf(ArquivoRestante, "%s\t\t%.1f\t\t%.1f\n", Materia, PrimeiraNota, Restante);
		
		system("Pause >> null");
		system("cls");
		
		cout << "\nDeseja realizar outra conta? Sim[S], Não[N]" << endl;
		cin >> Opcao;
		Opcao=toupper(Opcao);
		system("cls");
	}
	while(Opcao!='N');
	
	fclose(ArquivoRestante);
	
	system("cls");
	cout << "\nVocê retornará ao menu principal..." << endl;
	system("Pause>>null");
	system("cls");
}

//---------------------------------------FUNÇÃO PARA CALCULAR MÉDIA FINAL
void mediafinal(FILE *ArquivoMedia)
{
	char Materia[TAM_MATERIA], Opcao;
	float Media, Notas[2];
	
	ArquivoMedia=fopen("Media.txt", "a"); fflush(stdin);
	
	do
	{
		cout << "--------------------------------" << endl;
		cout << " Ambiente 2: Média final" << endl;
		cout << "--------------------------------" << endl; fflush (stdin);
		
		//ENTRADA DE DADOS
		fprintf(ArquivoMedia, "Matéria\t\tPrimeira VA\tSegunda VA\tMediaFinal\n\n");
		cout << "\nDigite o nome da matéria: ";
		gets(Materia); fflush(stdin);
		
		cout << "\nDigite sua primeira nota: ";
		cin >> Notas[0];
		
		cout << "\nDigite sua segunda nota: ";
		cin >> Notas[1];
		
		//CÁLCULO DA MÉDIA
		Media=(Notas[0]*2 + Notas[1]*3) / 5;
		
		//SAÍDA DE DADOS NA TELA DO COMPUTADOR
		printf("\nSua média final em %s é de: %.1f", Materia, Media);
		
		//SAÍDA DE DADOS NO ARQUIVO
		fprintf(ArquivoMedia, "%s\t\t%.1f\t\t%.1f\t\t%.1f\n", Materia, Notas[0], Notas[1], Media);
		
		system("Pause >> null");
		system("cls");
		
		cout << "\nDeseja realizar outra conta? Sim[S], Não[N]" << endl;
		cin >> Opcao;
		Opcao=toupper(Opcao);
		system("cls");
	}
	while(Opcao!='N');
	
	fclose(ArquivoMedia);
	
	system("cls");
	cout << "\nVocê retornará ao menu principal..." << endl;
	system("Pause>>null");
	system("cls");
}

//---------------------------------------FUNÇÃO PARA MOSTRAR ARQUIVO RESTANTE
void mostrarrestante(FILE *ArquivoRestante)
{
	char Caracter;
	
	ArquivoRestante=fopen("Restante.txt", "r");
	
	cout << "----------------------------------------" << endl;
	cout << " Ambiente 3: Apresentar arquivo Restante" << endl;
	cout << "----------------------------------------" << endl; fflush (stdin);
	cout << endl;
	
	while((Caracter=fgetc(ArquivoRestante)) != EOF)
	{
		cout << Caracter;
	}
	
	fclose(ArquivoRestante);
	
	system("pause>>null");
	system("cls");
	cout << "\nVocê retornará ao menu principal..." << endl;
	system("Pause>>null");
	system("cls");
}

//---------------------------------------FUNÇÃO PARA MOSTRAR ARQUIVO MÉDIA
void mostrarmedia(FILE *ArquivoMedia)
{
	char Caracter;
	
	ArquivoMedia=fopen("Media.txt", "r");
	
	cout << "-------------------------------------------" << endl;
	cout << " Ambiente 4: Apresentar arquivo Media Final" << endl;
	cout << "-------------------------------------------" << endl; fflush (stdin);
	cout << endl;
	
	while((Caracter=fgetc(ArquivoMedia)) != EOF)
	{
		cout << Caracter;
	}
	
	fclose(ArquivoMedia);
	
	system("pause>>null");
	system("cls");
	cout << "\nVocê retornará ao menu principal..." << endl;
	system("Pause>>null");
	system("cls");
}

int main ()
{
	//Declaração de parte das variáveis usadas no programa
	FILE *ArquivoRestante, *ArquivoMedia, *ArquivoSenha;
	int Retorno;
	char Opcao;
	
	//Mudando prompt para aceitar acentos em UTF-8
	unsigned int cp = 1252; //Codepage latin2

	//Salvando o codepage original da consola
	unsigned int cpin  = GetConsoleCP();
	unsigned int cpout = GetConsoleOutputCP();
    
	SetConsoleCP(cp);       //Estabelecendo o codepage de entrada 1252(latin2)
	SetConsoleOutputCP(cp);  //Estabelecendo o codepage de saída 1252(latin2)
	
	//Fim mudando prompt para aceitar acentos em UTF-8
	
	setlocale(LC_ALL, "Portuguese");
	system("title Calculadora 5");
	
	entrada();
	
	do
	{
		Retorno = menu();
		
		if(Retorno<1 || Retorno>5)
		{
			cout << "Opção incorreta, tente novamente!" << endl;
			system("Pause>>null");
			system("cls");
		}
		
		switch(Retorno)
		{
			//CASO PARA CALCULAR RESTANTE DE NOTA
			case 1:
				system("cls");
				restante(ArquivoRestante);
				break;
			case 2:
				system("cls");
				mediafinal(ArquivoMedia);
				break;
			case 3:
				system("cls");
				mostrarrestante(ArquivoRestante);
				break;
			case 4:
				system("cls");
				mostrarmedia(ArquivoMedia);
				break;
		}

	}
	while(Retorno!=5);
	
	//Retornando prompt codepage para original
	SetConsoleCP(cpin);
	SetConsoleOutputCP(cpout);
	
	return 0;
}

