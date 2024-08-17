//4.Write a program that performs the following operations in Double ended queue
// (enqueuer, dequeuer, and display elements of queue).(5pts)
#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
    Node *prev;
    
    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};
Node *front = NULL;
Node *rear = NULL;
// function to create a new node
Node* newNode(int x) {
    Node *node = new Node(x);
    return node;
}
void insertFront(int x) {
    // Create a new Node with required parameters
    Node *node = newNode(x);
    if (front == NULL) {
        // This is the first node to be inserted
        front = rear = node;
        cout<<"  "<<x<<" Is succesfuly inserted at the front\n";
    } 
	else {
        // Add the node before front
        node->next = front;
        front->prev = node;
        // update front
        front = node;
        cout<<"  "<<x<<" Is succesfuly inserted at the front\n";
    }

}

void insertEnd(int x) {
    // Create a new Node with required parameters
    Node *node = newNode(x);
    if (rear == NULL) {
        // This is the first node to be inserted
        front = rear = node;
        cout<<"  "<<x<<" Is succesfuly inserted at the END\n";
        
    }
	 else {
        // Insert the node after rear
        node->prev = rear;
        rear->next = node;
        // update rear
        rear = node;
        cout<<"  "<<x<<" Is succesfuly inserted at the END\n";
    }
}
void deleteFront() {
    if (front == NULL) {
        // no node to delete
        cout<<"  Dequeue is Empity : Underflow\n";
    }
    if (front == rear) {
        // only 1 node is present
        cout<<"  "<<rear->data<<" Is succesfully DELETED from FRONT OF Dequeue\n"; 
        front = rear = NULL;       
    } else {
        // delete front and move front ahead
        Node *temp = front;
        front = front->next;
        front->prev = NULL;
        // deallocate the memory taken by temp
        cout<<"  "<<temp->data<<" Is succesfully DELETED from FRONT of Dequeue\n"; 
        delete(temp);
    }
    
}
void deleteEnd() {
    if (rear == NULL) {
        // no node to delete
       cout<<"  Dequeue IS Empity: Underflow\n";
    }
    if (front == rear) {
        // only 1 node is present
         cout<<"  "<<rear->data<<" Is succesfully DELETED from END of Dequeue\n"; 
        front = rear = NULL;       
    } else {
        // delete rear and move rear backwards
        Node *temp = rear;
        rear = rear->prev;
        rear->next = NULL;
        cout<<"  "<<temp->data<<" Is succesfully DELETED from END of Dequeue\n"; 
        delete(temp);
    }
    
}
void display(){
	if(front==NULL){
		cout<<"Dequeue is Empity\n";
	}
else{
	Node *temp=front;
	cout<<"\tDequeue Elements Are\n";
	cout<<"\t======================\n\nFRONT --> ";
	while(temp!=NULL){
	cout<<temp->data<<" <--> ";
	temp=temp->next;	
	}
	cout<<"REAR\n";
}
}

   int main() {
      int c,i,ch;
     
     
      do
	  {
	  cout<<"\n\t\tENTER YOUR CHOICE:\n";
      cout<<"\t\t==================================="<<endl;
      cout<<"\t\tPress(1) TO Insert in to a Dequeue";
      cout<<"\n\t\tPress(2) To Delete element from Dequeue";
      cout<<"\n\t\tPress(3) To Display element of Dequeue";
      cout<<"\n\t\tPress(4) To Exit\n";
      cout<<"\t\t====================================\n\t\t";      
      cin>>c;
      switch(c) {
        case 1:
            cout<<"Enter the element to be inserted\n\t";
            cin>>i;
            cout<<"At which side you want to insert  (At END or FRONT)";
			cout<<"\n\tfor FRON Press(1)\n\t for END Press(2)\n\t";
            cin>>ch;
            if(ch==1){            
           insertFront(i);
            break;
            }
            else if(ch==2) {
           insertEnd(i);
            break;
            }
            else
            cout<<"INVALID choice please tray again\n\t";
            break;
         case 2:
         	cout<<"From which side you want to Delete (from FRONT or REAR)";
			cout<<" \n\t from FRONT Press(1)\n\t from REAR Press(2)\n\t";
            cin>>ch;
            if(ch==1){
          deleteFront();
            break;
            }
            else if(ch==2) {
            deleteEnd();
            break;
            }
            else
            cout<<"INVALID choice please try again\n\t";
            break;
            
          case 3:
         display();
         	break;
         case 4:
         cout<<"you choose to Exit from program\n";
            exit(1);
         break;
         default:
            cout<<"Invalid choice: Please choose again\n";
         break;
      }
   } while(c!=4);
}

