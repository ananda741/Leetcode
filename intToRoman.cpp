#include<iostream>
using namespace std;

    string intToRoman(int num) {
        string roman;
        
        int laser,i;
        if(num>=1000){
            laser = num/1000;
            for(i=0;i<laser;i++)
                roman+='M';
            num%=1000;
        }
        if(num>=100){
            laser = num/100;
            if(laser == 9)
                roman+="CM";
            else if(laser>=5){
                roman+='D';
                for(i=0;i<laser-5;i++)
                    roman+='C';
            }
            else if(laser == 4)
                roman+="CD";
            else if(laser>=1){
                for(i=0;i<laser;i++)
                    roman+='C';
            }
            
            num%=100;
        }
        
        if(num>=10){
            laser = num/10;
            if(laser == 9)
                roman+="XC";
            else if(laser>=5){
                roman+='L';
                for(i=0;i<laser-5;i++)
                    roman+='X';
            }
            else if(laser == 4)
                roman+="XL";
            else if(laser>=1){
                for(i = 0;i<laser;i++)
                    roman+='X';
            }
            
            num%=10;
        }
        
        if(num>=1){
            laser = num;
            if(laser == 9)
                roman+="IX";
            else if(laser>=5){
                roman+='V';
                for(i=0;i<laser-5;i++)
                    roman+='I';
            }
            else if(laser == 4)
                roman+="IV";
            else if(laser>=1){
                for(i=0;i<laser;i++)
                    roman+='I';
            }
        }
        
        return roman;
    }


int main(){
	cout<<intToRoman(4);
}
