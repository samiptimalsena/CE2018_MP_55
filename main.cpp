#include "stack.h"
#include "iostream"
#include "ctype.h"
#define POSTFIX_SIZE 100

using namespace std;

stack::stack(){
    top=-1;
}

stack::~stack(){
    
}

void stack::push(int element){
    if(top>=MAX_SIZE-1){
        cout<<"cannot push"<<element<<endl;
    }
    else{
        top++;
        this->element[top]=element;
    }
}

int stack::pop(){
    if(top<0){
        cout<<"Stack is empty"<<endl;
    }
    else{
        return this->element[top--];
    }
}


void postFixEval(char postFix[],int size){
    int i,A,B;
    int val=0;
    char ch;
    stack s;
    for(int i=0;i<size-1;i++){
        ch=postFix[i];
        if(isdigit(ch)){
            s.push(ch-'0');
        }
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' ){
            A=s.pop();
            B=s.pop();
            switch(ch){
                case '+':
                    val=A+B;
                    break;
                case '-':
                    val=B-A;
                    break;
                case '*':
                    val=B*A;
                    break;
                case '/':
                    val=B/A;
                    break;
                    
            }
            s.push(val);
            
        }
    }
    cout<<"The required value of postFix is"<<s.pop();
}

int main(){
    int i=0,size=1;
    char postFix[POSTFIX_SIZE];
    cout<<"Enter posfix Expression"<<endl;
    cout<<"press d or D when done"<<endl;
    for(i=0;i<POSTFIX_SIZE;i++){
     cin>>postFix[i];
     size++;
     if(postFix[i]=='d'||postFix[i]=='D'){
         break;
     }  
    }
    postFixEval(postFix,size);

    
    
}
