#include<iostream>
using namespace std;

class treeNode{
	private:
	int name;
	treeNode * leftleave=NULL;
	treeNode * rightleave=NULL;
	
	public:
		treeNode(int name){
			this->name=name;
        }
        void set(int name){
        	this->name=name;
		}
        int get(){
        	return name;
		}
	   friend class BST;	
};

class BST{
	private:
	   treeNode * root = NULL;
	
	treeNode* insert(int name,treeNode *temp) {
			if(temp==NULL){
				temp = new treeNode(name);
			//		cout<<" The node is added at the root ";
			}
			else if(temp->get() > name){  // for adding nodes at the left childs
				temp->leftleave=insert(name,temp->leftleave);
				cout<<" The node is added at the left leave ";
			}
			else if(temp->get()<name){
				temp->rightleave =insert(name,temp->rightleave);
				cout<<" The node is added at the right leave ";
			}
		return temp;
	}
	public:
		treeNode * ret_root(){
			return root;
		}
		void insert_Node(int data){
			root = insert(data,root);
		}
		
		void inorder(treeNode * temp){
			
			if(temp==NULL)
			   return; 
			inorder(temp->leftleave);
			cout<<endl<<temp->get();
			inorder(temp->rightleave);
		}
};

	int main(){
		
		BST * obj= new BST();
		
		treeNode * root = obj->ret_root();
		
		obj->insert_Node(8);
		obj->insert_Node(10);
		obj->insert_Node(1);
	
		obj->inorder(root);
	
	}
