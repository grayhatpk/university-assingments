#include<iostream>
using namespace std;
class linked_list;

class Node{
	private:
		string name;
		Node * next = NULL;
		Node * previous = NULL;
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
		Node * head = NULL;
		Node * tail = NULL;
	public:
		void show_head_node(){
		cout<<endl<<head->get_name()<<endl;	
		}
		
		void add_node_head(string data){
			// creating new node 
			Node * NewNode = new Node(data);
			if(head==NULL){

				head=NewNode;
				tail=NewNode;
			}
			else{
			head->previous=NewNode;
			NewNode->next=head;
			head=NewNode;
		}
	}
				
		
		void remove_node_head(){
			int len = length();
			if(head==NULL){
				cout<<"\n The Head Node cannot be deleted ";
			}
			else if(len==1){
				head=NULL;
				tail=NULL;
			}
			else{
				Node * temp=head;
				head=head->next;
				head->previous=temp->previous;
				
				delete temp;
			}
		}
		
		void add_node_tail(string data){
			Node * NewNode = new Node(data);
			if(tail==NULL){
				tail=NewNode;
				head=NewNode;
		}
			tail->next=NewNode;
			NewNode->previous=tail;
			tail=NewNode;
		}
		
		void removing_node_position(int position){
		int len=length();
		
		if(position>len)
		cout<<"\n Node cannot be removed from this position ";
		else{
			
			if(position==1)
				remove_node_head();
			else{
					Node * temp = head; 
					 int count=1;
					 
					while(temp!=NULL&&count!=position){
					 	temp=temp->next;
					 	count++;
					 }
					 
					 temp->previous->next=temp->next;
					 temp->next->previous=temp->previous;
					 delete temp;
							
			}
			
		} 
	}
			
		void add_node_position(int position,string data){
			int len=length();
			
			if(len<position)
				cout<<"\n The Data cannot be added at this position "<<endl;
			else{
						
			    if(position==1)
			   		add_node_head(data);
			
				else{
				
					int count = 1;
					Node * point = head ;
				
					while(point!=NULL&&count!=position){
						point=point->next;
						count++;
			}
					Node * newNode = new Node(data);
					
					newNode->next=point->next;
					point->next->previous=newNode;
					point->next=newNode;
			    	newNode->previous=point;
		}
			}}
	
	int length(){
		Node * pointer = head;
		int count=0;
		
		while ( pointer != NULL){
				count++;
				pointer=pointer->next;
	}
		return count;		
	}
	
	void printing_all_nodes(){
		
		if(head==NULL)
			cout<<" The Data cannot be printed "<<endl;
		
		else{
		Node * temp = head;	
		
		while(temp!=NULL){
			cout<<temp->get_name()<<endl;
			temp=temp->next;
	
	}}}
	
	void current_node_element(Node * point){
		cout<<point->get_name();
	}
	
	void next_node(Node *  hnext){
		hnext=hnext->next;
		return hnext;
	}
	
	void main_method(){
		add_node_tail("Noman");
		add_node_tail("Masood");
		add_node_head("MR.");
		remove_node_head();
		remove_node_tail();
	    current_node_element(Node * point);
		add_node_position(2,"Cyber Student");
		removing_node_position(1);
		show_head_node();
		printing_all_nodes();			
}
int main(){
	linked_list * obj = new linked_list();
	obj->main_method();
}





