#include <iostream>
using namespace std;

int main (){
	int *ptr=NULL;
	int count;
	double sum=0;
	cout << "how many numbers? ";
	cin >> count;
	ptr= new int [count];
	for (int i=0; i<count; i++){
		cout << "What is #" << i+1 << " number: ";
		cin >> ptr[i];
	}
	for (int i=0; i<count; i++){
		sum+=ptr[i];
	}
	double avg=sum/count;
	cout << "Average is: " << avg << endl;
	cout << "numbers above average: \n";
	for (int i=0; i<count; i++){
		if (ptr[i]>avg){
			cout << "number #" << i+1 << " which is " << ptr[i] << " is above the average\n";
		}
	}
	


	delete[] ptr;
	return 0;
}

