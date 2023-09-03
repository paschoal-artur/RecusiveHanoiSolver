#include <iostream>
#include <stack>

using namespace std;

/*função que opera a torre de hanói com 3 referências de pilhas e 3 referências de string para poder nomear corretamente no terminal*/
void torreDeHanoi(int numDiscos, stack<int> &origem, stack<int> &auxiliar, stack<int> &destino,
                  const string &origemNome, const string &auxiliarNome, const string &destinoNome)
{
    if (numDiscos == 1) {
        int disco = origem.top();
        origem.pop();
        destino.push(disco);
        cout << "Move disco " << disco << " da " << origemNome << " para " << destinoNome << endl;
        return;
    }

    torreDeHanoi(numDiscos - 1, origem, destino, auxiliar, origemNome, destinoNome, auxiliarNome);

    int disco = origem.top();
    origem.pop();
    destino.push(disco);
    cout << "Move disco " << disco << " da " << origemNome << " para " << destinoNome << endl;

    torreDeHanoi(numDiscos - 1, auxiliar, origem, destino, auxiliarNome, origemNome, destinoNome);
}

int main(void) {
    int numDiscos;

    cout << "Informe o numero de discos: ";
    cin >> numDiscos;

    stack<int> origem, auxiliar, destino;

    for (int i = numDiscos; i >= 1; i--) {
        origem.push(i);
    }

    torreDeHanoi(numDiscos, origem, auxiliar, destino, "Origem", "Auxiliar", "Destino");

    return 0;
}
