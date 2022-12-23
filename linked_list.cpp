#include<iostream>
using namespace std;
struct node{
	int data;
 	node *next;
	node *prev;
};
node * head;
node * tail;
node * index;
void linked_list_born(int ax)
{
	node *temp = new node();
	head = temp;
	temp->data = ax;
	temp->next = NULL;
	temp->prev = NULL;
	//index =	temp;
}
void in_middle(int ax, int pos)
{
 int pointer = 1;
 node *position = head;
 while (pointer < pos)
 {
 	position = position->next;
 	pointer++;
 }
 if(pos == 1)
 {
 	node * temp = new node();
 	head->next->prev = temp;
 	temp->next = head->next;
 	head->next = temp;
 	temp->prev = head;
 	temp->data = ax;
 }
 else if(position->next == NULL)
 {
 	node * temp = new node();
 	position->next = temp;
 	temp->prev = position;
 	temp->next = NULL;
 	temp->data = ax;
 	tail = temp;
 }
 else if(position->next != NULL)
 {
 	node * temp = new node();
 	position->next->prev = temp;
 	temp->next = position->next;
 	position->next = temp;
 	temp->prev = position;
 	temp->data = ax;
 }
 else
 {
 	cout<<"Invalid Number "<<endl;
 }
}
void last_element(int a)
{
	node * position = head;
	while(position->next != NULL)
	{
		//cout<<position->data<<endl;
		position=position->next;
	}
  node *temp = new node();
  position->next = temp;
  temp->prev = position;
  temp->next = NULL;
  temp->data = a;
  tail = temp;		
}
void show_all_elements()
{
	node *position = head;
	while(position->next != NULL)
	{
		cout<<position->data<<endl;
		position=position->next;
	} 
	cout<<position->data; 
	
 }
void delete_head()
{
 	node *temp = head;
 	temp->next->prev = NULL;
 	head = temp->next ;
 	free(temp);
}

void delete_tail()
{
  node *temp = tail;
  temp->prev->next = NULL;
  tail = temp->prev;
  free(temp); 	
}

void delete_in_middle(int pos)
{
 	int pointer = 1;
 	node *position = head;
 	while(pos != pointer)
 	{
 		position = position->next;
 		pointer++;
	}
	if(pos == 1)
 	{
		node *temp = head;
 		temp->next->prev = NULL;
 		head = temp->next ;
 		free(temp);
	}
	else if(position->next == NULL)
	{
		node *temp = position;
		temp->prev->next = NULL;
		tail = temp->prev;
		free(temp);
	}
	else if(position->next != NULL)
	{
		node *temp = position;
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		free(temp);
	}
	else
	{
		cout<<"Invalid Number ";
	}
 }
void circular_link()
{
 head->prev = tail;
 tail->next = head ;
	
} 
  
main(){
	linked_list_born(0);
	last_element(9);
    in_middle(1,1);
    in_middle(2,2);
    in_middle(3,3);
    in_middle(4,4);
    in_middle(5,5);
    in_middle(6,6);
    in_middle(69,4);
    delete_head();
    delete_tail();
    delete_in_middle(4);
	show_all_elements();	
}
