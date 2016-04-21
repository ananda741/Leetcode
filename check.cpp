#include<iostream>
using namespace std;

struct emp{
	char name[20];
	int age;
	float sal;
};

emp e1 = {"Amol",21,2345.00};
emp e2 = {"Ajay",19,2300.00};
emp e3 = {"Aditya",21,3306.44};

int main(){
	emp &fun();
	fun() = e2;
	cout<<endl<<e2.name<<" "<<e2.age<<" "<<e2.sal<<endl;
}

emp &fun(){
	
	return e3;
}
