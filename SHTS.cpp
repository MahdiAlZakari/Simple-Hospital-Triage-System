#include <iostream> 
#include<iomanip>
using namespace std; 
#define MAX 25 //defines array size
struct Queue {  //define Queue structure
	int front, rear; //declare integer variables front and rear
	int queue[MAX]; //declare integer array variable queue 
}; 

Queue q; //declare structure variable

struct Pateint //define Pateint information structure
{
	string fullname;  //declare string variable to store names
	int id; //declare integer variable to store IDs
	string CaseDescription; //declare string variable to store Case Description
	int TriageLevel; //declare integer variable to store Triage Levels
};
int num; //declare integer variable to save number of recorded records
Pateint patient[MAX]; //declare structure variable to save records
Pateint temprecord[MAX]; //declare structure temprecord variable to use it for swapping



// Function for Enqueue

void enqueue(int value) 
{ 	
//check if Queue in empty
    if ((q.front == 0 && q.rear == MAX-1) || (q.rear == q.front-1))
    { 
        cout << "\nSorry, we can't receive patients now\n"; 
    } 
    else if (q.front == -1) // Insert First Element
    { 
        q.front = q.rear = 0; 
        q.queue[q.rear] = value; 
    } 

    else if (q.rear == MAX-1 && q.front != 0) 
    { 
        q.rear = 0; 
        q.queue[q.rear] = value; 
    }   
    else
    { 
        q.rear++;
        q.queue[q.rear] = value; 
        
    } 
}

// Function to delete element from Circular Queue 

void dequeue(int value) 
{ 

    int data = q.queue[q.front]; 
    q.queue[q.front] = -1; 

    if (q.front == q.rear) // removing last element
    { 
        q.front = -1; 
        q.rear = -1; 
    } 
    else if (q.front == MAX-1) 
        q.front = 0; 
    else
        q.front++; 
  
   
}

void menu() //Function to print a simple menue 
{
	cout<<"\n \t   <Hospital Triage System>  "<<endl;
    cout<<"\n Press 1 > Add New Patient ";
	cout<<"             ";
	cout<<"\n Press 2 > Remove a patient who has been treated      ";
	cout<<"             ";
	cout<<"\n Press 3 > View all patients  ";
	cout<<"             ";
	cout<<"\n Press 4 > View the next patient to be treated        ";
	cout<<"             ";
	cout<<"\n Press 5 > Clear the list        ";
	cout<<"             ";
	cout<<"\n Press 6 > QUIT Application            ";
	cout<<"             ";
	cout<<"\n\n  Please Select an Option   > ";
}

bool select() //Function to allow the user to perform the recent process again
{
	cout<<"\n \tDo you want to do this process again? "<<endl;
	
	cout<<"\t \ty > YES"<<endl<<"\t \tn > NO ,Back to main menu"<<endl<<endl;
	
	char select;
	cout<<"\tPlease choice: ";
	
    cin>>select;
bool done = false;
    while(!done)
     {

	    switch(select)
	    {
	  	
	    	case 'y':
	  	    	return true;
	  			break;
	  			
	     	case 'n':
	  	    	 cin.ignore();
	  	    	 done = true;
	  	    	  break;
	  	     	
	  	    default:
	  	    	cout<<"\n\t"<<select<<" is a Wrong Option"<<endl;
		    	cout<<"\t Please choice: ";
		    	cin>>select;
	  	
        }
        
      }
}


 void InsertPatient() //Function to insert a new record
{
	int i=num;
	num+=1;
	cout<<"\n \t <Insert Patient Record>  "<<endl;
	cout<<"\n \t Enter The Following Details"<<endl;
    	cout<<"\n  First and Last Name        :";
    	cin.ignore();
		getline(cin,patient[i].fullname);
		cout<<"  ID                         :";	
		cin>>patient[i].id;
		cout<<"  Case Description           :";
		cin.ignore();
		getline(cin,patient[i].CaseDescription);
		cout<<"  Triage Level               :";
		cin>>patient[i].TriageLevel;
		enqueue(patient[i].TriageLevel);
	    cout<<endl;
	 
    if(select()==true)//to repeat the process
    InsertPatient();

}

void RemovePatient() //Function to remove a patient's record who has been treated
{ 
  int id, j, found=0;
  
   cout<<"\n \t <Remove a patient who has been treated>  "<<endl;
	cout<<endl;
	cout<<"\n  Enter the patien's ID To Delete: ";
	cin>>id;
	if(num==0) //check if empty
	{
		         cout<<"\n \tNo Records yet"<<endl;

	}
	else{
	
    for(int i=0; i<num; i++)
    {                         
        if(patient[i].id==id) //check if patient exist
        {
        	
            for(j=i; j<num ; j++)
            
              {
              patient[j].id = patient[j+1].id;
              patient[j].fullname= patient[j+1].fullname;
              patient[j].CaseDescription=patient[j+1].CaseDescription;
              patient[j].TriageLevel=patient[j+1].TriageLevel;
           	  

            found++;  
			
			 			  

             }
             dequeue(patient[j].TriageLevel);
             			  num--;

		}

    }
    if(found==0)
    {
	cout<<"**********************************************"<<endl;
	cout<<"\n  ID entered does NOT match with any Record\n"<<endl;
	cout<<"**********************************************"<<endl;

    }
    else
    {
	
        cout<<"\n \tRecord Removed Successfully!"<<endl;
    }
        if(select()==true)//to repeat the process
        RemovePatient();
  }
}

void deletelist() //Function to delete all records
{
		cout<<"\n \tYou are about to delete all the patients records, Do you want to continue ? "<<endl<<endl;
		cout<<"\t \ty > YES"<<endl<<"\t \tn > NO ,Back to main menu"<<endl<<endl;
	
	char choice;
	cout<<"\tPlease choose: ";
	
    cin>>choice;

    switch(choice)
	    {
	  	
	    	case 'y':
	    		
	  	     for(int i=0; i<=num; i++) //delete all records
  			   {				
            
           					  patient[i].id = patient[i+1].id;
            				  patient[i].fullname= patient[i+1].fullname;
            				  patient[i].CaseDescription=patient[i+1].CaseDescription;
            				  patient[i].TriageLevel=patient[i+1].TriageLevel;
 							  dequeue(patient[i].TriageLevel);
             				  num--;
               }
        					  cout<<"\n \tRecords Removed Successfully!"<<endl;
    		  
	  			break;
	  			
	     	case 'n':
	  	    	 cin.ignore();
	  	    	 return;
	  	    	  break;
	  	     	
	  	    default:
	  	    	cout<<"\n\t"<<choice<<" is a Wrong Option"<<endl;
		    	cout<<"\t Please choose: ";
		    	cin>>choice;
	  	
        }
        
}

void SortPatients() //Function to sort the queue of patients by triage Level
{
	 int min;
	  // One by one move boundary of unsorted subarray
    for (int i = 0; i < num-1; i++)
    {
        // Find the minimum element in unsorted array
        min = i;
        for (int j = i+1; j < num; j++)
        if (patient[j].TriageLevel < patient[min].TriageLevel)
            min = j;

        // Swap the found minimum element with the first element
        
      		temprecord[i] = patient[min];
    		patient[min]= patient[i];
   			patient[i] = temprecord[i];
    }
}

void NextPatient() //Function to print the next patient 
{
   
 if(num==0) //check if the list is empty
       {

         cout<<"\n \tNo Records yet"<<endl;
        }
        
 else
		{
		
      SortPatients(); //call SortPatients Function to sort the patients before print the next patient
      
   	 	    cout<<"\n \t      <The next patient> "<<endl;
   	 	    cout<<"----------------------------------------------"<<endl;
   	 	    cout<<"   Name               |"<<patient[0].fullname<<endl;
	    	cout<<"   ID                 |"<<patient[0].id<<endl;
	    	cout<<"   Case Description   |"<<patient[0].CaseDescription<<endl;
	    	cout<<"   TriageLevel        |"<<patient[0].TriageLevel<<endl;
		    cout<<"----------------------------------------------"<<endl;

    }
    cout<<"\n   Press Enter to continue"<<endl;
    string Enter="";
    getline(cin,Enter);
    cin.ignore();

}

void  list() //Function to print all patients
{
	
	
      if(num==0) //check if the list is empty
       {

         cout<<"\n \tNo Records yet"<<endl<<"\n";
        }
       else
      {
      	SortPatients(); //call SortPatients Function to sort the patients before print their records
      		cout<<"\n \t      <List of patients>  "<<endl;
	     	cout<<"----------------------------------------------"<<endl;
	        for(int i=0;i<=num-1;i++)
           	{
	    	cout<<"   Name               |"<<patient[i].fullname<<endl;
	    	cout<<"   ID                 |"<<patient[i].id<<endl;
	    	cout<<"   Case Description   |"<<patient[i].CaseDescription<<endl;
	    	cout<<"   TriageLevel        |"<<patient[i].TriageLevel<<endl;
		    cout<<"----------------------------------------------"<<endl;
	        }
      }
      
    cout<<"\n   Press Enter to continue"<<endl;
    string Enter="";
    getline(cin,Enter);
    cin.ignore();
}


int main() //main Function
{ 
	q.front = q.rear = -1; //Initialize front and rear to 0.
	int choice;
	
	do
	{
		//display operations on a menu
         menu();
		cin >> choice; //for switch cases
		
switch(choice)
		{
			case 1: // Call InsertPatient Function
				
				InsertPatient();
				cout << "\n";	
			break;
						
			case 2: // Call RemovePatien Function
				RemovePatient();
				cout << "\n";
			break;
			
			case 3: // Call list Function
				list();
				cout << "\n";
			break;
			
			case 4: // Call NextPatient Function
	            NextPatient();
				cout << "\n";
			break;
			
			case 5: // Call deletelist Function
			void deletelist();

				deletelist();
			break;
			
			case 6: // Terminates program
				cout << "\nProgram terminated..";
			break;
			
			default: // Incorrect Input message
				cout << "\n \tIncorrect Input\n";
		}
				
	}while(choice!=6);
	


	return 0; 
}












