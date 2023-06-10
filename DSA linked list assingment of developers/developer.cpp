#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

class developers;

class project {

private:

	int id=0;
	float duration=0.0;
	float cost=0.0;
	string status=" ";

public:
	project* next = NULL;
	
	friend developers;

	project(int id, float duration, float cost, string status) {
		this->id = id;
		this->cost = cost;
		this->duration = duration;
		this->status = status;
	}
	int get_id() {
		return id;
	}
	float get_duration() {
		return duration;
	}
	float get_cost() {
		return cost;
	}
	string get_status() {
		return status;
	}

};

class developers {        // Node of  developers 

private:
	int dev_id;
	string name, spec;
	int no_proj;
public:

	developers* next = NULL;        // node pointers for pointing to next and previous nodes
	developers* previous = NULL;

	project* head = NULL;          // head of the project nodes 
	project* tail = NULL;		  // tail  of the project nodes

	developers(int id, string n, string s, int np) {

		dev_id = id;
		name = n;
		spec = s;
		no_proj = np;
	}

	//void search_project(project* point, project id);
	void next_project();
	void add_project_head();  // adding project at head of all projects of the developer
//	void search_project(project * point, int proj_id);
	int get_devId() {
		return dev_id;
	}
	string get_devName() {
		return name;
	}
	string get_devSpeacial() {
		return spec;
	}
	int get_devProj() {
		return no_proj;
	}

	friend class doubly_dev;
};

 

void developers::next_project() {
	char choice;
 	if (head == NULL)
		cout << endl << " Developer has no Project ";
	else {
		project* temppoint = head;   // moves to the next project
		do {
			
			cout << "\n The project of the developer is :" << endl;
			cout << temppoint->get_id() << endl;
			cout << temppoint->get_duration() << endl;
			cout << temppoint->get_cost() << endl;
			cout << temppoint->get_status() << endl;

			cout << "------ Press n to go next project and e for Exit ";
			cin >> choice;

			temppoint = temppoint->next;

		} while (choice != 'e');

	}
}

 void developers :: add_project_head() {  // adding project at head of all projects of the developer
	 int id;
	 float cost, duration;
	 string status;

	 cout <<endl<< " Give the Project Id "<<endl;
	 cin >> id;
	 cout << " Give the cost of the Project "<<endl;
	 cin >> cost;
	 cout << " Give the duration of the Project "<<endl;
	 cin >> duration;
	 cout << " Give the status of the project " << endl;
	 cin >> status;


	project* projectNode = new project(id, duration, cost, status);

	if (head == NULL) {
		head = projectNode;
		tail = projectNode;
	}
	else {
		projectNode->next = head;
		head = projectNode;
		tail->next = projectNode;
	}
}

 class doubly_dev {
 private:
	 char choice='0';  // local variable for storing the user's choice

	 int id = 0;
	 float duration = 0.0;
	 float cost = 0.0;
	 string status = " ";

	 developers* head = NULL;
	 developers* tail = NULL;
 public:

	 void searching_projects(int id) {

		 int num = 0;
		 developers* point = head;     
		 project* temp = point->head;

		 if (head == NULL)
			 cout << "There is no Developer ";
		 else {
			 while (point != NULL && id != temp->get_id()) {   // the loop to check for the outer developer nodes 
				 temp = temp->next;
				 while (temp != point->head && id != temp->get_id())   // the loop to check the inner projects  
				 {
					 temp = temp->next;
				 }
				 if (temp->get_id() == id)   // if the project is found then go out of the loop
					 break;
				 else {
					 point = point->next;  // the pointer will now go to the next developer 
					 temp = point->head;   // the temp pointer will now go the next developer's first projects 
				 }
			 }

			 if (temp->get_id()!=id ) 
				 cout << endl << " THe Project is not found ";
			 else if (temp->get_id() == id) {
				 cout << "\n Id of the project is " << temp->get_id() << endl;
				 cout << " Status of The project is " << temp->get_status() << endl;
				 cout << " Duration of The project is " << temp->get_duration() << endl;
				 cout << " Cost of The project is " << temp->get_cost() << endl;
			 }
			 else
				 cout << endl << "Something went wrong ";
		 }
	 }

	 void show_developer(developers* point) {   

		 cout << endl << "The Name of the Developer is " << point->get_devName();
		 cout << endl << "The Id of the Developer is " << point->get_devId();
		 cout << endl << "The Specility of the Developer is " << point->get_devSpeacial();
		 cout << endl << "The Number of the Projects are " << point->get_devProj() << endl;

	 }

	 developers* seaching_developers(int ID) { //general class for finding the sepcific developer 

		 if (head == NULL) {
			 return NULL;
		 }
		 else if (head != NULL) {
			 developers* devPoint = head;

			 while (devPoint != NULL && ID != devPoint->get_devId()) {   // The loop will run till the developer is not found or the 
				 devPoint = devPoint->next;                            // the pointer reaches the NULL.
			 }

			 if (devPoint == NULL) {
				 return NULL;
			 }
			 else {
				 return devPoint;
			 }
		 }
		 else {
			 cout << "\n Something went Wrong";
			 return 0;
		 }
	 }

	 // Adding developer at the head
	 void add_developer_head() {
		 int DevId, numProj;
		 string Name, Spec;


		 cout << " \n Give the id of the developer ";
		 cin >> DevId;
		 cout << "\n Give the number of the Project ";
		 cin >> numProj;
		 cin.ignore();
		 cout << "\n Give the Name of the Developer ";
		 getline(cin, Name);
		 cout << "\n Give the speciality of the developer ";
		 getline(cin, Spec);

		 developers* Devpoint = new developers(DevId, Name, Spec, numProj); // creating new developer 

		 if (head == NULL) {
			 head = Devpoint;
			 tail = Devpoint;
		 }
		 else {
			 Devpoint->next = head;
			 head->previous = Devpoint;
			 head = Devpoint;
		 }
		 cout << "\n\t The Developer is successfly Added to the Developers lists ";
	 }

	 developers* next_developer(developers* nextpoint) {  // showing next developer in the linked list 
		 if (nextpoint == NULL) {
			 cout << endl << "THere is no next developer in the list ";
			 return nextpoint;
		 }
		 else {
			 nextpoint = nextpoint->next;  // go to next developer in the list		

			 while (choice != 'e' && nextpoint!=NULL) {

				 cout << nextpoint->get_devId() << endl;
				 cout << nextpoint->get_devName() << endl;
				 cout << nextpoint->get_devProj() << endl;
				 cout << nextpoint->get_devSpeacial() << endl;

				 cout << "press f to go to next developer or e to exit ";
				 cin >> choice;

				 nextpoint = nextpoint->next;
			 }
			 
			 if (nextpoint == NULL)
				 cout << "\n This is last Developer ";

			 return nextpoint;
		 }
	 }

	 developers* show_developer_head() {
		 choice= ' ';
		 developers* pointer = head;

		 if (head == NULL)
			 cout << " There is no Developer at the head ";

		 else {

			 cout << " The Id of the Developer is " << pointer->get_devId() << endl;
			 cout << "\n The Name of the Developer is " << pointer->get_devName() << endl;
			 cout << "\n THe No. of Projects of  Developer are " << pointer->get_devProj() << endl;
			 cout << "\n The Speciality of the Developer is  " << pointer->get_devSpeacial() << endl;

			 cout << " \n\t Press f to go next developer and e to exit ";
			 cin >> choice;

			 if (choice == 'f')
				 next_developer(pointer);
		 }
		 return pointer;
	 }

	 developers* show_previous(developers* tempPrev) {
		 choice = ' ';
		 if (head == NULL) {
			 cout << "\n There is no Developer in the list ";
			 return tempPrev;
		 }
		 else {
			 while (tempPrev->previous != NULL && choice != 'e') {
				 tempPrev = tempPrev->previous;

				 cout << "\n The id of the developer is " << tempPrev->get_devId();
				 cout << "\n THe Name of the developer is " << tempPrev->get_devName();
				 cout << "\n THe Speciality of the developer is " << tempPrev->get_devProj();
				 cout << "\n THe No of projects of the developer is " << tempPrev->get_devProj();

				 cout << "\n\t -> Press r to see previous developer and e to exit ";
				 cin >> choice;
			 }
			 if (tempPrev->previous == NULL)
				 cout << " \n This is the first developer ";
			 return tempPrev;
		 }
	 }
};
	
	 int main() {
		 char e;
		 char choice;
		 int id;
		 developers* headpoint = NULL; // for temporaily storing the return address of type 
		 //  developers 		

		 doubly_dev * obj = new doubly_dev();
		 
	 menu:system("CLS");
		  cout << "\n\t   Please choose a command :" << endl;

		 cout << "\n\t d Add a developer " << endl;
		 cout << "\n\t p Add a project " << endl;
		 cout << "\n\t s Search for a developer " << endl;
		 cout << "\n\t t Search for a project " << endl;
		 cout << "\n\t v View developers at head" << endl;
		 cout << "\n\t f Show next developer " << endl;
		 cout << "\n\t r Show previous developer " << endl;
		 cout << "\n\t e exit " << endl;
		 cout << "\n\t\t choice ---- >  ";
		 cin >> choice;

		 while (choice != 'd' && choice != 'p' && choice != 'p' && choice != 't' &&
			 choice != 'v' && choice != 'f' && choice != 'r' && choice != 'n' &&
			 choice != 'e') {

			 cout << " \a \n THe given option is not right ";
			 cin >> choice;
		 }
		
		 
		 if (choice == 'd') {
			 system("CLS");

			 obj->add_developer_head();
			 cout << "\n\n \t -> press e to exit ";
			 cin >> e;
			 if (e == 'e') {
				 goto menu;
			 }
		 }

		 else if (choice == 'p') {
			 id = 0;

			 cout << "\n Give the ID for Whome the The project is added ";
			 cin >> id;

			 developers* point = obj->seaching_developers(id);  // search for the developer whose id is given 

			 if (point == NULL) {                               // if not found 
				 cout << "THe developer is not found " << endl;
			 }
			 else {												// if found 
				 obj->show_developer(point);
				 point->add_project_head();
			 }
			 cout << "\n\n \t -> press e to exit ";
			 cin >> e;
			 if (e == 'e') {
				 goto menu;
			 }
		 }

		 else if (choice == 's') {
			 id = 0;
			 system("CLS");
			 cout << " GIve the Id of the Developer ";
			 cin >> id;

			 developers* point = obj->seaching_developers(id);
			 if (point == NULL)
				 cout << "\n The Developer is not found ";
			 else {
				 obj->show_developer(point);
				 point->next_project();
			 }
			 cout << "\n\n \t -> press e to exit ";
			 cin >> e;
			 if (e == 'e') {
				 goto menu;
			 }
		 }

		 else if (choice == 't') {
			 id = 0;

			 cout << "\n Enter the Id of the project to search " << endl;
			 cin >> id;

			 obj->searching_projects(id);

			 cout << "\n\n \t -> press e to exit ";
			 cin >> e;
			 if (e == 'e') {
				 goto menu;
			 }
		 }
		 else if (choice == 'v') {
			 headpoint = obj->show_developer_head();  // showing the head developer and returning the address of that developer

			 cout << "\n\n \t -> press e to exit ";
			 cin >> e;
			 if (e == 'e') {
				 goto menu;
			 }
		 }

		 else if (choice == 'f') {
			 headpoint = obj->next_developer(headpoint);

			 cout << "\n\n \t -> press e to exit ";
			 cin >> e;
			 if (e == 'e') {
				 goto menu;
			 }
		 }
		 else if (choice == 'r') {
			 headpoint = obj->show_previous(headpoint);
			 cout << "\n\n \t -> press e to exit ";
			 cin >> e;
			 if (e == 'e') {
				 goto menu;
			 }
		 }
		 else if (choice == 'e') {
			 cout << endl << "\t exting ....... ";
		 }
		 
	 }

