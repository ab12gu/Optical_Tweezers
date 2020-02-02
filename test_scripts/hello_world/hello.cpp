
#include <iostream>
#include "headers/add.h"

using namespace std; // automatically use the output class: standard.std however can call class variables directly

int main(int argc, char **argv)
{
	cout << "Hello World!" << endl; // input string and line argument into print function
	int jerry = add(1, 2);
	cout << jerry; // ints are able to print :)
	return 0;
}
    