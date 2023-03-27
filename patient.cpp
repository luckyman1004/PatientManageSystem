#include <iostream>
#include <string>
using namespace std;

class Patient
{
public:
  int CNIC,room_num;
  string name,phone_number,disease_type;
  Patient *next;
    Patient ()
  {
    this->next = NULL;
    this->CNIC = 0;
    this->name = "";
    this->phone_number = "";
    this->disease_type = "";
    this->room_num = 0;
  }
  Patient (string name, string phone_num, string d, int room_num,int val)
  {
    this->next = NULL;
    this->CNIC = val;
    this->disease_type = d;
    this->name = name;
    this->room_num = room_num;
    this->phone_number = phone_num;
    
  }

};

class Patient_Record
{
private:
  Patient *head;
  int count_patients_admitt;
public:
    Patient_Record ()
  { count_patients_admitt=0;
    head = NULL;
  }

  int get_total_admitted_patients(){
    return this->count_patients_admitt;
  }

  bool check_capacity(){

   return count_patients_admitt==20;
  }
  void Add_patient(string name, string phone_num, string d, int room_num,int val)
  {				// 1 CNIC _ address of 2... 2 Null 
    if(check_capacity()){ cout<<"Already 20 patients admitted. Can't Add more in our Hospital. Bitte!!! \n"; return; }
 
    Patient *new_patient = new Patient (name,phone_num,d,room_num,val);
    
    new_patient->next = head;
    head = new_patient;
    this->count_patients_admitt++;
    cout<<"Successfully added patient\n";
 
  }
  void Insert_Start (string name, string phone_num, string d, int room_num,int val)
  {				// 0 address of 1 1 address of 2  2 
   if(check_capacity()){ cout<<"Already 20 patients admitted. Can't Add more in our Hospital. Bitte!!! \n"; return; }

   Patient *new_patient = new Patient (name,phone_num,d,room_num,val);
   if(head==NULL) {head=new_patient;   count_patients_admitt++; return;}
   // before NULL 2 3 4.. after NULL 1 2 3 4
   Patient* curr = head;
   while(curr->next!=NULL){
    curr = curr -> next;
   }
   curr->next = new_patient;
   new_patient->next = NULL; /// New patient next will be NULL always in case of head
   count_patients_admitt++;



  }

  void Insert_Last (string name, string phone_num, string d, int room_num,int val)
  {  
    if(check_capacity()){ cout<<"Already 20 patients admitted. Can't Add more in our Hospital. Bitte!!! \n"; return; }
    else if(head==NULL){
      Insert_Start(name,phone_num,d,room_num,val); return;
    }
    Patient *new_patient = new Patient (name,phone_num,d,room_num,val);
    new_patient->next = head; //befor  NULL 1 2 3 then NULL 1 2 3 4 .. after addition of 4
    head = new_patient;
    count_patients_admitt++;
    cout<<"Successfully Inserted Last Patient\n";
   
  }
    
  

  void Delete_first ()
  { 
    if (head == NULL)
    {
	cout << "List empty." << endl;
	
return;
    }

// NULL 1 2 3 before then  NULL 2 3.. second_node_prev will store address of 2 and current will store address of 1
Patient * current_patient = head, *second_node_prev = NULL;

while (current_patient->next != NULL)
{
second_node_prev = current_patient ;       // second_node_prev node address here
current_patient  = current_patient ->next;	// next node updating
  
}
//current_patient  will be node 1.
//second_node_prev will be node no 2. 
second_node_prev->next = current_patient ->next;  // current_patient ka next is NULL

delete current_patient ;		// it will delete first node

this->count_patients_admitt--; // decrement counter
  }

void Delete_last ()

  { if(head==NULL)
  {
  cout<<"List is Empty.Can't delete\n"; return;
  }

  if(count_patients_admitt==1 || (head->next==NULL) ) { this->Delete_first(); return; }
    Patient *current_patient  = head;
    head = head->next; // NULL 1 2 3 then NULL 1 2
    
    delete current_patient;
    count_patients_admitt--;
    cout<<"Successfully Deleted Last Patient\n";

  }

  void Print_All_patients ()
  { if(head==NULL){
    cout<<"Can't print because list is empty\n";
    return;
  }

  //  int CNIC,room_num;
  // string name,phone_number,disease_type,
    Patient *current_patient  = head;
    int i=1;
    while (current_patient != NULL)
      {
	cout << "Name of patient number  << "<< i<<"  :   " << current_patient ->name << endl;
	cout << "Phone number of patient number  << "<< i<<"  :   " << current_patient ->phone_number << endl;
	cout << "CNIC of patient number  << "<< i<<"  :   " << current_patient ->CNIC << endl;
	cout << "Disease type of patient number  << "<< i<<"  :   " << current_patient ->disease_type<< endl;
	cout << "Room number of patient number  << "<< i<<"  :   " << current_patient ->room_num << endl;
	current_patient  = current_patient ->next;	// current_patient ->next is actually head->next coz pointer is pointing head
  i++;
      }				// patient ->next is updating
  }
  
Patient* Insert_Any_Position(int position, string name, string phone_num, string d, int room_num,int val ){
  if(check_capacity()){ cout<<"Already 20 patients admitted. Can't Add more in our Hospital. Bitte!!! \n"; return head; }
    Patient *new_patient = new Patient (name,phone_num,d,room_num,val);
    if(position==0 && head==NULL){  count_patients_admitt++;
    return new Patient(name,phone_num,d,room_num,val); }
    else if(position==0 && head!=NULL){
    new_patient->next = head; // like we have 1 2 3 NULl then insert 0 at 0 .. so 0 1 2 3 NULL
    head = new_patient;  count_patients_admitt++;
    return head; }
    
    Patient* cur= head;
    int c=0;// count nodes
    while(cur!=NULL) {cur=cur->next; c++;}
    if (position < 0 || position > c) { cout<<"Your position is incorrect\n"; return head; }
    
    Patient* current = head, *previous = NULL;
    int i=0;
    while(i!=position){
    previous = current;
    current = current -> next;
    i++;
    }
    // 1 3 4 5 NULL... 1 3 4 5 6 null
    previous->next = new_patient;
    new_patient->next = current;
    count_patients_admitt++;
    
    return head;
    // 1 2 3 NULL
    
}
Patient* reverse(Patient* head){
  if(head==NULL || head->next==NULL) return head;
  Patient* rest = reverse(head->next);
  head->next->next = head;
  head->next = NULL;

  return rest; /// will behave as head now


}
void Delete_Any_Position(int position){
   if(head==NULL ) { cout<<"List is Empty\n"; return; }  // in case no patient
   else if(position==0 && head->next==NULL){ head=NULL;  // in case only one patient
    return; }
    //before NULL 1 2 3 4  then NULL 1 2 4
   
  Patient * current_patient = head, *second_node_prev = NULL;

// 
int i=0;
while (i != position )
{
second_node_prev = current_patient ;       // second_node_prev node address here
current_patient  = current_patient ->next;	// next node updating
i++;
  
}
//current_patient  will be node 1.
//second_node_prev will be node no 2. 
second_node_prev->next = current_patient ->next;  // current_patient ka next address to second k prev

delete current_patient ;		// it will delete first node

count_patients_admitt--;
    
    
    
}
 
// search patient by Name
bool Search_patient_By_Name (string name)
  {
    
if (head == NULL)
      {
return false;
      }
    
Patient *current_patient  = head;

 
while (current_patient  != NULL)
      {
	
if (current_patient ->name == name)
	    return true;
    // break the loop if patient is found having name given in function parameter
	
current_patient  = current_patient ->next;	// next patient updating

      
} 

return false;  // in case no such name

      	

}
// search patient by CNIC
bool Search_patient_By_CNIC (int CNIC)
  {
    
if (head == NULL)
      {
return false;
      }
    
Patient *current_patient  = head;

 
while (current_patient  != NULL)
      {
	
if (current_patient ->CNIC == CNIC)
	    return true;
       	   // break the loop if patient is found having name given in function parameter
	

current_patient  = current_patient ->next;	// next patient updating

      
} 

return false;  // in case no such name

      	

}
// search patient by Phone Number
bool Search_patient_By_Phone (string p)
  {
    
if (head == NULL)
      {
return false;
      }
    
Patient *current_patient  = head;

 
while (current_patient  != NULL)
      {
	
if (current_patient ->phone_number == p)
	    return true;
       	   // break the loop if patient is found having name given in function parameter
	

current_patient  = current_patient ->next;	// next patient updating

      
} 

return false;  // in case no such name

      	

}
// search patient by disease type
bool Search_patient_By_Disease_Type (string disease_type)
  {
    
if (head == NULL)
      {
return false;
      }
    
Patient *current_patient  = head;

 
while (current_patient  != NULL)
      {
	
if (current_patient ->disease_type == disease_type)
	    return true;
       	   // break the loop if patient is found having name given in function parameter

current_patient  = current_patient ->next;	// next patient updating

      
} 

return false;  // in case no such name

      	

}
// search patient by room number
bool Search_patient_By_Room (int r)
  {
    
if (head == NULL)
      {
return false;
      }
    
Patient *current_patient  = head;

 
while (current_patient  != NULL)
      {
	
if (current_patient ->room_num == r)
	    return true;
       	   // break the loop if patient is found having name given in function parameter

current_patient  = current_patient ->next;	// next patient updating

      
} 

return false;  // in case no such name

      	

}

};
void Call_Patient_Management(){

int choice,counter,position,add_value, cnic, room_no , i; // variables
string name, number, disease_type;
Patient_Record object; 




cout<<"\t\tHospital Management System Implementation using Linked List\t\t\n\n";


// statements represting methods of linked list
cout<<"Press 1 for addmitting patients in linked list\n\n";
cout<<"Press 2 for printing patients in linked list\n\n";

cout<<"Press 3 for addmitting first patient in linked list\n";
cout<<"Press 4 for removing first patient in linked list\n\n";


cout<<"Press 5 for addmitting  last patient in linked list\n";
cout<<"Press 6 for removing last patient in linked list\n\n";

cout<<"Press 7 for addmitting patient by position in linked list\n";
cout<<"Press 8 for removing patient by position in linked list\n\n";


cout<<"Press 9  for  searching patient  by its name in linked list\n";
cout<<"Press 10 for searching patient  by its phone number in linked list\n";
cout<<"Press 11 for searching patient  by its  disease type in linked list\n";
cout<<"Press 12 for searching patient  by its  CNIC in linked list\n";
cout<<"Press 13 for searching patient  by its  room number in linked list\n";

cout<<"Press any number other than 1,2,3,4,5,6,7,8,9,10,11,12,13 for exit\n\n";

bool check=true;
while(check){

cout <<"Enter choice here:";  // choice for above statements
cin>>choice;

switch(choice){
case 1:
cout<<"How many values you want to add: ";
cin>>counter;

for(i=0;i<counter;i++){
cout<<"Enter name of patient number : "<<i+1 <<" -> ";
cin>>name; 

cout<<"Enter phone number of patient number : "<<i+1 <<" -> ";
cin>>number; 

cout<<"Enter disease type of patient number : "<<i+1 <<" -> ";
cin>>disease_type; 

cout<<"Enter cnic of patient number : "<<i+1 <<" -> ";
cin>>cnic; 

cout<<"Enter room_no of patient number : "<<i+1 <<" -> ";
cin>>room_no; 
//  name, number, disease  cnic, room_no

object.Add_patient(name,number,disease_type,cnic,room_no);  // add patients in list
}
break;

case 2:
 
object.Print_All_patients();  // print patients here
break;

case 3:
cout<<"Enter name of patient number : "<<" -> ";
cin>>name; 

cout<<"Enter phone number of patient number : "<<" -> ";
cin>>number; 

cout<<"Enter disease type of patient number : "<<" -> ";
cin>>disease_type; 

cout<<"Enter cnic of patient number : "<<" -> ";
cin>>cnic; 

cout<<"Enter room_no of patient number : "<<" -> ";
cin>>room_no; 
//  name, number, disease  cnic, room_no

object.Insert_Start(name,number,disease_type,cnic,room_no);
  
break; 
case 4:

object.Delete_first();  // Delete first Patient 
  
break; 

case 5:  
cout<<"Enter name of patient number : "<<" -> ";
cin>>name; 

cout<<"Enter phone number of patient number : "<<" -> ";
cin>>number; 

cout<<"Enter disease type of patient number : "<<" -> ";
cin>>disease_type; 

cout<<"Enter cnic of patient number : "<<" -> ";
cin>>cnic; 

cout<<"Enter room_no of patient number : "<<" -> ";
cin>>room_no; 

object.Insert_Last(name,number,disease_type,cnic,room_no);
  
break;
case 6: 
  

object.Delete_last();  // Delete Last Patient 

case 7: 

cout<<"Enter position of patient number to be added : "<<" -> ";
cin>>position; 

cout<<"Enter name of patient number : "<<" -> ";
cin>>name; 

cout<<"Enter phone number of patient number : "<<" -> ";
cin>>number; 

cout<<"Enter disease type of patient number : "<<" -> ";
cin>>disease_type; 

cout<<"Enter cnic of patient number : "<<" -> ";
cin>>cnic; 

cout<<"Enter room_no of patient number : "<<" -> ";
cin>>room_no; 

object.Insert_Any_Position(position,name,number,disease_type,cnic,room_no);
  
break;

case 8:
cout<<"Enter position of patient number to be deleted : "<<" -> ";
cin>>position; 
object.Delete_Any_Position(position);
break;

case 9:
cout<<"Enter name of patient number : "<<" -> ";
cin>>name; 

if(object.Search_patient_By_Name(name))
cout<<"Present!!\n";
else cout<<"Not here in our data record. Bitte\n";
break;
case 10:


cout<<"Enter phone number of patient number : "<<" -> ";
cin>>number; 

 

if(object.Search_patient_By_Phone(number))
cout<<"Present!!\n";
else cout<<"Not here in our data record. Bitte\n";
break;
case 11:


cout<<"Enter disease type of patient number : "<<" -> ";
cin>>disease_type; 



if(object.Search_patient_By_Disease_Type(disease_type))
cout<<"Present !!! \n";
else cout<<"Not here in our data record. Bitte\n";
break;
case 12:

cout<<"Enter cnic of patient number : "<<" -> ";
cin>>cnic; 


if(object.Search_patient_By_CNIC(cnic))
cout<<"Present !!! \n";
else cout<<"Not here in our data record. Bitte\n";
break;
case 13:

cout<<"Enter room_no of patient number : "<<" -> ";
cin>>room_no; 

if(object.Search_patient_By_Room(room_no))
cout<<"Present !!! \n";
else cout<<"Not here in our data record. Bitte\n";
break;

default:
 cout<<"Successfully exited!!"; check=false;

  
}
}
 
}

int main ()
{
  Call_Patient_Management();

  return 0;
}







