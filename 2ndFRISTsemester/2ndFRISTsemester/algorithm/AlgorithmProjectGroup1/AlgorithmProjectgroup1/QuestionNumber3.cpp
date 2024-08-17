//3.	Write a program that performs the following operations in Priority queue 
//(enqueuer, dequeuer, and display elements of queue).(4pts)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
struct node
 {
   int p;
   int info;
   struct node *next;
};
class Priority_Queue {
   private:
      node *head;
   public:
      Priority_Queue()
	   {
         head= NULL;
      }
      void insert(int i, int p) {
        node *temp, *q;
         temp = new node;
        temp->info = i;
        temp->p = p;
         if (head== NULL || p <head->p) {
            temp->next=head;
            head= temp;
         } 
		 else {
            q = head;
            while (q->next != NULL && q->next->p <= p)
               q = q->next;
               temp->next= q->next;
               q->next= temp;
         }
         cout<<i<<" is succesfuly entered in to queue\n";
      }
      void del() {
         node *temp;
         if(head == NULL)
            cout<<" Queue Underflow means queue is empity\n";
         else {
            temp = head;
            cout<<temp->info<<" IS succesfuly Deleted From QUEUE "<<endl;
            head= head->next;
            free(temp);
         }
      }
      void Display() 
	  {
        node *ptr;
         ptr = head;
         if (head == NULL)
            cout<<"Queue is empty\n";
         else {
            cout<<"Queue looks like this:\n";
            cout<<"\tDATA \tPRIORITY\n";
            while(ptr != NULL) {
               cout<<"\t "<<ptr->info<<"\t "<<ptr->p<<endl;
               ptr = ptr->next;
            }
         }
      }
};
int main() {
   int c, i, p;
   Priority_Queue pq;
      cout<<"\n\t\tTHIS IS PRIORITY QUEUE OPRETION\n";
      cout<<"\t========================================="<<endl;
      cout<<"\t\t(1)Insert\n";
      cout<<"\t\t(2)Delete\n";
      cout<<"\t\t(3)Display\n";
      cout<<"\t\t(4)Exit\n";
      
   do
   {
       cout<<"\t======================================================="<<endl;
       cout<<"\t\t\t\tEnter your Choice\n";
       cout<<"\t\t\t\t------------------\n";
       cout<<"\t1=TO Insert or 2=TO Delete or 3=TO Display or 4=TO Exit\n\t\t";
      
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Ensert item value you want to INSERT in to queue : \n";
            cin>>i;
            cout<<"Enter its priority : ";
            cin>>p;
            pq.insert(i, p);
            break;
         case 2:
            pq.del();
            break;
         case 3:
            pq.Display();
            break;
         case 4:
         cout<<"your choice is to Exit from program OK thanks";
            break;
         default:
         cout<<"\n\t Sorry you choose INVALID CHOICE please correct your choice \n";
      }
   }
   while(c != 4);
   return 0;
}
