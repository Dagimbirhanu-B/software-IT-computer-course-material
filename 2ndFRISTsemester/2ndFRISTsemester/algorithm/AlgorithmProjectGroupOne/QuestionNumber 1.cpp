 //1.	Write a program that performs the following operations in linked list.
 //(create node, insert node at beginning, insert node at last, insert node at any position, 
 //sort lists, delete a particular node, search elements from the list, display lists,
 //and reverse the list). (7Pts)
 
 #include<iostream>
 using namespace std;

struct node
{
    int data;
    struct node *next;
};
node*head=NULL,*rev=NULL;int count=0;
//function to create a node
void create_node(int d)
{
node*temp,*temp1;
temp=new node;
temp->data=d;
temp->next=NULL;
count++;
if(head==NULL){
    head=temp;
}
else{
    temp1=head;
    while(temp1->next!=NULL)
    temp1=temp1->next;
     temp1->next=temp; 
}
}
//Funciton to Insert node at beginning
void InsertAtBigining(int x)
{
node*temp=new node;
temp->data=x;
temp->next=NULL;
count++;
if(head==NULL)
head=temp;
else
{
temp->next=head;
head=temp;
}
    
}
//Funcition to Insert node at last
void InsertAtLast(int x)
{
node*temp=new node;
temp->data=x;
temp->next=NULL;
count++;
if(head==NULL)
head=temp;
else
{
node*temp2=head;
while(temp2->next!=NULL)
{
temp2=temp2->next;
}
temp2->next=temp;   
} 
}

//////Function to insert element at any poistion
void InserAtAnyPosition(int data,int n){
	node*temp1=new node();
	temp1->data=data;
	temp1->next=NULL;
	count++;
	if(n==1){
		temp1->next=head;
		head=temp1;
		return;
	}
	node*temp2=head;
	for(int i=0;i<n-2;i++)
	{
		temp2=temp2->next;
		}
		temp1->next=temp2->next;
		temp2->next=temp1;
		
	}
	
//////Functiob to sort a list
void sort(){
	node*i,*j;
	int temp;
	for(i=head;i!=NULL;i=i->next){
		for(j=i->next;j!=NULL;j=j->next){
			if(i->data>j->data){
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
		}
	}
}
//////function to delete a particular node
void DeleteAnyNode(int x)
{
node*temp,*temp3;
if(head==NULL)
cout<<"No data inside list \n";
if(head->data==x)
{
temp=head;
head = head->next;
delete temp;
count--;
}
else
{
temp = head;
while(temp->data!=x)
{
temp3 = temp;
temp = temp->next;
}
temp3->next = temp->next;
delete temp;
count--;
}
}
////Function to search elements from the list
void search(int n){
node*temp=head;
int count=0,found=0;
while(temp!=NULL)
{
	count++;
	if(temp->data==n)
	{
	  found=1;
		break;
	}
	temp=temp->next;
	}
	if(found==1)
	cout<<n<<" is found at at position----->"<<count<<endl;
	else
	cout<<n<<" IS NOt found in the list"<<endl;
	  	
	
}

///FUNCTION TO DISPLAY INFORMATION//
void display()
{
node *temp;
if(head==NULL)
cout << "No data inside\n";
else
{
temp=head;
cout<<"head";
while(temp!=NULL)
{
cout<<"------>"<<temp->data;
temp=temp->next;
}
}
cout<<endl;
}
//FUnction to reverse the list
node reverse(node*head) 
    { 
        node *current = head; 
        node *prev = NULL, *next = NULL; 
        while (current != NULL) 
        { 
            // Store next 
            next = current->next; 
  
            // Reverse current node's pointer 
            current->next = prev; 
  
            // Move pointers one position ahead. 
            prev = current; 
            current = next; 
        } 
        rev= prev;         
    } 
int main()
{
int m,n, choice;
int value[20];
cout<<"==================================="<<endl;
cout<<"\tLINkED LIST OPRETION\n";
cout<<"==================================="<<endl;
do
{
cout<<"== What operation you are going to do?"<<endl;
cout<<"\tPress 1: To Create Node"<<endl;
cout<<"\tPress 2: To Insert Node at beginning"<<endl;
cout<<"\t Press 3: To Insert node at last"<<endl;
cout<<"\t Press 4: To Insert node at position "<<endl;
cout<<"\t Press 5: To Sort Link List"<<endl;
cout<<"\t Press 6: To Delete a Particular Node"<<endl;
cout<<"\t Press 7: To Search Element in the list"<<endl;
cout<<"\t Press 8: To Display the content of Linked Lists"<<endl;
cout<<"\t Press 9: To Exit"<<endl;
cout<<"==================================="<<endl;
cout<<"\tEnter Your Choice:  ";
cin>>choice;
int d;	
switch(choice)
{
case 1:
cout<<"you choose to create a NODE\n"<<endl;
cout<<"How many element you want create in the link list:\n ";
cin>>m;
cout<<"\nEnter elements of the linked list1:"<<endl;
for(int i=1;i<=m ; i ++)
{
cout<<"  Enter element "<<i<<" :";
cin>>value[i];
create_node(value[i]);
}
cout<<"  link lis of "<<m<<" element is succesfuly created:\n"<<endl;
break;
case 2:
cout<<"you choose to INSERT AT FRONT of link\n"<<endl;
cout<<"\nEnter an element to insert at the FRONT:\n"<<endl;
int a;
cin>>a;
InsertAtBigining(a);
cout<<"\nElement is succesfuly inserted at the front:\n"<<endl<<"\t";
break;
case 3:
cout<<"you choose to INSERT AT END of link\n"<<endl;
cout<<"\n Enter an element to insert at the END:\n"<<endl;
cin>>a;
InsertAtLast (a);
cout<<"\n Element is succesfuly inserted at the end:\n"<<endl<<"\t";
break;
case 4:
cout<<"\n YOU choose insert element at any position:\n"<<endl;
cout<<"enter position you want to inter data in a list\n"<<endl;
cin>>n;
if(n>count+1||n<=0){
	cout<<"Position NOT FOUND\n";
}
else{
cout<<"enter data you want to insert in to  a list"<<endl;
cin>>a;
InserAtAnyPosition(a,n);
cout<<"\nElement is succesfuly inserted in to list if you want see enter 8 to display:\n"<<endl<<"\t";
}
break;

case 5:
cout<<"\n YOU choose sort element of linked list:\n"<<endl<<"\t";
sort();
cout<<"\nElement is succesfuly sorted  if you want see it by displaying elements:\n"<<endl<<"\t";
break;
case 6:
	{
	
cout<<"\n YOU choose to delete element from any position:\n"<<endl<<"\t";
cout<<"choose element to delete from link"<<endl;
cin>>a;
node*t=head;int found=0;
while(t!=NULL){
	if(t->data==a){
		found=1;
		break;
	}
	else{
		found==0;
	}
	t=t->next;
}
if(found==0){
cout<<"Element you want to DELETE IS NOT FOUND in the list\n";
break;
}
else{
 DeleteAnyNode(a);
cout<<"\nElement is succesfuly Deleting from list:\n"<<endl<<"\t";
break;
}
}
break;
case 7:
cout<<"enter element you want to search  "<<endl<<"\t";
cin>>a;
search(a);
break;
case 8:
	cout<<"In which order you want to display PRESS\n";
	cout<<"\t1 for Normal order\n\t2 for REVERSE order\n\t";
	cin>>d;
	if(d==1){
cout<<"The linked list has:" <<count<<" \nElements and looks like this\n"<<endl<<"\t";
display();
}
else if(d==2){
reverse(head);
head=rev;
cout<<"\nwhen we Reverse linked list it look like this\n\n\t";
display();
}
else{
	cout<<"\nInvalid choice\n";
}
break;
case 9:
cout<<"you chose to exit"<<endl<<"\t";
exit(0);
break;
default:
cout<<"Invalid entry, good bye"<<endl;
}

}while(choice!=9);
return 0;
}

