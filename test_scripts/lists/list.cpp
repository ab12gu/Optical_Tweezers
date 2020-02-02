// constructing lists
#include <iostream>
#include <list>

using namespace std;

int main ()
{

	int temp[] = {1,2,3};
	cout << temp[1];

	return 0;
    // constructors used in the same order as described above:
    list<int> first;                                // empty list of ints
    int my_int = 1;
    int value;
    int * pointer;
    pointer = &my_int;
    *pointer = 10;
    int myArray[][4] = { {1,2,3,4}, {5,6,7,8} };

    first.push_back (**myArray);

    cout << "The contents of fifth are: ";
    for (list<int>::iterator it = first.begin(); it != first.end(); it++)



        cout << sizeof *it << endl;
    cout << '\n';


        


    list<int> second (4,100);                       // four ints with value 100
    list<int> third (second.begin(),second.end());  // iterating through second
    list<int> fourth (third);                       // a copy of third

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    cout << "The contents of fifth are: ";
    for (list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
        cout << *it << ' ';

    cout << '\n';

  return 0;
}
