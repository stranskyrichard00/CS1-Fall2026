// Programmer name: Richard Stransky


#include <iostream>
#include "header.hpp"


using namespace std;


int main(){
//Puts these values in dynamic memory
int * a = new int;
int * b = new int;

cin >> *a >> *b;

//calls the functions from the header file
int larger = greater_function(*a, *b);
int  smaller = lesser_function(*a, *b);

cout << smaller << " " << larger << endl;
//deallocates the variables for dynamic memory
delete a;
delete b;

return 0;
}