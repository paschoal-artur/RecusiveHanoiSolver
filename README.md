# Trabalho-ED
A resolução da Torre de Hanoi é um problema clássico da teoria dos algoritmos e da recursão. O problema consiste em mover uma pilha de discos de um pino (torre de origem) para outro pino (torre de destino), usando um terceiro pino (torre auxiliar) como auxílio, de acordo com as seguintes regras:

    Apenas um disco pode ser movido por vez.

    Um disco maior nunca pode ser colocado em cima de um disco menor.

O objetivo é mover todos os discos da torre de origem para a torre de destino, mantendo a ordem correta dos discos.

Aqui está uma explicação detalhada das funções relacionadas à resolução da Torre de Hanoi no código que você está usando:

    void torreDeHanoi(int n, Pilha &origem, Pilha &destino, Pilha &auxiliar): Esta é a função principal que resolve a Torre de Hanoi usando a recursão. Ela recebe quatro parâmetros: o número de discos n a serem movidos e três pilhas (origem, destino e auxiliar). A função funciona da seguinte forma:

        Se n for igual a 0, a função retorna imediatamente, pois não há discos para mover.

        Caso contrário, a função realiza a seguinte sequência de passos:

            Move n-1 discos da torre de origem para a torre auxiliar, usando a torre de destino como auxílio. Isso é feito chamando a função torreDeHanoi recursivamente com n-1 discos.

            Move o disco superior (o maior) da torre de origem para a torre de destino e exibe a ação.

            Chama novamente a função torreDeHanoi para mover os n-1 discos da torre auxiliar para a torre de destino, usando a torre de origem como auxílio.

    Essa recursão garante que os discos sejam movidos na ordem correta e que todas as regras do problema sejam seguidas.

    void exibirEstadoDasTorres(const Pilha &origem, const Pilha &destino, const Pilha &auxiliar): Esta função exibe o estado atual das três torres (origem, destino e auxiliar). Ela é chamada após cada movimento de disco para que você possa acompanhar o progresso da resolução.

Portanto, a recursão é a chave para resolver a Torre de Hanoi, movendo discos menores para uma torre auxiliar, movendo o disco maior para a torre de destino e, em seguida, movendo os discos menores da torre auxiliar para a torre de destino, usando a torre de origem como auxílio. Esse processo é repetido até que todos os discos estejam na torre de destino na ordem correta. Cada passo é cuidadosamente controlado pelas funções para garantir que as regras do problema sejam obedecidas.
