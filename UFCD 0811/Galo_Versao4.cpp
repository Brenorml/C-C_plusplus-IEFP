#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;

int galo[9]={0,0,0,0,0,0,0,0,0};
int jog1;
int jog2;
bool resultado=false;
int njogada;




int mostraJogo() {
	
	cout<<endl;
	
	if (galo[0]==1) cout<<"X"; if (galo[0]==2) cout<<"O"; if (galo[0]==0) cout<<" "; cout<<"|";
	if (galo[1]==1) cout<<"X"; if (galo[1]==2) cout<<"O"; if (galo[1]==0) cout<<" "; cout<<"|";
	if (galo[2]==1) cout<<"X"; if (galo[2]==2) cout<<"O"; if (galo[2]==0) cout<<" "; cout<<endl<<"-----"<<endl;
	if (galo[3]==1) cout<<"X"; if (galo[3]==2) cout<<"O"; if (galo[3]==0) cout<<" "; cout<<"|";
	if (galo[4]==1)	cout<<"X"; if (galo[4]==2) cout<<"O"; if (galo[4]==0) cout<<" "; cout<<"|";
	if (galo[5]==1)	cout<<"X"; if (galo[5]==2) cout<<"O"; if (galo[5]==0) cout<<" "; cout<<endl<<"-----"<<endl;
	
	if (galo[6]==1)
	cout<<"X";
	if (galo[6]==2) 
	cout<<"O";
	if (galo[6]==0)
	cout<<" ";
	
	cout<<"|";
	
	if (galo[7]==1)
	cout<<"X";
	if (galo[7]==2) 
	cout<<"O";
	if (galo[7]==0)
	cout<<" ";
	
	cout<<"|";
	
	if (galo[8]==1)
	cout<<"X";
	if (galo[8]==2) 
	cout<<"O";
	if (galo[8]==0)
	cout<<" ";
		
}

int jogador1() {
	
	
	
	cout<<endl<<endl<<"escolha a jogada do jogador 1 : ";
	cin>>jog1;
	
	do {
		
	if (galo[jog1]!=0) {
		cout<<"casa ocupada";
			cout<<endl<<endl<<"escolha a jogada do jogador 1 : ";
			cin>>jog1;
			
	}
	
	}while (galo[jog1]!=0);
	galo[jog1]=1;
	njogada++;
}

int melhorJogadaAi() {
	int move = 9;
	if(galo[0] == 2 && galo[1] == 2)
		move = 2;
	if(galo[1] == 2 && galo[2] == 2)
		move = 0;
	if(galo[0] == 2 && galo[2] == 2)
		move = 1;
	if(galo[3] == 2 && galo[4] == 2)
		move = 5;
	if(galo[4] == 2 && galo[5] == 2)
		move = 3;
	if(galo[3] == 2 && galo[5] == 2)
		move = 4;
	if(galo[6] == 2 && galo[7] == 2)
		move = 8;
	if(galo[7] == 2 && galo[8] == 2)
		move = 6;
	if(galo[6] == 2 && galo[8] == 2)
		move = 7;
	if(galo[0] == 2 && galo[3] == 2)
		move = 6;
	if(galo[3] == 2 && galo[6] == 2)
		move = 0;
	if(galo[0] == 2 && galo[6] == 2)
		move = 3;
	if(galo[1] == 2 && galo[4] == 2)
		move = 7;
	if(galo[4] == 2 && galo[7] == 2)
		move = 1;
	if(galo[1] == 2 && galo[7] == 2)
		move = 4;
	if(galo[2] == 2 && galo[5] == 2)
		move = 8;
	if(galo[5] == 2 && galo[8] == 2)
		move = 2;
	if(galo[2] == 2 && galo[8] == 2)
		move = 5;
	if(galo[0] == 2 && galo[4] == 2)
		move = 8;
	if(galo[2] == 2 && galo[4] == 2)
		move = 6;
	if(galo[0] == 2 && galo[8] == 2 || galo[2] == 2 && galo[6] == 2)
		move = 4;
	if(galo[4] == 2 && galo[8] == 2)
		move = 0;
	if(galo[4] == 2 && galo[6] == 2)
		move = 2;
	return move;
}

int counterAiJogador1() {
	int counter = 10;
	if(galo[0] == 1 && galo[1] == 1)
		counter = 2;
	if(galo[1] == 1 && galo[2] == 1)
		counter = 0;
	if(galo[0] == 1 && galo[2] == 1)
		counter = 1;
	if(galo[3] == 1 && galo[4] == 1)
		counter = 5;
	if(galo[4] == 1 && galo[5] == 1)
		counter = 3;
	if(galo[3] == 1 && galo[5] == 1)
		counter = 4;
	if(galo[6] == 1 && galo[7] == 1)
		counter = 8;
	if(galo[7] == 1 && galo[8] == 1)
		counter = 6;
	if(galo[6] == 1 && galo[8] == 1)
		counter = 7;
	if(galo[0] == 1 && galo[3] == 1)
		counter = 6;
	if(galo[3] == 1 && galo[6] == 1)
		counter = 0;
	if(galo[0] == 1 && galo[6] == 1)
		counter = 3;
	if(galo[1] == 1 && galo[4] == 1)
		counter = 7;
	if(galo[4] == 1 && galo[7] == 1)
		counter = 1;
	if(galo[1] == 1 && galo[7] == 1)
		counter = 4;
	if(galo[2] == 1 && galo[5] == 1)
		counter = 8;
	if(galo[5] == 1 && galo[8] == 1)
		counter = 2;
	if(galo[2] == 1 && galo[8] == 1)
		counter = 5;
	if(galo[0] == 1 && galo[4] == 1)
		counter = 8;
	if(galo[2] == 1 && galo[4] == 1)
		counter = 6;
	if(galo[0] == 1 && galo[8] == 1 || galo[2] == 1 && galo[6] == 1)
		counter = 4;
	if(galo[4] == 1 && galo[8] == 1)
		counter = 0;
	if(galo[4] == 1 && galo[6] == 1)
		counter = 2;
	return counter;
}

int jogador2Ai() {
	
	
	cout<<endl<<"PC jogando. Pressione enter para continuar...";	
	getchar();
	getchar();

	
	if((jog2 = melhorJogadaAi()) >= 9){
		jog2 = counterAiJogador1();
		if(jog2 >= 9){
			srand(time(NULL));	
			jog2 = rand()%9;
		}
	}	
	
	do {
		
	if (galo[jog2]!=0) {
		cout<<"casa ocupada";
			cout<<endl<<"PC jogando. Pressione enter para continuar...";			
			getchar();
			jog2 = rand()%10 + 1;
	}

	
	}while (galo[jog2]!=0);
	galo[jog2]=2;
	njogada++;
}	

int testa(){
	
	
	if (galo[0]==1 && galo[1]==1 && galo[2]==1){
		resultado=true;
		cout<<endl<<"jogador 1 vencedor!"<<endl;
	}
	
	if (galo[0]==2 && galo[1]==2 && galo[2]==2) {
		resultado=true;
		cout<<endl<<"jogador 2 vencedor!"<<endl;
	}
	


	if (galo[3]==2 && galo[4]==2 && galo[5]==2) {
		resultado=true;
		cout<<endl<<"jogador 2 vencedor!"<<endl;
	}
	
	if (galo[3]==1 && galo[4]==1 && galo[5]==1) {
		resultado=true;
		cout<<endl<<"jogador 1 vencedor!"<<endl;
	}
	
	if (galo[6]==2 && galo[7]==2 && galo[8]==2) {
		resultado=true;
		cout<<endl<<"jogador 2 vencedor!"<<endl;
	}
	
	if (galo[6]==1 && galo[7]==1 && galo[8]==1) {
		resultado=true;
		cout<<endl<<"jogador 1 vencedor!"<<endl;
	}

	if (galo[0]==2 && galo[3]==2 && galo[6]==2) {
		resultado=true;
		cout<<endl<<"jogador 2 vencedor!"<<endl;
	}
	
	if (galo[0]==1 && galo[3]==1 && galo[6]==1) {
		resultado=true;
		cout<<endl<<"jogador 1 vencedor!"<<endl;
	}

	if (galo[1]==2 && galo[4]==2 && galo[7]==2) {
		resultado=true;
		cout<<endl<<"jogador 2 vencedor!"<<endl;
	}
	
	if (galo[1]==1 && galo[4]==1 && galo[7]==1) {
		resultado=true;
		cout<<endl<<"jogador 1 vencedor!"<<endl;
	}

	if (galo[2]==2 && galo[5]==2 && galo[8]==2) {
		resultado=true;
		cout<<endl<<"jogador 2 vencedor!"<<endl;
	}
	
	if (galo[2]==1 && galo[5]==1 && galo[8]==1) {
		resultado=true;
		cout<<endl<<"jogador 1 vencedor!"<<endl;
	}

	if (galo[0]==2 && galo[4]==2 && galo[8]==2) {
		resultado=true;
		cout<<endl<<"jogador 2 vencedor!"<<endl;
	}
	
	if (galo[0]==1 && galo[4]==1 && galo[8]==1) {
		resultado=true;
		cout<<endl<<"jogador 1 vencedor!"<<endl;
	}

	if (galo[2]==2 && galo[4]==2 && galo[6]==2) {
		resultado=true;
		cout<<endl<<"jogador 2 vencedor!"<<endl;
	}
	
	if (galo[2]==1 && galo[4]==1 && galo[6]==1) {
		resultado=true;
		cout<<endl<<"jogador 1 vencedor!"<<endl;
	}	
			
}

int main() {
	
	
		do {
			mostraJogo();
			jogador1();
			testa();
			if (resultado==true || njogada==9) {
				mostraJogo();
				cin.get();
				break;
			}
			mostraJogo();
			jogador2Ai();
			testa();
			if (resultado==true || njogada==9) {
			   mostraJogo();
			   cin.get();
			   break;
           }
		}while (resultado!=true || njogada!=9);
		
		cin.get();
}
	

