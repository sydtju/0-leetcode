
class Solution {
public:
    int atoi(string str) {
        long long result_temp=0;
        int flag=1;
        int i=0;
        if(str.length()==0) return 0;
        while(1){
            if(str[i]==' ') i++;
            else if(str[i]=='-'){
                flag=-1;
                i++;
                break;
            }
            else if(str[i]=='+'){
                flag=1;
                i++;
                break;
            }
            else
                break;
        }
        for(int j=i;j<str.length();j++){
            if(str[j]>='0'&&str[j]<='9'){
                result_temp=result_temp*10+(str[j]-'0');
                if(flag==1&&result_temp>=2147483647) return 2147483647;
                if(flag==-1&&result_temp>=2147483648) return -2147483648;
            }
            else{
                break;
            }
        }
        return (int)(flag*result_temp);
        
    }
};
