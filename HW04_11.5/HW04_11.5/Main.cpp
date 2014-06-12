#include <iostream>
using namespace std;
int findLow (int * p, int size){
	int low;
	low=*p;
	for (int i=0; i<size; i++){
		if (*(p+i)<low){
			low=*(p+i);
		}
	}
	return low;
}

int main (){
	int num=8;
	int* ptr=new int[num];
	ptr[0]=1;
	ptr[1]=2;
	ptr[2]=4;
	ptr[3]=5;
	ptr[4]=10;
	ptr[5]=100;
	ptr[6]=2;
	ptr[7]=-22;
	int a=findLow(ptr,num);
	cout << "lowest number is: " << a << endl;

	delete[] ptr;
	return 0;
}