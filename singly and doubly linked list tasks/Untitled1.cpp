#include<iostream>
#include<Windows.h>
using namespace std;

class student{
	private:
		string name,depart,semes;
		int regid;
		student * next=NULL;  // address of the next node
		student * previous=NULL; //address of then previous node
	public:
		student(string,string,string, int );
		void set_name(string);
		void set_department(string);
		void set_semester(string);
		void set_regid(int );
		string get_name();
		int  get_id();
		string get_department();
		string get_semester();
		
		friend class student_list;
};

student::student(string name,string depart,string semes,int regid){
	this->name=name;
	this->depart=depart;
	this->semes=semes;
	this->regid=regid;
	
}
 
 void student::set_name(string name){
 	this->name=name;
 }
 
 void student::set_department(string depart){
 	this->depart=depart;
 }
 void student::set_regid(int regid){
 	this->regid=regid;
 }
 
 void student::set_semester(string semester){
 	this->semes=semester;
 }
 
 string student::get_department(){
 	return depart;
 }
 int  student::get_id(){
 	return regid;
 }
 
 string student::get_name(){
 	return name;
 }
 string student::get_semester(){
 	return semes;
 }
 
 class student_list{
 	private:
 		student * head=NULL;
 		student * tail=NULL;
 	public:
 		void adding_node_head(string,string,string,int );
		void adding_node_tail(string,string,string,int );
		void adding_node_position(int position);
		void printing();
		void deleting_node_head();
		void deleting_node_tail();
		void deleting_specific_node(); 	
		int length();
		void adding_middle(string,string,string,int,int pos);
		void deleting_middle(int pos);
 };
 	void student_list::deleting_middle(int pos){
 		
 		
 		
 		
 		
 		
 		
 		
 		
 		
 		
 		
 		
 		

 		
	 
	 
	 
	 
	 
	 }
	void student_list::adding_middle(string depart,string name,string semes,int id,int pos){
		student* newNode= new student(name,depart,semes,id);	
		
		int count=1;
		student * temp = head;
		
		while(count<pos){
			temp=temp->next;
			count++;
		}
		
		newNode->next=temp;
		newNode->previous=temp->previous;
		temp->previous->next=newNode;
		newNode->previous=newNode;
		
	}
 
 void student_list::adding_node_head(string depart,string name,string semes,int id ){
    student* NewNode= new student(name,depart,semes,id);
 	
	 if(head==NULL){
 		head=NewNode;
 		tail=NewNode;
 		cout<<"\n\tTHe Node is succesfly added at the head ";
	 }
	else{
		NewNode->next=head;
 		head->previous=NewNode;
 		head=NewNode;
 		cout<<"\n\t THe Node is succesfly added at the head ";
	 }
 }
 
 void student_list::printing(){
 	student * temp=head;
 	while(temp!=NULL){
 		cout<<endl<<temp->get_name()<<" "<<temp->get_id()<<" "<<temp->get_department()<<" "<<temp->get_semester()<<endl;
 		temp=temp->next;
	}
 }
 
 void student_list::adding_node_tail(string name,string depart,string semes,int reg_id){
 	// creating new node	
 	student * NewNode = new student(name,depart,semes,reg_id);
 	if(tail ==NULL){
 		head=NewNode;
 		tail=NewNode;
 		cout<<"\n\t The Node is Successfly added at the Tail ";
   }
  else{
 	tail->next=NewNode;
 	NewNode->previous=tail;
 	tail=NewNode;
 	cout<<"\n\t The Node is Successfly added at the Tail ";
 }
 }
 
 
 int student_list::length(){
 	int len=0;
	 student * temp=head;
 	while(temp!=NULL){
 		len++;
 		temp=temp->next;
	 }
 	return len;	
 }
 
 void student_list::deleting_node_head(){
 	student * temp  = head;

	if(head==NULL)
 		cout<<"THERE is no Node at the head";
 		
 	else if (length()==1){
 	 head=NULL;
 	 delete temp;
 	 cout<<"\n\t The Head Node is successfly deleted ";
	}
 	else{
 	head=head->next;
 	head->previous=NULL;
 	delete temp;
 	cout<<"\n\t The Head Node is successfly deleted b";
   }
 }
 
void student_list::deleting_node_tail(){
	if(head==NULL)
		cout<<"\n the node cannot be deleted at the tail ";
	
	else{
		student * temp = tail;
		tail->previous->next=NULL;
			
	}			
}
	
 int main(){
 	 char exit;
	 int choice;
	 student_list * pointer = new student_list();

 	
   pointer->adding_node_head("cys","noman","3",211042);
   pointer->adding_node_tail("masood","cys","4",21111);
   pointer->adding_node_tail("khan","cys","4",211040);
   
   pointer->adding_middle("cys","ahmed","4",211040,2);
   pointer->printing();
 
 
 }
 