# Hanoi Solver, Recusive C++ Exercise<br>

##The Tower of Hanoi is a classic problem in computer science and mathematics. It consists of three rods and a number of disks of different sizes, which can be moved from one rod to another following specific rules without placing a larger disk on top of a smaller one.<br>

"#include <iostream>"<br>
"#include <stack>"<br>
These lines include necessary standard C++ libraries for input/output and using stacks.<br>

"void torreDeHanoi(int numDiscos, stack<int> &origem, stack<int> &auxiliar, stack<int> &destino, const string &origemNome, const string &auxiliarNome, const string &destinoNome)"<br>
This function performs the Tower of Hanoi operation using three stacks representing the rods (origem, auxiliar, and destino). It takes the number of disks, references to the stacks, and strings representing rod names as parameters.<br>

Recursive Implementation:<br>
