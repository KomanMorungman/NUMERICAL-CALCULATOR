#ifndef POP_H_INCLUDED
#define POP_H_INCLUDED
//Functions used in infix to postfix expression conversion
/*Priority Assignment Function*/
int prior(char ch){
int p2;
switch(ch){
case '^':p2=5;
              break;
case  '*':p2=4;
             break;
case  '/':p2=4;
             break;
case  '+':p2=3;
             break;
case  '-':p2=3;
             break;
case  '(':p2=2;
             break;
case  ')':p2=1;
             break;
default:p2=0;
             break;
}
return p2;
}
void pop(char expn,int p1,int &top1,int &top2,char *arr1,char *arr2){
if(expn==')'){
   while(arr1[top1]!='('){
            if(top1==-1){
            cout<<"underflow"<<endl;
            top1++;
            break;
         }
         else{
        top2++;
        arr2[top2]=arr1[top1];
        top1--;
         }

         }
         top1--;
}
else{
    if(prior(arr1[top1])>=p1&&top1!=-1){
        while(prior(arr1[top1])>=p1&&top1!=-1){
            if(arr1[top1]=='('){
                arr1[top1]=expn;
                break;
               }
               else{
                top2++;
                arr2[top2]=arr1[top1];
                top1--;
               }
        }
        arr1[++top1]=expn;
    }
    else{
        top1++;
        arr1[top1]=expn;
    }
}
}
//Function used in postfix calculation
double pop(double *arr4,int &top3){
float n;
if(top3==-1){
    cout<<"\nUnderflow";
    return ' ';
}
else {
    n=arr4[top3];
    top3--;
}
return n;
}


#endif //
