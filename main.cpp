#include <iostream>
#include <stack>
#include <vector>

/*inclusão de bibliotecas necessárias*/

#include <iostream>
#include <vector>

using namespace std; /*para não escrever o parâmetro std::"..." todas as vezes antes de usar algo*/

/*funções e estrutura Pilha*/
/*&p é uma referência da estrutura denominada "Pilha"*/

struct Pilha {                      /*Estrutura chamada pilha que representa a estrutura da pilha, que possui 3 membros*/

	int topo;         				/*posição do elemento do topo*/
	int capacidadeMax;				/*capacidade máxima da pilha*/
	vector <float> vetorElementos;			/*elemento 'vetor' que armazena os elementos da pilha como float*/
    string nome;
};

void criarPilha (struct Pilha &p, int c){  	/*função que cria pilha, recebe uma referência para uma estrutura Pilha
											e a capacidade "int c" como argumentos*/
	p.topo = -1;
	p.capacidadeMax = c;              /*define a capacidade da pilha*/
	p.vetorElementos.reserve(p.capacidadeMax); /*define a capacidade do vetor*/
}

bool checaVazia(const struct Pilha &p) {

	return p.topo == -1; 		/*checa se a pilha é vazia, caso o topo seja -1
								a pilha é vazia.*/
}

bool estaCheia(const struct Pilha &p) {

	return p.topo == p.capacidadeMax - 1; 		/*checa se a pilha está cheia, caso o topo seja igual a capacidadeMax -1
												a pilha está lotada*/

}

void empilha(struct Pilha &p, float v) {

    if (!estaCheia(p)) {        /*Checa se a pilha está cheia usando a função estaCheia*/
		p.topo++;
		p.vetorElementos.push_back(v);
	} else {
		cout << "Pilha esta cheia!\n"; /*mensagem de erro, caso esteja cheia.*/
	}

}

float removeTopo(struct Pilha &p) { /*função que remove elementos da pilha, sempre o do topo.*/
	if (!checaVazia(p)) {
		float aux = p.vetorElementos[p.topo]; /*se não estiver vazia, o topo é removido*/
		p.topo--;
		return aux;
	} else {
		cout << "\nPilha esta vazia\n";
		return 0.0;
	}
}


float retornaTopo(const struct Pilha &p) {
	if(!checaVazia(p)) {
		return p.vetorElementos[p.topo]; /*topo da pilha é retornado*/
	} else {
		cout << "\nPilha esta vazia\n";
		return 0.0;
	}
}

void torreDeHanoi(int n, struct Pilha &origem, struct Pilha &destino, struct Pilha &auxiliar) { /*3 referências novas para 3 torres*/
    if (n > 0) {
        // move n-1 discos de origme para auxiliar usando 'destino' como auxiliar
        torreDeHanoi(n - 1, origem, auxiliar, destino);

        // move o enésimo da origem para o destino
        float disco = removeTopo(origem);
        empilha(destino, disco);
        cout << "Mover disco " << disco << " de " << origem.nome << " para " << destino.nome << endl;

        // Move n-1 discos da auxiliar para a destino usando a origem como auxiliar
        torreDeHanoi(n - 1, auxiliar, destino, origem);
    }
}

void exibirTorres(const struct Pilha &origem, const struct Pilha &destino, const struct Pilha &auxiliar) {
    cout << "Origem: ";
    for (int i = origem.topo; i >= 0; i--) {
        cout << origem.vetorElementos[i] << " ";
    }
    cout << endl;

    cout << "Destino: ";
    for (int i = destino.topo; i >= 0; i--) {
        cout << destino.vetorElementos[i] << " ";
    }
    cout << endl;

    cout << "Auxiliar: ";
    for (int i = auxiliar.topo; i >= 0; i--) {
        cout << auxiliar.vetorElementos[i] << " ";
    }
    cout << endl;
}

/*código principal de interação com usuários*/

int main(void)
{
	struct Pilha minhaPilha;
    struct Pilha origem, destino, auxiliar;
	int capacidade, option, numDiscos;   /*variáveis inteiras para função principal*/
	float valor;      /*variável ponto flutuante, pilha pode armazenar ponto flutuante*/

	cout << "\nCapacidade da pilha? ";
	cin >> capacidade;

	criarPilha(minhaPilha, capacidade);

	while (true) { /*loop infinito que permite escolher a operação*/

		cout << "\n1- Empilhar (Push)\n"
		     << "2- Desempilhar/Remover (Pop)\n"
		     << "3- Mostrar topo\n"
		     << "4- Resolver a torre de hanoi\n"
             << "5- Finalizar\n"
		     << "\nDigite a opcao: \n";
		cin >> option; /*operação escolhida é armazenada na variável*/

		switch (option) { /*switch permite dividir condições em casos e orientar ao que fazer de acordo com o valor selecionado pelo user.*/

			case 1 : /*push*/

				if (estaCheia(minhaPilha)) {
					cout << "\nPilha esta cheia. \n";
				} else {
					cout << "\nValor? \n";
					cin >> valor;
					empilha(minhaPilha, valor);
				}

				break;

			case 2 : /*pop*/

				if(checaVazia(minhaPilha)) {
					cout << "\nPilha vazia. \n";
				} else {
					valor = removeTopo(minhaPilha);
					cout << "\n" << valor << " Desempilhado.";
				}

				break;

			case 3 : /*mostrar topo*/

				if (checaVazia(minhaPilha)) {
					cout << "\nPilha vazia. \n";
				} else {
					valor = retornaTopo(minhaPilha);
					cout << "\nTopo: " << valor << "\n";
				}

				break;

      case 4:
          cout << "\nInforme o numero de discos para a Torre de Hanoi: ";
          cin >> numDiscos;

          origem.nome = "Origem";
          destino.nome = "Destino";
          auxiliar.nome = "Auxiliar";

          for (int i = numDiscos; i >= 1; i--) {
             empilha(origem, i);
          }

          cout << "\nEstado inicial das torres: \n";
          exibirTorres(origem, auxiliar, destino);

          cout << "\nResolvendo a Torre de Hanoi...\n";
          torreDeHanoi(numDiscos, origem, destino, auxiliar);
          cout << "\nTorre de Hanoi resolvida!\n";

          break;

          case 5:
              exit(0);

			default:
				  cout << "\nOpcao invalida. \n";
		}
	}
	return 0;
}
