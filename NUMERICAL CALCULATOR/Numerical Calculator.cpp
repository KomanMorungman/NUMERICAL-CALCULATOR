#include<iostream>
using namespace std;
#include<cstring>
#include<cstdio>
#include<cmath>
#include"char_to_int.h"
#include"pop.h"
int prior(char ch);
void pop(char expn,int p1,int &top1,int &top2,char *arr1,char *arr2);
int  char_int_conv(char expn);
double pop(double *arr4,int &top3);
int main(){
                  /*START--INFIX TO POSTFIX CONVERSION*/
char expn[30];
int p1,i,j,s,temp,top1=-1,top2=-1,check=0,tem_length=0,num1=0;
float num2=0;
                     /*Input Taken*/
cout<<"Enter infix expression with ';' to end:";
gets(expn);
s=strlen(expn);
double arr3[s];
char arr1[s],arr2[s];/*arr1 stores operators and '('
                                arr2 stores the postfix expression with numbers substituted by q
                                and arr3 holds numbers in the expression*/

                       /*Priority Assignment and Conversion*/
for(i=0;i<s;i++){
p1=prior(expn[i]);
switch(p1){
case 0:if((int)expn[i]>47&&(int)expn[i]<58){
           top2++;
           arr2[top2]='q';
           temp=i;
           while((int)expn[i]>47&&(int)expn[i]<58){
           tem_length++;
           i++;
           }
           for(j=tem_length;j>0;j--){
            num1=num1*10+char_int_conv(expn[temp]);
            temp++;
           }
           tem_length=0;
           if(expn[i]=='.'){
           temp=++i;
           while((int)expn[i]>47&&(int)expn[i]<58){
           tem_length++;
           i++;
           }
           for(j=1;j<=tem_length;j++){
            num2=num2*10+char_int_conv(expn[temp]);
            temp++;
           }
            num2*=pow(10,-tem_length);
           }
            i--;
            tem_length=0;
            arr3[top2]=num1+num2;
            num1=0;
            num2=0;
            temp=0;

            }
            else if(expn[i]==';'){
                while(top1>-1){
                    top2++;
                    arr2[top2]=arr1[top1];
                    top1--;
                }
            }
            else check=-1;
            break;
case 2:if(expn[i+1]=='-'){
        top2++;
       arr2[top2]='q';
       i=i+2;
       temp=i;
       while((int)expn[i]>47&&(int)expn[i]<58){
           tem_length++;
           i++;
           }
           for(j=tem_length;j>0;j--){
            num1=num1*10+char_int_conv(expn[temp]);
            temp++;
           }
           tem_length=0;
           if(expn[i]=='.'){
           temp=++i;
           while((int)expn[i]>47&&(int)expn[i]<58){
           tem_length++;
           i++;
           }
           for(j=1;j<=tem_length;j++){
            num2=num2*10+char_int_conv(expn[temp]);
            temp++;
           }
            num2*=pow(10,-tem_length);
}
           if(expn[i]!=')'){
            top1++;
            arr1[top1]='(';
            i--;
           }
            tem_length=0;
            arr3[top2]=-(num1+num2);
            num1=0;
            num2=0;
            temp=0;

}
else{
              top1++;
          arr1[top1]=expn[i];
}
           break;
case 1:
case 3:
case 4:
case 5:pop(expn[i],p1,top1,top2,arr1,arr2);
            break;
default:break;
}
if(check!=0)
    break;
}
arr2[++top2]=';';
                  /*Postfix Expression*/
cout<<"\nPostfix Expression:";
if(check!=0)
    cout<<"Typo in expression";
else{
    for(i=0;i<=top2;i++)
    cout<<arr2[i]<<" ";
    cout<<endl;
}
 /*END--INFIX TO POSTFIX CONVERSION*/

                /*START-POSTFIX CALCULATION*/
int s1,top3=-1;
s1=strlen(arr2);
double arr4[s1],p3,p2;
for(i=0;i<s1;i++){
switch(arr2[i]){
case '^':p2=pop(arr4,top3);
              p3=pop(arr4,top3);
              top3++;
              arr4[top3]=pow(p3,p2);
              break;
case '/':p2=pop(arr4,top3);
              p3=pop(arr4,top3);
              top3++;
              arr4[top3]=p3/p2;
              break;
case '*':p2=pop(arr4,top3);
              p3=pop(arr4,top3);
              top3++;
              arr4[top3]=p3*p2;
              break;
case '+':p2=pop(arr4,top3);
              p3=pop(arr4,top3);
              top3++;
              arr4[top3]=p3+p2;
              break;
case '-':p2=pop(arr4,top3);
              p3=pop(arr4,top3);
              top3++;
              arr4[top3]=p3-p2;
              break;
case ';':cout<<"Result:"<<arr4[top3];
            break;
default:top3++;
            arr4[top3]=arr3[i];
            break;
}
             /*END-POSTFIX CALCULATION*/
}
return 0;
}

             /*START-Functions used in postfix calculation*/

              /*END-Functions used in postfix calculation*/



