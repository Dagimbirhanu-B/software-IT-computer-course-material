#include<iostream>
using namespace std;
struct node {
	int num;
	node *nxt; 
};

void display();
struct node*start=NULL;
node*top=NULL;
void push(){
	char ask;
	do{
		node*temp;
		temp=new node;
		cout<<"Enter a number\n";
		cin>>temp->num;
		temp->nxt==NULL;
		if(start==NULL){
			start=temp;
			top=start;
		}
		else{
			top->nxt=temp;
			top=temp;
		}
		display();
		cout<<"Do you want to enter again(y/n)\n";
		cin>>ask;
	}while(ask='y'||ask=='Y');
	void pop()
	{char ask;
	int del_val;
	do{
		if(start==NULL)
		cout<<"the stack is emmpty\n";
		else{
			if(stsrt->nxt=NULL){
				del-val=top-.num;
				delete top;
				stars=NULL;
				top=start;
			}
		}
		else{ 
		node*temp=start;
		while(temp-.nxt!=top)
		temp=temp->nxt;
		del_val=top->num;
		temp->nxt=NULL
		delete top;
		top=temp;
		}
		cout<<del_val<<"is deleted\n";
		display(0);
		
	}
	cout<"Do u want to delete again(y/n)\n";
	cin ask;
	}while(ask=='y'||ask=='Y';)
	}
	void display()
	{

	node*temp;

	if(start==NULL)

	cout<<"start->nxtnull\n";
	else{cout<<"start->";
	temp=start;
		do{
	cout<<temp->num<<"->";
			temp=temp->nxt;
	}while(temp!NULL);
	cout<<"null\n";
	}
	int main(){
	int ch;
	char ask;
	menu:
	cout<<"enter 1 to push \n";
	cout<<"enter 2 to pop \n";
	cout<<"enter 1 to push \n";
	cin>>ch;
	if(ch==1){
		push();
		{
			goto menu;
		}
	}
	if(ch==2)
	{
		pop();
		{goto menu;}
	}
	if(ch==3){
		display();
		{goto menu;}
		if(ch==4)
		cout<<"good bye\n";
		else
		cout<<"invalid choice\n";
		
		}

