#include<iostream>
using namespace std;
class linked_list;

class Node{
	private:
		string name;
		Node * next = NULL;
	public:

		Node(string name){   
			this->name=name;
		}
		string get_name(){
			return name;	
		}
		Node * getnext(){
			return next;
		}
		void setnext(Node * next){
			this->next=next;
		}
		friend linked_list;
};

class linked_list{
	private:
		Node * head;
		Node * currentNode ;
	public:
		linked_list();
	void adding_any_position(string name,int position);
		void removig_any_position(int position);
		void add_node_head(string name);
         void remove_node_head();
		void show_head_node();
		void add_tail(string name);
		void remove_tail();
		void show_current(Node * point);
		void printing_data();
		void traverse();
		Node * next(Node * point);
		int length();
		Node * goto_start(Node * point);
		void main_method();
};

linked_list::linked_list(){
			head=NULL;
			currentNode=NULL;
}		
		
void linked_list::removig_any_position(int position){
			int len=length() , count=1;
			
			if (position==1){
				remove_node_head();
			}
			else {
				Node * current=head;
				Node * previous;
				
			do{ 
			previous=current;
			current=current->next;
			count++;
			}while(count!=position);
				
			previous->next=current->next;
			delete current;
										
				}
			}			
void linked_list::adding_any_position(string name,int position){
			
		Node * NewPoint= new Node(name);  
		// creating new node
		Node * temp = head;
		int count=1;	
		int len=length();

		if(position<=len){
		
			while(count!=position){
 				temp = temp->next;  
				 // going to next node
			 	count++;
			 }
			
			NewPoint->next = temp->next;
			temp->next=NewPoint;
			}
	else 
	cout<<"\n The Node can not be added at this position";
		
}
void linked_list::add_node_head(string name){
		
			Node * point = new Node(name);
			   point->next=head;
			   head=point;
			   
	cout<<"\n The Node is succesfly added to the head of the Linked list "<<endl;		
}

void linked_list::show_head_node(){
		if(head==NULL){
			cout<<"\n The class head is empty";
		}
		else{
			Node * point = head;
			cout<<"\n Data at the head of the Node is "<<point->get_name()<<endl;
			}
		}
void linked_list::remove_node_head(){
		
		Node * point = head;
		head=head->next;
		delete point;
		
	cout<<"\n The node at the head of the node is deleted "<<endl;
}

int linked_list::length(){
	int count=0;
	
	Node * point = head;
	while(point!=0){
		count++;
		point=point->next;
	}
	return count;
}

void linked_list::remove_tail(){
	
	Node * current = head;
	Node * previous = head;
	current = current->next;
	while(current->next!=NULL){
		previous = previous->next;
		current  = current->next;
	}
	previous->next=current->next;
	delete current;
}
void linked_list::add_tail(string name){
	Node * point = head;
	Node * node = new Node(name);
	
	while(point->next!=NULL){
		point=point->next;	
	}
	point->next=node;
	node->next=NULL;
	
}
void linked_list::printing_data(){
	Node * point = head;
	 while( point!=NULL){
	 	cout<<point->get_name()<<endl;
	 	point=point->next;
	 }
}
void linked_list::show_current(Node * point){
	cout<<"\n THE data of the current Node is "<<point->get_name();
}

Node * linked_list::next(Node * point){
	point=point->next;
	return point;
}
Node * linked_list::goto_start(Node * point){
	point=head;
	return point;
}

void linked_list::main_method(){
	
	add_node_head(" Noman masood khan");
	add_node_head(" hassan Raza ");
	add_tail("ali");
	remove_tail();
	
	adding_any_position("Ali khan",1);
	printing_data();
	
	removig_any_position(3);
	printing_data();
		
}

int main(){
	
	linked_list * dynamicObj = new linked_list();
	
	dynamicObj->main_method();
	
	
}
