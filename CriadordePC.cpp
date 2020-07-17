#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

struct dados{
	char nome[100];
	char tel[20];
	char cpf[15];
	char uf[10];
	char city[50];
	char cep[10];
	char sisop[20];
	char proc[20];
	char plv[30];
	char mmr[10];
	char hdisp[10];
	char pref[50];
	bool status;
}computer;

fstream arquivo;

void gotoxy (int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showinterface1();
void showinterface2();
void showinterface3();

void cadastrar(){
	cin.ignore();
	gotoxy(16,9);
	cin.getline(computer.nome, 100);
	if(isalpha(computer.nome[0]) == 0){
		do{
			gotoxy(16,9);
			cout<<"Entre com Letras"<<endl;
			gotoxy(16,9);
			getch();
			cout<<"                "<<endl;
			gotoxy(16,9);
			cin.getline(computer.nome, 100);
		}while(isalpha(computer.nome[0]) == 0);
	}
	
	gotoxy(54,9);
	cin.getline(computer.tel, 20);
	if(isdigit(computer.tel[0]) == 0){
		do{
			gotoxy(54,9);
			cout<<"Entre com Digitos"<<endl;
			gotoxy(54,9);
			getch();
			cout<<"                  "<<endl;
			gotoxy(54,9);
			cin.getline(computer.tel, 20);
		}while(isdigit(computer.tel[0]) == 0);
	}
	gotoxy(16,11);
	cin.getline (computer.cpf, 15);
	if(isdigit(computer.cpf[0]) == 0){
		do{
			gotoxy(16,11);
			cout<<"Entre com Digitos"<<endl;
			gotoxy(16,11);
			getch();
			cout<<"                  "<<endl;
			gotoxy(16,11);
			cin.getline(computer.cpf, 15);
		}while(isdigit(computer.cpf[0]) == 0);
	}
	gotoxy(54,11);
	cin.getline (computer.uf, 10);
	if(isalpha(computer.uf[0]) == 0){
		do{
			gotoxy(54,11);
			cout<<"Entre com Letras"<<endl;
			gotoxy(54,11);
			getch();
			cout<<"                "<<endl;
			gotoxy(54,11);
			cin.getline(computer.uf, 10);
		}while(isalpha(computer.uf[0]) == 0);
	}
	gotoxy(16,13);
	cin.getline (computer.city, 50);
	if(isalpha(computer.city[0]) == 0){
		do{
			gotoxy(16,13);
			cout<<"Entre com Letras"<<endl;
			gotoxy(16,13);
			getch();
			cout<<"                  "<<endl;
			gotoxy(16,13);
			cin.getline(computer.city, 50);
		}while(isalpha(computer.city[0]) == 0);
	}
	gotoxy(54,13);
	cin.getline (computer.cep, 10);
	if(isdigit(computer.cep[0]) == 0){
		do{
			gotoxy(54,13);
			cout<<"Entre com Digitos"<<endl;
			gotoxy(54,13);
			getch();
			cout<<"                  "<<endl;
			gotoxy(54,13);
			cin.getline(computer.cep, 10);
		}while(isdigit(computer.cep[0]) == 0);
	}
	gotoxy(29,21);
	cin.getline (computer.sisop, 20);
	gotoxy(24,23);
	cin.getline (computer.proc, 20);
	gotoxy(54,23);
	cin.getline (computer.mmr, 10);
	gotoxy(24,25);
	cin.getline (computer.plv, 30);
	gotoxy(54,25);
	cin.getline (computer.hdisp, 10);	
	gotoxy(24,27);
	cin.getline (computer.pref, 10);	
	computer.status=true;
	arquivo.seekp(0,arquivo.end);
	arquivo.write((char *) &computer, sizeof(computer));
	gotoxy(19,29);
	cout<<"Computador cadastrado com sucesso"<<endl;
	gotoxy(16,30);
	system("pause");
	
}

void listar(){
	arquivo.seekg(0, arquivo.beg);
	arquivo.read((char*) &computer,sizeof(computer));
	while(!arquivo.eof()){
		if(computer.status==true){
			showinterface3();
			gotoxy(13,11);
			cout<<"NOME: "<<computer.nome;
			gotoxy(51,11);
			cout<<"TELEFONE: "<<computer.tel;
			gotoxy(13,13);
			cout<<"CPF: "<<computer.cpf;
			gotoxy(51,13);
			cout<<"UF: "<<computer.uf;
			gotoxy(13,15);
			cout<<"CIDADE: "<<computer.city;
			gotoxy(51,15);
			cout<<"CEP: "<<computer.cep;
			gotoxy(13,20);
			cout<<"SISTEMA OPERACIONAL: "<<computer.sisop;
			gotoxy(13,22);
			cout<<"PROCESSADOR: "<<computer.proc;
			gotoxy(49,22);
			cout<<"PLACA DE VIDEO: "<<computer.plv;
			gotoxy(13,24);
			cout<<"MEMORIA RAM: "<<computer.mmr;
			gotoxy(49,24);
			cout<<"HD: "<<computer.hdisp;
			gotoxy(13,26);
			cout<<"Jogo preferido: "<<computer.pref;
			gotoxy(21,28);
			system("PAUSE");
			system("cls");
		}
		arquivo.read((char *)&computer,sizeof(computer));
	}
}

void excluir(){
	
	char nomep[100];
	cin.ignore();
	cin.getline(nomep,100);
	
	arquivo.seekg(0, arquivo.beg);
	arquivo.read((char*) &computer,sizeof(computer));
	while(!arquivo.eof()){
		if(strcmp(nomep,computer.nome)==0){
			cout <<"Dados: " << endl << endl;
			cout<<"Nome: "<<computer.nome<<endl;
			cout<<"Sistema Operacional: "<<computer.sisop<<endl;
			cout<<"Processador: "<<computer.proc<<endl;
			cout<<"Placa de Video: "<<computer.plv<<endl;
			cout<<"Memoria RAM: "<<computer.mmr<<endl;
			cout<<"Espaco no HD disponivel: "<<computer.hdisp<<endl;
			cout<<"Jogo preferido: "<<computer.pref<<endl;
			cout <<"Deseja realmente excluir o cadastro: ";
			//if
			computer.status=false;
			
			arquivo.seekp(arquivo.tellp()-sizeof(computer));
			arquivo.write((char *) &computer, sizeof(computer));
			break;
		}
		arquivo.read((char *)&computer,sizeof(computer));
		cout << endl << endl;
	}
	system("pause");
	
}
void editar(){
	showinterface2();
	gotoxy(16,9);
	char nomep[100];
	cin.ignore();
	cin.getline(nomep,100);
	arquivo.seekg(0, arquivo.beg);
	arquivo.read((char*) &computer,sizeof(computer));
	while(!arquivo.eof()){
		if(strcmp(nomep,computer.nome)==0){
			gotoxy(54,9);
			cout<<computer.tel;
			gotoxy(16,11);
			cout<<computer.cpf;
			gotoxy(54,11);
			cout<<computer.uf;
			gotoxy(16,13);
			cout<<computer.city;
			gotoxy(54,13);
			cout<<computer.cep;
			gotoxy(29,21);
			cout<<computer.sisop;
			gotoxy(24,23);
			cout<<computer.proc;
			gotoxy(24,25);
			cout<<computer.plv;
			gotoxy(54,23);
			cout<<computer.mmr;
			gotoxy(54,25);
			cout<<computer.hdisp;
			gotoxy(24,27);
			cout<<computer.pref;
			gotoxy(54,9);
			cin>>computer.tel;
			gotoxy(16,11);
			cin>>computer.cpf;
			gotoxy(54,11);
			cin>>computer.uf;
			gotoxy(16,13);
			cin>>computer.city;
			gotoxy(54,13);
			cin>>computer.cep;
			gotoxy(29,21);
			cin>>computer.sisop;
			gotoxy(24,23);
			cin>>computer.proc;
			gotoxy(24,25);
			cin>>computer.plv;
			gotoxy(54,23);
			cin>>computer.mmr;
			gotoxy(54,25);
			cin>>computer.hdisp;
			gotoxy(24,27);
			cin>>computer.pref;
			gotoxy(19,29);
			cout<<"Informacoes alteradas com sucesso !"<<endl;
			gotoxy(19,30);
			arquivo.seekp(arquivo.tellp()-sizeof(computer));
			arquivo.write((char *) &computer, sizeof(computer));
			break;
		}
		arquivo.read((char *)&computer,sizeof(computer));
		cout << endl << endl;
	}
	system("pause");
	
}


void showinterface1 (){
	cout<<"                   ___   ____    ____ ____ ____ ___ ____ ____ "<<endl;
	cout<<"                   |__]  |    __ |__/ |___ |__|  |  |  | |__/ "<<endl;
	cout<<"                   |    .|___    |  | |___ |  |  |  |__| |  | "<<endl;
	cout<<"  ___________________________________________________________________________ "<<endl;
    cout<<" /                                                                            |" <<endl;
    cout<<"|    _____________________________________________________________________    |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                     ENTRE COM A OPCAO DESEJADA                      |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |          1- CADASTRAR                       2- LISTAR               |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |          3- EDITAR                          4- EXCLUIR              |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |          5- SAIR                                                    |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                          OPCAO:                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
	cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |_____________________________________________________________________|   |"<<endl;
    cout<<"|                                                                             |"<<endl;
    cout<<"|_____________________________________________________________________________/"<<endl;
    cout<<"             \____________________________________________/"<<endl;
    cout<<"            |______________________________________________|"<<endl;
    cout<<"          _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_"<<endl;
    cout<<"       _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_"<<endl;
    cout<<"     _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_"<<endl;
    cout<<"  _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_"<<endl;
 cout<<"  -'.-.-.-.-.-. .---.-. .-----------------------------. .-.---. .---.-.-.-.`-_"<<endl;
cout<<" :-----------------------------------------------------------------------------:"<<endl;
cout<<" `---._.-----------------------------------------------------------------._.---'"<<endl;
}
void showinterface2 (){
	cout<<"                   ___   ____    ____ ____ ____ ___ ____ ____ "<<endl;
	cout<<"                   |__]  |    __ |__/ |___ |__|  |  |  | |__/ "<<endl;
	cout<<"                   |    .|___    |  | |___ |  |  |  |__| |  | "<<endl;
	cout<<"  ___________________________________________________________________________ "<<endl;
    cout<<" /                                                                            |" <<endl;
    cout<<"|    _____________________________________________________________________    |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                    INFORMACOES SOBRE O CLIENTE                      |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |      NOME:                                  TEL:                    |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |       CPF:                                   UF:                    |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |    CIDADE:                                  CEP:                    |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |---------------------------------//----------------------------------|   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                         CONFIGURACOES DO PC                         |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |    SISTEMA OPERACIONAL:                                             |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |       PROCESSADOR:                  MEMORIA RAM:                    |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
	cout<<"|   |    PLACA DE VIDEO:                           HD:                    |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |    JOGO PREFERIDO:                                                  |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |_____________________________________________________________________|   |"<<endl;
    cout<<"|                                                                             |"<<endl;
    cout<<"|_____________________________________________________________________________/"<<endl;
    cout<<"             \____________________________________________/"<<endl;
    cout<<"            |______________________________________________|"<<endl;
    cout<<"          _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_"<<endl;
    cout<<"       _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_"<<endl;
    cout<<"     _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_"<<endl;
    cout<<"  _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_"<<endl;
 cout<<"  -'.-.-.-.-.-. .---.-. .-----------------------------. .-.---. .---.-.-.-.`-_"<<endl;
cout<<" :-----------------------------------------------------------------------------:"<<endl;
cout<<" `---._.-----------------------------------------------------------------._.---'"<<endl;
}

void showinterface3(){
	cout<<"                   ___   ____    ____ ____ ____ ___ ____ ____ "<<endl;
	cout<<"                   |__]  |    __ |__/ |___ |__|  |  |  | |__/ "<<endl;
	cout<<"                   |    .|___    |  | |___ |  |  |  |__| |  | "<<endl;
	cout<<"  ___________________________________________________________________________ "<<endl;
    cout<<" /                                                                            |" <<endl;
    cout<<"|    _____________________________________________________________________    |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                  USUARIOS CADASTRADOS NO SISTEMA                    |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
	cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |---------------------------------//----------------------------------|   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
	cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |                                                                     |   |"<<endl;
    cout<<"|   |_____________________________________________________________________|   |"<<endl;
    cout<<"|                                                                             |"<<endl;
    cout<<"|_____________________________________________________________________________/"<<endl;
    cout<<"             \____________________________________________/"<<endl;
    cout<<"            |______________________________________________|"<<endl;
    cout<<"          _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_"<<endl;
    cout<<"       _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_"<<endl;
    cout<<"     _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_"<<endl;
    cout<<"  _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_"<<endl;
 cout<<"  -'.-.-.-.-.-. .---.-. .-----------------------------. .-.---. .---.-.-.-.`-_"<<endl;
cout<<" :-----------------------------------------------------------------------------:"<<endl;
cout<<" `---._.-----------------------------------------------------------------._.---'"<<endl;
}

int main(){
	system("colorfc");
	int opcao = -1;
	arquivo.open("computer.txt", ios::in | ios::out | ios::binary);
	if(arquivo.is_open() == false)
		arquivo.open ("computer.txt", ios::trunc | ios::in | ios::out | ios::binary);
	do{
		arquivo.clear();
		system("cls");
		showinterface1();
		gotoxy(37,22);
		cin>>opcao;
		system("cls");
		switch(opcao){
			case 1:
				showinterface2();
				cadastrar();
				break;
			case 2:
				listar();
				break;
			case 3:
				editar();
				break;
			case 4:
				excluir();
				break;
		}
	}while(opcao!=4);
}