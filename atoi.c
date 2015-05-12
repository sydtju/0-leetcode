//将字符串转为整数  (1)去掉前面的空格 并且取正负号  (2)对后面的数字进行处理  （3）int的范围 需要注意  
//(4)遇到非数字退出  并返回前面的数字  
//c语言  运行时间是6ms
int myAtoi(char *str) {
        long long result_temp=0;
        int flag=1;
        int i=0;
        if(str==NULL) return 0;
        while(str[i]!='\0'){
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
        for(int j=i;str[j]!='\0';j++){
            if(str[j]>='0'&&str[j]<='9'){
                result_temp=result_temp*10+(str[j]-'0');
                if(flag==1&&result_temp>=2147483647) return 2147483647;//极值处理
                if(flag==-1&&result_temp>=2147483648) return -2147483648;
            }
            else{
                break;
            }
        }
        return (int)(flag*result_temp);
}
