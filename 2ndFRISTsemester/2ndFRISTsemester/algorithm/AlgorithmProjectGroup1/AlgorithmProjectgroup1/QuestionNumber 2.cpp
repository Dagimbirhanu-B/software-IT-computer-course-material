//2.Write a program that performs the following operations in stack 
//(push, pop and display elements of stack).(4pts)
#include <iostream>
using namespace std;
int stack[100], n=100, top=-1;
void push(int val) {
   if(top>=n-1)
   cout<<" Stack Overflow"<<endl;
   else {
      top++;
      stack[top]=val;
   }
}
void pop() {
   if(top<=-1)
   cout<<" Stack Underflow"<<endl;
   else {
      cout<<" "<<stack[top]<< " is popped from stack"<<endl;
      top--;
   }
}
void display() {
   if(top>=0) {
      cout<<" Stack elements are:\n\t";
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<"  ";
      cout<<endl;
   } else
   cout<<" Stack is empty\n";
}
int main() {
   int ch, val;
   cout<<"\t\t==================================="<<endl;
   cout<<"\t\t\tSTACK OPRETION"<<endl;
   cout<<"\t\t==================================="<<endl;
   cout<<"\t\t(1) to Push in stack"<<endl;
   cout<<"\t\t(2) Pop from stack"<<endl;
   cout<<"\t\t(3) Display stack"<<endl;
   cout<<"\t\t(4) Exit"<<endl;
   do {
       cout<<"\t-------------------------------------------"<<endl;
      cout<<"\t\tENTER YOUR CHOICE:\n\t ";
      cout<<"1 TO PUSH 2 FOR POP 3 TO Display 4 FOR EXIT\n";
       cout<<"\t--------------------------------------------"<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<" Enter value to be pushed:\n";
            cin>>val;
            push(val);
            cout<<" "<<val<<" is succesfuly pushed\n";
            break;
         }
         case 2: {
            pop();
            break;
         }
        
         case 3: {
            display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<" Invalid Choice"<<endl;
         }
      }
   }while(ch!=4);
   return 0;
}
