#include<iostream>
using namespace std;

class A{
	public:
		A(){
			cout<<"Hey I'm a A\n";
		}
		void add(){
			cout<<"We are in add A\n";			
		}
		virtual void mul(){
			cout<<"We are in mul A\n";
		} 
		virtual ~A(){
			cout<<"Deleteing A\n";
		}
};


class B:public A{
	public:
		B(){
			cout<<"Hey I'm a B\n";
		}
		void ad(){
			cout<<"We are in add B\n";
		}
		/*void mul(){
			A::mul();
			cout<<"We are in mul B\n";
		}*/
		~B(){
			cout<<"Deleteing B\n";
		}
};


int main(){
	A *a = new B();
	a->add();
	a->ad();
	a->mul();
	delete a;
}

