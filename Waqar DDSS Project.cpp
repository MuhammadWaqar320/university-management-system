
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                               KICSIT Management System                                                    //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //Declaration of Header files
#include<iostream>
#include<cstring>
#include<conio.h>
#include<unistd.h>
#include<windows.h>
#define ENTERKEY 13
#define TAB 9
#define BKSP 8
#define SPACE 32
using namespace std;
struct Linkedlist
{
  	char name[100],Fname[100],program[100],Bld_Grp[4];
  	char designation[100],address[100],hod[100],dom[67];
  	float gpa,cgpa,CGpa,total_hour,sgpa,T_NTS,T_Mt,T_Fsc,Agrgte,P_Agrgte;
	string cnic,pay,grade,mon,tuse,wed,thur,fri;
  	string DOB,Reg_No,id,nam,edu,subject;
  	int number,No,semester,TS,h,s,wk,A,P;
	float present,total_class,T_Marks,O_Marks,nts,fsc,matric;
	Linkedlist *ptr;
};
struct Queue
{
	char name[100],program[100],address[100];
	string semester,amount,Reg_No;
	Queue *next;
};
struct Tree
{
	string cnic,pay, DOB,edu;
	char name[100],Fname[100],program[100],Bld_Grp[4];
	char address[100],designation[100];
	int scale;
	Tree *right,*left;
};
//class 1 
class Person       // Parent class 
{
protected:         //Access Modifier
    //Data member	
	string Name_of_Person;
	string FatherName_of_Person;
	string Address_of_Person;
	string DateOfBirth_of_Person;
	string BloodGroup_of_Person;	
public:              //Access Modifier
    Person()                    //Constructor
    {
		Name_of_Person="\0";
		FatherName_of_Person="\0";
		Address_of_Person="\0";
		DateOfBirth_of_Person="\0";
		BloodGroup_of_Person="\0";		
	}
	//Member Function for Set value (Setter)
    void SetName_of_Person(string Name)
    {
		Name_of_Person=Name;
	}
	void SetFatherName_of_Person(string FName)
	{
		FatherName_of_Person=FName;
	} 
	void SetAddress_of_Perosn(string Address)
	{
		Address_of_Person=Address;
	}
	void SetDateOfBirth_of_Person(string DOB)
	{
		DateOfBirth_of_Person=DOB;
	}
	void SetBloodGroup_of_Person(string BldGroup)
	{
		BloodGroup_of_Person=BldGroup;
	} 	
	//Getter Function for Get value (Getter)
	string GetName_of_Person()
	{
		return Name_of_Person;
	}
	string GetFatherName_of_Person()
	{
		return FatherName_of_Person;
	}
	string GetAddress_of_Perosn()
	{
		return Address_of_Person;
	}
	string GetDateOfBirth_of_Person()
	{
		return DateOfBirth_of_Person;
	}
	string GetBloodGroup_of_Person()
	{
		return BloodGroup_of_Person;
	}
};//Ending of person class
//class 2
class Student:public Person  // Child class of Person class
{
private:             //Access Modifier 
	//Data Member
	string Registration_No;
	string Program;
	int Semester;
	double CGPA;
public: 
	static int stu_Counter;                      //Access Modifier
	   //Static variable whose value is same for all objects
	Student()             //Constructor
	{
		Registration_No="\0";//\0 Null chara
		Program="\0";
		Semester=0;
	}
	//Member funtion for Set value (Setter)
	void Set_StudentRegistration_No(string Reg_No)
	{
	Registration_No=Reg_No;
    }
    void SetProgram(string _Program)
	{
    Program=_Program;
    }
    void SetSemester(int _Semester)
	{
	Semester=_Semester;
	}
	void setCGPA(double c)
	{
		CGPA=c;
	}
	//Member Function for Get value (getter)
	int GetSemester()
	{
	return Semester;
	}
	string Get_RegistrationNo()
	{
	return Registration_No;
	}
	string Get_Program()
	{
		return Program;
	}
	double GetCGPA()
	{
		return CGPA;
	}
	void Display_StudentInformation()
	{
		cout<<"Name of student is :"<<GetName_of_Person()<<endl;
		cout<<"Registration No of student is :"<<Get_RegistrationNo()<<endl;
		cout<<"Father Name of student is :"<<GetFatherName_of_Person()<<endl;
		cout<<"Address of student is :"<<GetAddress_of_Perosn()<<endl;
		cout<<"Program of student is :"<<Get_Program()<<endl;
		cout<<"Semester of student is :"<<GetSemester()<<endl;
		cout<<"Blood Group of student is :"<<GetBloodGroup_of_Person()<<endl;
		cout<<"Date of birth of student is :"<<GetDateOfBirth_of_Person()<<endl;
	}
};//Ending of Student class
//class 3 
class Faculty:public Person   // Child class of Person class
{
private:            //Access Modifier
	    //Data member					
	string CNIC_of_Faulty;
	string Monthly_Pay;
	string Designation;
	string Education;
	int kic;
	Tree *root,*next,*tem;
public:                            //Access Modifier
          //static variable
	Faculty()                        //Constructor
	{
		CNIC_of_Faulty="\0";
	    Monthly_Pay="\0";
	    Designation="\0";
	    next=NULL;
	    root=NULL;
	    kic=0;
	}
	void Insertion()
	{
		int flag=0,check=0;
		system("cls");
		cout<<"\t\t\tPlease Enter Information of Faculty \n";
		int Ch,f;
		Ch=f=1;
		while(Ch)
		{
			cout<<"___________________________Employee No."<<f<<"____________________________\n";
			tem=new Tree;					
			cout<<"Enter name of Faculty Employee :";
			cin.ignore();
			cin.getline(tem->name,100);
			for(int i=0;tem->name[i]!='\0';i++)   //validation for name
			{
				if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
				{
				    cout<<"Sorry You Entered invalid name \n";
					cout<<"Enter valid name :"<<endl;
					cin.ignore();
					cin.getline(tem->name,50);
					i=0;
				}
			}  
			cout<<"Enter CNIC of Employee :";
			cin>>tem->cnic;
			for(int i=0;i<tem->cnic.size();i++)   //validation for CNIC
		    {
			    if(!(isdigit(tem->cnic[i])||(tem->cnic[i]=='-')))
				{
					  cout<<"Sorry You Entered invalid CNIC \n";
					  cout<<"Enter valid CNIC :";
					  cin>>tem->cnic;
					  i=0;							
				}
			}
			cout<<"Enter Scale of Faculty  Employee :";
			cin>>tem->scale;
			cout<<"Enter Father name of Employee :";
			cin.ignore();
			cin.getline(tem->Fname,100);
			for(int i=0;tem->Fname[i]!='\0';i++)   //validation for name
			{
				if(!(isalpha(tem->Fname[i])||tem->Fname[i]=='.'||isspace(tem->Fname[i])))
				{
			     	cout<<"Sorry You Entered invalid name \n";
					cout<<"Enter valid name :"<<endl;
					cin.ignore();
					cin.getline(tem->Fname,50);
					i=0;
				}
			}  
			cout<<"Enter Address of Employee :";
			//		cin.ignore();
			cin.getline(tem->address,100);  
			cout<<"Enter Monthly pay of Employee :";
			cin>>tem->pay;
			cout<<"Enter Education of Employee :";
			cin>>tem->edu;
			cout<<"Enter Designation of Employee  :";
			cin.ignore();
			cin.getline(tem->designation,50);
			for(int i=0;tem->designation[i]!='\0';i++)   //validation for name
			{
			    if(!(isalpha(tem->designation[i])||tem->designation[i]=='.'||isspace(tem->designation[i])))
				{
					cout<<"Sorry You Entered invalid name \n";
					cout<<"Enter valid name :"<<endl;
					cin.ignore();
					cin.getline(tem->designation,50);
		     		i=0;
		    	}
    		}  
			cout<<"Enter Blood Group of Employee:";
	//		cin.ignore();
			cin.getline(tem->Bld_Grp,50);
			for(;;)
			{
	   			for(int i=0;tem->Bld_Grp[i]!='\0';i++)   //validation for Blood Group
    			{
            		if(!(isalpha(tem->Bld_Grp[i])||tem->Bld_Grp[i]=='+'||(tem->Bld_Grp[i]=='-')))
            		{
    	    			cout<<"Sorry You Entered invalid Blood Group \n";
                		cout<<"Enter valid Blood Group :";
                		//cin.ignore();
						cin.getline(tem->Bld_Grp,50);
                		i=0;
                		check=1;
                		continue;
            		}
    			}
        			if(check!=1)
        			{
        				break;
					}
					check=0;
    		}
			cout<<"Enter Date of Birth of Employee :";
			cin>>tem->DOB;
			for(;;)
			{
	   			for(int i=0;i<tem->DOB.size();i++)   //validation for Blood Group
    			{
            		if(!(isalpha(tem->DOB[i])||tem->DOB[i]==','||(tem->DOB[i]=='-')||isdigit(tem->DOB[i])||tem->DOB[i]=='/'))
            	    {
    	    			cout<<"Sorry You Entered invalid Date \n";
                		cout<<"Enter valid Date :";
                		//cin.ignore();
						cin>>tem->DOB;
                		i=0;
                		check=1;
                		continue;
            		}
    			}
        			if(check!=1)
        			{
        				break;
					}
					check=0;
           	}
					if(next==NULL)
					{
						root=next=tem;
					}
					else
					{
						next->left=tem;
						next=tem;
					}
					kic=1;;
					cout<<"Do you want to add another faculty member (1/0) :";
					cin>>Ch;
					cout<<endl;
					f++;
			}		
	}
void Searching()
{
	string cnic;
	system("cls");
	cout<<"\t\t\tFOR SEARCHING ENTER CNIC OF EMPLOYEE\n";
	cout<<"Enter CNIC of Faculty for Search Record : ";
	cin>>cnic;
	int flag=0;
	tem=root;
	next->left=NULL;
	while(tem!=NULL)
	{
    	if(tem->cnic==cnic)
	    {
	      	flag=1;
	        break;
		}
	    else
		{
			tem=tem->left;
		}
	}
	    if(flag)
		{
			cout<<"-------------------------------------------------\n";
			cout<<"Name of Faculty member is          :"<<tem->name<<endl;
			cout<<"CNIC No of Faculty member is       :"<<tem->cnic<<endl;
			cout<<"Father Name of Faculty member is   :"<<tem->Fname<<endl;
			cout<<"Address of  Faculty member is      :"<<tem->address<<endl;
			cout<<"Education of  Faculty member is    :"<<tem->edu<<endl;
			cout<<"Designation of Faculty member is   :"<<tem->designation<<endl;
			cout<<"Monthly pay of Faculty member is   :"<<tem->pay<<endl;
			cout<<"Blood Group of Faculty member is   :"<<tem->Bld_Grp<<endl;
			cout<<"Date of birth of Faculty member is :"<<tem->DOB<<endl;
			cout<<"-------------------------------------------------\n";
		}
		else
		{
			cout<<"\t\t\t\t\tPlease enter valid cnic: "<<endl;
		}
	    	getch();
}
void Deletion()
{
	system("cls");
	int flag=0;
	string cnic;
	cout<<"Enter cnic  of Employee for deletion : ";
  	cin>>cnic;
    for(int i=0;i<cnic.size();i++)   //validation for CNIC
	{
		if(!(isdigit(cnic[i])||(cnic[i]=='-')))
		{
			cout<<"Sorry You Entered invalid CNIC \n";
			cout<<"Enter valid CNIC :";
			cin>>cnic;
			i=0;							
		}
	}	 
		if(root==NULL)
		{
			cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	        getch();
		}
		else if(root->cnic==cnic)
		{
		    tem=root;
			root=root->left;
			delete(tem);
			cout<<"\n\t\t\tDeleted Successfully";
			getch();
		}
		else if(next->cnic==cnic)
		{
		    Tree *tp;
			tp=root;
			while(tp->left!=NULL)
			{
				if(tp->left->cnic==cnic)
				{
				    tem=tp->left;
					tp->left=tem->left;
					delete(tem);
				}
				else
				{
					tp=tp->left;
				}
			}
		cout<<"\n\t\t\tDeleted Successfully";
		getch();
		}
		else if(root->cnic!=cnic&&next->cnic!=cnic)
		{
			Tree *temp;	
	        temp=root;
	        while(temp->left->left!=NULL)
	        {
	        	if(temp->left->cnic==cnic)
	        	{
	        		flag=1;
	        		break;
				}
				else
				{
					temp=temp->left;
					tem=temp->left;
				}
			}
			    if(flag)
				{
					temp->left=temp->left->left;
					cout<<"\n\t\t\tDeleted Successfully";
					getch();
				}
		}
		else
		{
			cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
			getch();
		}
					
}
void bubbleSort(Tree *start) 
{ 
    int swapped, i; 
     Tree *ptr1; 
     Tree *lptr = NULL; 
    if (start == NULL) 
        return; 
    do
    { 
        swapped = 0; 
        ptr1 = start; 
        while (ptr1->left != lptr) 
        { 
            if (ptr1->scale < ptr1->left->scale) 
            {  
                swap(ptr1, ptr1->left); 
                swapped = 1;
            } 
            ptr1 = ptr1->left; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
/* function to swap data of two nodes a and b*/
void swap(Tree *a, Tree *b) 
{ 
  int temp = a->scale; 
    a->scale = b->scale; 
    b->scale = temp;
    //Swap name
    char temp1[100]; 
    strcpy(temp1,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,temp1);
    //swap cnic
    string temp2;
    temp2=a->cnic;
    a->cnic=b->cnic;
    b->cnic=temp2;
    //swap address
    char temp3[100];
    strcpy(temp3,a->address);
    strcpy(a->address,b->address);
    strcpy(b->address,temp3);
    //swap blood group
    char temp4[100];
    strcpy(temp4,a->Bld_Grp);
    strcpy(a->Bld_Grp,b->Bld_Grp);
    strcpy(b->Bld_Grp,temp4);
    //swap designation
    char temp5[100];
    strcpy(temp5,a->designation);
    strcpy(a->designation,b->designation);
    strcpy(b->designation,temp5);
	//swap DOB 
    string temp6; 
    temp6=a->DOB;
    a->DOB=b->DOB;
    b->DOB=temp6;
    //swap edu
    string temp7;
    temp7=a->edu;
    a->edu=b->edu;
    b->edu=temp7;
    //swap Fname
    char temp8[100];
    strcpy(temp8,a->Fname);
    strcpy(a->Fname,b->Fname);
    strcpy(b->Fname,temp8);
    //swap pay
    string temp9; 
    temp9=a->pay;
    a->pay=b->pay;
    b->pay=temp9;
}
void Updation()
{
	string cnic;
	int check,Ch,f;
	system("cls");
	cout<<"\t\t\tFOR SEARCHING ENTER CNIC OF EMPLOYEE\n";
	cout<<"Enter CNIC of Faculty for Search Record : ";
	cin>>cnic;
	int flag=0;
	tem=root;
	next->left=NULL;
	while(tem!=NULL)
	{
    	if(tem->cnic==cnic)
	    {
	      	flag=1;
	        break;
		}
	    else
		{
			tem=tem->left;
		}
	}
	    if(flag)
		{
			cout<<"-------------------Updation-----------------------\n";
		cout<<"Enter name of Faculty Employee :";
			cin.ignore();
			cin.getline(tem->name,100);
			for(int i=0;tem->name[i]!='\0';i++)   //validation for name
			{
				if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
				{
				    cout<<"Sorry You Entered invalid name \n";
					cout<<"Enter valid name :"<<endl;
					cin.ignore();
					cin.getline(tem->name,50);
					i=0;
				}
			}  
			cout<<"Enter CNIC of Employee :";
			cin>>tem->cnic;
			for(int i=0;i<tem->cnic.size();i++)   //validation for CNIC
		    {
			    if(!(isdigit(tem->cnic[i])||(tem->cnic[i]=='-')))
				{
					  cout<<"Sorry You Entered invalid CNIC \n";
					  cout<<"Enter valid CNIC :";
					  cin>>tem->cnic;
					  i=0;							
				}
			}
			cout<<"Enter Scale of Faculty  Employee :";
			cin>>tem->scale;
			cout<<"Enter Father name of Employee :";
			cin.ignore();
			cin.getline(tem->Fname,100);
			for(int i=0;tem->Fname[i]!='\0';i++)   //validation for name
			{
				if(!(isalpha(tem->Fname[i])||tem->Fname[i]=='.'||isspace(tem->Fname[i])))
				{
			     	cout<<"Sorry You Entered invalid name \n";
					cout<<"Enter valid name :"<<endl;
					cin.ignore();
					cin.getline(tem->Fname,50);
					i=0;
				}
			}  
			cout<<"Enter Address of Employee :";
			//		cin.ignore();
			cin.getline(tem->address,100);  
			cout<<"Enter Monthly pay of Employee :";
			cin>>tem->pay;
			cout<<"Enter Education of Employee :";
			cin>>tem->edu;
			cout<<"Enter Designation of Employee  :";
			cin.ignore();
			cin.getline(tem->designation,50);
			for(int i=0;tem->designation[i]!='\0';i++)   //validation for name
			{
			    if(!(isalpha(tem->designation[i])||tem->designation[i]=='.'||isspace(tem->designation[i])))
				{
					cout<<"Sorry You Entered invalid name \n";
					cout<<"Enter valid name :"<<endl;
					cin.ignore();
					cin.getline(tem->designation,50);
		     		i=0;
		    	}
    		}  
			cout<<"Enter Blood Group of Employee:";
			cin.getline(tem->Bld_Grp,50);
			for(;;)
			{
	   			for(int i=0;tem->Bld_Grp[i]!='\0';i++)   //validation for Blood Group
    			{
            		if(!(isalpha(tem->Bld_Grp[i])||tem->Bld_Grp[i]=='+'||(tem->Bld_Grp[i]=='-')))
            		{
    	    			cout<<"Sorry You Entered invalid Blood Group \n";
                		cout<<"Enter valid Blood Group :";
                		//cin.ignore();
						cin.getline(tem->Bld_Grp,50);
                		i=0;
                		check=1;
                		continue;
            		}
    			}
        			if(check!=1)
        			{
        				break;
					}
					check=0;
    		}
			cout<<"Enter Date of Birth of Employee :";
			cin>>tem->DOB;
			for(;;)
			{
	   			for(int i=0;i<tem->DOB.size();i++)   //validation 
    			{
            		if(!(isalpha(tem->DOB[i])||tem->DOB[i]==','||(tem->DOB[i]=='-')||isdigit(tem->DOB[i])||tem->DOB[i]=='/'))
            	    {
    	    			cout<<"Sorry You Entered invalid Date \n";
                		cout<<"Enter valid Date :";
                		//cin.ignore();
						cin>>tem->DOB;
                		i=0;
                		check=1;
                		continue;
            		}
    			}
        			if(check!=1)
        			{
        				break;
					}
					check=0;
           	}
			f++;
			cout<<"\n\nData Updated Successfully\n";
		}
		else
		{
			cout<<"\t\t\t\t\tPlease enter valid cnic: "<<endl;
		}
	    	getch();
}
void PreOrder_Display()
{
	int f;
	system("cls");
	if(kic==1)
	{
	    cout<<"                                                        SAVED RECORD\n";
		f=1;
		bubbleSort(root);
		tem=root;
		next->left=NULL;
		int fag=1;
		while(tem!=NULL)
		{
			cout<<"---------------------Employee No."<<f<<"-------------------------\n";
			cout<<"Information of Employee No."<<f<<" \n";
			cout<<"Name of Faculty member is        :"<<tem->name<<endl;
			cout<<"CNIC No of Faculty member is       :"<<tem->cnic<<endl;
			cout<<"Scale No of Faculty member is      :"<<tem->scale<<endl;
			cout<<"Father Name of Faculty member is   :"<<tem->Fname<<endl;
			cout<<"Address of  Faculty member is      :"<<tem->address<<endl;
			cout<<"Education of  Faculty member is    :"<<tem->edu<<endl;
			cout<<"Designation of Faculty member is   :"<<tem->designation<<endl;
			cout<<"Monthly pay of Faculty member is   :"<<tem->pay<<endl;
			cout<<"Blood Group of Faculty member is   :"<<tem->Bld_Grp<<endl;
			cout<<"Date of birth of Faculty member is :"<<tem->DOB<<endl;
			tem=tem->left;
			f++;
			fag=0;
		}
		if(fag)
		{
			cout<<"\n\n\n\n\t\t\t\tSorry Record Not Saved\n";
		}
	    	getch();
	}
	else
	{
	   	system("cls");
   		cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	   	getch();
	}
}	
};
//End of employee class
//class 4                    
class Department
{
private:          //access modifier
    //Data members	
	string name_of_Dep;
	string Id;
	string Head_of_Department;
	int  No_of_Student;
	int  No_of_lecturer;
	int Total_ReSearch;	
public:                 //access modifier	
	static int depart_counter;  ////static variable
    Department()     //Constructor
    {
		name_of_Dep="\0";
	    Id="\0";
	    Head_of_Department="\0";
	    No_of_Student=0;
	    No_of_lecturer=0;
	}
  //Member variable for set value(setter)    
	void TotalReSearch(int TR)
	{
		Total_ReSearch=TR;
	}
	void SetName_of_Dep(string name)
	{
	    name_of_Dep=name;	
    }
	void SetId_of_Dep(string id)
	{
	    Id=id;
	}
	void SetHead_of_Department(string hod)
	{
	    Head_of_Department=hod;
	}
	void SetNo_of_Student(int S_no)
	{
	    No_of_Student=S_no;
	}
	void SetNo_of_lecturer(int L_no)
	{
	    No_of_lecturer=L_no;
	}
  //Member variable for get value(getter)
	int  TotalReSearch()
	{
		return Total_ReSearch;
	}
	string GetName_of_Dep()
	{
	    return name_of_Dep;
	}
	string GetId_of_Dep()
	{
		return Id;
	}
	string GetHead_of_Department()
	{
		return Head_of_Department;
	}
	int GetNo_of_Student()
	{
		return No_of_Student;
	}
	int GetNo_of_lecturer()
	{
		return No_of_lecturer;
	}
	void Display_Dep()
	{
		cout<<"Name of Department is :"<<GetName_of_Dep()<<endl;
		cout<<"Id of Department is :"<<GetId_of_Dep()<<endl;
		cout<<"Head of Department is :"<<GetHead_of_Department()<<endl;
		cout<<"Number of students they have "<<GetName_of_Dep()<<" Department are :"<<GetNo_of_Student()<<endl;
		cout<<"Number of Lecturer they have "<<GetName_of_Dep()<<" Department are :"<<GetNo_of_lecturer()<<endl;
		cout<<"Total  ReSearch in "<<GetName_of_Dep()<<" Department are :"<<TotalReSearch()<<endl;
	}
}; //End of department class
void Degree()
{
	cout<<"                   ================================================================\n";
	cout<<"                   |                            SUB MENU                          |\n";
	cout<<"                   ================================================================\n";
	cout<<"                   |            1.    BS in Computer Science (BSCS)               |\n";
	cout<<"                   |            2.    BS in Computer Engineering (BSCE)           |\n";
	cout<<"                   |            3.    Back                                        |\n";
    cout<<"                   ----------------------------------------------------------------\n";
}
//class 5
class Admin
{
private:               //access modifier
    //Data members	
	string NameAdministrator;
	string Address_Administrator;
	string CNIC_Administrator;
	string Employee_No_of_Admin;
	string Date_of_Birth;
	int Total_Lecturer;
	int Total_Student;
	int Total_Room;
	int Total_Employee;
public:                   //access modifier
    Admin()          //Constructor
    {
	NameAdministrator="\0";
		Address_Administrator="\0";
		CNIC_Administrator="\0";
		Employee_No_of_Admin="\0";
		Date_of_Birth="\0";
		Total_Lecturer=0;
		Total_Student=0;
		Total_Room=0;
		Total_Employee=0;
	}
  //Member variable for set value(setter)
	void SetNameAdministrator(string name)
	{
		NameAdministrator=name;
	}
	void SetAddress_Administrator(string address)
	{
		Address_Administrator=address;
	}
	void SetCNIC_Administrator(string cnic)
	{
		CNIC_Administrator=cnic;
	}
	void SetEmployee_No_of_Admin(string Eno)
	{
		Employee_No_of_Admin=Eno;
	}
	void SetDate_of_BirthAdmin(string DOB)
	{
		Date_of_Birth=DOB;
	}
	void SetTotal_Lecturer(int Tlec)
	{
		Total_Lecturer=Tlec;
    }
	void SetTotal_Student(int TStu)
	{
		Total_Student=TStu;
	}
	void SetTotal_Room(int Trom)
	{
		Total_Room=Trom;
	}
	void SetTotal_Employee(int emp)
	{
		Total_Employee=emp;
	}
	string GetNameAdministrator()
	{
		return NameAdministrator;
	}
	string GetCNIC_Administrator()
	{
		return CNIC_Administrator;
	}
	string GetEmployee_No_of_Admin()
	{
		return Employee_No_of_Admin;
	}
	string GetDate_of_BirthAdmin()
	{
		return Date_of_Birth;
	}
	string GetAddress_Administrator()
	{
		return Address_Administrator;;
	}
	int GetTotal_Lecturer()
	{
		return Total_Lecturer;
	}
	int GetTotal_Student()
	{
		return Total_Student;
	}
	int GetTotal_Room()
	{
		return Total_Room;
	}
	int GetTotal_Employee()
	{
		return Total_Employee;
	}
	void Display_Admin()
	{
		cout<<"Name of Administrator is :"<<GetNameAdministrator()<<endl;
		cout<<"CNIC of Administrator is   :"<<GetCNIC_Administrator()<<endl;
		cout<<"Address of Administrator is 	:"<<GetAddress_Administrator()<<endl;
		cout<<"Date of Birth of Administrator is :"<<GetDate_of_BirthAdmin()<<endl;
		cout<<"Employee Number of Administrator is :"<<GetEmployee_No_of_Admin()<<endl;
		cout<<"Total number of Employees in univeristy are :"<<GetTotal_Employee()<<endl;
		cout<<"Total number of Lecturers in univeristy are :"<<GetTotal_Lecturer()<<endl;
		cout<<"Total number of Students in univeristy are  :"<<GetTotal_Student()<<endl;
		cout<<"Total number of Rooms in univeristy are     :"<<GetTotal_Room()<<endl;
	}
}; //End of admin class
  //class  6           
class GPA_Calculator
{
private:           //Access Modifier
	//Data member              
	string Name_of_student;
	string Grade;
	string Registration;
	double Credit_Hour;
	double Final_GPA;
	double Final_CGPA;
	double S_GPA[10];
	double Total_CreditHour;
	double Obtain_CreditHour;
	double Total_Obtain_CreditHour;
	char Name_of_subject[50];
public:               //Access Modifier
	GPA_Calculator()   //Constructor
	{
		Name_of_student="\0";
		Credit_Hour=0;
		Grade="\0";
		Final_GPA=0;
		Final_CGPA=0;
		S_GPA[10]=0;
		Name_of_subject[50]='\0';
		double Total_CreditHour=0.0;
	   	double Obtain_CreditHour=0.0;
	   	double Total_Obtain_CreditHour=0.0;		
	}
	//Member function
	void SetReg(string reg)
	{
		Registration=reg;
	}
	string Get_Name_of_student()
	{
		return Name_of_student;
	}
	string GetReg()
	{
		return Registration;
	}
	void SSSGPA_Calculator(string grad,float C_H)
	{
	   Grade=grad;
	   Credit_Hour=C_H;
	   const double A = 4.0;
       const double A_MINUS = 3.67;
	   const double B_PLUS = 3.33;
	   const double B = 3.0;
	   const double B_MINUS = 2.67;
	   const double C_PLUS = 2.33;
	   const double C = 2.0;
	   const double C_MINUS = 1.67;
	   const double D = 1.00;
	   const double F = 0.0;
	   int choice;
			//calculating credit hours
			if(Grade=="a"||Grade=="A")
			{
			 Obtain_CreditHour=Credit_Hour*A;
			}
			else if(Grade=="a-"||Grade=="A-")
			{
				Obtain_CreditHour=Credit_Hour*A_MINUS;
			}
			else if(Grade=="b+"||Grade=="B+")
			{
				Obtain_CreditHour=Credit_Hour*B_PLUS;
			}
			else if(Grade=="b"||Grade=="B")
			{
				Obtain_CreditHour=Credit_Hour*B;
			}
			else if(Grade=="b-"||Grade=="B-")
			{
			    Obtain_CreditHour=Credit_Hour*B_MINUS;
			}
			else if(Grade=="c+"||Grade=="C+")
			{
				Obtain_CreditHour=Credit_Hour*C_PLUS;
			}
			else if(Grade=="c"||Grade=="C")
			{
				Obtain_CreditHour=Credit_Hour*C;
			}
			else if(Grade=="c-"||Grade=="C-")
			{
				Obtain_CreditHour=Credit_Hour*C_MINUS;
			}
			else if(Grade=="d"||Grade=="D")
			{
				Obtain_CreditHour=Credit_Hour*D;
			}
			else if(Grade=="f"||Grade=="F")
			{
				Obtain_CreditHour=Credit_Hour*F;
			}
			else
			{
				cout<<"Invalid input"<<endl;
			}
			Total_CreditHour=Total_CreditHour+Credit_Hour;
			Total_Obtain_CreditHour=Total_Obtain_CreditHour+Obtain_CreditHour;
	//GPA calculating formula
	Final_GPA=Total_Obtain_CreditHour/Total_CreditHour;
	}
	void SGPA_Calculator(int no,string _Name_of_student)
	{
	   no++;
	   Name_of_student=_Name_of_student;
	   const double A = 4.0;
       const double A_MINUS = 3.67;
	   const double B_PLUS = 3.33;
	   const double B = 3.0;
	   const double B_MINUS = 2.67;
	   const double C_PLUS = 2.33;
	   const double C = 2.0;
	   const double C_MINUS = 1.67;
	   const double D = 1.00;
	   const double F = 0.0;
	   int choice;
	   double Total_CreditHour=0.0;
	   double Obtain_CreditHour=0.0;
	   double Total_Obtain_CreditHour=0.0;
	   cout<<"Enter Subjects,Grade and credit hour for student "<<no<<" :"<<endl;
       for( ;; )
		{
			cout<<"Enter Name of subject :";
			cin.ignore();
			cin.getline(Name_of_subject,50);
			cout<<"Enter grade in Subject :";
			cin>>Grade;
			cout<<"Enter credit hour of Subject :";
			cin>>Credit_Hour;
			//calculating credit hours
			if(Grade=="a"||Grade=="A")
			{
			 Obtain_CreditHour=Credit_Hour*A;
			}
			else if(Grade=="a-"||Grade=="A-")
			{
				Obtain_CreditHour=Credit_Hour*A_MINUS;
			}
			else if(Grade=="b+"||Grade=="B+")
			{
				Obtain_CreditHour=Credit_Hour*B_PLUS;
			}
			else if(Grade=="b"||Grade=="B")
			{
				Obtain_CreditHour=Credit_Hour*B;
			}
			else if(Grade=="b-"||Grade=="B-")
			{
			    Obtain_CreditHour=Credit_Hour*B_MINUS;
			}
			else if(Grade=="c+"||Grade=="C+")
			{
				Obtain_CreditHour=Credit_Hour*C_PLUS;
			}
			else if(Grade=="c"||Grade=="C")
			{
				Obtain_CreditHour=Credit_Hour*C;
			}
			else if(Grade=="c-"||Grade=="C-")
			{
				Obtain_CreditHour=Credit_Hour*C_MINUS;
			}
			else if(Grade=="d"||Grade=="D")
			{
				Obtain_CreditHour=Credit_Hour*D;
			}
			else if(Grade=="f"||Grade=="F")
			{
				Obtain_CreditHour=Credit_Hour*F;
			}
			else
			{
				cout<<"Invalid input"<<endl;
			}
			Total_CreditHour=Total_CreditHour+Credit_Hour;
			Total_Obtain_CreditHour=Total_Obtain_CreditHour+Obtain_CreditHour;
			cout<<"Do you want to enter grade of another subject Of this student (1-Yes ,2-No) :";
			cin>>choice;
			if(choice==1)
			{
				continue;
			}
			else
			{
				break;
			}
		}
	//GPA calculating formula
	Final_GPA=Total_Obtain_CreditHour/Total_CreditHour;
	}
     //CGPA calculating
     float Final_SGPA()
     {
     	return Final_GPA;
	 }
	void CGPA_Calculator(int no,string _Name_of_student)
	{
		Name_of_student=_Name_of_student;
		int ch;
		float Semesters_GPA[10];
		no++;
		cout<<"How many semester's result( In GPA ) you want to input of student No "<<no<<" :";
		cin>>ch;
		cout<<"Enter semester result in SGPA of student No "<<no<<endl;
		for(int i=0;i<ch;i++)
		{
			cout<<"Enter SGPA of "<<i+1<<" semester :";
			cin>>Semesters_GPA[i];
		}
		float Total_GPA=0.0;
		for(int i=0;i<ch;i++)
		{
		  Total_GPA=Total_GPA+Semesters_GPA[i];	
		}
		Final_CGPA=Total_GPA/ch;
	}
	//Function for displaying SGPA of students
	float final_CGPA()
	{
		return Final_CGPA;
	}
};//Ending of GPA class 
// class 7 
class Accountant:public Person
{
private:               //access modifier
    //Data members
	string CNIC_Accountant;
	string Employee_No_of_A;
	int Total_Student;
public:                   //access modifier
    Accountant()          //Constructor
    {
		CNIC_Accountant="\0";
		Employee_No_of_A="\0";
		Total_Student=0;
	}
  //Member variable for set value(setter)
	void SetCNIC_Accountant(string cnic)
	{
		CNIC_Accountant=cnic;
	}
	void SetEmployee_No_of_A(string Eno)
	{
		Employee_No_of_A=Eno;
	}
	void SetTotal_Student(int TStu)
	{
		Total_Student=TStu;
	}
	string GetCNIC_Accountant()
	{
		return CNIC_Accountant;
	}
	string GetEmployee_No_of_A()
	{
		return Employee_No_of_A;
	}
	int GetTotal_Student()
	{
		return Total_Student;
	}
	void Display_Acc()
	{
		cout<<"Name of Accountant is  :"<<GetName_of_Person()<<endl;
		cout<<"CNIC of Accountant is :"<<GetCNIC_Accountant()<<endl;
		cout<<"Address of Accountant is :"<<GetAddress_of_Perosn()<<endl;
		cout<<"Date of Birth of Accountant is :"<<GetDateOfBirth_of_Person()<<endl;
		cout<<"Employee Number of Accountant is :"<<GetEmployee_No_of_A()<<endl;
		cout<<GetTotal_Student()<<" students are taking need base Scholarship."<<endl;
	}
};               
class University
{
private:            //Access Modifier
	//Data members                   
	string Id_of_Uni;
	string Name_of_Uni;
	string Address_of_Uni;
	int Total_Room;
	int Campus_NO;
	int libr_NO,P_ground;
	//For composition here we are creating objects
	Admin admin;
public:                 //Access Modifier
   	University()         //Constructor
   	{
		Id_of_Uni="\0";
		Name_of_Uni="\0";
		Address_of_Uni="\0";
		Total_Room=0;
		Campus_NO=0;
		libr_NO=0;
		P_ground=0;
		
   	}
   //Member function for set value (setter)
   	void SetCampus(int c)
   	{
   		Campus_NO=c;
	}
	void SetTotal_Library(int l)
	{
		libr_NO=l;	
	}
	void SetP_Ground(int p)
	{
		P_ground=p;	
	}		
	void SetId_of_Uni(string id)
	{
		Id_of_Uni=id;
	}
	void SetName_of_Uni(string Name)
	{
		Name_of_Uni=Name;
	}
	void SetAddress_of_Uni(string Address)
	{
		Address_of_Uni=Address;
	}
	void SetTotal_Room(int room)
	{
		Total_Room=room;
	}	
	//Member function for get value (getter)
	int GetCampus()
   	{
   		return Campus_NO;
	}
	int  GetTotal_Library()
	{
		return libr_NO;	
	}
	int  GetP_Ground()
	{
		return P_ground;	
	}
	string GetId_of_Uni()
	{
		return Id_of_Uni;
	}
	string GetName_of_Uni()
	{
		return Name_of_Uni;
	}
	string GetAddress_of_Uni()
	{
		return Address_of_Uni;
	}
	int GetTotal_Room()
	{
		return Total_Room;
	}
	void Display_Uni()
	{
		cout<<"FULL Form of KICSIT is :"<<GetName_of_Uni()<<endl;
		cout<<"Id of KICSIT is :"<<GetId_of_Uni()<<endl;
		cout<<"Address of KICSIT is :"<<GetAddress_of_Uni()<<endl;
		cout<<"Total campus of KICSIT are : "<<GetCampus()<<endl;
		cout<<"Total Libraries in KICSIT are :"<<GetTotal_Library()<<endl;
		cout<<"KICSIT  has "<<GetP_Ground() <<" Play Ground. "<<endl;
		cout<<"Total Number of Rooms are :"<<GetTotal_Room()<<endl;
	}
	void Add_Admin(Admin adm)
	{
		admin=adm;
	}
	void Show_Admin()
	{
	    cout<<"DISPLAYING INFORMATION OF ADMIN\n";
	    cout<<endl;
		admin.Display_Admin();	
	}
};//Ending of University class
//class 8
class Lecturer
{
	private:
		Linkedlist *head,*last,*tem;
		Linkedlist *temm,*head6,*last6;
		int kic,z;
	public:
		Lecturer()
		{
			head=NULL;
			last=NULL;
			temm=NULL;
			last6=head6=NULL;
			kic=z=0;
		}
		void Insertion()
		{
			int flag=0,check=0;
			system("cls");
			cout<<"\t\t\tPlease Enter Information of Faculty \n";
			int Ch,f;
			Ch=f=1;
			while(Ch)
			{
				cout<<"-------------------------Lecturer No."<<f<<" -------------------------\n";
				tem=new Linkedlist;					
				cout<<"Enter name of  Lecturer :";
				cin.ignore();
				cin.getline(tem->name,100);
				for(int i=0;tem->name[i]!='\0';i++)   //validation for name
				{
					if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
					{
				    	cout<<"Sorry You Entered invalid name \n";
						cout<<"Enter valid name :"<<endl;
						cin.ignore();
						cin.getline(tem->name,50);
						i=0;
					}
				}  
				cout<<"Enter CNIC of Lecturer :";
				cin>>tem->cnic;
				for(int i=0;i<tem->cnic.size();i++)   //validation for CNIC
		   		 {
			    	if(!(isdigit(tem->cnic[i])||(tem->cnic[i]=='-')))
					{
						cout<<"Sorry You Entered invalid CNIC \n";
					  	cout<<"Enter valid CNIC :";
					  	cin>>tem->cnic;
					  	i=0;							
					}
				}
				cout<<"Enter Father name of Lecturer :";
				cin.ignore();
				cin.getline(tem->Fname,100);
				for(int i=0;tem->Fname[i]!='\0';i++)   //validation for name
				{
					if(!(isalpha(tem->Fname[i])||tem->Fname[i]=='.'||isspace(tem->Fname[i])))
					{
			     		cout<<"Sorry You Entered invalid name \n";
						cout<<"Enter valid name :"<<endl;
						cin.ignore();
						cin.getline(tem->Fname,50);
						i=0;
					}
				}	  
				cout<<"Enter Address of Lecturer :";
				//cin.ignore();
				cin.getline(tem->address,100);  
				cout<<"Enter Monthly pay of Lecturer :";
				cin>>tem->pay;
				cout<<"Enter Qualification of Lecturer :";
				cin>>tem->edu; 
				cout<<"Enter Blood Group of Lecturer:";
				cin.ignore();
				cin.getline(tem->Bld_Grp,50);
				for(;;)
				{
	   				for(int i=0;tem->Bld_Grp[i]!='\0';i++)   //validation for Blood Group
    				{
            			if(!(isalpha(tem->Bld_Grp[i])||tem->Bld_Grp[i]=='+'||(tem->Bld_Grp[i]=='-')))
            			{
    	    				cout<<"Sorry You Entered invalid Blood Group \n";
                			cout<<"Enter valid Blood Group :";
                			//cin.ignore();
							cin.getline(tem->Bld_Grp,50);
                			i=0;
                			check=1;
                			continue;
            			}
    				}
        			if(check!=1)
        			{
        				break;
					}
					check=0;
    			}
				cout<<"Enter Date of Birth of Lecturer :";
				cin>>tem->DOB;
				for(;;)
				{
	   				for(int i=0;i<tem->DOB.size();i++)   //validation for Blood Group
    				{
            			if(!(isalpha(tem->DOB[i])||tem->DOB[i]==','||(tem->DOB[i]=='-')||isdigit(tem->DOB[i])||tem->DOB[i]=='/'))
            	    	{
    	    				cout<<"Sorry You Entered invalid Date \n";
                			cout<<"Enter valid Date :";
                			//cin.ignore();
							cin>>tem->DOB;
                			i=0;
                			check=1;
                			continue;
            			}
    				}
        			if(check!=1)
        			{
        				break;
					}
					check=0;
           		}
				if(last==NULL)
				{
					head=last=tem;
				}
				else
				{
					last->ptr=tem;
					last=tem;
				}
				kic=1;;
				cout<<"Do you want to add another Lecturer member (1/0) :";
				cin>>Ch;
				cout<<endl;
				f++;
			}
			}		
void Attendance()
{
	string cnic;	
	system("cls");   	
	cout<<"\t\t\t\tATTENDANCE RECORD\n";
	   	cout<<"Enter CNIC number of student :";
					cin>>cnic;
					int flag=0;
					tem=head;
					last->ptr=NULL;
					temm=head6;
					last6->ptr=NULL;	
					while(tem!=NULL)
	        		{
	        			if(tem->cnic==cnic)
	        	   		{ 
	        			flag=1;
	        			break;
				   		}
				  		else
				  		{ 
						
						 
					       for(int i=0;i<tem->TS;i++)
					       {
					        	temm=temm->ptr;
					       }
					        tem=tem->ptr;
				 		} 
					}
					if(flag)
					{
			   			cout<<"Name    :"<<tem->name<<endl;
			   			cout<<"CNIC  :"<<tem->cnic<<endl;
			   			cout<<"Qualification :"<<tem->edu<<endl;
			   		//	cout<<"Semester:"<<tem->semester<<endl;
			   			cout<<"______________________________________________________________________________________________________\n";
			   			cout<<"Subject\t\t\tTotal classes\t\t\tAttendance\t\t\tPercentage\n";
						cout<<"______________________________________________________________________________________________________\n";
						for(int i=0;i<tem->TS;i++)
						{
						  cout<<temm->subject<<"\t\t\t"<<temm->total_class<<"\t\t\t\t"<<(temm->present)<<"\t\t\t\t"<<(((temm->present)*100)/(temm->total_class))<<"%"<<endl;
			   			  temm=temm->ptr;
						cout<<"______________________________________________________________________________________________________\n";
						}
					}
					else
					{
						system("cls");
						cout<<"\n\n\n\n\t\t\t\tPlease Enter Valid Registration Number: "<<endl;
					}
	    			getch();       	
}
void Searching()
{
	string cnic;
	system("cls");
	cout<<"\t\t\tFOR SEARCHING ENTER CNIC OF LECTURER\n";
	cout<<"Enter CNIC of lecturer for Search Record : ";
	cin>>cnic;
	int flag=0;
	tem=head;
	last->ptr=NULL;
	while(tem!=NULL)
	{
    	if(tem->cnic==cnic)
	    {
	      	flag=1;
	        break;
		}
	    else
		{
			tem=tem->ptr;
		}
	}
	if(head==NULL)
	{
		cout<<"\n\n\n\n\t\t\tSorry data is not saved\n";
	}
	if(flag)
	{
		cout<<"-------------------------------------------------------------\n";
		cout<<"Name of Lecturer is :"<<tem->name<<endl;
		cout<<"CNIC No of Lecturer is :"<<tem->cnic<<endl;
		cout<<"Father Name of Lecturer is :"<<tem->Fname<<endl;
		cout<<"Address of  Lecturer is :"<<tem->address<<endl;
		cout<<"Education of  Faculty member is :"<<tem->edu<<endl;
		cout<<"Monthly pay of Lecturer is :"<<tem->pay<<endl;
		cout<<"Blood Group of Lecturer is :"<<tem->Bld_Grp<<endl;
		cout<<"Date of birth of Lecturer is :"<<tem->DOB<<endl;
		cout<<"-------------------------------------------------------------\n";
	}
	else
	{
		cout<<"\t\t\t\t\tPlease enter valid cnic: "<<endl;
	}
	getch();
}
void Deletion()
{
	system("cls");
	int flag=0;
	string cnic;
	system("cls");
			cout<<"\t\t\tENTER CNIC FOR DELETION \n\n";
		    cout<<"Enter CNIC of Lecturer for deletion : ";
            cin>>cnic;
				if(head==NULL)
				{
					cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
					getch();
				}
				else if(head->cnic==cnic)
				{
					tem=head;
					head=head->ptr;
					delete(tem);
					cout<<"\n\t\t\tDeleted Successfully";
					getch();
				}
				else if(last->cnic==cnic)
				{
					Linkedlist *temp;
					temp=head;
					while(temp->ptr!=NULL)
					{
						if(temp->ptr->cnic==cnic)
						{
							tem=temp->ptr;
							temp->ptr=tem->ptr;
							delete(tem);
						}
						else
						{
							temp=temp->ptr;
						}
					}
					cout<<"\n\t\t\tDeleted Successfully";
					getch();
				}
				else if(head->cnic!=cnic&&last->cnic!=cnic)
				{
				Linkedlist *temp;	
	        	temp=head;
	        	while(temp->ptr->ptr!=NULL)
	        	{
	        		if(temp->ptr->cnic==cnic)
	        		{
	        		flag=1;
	        		break;
					}
					else
					{
					temp=temp->ptr;
					tem=temp->ptr;
					}
				}
				if(flag)
				{
					temp->ptr=temp->ptr->ptr;
					cout<<"\n\t\t\tDeleted Successfully";
					getch();
				}
				}
	    	else 
	    	{
				cout<<"Wrong input\n";
				getch(); 
			
		    }					
}
void Course()
{
	string cnic;
				system("cls");
				cout<<"Enter CNIC of lecturer :";
				cin>>cnic;
				int flag=0;
					tem=head;
					temm=head6;
					last6->ptr=NULL;	
					while(tem!=NULL)
	        		{
	        			if(tem->cnic==cnic)
	        	   		{ 
	        			flag=1;
	        			break;
				   		}
				  		else
				  		{  
					       for(int i=0;i<tem->TS;i++)
					       {
					        	temm=temm->ptr;
					       }
					     
						tem=tem->ptr;
				 		} 
					}
					if(flag)
					{
			   			cout<<"Name    :"<<tem->name<<endl;
			   			cout<<"CNIC :"<<tem->cnic<<endl;
			   			cout<<"Course under "<<tem->name<<endl;
			   			cout<<endl;
						cout<<"Subject\n";
						for(int i=0;i<tem->TS;i++)
						{
						  cout<<temm->subject<<endl;
			   			  temm=temm->ptr;	
						}
					}
					else
					{
						system("cls");
						cout<<"\n\n\n\n\t\t\t\tPlease Enter Valid CNIC: "<<endl;
					}
	    			getch();       	
}
	void Display()
	{	
	int f;
	system("cls");
	if(kic==1)
	{
	    cout<<"                                                        SAVED RECORD\n";
		f=1;
		tem=head;
		last->ptr=NULL;
		int fag=1;
		while(tem!=NULL)
		{
			cout<<"\n";
			cout<<"-------------------------Lecturer No."<<f<<" -------------------------\n";
			cout<<"Name of Lecturer is 			:"<<tem->name<<endl;
			cout<<"CNIC No of Lecturer is       :"<<tem->cnic<<endl;
			cout<<"Father Name of Lecturer is   :"<<tem->Fname<<endl;
			cout<<"Address of  Lecturer is      :"<<tem->address<<endl;
			cout<<"Qualification of  Lecturer is:"<<tem->edu<<endl;
			cout<<"Monthly pay of Lecturer is   :"<<tem->pay<<endl;
			cout<<"Blood Group of Lecturer is   :"<<tem->Bld_Grp<<endl;
			cout<<"Date of birth of Lecturer is :"<<tem->DOB<<endl;
			tem=tem->ptr;
			f++;
			fag=0;
		}
		if(fag)
		{
			cout<<"\n\n\n\n\t\t\t\tSorry Record Not Saved\n";
		}
	    	getch();
	}
	else
	{
	   	system("cls");
   		cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	   	getch();
	}
}	
};
class Examiner:public Person
{
	private:            //Access Modifier
	//Data member					
	string CNIC_of_Ex;
	string Monthly_Pay;
	string Designation;
public:                            //Access Modifier
	Examiner()                        //Constructor
	{
		CNIC_of_Ex="\0";
	    Monthly_Pay="\0";
	    Designation="\0";
	}
	// Mamber function for set value (setter)
	void SetCNIC_of_Ex(string cnic)
	{
		CNIC_of_Ex=cnic;
	}
	void SetMonthly_Pay(string pay)
	{
		Monthly_Pay=pay;
	}
	//Member function for get value (getter)
	string GetMonthly_Pay()
	{
	    return Monthly_Pay;
	}
	string GetCNIC_of_Ex()
	{
		return CNIC_of_Ex;
	}
	void Mid_Term_DateSheet()
	{
			cout<<" _________________________________________________________________________________________________________________"<<endl;
			cout<<"|                                          Group wise Date Sheet Mid Term                                         |"<<endl;
			cout<<"|_________________________________________________________________________________________________________________|"<<endl;
			cout<<"|             Group A            |      Paper Timing     |           Group B             |          Paper Timing  |"<<endl;
			cout<<"|Exam Hall Entry Timing:12:35hrs.|Group A 12:50to14:50hrs|Exam Hall Entry Timing:15:00hrs|Group A 15:15to17:15hrs |"<<endl;
			cout<<"|Exam Hall Entry Timing:12:35hrs.|Group A 14:00to16:00hrs|Exam Hall Entry Timing:16:00hrs|Group A 16:15to18:15hrs |"<<endl;
			cout<<"|_________________________________________________________________________________________________________________|"<<endl;
			cout<<"|S.No| Day/Date |      Subjects       |                   |          |   Subjects          |                      |"<<endl;
			cout<<"|____|__________|_____________________|___________________|__________|_____________________|______________________|"<<endl;
			cout<<"|    |          |OOP CS-2             |                   |          |Assembly Lang. CS-5  |                      |"<<endl;
			cout<<"| 01.|Monday    |Operating System CS-4|    Paper Timing   |  Break   |Visual Prog. CS-6    |     Paper Timing     |"<<endl;
			cout<<"|    |08-04-2019|Professional P. CS-8 | 12:50 to 14:50hrs |          |(HRM) CS-7           |  15:15 to 17:15hrs   |"<<endl;
			cout<<"|    |          |DLD CE-2             |                   |          |Signal System CSE-4  |                      |"<<endl;
			cout<<"|    |          |DataBase MS CE-6     |                   |          |                     |                      |"<<endl;
			cout<<"|____|__________|_____________________|___________________|__________|_____________________|______________________|"<<endl;
			cout<<"|    |          |DLD CS-3             |                   |          |Discrete Struct. CS-2|                      |"<<endl;
			cout<<"| 02.|Tuesday   |Networking CS-5      |    Paper Timing   |  Break   |Database System CS-4 |     Paper Timing     |"<<endl;
			cout<<"|    |09-04-2019|Informatiom S CS-6   | 12:50 to 14:50hrs |          |Digital Comm. CE-8   |  15:15 to 17:15hrs   |"<<endl;
			cout<<"|    |          |Information S CS-8   |                   |          |                     |                      |"<<endl;
			cout<<"|____|__________|_____________________|___________________|__________|_____________________|______________________|"<<endl;
			cout<<"|    |          |Num Computing CS-4   |                   |          |Technical Writ. CS-2 |                      |"<<endl;
			cout<<"| 03.|Wednessday|Automata CS-5        |    Paper Timing   |  Break   |Finance Manage. CS-3 |     Paper Timing     |"<<endl;
			cout<<"|    |10-04-2019|Artficial I(AI) CS-7 | 12:50 to 14:50hrs |          |Analysis Algo CS-6   |  15:15 to 17:15hrs   |"<<endl;
			cout<<"|    |          |Islamiat CE-2        |                   |          |Data Struct. CE-4    |                      |"<<endl;
			cout<<"|    |          |Pak Study CE-4       |                   |          |Professional E CE-8  |                      |"<<endl;
			cout<<"|____|__________|_____________________|___________________|__________|_____________________|______________________|"<<endl;
			cout<<"|    |          |English 3 CS-3       |                   |          |Introduction SE CS-4 |                      |"<<endl;
			cout<<"| 04.|Thrusday  |(HCI) CS-6           |    Paper Timing   |  Break   |Marketing CS-5       |     Paper Timing     |"<<endl;
			cout<<"|    |11-04-2019|(HCI) CS-7           | 12:50 to 14:50hrs |          |(Micro. SA) CE-4     |  15:15 to 17:15hrs   |"<<endl;
			cout<<"|    |          |Computing Pro. CE-2  |                   |          |(ATICE) CE-6         |                      |"<<endl;
			cout<<"|____|__________|_____________________|___________________|__________|_____________________|______________________|"<<endl;
			cout<<"|    |          |Data Structure CS-3  |                   |          |Isl/Pak Study CS-2   |                      |"<<endl;
			cout<<"| 05.|Friday    |(GIS) CS-5           |    Paper Timing   |  Break   |Computer Archi CS-4  |     Paper Timing     |"<<endl;
			cout<<"|    |12-04-2019|Compiler Comm. CS-6  | 14:00 to 16:00hrs |          |Numerical Method CS-7|  16:15 to 18:15hrs   |"<<endl;
			cout<<"|    |          |Circuit Analysis CE-2|                   |          |Discrete Struct. CE-4|                      |"<<endl;
			cout<<"|    |          |Network M CE-6       |                   |          |E Leadership CE-8    |                      |"<<endl;
			cout<<"|____|__________|_____________________|___________________|__________|_____________________|______________________|"<<endl;
		}
		void Final_Term_DateSheet()
		{
			cout<<" _________________________________________________________________________________________________________________"<<endl;
			cout<<"|                                          Group wise Date Sheet Mid Term                                         |"<<endl;
			cout<<"|_________________________________________________________________________________________________________________|"<<endl;
			cout<<"|             Group A            |      Paper Timing     |           Group B             |          Paper Timing  |"<<endl;
			cout<<"|Exam Hall Entry Timing:12:35hrs.|Group A 12:50to14:50hrs|Exam Hall Entry Timing:15:00hrs|Group A 15:15to17:15hrs |"<<endl;
			cout<<"|Exam Hall Entry Timing:12:35hrs.|Group A 14:00to16:00hrs|Exam Hall Entry Timing:16:00hrs|Group A 16:15to18:15hrs |"<<endl;
			cout<<"|_________________________________________________________________________________________________________________|"<<endl;
			cout<<"|S.No| Day/Date |      Subjects       |                   |          |   Subjects          |                      |"<<endl;
			cout<<"|____|__________|_____________________|___________________|__________|_____________________|______________________|"<<endl;
			cout<<"|    |          |OOP CS-2             |                   |          |Assembly Lang. CS-5  |                      |"<<endl;
			cout<<"| 01.|Monday    |Operating System CS-4|    Paper Timing   |  Break   |Visual Prog. CS-6    |     Paper Timing     |"<<endl;
			cout<<"|    |16-06-2019|Professional P. CS-8 | 12:50 to 14:50hrs |          |(HRM) CS-7           |  15:15 to 17:15hrs   |"<<endl;
			cout<<"|    |          |DLD CE-2             |                   |          |Signal System CSE-4  |                      |"<<endl;
			cout<<"|    |          |DataBase MS CE-6     |                   |          |                     |                      |"<<endl;
			cout<<"|____|__________|_____________________|___________________|__________|_____________________|______________________|"<<endl;
			cout<<"|    |          |DLD CS-3             |                   |          |Discrete Struct. CS-2|                      |"<<endl;
			cout<<"| 03.|Wednessday|Networking CS-5      |    Paper Timing   |  Break   |Database System CS-4 |     Paper Timing     |"<<endl;
			cout<<"|    |18-06-2019|Informatiom S CS-6   | 12:50 to 14:50hrs |          |Digital Comm. CE-8   |  15:15 to 17:15hrs   |"<<endl;
			cout<<"|    |          |Information S CS-8   |                   |          |                     |                      |"<<endl;
			cout<<"|____|__________|_____________________|___________________|__________|_____________________|______________________|"<<endl;
			cout<<"|    |          |Num Computing CS-4   |                   |          |Technical Writ. CS-2 |                      |"<<endl;
			cout<<"| 05.|Friday    |Automata CS-5        |    Paper Timing   |  Break   |Finance Manage. CS-3 |     Paper Timing     |"<<endl;
			cout<<"|    |20-06-2019|Artficial I(AI) CS-7 | 12:50 to 14:50hrs |          |Analysis Algo CS-6   |  15:15 to 17:15hrs   |"<<endl;
			cout<<"|    |          |Islamiat CE-2        |                   |          |Data Struct. CE-4    |                      |"<<endl;
			cout<<"|    |          |Pak Study CE-4       |                   |          |Professional E CE-8  |                      |"<<endl;
			cout<<"|____|__________|_____________________|___________________|__________|_____________________|______________________|"<<endl;
			cout<<"|    |          |English 3 CS-3       |                   |          |Introduction SE CS-4 |                      |"<<endl;
			cout<<"| 04.|Tuesday   |(HCI) CS-6           |    Paper Timing   |  Break   |Marketing CS-5       |     Paper Timing     |"<<endl;
			cout<<"|    |24-06-2019|(HCI) CS-7           | 12:50 to 14:50hrs |          |(Micro. SA) CE-4     |  15:15 to 17:15hrs   |"<<endl;
			cout<<"|    |          |Computing Pro. CE-2  |                   |          |(ATICE) CE-6         |                      |"<<endl;
			cout<<"|____|__________|_____________________|___________________|__________|_____________________|______________________|"<<endl;
			cout<<"|    |          |Data Structure CS-3  |                   |          |Isl/Pak Study CS-2   |                      |"<<endl;
			cout<<"| 05.|Friday    |(GIS) CS-5           |    Paper Timing   |  Break   |Computer Archi CS-4  |     Paper Timing     |"<<endl;
			cout<<"|    |27-06-2019|Compiler Comm. CS-6  | 14:00 to 16:00hrs |          |Numerical Method CS-7|  16:15 to 18:15hrs   |"<<endl;
			cout<<"|    |          |Circuit Analysis CE-2|                   |          |Discrete Struct. CE-4|                      |"<<endl;
			cout<<"|    |          |Network M CE-6       |                   |          |E Leadership CE-8    |                      |"<<endl;
			cout<<"|____|__________|_____________________|___________________|__________|_____________________|______________________|"<<endl;
		}
		void Display_ExaminerInformation()
		{
		cout<<"Name of Examiner is 	:"<<GetName_of_Person()<<endl;
		cout<<"CNIC No of Examiner is :"<<GetCNIC_of_Ex()<<endl;
		cout<<"Address of Examineris :"<<GetAddress_of_Perosn()<<endl;
		cout<<"Date of birth of Examiner is :"<<GetDateOfBirth_of_Person()<<endl;
		cout<<"Blood Group of Examiner is :"<<GetBloodGroup_of_Person()<<endl;
		cout<<"Monthly Pay  of Examiner is :"<<GetMonthly_Pay()<<endl;
		}
};
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //                                  Definition of the Function and these are not Member function                           //
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Login_Function()
{ 	string FirstName,SecondName;
	char pswd[100],password[9]="12345678",ch;
    int count=0,i,flag=0;
    for(;;)
    {
	cout<<"                            ================================================================\n";  
    cout<<"                            |             Enter user name and password for login           |\n";
	cout<<"                            ================================================================\n";
	{
	i=0;
	cout<<"\t\t\t\t\t\tFirst Name :";
    cin>>FirstName;
    cout<<"\t\t\t\t\t\tLast Name  :";
    cin>>SecondName;
    cout<<"\t\t\t\t\t\tPassword   :";
    while(1)
    {
	ch=getch();
	if(ch==ENTERKEY)
	{
	   pswd[i]='\0';
	   if(i>=6)
	   {
	   break;
		}
		}
		else if(ch==BKSP)
		{
			if(i>0)
			{
				i--;
				cout<<"\b \b";
			}
		}
		else if(ch==TAB||ch==SPACE)
		{
			continue;
		}
		else
		{
			pswd[i]=ch;
			cout<<"*";
			i++;
		}
	}
	for(int j=0;j<i;j++)
	{
		if(i<=8)
		{	
		if(pswd[j]==password[j])
		{
			count++;
		}
	    }
	}
	if((FirstName=="Muhammad"||FirstName=="Zahid")&&(SecondName=="Waqar"||SecondName=="Ali"||SecondName=="Usama")&&count==8)
	{
		if(FirstName=="Zahid")
		{
			return FirstName;
		}
		else
		{
			return SecondName;
		}
		break;
		system("cls");
		flag=1;	
	}
	else
	{
		if((flag==0)&&(count!=8))
		{
		cout<<"\n\t\t\t\t\t\tSorry incorrect username and password : Try again"<<endl;
	
		}
		else if(count==8)
		{
		cout<<"\n\t\t\t\t\t\tSorry incorrect username : Try again"<<endl;
	
	    }
	    else if(count!=8)
	    {
		
	    cout<<"\n\t\t\t\t\t\tSorry incorrect password :Try again"<<endl;
	
		}
		
	    }
	
       }
	    count=0;
		cout<<"\t\t\t\t\t\tPress any key to continue...........";
		getch();
		system("cls");
  }  
}
class Admission
{
	private:
		Linkedlist *tem,*head1,*last1;
		Linkedlist *head2,*last2;
		int ch;
		int flag,faag;
	public:
		Admission()
		{
			head1=NULL;
			last1=NULL;
			head2=NULL;
			last2=NULL;
			flag=0;
			faag=0;
		}
		void InsertionCS()
		{
		  	system("cls");
			ch=1;
			while(ch)
			{
				cout<<"       Dr.A.Q Khan Institute Of Computer Science And Information Technology\n";
				cout<<"\t\t\t\tApplication Form\n";
				tem=new Linkedlist;
				cout<<"__________________________________________________________________________________\n";
				cout<<"Enter Name of Candidate :";
				cin.ignore();
				cin.getline(tem->name,150);
				for(int i=0;tem->name[i]!='\0';i++)   //validation for name
            	{
                    		if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
                    		{
	           	 				cout<<"Sorry You Entered invalid name \n";
                   	 			cout<<"Enter valid name :";
                    			cin.getline(tem->name,150);
                    			i=0;
                    		}
                }  
				cout<<"Enter CNIC of Candidate :";
				cin>>tem->cnic;
				for(int i=0;i<tem->cnic.size();i++)   //validation for CNIC
			   		{
				  		 if(!(isdigit(tem->cnic[i])||(tem->cnic[i]=='-')))
				 				 	{
				    					cout<<"Sorry You Entered invalid CNIC \n";
				    					cout<<"Enter valid CNIC :";
				    					cin>>tem->cnic;
			    						i=0;							
				 			 		}
			    	} 
				cout<<"Enter Father name of Candidate :";
				cin>>tem->Fname;
				for(int i=0;tem->Fname[i]!='\0';i++)   //validation for name
            	{
                    		if(!(isalpha(tem->Fname[i])||tem->Fname[i]=='.'||isspace(tem->Fname[i])))
                    		{
	           	 				cout<<"Sorry You Entered invalid name \n";
                   	 			cout<<"Enter valid name :";
                    			cin.getline(tem->Fname,150);
                    			i=0;
                    		}
                } 
				cout<<"Enter Total Marks in Fsc/ICS/A-Level :";
				cin>>tem->fsc;
	       		while(cin.fail())
	      		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid Total Marks \n";
							cout<<"Enter  valid Total Marks :";
							cin>>tem->fsc;
				}
				cout<<"Enter Marks obtained in Fsc/ICS/A-Level :";
				cin>>tem->No;
	       		while(cin.fail())
	           	{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid Obtained Marks \n";
							cout<<"Enter  valid Obtained Marks :";
							cin>>tem->No;
				}
				cout<<"Enter Total Marks in Matric :";
				cin>>tem->T_Marks;
	       		while(cin.fail())
	       		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid Total Marks \n";
							cout<<"Enter  valid Total Marks:";
							cin>>tem->T_Marks;
				}
				cout<<"Enter Marks obtained in Matric :";
				cin>>tem->O_Marks;
					            		while(cin.fail())
	            		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid Obtained Marks \n";
							cout<<"Enter  valid Obtained Marks :";
							cin>>tem->O_Marks;
						}
				cout<<"From where is Candidate Domicile :";
				cin>>tem->dom;
				cout<<"Enter Total Marks in NTS :";
				cin>>tem->present;
	       		while(cin.fail())
	            		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid Total Marks \n";
							cout<<"Enter  valid Total Marks :";
							cin>>tem->present;
						}
				cout<<"Enter Marks obtained in NTS Test ";
				cin>>tem->nts;
	       		while(cin.fail())
	           	{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid Obtained Marks \n";
							cout<<"Enter  valid Obtained Marks :";
							cin>>tem->nts;
				}
				tem->T_Mt=(tem->O_Marks/tem->T_Marks)*1100*0.10;
				tem->T_Fsc=(tem->No/tem->fsc)*1100*0.40;
				tem->T_NTS=(tem->nts/tem->present)*0.50*1100;
				tem->Agrgte=(tem->T_Mt+tem->T_Fsc+tem->T_NTS);
				tem->P_Agrgte=(tem->Agrgte*100)/1100;
				if(tem->P_Agrgte>=70)
				{
					if(last1==NULL)
					{
						last1=head1=tem;
					}
					else
					{
						last1->ptr=tem;
						last1=tem;
					}
					cout<<"__________________________________________________________________________________\n";
					cout<<"\t\t\tThank You Form Submitted\n";
					cout<<"__________________________________________________________________________________\n";
					flag=1;
				}
				else 
				{
					cout<<"______________________________________________________________________________\n";
					cout<<"\t\t\tSorry this Candidate has minimun Aggregate \n";
					cout<<"______________________________________________________________________________\n";
				}
				cout<<"Do you want to Insert another candidate (1/0) :";
				cin>>ch;
	       		while(cin.fail())
	       		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid choice \n";
							cout<<"Enter  valid choice :";
							cin>>ch;
				}
				system("cls");
			}
		}
	void bubbleSort(Linkedlist *start) 
	{ 
    int swapped, i; 
     Linkedlist *ptr1; 
     Linkedlist *lptr = NULL; 
    if (start == NULL) 
       {
	    return;
		}
    do
    { 
        swapped = 0; 
        ptr1 = start; 
        while (ptr1->ptr != lptr) 
        { 
            if (ptr1->P_Agrgte <ptr1->ptr->P_Agrgte) 
            {  
                swap(ptr1, ptr1->ptr); 
                swapped = 1;
            } 
            ptr1 = ptr1->ptr; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
	} 
/* function to swap data of two nodes a and b*/
void swap(Linkedlist *a, Linkedlist *b) 
{ 
  	int temp = a->P_Agrgte; 
    a->P_Agrgte = b->P_Agrgte; 
    b->P_Agrgte = temp;
	char temp1[100]; 
    strcpy(temp1,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,temp1);
    //swap cnic
    string temp2;
    temp2=a->cnic;
    a->cnic=b->cnic;
    b->cnic=temp2; 
}
void DisplayDataCS()
{
			system("cls");
			if(flag)
			{
				cout<<"           Dr.A.Q Khan Institute Of Computer Science And Information Technology\n";
				cout<<"\t\t List of Selected Candidate in BSCS Fall Semester\n\n";
				bubbleSort(head1); 
				tem=head1;
				last1->ptr=NULL;
				cout<<"           _____________________________________________________________________\n";
				cout<<"\t\tCNIC\t\tName\t\tAggregate\n";
				cout<<"           _____________________________________________________________________\n";
				while(tem!=NULL)
				{
					cout<<"\t\t"<<tem->cnic<<"\t\t"<<tem->name<<"\t\t"<<tem->P_Agrgte<<"%"<<endl;
					tem=tem->ptr;
				cout<<"           _____________________________________________________________________\n";	
				}
				cout<<"\t\t\tSelected Candidate Must Submit Fee in Time \n";
				cout<<"           _____________________________________________________________________\n";
				getch();
			}
			else
			{
				cout<<"\n\n\n\n\n\t\t\t\tSorry Record is Not Saved";
				getch();	
			}
		}
		void InsertionCE()
		{
		  	system("cls");
			ch=1;
			while(ch)
			{
				cout<<"       Dr.A.Q Khan Institute Of Computer Science And Information Technology\n";
				cout<<"\t\t\t\tApplication Form\n";
				tem=new Linkedlist;
				cout<<"__________________________________________________________________________________\n";
				cout<<"Enter Name of Candidate :";
				cin.ignore();
				cin.getline(tem->name,150);
				for(int i=0;tem->name[i]!='\0';i++)   //validation for name
            	{
                    		if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
                    		{
	           	 				cout<<"Sorry You Entered invalid name \n";
                   	 			cout<<"Enter valid name :";
                    			cin.getline(tem->name,150);
                    			i=0;
                    		}
                }  
				cout<<"Enter CNIC of Candidate :";
				cin>>tem->cnic;
				for(int i=0;i<tem->cnic.size();i++)   //validation for CNIC
			   		{
				  		 if(!(isdigit(tem->cnic[i])||(tem->cnic[i]=='-')))
				 				 	{
				    					cout<<"Sorry You Entered invalid CNIC \n";
				    					cout<<"Enter valid CNIC :";
				    					cin>>tem->cnic;
			    						i=0;							
				 			 		}
			    	} 
				cout<<"Enter Father name of Candidate :";
				cin>>tem->Fname;
				for(int i=0;tem->Fname[i]!='\0';i++)   //validation for name
            	{
                    		if(!(isalpha(tem->Fname[i])||tem->Fname[i]=='.'||isspace(tem->Fname[i])))
                    		{
	           	 				cout<<"Sorry You Entered invalid name \n";
                   	 			cout<<"Enter valid name :";
                    			cin.getline(tem->Fname,150);
                    			i=0;
                    		}
                } 
				cout<<"Enter Total Marks in Fsc/ICS/A-Level :";
				cin>>tem->fsc;
	       		while(cin.fail())
	      		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid Total Marks \n";
							cout<<"Enter  valid Total Marks :";
							cin>>tem->fsc;
				}
				cout<<"Enter Marks obtained in Fsc/ICS/A-Level :";
				cin>>tem->No;
	       		while(cin.fail())
	           	{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid Obtained Marks \n";
							cout<<"Enter  valid Obtained Marks :";
							cin>>tem->No;
				}
				cout<<"Enter Total Marks in Matric :";
				cin>>tem->T_Marks;
	       		while(cin.fail())
	       		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid Total Marks \n";
							cout<<"Enter  valid Total Marks:";
							cin>>tem->T_Marks;
				}
				cout<<"Enter Marks obtained in Matric :";
				cin>>tem->O_Marks;
	            		while(cin.fail())
	            		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid Obtained Marks \n";
							cout<<"Enter  valid Obtained Marks :";
							cin>>tem->O_Marks;
						}
				cout<<"From where is Candidate Domicile :";
				cin>>tem->dom;
				cout<<"Enter Total Marks in NTS :";
				cin>>tem->present;
	       		while(cin.fail())
	            		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid Total Marks \n";
							cout<<"Enter  valid Total Marks :";
							cin>>tem->present;
						}
				cout<<"Enter Marks obtained in NTS Test ";
				cin>>tem->nts;
	       		while(cin.fail())
	           	{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid Obtained Marks \n";
							cout<<"Enter  valid Obtained Marks :";
							cin>>tem->nts;
				}
				tem->T_Mt=(tem->O_Marks/tem->T_Marks)*1100*0.10;
				tem->T_Fsc=(tem->No/tem->fsc)*1100*0.40;
				tem->T_NTS=(tem->nts/tem->present)*0.50*1100;
				tem->Agrgte=(tem->T_Mt+tem->T_Fsc+tem->T_NTS);
				tem->P_Agrgte=(tem->Agrgte*100)/1100;
				if(tem->P_Agrgte>=70)
				{
					if(last2==NULL)
					{
						last2=head2=tem;
					}
					else
					{
						last2->ptr=tem;
						last2=tem;
					}
					cout<<"__________________________________________________________________________________\n";
					cout<<"\t\t\tThank You Form Submitted\n";
					cout<<"__________________________________________________________________________________\n";
					faag=1;
				}
				else 
				{
					cout<<"______________________________________________________________________________\n";
					cout<<"\t\t\tSorry this Candidate has minimun Aggregate \n";
					cout<<"______________________________________________________________________________\n";
				}
				cout<<"Do you want to Insert another candidate (1/0) :";
				cin>>ch;
	       		while(cin.fail())
	       		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid choice \n";
							cout<<"Enter  valid choice :";
							cin>>ch;
				}
				system("cls");
			}
		}
		void DisplayDataCE()
		{
			system("cls");
			if(faag)
			{
				cout<<"           Dr.A.Q Khan Institute Of Computer Science And Information Technology\n";
				cout<<"\t\t List of Selected Candidate in BSCE Fall Semester\n\n";
				bubbleSort(head2); 
				tem=head2;
				last2->ptr=NULL;
				cout<<"           _____________________________________________________________________\n";
				cout<<"\t\tCNIC\t\tName\t\tAggregate\n";
				cout<<"           _____________________________________________________________________\n";
				while(tem!=NULL)
				{
					cout<<"\t\t"<<tem->cnic<<"\t\t"<<tem->name<<"\t\t"<<tem->P_Agrgte<<"%"<<endl;
					tem=tem->ptr;
				cout<<"           _____________________________________________________________________\n";	
				}
				cout<<"           _____________________________________________________________________\n";
				cout<<"\t\t\tSelected Candidate Must Submit Fee in Time \n";
				cout<<"           _____________________________________________________________________\n";
				getch();
			}
			else
			{
				cout<<"\n\n\n\n\n\t\t\t\tSorry Record is Not Saved";
				getch();	
			}
		}
};
class FeeSub
{
	private:
		Queue *front,*rear,*tem;
		int count;
	public:
		FeeSub()
		{
			front=rear=NULL;
			count=0;
		}
		int IsEmpty()
		{
			if(count)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		void EnQueue()
		{
		   	int 	Ch=1;
			while(Ch)
			{
				tem=new Queue;
				cout<<"Enter Name of student :";
				cin>>tem->name;
				for(int i=0;tem->name[i]!='\0';i++)   //validation for name
            	{
                    		if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
                    		{
	           	 				cout<<"Sorry You Entered invalid name \n";
                   	 			cout<<"Enter valid name :";
                    			cin.getline(tem->name,150);
                    			i=0;
                    		}
                }  					
				cout<<"Enter Registration of Student :";
				cin>>tem->Reg_No;
				cout<<"Enter Program of Student :";
				cin>>tem->program;
				cout<<"Enter Semester of Student :";
				cin>>tem->semester;
				while(cin.fail())
	       		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered Invalid Semester Number \n";
							cout<<"Enter  valid Semester Number:";
							cin>>tem->semester;
				}
				cout<<"Enter amount of Fee you want to submit :";
				cin>>tem->amount;
				while(cin.fail())
	       		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered Invalid amount \n";
							cout<<"Enter  valid amount:";
							cin>>tem->amount;
				}	
				if(IsEmpty())
				{
					rear=front=tem;
				}
				else
				{
					rear->next=tem;
					rear=tem;
				}
				cout<<"Fee Submitted Successfully\n\n";
				cout<<"Do you want to Enqueue (1/0) :";
				cin>>Ch;
				while(cin.fail())
	       		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered Choice \n";
							cout<<"Enter  valid Choice:";
							cin>>Ch;
				}
				count++;
			}
		}
		void DeQueue()
		{
			system("cls");
			if(IsEmpty())
			{
				cout<<"\n\n\n\n\t\t\t\tQueue is Empty\n";
				getch();
			}
			else
			{
				tem=front->next;
				delete front;
				front=tem;
				count--;
				cout<<"\n\n\n\n\t\t\t\tData is  DeQueue Successfully \n";
				getch();
			}
		}
		void Display()
		{
			tem=front;
			if(count==0)
			{
				cout<<"\n\n\n\n\t\t\t\tQueue is Empty \n";
				getch();
			}
			else
			{
			 	cout<<"Dr.A.Q Khan Institute Of Computer Science And Information Technology\n";
				cout<<"\t\t\tList Of Submitted Fee\n\n";
				cout<<"Reg.No\t\tName\t\tSemester\t\tAmount\n";
				rear->next=NULL;
				while(tem!=NULL)
				{
			 		cout<<tem->Reg_No<<"\t\t"<<tem->name<<"\t\t"<<tem->semester<<"\t\t\t"<<tem->amount<<endl;
				  	tem=tem->next;	
				}
	    		getch();
			}
		}
};
void gotoxy(int x,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void Shape()
{
	cout<<"\n\n\n";
	cout<<"\t\t\t*********************************************************************************\n";
	cout<<"\t\t\t*********************************************************************************\n";   
    cout<<"\t\t\t||                          KICSIT MANAGEMENT SYSTEM              	       ||\n";
	cout<<"\t\t\t*********************************************************************************\n";
	cout<<"\t\t\t*********************************************************************************\n";
}
void Main_Menu()
{
	cout<<"                      ================================================================\n";
	cout<<"                      |                          HOME SCREEN                         |\n";
	cout<<"                      ================================================================\n";
	cout<<"                      |            1.      KICSIT Information                        |\n";
	cout<<"                      |            2.      Admin   Block                             |\n";
	cout<<"                      |            3.      Department Information                    |\n";
	cout<<"                      |            4.      Student    Information                    |\n";
	cout<<"                      |            5.      Faculty    Information                    |\n";
	cout<<"                      |            6.      Exam system                               |\n";
	cout<<"                      |            20.     Exit                                      |\n";
	cout<<"                      ----------------------------------------------------------------\n";
}
void ExamMenu()
{
    cout<<"                   ================================================================\n";
	cout<<"                   |                            SUB MENU                          |\n";
	cout<<"                   ================================================================\n";
	cout<<"                   |            1.      Examiner Information                      |\n";
	cout<<"                   |            2.      Date Sheet                                |\n";
	cout<<"                   |            3.      Display Final Result                      |\n";
	cout<<"                   |            4.      GPA Calculator                            |\n";	
	cout<<"                   |            5.      Go Back to Main Menu                      |\n";
    cout<<"                   ----------------------------------------------------------------\n";
}
void DatesheetMenu()
{
    cout<<"                   ================================================================\n";
	cout<<"                   |                            SUB MENU                          |\n";
	cout<<"                   ================================================================\n";
	cout<<"                   |            1.      Date Sheet for Mids                       |\n";
	cout<<"                   |            2.      Date Sheet for Finals                     |\n";
	cout<<"                   |            3.      Go Back to Main Menu                      |\n";
    cout<<"                   ----------------------------------------------------------------\n";
}
void SemesterSubMenu()
{
    cout<<"                   ================================================================\n";
	cout<<"                   |                            SUB MENU                          |\n";
	cout<<"                   ================================================================\n";
	cout<<"                   |            1.      CS Information                            |\n";
	cout<<"                   |            2.      CE Information                            |\n";
	cout<<"                   |            3.      Go Back to Main Menu                      |\n";
    cout<<"                   ----------------------------------------------------------------\n";
}
void Sub_Menu()
{
	cout<<"                   ================================================================\n";
	cout<<"                   |                            SUB MENU                          |\n";
	cout<<"                   ================================================================\n";
	cout<<"                   |            1.      Create New Entry                          |\n";
	cout<<"                   |            2.      Find and Display Information              |\n";
	cout<<"                   |            3.      Display All Information                   |\n";
	cout<<"                   |            4.      Go Back to Main Menu                      |\n";
	cout<<"                   |            5.      Delete the record                         |\n";
    cout<<"                   |            6.      Updation Information                      |\n";
	cout<<"                   ----------------------------------------------------------------\n";
}
void SubLec()
{
	cout<<"                   ================================================================\n";
	cout<<"                   |                            SUB MENU                          |\n";
	cout<<"                   ================================================================\n";
	cout<<"                   |            1.      Create New Entry                          |\n";
	cout<<"                   |            2.      Find and Display Information              |\n";
	cout<<"                   |            3.      Display All Information                   |\n";
	cout<<"                   |            4.      Go Back to Main Menu                      |\n";
	cout<<"                   |            5.      Delete the record                         |\n";
	cout<<"                   ----------------------------------------------------------------\n";
}
void Astumenu()
{
	cout<<"                   ================================================================\n";
	cout<<"                   |                            SUB MENU                          |\n";
	cout<<"                   ================================================================\n";
	cout<<"                   |            1.      Create New Entry                          |\n";
	cout<<"                   |            2.      Find and Display Information              |\n";
	cout<<"                   |            3.      Delete the record                         |\n";
	cout<<"                   |            4.      Display All Student Information           |\n";
	cout<<"                   |            6.      Daily Basis Attendance                    |\n";
	cout<<"                   |            7.      Go Back to Main Menu                      |\n";
    cout<<"                   ----------------------------------------------------------------\n";
}
void Sub_ResultMenu()
{
    cout<<"                   ================================================================\n";
	cout<<"                   |                            SUB MENU                          |\n";
	cout<<"                   ================================================================\n";
	cout<<"                   |            1.      Create New Entry                          |\n";
	cout<<"                   |            2.      Display Result                            |\n";
	cout<<"                   |            3.      Go Back to Main Menu                      |\n";
    cout<<"                   ----------------------------------------------------------------\n";
}
void Sub_Menu_Uni()
{
	cout<<"                   ================================================================\n";
	cout<<"                   |                            SUB MENU                          |\n";
	cout<<"                   ================================================================\n";
	cout<<"                   |            1.      Add KICSIT Information                    |\n";
	cout<<"                   |            2.      Display Information                       |\n";
	cout<<"                   |            3.      Update Information                        |\n";
	cout<<"                   |            4.      Go Back to Main Menu                      |\n";
    cout<<"                   ----------------------------------------------------------------\n";
}
void Department_SubMenu()
{
	cout<<"                   =================================================================\n";
	cout<<"                   |                            SUB MENU                           |\n";
	cout<<"                   =================================================================\n";
	cout<<"                   |                    1.Set Department Information               |\n";
	cout<<"                   |                    2.Find and display Information             |\n";
	cout<<"                   |                    3.Display All information                  |\n";
	cout<<"                   |                    4.Go to Main Menu                          |\n";
	cout<<"                   |                    5:Delete department                        |\n";
	cout<<"                   |                    6.Update Information                       |\n";
	cout<<"                   -----------------------------------------------------------------\n";
}
void Admin_SubMenu()
{
	cout<<"                   =================================================================\n";
	cout<<"                   |                           SUB MENU                           |\n";
	cout<<"                   =================================================================\n";
	cout<<"                   |                    1.Administrator                            |\n";
	cout<<"                   |                    2.New Admission                            |\n";
	cout<<"                   |                    3.Accountant                               |\n";
	cout<<"                   |                    4.Go to Main Menu                          |\n";
	cout<<"                   -----------------------------------------------------------------\n";
}
void NewAdmission()
{
	cout<<"                   =================================================================\n";
	cout<<"                   |                            SUB MENU                           |\n";
	cout<<"                   =================================================================\n";
	cout<<"                   |                    1.Apply Now                                |\n";
	cout<<"                   |                    2.Admission Done                           |\n";
	cout<<"                   |                    3.Go to Main Menu                          |\n";
	cout<<"                   -----------------------------------------------------------------\n";
	
}
void AccountantMenu()
{
	cout<<"                   =================================================================\n";
	cout<<"                   |                            SUB MENU                           |\n";
	cout<<"                   =================================================================\n";
	cout<<"                   |                    1.Accountant Information                   |\n";
	cout<<"                   |                    2.Display Information                      |\n";
	cout<<"                   |                    3.Fee Submission                           |\n";
	cout<<"                   |                    4.Delete Fee Information                   |\n";
	cout<<"                   |                    5.Submited Fee                             |\n";
	cout<<"                   |                    6.Update Accountant Information            |\n";
	cout<<"                   |                    7.Go to back                               |\n";
	cout<<"                   -----------------------------------------------------------------\n";	
}
void aadmin()
{
	cout<<"                   =================================================================\n";
	cout<<"                   |                            SUB MENU                           |\n";
	cout<<"                   =================================================================\n";
	cout<<"                   |                    1.Set Admin Information                    |\n";
	cout<<"                   |                    2.Display Information                      |\n";
	cout<<"                   |                    3.Fee Structure                            |\n";
	cout<<"                   |                    4.Update Admin Information                 |\n";
	cout<<"                   |                    5.Go to Main Menu                          |\n";
	cout<<"                   -----------------------------------------------------------------\n";
}

void Sub_GPA()
{
	cout<<"                   ================================================================\n";
	cout<<"                   |                            SUB MENU                          |\n";
	cout<<"                   ================================================================\n";
	cout<<"                   |            1.     Calculate SGPA                             |\n";
	cout<<"                   |            2.     Calculate CGPA                             |\n";
	cout<<"                   |            3.     Go Back                                    |\n";
    cout<<"                   ----------------------------------------------------------------\n";
}
void StuSubMenu()
{
	cout<<"                   ================================================================\n";
	cout<<"                   |                            SUB MENU                          |\n";
	cout<<"                   ================================================================\n";
	cout<<"                   |            1.     Admin                                      |\n";
	cout<<"                   |            2.     Student Information                        |\n";
	cout<<"                   |            3.     Go Back                                    |\n";
    cout<<"                   ----------------------------------------------------------------\n";
}
void ExamSubMenu()
{
	cout<<"                   ================================================================\n";
	cout<<"                   |                            SUB MENU                          |\n";
	cout<<"                   ================================================================\n";
	cout<<"                   |            1.     Add Examiner Information                   |\n";
	cout<<"                   |            2.     Display Information                        |\n";
	cout<<"                   |            3.     Update Information                         |\n";
	cout<<"                   |            4.     Go Back                                    |\n";
    cout<<"                   ----------------------------------------------------------------\n";
}
void SemesterCSMenu()
{
	cout<<"                   =================================================================\n";
	cout<<"                   |                            SUB MENU                           |\n";
	cout<<"                   =================================================================\n";
	cout<<"                   |                    1.CS1 Information                          |\n";
	cout<<"                   |                    2.CS2 Information                          |\n";
	cout<<"                   |                    3.CS3 Information                          |\n";
	cout<<"                   |                    4.CS4 Information                          |\n";
	cout<<"                   |                    5.CS5 Information                          |\n";
	cout<<"                   |                    6.CS6 Information                          |\n";
	cout<<"                   |                    7.CS7 Information                          |\n";
	cout<<"                   |                    8.CS8 Information                          |\n";
	cout<<"                   |                    9.Exit                                     |\n";
	cout<<"                   -----------------------------------------------------------------\n";	
}
void SemesterCEMenu()
{
	cout<<"                   =================================================================\n";
	cout<<"                   |                            SUB MENU                           |\n";
	cout<<"                   ====================================================i=============\n";
	cout<<"                   |                    1.CE1 Information                          |\n";
	cout<<"                   |                    2.CE2 Information                          |\n";
	cout<<"                   |                    3.CE3 Information                          |\n";
	cout<<"                   |                    4.CE4 Information                          |\n";
	cout<<"                   |                    5.CE5 Information                          |\n";
	cout<<"                   |                    6.CE6 Information                          |\n";
	cout<<"                   |                    7.CE7 Information                          |\n";
	cout<<"                   |                    8.CE8 Information                          |\n";
	cout<<"                   |                    9.Exit                                     |\n";
	cout<<"                   -----------------------------------------------------------------\n";	
}
void ProfileMenu()
{
	cout<<"                   ================================================================\n";
	cout<<"                   |                            SUB MENU                          |\n";
	cout<<"                   ================================================================\n";
	cout<<"                   |            1.     Personal profile                           |\n";
	cout<<"                   |            2.     Course profile                             |\n";
	cout<<"                   |            3.     View Attendance Overall                    |\n";
	cout<<"                   |            4.     View GPA                                   |\n";
	cout<<"                   |            5.     View Attendance Daily Basis                |\n";
	cout<<"                   |            6.     Go Back                                    |\n";
    cout<<"                   ----------------------------------------------------------------\n";
}
void Start()
{
	cout<<"                   ================================================================\n";
	cout<<"                   |                       MAIN MENU                              |\n";
	cout<<"                   ================================================================\n";
	cout<<"                   |            1.     Home Screen                                |\n";
	cout<<"                   |            2.     Help                                       |\n";
	cout<<"                   |            3.     Exit                                       |\n";
    cout<<"                   ----------------------------------------------------------------\n";
}
void Help()
{
	cout<<"\t\t\tHelp for Using this Software\n";
	cout<<"-----------------------------------------------------------------------\n";
	cout<<"1. Using this software you can maintain data.\n";
	cout<<"2. After entered or displayed information Press any key to go back.\n";
	cout<<"3. Press 20 key to close this software.\n";
	cout<<"4. This software is usefull for KICSIT\n";
	cout<<"5. This software can maintain KICSIT,Students,Faculty etc Record.\n";
	cout<<"6. This software can calculate Student result etc.\n";
	cout<<"7. This software can maintain Student Attendance.\n";
	cout<<"8. Press key 4 to jump from sub menu.\n";
	cout<<"9. Dev C++ compiler is very best for this.\n";
	cout<<"10.Use this software carefully.\n";
	cout<<"-----------------------------------------------------------------------\n";
}
void Lec()
{
	cout<<"                   ================================================================\n";
	cout<<"                   |                            SUB MENU                          |\n";
	cout<<"                   ================================================================\n";
	cout<<"                   |            1.     Other staff                                |\n";
	cout<<"                   |            2.     Lecturer                                   |\n";
	cout<<"                   |            3.     Go Back                                    |\n";
    cout<<"                   ----------------------------------------------------------------\n";
}
void LOADING()
{
	int r,q;
system("COLOR 3E");
Shape();
cout<<"\n\n\n\n\n\t\t\t\tTHIS SOFTWARE IS MADE BY :\n";
sleep(1);
cout<<"\n\n\t\t\t\tNAME           \t\t\tREGISTRATION NO\n";
sleep(1);
cout<<"\n\n\t\t\t\tMuhammad Waqar\t\t\t18S-BSCS-01\n";
sleep(1);
cout<<"\n\n\t\t\t\tShahzaib Hamza\t\t\t18S-BSCS-023\n";
sleep(1);
cout<<"\n\n\t\t\t\tMuhammad Khizar\t\t\t18S-BSCS-25\n";
sleep(1);
cout<<"\n\n\t\t\t\tAzam Ramzan\t\t\t18S-BSCS-38\n";
sleep(1);
cout<<"\n\n\t\t\t\tIrsa\t\t\t\t18S-BSCS-43\n";
sleep(1);
cout<<"\t\t\t\t\tPress any key to start........!";
getch(); 
system("cls");
system("COLOR 07");                        
Login_Function();
system("cls");
system("COLOR 4E");
cout<<"\n\t\t\t\t\t\tWELL COME TO KICSIT MANAGEMENT SYSTEM";
gotoxy(30,10);
cout<<"\t\t\tPlease wait\n";
cout<<"\t\t\t\t\t\tLoading";
for(r=0;r<=20;r++)
{
	for(q=0;q<=100000000;q++);
	{
	cout<<".";
	}
}
}
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                          Main Funtion                                                                       //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
// Here we are creating objects of different classes                
University Uni;
Student stdnt;
Faculty staff;
Department departments;
Admin admin;
GPA_Calculator gpa;
Examiner exam;
Accountant acc;
FeeSub fs;
Lecturer lec;
Admission New;
// Declaration of Pointers
Linkedlist *tem,*temm;
Linkedlist *head,*last;
Linkedlist *head1,*last1;
Linkedlist *head2,*last2;
Linkedlist *head3,*last3;
Linkedlist *head4,*last4;
Linkedlist *head5,*last5;
Linkedlist *head6,*last6;
Linkedlist *Head,*Last,*llast,*lllast,*Temm,*Temmm,*hhead,*hhhead;
Last=NULL;
//Initialization of Pointers
last=NULL,last1=NULL,last2=NULL;
Last=NULL,last3=NULL,last4=NULL,head=NULL;
head1=NULL,head2=NULL,head3=NULL;
head4=NULL,head5=NULL,last5=NULL;
head6=NULL,last6=NULL;
// Declaration of Variables           
string id;
string Reg_No;
string cnic;
//int type
int check=0,CS1=1,CE1=1,z=0;
int CS2=1,CE2=1;
int counterP,counterA;
int wrong=0,CS3=1,CE3=1;
int flag=0,CS4=1,CE4=1;
int Ch=1,kic=1,ad=1,CS5=1,CE5=1;
int main_choice,CS6=1,CE6=1;
int ch,select,CS7=1,CE7=1,a=0;
int choice_stdnt,Condition,choice_Lecturer,choice,CS8=1,CE8=1;
int T_Emp,no,f,	ex=1,ac=1,CCCHHH;
LOADING();
system("cls");//For clear data on console screen
do
{
system("cls");
system("COLOR 1f");
Start();
cout<<"Enter your choice :";
cin>>CCCHHH;
while(cin.fail())
{  
	cin.clear();
	cin.ignore(80,'\n');
	cout<<"Sorry You entered invalid choice \n";
	cout<<"Enter valid choice :";
	cin>>CCCHHH;
}
if(CCCHHH==1)
{
	system("COLOR 4f");
	do //Outter Loop
{
	system("cls");
	Main_Menu();                       //Calling Function
    cout<<"Enter your choice :";
	cin>>Condition;
    while(cin.fail())
	{  
		cin.clear();
		cin.ignore(80,'\n');
		cout<<"Sorry You entered invalid choice \n";
		cout<<"Enter valid choice :";
		cin>>Condition;
	}
	system("cls");
	//Outter loop Condition
	if(Condition==1)
	{
		flag=0;
			system("COLOR A0");
	    	do //inner loop
	    	{
				system("cls");
	       		Sub_Menu_Uni();
	        	cout<<"Enter your choice :";
	       		 cin>>choice;
	        	while(cin.fail())
				{  
					cin.clear();
					cin.ignore(80,'\n');
					cout<<"Sorry You entered invalid choice \n";
					cout<<"Enter valid choice :";
					cin>>choice;
				}
	        	if(choice==1)
	        	{
					system("cls");
					if(kic==1)
					{
						cout<<"\t\t\t\tPLEASE ENTER INFORMATION OF KICSIT\n";
						cout<<endl;
						tem=new Linkedlist;
						cout<<"-----------------------------------------------------------------------------------------------\n";
	            		cout<<"Enter Full form of KICSIT :";
	            		cin.ignore();
						cin.getline(tem->name,150);
	            		for(int i=0;tem->name[i]!='\0';i++)   //validation for name
               	 		{
                    		if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
                    		{
	           	 				cout<<"Sorry You Entered invalid name \n";
                   	 			cout<<"Enter valid name :";
                    			cin.getline(tem->name,150);
                    			i=0;
                    		}
                		}    
	            		Uni.SetName_of_Uni(tem->name);
	            		cout<<"Enter Id of KICSIT :";
	            		cin>>tem->id;
	            		Uni.SetId_of_Uni(tem->id);
	            		cout<<"Enter Total number of rooms in your KICSIT :";
	            		cin>>tem->No;
	            		while(cin.fail())
	            		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid number of rooms \n";
							cout<<"Enter  valid number of rooms :";
							cin>>tem->No;
						}
	            		Uni.SetTotal_Room(tem->No);
	            		cout<<"Enter Total number of campus of KICSIT :";
	            		cin>>tem->No;
	            		while(cin.fail())
	            		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid number of campus \n";
							cout<<"Enter  valid number of campus :";
							cin>>tem->No;
						}
	            		Uni.SetCampus(tem->No);
	            		cout<<"Enter Address of KICSIT :";
	            		cin.ignore();
	            		cin.getline(tem->address,50);
	            		Uni.SetAddress_of_Uni(tem->address);
	            		cout<<"Enter Total number of Libraries of KICSIT :";
	            		cin>>tem->No;
	            		while(cin.fail())
	            		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid number of Libraries \n";
							cout<<"Enter  valid number of Libraries :";
							cin>>tem->No;
						}
						Uni.SetTotal_Library(tem->No);
						cout<<"Enter Total number of Play Ground of KICSIT :";
	            		cin>>tem->No;
	            		while(cin.fail())
	           			{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid number of Play Ground \n";
							cout<<"Enter  valid number of Play Ground :";
							cin>>tem->No;
						}
						cout<<"------------------------------------Successfully Entered---------------------------------------\n";
						Uni.SetP_Ground(tem->No);
						getch();
	            		flag=1;
	            		kic=0;
	        		}
	        		else
	        		{	
	        			cout<<"\n\n\n\n\t\t\tSorry You cannot enter new information because information is entered \n";
	        			getch();
					}
            	}
            	else if(choice==2)
            	{
					if(flag==1)
					{
						system("cls");
						cout<<"                                                         SAVED RECORD"<<endl;
						cout<<"\t\t\t\tINFORMATION OF KICSIT \n";
						cout<<endl;
						cout<<"-----------------------------------------------------------------------------------------------\n";
						Uni.Display_Uni();
						cout<<"-----------------------------------------------------------------------------------------------\n";
						getch();
	        		}
	        		else 
	        		{
						system("cls");
						cout<<"\n\n\n\n\n\n\n\t\t\t\tSorry Record not saved \n";
						getch();		
					}
	        	}
	        	else if(choice==3)
	        	{
	        		if(flag==1)
	        		{
	        			system("cls");
	        			cout<<"\t\t\t\tPLEASE ENTER INFORMATION FOR UPDATION\n";
		        		cout<<"-----------------------------------------------------------------------------------------------\n";
						cout<<"Enter Full form of KICSIT :";
	            		cin.ignore();
						cin.getline(tem->name,150);
	            		for(int i=0;tem->name[i]!='\0';i++)   //validation for name
               	 		{
                    		if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
                    		{
	           	 				cout<<"Sorry You Entered invalid name \n";
                   	 			cout<<"Enter valid name :";
                    			cin.getline(tem->name,150);
                    			i=0;
                    		}
                		}    
	            		Uni.SetName_of_Uni(tem->name);
	            		cout<<"Enter Id of KICSIT :";
	            		cin>>tem->id;
	            		Uni.SetId_of_Uni(tem->id);
	            		cout<<"Enter Total number of rooms in your KICSIT :";
	            		cin>>tem->No;
	            		while(cin.fail())
	            		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid number of rooms \n";
							cout<<"Enter  valid number of rooms :";
							cin>>tem->No;
						}
	            		Uni.SetTotal_Room(tem->No);
	            		cout<<"Enter Total number of campus of KICSIT :";
	            		cin>>tem->No;
	            		while(cin.fail())
	            		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid number of campus \n";
							cout<<"Enter  valid number of campus :";
							cin>>tem->No;
						}
	            		Uni.SetCampus(tem->No);
	            		cout<<"Enter Address of KICSIT :";
	            		cin.ignore();
	            		cin.getline(tem->address,50);
	            		Uni.SetAddress_of_Uni(tem->address);
	            		cout<<"Enter Total number of Libraries of KICSIT :";
	            		cin>>tem->No;
	            		while(cin.fail())
	            		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid number of Libraries \n";
							cout<<"Enter  valid number of Libraries :";
							cin>>tem->No;
						}
						Uni.SetTotal_Library(tem->No);
						cout<<"Enter Total number of Play Ground of KICSIT :";
	            		cin>>tem->No;
	            		while(cin.fail())
	           			{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You  entered invalid number of Play Ground \n";
							cout<<"Enter  valid number of Play Ground :";
							cin>>tem->No;
						}
						Uni.SetP_Ground(tem->No);
						cout<<"------------------------------------Updated Successfully---------------------------------------\n";
						getch();
					}
					else 
					{
						system("cls");
						cout<<"\n\n\n\n\t\t\tSorry Record is not saved so you cannot update record\n";
						getch();
					}
	        	}
	        	else if(choice==4)
	        	{
	        		system("cls");
	        		system("COLOR 4f");
				}
	        	else 
	        	{
						cout<<"\n\n\n\n\t\t\tWrong input\n";
	        			getch();
				}
        	}while(choice!=4); 
	} 
    //Outter loop Condition
    else if(Condition==2)
    {
			system("COLOR F0");
			do //Inner loop
			{
				system("cls");	
				Admin_SubMenu()	;
	    		cout<<"Enter your choice :";
	    		cin>>choice;
				while(cin.fail())
				{  
					cin.clear();
					cin.ignore(80,'\n');
					cout<<"Sorry You entered invalid choice \n";
					cout<<"Enter valid choice :";
					cin>>choice;
				}
	    		if(choice==1)
	    		{
	    			flag=0;
					system("cls");
					do
					{
						system("cls");
						aadmin();
						cout<<"Enter your choice :";
						cin>>ch;
						while(cin.fail())
		      			{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You entered invalid choice \n";
							cout<<"Enter valid choice :";
							cin>>ch;
						}   
						if(ch==1)
						{
							system("cls");
							
							if(ad==1)
							{
								cout<<"\t\t\tPLEASE ENTER INFORMATION OF ADMINISTRATOR \n";
								cout<<endl;
								cout<<"------------------------------------------------------------------------\n";
								tem=new Linkedlist;
		    					cout<<"Enter Name of Administrator :";
	            				cin.ignore();
								cin.getline(tem->name,50);
	            				for(int i=0;tem->name[i]!='\0';i++)   //validation for name
                				{
                   			 		if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
                    				{
	            						cout<<"Sorry You Entered invalid name \n";
                    					cout<<"Enter valid name :";
                    					cin.getline(tem->name,10);
                    					i=0;
                    				}
                				}
			    				admin.SetNameAdministrator(tem->name); 
			    				cout<<"Enter CNIC of Administrator: ";
			    				cin>>tem->cnic;
			    				for(int i=0;i<tem->cnic.size();i++)   //validation for CNIC
			   			 		{
				  					 if(!(isdigit(tem->cnic[i])||(tem->cnic[i]=='-')))
				 				 	{
				    					cout<<"Sorry You Entered invalid CNIC \n";
				    					cout<<"Enter valid CNIC :";
				    					cin>>tem->cnic;
			    						i=0;							
				 			 		}
			    				}    
			    				admin.SetCNIC_Administrator(tem->cnic);
			    				cout<<"Enter Address of Administrator :";
			    				cin.ignore();
								cin.getline(tem->address,50);   
			    				admin.SetAddress_Administrator(tem->address);
			    				cout<<"Enter Date of birth day :";
			    				cin>>tem->DOB;
			    				admin.SetDate_of_BirthAdmin(tem->DOB);
			    				cout<<"Enter Employee number of Administrator:";
								cin>>tem->Reg_No;
								admin.SetEmployee_No_of_Admin(tem->Reg_No);
								cout<<"Enter Total number of students in university :";
								cin>>tem->number;
								while(cin.fail())
								{  
									cin.clear();
									cin.ignore(80,'\n');
									cout<<"Sorry You entered invalid number of students \n";
									cout<<"Enter valid number of students :";
									cin>>tem->number;
								}
								admin.SetTotal_Student(tem->number);
								cout<<"Enter Total number of Lecturers in university :";
								cin>>tem->number;
								while(cin.fail())
								{
									cin.clear();
									cin.ignore(80,'\n');
									cout<<"Sorry You entered invalid number of lecturers \n";
									cout<<"Enter valid number of lecturers :";
									cin>>tem->number;
								}
								admin.SetTotal_Lecturer(tem->number);
								cout<<"Enter Total number of Employee in university :";
								cin>>tem->number;
								while(cin.fail())
		      					{
									cin.clear();
									cin.ignore(80,'\n');
									cout<<"Sorry You entered invalid number of Employee \n";
									cout<<"Enter valid number of Employee :";
									cin>>tem->number;
								}   
								admin.SetTotal_Employee(tem->number);
								cout<<"Enter Total number of Rooms in university :";
								cin>>tem->number;
								while(cin.fail())
		        				{
									cin.clear();
									cin.ignore(80,'\n');
									cout<<"Sorry You entered invalid number of Rooms \n";
									cout<<"Enter valid number of Rooms";
									cin>>tem->number;
								} 
								admin.SetTotal_Room(tem->number);
								Uni.Add_Admin(admin);
								flag=1;
								ad=0;
								cout<<"------------------------------------------------------------------------\n";
								getch();
							}
							else
	        				{
	        					cout<<"\n\n\n\n\t\t\tSorry You cannot enter new information because information is entered \n";
	        					getch();
							}
						}
						else if(ch==2)
						{
							system("cls");
							if(flag==1)
							{
								cout<<"                                                         SAVED RECORD\n";
								cout<<"------------------------------------------------------------------------\n";
								Uni.Show_Admin();
								cout<<"------------------------------------------------------------------------\n";
	    						getch();
							}
							else
							{
	    						system("cls");
	      						cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	        					getch();	
							}
						}
						else if(ch==3)
						{
							system("cls");
							cout<<"Dr.A.Q Khan Institute Of Computer Science And Information Technology\n";
							cout<<"\t\t\t\tFee Structure\n";
							cout<<"_____________________________________________________________________________\n";
							cout<<"| Particulars   | Wards of KRL (Rs) | Wards of SPD(Rs) | Wards of Other(Rs) |\n";
							cout<<"|Admission Fee  | 5000              | 5000             | 5000               |\n"; 
							cout<<"|KICSIT Reg.Fee | 800               | 800              | 800                |\n"; 
							cout<<"|Lab Security   | 2300              | 2300             | 2300               |\n"; 
							cout<<"|Library Sec    | 2300              | 2300             | 2300               |\n";
							cout<<"|ID card        | 700               | 700              | 700                |\n"; 
							cout<<"|Certificate    | 2700              | 2700             | 2700               |\n"; 	
							cout<<"|Tuition Fee    | 24000             | 24000            | 24000              |\n"; 
							cout<<"|Exam Fee       | 900               | 900              | 900                |\n"; 
							cout<<"|MISC Dues      | 16300             | 21300            | 39300              |\n"; 
							cout<<"_____________________________________________________________________________\n";
							cout<<"Total Fee        55000                6000               78000               \n"; 	
							cout<<"_____________________________________________________________________________\n";
							cout<<"\t\t\t\tPer Semester\n";
							cout<<"_____________________________________________________________________________\n";
							cout<<"| Particulars   | Wards of KRL (Rs) | Wards of SPD(Rs) | Wards of Other(Rs) |\n";
							cout<<"|Total Fee      | 45000             | 55000            | 65000              |\n";
							cout<<"_____________________________________________________________________________\n";
							getch();
						}
						else if(ch==4)
						{
							if(flag==1)
							{
								system("cls");
								cout<<"\t\t\tPLEASE ENTER INFORMATION FOR UPDATION \n\n";
								cout<<"------------------------------------------------------------------------\n";
								cout<<"Enter Name of Administrator :";
	            				cin.ignore();
								cin.getline(tem->name,50);
	            				for(int i=0;tem->name[i]!='\0';i++)   //validation for name
                				{
                   			 		if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
                    				{
	            						cout<<"Sorry You Entered invalid name \n";
                    					cout<<"Enter valid name :";
                    					cin.getline(tem->name,10);
                    					i=0;
                    				}
                				}
			    				admin.SetNameAdministrator(tem->name); 
			    				cout<<"Enter CNIC of Administrator: ";
			    				cin>>tem->cnic;
			    				for(int i=0;i<tem->cnic.size();i++)   //validation for CNIC
			   			 		{
				  					 if(!(isdigit(tem->cnic[i])||(tem->cnic[i]=='-')))
				 				 	{
				    					cout<<"Sorry You Entered invalid CNIC \n";
				    					cout<<"Enter valid CNIC :";
				    					cin>>tem->cnic;
			    						i=0;							
				 			 		}
			    				}    
			    				admin.SetCNIC_Administrator(tem->cnic);
			    				cout<<"Enter Address of Administrator :";
			    				cin.ignore();
								cin.getline(tem->address,50);   
			    				admin.SetAddress_Administrator(tem->address);
			    				cout<<"Enter Date of birth day :";
			    				cin>>tem->DOB;
			    				admin.SetDate_of_BirthAdmin(tem->DOB);
			    				cout<<"Enter Employee number of Administrator:";
								cin>>tem->Reg_No;
								admin.SetEmployee_No_of_Admin(tem->Reg_No);
								cout<<"Enter Total number of students in university :";
								cin>>tem->number;
								while(cin.fail())
								{  
									cin.clear();
									cin.ignore(80,'\n');
									cout<<"Sorry You entered invalid number of students \n";
									cout<<"Enter valid number of students :";
									cin>>tem->number;
								}
								admin.SetTotal_Student(tem->number);
								cout<<"Enter Total number of Lecturers in university :";
								cin>>tem->number;
								while(cin.fail())
								{
									cin.clear();
									cin.ignore(80,'\n');
									cout<<"Sorry You entered invalid number of lecturers \n";
									cout<<"Enter valid number of lecturers :";
									cin>>tem->number;
								}
								admin.SetTotal_Lecturer(tem->number);
								cout<<"Enter Total number of Employee in university :";
								cin>>tem->number;
								while(cin.fail())
		      					{
									cin.clear();
									cin.ignore(80,'\n');
									cout<<"Sorry You entered invalid number of Employee \n";
									cout<<"Enter valid number of Employee :";
									cin>>tem->number;
								}   
								admin.SetTotal_Employee(tem->number);
								cout<<"Enter Total number of Rooms in university :";
								cin>>tem->number;
								while(cin.fail())
		        				{
									cin.clear();
									cin.ignore(80,'\n');
									cout<<"Sorry You entered invalid number of Rooms \n";
									cout<<"Enter valid number of Rooms";
									cin>>tem->number;
								} 
								admin.SetTotal_Room(tem->number);
								Uni.Add_Admin(admin);
								flag=1;
								ad=0;
								cout<<"--------------------------Update Successfully---------------------------\n";
								getch();
							}
							else
							{
								system("cls");
								cout<<"\n\n\n\t\t\tSorry Record is not saved so you cannat update record\n";
								getch();
							}
						}
						else if(ch==5)
						{
							system("cls");
						}
						else
						{
							cout<<"Sorry Invalid input\n";
							getch();
						}
					}while(ch!=5);
				}
				else if(choice==2)
				{
					do
					{
						system("cls");
						NewAdmission();
						cout<<"Enter your choice :";
						cin>>ch;
						while(cin.fail())
		        		{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You entered invalid choice \n";
							cout<<"Enter valid choice	";
							cin>>ch;
						}
						if(ch==1)
						{
							do
							{
								system("cls");
								Degree();
								cout<<"Enter your choice :";
								cin>>Ch;
								while(cin.fail())
		        				{	
									cin.clear();
									cin.ignore(80,'\n');
									cout<<"Sorry You entered invalid choice \n";
									cout<<"Enter valid choice";
									cin>>Ch;
								}
								if(Ch==1)
								{
									system("cls");
									New.InsertionCS();
								}
								else if(Ch==2)
								{
									system("cls");
									New.InsertionCE();
								}
								else if(Ch!=3)
								{
									cout<<"Invalid input\n";
									getch();
								}
							}while(Ch!=3);
						}
						else if(ch==2)
						{
							do
							{
								system("cls");
								Degree();
								cout<<"Enter your choice :";
								cin>>Ch;
								while(cin.fail())
		        				{	
									cin.clear();
									cin.ignore(80,'\n');
									cout<<"Sorry You entered invalid choice \n";
									cout<<"Enter valid choice";
									cin>>Ch;
								}
								if(Ch==1)
								{
									system("cls");
									New.DisplayDataCS();
								}
								else if(Ch==2)
								{
									system("cls");
									New.DisplayDataCE();
								}
								else if(Ch!=3)
								{
									cout<<"Invalid input\n";
									getch();
								}
							}while(Ch!=3);
						}
						else if(ch==3)
						{
							system("cls");	
						}
						else
						{
							system("cls");
							cout<<"\t\t\t\tSorry Invalid Input\n";
						}
					}while(ch!=3);
				}
				else if(choice==3)
				{
				system("cls");
				flag=0;
				do
				{
					system("cls");
					AccountantMenu();
					cout<<"Enter your choice :";
					cin>>ch;
					while(cin.fail())
		      		{
					cin.clear();
					cin.ignore(80,'\n');
					cout<<"Sorry You entered invalid choice \n";
					cout<<"Enter valid choice :";
					cin>>tem->number;
					}   
					if(ch==1)
					{
						system("cls");
						if(ac==1)
						{
							cout<<"\t\t\tPLEASE ENTER INFORMATION OF ACCOUNTANT \n";
							cout<<endl;
							cout<<"------------------------------------------------------------------------\n";
							tem=new Linkedlist;
		    				cout<<"Enter Name of Accountant :";
	            			cin.ignore();
							cin.getline(tem->name,50);
	            			for(int i=0;tem->name[i]!='\0';i++)   //validation for name
                			{
                   				 if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
                    			{
	            					cout<<"Sorry You Entered invalid name \n";
                    				cout<<"Enter valid name :";
                    				cin.getline(tem->name,10);
                    				i=0;
                    			}
                			}
			    			acc.SetName_of_Person(tem->name); 
			    			cout<<"Enter CNIC of Accountant: ";
			    			cin>>tem->cnic;
			    			for(int i=0;i<tem->cnic.size();i++)   //validation for CNIC
			   			 	{
				  				if(!(isdigit(tem->cnic[i])||(tem->cnic[i]=='-')))
				 				{
				    				cout<<"Sorry You Entered invalid CNIC \n";
				    				cout<<"Enter valid CNIC :";
				    				cin>>tem->cnic;
			    					i=0;							
				 			 	}
			    			}    
			    			acc.SetCNIC_Accountant(tem->cnic);
			    			cout<<"Enter Address of Accountant :";
			    			cin.ignore();
							cin.getline(tem->address,50);   
			    			acc.SetAddress_of_Perosn(tem->address);
			    			cout<<"Enter Date of birth day :";
			    			cin>>tem->DOB;
			    			acc.SetDateOfBirth_of_Person(tem->DOB);
			    			cout<<"Enter Employee number of Accountant:";
							cin>>tem->Reg_No;
							acc.SetEmployee_No_of_A(tem->Reg_No);
							cout<<"Enter total number of students they are taking need base scholarship :";
							cin>>tem->No;
							while(cin.fail())
		      				{
								cin.clear();
								cin.ignore(80,'\n');
								cout<<"Sorry You entered invalid number of Employee \n";
								cout<<"Enter valid number of Employee :";
								cin>>tem->No;
							}   
							acc.SetTotal_Student(tem->No);
							flag=1;
							ac=0;
							cout<<"------------------------------------------------------------------------\n";
							getch();
						}
						else
	        			{
	        				cout<<"\n\n\n\n\t\t\tSorry You cannot enter new information because information is entered \n";
	        				getch();
						}
					}
					else if(ch==2)
					{
							system("cls");
							if(flag)
							{
								cout<<"\t\t\t\tINFORMATION OF KICSIT ACCOUNTANT\n\n";
								cout<<"------------------------------------------------------------------------\n";
								acc.Display_Acc();
								cout<<"------------------------------------------------------------------------\n";
								getch();
							}
							else
							{
								cout<<"\n\n\n\n\t\t\t\tRecord is not Saved\n";
								getch();
							}
												
					}
					else if(ch==3)
					{
						system("cls");
						cout<<"PLEASE ENTER INFORMATION FOR FEE SUBMISSION\n\n";
						fs.EnQueue();    
					}
					else if(ch==4)
					{
						fs.DeQueue();
					}
					else if(ch==5)
					{
						system("cls");
						fs.Display();
					
					}
					else if(ch==6)
					{
						if(flag==1)
						{
							system("cls");
							cout<<"\t\t\tENTER ACCOUNTANT INFORMATION FOR UPDATION\n\n";
							cout<<"------------------------------------------------------------------------\n";
							cout<<"Enter Name of Accountant :";
	            			cin.ignore();
							cin.getline(tem->name,50);
	            			for(int i=0;tem->name[i]!='\0';i++)   //validation for name
                			{
                   				 if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
                    			{
	            					cout<<"Sorry You Entered invalid name \n";
                    				cout<<"Enter valid name :";
                    				cin.getline(tem->name,10);
                    				i=0;
                    			}
                			}
			    			acc.SetName_of_Person(tem->name); 
			    			cout<<"Enter CNIC of Accountant: ";
			    			cin>>tem->cnic;
			    			for(int i=0;i<tem->cnic.size();i++)   //validation for CNIC
			   			 	{
				  				if(!(isdigit(tem->cnic[i])||(tem->cnic[i]=='-')))
				 				{
				    				cout<<"Sorry You Entered invalid CNIC \n";
				    				cout<<"Enter valid CNIC :";
				    				cin>>tem->cnic;
			    					i=0;							
				 			 	}
			    			}    
			    			acc.SetCNIC_Accountant(tem->cnic);
			    			cout<<"Enter Address of Accountant :";
			    			cin.ignore();
							cin.getline(tem->address,50);   
			    			acc.SetAddress_of_Perosn(tem->address);
			    			cout<<"Enter Date of birth day :";
			    			cin>>tem->DOB;
			    			acc.SetDateOfBirth_of_Person(tem->DOB);
			    			cout<<"Enter Employee number of Accountant:";
							cin>>tem->Reg_No;
							acc.SetEmployee_No_of_A(tem->Reg_No);
							cout<<"Enter total number of students they are taking need base scholarship :";
							cin>>tem->No;
							while(cin.fail())
		      				{
								cin.clear();
								cin.ignore(80,'\n');
								cout<<"Sorry You entered invalid number of Employee \n";
								cout<<"Enter valid number of Employee :";
								cin>>tem->No;
							}   
							acc.SetTotal_Student(tem->No);
							flag=1;
							ac=0;
							cout<<"---------------------------Updation Successfully------------------------\n";
							getch();	
						}
						else 
						{
							system("cls");
							cout<<"\n\n\n\t\t\tSoryy Record Not Saved So you cannot update data\n";
							getch();
						}
					}
					else if(ch==7)
					{
						system("cls");
					}
					else
					{
						cout<<"\n\n\n\n\t\t\t\tSorry Invalid input";
						getch();
					}
			
				}while(ch!=7);
			}
			else if(choice==4)
			{
				system("cls");
				system("COLOR 4f");
			}
	   		else 
	    	{
	    		system("cls");
				cout<<"Wrong input\n";
	    		getch();
			}
      	}while(choice!=4);
	} 
	//Outter loop Condition
	else if(Condition==3)
	{
		system("COLOR 17");
		do //Inner loop
		{
			system("cls");
		    Department_SubMenu();
		    cout<<"Enter your choice :";
		    cin>>choice;
			while(cin.fail())
			{  
				cin.clear();
				cin.ignore(80,'\n');
				cout<<"Sorry You entered invalid choice \n";
				cout<<"Enter valid choice :";
				cin>>choice;
			}
		    if(choice==1)
		    {
			system("cls");
			cout<<"\t\t\tPLEASE ENTER INFORMATION\n";
			Ch=1;
			while(Ch)
			{
			 	f=1;
			    cout<<"Enter Information of \n\n";
			    cout<<"---------------------Department No."<<f<<" ----------------------------\n";
			    tem=new Linkedlist;
			    
			    cout<<"Enter name of Department :";
			    cin.ignore();
				cin.getline(tem->name,100);
				for(int i=0;tem->name[i]!='\0';i++)   //validation for name
				{
					if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
					{
						cout<<"Sorry You Entered invalid name \n";
						cout<<"Enter valid name :"<<endl;
						cin.ignore();
						cin.getline(tem->name,50);
						i=0;
					}
				}
				departments.SetName_of_Dep(tem->name);
				cout<<"Enter id of Department : ";
				cin>>tem->id;
				departments.SetId_of_Dep(tem->id);
				cout<<"Enter Head of Department :";
				cin.ignore();
				cin.getline(tem->hod,100);
				for(int i=0;tem->hod[i]!='\0';i++)   //validation for name
				{
					if(!(isalpha(tem->hod[i])||tem->hod[i]=='.'||isspace(tem->hod[i])))
					{
						cout<<"Sorry You Entered invalid name \n";
						cout<<"Enter valid name :"<<endl;
						cin.ignore();
						cin.getline(tem->hod,50);
						i=0;
					}
				}
				departments.SetHead_of_Department(tem->hod);
				cout<<"Enter Total number of Students they have "<<tem->name<<" Department :";
				cin>>tem->number;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore(80,'\n');
					cout<<"Sorry You entered invalid number of Students \n";
					cout<<"Enter valid number of Students :";
					cin>>tem->number;
				} 
				departments.SetNo_of_Student(tem->number);
                cout<<"Enter Total number of Lecturers they have "<<tem->name<<" Department :";
                cin>>tem->number;
                while(cin.fail())
				{
					cin.clear();
					cin.ignore(80,'\n');
					cout<<"Sorry You entered invalid number of lecturers \n";
					cout<<"Enter valid number of lecturers :";
					cin>>tem->number;
				}
                departments.SetNo_of_lecturer(tem->number);
                cout<<"Enter Total ReSearch in "<<departments.GetName_of_Dep()<<" Department :";
                cin>>tem->No;
                while(cin.fail())
				{
					cin.clear();
					cin.ignore(80,'\n');
					cout<<"Sorry You entered invalid number of ReSearch \n";
					cout<<"Enter valid number of ReSearch :";
					cin>>tem->number;
				}
				departments.TotalReSearch(tem->No);
                flag=1;
                if(last==NULL)
                {
                	head=last=tem;
				}
				else
				{
					last->ptr=tem;
					last=tem;
				}
				cout<<"Do you want to add another Department (1/0) :";
				cin>>Ch;
				f++;
			}
		}
		else if(choice==2)
		{
			system("cls");
			int flag=0;
			cout<<"\t\t\tENTER ID FOR SEARCH \n\n";
		    cout<<"Enter Id  of Department for Search Record : ";
            cin>>id;
            cout<<endl;
	        tem=head;
	        while(tem!=NULL)
	        {
	        	if(tem->id==id)
	        	{
	        		flag=1;
	        		break;
				}
				else
				{
					tem=tem->ptr;
				}
			}
			if(flag)
			{
				cout<<"------------------------------- "<<tem->name<<" Department -------------------------\n";
				cout<<"Name of Department is :"<<tem->name<<endl;
				cout<<"Id of Department is :"<<tem->id<<endl;
				cout<<"Head of Department is :"<<tem->hod<<endl;
				cout<<"Number of Lecturer they have "<<tem->name<<" Department are :"<<tem->No<<endl;
				cout<<"Number of students they have "<<tem->name<<" Department are :"<<tem->number<<endl;
				cout<<"Total  ReSearch in "<<tem->name<<" Department are :"<<tem->No<<endl;
			}
			else
			{
				cout<<"\n\n\n\t\t\t\tSorry You entered Invalid Id please try again "<<endl;
			}
	    	getch();  
		}
		else if(choice==3)
		{
			system("cls");
			if(flag==1)
			{
			cout<<"                                                        SAVED RECORD\n";
			f=1;
			tem=head;
			last->ptr=NULL;
			int fag=1;
			while(tem!=NULL)
			{
				cout<<"\n";
				cout<<"---------------------------Department No."<<f<<" ------------------------------\n";
				cout<<"Name of Department is :"<<tem->name<<endl;
				cout<<"Id of Department is :"<<tem->id<<endl;
				cout<<"Head of Department is :"<<tem->hod<<endl;
				cout<<"Number of Lecturer they have "<<tem->name<<" Department are :"<<tem->No<<endl;
				cout<<"Number of students they have "<<tem->name<<" Department are :"<<tem->number<<endl;
				cout<<"Total  ReSearch in "<<tem->name<<" Department are :"<<tem->No<<endl;
				tem=tem->ptr;
				f++;
				fag=0;
			}
			if(fag)
			{
				cout<<"\n\n\n\n\t\t\t\tSorry Record Not Saved\n";
			}
	    	getch();
			}
			else
			{
		    	system("cls");
	       		cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	        	getch();
			}
		}
		else if(choice==4)
		{
			system("cls");
			system("COLOR 4f");
		}
		else if(choice==5)
		{
			system("cls");
			cout<<"\t\t\tENTER ID FOR DELETION \n\n";
			int flag=0;
		    cout<<"Enter Id  of Department for deletion : ";
            cin>>id;
				if(head==NULL)
				{
					cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
					getch();
				}
				else if(head->id==id)
				{
					tem=head;
					head=head->ptr;
					delete(tem);
					cout<<"\n\t\t\tDeleted Successfully";
					getch();
				}
				else if(last->id==id)
				{
					Linkedlist *temp;
					temp=head;
					while(temp->ptr!=NULL)
					{
						if(temp->ptr->id==id)
						{
							tem=temp->ptr;
							temp->ptr=tem->ptr;
							delete(tem);
						}
						else
						{
							temp=temp->ptr;
						}
					}
					cout<<"\n\t\t\tDeleted Successfully";
					getch();
				}
				else if(head->id!=id&&last->id!=id)
				{
				Linkedlist *temp;	
	        	temp=head;
	        	while(temp->ptr->ptr!=NULL)
	        	{
	        		if(temp->ptr->id==id)
	        		{
	        		flag=1;
	        		break;
					}
					else
					{
					temp=temp->ptr;
					tem=temp->ptr;
					}
				}
				if(flag)
				{
					temp->ptr=temp->ptr->ptr;
					cout<<"\n\t\t\tDeleted Successfully";
					getch();
				}
				}
	    	else 
	    	{
				cout<<"Wrong input\n";
				getch(); 
			
		    }
		}
		else if(choice==6)
		{
			system("cls");
			int flag=0;
			cout<<"\t\t\tENTER ID FOR SEARCH \n\n";
		    cout<<"Enter Id  of Department for Update Record : ";
            cin>>id;
            cout<<endl;
	        tem=head;
	        while(tem!=NULL)
	        {
	        	if(tem->id==id)
	        	{
	        		flag=1;
	        		break;
				}
				else
				{
					tem=tem->ptr;
				}
			}
			if(flag)
			{
				cout<<"-----------------------------------------------------------------------\n";
			   cout<<"Enter name of Department :";
			    cin.ignore();
				cin.getline(tem->name,100);
				for(int i=0;tem->name[i]!='\0';i++)   //validation for name
				{
					if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
					{
						cout<<"Sorry You Entered invalid name \n";
						cout<<"Enter valid name :"<<endl;
						cin.ignore();
						cin.getline(tem->name,50);
						i=0;
					}
				}
				departments.SetName_of_Dep(tem->name);
				cout<<"Enter id of Department : ";
				cin>>tem->id;
				departments.SetId_of_Dep(tem->id);
				cout<<"Enter Head of Department :";
				cin.ignore();
				cin.getline(tem->hod,100);
				for(int i=0;tem->hod[i]!='\0';i++)   //validation for name
				{
					if(!(isalpha(tem->hod[i])||tem->hod[i]=='.'||isspace(tem->hod[i])))
					{
						cout<<"Sorry You Entered invalid name \n";
						cout<<"Enter valid name :"<<endl;
						cin.ignore();
						cin.getline(tem->hod,50);
						i=0;
					}
				}
				departments.SetHead_of_Department(tem->hod);
				cout<<"Enter Total number of Students they have "<<tem->name<<" Department :";
				cin>>tem->number;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore(80,'\n');
					cout<<"Sorry You entered invalid number of Students \n";
					cout<<"Enter valid number of Students :";
					cin>>tem->number;
				} 
				departments.SetNo_of_Student(tem->number);
                cout<<"Enter Total number of Lecturers they have "<<tem->name<<" Department :";
                cin>>tem->number;
                while(cin.fail())
				{
					cin.clear();
					cin.ignore(80,'\n');
					cout<<"Sorry You entered invalid number of lecturers \n";
					cout<<"Enter valid number of lecturers :";
					cin>>tem->number;
				}
                departments.SetNo_of_lecturer(tem->number);
                cout<<"Enter Total ReSearch in "<<departments.GetName_of_Dep()<<" Department :";
                cin>>tem->No;
                while(cin.fail())
				{
					cin.clear();
					cin.ignore(80,'\n');
					cout<<"Sorry You entered invalid number of ReSearch \n";
					cout<<"Enter valid number of ReSearch :";
					cin>>tem->number;
				}
				departments.TotalReSearch(tem->No);
                flag=1;
                cout<<"--------------------------Updated Successfully-------------------------\n";
                getch();
			}
			else
			{
				cout<<"\n\n\n\t\t\t\tSorry You entered Invalid Id please try again "<<endl;
			}
	    	getch();  
		}
	  }while(choice!=4);
	}
	//Outter loop condition
	else if(Condition==4)
	{
		system("COLOR 07");
		int ASC;
		do
		{	
		    system("cls");
		    system("COLOR 07");
		    StuSubMenu();
		    cout<<"Enter Your Choice: "<<endl;
		    cin>>ASC;
		    while(cin.fail())
			{  
				cin.clear();
				cin.ignore(80,'\n');
				cout<<"Sorry You entered invalid choice \n";
				cout<<"Enter valid choice :";
				cin>>ASC;
			}
		    if(ASC==1)
		    {
		    	system("cls");
		    	Login_Function();
		    	system("cls");
		    do
			{ //inner loop
		    system("cls");

		    system("COLOR 07");
			Astumenu();
			cout<<"Enter your choice : ";
			cin>>choice_stdnt;
			while(cin.fail())
			{  
				cin.clear();
				cin.ignore(80,'\n');
				cout<<"Sorry You entered invalid choice \n";
				cout<<"Enter valid choice :";
				cin>>choice_stdnt;
			}
			if(choice_stdnt==1)
			{
				system("cls");
				cout<<"\t\t\tENTER INFORMATION OF STUDENTS \n";
				Ch=1;
				while(Ch)
				{				  
			    	tem=new Linkedlist;
					cout<<"Enter Name of student :";
					cin.ignore();
					cin.getline(tem->name,100);
					a++;
					tem->h=a;
					for(int i=0;tem->name[i]!='\0';i++)   //validation for name
					{
						if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
						{
							cout<<"Sorry You Entered invalid name \n";
							cout<<"Enter valid name :"<<endl;
							cin.ignore();
							cin.getline(tem->name,50);
							i=0;
						}
					}		   
				stdnt.SetName_of_Person(tem->name);
				cout<<"Enter Registration No of student :";
				cin>>tem->Reg_No;
				stdnt.Set_StudentRegistration_No(tem->Reg_No);
				cout<<"Enter Father Name of student :";
				cin.ignore();
				cin.getline(tem->Fname,100);
				for(int i=0;tem->Fname[i]!='\0';i++)   //validation for name
				{
					if(!(isalpha(tem->Fname[i])||tem->Fname[i]=='.'||isspace(tem->Fname[i])))
					{
						cout<<"Sorry You Entered invalid name \n";
						cout<<"Enter valid name :"<<endl;
						cin.ignore();
						cin.getline(tem->Fname,50);
						i=0;
					}
				}	  
				stdnt.SetFatherName_of_Person(tem->Fname);
				cout<<"Enter Program of student :";
				//cin.ignore();
				cin.getline(tem->program,50);
				stdnt.SetProgram(tem->program);
				cout<<"Enter Semester of student :";
				cin>>tem->semester;
				stdnt.SetSemester(tem->semester);
				cout<<"Enter Blood Group of Student :";
				cin.ignore();
				cin.getline(tem->Bld_Grp,50);
				for(;;)
				{
	   					for(int i=0;tem->Bld_Grp[i]!='\0';i++)   //validation for Blood Group
    					{
            				if(!(isalpha(tem->Bld_Grp[i])||tem->Bld_Grp[i]=='+'||(tem->Bld_Grp[i]=='-')))
            				{
    	    					cout<<"Sorry You Entered invalid Blood Group \n";
                				cout<<"Enter valid Blood Group :";
                			//	cin.ignore();
								cin.getline(tem->Bld_Grp,50);
                				i=0;
                				check=1;
                				continue;
            				}
    					}
        				if(check!=1)
        				{
        					break;
						}
						check=0;
    			}
				stdnt.SetBloodGroup_of_Person(tem->Bld_Grp);
				cout<<"Enter Address of student :";
		//		cin.ignore();
				cin.getline(tem->address,50);
				stdnt.SetAddress_of_Perosn(tem->address);
				cout<<"Enter Date of birth of student :";
				cin>>tem->DOB;
				for(;;)
				{
	   					for(int i=0;i<tem->DOB.size();i++)   //validation for Blood Group
    					{
            				if(!(isalpha(tem->DOB[i])||tem->DOB[i]==','||(tem->DOB[i]=='-')||isdigit(tem->DOB[i])||tem->DOB[i]=='/'))
            				{
    	    					cout<<"Sorry You Entered invalid Date \n";
                				cout<<"Enter valid Date :";
                				//cin.ignore();
								cin>>tem->DOB;
                				i=0;
                				check=1;
                				continue;
            				}
    					}
        				if(check!=1)
        				{
        					break;
						}
						check=0;
           }
				stdnt.SetDateOfBirth_of_Person(tem->DOB);
				cout<<"Enter number of subjects that student have in this semsester: "<<endl;
				cin>>tem->TS;
				flag=1;
				int ch=1,i=1;
				cout<<"Enter subject of "<<tem->name<<" in "<<tem->semester<<" semester \n\n";
				for(int i=0;i<tem->TS;i++)
				{
					    
						temm=new Linkedlist;
						cout<<"Enter subject No."<<i+1<<" :";
						cin>>temm->subject;
						z++;
						temm->s=z;
						cout<<"Enter presents in "<<temm->subject<<" :";
						cin>>temm->present;
						while(cin.fail())
						{  
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You entered invalid Presents \n";
							cout<<"Enter valid Presents :";
							cin>>temm->present;
						}
						cout<<"Enter Total classes in "<<temm->subject<<": ";
						cin>>temm->total_class;
						while(cin.fail())
						{  
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You entered invalid Total classes \n";
							cout<<"Enter valid Total classes :";
							cin>>temm->total_class;
						}
						cout<<"Enter Total credit hours in "<<temm->subject<<" :";
						cin>>temm->total_hour;
						while(cin.fail())
						{  
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You entered invalid Credit Hour \n";
							cout<<"Enter valid Credit Hour :";
							cin>>temm->total_hour;
						}
						cout<<"Enter grade in "<<temm->subject<<" :";
						cin>>temm->grade;
						gpa.SSSGPA_Calculator(temm->grade,temm->total_hour);
						if(last6==NULL)
						{
							last6=head6=temm;
						}
						else
						{
							last6->ptr=temm;
							last6=temm;
						}
				}
				cout<<"Enter CGPA of student: ";
			    cin>>tem->CGpa;
			    while(cin.fail())
				{  
					cin.clear();
					cin.ignore(80,'\n');
					cout<<"Sorry You entered invalid choice \n";
					cout<<"Enter valid choice :";
					cin>>choice_stdnt;
				}
				stdnt.setCGPA(tem->CGpa);
			    tem->sgpa=gpa.Final_SGPA();
				if(last1==NULL)
				{
					head1=last1=tem;
				}
				else
				{
					last1->ptr=tem;
					last1=tem;
				}
				cout<<"Do you want to insert another Student Information (1/0) :";
				cin>>Ch;
				system("cls");
			}
		}
       else if (choice_stdnt==2)
       {
		system("cls");
			cout<<"\t\t\tFOR SEARCHIN ENTER REGISTRATION NO OF STUDENT \n";   	
	        cout<<"Enter Registration number of student for Search Record : ";
			cin>>Reg_No;
			int flag=0;
			tem=head1;
			while(tem!=NULL)
	        {
	        	if(tem->Reg_No==Reg_No)
	        	{
	        		flag=1;
	        		break;
				}
				else
				{
					tem=tem->ptr;
				}
			}
			if(flag)
			{
			   cout<<"----------------------------Saved Data----------------------------------------\n";
			   cout<<"Name of student is :"<<tem->name<<endl;
			   cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
			   cout<<"Father Name of student is :"<<tem->Fname<<endl;
			   cout<<"Address of student is :"<<tem->address<<endl;
			   cout<<"Program of student is :"<<tem->program<<endl;
			   cout<<"Semester of student is :"<<tem->semester<<endl;
			   cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
			   cout<<"Date of birth of student is :"<<tem->DOB<<endl;
			   cout<<"-----------------------------------------------------------------------------\n";
			}
			else
			{
				cout<<"\t\t\t\tPlease enter valid Registration number: "<<endl;
			}
	    	getch();       	
       }
       else if(choice_stdnt==3)
		{
			system("cls");
			int flag=0;
		    cout<<"Enter Registration No  of Student for deletion : ";
            cin>>Reg_No;
				if(head1==NULL)
				{
					cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
				}
				else if(head1->Reg_No==Reg_No)
				{
					tem=head1;
					head1=head1->ptr;
					delete(tem);
					cout<<"\n\t\t\tDeleted Successfully";
					getch();
				}
				else if(last1->id==id)
				{
					Linkedlist *temp;
					temp=head1;
					while(temp->ptr!=NULL)
					{
						if(temp->ptr->Reg_No==Reg_No)
						{
							tem=temp->ptr;
							temp->ptr=tem->ptr;
							delete(tem);
						}
						else
						{
							temp=temp->ptr;
						}
					}
					cout<<"\n\t\t\tDeleted Successfully";
					getch();
				}
				else if(head1->Reg_No!=Reg_No&&last1->Reg_No!=Reg_No)
				{
				Linkedlist *temp;	
	        	temp=head1;
	        	while(temp->ptr->ptr!=NULL)
	        	{
	        		if(temp->ptr->Reg_No==Reg_No)
	        		{
	        		flag=1;
	        		break;
					}
					else
					{
					temp=temp->ptr;
					tem=temp->ptr;
					}
				}
				if(flag)
				{
					temp->ptr=temp->ptr->ptr;
					cout<<"\n\t\t\tDeleted Successfully";
					getch();
				}
				}
	    	else 
	    	{
				cout<<"\t\t\t\t\tWrong input\n";
				getch(); 
			
		    }
		}
        else if(choice_stdnt==4)
       {
       	    system("cls");
       	    
			int SCHOICE;
			do
			{

				SemesterSubMenu();
			   cout<<"Enter your choice: "<<endl;
			   cin>>SCHOICE;
			   if(SCHOICE==1)
			   {
			   	
			/*system("cls");
			SemesterCSMenu();*/
			int semschoice;
			char ck[10]="CS";
			do
			{
				system("cls");
				SemesterCSMenu();
				cout<<"Enter your choice: "<<endl;
				cin>>semschoice;
				if(semschoice==1)
				{
			       if(flag==1)
			       {
				    tem=head1;
				    last1->ptr=NULL;
				    f=1;
				    system("cls");
				    while(tem!=NULL)
				    {
					if(tem->semester==semschoice&&(strcmp(tem->program,ck)==0))
					{
						
					cout<<"Information of student No."<<f<<"\n";
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is :"<<tem->DOB<<endl;
					f++;
					CS1=0;	
					}
					tem=tem->ptr;
				    }
				     cout<<"\nPress any key to Go back to continue .............";
				     getch();
		        	}
			   if(CS1)
			   {		
		    	system("cls");
	        	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       		cout<<"\t\t\t\t\tPress any key to Go back to continue .............";
	        	getch();
			   }   
				}
			
				else if(semschoice==2)
				{
			       if(flag==1)
			       {
				    tem=head1;
				    last1->ptr=NULL;
				    f=1;
				    system("cls");
				    while(tem!=NULL)
				    {
					if(tem->semester==semschoice&&(strcmp(tem->program,ck)==0))
					{
					cout<<"Information of student No."<<f<<"\n";
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is :"<<tem->DOB<<endl;
					f++;
					CS2=0;	
					}
					tem=tem->ptr;
				    }
				     cout<<"\nPress any key to Go back to continue .............";
				     getch();
		        	}
			    if(CS2)
			   {		
		    	system("cls");
	        	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       		cout<<"\t\t\t\t\tPress any key to Go back to continue .............";
	        	getch();
			   } }  
				else if(semschoice==3)
				{
			       if(flag==1)
			       {
				    tem=head1;
				    last1->ptr=NULL;
				    f=1;
				    system("cls");
				    while(tem!=NULL)
				    {
					if(tem->semester==semschoice&&(strcmp(tem->program,ck)==0))
					{
					cout<<"Information of student No."<<f<<"\n";
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is :"<<tem->DOB<<endl;
					f++;
					CS3=0;	
					}
					tem=tem->ptr;
				    }
				     cout<<"\nPress any key to Go back to continue .............";
				     getch();
		        	}
			    if(CS3)
			   {		
		    	system("cls");
	        	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       		cout<<"\t\t\t\t\tPress any key to Go back to continue .............";
	        	getch();
			   }  } 
				else if(semschoice==4)
				{
			       if(flag==1)
			       {
				    tem=head1;
				    last1->ptr=NULL;
				    f=1;
				    system("cls");
				    while(tem!=NULL)
				    {
					if(tem->semester==semschoice&&(strcmp(tem->program,ck)==0))
					{
					cout<<"Information of student No."<<f<<"\n";
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is :"<<tem->DOB<<endl;
					f++;
					CS4=0;	
					}
					tem=tem->ptr;
				    }
				     cout<<"\nPress any key to Go back to continue .............";
				     getch();
		        	}
			    if(CS4)
			   {		
		    	system("cls");
	        	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       		cout<<"\t\t\t\t\tPress any key to Go back to continue .............";
	        	getch();
			   }}   
				else if(semschoice==5)
				{
			       if(flag==1)
			       {
				    tem=head1;
				    last1->ptr=NULL;
				    f=1;
				    system("cls");
				    while(tem!=NULL)
				    {
					if(tem->semester==semschoice&&(strcmp(tem->program,ck)==0))
					{
					cout<<"Information of student No."<<f<<"\n";
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is :"<<tem->DOB<<endl;
					f++;
					CS5=0;	
					}
					tem=tem->ptr;
				    }
				     cout<<"\nPress any key to Go back to continue .............";
				     getch();
		        	}
			    if(CS5)
			   {		
		    	system("cls");
	        	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       		cout<<"\t\t\t\t\tPress any key to Go back to continue .............";
	        	getch();
			   } }  
				else if(semschoice==6)
				{
			       if(flag==1)
			       {
				    tem=head1;
				    last1->ptr=NULL;
				    f=1;
				    system("cls");
				    while(tem!=NULL)
				    {
					if(tem->semester==semschoice&&(strcmp(tem->program,ck)==0))
					{
					cout<<"Information of student No."<<f<<"\n";
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is :"<<tem->DOB<<endl;
					f++;
				    CS6=0;	
					}
					tem=tem->ptr;
				    }
				     cout<<"\nPress any key to Go back to continue .............";
				     getch();
		        	}
			    if(CS6)
			   {		
		    	system("cls");
	        	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       		cout<<"\t\t\t\t\tPress any key to Go back to continue .............";
	        	getch();
			   }   }
				else if(semschoice==7)
				{
			       if(flag==1)
			       {
				    tem=head1;
				    last1->ptr=NULL;
				    f=1;
				    system("cls");
				    while(tem!=NULL)
				    {
					if(tem->semester==semschoice&&(strcmp(tem->program,ck)==0))
					{
					cout<<"Information of student No."<<f<<"\n";
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is :"<<tem->DOB<<endl;
					f++;
					CS7=0;	
					}
					tem=tem->ptr;
				    }
				     cout<<"\nPress any key to Go back to continue .............";
				     getch();
		        	}
			    if(CS7)
			   {		
		    	system("cls");
	        	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       		cout<<"\t\t\t\t\tPress any key to Go back to continue .............";
	        	getch();
			   }   }
				else if(semschoice==8)
				{
			       if(flag==1)
			       {
				    tem=head1;
				    last1->ptr=NULL;
				    f=1;
				    system("cls");
				    while(tem!=NULL)
				    {
					if(tem->semester==semschoice&&(strcmp(tem->program,ck)==0))
					{
					cout<<"Information of student No."<<f<<"\n";
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is :"<<tem->DOB<<endl;
					f++;
					CS8=0;	
					}
					tem=tem->ptr;
				    }
				     cout<<"\nPress any key to Go back to continue .............";
				     getch();
		        	}
			    if(CS8)
			   {		
		    	system("cls");
	        	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       		cout<<"\t\t\t\t\tPress any key to Go back to continue .............";
	        	getch();
			   }
		}
		
	    else if(semschoice==9)
	    {
		    system("cls");
		  //  system("color 70");
	   }
       else if(semschoice!=9) 
	   {
		   cout<<"Wrong input\n";
		   cout<<"Press any key to Go back to continue .............";
		   getch(); 
		        }
		}while(semschoice!=9);

       }
	 else if(SCHOICE==2)
	 {
			char EK[10]="CE";
			/*system("cls");
			SemesterCEMenu();*/
			int semschoice;
			do
			{
				system("cls");
				SemesterCEMenu();
				cout<<"Enter your choice: "<<endl;
				cin>>semschoice;
				if(semschoice==1)
				{
			       if(flag==1)
			       {
				    tem=head1;
				    last1->ptr=NULL;
				    f=1;
				    system("cls");
				    while(tem!=NULL)
				    {
					if(tem->semester==semschoice&&(strcmp(tem->program,EK)==0))
					{
					cout<<"Information of student No."<<f<<"\n";
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is :"<<tem->DOB<<endl;
					f++;
					CE1=0;	
					}
					tem=tem->ptr;
				    }
				     cout<<"\nPress any key to Go back to continue .............";
				     getch();
		        	}
			   if(CE1)
			   {		
		    	system("cls");
	        	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       		cout<<"\t\t\t\t\tPress any key to Go back to continue .............";
	        	getch();
			   }   
				}
			
				else if(semschoice==2)
				{
			       if(flag==1)
			       {
				    tem=head1;
				    last1->ptr=NULL;
				    f=1;
				    system("cls");
				    while(tem!=NULL)
				    {
					if(tem->semester==semschoice&&(strcmp(tem->program,EK)==0))
					{
					cout<<"Information of student No."<<f<<"\n";
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is :"<<tem->DOB<<endl;
					f++;
					CE2=0;	
					}
					tem=tem->ptr;
				    }
				     cout<<"\nPress any key to Go back to continue .............";
				     getch();
		        	}
			    if(CE2)
			   {		
		    	system("cls");
	        	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       		cout<<"\t\t\t\t\tPress any key to Go back to continue .............";
	        	getch();
			   } }  
				else if(semschoice==3)
				{
			       if(flag==1)
			       {
				    tem=head1;
				    last1->ptr=NULL;
				    f=1;
				    system("cls");
				    while(tem!=NULL)
				    {
					if(tem->semester==semschoice&&(strcmp(tem->program,EK)==0))
					{
					cout<<"Information of student No."<<f<<"\n";
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is :"<<tem->DOB<<endl;
					f++;
					CE3=0;	
					}
					tem=tem->ptr;
				    }
				     cout<<"\nPress any key to Go back to continue .............";
				     getch();
		        	}
			    if(CE3)
			   {		
		    	system("cls");
	        	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       		cout<<"\t\t\t\t\tPress any key to Go back to continue .............";
	        	getch();
			   }  } 
				else if(semschoice==4)
				{
			       if(flag==1)
			       {
				    tem=head1;
				    last1->ptr=NULL;
				    f=1;
				    system("cls");
				    while(tem!=NULL)
				    {
					if(tem->semester==semschoice&&(strcmp(tem->program,EK)==0))
					{
					cout<<"Information of student No."<<f<<"\n";
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is :"<<tem->DOB<<endl;
					f++;
					CE4=0;	
					}
					tem=tem->ptr;
				    }
				     cout<<"\nPress any key to Go back to continue .............";
				     getch();
		        	}
			    if(CE4)
			   {		
		    	system("cls");
	        	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       		cout<<"\t\t\t\t\tPress any key to Go back to continue .............";
	        	getch();
			   }}   
				else if(semschoice==5)
				{
			       if(flag==1)
			       {
				    tem=head1;
				    last1->ptr=NULL;
				    system("cls");
				    f=1;
				    while(tem!=NULL)
				    {
					if(tem->semester==semschoice&&(strcmp(tem->program,EK)==0))
					{
					cout<<"Information of student No."<<f<<"\n";
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is :"<<tem->DOB<<endl;
					f++;
					CE5=0;	
					}
					tem=tem->ptr;
				    }
				     cout<<"\nPress any key to Go back to continue .............";
				     getch();
		        	}
			    if(CE5)
			   {		
		    	system("cls");
	        	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       		cout<<"\t\t\t\t\tPress any key to Go back to continue .............";
	        	getch();
			   } }  
				else if(semschoice==6)
				{
			       if(flag==1)
			       {
				    tem=head1;
				    last1->ptr=NULL;
				    f=1;
				    system("cls");
				    while(tem!=NULL)
				    {
					if(tem->semester==semschoice&&(strcmp(tem->program,EK)==0))
					{
					cout<<"Information of student No."<<f<<"\n";
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is :"<<tem->DOB<<endl;
					f++;
				    CE6=0;	
					}
					tem=tem->ptr;
				    }
				     cout<<"\nPress any key to Go back to continue .............";
				     getch();
		        	}
			    if(CE6)
			   {		
		    	system("cls");
	        	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       		cout<<"\t\t\t\t\tPress any key to Go back to continue .............";
	        	getch();
			   }   }
				else if(semschoice==7)
				{
			       if(flag==1)
			       {
				    tem=head1;
				    last1->ptr=NULL;
				    f=1;
				    system("cls");
				    while(tem!=NULL)
				    {
					if(tem->semester==semschoice&&(strcmp(tem->program,EK)==0))
					{
					cout<<"Information of student No."<<f<<"\n";
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is :"<<tem->DOB<<endl;
					f++;
					CE7=0;	
					}
					tem=tem->ptr;
				    }
				     cout<<"\nPress any key to Go back to continue .............";
				     getch();
		        	}
			    if(CE7)
			   {		
		    	system("cls");
	        	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       		cout<<"\t\t\t\t\tPress any key to Go back to continue .............";
	        	getch();
			   }   }
				else if(semschoice==8)
				{
			       if(flag==1)
			       {
				    tem=head1;
				    last1->ptr=NULL;
				    f=1;
				    system("cls");
				    while(tem!=NULL)
				    {
					if(tem->semester==semschoice&&(strcmp(tem->program,EK)==0))
					{
					cout<<"Information of student No."<<f<<"\n";
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is :"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is :"<<tem->DOB<<endl;
					f++;
					CE8=0;	
					}
					tem=tem->ptr;
				    }
				     cout<<"\nPress any key to Go back to continue .............";
				     getch();
		        	}
			    if(CE8)
			   {		
		    	system("cls");
	        	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       		cout<<"\t\t\t\t\tPress any key to Go back to continue .............";
	        	getch();
			   }
		}
	    else if(semschoice==9)
	    {
		   system("cls");
		//   system("color 70");
	    }
        else if(semschoice!=9) 
	    {
		    cout<<"Wrong input\n";
		    cout<<"Press any key to Go back to continue .............";
		    getch(); 
		}
		}while(semschoice!=9);

			   }
			
	   	else if(SCHOICE==3)
	   	{
	   		system("cls");
		}
       	else if(SCHOICE!=3)
	    {
			cout<<"\t\t\t\t\t\tWrong input\n";
			cout<<"\t\t\t\t\t\tPress any key to Go back to continue .............";
			getch(); 
		}
			}while(SCHOICE!=3);
	   }
//////////////////////////////////////////////////////////////////////////////////////////////	   
	   else if(choice_stdnt==6)
	   {
	   	system("cls");
	   	llast=NULL,lllast=NULL;
 		system("cls");
	   	llast=NULL,lllast=NULL;
	   	int  ch=1;
	   	f=1;
	   	cout<<"\t\t\tPlease Enter Information of student of daily basis attendance\n";
	   	while(ch)
		{
			cout<<"-----------------------------Student No."<<f<<"------------------------\n";
		   	tem=new Linkedlist;
		   	cout<<"Enter Name of student :";
		   	cin.ignore();
			cin.getline(tem->name,45);
			for(int i=0;tem->name[i]!='\0';i++)   //validation for name
               	 		{
                    		if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
                    		{
	           	 				cout<<"Sorry You Entered invalid name \n";
                   	 			cout<<"Enter valid name :";
                    			cin.getline(tem->name,150);
                    			i=0;
                    		}
                		}    
			cout<<"Enter Reg. No of student :";
			cin>>tem->Reg_No;
			cout<<"Enter Number of subject of "<<tem->name<<":";
			cin>>tem->TS;
			while(cin.fail())
		    {
				cin.clear();
				cin.ignore(80,'\n');
				cout<<"Sorry You entered invalid Number \n";
				cout<<"Enter valid Number :";
				cin>>tem->TS;
			}  
			for(int i=0;i<tem->TS;i++)
			{
						counterP=0,counterA=0;		
						Temm=new Linkedlist;
						cout<<"Enter Name of  subject No."<<i+1<<" :";
						cin>>Temm->subject;
						cout<<"How many weeks you want enter attendance :";
						cin>>Temm->wk;
						while(cin.fail())
		      			{
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You entered invalid week \n";
							cout<<"Enter valid week :";
							cin>>tem->number;
						}	  
						for(int j=0;j<Temm->wk;j++)
						{
							Temmm=new Linkedlist;
							cout<<"Enter Attendance of week "<<j+1<<"\n";
							cout<<"1.Monday:\n P. Present\n A. Absent\n --.No lecture\n";
							cin>>Temmm->mon;
							if(Temmm->mon=="P"||Temmm->mon=="p")
							{
								counterP++;
							}
							else if(Temmm->mon=="A"||Temmm->mon=="a")
							{
								counterA++;
							}
							cout<<"2.Tuesday:\n P. Present\n A. Absent\n --.No lecture\n";
							cin>>Temmm->tuse;
							if(Temmm->tuse=="P"||Temmm->tuse=="p")
							{
								counterP++;
							}
							else if(Temmm->tuse=="A"||Temmm->tuse=="a")
							{
								counterA++;
							}
							cout<<"3.Wednesday:\n P. Present\n A. Absent\n --.No lecture\n";
							cin>>Temmm->wed;
							if(Temmm->wed=="P"||Temmm->wed=="p")
							{
								counterP++;
							}
							else if(Temmm->wed=="A"||Temmm->wed=="a")
							{
								counterA++;
							}
							cout<<"4.Thursday:\n P. Present\n A. Absent\n --.No lecture\n";
							cin>>Temmm->thur;
							if(Temmm->thur=="P"||Temmm->thur=="p")
							{
								counterP++;
							}
							else if(Temmm->thur=="A"||Temmm->thur=="a")
							{
								counterA++;
							}
							cout<<"5.Friday:\n P. Present\n A. Absent\n --.No lecture\n";
							cin>>Temmm->fri;
							if(Temmm->fri=="P"||Temmm->fri=="p")
							{
								counterP++;
							}
							else if(Temmm->fri=="A"||Temmm->fri=="a")
							{
								counterA++;
							}
							if(lllast==NULL)
							{
								lllast=hhhead=Temmm;
							}
							else
							{
								lllast->ptr=Temmm;
								lllast=Temmm;
							}
						}
						Temm->A=counterA;
						Temm->P=counterP;
						if(llast==NULL)
						{
							llast=hhead=Temm;
						}
						else
						{
							llast->ptr=Temm;
							llast=Temm;
						}
				}
				if(Last==NULL)
				{
					Head=Last=tem;
				}
				else 
				{
					Last->ptr=tem;
					Last=tem;
				}
				cout<<"Do you want to add attendance of another student (1/0) :";
				cin>>ch;
		}	 
	   }
////////////////////////////////////////////////////////////////////////////////////////////////////	   
	   	else if(choice_stdnt==7)
	   	{
	   		system("cls");
		}
       	else if(choice_stdnt!=7)
	    {
			cout<<"\t\t\t\t\t\tWrong input\n";
			cout<<"\t\t\t\t\t\tPress any key to Go back to continue .............";
			getch(); 
		}
      	}while(choice_stdnt!=7);   	
		}
		else if(ASC==2)
		{
		 system("cls");
		 int Pchoice;
		 do
		 {
		 	system("cls");
		 		system("COLOR 07");
		 	ProfileMenu();
		 	cout<<"Enter your choice: "<<endl;
		 	cin>>Pchoice;
		 	if(Pchoice==1)
		 	{
				{
					system("cls");
					cout<<"Enter Registration number of student :";
					cin>>Reg_No;
					int flag=0;
					tem=head1;	
					while(tem!=NULL)
	        		{
	        			if(tem->Reg_No==Reg_No)
	        	   		{ 
	        			flag=1;
	        			break;
				   		}
				  		else
				  		{ 
						tem=tem->ptr;
				 		} 
					}
					if(flag)
					{
					cout<<"Name of student is :"<<tem->name<<endl;
					cout<<"Registration No of student is:"<<tem->Reg_No<<endl;
					cout<<"Father Name of student is :"<<tem->Fname<<endl;
					cout<<"Address of student is :"<<tem->address<<endl;
					cout<<"Program of student is :"<<tem->program<<endl;
					cout<<"Semester of student is :"<<tem->semester<<endl;
					cout<<"Blood Group of student is :"<<tem->Bld_Grp<<endl;
					cout<<"Date of birth of student is 	:"<<tem->DOB<<endl;
					}
					else
					{
						system("cls");
						cout<<"\n\n\n\n\t\t\t\t\t\tPlease Enter Valid Registration Number: "<<endl;
					}
	    			getch();       	
				}	
			}
			else if(Pchoice==2)
			{
				system("cls");
					system("COLOR 07");
				cout<<"Enter Registration number of student :";
				cin>>Reg_No;
				int flag=0;
					tem=head1;
					temm=head6;
					last6->ptr=NULL;	
					while(tem!=NULL)
	        		{
	        			if(tem->Reg_No==Reg_No)
	        	   		{ 
	        			flag=1;
	        			break;
				   		}
				  		else
				  		{  
					       for(int i=0;i<tem->TS;i++)
					       {
					        	temm=temm->ptr;
					       }
					     
						tem=tem->ptr;
				 		} 
					}
					if(flag)
					{
			   			cout<<"Name :"<<tem->name<<endl;
			   			cout<<"Program :"<<tem->program<<endl;
			   			cout<<"Semester:"<<tem->semester<<endl;
			   			cout<<"Course of "<<tem->name<<" in this semester"<<endl;
			   			cout<<endl;
						cout<<"Subject\t\t\tTotal Credit Hours\n";
			   		    
						for(int i=0;i<tem->TS;i++)
						{
						  cout<<temm->subject<<"\t\t\t"<<temm->total_hour<<endl;
			   			  temm=temm->ptr;	
						}
					}
					else
					{
						system("cls");
						cout<<"\n\n\n\n\t\t\t\tPlease Enter Valid Registration Number: "<<endl;
					}
		
	    			getch();       	
				}
				else if(Pchoice==3)
				{
					system("cls");   
						system("COLOR 07");	
					cout<<"\t\t\t\tOver All ATTENDANCE RECORD\n";
	        		cout<<"Enter Registration number of student :";
					cin>>Reg_No;
					int flag=0;
					tem=head1;
					last1->ptr=NULL;
					temm=head6;
					last6->ptr=NULL;	
					while(tem!=NULL)
	        		{
	        			if(tem->Reg_No==Reg_No)
	        	   		{ 
	        			flag=1;
	        			break;
				   		}
				  		else
				  		{ 
				  		
					       for(int i=0;i<tem->TS;i++)
					       {
					        	temm=temm->ptr;
					       }
					     
						tem=tem->ptr;
				 		} 
					}
					if(flag)
					{
			   			cout<<"Name :"<<tem->name<<endl;
			   			cout<<"Reg.No :"<<tem->Reg_No<<endl;
			   			cout<<"Program :"<<tem->program<<endl;
			   			cout<<"Semester:"<<tem->semester<<endl;
			   			cout<<"Subject\t\t\tTotal classes\t\t\tAttendance\t\t\tPercentage\n";
			   			
						for(int i=0;i<tem->TS;i++)
						{
						  cout<<temm->subject<<"\t\t\t"<<temm->total_class<<"\t\t\t\t"<<(temm->present)<<"\t\t\t\t"<<(((temm->present)*100)/(temm->total_class))<<"%"<<endl;
			   			  temm=temm->ptr;	
						}
					}
					else
					{
						system("cls");
						cout<<"\n\n\n\n\t\t\t\tPlease Enter Valid Registration Number: "<<endl;
					}
	    			getch();       	
				
				}			
				else if(Pchoice==4)
				{
					system("cls");
						system("COLOR 07");
					cout<<"Enter Registration number of student :";
					cin>>Reg_No;
					int flag=0;
					tem=head1;
					temm=head6;
					last6->ptr=NULL;	
					while(tem!=NULL)
	        		{
	        			if(tem->Reg_No==Reg_No)
	        	   		{ 
	        			flag=1;
	        			break;
				   		}
				  		else
				  		{ 
						tem=tem->ptr;
				 		} 
					}
					if(flag)
					{
			   			cout<<"Name  of   student  is :"<<tem->name<<endl;
			   			cout<<"Program of  student is :"<<tem->program<<endl;
			   			cout<<"Semester of student is :"<<tem->semester<<endl;
			   			cout<<"CGPA   of  student  is :"<<tem->CGpa<<endl;
			   			cout<<"SGPA in last  Semester :"<<tem->sgpa<<endl;
					}
					else
					{
						system("cls");
						cout<<"\n\n\n\n\t\t\t\tPlease Enter Valid Registration Number: "<<endl;
					}
	    			getch();       	
				}
///////////////////////////////////////////////////////////////////////////////////////////////////
				else if(Pchoice==5)
				{
					system("cls");
						system("COLOR 07");
					cout<<"Enter Registration number of student :";
					cin>>Reg_No;
					int flag=0;
					tem=Head;
					Temm=hhead;
					Temmm=hhhead;
					Last->ptr=NULL;
					while(tem!=NULL)
	        		{
	        			if(tem->Reg_No==Reg_No)
	        	   		{ 
	        			flag=1;
	        			break;
				   		}
				  		else
				  		{ 
				  			tem=tem->ptr;
				  			for(int i=0;i<tem->TS;i++)
					      	{
					      		for(int i=0;i<Temm->wk;i++)
					       		{	
					        		Temmm=Temmm->ptr;
					       		}
					        	Temm=Temm->ptr;
					       	}
				 		} 
					}
					if(flag)
					{
						cout<<"\t\t\t\tDAILY BASIS ATTENDANCE OF A STUDENT\n\n\n";
			   			cout<<"-----------------------------------------------------\n";
						cout<<"Name  of   student  is :"<<tem->name<<endl;
			   			cout<<"Reg No. of   student  is :"<<tem->Reg_No<<endl;
			   			cout<<"-----------------------------------------------------\n";
						for(int i=0;i<tem->TS;i++)
			   			{
			   			
			   				cout<<"--------------------Subject No."<<i+1<<"-----------------------\n";
							cout<<"Name of Subject is :"<<Temm->subject<<endl;
							cout<<"Day\t\t\t\tPresent/Absent\n";
							for(int j=0;j<Temm->wk;j++)
							{
							cout<<"_________________________Week No."<<j+1<<"______________________"<<endl;	
							cout<<"Monday\t\t\t\t"<<Temmm->mon<<endl;
							cout<<"Tuesday\t\t\t\t"<<Temmm->tuse<<endl;
							cout<<"Wednesday\t\t\t"<<Temmm->wed<<endl;
							cout<<"Thursday\t\t\t"<<Temmm->thur<<endl;
							cout<<"Friday\t\t\t\t"<<Temmm->fri<<endl;
							Temmm=Temmm->ptr;	
							}
							cout<<"-----------------------------------------------------\n";
							cout<<"Total Present\t\t\t:"<<Temm->P<<endl;
							cout<<"Total Absent\t\t\t:"<<Temm->A<<endl;
							Temm=Temm->ptr;	
						}
				
					}
					else
					{
						system("cls");
						cout<<"\n\n\n\n\t\t\t\tPlease Enter Valid Registration Number: "<<endl;
					}
	    			getch();
				}
				else if(Pchoice==6)
				{
					system("cls");
				}
	    		else if(Pchoice!=6)
				{
					system("cls");
					cout<<"\t\t\t\tSorry Invalid input\n";	
	    			getch();
				}
			}while(Pchoice!=6);
		}
		else if(ASC==3)
		{
			system("cls");
			system("COLOR 4f");
		}
		else if(ASC!=3)
		{
			system("cls");
			cout<<"\t\t\t\tSorry Invalid input\n";	
	    	getch();
		}
		}while(ASC!=3);
}
	else if(Condition==5)
	{
		Ch=1;
		do
    	{
    		system("cls");
    		system("COLOR 1f");
    		Lec();
    		cout<<"Enter your choice :";
    		cin>>ch;
    		while(cin.fail())
			{  
				cin.clear();
				cin.ignore(80,'\n');
				cout<<"Sorry You entered invalid choice \n";
				cout<<"Enter valid choice :";
				cin>>ch;
			}
    		if(ch==1)
    		{
    			system("COLOR 70");
	   			do //Inner loop
	   			{
					system("cls");	
					Sub_Menu();
					cout<<"Enter your choice :";
					cin>>choice;
					while(cin.fail())
					{  
						cin.clear();
						cin.ignore(80,'\n');
						cout<<"Sorry You entered invalid choice \n";
						cout<<"Enter valid choice :";
						cin>>choice;
					}
					if(choice==1)
					{
						system("cls");
						staff.Insertion();
					}		 
       				else if(choice==2)
	   				{
	   					system("cls");
	   					staff.Searching();
						getch();			
	 				}
	 				else if(choice==3)
	 				{
	 					system("cls");
	 					staff.PreOrder_Display();
	 					getch();
					}  
					else if(choice==5)
					{
						staff.Deletion();
					}
					else if(choice==6)
					{
						staff.Updation();
					}			
					else if(choice==4)
					{
						system("cls");
						system("COLOR 4f");
					}
        			else 
	    			{
						cout<<"\t\t\tWrong input\n";
						getch(); 
					}
     		 	}while(choice!=4);  
			}
			else if(ch==2)
			{
				system("cls");
				system("COLOR 70");
				do
				{
					system("cls");	
					SubLec();
					cout<<"Enter your choice :";
					cin>>choice;
					while(cin.fail())
					{  
						cin.clear();
						cin.ignore(80,'\n');
						cout<<"Sorry You entered invalid choice \n";
						cout<<"Enter valid choice :";
						cin>>choice;
					}
					if(choice==1)
					{
						system("cls");
						lec.Insertion();
					}
					else if(choice==2)
					{
						system("cls");
						lec.Searching();
					}
					else if(choice==3)
					{
						system("cls");
						lec.Display();
					}
					else if(choice==4)
					{
						system("cls");
						system("COLOR 1f");
					}
					else if(choice==5)
					{
						system("cls");
						lec.Deletion();
					}
				
					else if(choice!=4)
					{
						system("cls");
						cout<<"\n\n\n\n\t\t\t\tSorry Invalid input\n";
					}
				}while(choice!=4);	
			}
			else if(ch!=3)
			{
				system("cls");
				system("COLOR 1f");
				cout<<"\n\n\n\n\t\t\t\tSorry invalid input\n";
			}
			else if(ch==3)
			{
				system("cls");
				system("COLOR 4f");
			}
		}while(ch!=3);
			 	
	}
//Outter Condition
    else if(Condition==6)
    {
    	do
    	{
    		system("cls");
    		system("COLOR 60");
    		ExamMenu();
    		cout<<"Enter your choice: "<<endl;
    		cin>>choice;
    		while(cin.fail())
			{  
				cin.clear();
				cin.ignore(80,'\n');
				cout<<"Sorry You entered invalid choice \n";
				cout<<"Enter valid choice :";
				cin>>choice;
			}
    		if(choice==1)
			{
				flag=0;
    			system("cls");
    			system("COLOR 06");
    			Linkedlist *eXam;
    			do
    			{
    					system("cls");
    					ExamSubMenu();
    					cout<<"Enter your choice :";
    					cin>>ch;
    						while(cin.fail())
							{  
								cin.clear();
								cin.ignore(80,'\n');
								cout<<"Sorry You entered invalid choice \n";
								cout<<"Enter valid choice :";
								cin>>ch;
							}
    						if(ch==1)
    						{
    							if(ex==1)
								{
    							system("cls");
    							cout<<"\t\t\tPlease Enter Examiner Information\n";
    							cout<<"-----------------------------------------------------------------------\n";
    							eXam=new Linkedlist;
    							cout<<"Enter name of Examiner :";
    							cin>>eXam->name;
   								for(int i=0;eXam->name[i]!='\0';i++)   //validation for name
								{
								if(!(isalpha(eXam->name[i])||eXam->name[i]=='.'||isspace(eXam->name[i])))
								{
								cout<<"Sorry You Entered invalid name \n";
								cout<<"Enter valid name :"<<endl;
								cin.ignore();
								cin.getline(eXam->name,50);
								i=0;
								}
								}
    							exam.SetName_of_Person(eXam->name);
    							cout<<"Enter CNIC of Examiner :";
    							cin>>eXam->cnic;
    							for(int i=0;i<eXam->cnic.size();i++)   //validation for CNIC
		    					{
			   						 if(!(isdigit(eXam->cnic[i])||(eXam->cnic[i]=='-')))
									{
					  				cout<<"Sorry You Entered invalid CNIC \n";
					  				cout<<"Enter valid CNIC :";
					  				cin>>eXam->cnic;
								  	i=0;							
									}
								}
    							exam.SetCNIC_of_Ex(eXam->cnic);
    							cout<<"Enter Address of Examiner :";
    							cin>>eXam->address;
    							exam.SetAddress_of_Perosn(eXam->address);
    							cout<<"Enter Monthly pay of Examiner :";
    							cin>>eXam->pay;
    							exam.SetMonthly_Pay(eXam->pay);
    							cout<<"Enter  Date of birth of Examiner :";
    							cin>>eXam->DOB;
    							exam.SetDateOfBirth_of_Person(eXam->DOB);
    							cout<<"Enter Blood Group of Examiner :";
    							cin.ignore();
								cin.getline(eXam->Bld_Grp,15);
    							exam.SetBloodGroup_of_Person(eXam->Bld_Grp);
    							flag=1;
    							ex=0;
								}
								else
								{
									system("cls");
									cout<<"\n\n\n\n\t\t\t\tSorry you cannot enter data because data is already entered\n";
									getch();
								}
						}
							else if(flag==1)
							{
								 if(ch==2)
								{
								system("cls");
								cout<<"\t\tINFORMATION OF KICSIT EXAMINER \n";
								exam.Display_ExaminerInformation();
								getch();
								}	
							}
							else if(flag==0)
							{
								system("cls");
								cout<<"\n\n\n\t\t\tSorry Record is Not Saved\n";
								getch();
							}
							else if(ch==3)
							{
								if(flag==1)
								{
								system("cls");
								cout<<"\t\t\tPLEASE ENTER EXAMINER INFORMATION FOR UPDATION	\n\n";
								cout<<"Enter name of Examiner :";
    							cin>>eXam->name;
   								for(int i=0;eXam->name[i]!='\0';i++)   //validation for name
								{
								if(!(isalpha(eXam->name[i])||eXam->name[i]=='.'||isspace(eXam->name[i])))
								{
								cout<<"Sorry You Entered invalid name \n";
								cout<<"Enter valid name :"<<endl;
								cin.ignore();
								cin.getline(eXam->name,50);
								i=0;
								}
								}
    							exam.SetName_of_Person(eXam->name);
    							cout<<"Enter CNIC of Examiner :";
    							cin>>eXam->cnic;
    							for(int i=0;i<eXam->cnic.size();i++)   //validation for CNIC
		    					{
			   						 if(!(isdigit(eXam->cnic[i])||(eXam->cnic[i]=='-')))
									{
					  				cout<<"Sorry You Entered invalid CNIC \n";
					  				cout<<"Enter valid CNIC :";
					  				cin>>eXam->cnic;
								  	i=0;							
									}
								}
    							exam.SetCNIC_of_Ex(eXam->cnic);
    							cout<<"Enter Address of Examiner :";
    							cin>>eXam->address;
    							exam.SetAddress_of_Perosn(eXam->address);
    							cout<<"Enter Monthly pay of Examiner :";
    							cin>>eXam->pay;
    							exam.SetMonthly_Pay(eXam->pay);
    							cout<<"Enter  Date of birth of Examiner :";
    							cin>>eXam->DOB;
    							exam.SetDateOfBirth_of_Person(eXam->DOB);
    							cout<<"Enter Blood Group of Examiner :";
    							cin.ignore();
								cin.getline(eXam->Bld_Grp,5);
    							for(;;)
								{			
	   								for(int i=0;tem->Bld_Grp[i]!='\0';i++)   //validation for Blood Group
    								{
            						if(!(isalpha(tem->Bld_Grp[i])||tem->Bld_Grp[i]=='+'||(tem->Bld_Grp[i]=='-')))
            						{
    	    						cout<<"Sorry You Entered invalid Blood Group \n";
                					cout<<"Enter valid Blood Group :";
                					//	cin.ignore();
									cin.getline(tem->Bld_Grp,50);
                					i=0;
                					check=1;
                					continue;
            						}
    								}
        							if(check!=1)
        							{		
        								break;
									}
									check=0;
    							}
    							exam.SetBloodGroup_of_Person(eXam->Bld_Grp);
    							flag=1;
    							ex=0;
								cout<<"--------------------------------------------------------------------------\n";	
								}
								else 
								{
									system("cls");
									cout<<"\n\n\n\t\t\tSorry Record is not saved so you cannot update record\n ";
									getch();
								}
							}
							else if(ch==4)
							{
								system("cls");
								system("COLOR 60");
							}
							else
							{
							cout<<"Sorry invalid input\n";
							getch();
						}
				}while(ch!=4);		
			}
    		else if(choice==2)
    		{
    			int ch;
    			do
    			{
    			    system("cls");
    			    DatesheetMenu();
    				cout<<"Enter your choice: "<<endl;
    				cin>>ch;
    				while(cin.fail())
				{	  
				cin.clear();
				cin.ignore(80,'\n');
				cout<<"Sorry You entered invalid choice \n";
				cout<<"Enter valid choice :";
				cin>>ch;
				}
    				if(ch==1)
    				{
    					system("cls");
    					exam.Mid_Term_DateSheet();
						getch();
					}
					else if(ch==2)
					{
						system("cls");
						exam.Final_Term_DateSheet();
			           // cout<<"Press any key to Go back to continue .............";
	    	            getch();
					}
                    else if(ch!=3) 
	                {
		               cout<<"Wrong input\n";
		              // cout<<"Press any key to Go back to continue .............";
		               getch(); 
		            }
				}while(ch!=3);
			}
			else if(choice==3)
			{
				system("cls");
				cout<<"Enter Registration number of student :";
				cin>>Reg_No;
				int flag=0;
					tem=head1;	
					temm=head6;
					while(tem!=NULL)
	        		{
	        			if(tem->Reg_No==Reg_No)
	        	   		{ 
	        			flag=1;
	        			break;
				   		}
				  		else
				  		{ 
				  		
					       for(int i=0;i<tem->TS;i++)
					       {
					        	temm=temm->ptr;
					       }
						tem=tem->ptr;
				 		} 
					}
					if(flag)
					{
						system("cls");
						cout<<"\t\t\t\t----------------------------------------------------------------------\n";
						cout<<"\t\t\t\t|                    RESULT CARD                                     |\n";
						cout<<"\t\t\t\t----------------------------------------------------------------------\n";
					    cout<<"\t\t\t\t______________________________________________________________________\n";
			   			cout<<"\t\t\t\tName   of student is          :"<<tem->name<<endl;
			   			cout<<"\t\t\t\tRegistration No of student is :"<<tem->Reg_No<<endl;
			   			cout<<"\t\t\t\tSemester of student           :"<<tem->semester<<endl;
						cout<<"\t\t\t\tProgram of student            :"<<tem->program<<endl;
						cout<<"\t\t\t\t______________________________________________________________________\n";
						cout<<"\t\t\t\tSubject\t\t\tGrade\n";
						cout<<"\t\t\t\t______________________________________________________________________\n";
						for(int i=0;i<tem->TS;i++)
						{
			   			cout<<"\t\t\t\t"<<temm->subject<<"\t\t\t"<<temm->grade<<endl;
			   			temm=temm->ptr;	
			   			cout<<"\t\t\t\t______________________________________________________________________\n";
						}
			   			cout<<"\t\t\t\tCGPA :"<<tem->CGpa<<endl;
						cout<<"\t\t\t\tSGPA :"<<tem->sgpa<<endl;	
					   	cout<<"\t\t\t\t______________________________________________________________________\n";
			   			cout<<"\t\t\t\t                                                    Approved by :"<<exam.GetName_of_Person()<<endl;
					}
					else
					{
						system("cls");
						cout<<"\n\n\n\n\t\t\t\tPlease Enter Valid Registration Number: "<<endl;
					}
					//cout<<"\t\t\t\tPress any key to Go back to continue .............";
	    			getch();    
				}
				else if(choice==4)
				{
					system("COLOR 0c");
					do  //Inner loop
					{
						system("cls");
    					Sub_GPA();
						cout<<"Enter your choice :";
						cin>>Condition;
						while(cin.fail())
						{  
							cin.clear();
							cin.ignore(80,'\n');
							cout<<"Sorry You entered invalid choice \n";
							cout<<"Enter valid choice :";
							cin>>Condition;
						}
						if(Condition==1)
						{
							do
							{
							system("cls");					
							Sub_ResultMenu();
		    				cout<<"Enter your choice :";
		    				cin>>choice;
							while(cin.fail())
							{  
								cin.clear();
								cin.ignore(80,'\n');
								cout<<"Sorry You entered invalid choice \n";
								cout<<"Enter valid choice :";
								cin>>choice;
							}
		   					if(choice==1)
							{
								system("cls");
								cout<<endl;
								Ch=1;
								while(Ch)
								{
									int j=0;
									cout<<"-----------------------------Student----------------------------\n";
									tem=new Linkedlist;
									cout<<"Enter Name of  Student :";
									cin.ignore();
									cin.getline(tem->name,100);
									for(int i=0;tem->name[i]!='\0';i++)   //validation for name
									{
										if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
										{
											cout<<"Sorry You Entered invalid name \n";
											cout<<"Enter valid name :"<<endl;
											cin.getline(tem->name,50);
											i=0;
										}
									}
									cout<<"Enter Registration Number of student :";
									cin>>tem->Reg_No;
				    				gpa.SetReg(tem->Reg_No);
				    				gpa.SGPA_Calculator(j,tem->name);
				    				tem->gpa=gpa.Final_SGPA();
				    				tem->nam=gpa.Get_Name_of_student();
									j++;
									if(last3==NULL)
									{
					 					head3=last3=tem;	
									} 
									else
									{
										last3->ptr=tem;
										last3=tem;
					 				} 
									cout<<"Do you want to calculate gpa of another student (1/0) :";
									cin>>Ch;
									flag=1;  
								}	
		    				}
		    				else if(choice==2)
							{
								system("cls");
								if(flag==1)
								{
									tem=head3;
									last3->ptr=NULL;
									while(tem!=NULL)
									{
										cout<<"Name of student is "<<tem->name<<endl;
										cout<<"SGPA of "<<tem->name<<" is "<<tem->gpa<<endl;
										tem=tem->ptr;
									}
								//	cout<<"Press any key to Go back to continue .............";
									getch();
								}
								else
								{		
	    							system("cls");
	        						cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	        					//	cout<<"\t\t\tPress any key to Go back to continue .............";
	        						getch();	
								}
							}
							else if(choice==3)
							{
								system("cls");
							}
							else
							{
								cout<<"Invalid input\n";
								//cout<<"Press any key to Go back to continue .............";
								getch(); 
							}
						}while(choice!=3);
					}
    				else if(Condition==2)
					{
						do
						{
							system("cls");
							Sub_ResultMenu();
							cout<<"Enter your choice :";
							cin>>choice;
							while(cin.fail())
							{  
								cin.clear();
								cin.ignore(80,'\n');
								cout<<"Sorry You entered invalid choice \n";
								cout<<"Enter valid choice :";
								cin>>choice;
							}
							if(choice==1)
							{
								system("cls");
								last3=NULL;
								Ch=1;
								while(Ch)
								{
								tem=new Linkedlist;
								cout<<"Enter name of  student : ";
								cin.ignore();
								int k=0;
								cin.getline(tem->name,100);
								for(int i=0;tem->name[i]!='\0';i++)   //validation for name
								{
		    						if(!(isalpha(tem->name[i])||tem->name[i]=='.'||isspace(tem->name[i])))
									{
					    				cout<<"Sorry You Entered invalid name \n";
										cout<<"Enter valid name :"<<endl;
						cin.ignore();
						cin.getline(tem->name,50);
						i=0;
						}
					}    
					cout<<"Enter Registration number of student :";
					cin>>tem->Reg_No;
					gpa.SetReg(tem->Reg_No);
					gpa.CGPA_Calculator(k,tem->name);
					flag=1;
					tem->nam=gpa.Get_Name_of_student();
					tem->cgpa=gpa.final_CGPA();
					if(last4==NULL)
					{
						last4=head4=tem;
					}
					else
					{
						last4->ptr=tem;
						last4=tem;
					}
					k++;
					cout<<"Do you want to calculate CGPA of another student (1/0) :";
					cin>>Ch;
				}
			}
			else if(choice==2)
			{
				system("cls");
				if(flag==1)
				{
				 tem=head4;
				 last4->ptr=NULL;
				while(tem!=NULL)
				{
				cout<<"Name of student is "<<tem->nam<<endl;
				cout<<"CGPA of"<<tem->nam<<" is "<<tem->cgpa<<endl;
				tem=tem->ptr;	
				}	
				///cout<<"Press any key to Go back to continue .............";
				getch();
				}
			else
			{
			system("cls");
	       	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSorry Record not saved \n";
	       // cout<<"\t\t\tPress any key to Go back to continue .............";
	        getch();	
				}
			}
			else if(choice==3)
			{
				system("cls");
			}
		}while(choice!=3);
	}	
	else if(Condition==3)
	{
		system("cls");

	}
	else
	{
		cout<<"Invalid input";
		//cout<<"Press any key to Go back to continue .............";
	getch();
			}
			}while(Condition!=3);
	}
	else if(choice==5)
	{
		system("cls");
		system("COLOR 4f");
	}
    else if(choice!=5) 
	{
		cout<<"Wrong input\n";
	    //cout<<"Press any key to Go back to continue .............";
        getch(); 
	 }
		}while(choice!=5);
		system("cls");
	}
	else if(Condition!=20)
	{
		cout<<"Invalid input\n";
		//cout<<"Press any key to Go back to continue .............";
	getch(); 
	}
	
	else if(Condition==20)
	{
		system("cls");
		system("COLOR 4f");
	}
  }while(Condition!=20);//End of outter loop	
}
else if(CCCHHH==2)
{
	system("cls");
	system("COLOR 2f");
	Help();
	getch();
}
else if(CCCHHH==3)
{
	system("cls");
	system("COLOR 5f");
	cout<<"\n\n\n\n\n\n\t\t\t\t\tThank you so much for using this software\n";
	getch();
}
else if(CCCHHH!=3)
{
	system("cls");
	cout<<"Sorry Invalid Input\n";
}
}while(CCCHHH!=3);

  return 0;
}
