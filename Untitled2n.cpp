#include <iostream>
#include <cstdlib>
#include <locale>
#include <string>


using namespace std;

struct Nome_estrutura{
	int valor;
	Nome_estrutura *proximo;
};

void pular_linha(int x);

Nome_estrutura* add_lista(Nome_estrutura*, Nome_estrutura*);

void imprimir_lista(Nome_estrutura*);
void remover_lista(Nome_estrutura*);

void pesquisar(Nome_estrutura*);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Nome_estrutura *inicio = NULL;
	Nome_estrutura *temporario;
	int num;
	
	for (int i=0; i<5; i++){
		cout<<"Valor a ser inserido na lista" << "("<< i+1 << ")";
		cin >> num;
		
		temporario = new Nome_estrutura;
		temporario->valor = num;
		temporario->proximo = NULL;
		inicio = add_lista(inicio, temporario);
		
	}
	imprimir_lista(inicio);
	pular_linha(2);
	remover_lista(inicio);
	
	cout << "Foi eliminado um da lista atual:" <<endl;
	imprimir_lista(inicio);
	
	pular_linha(2);
	system("PAUSE");
	
	pular_linha(1);
	pesquisar(inicio);
	pular_linha(2);
	
	system("PAUSE");
	return EXIT_SUCCESS;
	}
	Nome_estrutura* add_lista(Nome_estrutura *inicio, Nome_estrutura *temporario){
		if (inicio == NULL){
			inicio = temporario;
			cout << "Endereço de inicio: " << inicio << endl << endl;
		}else{
			temporario->proximo = inicio;
			inicio = temporario;
			cout << "Endereço de ínicio: " << inicio << endl;
		}
		return inicio;
	}
	
	void imprimir_lista(Nome_estrutura *inicio){
		Nome_estrutura *aux = inicio;
		cout << "listagem";
		while(aux != NULL){
			cout << aux->proximo << " ";
			aux =  aux->proximo;
		}
		cout << endl;
	}
	
	void remover_lista(Nome_estrutura *inicio){
		Nome_estrutura *aux = inicio;
		Nome_estrutura *anterior = inicio;
		
		while(aux->proximo != NULL){
			anterior = aux;
			aux = aux->proximo;
		}
		anterior->proximo = NULL;
		delete aux;
	}
	
	void pular_linha (int x){
		int y;
		for (y=1; y<=x;y++){
			cout << endl;
		}
	}
	void pesquisar(Nome_estrutura *inicio){
		Nome_estrutura *continuar = inicio;
		int vr, sim = 0;
		
		cout << "Digite o valor para pesquisar:";
		cin >> vr;
		
		while(continuar!= NULL){
			if(continuar->valor == vr){
				sim = 1;
				break;
			}
			continuar = continuar->proximo;
		}
		
		pular_linha(1);
		if(sim ==1){
			cout << "Valor digitado achado no endereço: " << continuar <<endl;
			
		}else{
			cout << "Valor digitado não achado.";
		}
		
		pular_linha(1);
		
		system("pause > nul");
	}
	

