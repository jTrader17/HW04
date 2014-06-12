#include <iostream>
using namespace std;

int* doubleCapacity (const int* list, int size){
	int *newlist=new int[2*size];
	return newlist;
}

int main(){
	int isize=5;
	const int *mylist = new int[isize];
	int* mynewlist = doubleCapacity (mylist,isize);
	delete[] mylist;
	delete[] mynewlist;
	return 0;
}