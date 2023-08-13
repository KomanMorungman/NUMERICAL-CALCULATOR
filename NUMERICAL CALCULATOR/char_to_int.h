#ifndef CHAR_TO_INT_H_INCLUDED
#define CHAR_TO_INT_H_INCLUDED
//Function used in infix to postfix expression conversion
int char_int_conv(char expn){
int temp1,temp2;
temp1=(int)expn;
switch(temp1){
case 48:temp2=0;
             break;
case 49:temp2=1;
             break;
case 50:temp2=2;
             break;
case 51:temp2=3;
             break;
case 52:temp2=4;
             break;
case 53:temp2=5;
             break;
case 54:temp2=6;
             break;
case 55:temp2=7;
             break;
case 56:temp2=8;
             break;
case 57:temp2=9;
             break;
default:break;
}
return temp2;
}


#endif
