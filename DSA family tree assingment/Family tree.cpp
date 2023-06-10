#include<iostream>
#include<fstream>
#include<Windows.h>
using namespace std;

class Tnode{
	private:
		string name;
		Tnode * fc;
		Tnode * sibling;
	public:
		Tnode(string name);
		void set_name(string name);
		string get_name();
		
		friend class Tree;
};
Tnode::Tnode(string name){
	this->name=name;
	name="A";
	fc=NULL;
 sibling=NULL;
}
void Tnode::set_name(string name){
	this->name=name;
}
string Tnode::get_name(){
	return name;
}

class Tree{
	private:
			
		Tnode * find = NULL; // pointer for the storing the address of the searched node 
		Tnode * S = NULL;   // pointer storing the address of the parent Node in insertion function  
 		
		Tnode * root=new Tnode("A"); 
		
		Tnode * insert(Tnode * temp,string parent,string child){   // private recursive fucntion
			if(temp==NULL){
				return NULL;			
		    }
			
			if(temp->name==parent){
				adding_last_child(temp,child);	
				S = temp;
				return NULL;
				}
				
			if(insert(temp->sibling,parent,child)!=NULL){}
				 //insert(temp->fc,parent,child);
				
			if(insert(temp->fc,parent,child)!=NULL){}
				 //insert(temp->fc,parent,child);
			
			return NULL;
		}
		
		void pre_order(Tnode * temp){
			
			if(temp==NULL)
				return ;
	 	
			cout<<"\t"<<temp->name;
		 	
			pre_order(temp->fc);	
			 
			pre_order(temp->sibling);
			 			
		}
	
		void post_order(Tnode * temp){
		
			if(temp==NULL)
				return ;
		
			post_order(temp->fc);
			cout<<"\t"<<temp->name;
			post_order(temp->sibling);
		
		}	
	
		void  searching_node(Tnode * temp, string search){
		
		if(temp==NULL)
			return ;
		
		if(temp->name==search)
		{
			find = temp;  // stores the address of the found node
		    return;             // returns that address
		}
		searching_node(temp->fc,search);
		searching_node(temp->sibling,search);
		
		return ;	
		}
				
	public:
		
		bool insert(string parent,string child){
			insert(root,parent,child); // call the private insert Fucntion for recursion 
			
			if(S==NULL) 
				return false;
			else 
				return true;
		} 
		
		void pre_order(){
			return pre_order(root);
		}
		
		void post_order(){
			post_order(root);
		}
		
		bool searching(string search){
			find=NULL;  // Assing back the NULL To the find pointer
			searching_node(root,search);
			
			if(find==NULL)
				return false;	
			else
				return true;	
		}
		
		void adding_last_child(Tnode * point,string child){
			string word="";
		
			fstream file("family.txt",ios::app | ios::in | ios::out);
			
			Tnode * newchild = new Tnode(child);
			
			if(point->fc==NULL){
				point->fc=newchild;
				
				while(file>>word){
					if(word==point->name){
						file<<endl<<child<<" ";
						break;
					}
				}
			}
			else{
				Tnode * temp = point->fc;	
				
				string word;
				
				while(temp->sibling != NULL)
					temp=temp->sibling;
			
				temp->sibling=newchild;
				
				while(file>>word){
					if(word==point->name){
						file<<child<<" ";
						break;
					}	
				}
			}
			
		file.close();
		
	    }
	    
	    void print_all_descendants(string name){
	    	
			if(searching(name)){				// if the searching funtion returns true which means the node is found in the tree
	  			cout<<"\n\t\t -> THE NAME IS FOUND IN THE TREE \n\n";
				cout<<"\n\t\t -> The List of the all Descendants of the Name are \n\t\t ";  	
				pre_order(find);
	  			  	
	  	}
	    	else if(searching(name)==false)
	    		cout<<"THE GIVEN NAME IS NOT FOUND IN THE TREE ";
		}
		
		void import (){
			
			ifstream file("family.txt",ios::in); // opening file for reading 
			string word;
			
			cout<<"\n\t------------------------- Family Tree------------------------------------------------ ";
			
			while(file>>word){
				
				cout<<word;
			
			}		
		}
	};
	
int input_handling(int var,int start,int stop){
	
	while(var<start||var>stop){
	
		cout<<"\n\n\t\t->INVALID INPUT__ ";
		cout<<"\n\n \t\t\t  -> choice __   ";
		cin>>var;
    }
	return var;
}		

int main(){                  // The Root Node is A 
	
	char exit;        
	int choice,temp,c;
	string parent,child,search,name;  // strings for inserting new child
	
	fstream file("family.txt", ios::out);   // creating file for storing the family tree in txt file	in append mode	
	file<<"A ";
	file.close();
	
	Tree * obj = new Tree(); 
	menu:system("CLS");
	cout<<"\n\t ------------------------------------------------------------------------------- ";
	cout<<"\n\t\t\t\t\t Family Tree ";
	cout<<"\n\t ------------------------------------------------------------------------------- ";
	
	cout<<"\n\n\t\t\t\t  1. Inserting New Children "<<endl;
	cout<<"\t\t\t 	  2. Searching For Family Member "<<endl;
	cout<<"\t\t\t 	  3. Traversing The Family Members "<<endl;
	cout<<"\t\t\t 	  4. Print All Descendants "<<endl;
	cout<<"\t\t\t 	  5. Import Function "<<endl;
	cout<<"\t\t\t 	  6. Exit  "<<endl;
	cout<<"\n\n \t\t\t  -> choice __   ";
		cin>>choice;
	  
	choice=input_handling(choice,1,6);  
		  
menu1: switch(choice){
	 	case 1:
	 		 
			cout<<"\n\n \t\t -> Enter Name of the Parent to Insert Child to __ ";
	 		cin.ignore();
			getline(cin,parent);
	 		 
			cout<<"\n\t\t -> Enter Name of the Child __ ";
	 		getline(cin,child);
			                    
	 		if(obj->insert(parent,child))
	 		  cout<<"\n\n\t\t The Child is Successfly Added to the Given Parent Name ";
	 		else if(obj->insert(parent,child)==false)
	 			cout<<"\n\t\t The Given Parent Does not exits ";
			 
			 cout<<"\n\n\n\t\t Press.   E to exit   1. GoBack to Insertion ";
       		cin>>exit;
       		
	 		if(exit=='1')
			 	goto menu1;
	 		else if(exit=='E' || exit=='e')
	 		 	goto menu;
		
	case 2:
	
menu2:	cout<<"\n\n\t\t Enter The Name to Search \n\t\t";
		cin.ignore();
		getline(cin,search);
		
		if(obj->searching(search))
			cout<<" \n\n\t\t THis Name is found in the Tree ";
		else if(obj->searching(search)==false)
			cout<<"\n\t\t This Name is not found ";
		
		 cout<<"\n\n\n\t\t Press.   E to exit   2. GoBack to Search ";
       		cin>>exit;
       		
	 		if(exit=='2')
			 	goto menu2;
	 		else if(exit=='E' || exit=='e')
	 		 	goto menu;
		
		case 3:
				
menu3:	cout<<"\n\n\t\t Select Type of Traversal \n\t\t ";
		cout<<"1. Pre order 2. Post Order ";
		cin>>c;
		
		c = input_handling(c,1,2);
		
		if(c==1){
			cout<<"\t\t\t Pre Order Traversal \n";
			obj->pre_order();
		}	
		else if(c==2)
			cout<<"\t\t\t\t Post Order Traversal \n ";
			obj->post_order();
			
		cout<<"\n\n\n\t\t Press.  E to exit   3. GoBack to Traversal ";
       		cin>>exit;
       		
	 		if(exit=='3')
			 	goto menu3;
	 		else if(exit=='E' || exit=='e')
	 		 	goto menu;	
	
	case 4:
		
 menu4:	
		cout<<" Give Name to Print list of his Descendants ";
		cin>>name;
		
		obj->print_all_descendants(name);
		
		cout<<"\n\n\n\t\t Press.  E to exit   4. GoBack to Traversal ";
       		cin>>exit;
       		
	 		if(exit=='4')
			 	goto menu4;
	 		else if(exit=='E' || exit=='e')
	 		 	goto menu;	
	
	case 5:
		
		obj->import();
		
		cout<<"\n\n\n\t\t Press.  E to exit  ";
       		cin>>exit;
       	
	 	 if(exit=='E' || exit=='e')
	 		goto menu;
		
		
	case 6:
		cout<<"\n\n\n\t\t Exiting.....  ";		
	
	default:
		cout<<"\n\n\n\t\t Something Went Wrong ";
		goto menu;
	}

}
                  