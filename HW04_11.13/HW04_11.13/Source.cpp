#include <iostream>
#include <string>
using namespace std;

class Course{
private:
	string courseName;
	string *students;
	int numberOfStudents;
	int capacity;
public:
	Course (const string &courseName, int capacity){
		numberOfStudents=0;
		this->courseName = courseName;
		this->capacity=capacity;
		students=new string [capacity];
		for (int i=0; i<capacity; i++){
			students[i]="";
		}
	}
	~Course(){
		delete[] students;
	}
	string getCourseName() const{
		return courseName;
	}
	void addStudent (const string &name){
		students[numberOfStudents]=name;
		numberOfStudents++;
		if (numberOfStudents==capacity){
			string* tempstudents= new string [capacity+1];
			for (int i=0; i<numberOfStudents; i++){
				tempstudents[i]=students[i];
			}
			delete[] students;
			students=tempstudents;
		}
	}
	void dropStudent(const string &name){
		if (students[numberOfStudents-1]==name){
			students[numberOfStudents-1]="";
		}
		else{
			bool test=false;
			for(int i=0; i<numberOfStudents-1; i++){
				if (test){
					students[i]=students[i+1];
				}
				else{
					if (students[i]==name){
						students[i]=students[i+1];
						test= (!test);
					}
				}
			}
			students[numberOfStudents-1]="";
		}
		numberOfStudents--;
	}
	string* getStudents(){
		return students;
	}
	int getNumberOfStudents() const{
		return numberOfStudents;
	}
	void clear(){
		for (int i=0; i<numberOfStudents; i++){
			students[i]="";
		}
	}
	Course (const Course&);
};

int main (){
	Course a("Geology",5);
	a.addStudent("Jack");
	a.addStudent("Diane");
	a.addStudent("Robert");
	a.dropStudent("Robert");
	string*p=a.getStudents();
	for (int i=0; i<a.getNumberOfStudents(); i++){
		cout << p[i] << endl;
	}
	return 0;
}