#include<iostream>
using namespace std;

class singleton{
	int value;
	static singleton *global;
	singleton(int v = 0){
		value = v;
	}
	public:
		void get_value(){ cout<<value;}
		void set_value(int v){value = v;}
		static singleton *instance(){
			if(!global)
			global = new singleton();
			return global;
		}
};

singleton *singleton::global = 0;

int main(){
	
	singleton::instance()->set_value(5);
	singleton::instance()->get_value();
}
