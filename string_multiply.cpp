#include<iostream>
#include<string>
using namespace std;

    string reverse(string str){
        int len = str.length();
        int i,j;
        char temp;
        for(i=0,j=len-1;i<j;i++,j--){
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
        return str;
    }
    
    string remove_leading_zeros(string str){
	int len = str.length(),i=0;
	string new_string;
	while(str[i] == '0') i++;
	while(i<len){
		new_string = new_string + str[i];
		i++;
	}

	return new_string;
    }

    string addition(string first,string second){
        if(first.empty()) return second;
        if(second.empty()) return first;
        int carry = 0;
        int len1 = first.length(),len2 = second.length();
        int var1 = len1-1,var2 = len2-1;
        
        string new_str;
        
        while(var1 >= 0 && var2 >= 0){
            int val = carry + int(first[var1])-48 + int(second[var2])-48;
            carry = val/10;
            val = val%10;
            new_str = new_str + char(val+'0');
            var1--,var2--;
        }
        
        if(var1>=0){
            while(var1>=0){
                int val = carry + int(first[var1])-48;
                carry = val/10;
                val = val%10;
                new_str = new_str + char(val+'0');
                var1--;
            }
        }
        else if(var2>=0){
            while(var2>=0){
                int val = carry + int(second[var2])-48;
                carry = val/10;
                val = val%10;
                new_str = new_str + char(val+'0');
                var2--;
            }           
        }
        
        if(carry >= 1)
            new_str = new_str + char(carry+'0');
        
        new_str = reverse(new_str);
        
        return new_str;
    }
    
    string mult(string str,char s){
        int carry = 0,len = str.length();
        int var = len-1;
        int multiplier = int(s)-48;
        string answer;
        while(var>=0){
            int val = carry + (int(str[var])-48)*multiplier;
            carry = val/10;
            val%=10;
            answer = answer + char(val+'0');
            var--;
        }
        
        if(carry >=1)
            answer = answer + char(carry+'0');
        
	//cout<<answer<<" ";

        answer = reverse(answer);
        
        return answer;
    }

    string multiply(string num1, string num2) {
        if(num1.empty()) return num1;
        if(num2.empty()) return num2;

        
        string answer,inter_mid;
        int len1 = num1.length(),len2 = num2.length();

	if((len1 == 1 && num1[0] == '0')||(len2 == 1 && num2[0] == '0')) return "0";        
        
        if( len1> len2){
            for(int i=len2-1;i>=0;i--){
                string answer_mid;
                answer_mid = mult(num1,num2[i]);
                if(i < len2-1){
                    inter_mid = inter_mid + '0';
                    answer_mid = answer_mid + inter_mid;
                }
                answer = addition(answer,answer_mid);
            }
        }
        else{
            for(int i=len1-1;i>=0;i--){
                string answer_mid = "";
                answer_mid = mult(num2,num1[i]);
		//cout<<answer_mid<<endl;
                if(i < len1-1){
                    inter_mid = inter_mid + '0';
                    answer_mid = answer_mid + inter_mid;
                }
                answer = addition(answer,answer_mid);
            }
        }
        
	if(answer.length() != 1)
		answer = remove_leading_zeros(answer);

        return answer;
    }

int main(){
	cout<<multiply("6020453667958309279424408570378228292268488402","0021473700594524297017810575200827941459805716642468749607585313713214621412");
}
