#include<iostream>
using namespace std;

    string convert(string s, int numRows) {
        int i,len = s.length();
        if(len<=numRows || numRows == 1)
            return s;
        
        string laser;
            
        int j,k,index;
        for(i = 0;i<numRows;i++){
            k = 2*numRows-2;
            for(j=0,index=i;index<len;j++,index = k*j+i){
                laser.append(1,s[index]);
                if(i == 0 || i == numRows-1)
                    continue;
                    
                if(k*(j+1)-i<len)
                    laser.append(1,s[k*(j+1)-i]);
            }
        }
        
        return laser;
    }

int main(){
	string s = "ABCDE",p;
	int i;	
	p = convert(s,4);
	cout<<p<<endl;


	cout<<"Length = "<<p.length()<<" "<<s.length()<<endl;
}
