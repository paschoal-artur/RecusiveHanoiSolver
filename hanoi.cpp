#include <iostream>
#include <stack>
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


void exibirEstadoDasTorres(const struct Pilha &origem, const struct Pilha &destino, const struct Pilha &auxiliar) {
        cout << "Estado das Torres:\n";

        cout << origem.nome << ": ";
        for (int i = origem.topo; i >= 0; i--) {
            cout << origem.vetorElementos[i] << " ";
        }
        cout << endl;

        cout << destino.nome << ": ";
        for (int i = destino.topo; i >= 0; i--) {
            cout << destino.vetorElementos[i] << " ";
        }
        cout << endl;

        cout << auxiliar.nome << ": ";
        for (int i = auxiliar.topo; i >= 0; i--) {
            cout << auxiliar.vetorElementos[i] << " ";
        }
        cout << endl;
}

void torreDeHanoi(int n, struct Pilha &origem, struct Pilha &destino, struct Pilha &auxiliar) { /*3 referências novas para 3 torres*/
    if (n > 0) {
        // move n-1 discos de origme para auxiliar usando 'destino' como auxiliar
        torreDeHanoi(n - 1, origem, auxiliar, destino);

        // move o enésimo da origem para o destino
        float disco = removeTopo(origem);
        empilha(destino, disco);
        cout << "Mover disco " << disco << " de " << origem.nome << " para " << destino.nome << endl;

        exibirEstadoDasTorres(origem, destino, auxiliar);

        // Move n-1 discos da auxiliar para a destino usando a origem como auxiliar
        torreDeHanoi(n - 1, auxiliar, destino, origem);
    }
}

/*código principal de interação com usuários*/

int main(void) {
    int option;

    while (true) {
        cout << "Escolha uma opcao:" << endl;
        cout << "1- Trabalhar com Pilhas" << endl;
        cout << "2- Resolver a Torre de Hanoi" << endl;
        cout << "3- Sair" << endl;
        cout << "Digite sua escolha: ";
        cin >> option;

        if (option == 1) {
            Pilha minhaPilha;
            int capacidade;
            float valor;

            cout << "Capacidade da pilha? ";
            cin >> capacidade;

            criarPilha(minhaPilha, capacidade);

            while (true) {
                cout << "1- Empilhar (Push)" << endl;
                cout << "2- Desempilhar/Remover (Pop)" << endl;
                cout << "3- Mostrar topo" << endl;
                cout << "4- Exibir pilha" << endl;
                cout << "5- Voltar" << endl;
                cout << "Opcao? ";
                cin >> option;

                switch (option) {
                    case 1: // Push
                        if (estaCheia(minhaPilha)) {
                            cout << "PILHA CHEIA!" << endl;
                        } else {
                            cout << "VALOR? ";
                            cin >> valor;
                            empilha(minhaPilha, valor);
                        }
                        break;

                    case 2: // Pop
                        if (checaVazia(minhaPilha)) {
                            cout << "PILHA VAZIA!" << endl;
                        } else {
                            valor = removeTopo(minhaPilha);
                            cout << valor << " DESEMPILHADO!" << endl;
                        }
                        break;

                    case 3: // Mostrar topo
                        if (checaVazia(minhaPilha)) {
                            cout << "PILHA VAZIA!" << endl;
                        } else {
                            valor = retornaTopo(minhaPilha);
                            cout << "TOPO: " << valor << endl;
                        }
                        break;

                    case 4: // Exibir pilha
                        exibirEstadoDasTorres(minhaPilha, minhaPilha, minhaPilha); // Exibição da pilha como se fosse a Torre de Hanoi
                        break;

                    case 5: // Voltar
                        break;

                    default:
                        cout << "Opcao invalida!" << endl;
                }

                if (option == 5) {
                    break;
                }
            }
        } else if (option == 2) {
            int numDiscos;
            Pilha origem, destino, auxiliar;

            cout << "Informe o numero de discos para a Torre de Hanoi: ";
            cin >> numDiscos;

            criarPilha(origem, numDiscos);
            criarPilha(destino, numDiscos);
            criarPilha(auxiliar, numDiscos);

            for (int i = numDiscos; i >= 1; i--) {
                empilha(origem, i);
            }

            cout << "Resolvendo a Torre de Hanoi..." << endl;
            torreDeHanoi(numDiscos, origem, destino, auxiliar);
            cout << "Torre de Hanoi resolvida!" << endl;

        } else if (option == 3) {
            cout << "Saindo do programa. Ate logo!" << endl;
            break;
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}
