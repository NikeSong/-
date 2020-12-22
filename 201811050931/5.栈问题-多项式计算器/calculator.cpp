#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int expression_value()//一个表达式的值  表达式为项的加减 
{
    int result=term_value();
    while(true)
    {
        char op = cin.peek();
        if(op=='+'||op=='-')
        {
            cin.get();
            int value=term_value();
            if(op=='+') result +=value;
            else result -=value;
        }
        else break;
    }
    return result;
}

int term_value()//一个项的值  项可以是一个数，或者是乘除结构，乘除结构表现为是项的乘除 
{
    int result=factor_value();
    while(true)
    {  
        char op=cin.peek();
        if(op=='*'||op=='/')
        {
            cin.get();
            int value =factor_value();
            if(op=='*')
            result *=value;
            else result /=value;
        }
        else break;
    }
    return result;
}

int factor_value() //因子，因子可以是一个数，也可以是一个（表达式） 
{
    int result=0;
    char c=cin.peek();
    if(c=='(')
    {
        cin.get();
        result = expression_value();
        cin.get();
    }
    else
    {
        while(isdigit(c))
        {
            result=10*result+c-'0';
            cin.get();
            c=cin.peek();
        }
    }
    return result;
}

int main()
{
    cout<<expression_value()<<endl; //一个式子必然是一个表达式 
    return 0;
}








