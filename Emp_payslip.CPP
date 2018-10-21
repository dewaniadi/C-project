//a program for creating and processing pay slips of employess

#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<ctype.h>
#include<fstream.h>


// class employe

class employe
{
int empcd;
char name[50];
char desig[50];
int basic;
int hra;
int da;
int pf;
int net;
public :

void append();

void display();

void del();

void modify();

void calc()
{

hra = 0.1*basic;

da  = 0.8*basic;

pf  = 0.4*basic;

net = basic+hra+da-pf;
}

int getempcd()

{
return empcd;
}
}e1;

void main()

{

int ch;

char ch1;

while(1)
{
clrscr();

// main menu starts

cout<<"\n********************************************************************************";

cout<<"\n\t\tWELCOME TO EMPLOYEE SALARY CREATION PROGRAM    ";

cout<<"\n================================================================================";

cout<<"\n\t\t [ PROGRAM BY ASHISH SHARMA AND DEVANSH DUBEY ]   ";
cout<<"\n\n\n\n";
cout<<"\t\t  =================MAIN MENU==================  ";
cout<<"\n\n ";

cout<<"\n\n\t    1 : CREATE A NEW PAY SLIP ";

cout<<"\n\n\t    2 : VIEW AN ALREADY EXISTING PAY SLIP ";

cout<<"\n\n\t    3 : DELETE AN ALREADY EXISTING PAY SLIP ";

cout<<"\n\n\t    4 : MODIFY AN ALREADY EXISTING PAY SLIP ";

cout<<"\n\n\t    0 : QUIT";
cout<<"\n================================================================================";
cout<<"\n\t Enter your Choice :";
cin>>ch;


switch(ch)

{
case (1) :e1.append();
	      break;
case (2) :e1.display();
	      break;
case (3) :e1.del();
	      break;
case (4) :e1.modify();
	      break;
case (0) :clrscr();

cout<<"\n################################################################################";
cout<<"\n\t    This program is created by Ashish Sharma & Devansh Dubey ";
cout<<"\n################################################################################";
getch();

exit(0);
     }
  }
}
// function to create or append the records (ie. Payslips )

void employe :: append()
{
char choice;
fstream f;
f.open("emp.dat",ios::app);
if (!f)
{
cout<<"\n Unable to open file";
getch();
return;
}

while(choice!=0)
{
clrscr();
cout<<"\n ===============================================================================";

while(1)
{
cout<<"\n\t ENTER THE EMPLOYEE CODE  ";
cin>>e1.empcd;
cout<<"\n\t ENTER THE NAME  ";
gets(e1.name);
if(strlen(e1.name)==0)

cout<<"\n\n\tName cannot be left blank\a\a";
else
break;}

while(1)
{
cout<<"\n\t ENTER THE DESIGNATION ";

gets(e1.desig);
if(strlen(desig)!=0)
break;}

while(1)
{
cout<<"\n\t ENTER THE BASIC PAY   ";
cin>>e1.basic;
if(e1.basic!=0)
break;
else
{
cout<<"\n\n\t basic pay cannot be left blank";
     }
}

cout<<"\n 1 : Save & Exit     2 : Save &coutinue    0 : Exit without save";
cout<<"? ";
cin>>choice;
switch(choice)
{
case ('1'): f.write((char*)&e1,sizeof(employe ));
	       f.close();
	       return;
case ('2'): f.write((char*)&e1,sizeof(e1));
	       break;
case ('0'): f.close();
	       return;
default:    f.close();
return;
	      }
       }
}

//function to display an already existing pay slip

void employe::display()
{
int emp ;
int choice=1;
char found='n';
fstream f;

if (!f)
{
f.open ("emp.dat",ios::in);
cout<<"unable to open a file";
getch();
f.close();
return;
}

while(choice==1)

{
clrscr();
f.open("emp.dat",ios::in);
while(!f.eof())
{clrscr();
cout<<"Please enter the employee code ";
cin>>emp;
f.read((char*)&e1,sizeof(e1));
if(e1.getempcd()==emp)
{
clrscr();
found='y';

cout<<"\n\n\n============================================================================";
cout<<"\n\n";
cout<<"\n\t    EMPLOYEE CODE               =="<<e1.empcd;
cout<<"\n\t    THE NAME OF THE EMPLOYEE    ==";
puts(e1.name);
cout<<"\n\t    DESIGNATION OF THE EMPLOYEE ==";
puts(e1.desig);
cout<<"\n\t    BASIC SALARY                =="<<e1.basic;
e1.calc();
cout<<"\n\t    HRA                         =="<<e1.hra;
cout<<"\n\t    DA                          =="<<e1.da;
cout<<"\n\t    PF                          =="<<e1.pf;
cout<<"\n\t    NET SALARY                  =="<<e1.net;

cout<<"\n\n==============================================================================";
}
f.read((char*)&e1,sizeof(e1));
}
if(found=='n')
cout<<"\n RECORD NOT FOUND...!!";
cout<<"\n\n1 : Cont.    0: Exit";
cout<<"?";
cin>>choice;
switch(choice)
{
case(1):f.close();
break;
case(0):f.close();
return;

default:return;
}

}



}




//function to delete an already existing pay slip


void employe::del()
{  clrscr();
ifstream fi("emp.dat",ios::in);
ofstream fo("temp.dat",ios::out);
int emp;
char found='f',confirm='n';
cout<<"\n\n\n\n";
cout<<"****************************************************************************";

cout<<"\n ENTER THE EMPLOYEE CODE :";
cin>>emp;
while(!fi.eof())
{
fi.read((char*)&e1,sizeof(e1));
if(e1.getempcd()==emp)
{ cout<<"\n\n THE EMPLOYEE SLIP YOU WANT TO DELETE IS :";
cout<<"\n\n\n";
cout<<"===============================================================================";
cout<<"\n\t     EMPLOYEE CODE    =="<<emp;
cout<<"\n\t     NAME             ==";
puts(e1.name);
cout<<"\n\t     DESIGNATION      ==";
puts(e1.desig);
cout<<"\n\t     BASIC PAY        =="<<e1.basic;
e1.calc();
cout<<"\n\t	HRA              =="<<e1.hra;
cout<<"\n\t	DA               =="<<e1.da;
cout<<"\n\t 	PF               =="<<e1.pf;
cout<<"\n\t 	NET SALARY       =="<<e1.net;
cout<<"\n\n";
cout<<"==============================================================================";
found='t';
cout<<"\n ARE YOU SURE YOU WANT TO DELETE THIS PAY SLIP ? (Y/N) ";
cin>>confirm;

if(confirm=='y'||confirm=='Y')
fo.write((char*)&e1,sizeof(e1));
else
break;
}
else
fo.write((char*)&e1,sizeof(e1));
cout<<"\n record not found";
delay(500);
}

if (found=='f')
cout<<"\n\ record not found";
fi.close();
fo.close();
remove("emp.dat");
rename("temp.dat","emp.dat");

}

//function to modify an already existing pay slip

void employe::modify()
{
char ch;
int emp,no;
fstream tp,f;
f.open("emp.dat",ios::in);
if (!f)
{
cout<<"\n Unable to open pay slip file";
getch();
f.close();
return;
}
tp.open("temp.dat",ios::out);
if (!tp)
{
cout<<"\n Unable to open Temporary file";
getch();
return;

}
clrscr();
cout<<"\n\n\n";
cout<<"==============================================================================";
cout<<"\n\t ENTER THE EMPLOYEE CODE ON THE PAY SLIP TO BE MODIFIED : ";
cin>>emp;
int found=0;

while(f.read ((char*)&e1,sizeof(e1)))
{
if(e1.getempcd()==emp)
{
found =1;
cout<<"\n\n\n   THE PAY SLIP WHICH YOU WANT TO MODIFY  IS ";

cout<<"\n\n\n";
cout<<"\n==============================================================================";
cout<<"\n\t   EMPLOYE CODE =="<<e1.empcd;
cout<<"\n\t   NAME         ==";
puts(e1.name);
cout<<"\n\t   DESIGNTION   ==";
puts(e1.desig);
cout<<"\n\t   BASIC PAY    =="<<e1.basic;
e1.calc();
cout<<"\n\t   HRA          =="<<e1.hra;
cout<<"\n\t   DA           =="<<e1.da;
cout<<"\n\t   PF           =="<<e1.pf;
cout<<"\n\t   NET SALARY   =="<<e1.net;
cout<<"\n\n";
cout<<"================================================================================";
cout<<"\n\n are you sure you want to Modify this record (Y/N)";
cin>>ch;
if(toupper(ch) =='y')
{
clrscr();
cout<<"\n       ENTER THE DETAILS OF NEW PAY SLIP  ";
cout<<"\n\n  ===========================================================================";
cout<<"\n\n 	ENTER THE NEW NAME ==";
gets(e1.name);
cout<<"\n       ENTER THE NEW DESIGNTION ==";
gets(e1.desig);
cout<<"\n      ENTER THE NEW BASIC SALARY ==";
cin>>e1.basic;


while(no!=0)
{
clrscr();
cout<<"\n\n\n   THE MODIFIED PAY SLIP IS :";
cout<<"\n ==============================================================================";
cout<<"\n\t 	EMPLOYEE CODE =="<<emp;
cout<<"\n\t 	NAME          ==";
puts(e1.name);
cout<<"\n\t     DESIGNTION    ==";
puts(e1.desig);
cout<<"\n\t     BASIC PAY     =="<<e1.basic;
e1.calc();
cout<<"\n\t 	HRA           =="<<e1.hra;
cout<<"\n\t 	DA            =="<<e1.da;
cout<<"\n\t 	PF            =="<<e1.pf;
cout<<"\n\t 	NET SALARY    =="<<e1.net;
cout<<"\n\n";
cout<<"    ==========================================================================";
cout<<"\n\n\n\n\n PRESS 0 TO EXIT";
cin>>no;
if(no==0)
break;
	    }
	       }
		 }
tp.write((char*)&e1,sizeof(e1));
	 }
f.close();
tp.close();
if(toupper(ch)=='N')
return;

if(!found)
{
cout<<"\n\n   PAY SLIP NOT FOUND..!!";
getch();
return;
}
f.open("emp.dat",ios::out);
tp.open("emp.dat",ios::out);
while(tp.read((char*)&e1,sizeof(e1)))
f.write((char*)&e1,sizeof(e1));
f.close();
tp.close();
}
