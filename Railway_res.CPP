#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<fstream.h>
#include<stdio.h>

class ticket
{
    long pnrno;
    char trainname[50];
    char pname[20];
    char board[10];
    char dest[10];
    char date[10];

public:
    
    void create();
    void modify();
    void display();
    void del();

int getpnrno();
}t1;


void main()
{
    clrscr();
    int ch;
    while(1)
    {
        clrscr();
        //main menu starts
        cout<<"\n ====================================================================";
        cout<<"\n ****           WELCOME TO TICKET RESERVATION SYSTEM             ****";
        cout<<"\n ====================================================================";
        cout<<"\n\t [ A PROGRAM BY ADITYA DEWANI AND ASHWINEE BHATT ]";
        cout<<"\n\n\n";
        cout<<"\n\n\t            **** MAIN MENU ****";
        cout<<"\n\n\t  1 - CREATE A NEW TICKET";
        cout<<"\n\n\t  2 - DISPLAY AN ALREADY EXISTING TICKET";
        cout<<"\n\n\t  3 - DELETE AN ALREADY EXISTING TICKET";
        cout<<"\n\n\t  4 - MODIFY AN ALREADY EXISTING TICKET";
        cout<<"\n\n\t  0 - QUIT";
        cout<<"\n\n";
        cout<<"\n======================================================================";

        cout<<"\n\n\t ENTER YOUR CHOICE";
        cin>>ch;

        switch(ch)
        {
           
	    case(1):t1.create();
	    break;

	    case(2):t1.display();
	    break;

	    case(3):t1.del();
	    break;

	    case(4):t1.modify();
	    break;

	    case(0):clrscr();

            cout<<"\n **********************************************************";
	    cout<<"\n theis program is created by aditya dewani and ashwinee bhatt";

	    getch();
	    exit(0);
            
       }
   }
getch();
return;
}



//function to create the record(ticket)

void ticket::create()
{
    
    int choice=1;
    fstream f;
    f.open("ticket.dat",ios::app);
    if(!f)
    {
	cout<<"\n unable to open the file";
	getch();
	return;
    }
    
    while(choice!=0)
    {

	clrscr();
	cout<<"\n=====================================================================";
	while(1)
	{
	  cout<<"\n\t ENTER THE PNR NUMBER";
	  cin>>t1.pnrno;
          if(strlen(t1.pnrno)!==0)
              break;
          else
          cout<<"\n pnr number cannot beleft blank";
        while(1)
        {
             cout<<"\n ENTER THE TRAIN NAME ";
             gets(t1.trainname);
             if(strlen(t1.trainname)!==0)
                  break;
             else
                  cout<<"\n train name cannot ne left blank";
         }
	  
         while(1)
         {
	     cout<<"\n\t enter the passanger name ";
	     gets(t1.pname);
	     if(strlen(pname)!=0)
	     break;
           else
	      cout<<"\n passanger name cannot be left blank";
          }

	  while(1)
	  {
	      cout<<"\n enter the name of boarding point";
	      gets(t1.board);
	      if(t1.board!=0)
	      break;
	      else
	      cout<<"\n boarding point cannot be left blank";
	  }

	  while(1)
	  {
	    cout<<"\n enter the destination";
	    gets(t1.dest);
	    if(t1.board!=0)
	    break;
	    else;
	    cout<<"\n destination cannot be left blank";
	  }

	  while(1)
	  {
	    cout<<"\n enter the date of journey (ddmmyyyy)";
	    gets(t1.date);
	    if(t1.date!=0)
	    break;
	    else
	    cout<<"\n date cannot be left blank";
	  }

	  cout<<"\n 1:save and exit 2:save and continue 0:exit without saving ";
	  cout<<"?";
	  cin>>choice;

	  switch(choice)
	  {
	    case('1'):f.write((char*)&t1,sizeof(t1));
	    f.close();
	    return;

	    case('2'):f.write((char*)&t1,sizeof(t1));
	    break;

	    case('3'):f.close();
	    return;

	    default: f.close();
	    return;
	  }
	}
    }
}

//function to display an already existing tickit

void ticket::display()
{
     long pnr;
     int choice=1;
     char found='n';
     fstream f;
     if(!f)
     {
         f.open("ticket.dat",ios::in);
         cout<<"\n unable to open the file";
         getch();
	 f.close();
	 return;
     }
     while(choice==1)
     {
	 clrscr();
         f.open("ticket.dat",ios::in);
	 while(!f.eof())
     {
		  clrscr();
		  cout<<"\n please enter the pnr number";
		  cin>>pnr;
		  f.read((char*)&t1,sizeof(t1));
		  if(pnr==t1.getpnrno())
		  {
		    clrscr();
		    found='y';
		    cout<<"\n\n===============================================================";
		    cout<<"\n\n";
		    cout<<"\n\t  PNR NUMBER =="<<t1.pnrno;
		    cout<<"\n\t  TRAIN NAME=="<<puts(t1.trainname);
		    cout<<"\n\t  PASSANGER NAME =="<<puts(t1.pname);
		    cout<<"\n\t  BOARDING POINT =="<<puts(t1.board);
		    cout<<"\n\t  DESTINATION =="<<puts(t1.dest);
		    cout<<"\n\t  DATE OF JOURNEY =="<<puts(t1.date);
		    cout<<"\n\n";
		    cout<<"\n\n================================================================";
		  }
		  f.read((char*)&t1,sizeof(t1));
		}
		if(found=='n')
		cout<<"\n record not found";

		cout<<"\n\n  1:continue   2:exit";
		cout<<"?";
		cin>>choice;
		switch(choice)
		{
		  case 1:f.close();
		  break;
		  case 2:f.close();
		  return;
		  default:return;
		}
	      }
	   }


//function to delete an already existing ticket

	   void ticket::del()
	   {
	     clrscr();
	     ifstream fi("ticket.dat",ios::in);
	     ofstream fo("temp.dat",ios::out);
	     long pnr;
	     char found='f',confirm='n';
	     cout<<"\n\n\n\n";
	     cout<<"******************************************************************";

	     cout<<"\n enter the pnr number :";
	     cin>>pnr;
	     while(!fi.eof())
	     {
	       fi.read((char*)&t1,sizeof(t1));

	       if(pnr==t1.getpnrno())
	       {
		 cout<<"\n the ticket you want to delete is:";
		 cout<<"\n\n\n";
		 cout<<"===================================================================";
		 cout<<"\n\t  PNR NUMBER =="<<t1.pnrno;
		 cout<<"\n\t  TRAIN NAME=="<<puts(t1.trainname);
		 cout<<"\n\t  PASSANGER NAME =="<<puts(t1.pname);
		 cout<<"\n\t  BOARDING POINT =="<<puts(t1.board);
		 cout<<"\n\t  DESTINATION =="<<puts(t1.dest);
		 cout<<"\n\t  DATE OF JOURNEY =="<<puts(t1.date);
		 cout<<"\n\n";
		 cout<<"\n\n================================================================";

		 found='t';
		 cout<<"\n are you sure you want to delete this ticket ?(y/n)";
		 cin>>confirm;

		if(confirm=='y'||confirm=='Y')
		fo.write((char*)&t1,sizeof(t1));
		else
		break;
	     }
	      else
	      fo.write((char*)&t1,sizeof(t1));
	      cout<<"\n the ticket not found";
	   }
	   if(found=='f')
	   cout<<"\n ticket not found";
	   fi.close();
	   fo.close();

	   remove("ticket.dat");
	   rename("temp.dat","ticket.dat");

	   }

//function to modify an already existing ticket


	   void ticket::modify()

	  {
	    char ch;
	    long pnr;
	    int no;
	    fstream tp,f;
	    f.open("ticket.dat",ios::in);

	    if(!f)
	    {
	      cout<<"\n unable to open the ticket";
	      getch();
	      f.close();
	      return;
	    }

	    tp.open("temp.dat",ios::out);

	    clrscr();
	    cout<<"\n\n\n";
	    cout<<"=================================================================";
	    cout<<"\n\t enter the pnr number on ticket to be modified";
	    cin>>pnr;

	    int found=0;
	    while(f.read((char*)&t1,sizeof(t1)))
	    {
	      if(pnr==t1.getpnrno())
	      {
		found=1;

		cout<<"\n the ticket which you want to modify is ";
		cout<<"==================================================================";
		cout<<"\n\t  PNR NUMBER =="<<t1.pnrno;
		cout<<"\n\t  TRAIN NAME=="<<puts(t1.trainname);
		cout<<"\n\t  PASSANGER NAME =="<<puts(t1.pname);
		cout<<"\n\t  BOARDING POINT =="<<puts(t1.board);
		cout<<"\n\t  DESTINATION =="<<puts(t1.dest);
		cout<<"\n\t  DATE OF JOURNEY =="<<puts(t1.date);
		cout<<"\n\n";
		cout<<"\n\n================================================================";
		cout<<"\n\n are you sure you want to modify this ticket ? (y/n)";
		cin>>ch;
		if(ch=='Y'||ch=='y')
		{
		  clrscr();
		  cout<<" \n enter the details of the new ticket";
		  cout<<"\n\n ===========================================================";
		  cout<<"\n enter the new pnr no ==";
		  cin>>t1.pnrno;
		  cout<<"\n enter the new train name ==";
		  gets(t1.trainname);
		  cout<<"\n enter the new passanger name  ==";
		  gets(t1.pname);
		  cout<<"\n enter the new boarding point ==";
		  gets(t1.board);
		  cout<<"\n enter the new destination ";
		  gets(t1.dest);
		  cout<<"\n enter the new date(ddmmyyyy)";
		  gets(t1.date);

		  while(no!=0)
		  {
		    clrscr();

		    cout<<"\n\n\n the modified pay slip is:";
		    cout<<"==================================================================";
		    cout<<"\n\t  PNR NUMBER =="<<t1.pnrno;
		    cout<<"\n\t  TRAIN NAME=="<<puts(t1.trainname);
		    cout<<"\n\t  PASSANGER NAME =="<<puts(t1.pname);
		    cout<<"\n\t  BOARDING POINT =="<<puts(t1.board);
		    cout<<"\n\t  DESTINATION =="<<puts(t1.dest);
		    cout<<"\n\t  DATE OF JOURNEY =="<<puts(t1.date);
		    cout<<"====================================================================";
		    cout<<"\n\n\n\n press 0 to exit";
		    cin>>no;
		    if(no==0)
		    break;
		 }
	      }
	   }
	   tp.write((char*)&t1,sizeof(t1));
	   break;
	 }
	 f.close();
	 tp.close();
	 if(ch=='N'||ch=='n')
	 return;

	 if(!found)
	 {
	   cout<<"\n\n ticket not found..";
	   getch();
	   return;
	 }

	 f.open("ticket.dat",ios::out);
	 tp.open("temp.dat",ios::in);
	 while(tp.read((char*)&t1,sizeof(t1)))
	 f.write((char*)&t1,sizeof(t1));;
	 f.close();
	 tp.close();
      }
      ticket::getpnrno()
      {
	return 0;
      }
//end of program