/*--------------------------------Bibliotecas----------------------------------------------------------------------*/
#include <iostream>
using namespace std;
#include <conio.h>

/*--------------------------------Constantes-----------------------------------------------------------------------*/
#define MIN_IDADE_CADASTRO 0
#define MAX_IDADE_CADASTRO 120
#define MIN_IDADE_GRAVIDEZ 10
#define MIN_PESO_CADASTRO 0
#define MAX_PESO_CADASTRO 450
#define SEXO_AMBOS 'A'
#define SEXO_FEM 'F'
#define SEXO_MASC 'M'
#define QTD_VACINAS 18


/*--------------------------------Structs--------------------------------------------------------------------------*/
typedef struct Pessoa{
	string nome;
	int idade;
	float peso;
	char sexo;
	bool gestante;
}Pessoa;

typedef struct Vacina{
	string nome, descricao;
	int qtdDoses, idadeMin, idadeMax;
	float pesoMin, pesoMax; 
	char sexo;
	bool gestante;
}Vacina;


/*--------------------------------Funções--------------------------------------------------------------------------*/
//Funcao para esperar o usario digitar enter para prosseguir
void continuar()
{
	cout<< endl << "Pressione qualquer tecla para continuar" << endl << endl;
	getch();
	system("cls");
}
void exibeArte() 
{
	cout << "\a" <<  " __      __                 _                                    " << endl;
	cout <<  " \\ \\    / /                (_)             /\\                    " << endl;
	cout <<  "  \\ \\  / /    __ _    ___   _   _ __      /  \\     _ __    _ __  " << endl;
	cout <<  "   \\ \\/ /    / _` |  / __| | | | '_ \\    / /\\ \\   | '_ \\  | '_ \\ " << endl;
	cout <<  "    \\  /    | (_| | | (__  | | | | | |  / ____ \\  | |_) | | |_) |" << endl;
	cout <<  "     \\/      \\__,_|  \\___| |_| |_| |_| /_/    \\_\\ | .__/  | .__/ " << endl;
	cout <<  "                                                  | |     | |    " << endl;
	cout <<  "                                                  |_|     |_|    " << endl;
	cout <<  ".     |___________________________________                            " << endl;
	cout <<  "|-----|- - -|''''|''''|''''|''''|''''|'  \\|__                         " << endl;
	cout <<  "|- -  |  cc 6    5    4    3    2    1     __]==-----------------" << endl;
	cout <<  "|-----|__________________________________/|                           " << endl;
	cout <<  "'     |                                                               " << endl << endl;
}

//funcao para receber dados do usuario
Pessoa dados(Pessoa *usuario)//Funçao do tipo pessoa que recebe como parametro de entrada um ponteiro do tipo pessoa
{	
	(*usuario).gestante = 0;
	char gestante;//Criação de uma variavel char para perguntar se o usuario é gestante

//Arte do app
	
	exibeArte();
	
	cout << "+----------------------------------------------------------------+" << endl;
	cout << "|                                                                |" << endl;
	cout << "|                           CADASTRO                             |" << endl;
	cout << "|                                                                |" << endl;
	cout << "|    Digite seus dados                                           |" << endl;
	
	do{
		cout << "|                                                                |" << endl;
		cout << "|    Nome:                                                       |" << endl;
		cout << "|    " ;
		getline(cin, (*usuario).nome);//Recebendo o nome do usuario
		if((*usuario).nome == "")//Se o usuario nao inserir um nome ele é avisado q o valor é invalido e precisa inserir novamente
		{
			cout << "|                                                                |" << endl;
			cout << "\a|    !! Voce inseriu um valor invalido! Tente novamente. !!      |" << endl;
		}
			
	}while((*usuario).nome == "");
	
	
	
	do{
		cout << "|                                                                |" << endl;
		cout << "|    Idade:                                                      |" << endl;
		cout << "|    " ;
		cin >> (*usuario).idade; //Recebendo a idade do usuario
		//Se a idade do usuario for menor que a minima para cadastro ou maior que a maxima ele é avisado q o valor é invalido e precisa inserir novamente
		if((*usuario).idade <  MIN_IDADE_CADASTRO || (*usuario).idade > MAX_IDADE_CADASTRO)
		{
			cout << "|                                                                |" << endl;
			cout << "\a|    !! Voce inseriu um valor invalido! Tente novamente. !!      |" << endl;
		}
	}while((*usuario).idade <  MIN_IDADE_CADASTRO || (*usuario).idade > MAX_IDADE_CADASTRO);
	
	do{
		cout << "|                                                                |" << endl;
		cout << "|    Peso:                                                       |" << endl;
		cout << "|    " ;
		cin >> (*usuario).peso;//Recebendo o peso do usuario 
		//Se o peso do usuario for menor que o minimo para cadastro ou maior que o maxima ele é avisado q o valor é invalido e precisa inserir novamente
		if((*usuario).peso < MIN_PESO_CADASTRO || (*usuario).peso > MAX_PESO_CADASTRO)
		{
			cout << "|                                                                |" << endl;
			cout << "\a|    !! Voce inseriu um valor invalido! Tente novamente. !!      |" << endl;
		}
	}while ((*usuario).peso < MIN_PESO_CADASTRO || (*usuario).peso > MAX_PESO_CADASTRO);
	
	do{
		cout << "|                                                                |" << endl;
		cout << "|    Sexo (M/F):                                                 |" << endl;
		cout << "|    " ;
		cin >> (*usuario).sexo;//Lendo o sexo do usuario
		(*usuario).sexo = toupper((*usuario).sexo);//Forçando o caractere a ser Maiusculo
		//Se o sexo for diferente de M ou N o usuario é avisado que o dado inserido é invalido e precisa inserir novamente
		if(not((*usuario).sexo == 'M' || (*usuario).sexo == 'F'))
		{
			cout << "|                                                                |" << endl;
			cout << "\a|    !! Voce inseriu um valor invalido! Tente novamente. !!      |" << endl;
		}		
	}while(not((*usuario).sexo == 'M' || (*usuario).sexo == 'F'));

	//Se o usuario for do sexo feminino e possuir a idade maior ou igual o minimo para gravidez é perguntado se a usuaria está gravida
	if((*usuario).sexo == 'F' && (*usuario).idade > MIN_IDADE_GRAVIDEZ)
	{
		do
		{
			cout << "|                                                                |" << endl;
			cout << "|    Voce eh gestante? (S/N):                                    |" << endl;
			cout << "|    " ;
			cin >> gestante;//Recebendo a resposta do usuario se está gestante ou nao
			gestante = toupper(gestante);//Forçando o caractere a ser Maiusculo
			//Se o usuario inserir algo diferente de S ou N ele é avisado que o valor é invalido e precisa inserir novamente
			if(not(gestante == 'S' || gestante == 'N'))
			{
				cout << "|                                                                |" << endl;
				cout << "\a|    !! Voce inseriu um valor invalido! Tente novamente. !!      |" << endl;
			}else if(gestante == 'S')//Se a resposta for sim o campo gestante da variavel usuario do tipo Pessoa recebe o valor booleando true (1)
				(*usuario).gestante = 1;
			else if(gestante == 'N')//Se a resposta for não o campo gestante da variavel usuario do tipo Pessoa recebe o valor booleando false (0)
				(*usuario).gestante = 0;
		}while (not(gestante == 'S' || gestante == 'N'));
	}
	cout << "+----------------------------------------------------------------+" << endl;
	cout << "|                                                                |" << endl;
	cout << "|                      CADASTRADO COM SUCESSO!                   |" << endl;
	cout << "|                                                                |" << endl;
	cout << "+----------------------------------------------------------------+" << endl;
	return *usuario;
}

//funcao para exibir tabela e receber opcao desejada
int tabela(Vacina *cartilha)  
{
	int operador, i=0;
	do{
		cout << "+----------------------------------------------------------------+" << endl;
	cout << "|                                                                |" << endl;
	cout << "|                      CARTILHA DE VACINACAO                     |" << endl;
	cout << "|                                                                |" << endl;
		//Exibe todas as vacinas cadastradas no vetor cartilha do tipo Vacina
		for(i = 0; i < QTD_VACINAS ;i++)
		{
			if (i ==0) {
				cout << "|                                                                |" << endl;
				cout << "|                                                                |" << endl;
				cout << "|                            #Criancas#                          |" << endl;
				cout << "|                                                                |" << endl;
			}
			if (i == 15) {
				cout << "|                                                                |" << endl;
				cout << "|                                                                |" << endl;
				cout << "|                          #Adolescentes#                        |" << endl;
				cout << "|                                                                |" << endl;
			}
			if (i == 17) {
				cout << "|                                                                |" << endl;
				cout << "|                                                                |" << endl;
				cout << "|                            #Adultos#                           |" << endl;
				cout << "|                                                                |" << endl;			
			}
			cout <<"|    ("<<i+1<<") "<< (cartilha[i]).nome<<endl;
		}
		cout << "|                                                                |" << endl;
		cout << "|                                                                |" << endl;
		cout << "|    (0) Sair" << endl;
		cout << "|                                                                |" << endl;
		cout << "|                                                                |" << endl;
		cout << "|    Insira o comando desejado:                                  |" << endl;
		cout << "|    " ;
		cin >> operador;//Recebendo a opcao escolhida pelo usuario
		cout << "|                                                                |" << endl; 
		cout << "+----------------------------------------------------------------+" << endl;
		//Se a opção for invalida o usuario recebe um aviso que o valor é invalido e precisa inserir novamente
		if (operador < 0 || operador > QTD_VACINAS) 
		{
			cout << "|                                                                |" << endl;
			cout << "\a|      Voce inseriu um comando inexistente. Tente novamente!     | " << endl;
			cout << "|                                                                |" << endl;
			cout << "+----------------------------------------------------------------+" << endl;
			continuar();
		}
	}while (operador < 0 || operador > QTD_VACINAS);
	return operador;
}
void exibeVacina(Vacina *cartilha, int *operador)
{
	cout << "|                                                                |" << endl; 
							cout << "|    " << (cartilha[*operador-1]).nome << endl;
							cout << "|    " << (cartilha[*operador-1]).descricao << endl;
							cout << "|    Doses: " << (cartilha[*operador-1]).qtdDoses << endl;
							cout << "|    Idade minima: " << (cartilha[*operador-1]).idadeMin << endl;
							cout << "|    Idade maxima: " << (cartilha[*operador-1]).idadeMax << endl;
							cout << "|                                                                |" << endl;
}

/*--------------------------------Main-----------------------------------------------------------------------------*/
int main()
{
	int operador;//Criando variavel do tipo int para a opçao do menu escolhida pelo usuario
	
	Pessoa usuario, *pUsuario;//Criando Variaveis do tipo Pessoa

	Vacina *pVacina, cartilha[QTD_VACINAS]=//Criando variaveis do tipo Vacina e preenchendo o vetor cartilha com  as vacinas
	{
		//vacinas crianca 0 - 10 anos
		{"BCG (Bacilo Calmette-Guerin)","Previne as formas graves de tuberculose, principalmente     |\n|    miliar e meningea",1, MIN_IDADE_CADASTRO,5,2, MAX_PESO_CADASTRO, SEXO_AMBOS,1},

		{"Hepatite B","Previne hepatite do tipo B                                  |",1, MIN_IDADE_CADASTRO,7, MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,0},

		{"Pentavalente (DTP/HB/Hib)", "Prevenir a difteria, o tetano e a coqueluche                |",3, MIN_IDADE_CADASTRO,7,MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,0},

		{"VIP (Poliomielite inativada)","Previne poliomielite ou paralisia infantil                  |",3, MIN_IDADE_CADASTRO,5,MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,0},

		{"Poliomielite oral VOP","Previne poliomielite ou paralisia infantil                  |",2,1,5, MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,0},

		{"Rotavirus humano G1P1","Previne diarreia por rotavirus                              |",2, MIN_IDADE_CADASTRO,7, MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,0},	
		
		{"Pneumococica V10", "Indicada para imunizacao ativa (ou seja, estimula o sistema |\n|    de defesa do organismo a produzir anticorpos)",3, MIN_IDADE_CADASTRO,6, MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,0},

		{"Meningococica C", "Prevenir doencas causadas pelo meningococo C (incluindo     |\n|    meningite e     |\n|    meningococcemia )",3, MIN_IDADE_CADASTRO,5, MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,0},	

		{"Febre Amarela","Previne a febre amarela                                     |",2, MIN_IDADE_CADASTRO,5, MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,0},

		{"Triplice Viral", "Previne sarampo, caxumba e rubeola                          |",1,1,7, MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,1},

		{"Tetra viral ou triplice viral + varicela", "Previne sarampo, rubeola, caxumba e                         |\n|    varicela/catapora",1,1,5, MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,0},

		{"DTP", "Difteria, tetano e coqueluche                               |",2,1,7, MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,0},

		{"Hepatite A","Previne Hepatite A                                          |",1, MIN_IDADE_CADASTRO,5, MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,0},

		{"Varicela","Previne varicela/catapora                                   |",1,4,7, MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,1},

		{"DTP", "Difteria, tetano e coqueluche                               |",2,1,7, MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,0},
		
		//vacinas adolescentes 11 - 19 anos

		{"HPV", "Previne o papiloma, virus humano que causa canceres e       |\n|    verrugas genitais",2,9,14, MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,1},
		
		{"Meningococica ACWY", "Previne pneumonia, otite, meningite e outras doencas        |\n|    causadas pelo Pneumococo",1,11,12, MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,0},
		
		//vacinas adulto 20 - 59 anos
		{"Difteria e tetano adulto", "Previne difteria e tetano (reforco a cada 10 anos)          |",1,7,120, MIN_PESO_CADASTRO, MAX_PESO_CADASTRO, SEXO_AMBOS,0}
	};
	
	//Apontando os ponteiros pUsuario para a variavel usuario do tipo Pessoa e o ponteiro pVacina para o vetor cartilha do tipo Vacina
	pUsuario = &usuario;
	pVacina = cartilha;
	
	//Executando a função dados para receber os dados do usuario
	usuario = dados(pUsuario);
	
	//Loop principal do programa
	do{
		continuar();
		//Recebendo com a variavel operador a opção escolhida pelo usuario na funçao tabela 
		operador = tabela(pVacina);
		
		//A opção para sair do programa eh a 0
		if (operador == 0)
		{
			cout << "|                                                                |" << endl;
			cout << "\a|                 Voce escolheu encerrar, ate logo " << usuario.nome << "!" << endl;
			cout << "|                                                                |" << endl;
			cout << "+----------------------------------------------------------------+" << endl;
		}	
		//Se o usuario nao digitou 0, ele escolheu alguma das vacinas cadastradas para verificar se esta apto a tomar 
		else
		{
			//Se o usuario for do sexo ao qual a vacina for destinada ou a vacina nao possuir limitação quanto ao sexo
			if(usuario.sexo == cartilha[operador-1].sexo || cartilha[operador-1].sexo == SEXO_AMBOS)
			{
				//Se o usuario nao for gestante ou a vacina nao tiver limitação quanto a ser gestante
				if(usuario.gestante == 0 || cartilha[operador-1].gestante == 0)
				{
					//Se o usuario estiver com o peso correta para receber a vacina ou a vacina nao possuir limitação quanto ao peso
					if(usuario.peso >= cartilha[operador-1].pesoMin && usuario.peso <= cartilha[operador-1].pesoMax)
					{
						//Se o usuario estiver com a idade correta para receber a vacina ou a vacina nao possuir limitação quanto a idade
						if(usuario.idade >= cartilha[operador-1].idadeMin && usuario.idade <= cartilha[operador-1].idadeMax)
						{
							//Se todas as condições forem verdadeiras o programa exibe o nome da vacina escolhida pelo usuario, a descrição da vacina,
							//a quantidade de doses que essa vacina eh aplicada, a idade minima e maxima para recer a vacina e uma mensagem dizendo que o 
							//usuario está apto a receber a vacina
							exibeVacina(cartilha,&operador);
							cout << "\a|               Voce esta apto a receber esta vacina!            |" << endl;
							cout << "|                                                                |" << endl;
							cout << "+----------------------------------------------------------------+" << endl;
							continue;
						}
						else if(usuario.idade > cartilha[operador-1].idadeMin)
						{
							//Caso o usuario nao esteja com a idade correta para receber a vacina
							exibeVacina(cartilha,&operador);
							cout << "|    Esta vacina deve ser tomada entre "<<cartilha[operador-1].idadeMin<<" e "<<cartilha[operador-1].idadeMax<<" anos de idade."  << endl;
							cout << "|    Se ainda nao tomou essa vacina procure o posto de saude     |"<<endl;
							cout << "|    mais proximo para receber a vacina!                         |"<<endl;
							cout << "|                                                                |" << endl;
							cout << "+----------------------------------------------------------------+" << endl;
						}
					} 
					else 
					{//Caso o usuario nao esteja no peso correto para receber a vacina
						exibeVacina(cartilha,&operador);
						cout << "\a|            Voce nao esta apto a receber esta vacina.           |" << endl;
						cout << "|        nao se enquadra no peso para receber essa vacina!       |" << endl;
						cout << "|                                                                |" << endl;
						cout << "+----------------------------------------------------------------+" << endl;
					}
				}
				else
				{//Caso o usuario esteja gestante e a vacina nao seja recomendada para gestantes
					exibeVacina(cartilha,&operador);
					cout << "\a|            Voce nao esta apto a receber esta vacina.           |" << endl;
					cout << "|       a vacina nao eh recomendada para pessoas gestantes!      |" << endl;
					cout << "|                                                                |" << endl;
					cout << "+----------------------------------------------------------------+" << endl;
				}
			}
			else
			{//Caso o usuario nao seja do sexo correto para receber a vacina
				exibeVacina(cartilha,&operador);
				cout << "\a|            Voce nao esta apto a receber esta vacina.           |" << endl;
				cout << "|            a vacina nao eh para pessoas do seu sexo!           |" << endl;
				cout << "|                                                                |" << endl;
				cout << "+----------------------------------------------------------------+" << endl;
			}
		}	
	}while(operador != 0);//A condição para encerrar o loop é se o usuario escolher a opção 0(sair) na função tabela
}
