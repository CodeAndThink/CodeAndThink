#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<fstream>
#include<string.h>
#include<conio.h>
#include <sstream>

using namespace std;

class Lib
{
   	public:  		
       	char bookname[100],auname[50],sc[20],sc1[50];
       	int q,B,p;
       	Lib()
       	{
           	strcpy(bookname,"NO Book Name");//copy
           	strcpy(auname,"No Author Name");
           	strcpy(sc,"No Book ID");
           	strcpy(sc1,"No Publication name");
           	q=0;
           	B=0;
           	p=0;
       	}
	        void get();
	        void student();
	        void pass();
	        void librarian();
	        void password();
	        void getdata();
	        void show(int);
	        void booklist(int);
	        void modify();
	        void see(int);
	        int branch(int);
	        void issue();
	        void der(char[],int,int);
	        void fine(int,int,int,int,int,int);
			void listStuOrder();
			void OutOrder();
};
	         
void Lib::getdata()//add more book data 
{
    int i;
    fflush(stdin);
    cout<<"\n\t\tEnter the details :-\n";
    cout<<"\n\t\tEnter Book's Name : ";
    cin.getline(bookname,100);
    for(i=0;bookname[i]!='\0';i++)
    {
    if(bookname[i]>='a'&&bookname[i]<='z')
        bookname[i]-=32;
    }
    cout<<"\n\t\tEnter Author's Name : ";
    cin.getline(auname,50);
    cout<<"\n\t\tEnter Publication name : ";
    cin.getline(sc1,50);
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(sc,20);
    cout<<"\n\t\tEnter Book's Price : ";
    cin>>p;
    cout<<"\n\t\tEnter Book's Quantity : ";
	cin>>q;
}
void Lib::show(int i)//display all book data(if i = 1: display for student, if i = 2: display for librian)
{
    cout<<"\n\t\tBook Name : "<<bookname<<endl;
    cout<<"\n\t\tBook's Author Name : "<<auname<<endl;
    cout<<"\n\t\tBook's ID : "<<sc<<endl;
    cout<<"\n\t\tBook's Publication : "<<sc1<<endl;
    if(i==2)
    {
        cout<<"\n\t\tBook's Price : "<<p<<endl;
        cout<<"\n\t\tBook's Quantity : "<<q<<endl;
    }
}
void Lib::booklist(int i)//display all book data
{
    int b,r=0;
    system("cls");
    b=branch(i);
    system("cls");
    ifstream intf("Booksdata.txt",ios::binary);
    if(!intf)
        cout<<"\n\t\tFile Not Found.";
    else
    {
        cout<<"\n\t    ************ Book List ************ \n\n";
        intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
                {
                    if(b==B)
                    {
                        if(q==0 && i==1)
                        {

                        }
                        else
                            {
                                r++;
                                cout<<"\n\t\t********** "<<r<<". ********** \n";
                                show(i);
                            }
                    }
                    intf.read((char*)this,sizeof(*this)); 
                }
        }
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    if(i==1)
        student();
    else
        librarian();
    }
void Lib::modify()//adding, rewrite book information, delete book
{
    char ch,st1[100];
    int i=0,b,cont=0;
    system("cls");
    cout<<"\n\t\t>>Please Choose one option :-\n";
    cout<<"\n\t\t1.Modification In Current Books\n\n\t\t2.Add New Book\n\n\t\t3.Delete A Book\n\n\t\t4.Go back\n";
    cout<<"\n\n\t\tEnter your choice : ";
    cin>>i;
    if(i==1)
    {
                    system("cls");
                    b=branch(2);//choose the book branch
                    ifstream intf1("Booksdata.txt",ios::binary);//open file too read
                    if(!intf1)
                    {
                        cout<<"\n\t\tFile Not Found\n";
                        cout<<"\n\t\tPress any key to continue.....";
                        getch();
                        system("cls");
                        librarian();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tPlease Choose One Option :-\n";
                        cout<<"\n\t\t1.Search By Book Name\n\n\t\t2.Search By Book's ID\n";
                        cout<<"\n\t\tEnter Your Choice : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tEnter Book Name : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&bookname[i]!='\0'&&st1[i]!='\0'&&(st1[i]==bookname[i]||st1[i]==bookname[i]+32);i++);//check bookname
                                        if(bookname[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                                     intf.read((char*)this,sizeof(*this));
                                    }
                                    intf.close();
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tEnter Book's ID : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())//read until end of file
                                    {
                                        for(i=0;b==B&&sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);//check book ID
                                        if(sc[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                        intf.read((char*)this,sizeof(*this));
                                    }

                                intf.close();
                        }
                        else
                        {
                            cout<<"\n\t\tIncorrect Input.....:(\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tBook Not Found.\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        else
                            cout<<"\n\t\tUpdate Successful.\n";


    }
    else if(i==2)
    {
                    system("cls");
                    B=branch(2);//choose branch for book
                    system("cls");
                    getdata();
                    ofstream outf("Booksdata.txt",ios::app|ios::binary);
                    outf.write((char*)this,sizeof(*this));
                    outf.close();
                    cout<<"\n\t\tBook added Successfully.\n";
    }
    else if(i==3)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("Booksdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tFile Not Found\n";
                        cout<<"\n\t\tPress any key to continue.....";
                        getch();
                        intf1.close();
                        system("cls");
                        librarian();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tPlease Choose One Option for deletion:-\n";
                        cout<<"\n\t\t1.By Book Name\n\n\t\t2.By Book's ID\n";
                        cout<<"\n\t\tEnter Your Choice : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tEnter Book Name : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Booksdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&bookname[i]!='\0'&&st1[i]!='\0'&&(st1[i]==bookname[i]||st1[i]==bookname[i]+32);i++);
                                        if(bookname[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));

                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }

                    intf.close();
                    outf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tEnter Book's ID : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Booksdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
                                        if(sc[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));
                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }
                    outf.close();
                    intf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");
                        }
                        else
                        {
                            cout<<"\n\t\tIncorrect Input.....:(\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tBook Not Found.\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        else
                            cout<<"\n\t\tDeletion Successful.\n";

    }
    else if(i==4)
    {
    system("cls");
    librarian();
    }
    else
    {
    cout<<"\n\t\tWrong Input.\n";
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    modify();
    }
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    librarian();
  }
int Lib::branch(int x)//branch of book
{
      int i;
      cout<<"\n\t\t>>Please Choose one Branch :-\n";
      cout<<"\n\t\t1.Class 10th\n\n\t\t2.Class 11th\n\n\t\t3.Class 12th\n\n\t\t4.Go to menu\n";
      cout<<"\n\t\tEnter youur choice : ";
      cin>>i;
      switch(i)
      {
          case 1: return 1;
                  break;
          case 2: return 2;
                  break;
          case 3: return 3;
                  break;
          case 4: system("cls");
                  if(x==1)
                  	student();
                  else
                    librarian();
          default : cout<<"\n\t\tPlease enter correct option :(";
                    getch();
                    system("cls");
                    branch(x);
        }
}
void Lib::see(int x)//search book
{
      int i,b,cont=0;
      char ch[100];
      system("cls");
      b=branch(x);
      ifstream intf("Booksdata.txt",ios::binary);
        if(!intf)
        {
            cout<<"\n\t\tFile Not Found.\n";
            cout<<"\n\t\t->Press any key to continue.....";
            getch();
            system("cls");
            if(x==1)
            student();
            else
            librarian();
        }

      system("cls");
      cout<<"\n\t\tPlease Choose one option :-\n";
      cout<<"\n\t\t1.Search By Name\n\n\t\t2.Search By Book's ID\n";
      cout<<"\n\t\tEnter Your Choice : ";
      cin>>i;
      fflush(stdin);
      intf.read((char*)this,sizeof(*this));
      if(i==1)
      {
          cout<<"\n\t\tEnter Book's Name : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
            for(i=0;b==B&&q!=0&&bookname[i]!='\0'&&ch[i]!='\0'&&(ch[i]==bookname[i]||ch[i]==bookname[i]+32);i++);
            if(bookname[i]=='\0'&&ch[i]=='\0')
                {
                        cout<<"\n\t\tBook Found :-\n";
                        show(x);
                        cont++;
                        break;
                }
             intf.read((char*)this,sizeof(*this));
          }
      }
          else if(i==2)
          {
          cout<<"\n\t\tEnter Book's ID : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
              for(i=0;b==B&&q!=0&&sc[i]!='\0'&&ch[i]!='\0'&&ch[i]==sc[i];i++);
              if(sc[i]=='\0'&&ch[i]=='\0')
                {
                            cout<<"\n\t\tBook Found :-\n";
                            show(x);
                            cont++;
                            break;
                }
               intf.read((char*)this,sizeof(*this));
          }

          }
          else
          {
             cont++;
             cout<<"\n\t\tPlease enter correct option :(";
             getch();
             system("cls");
             see(x);
          }
          intf.close();
          if(cont==0)
              cout<<"\n\t\tThis Book is not available :( \n";

    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    if(x==1)
    student();
    else
    librarian();


}
void Lib::issue()//borrow book
{
	char st[50],st1[20];
    int b,i,j,d,m,y,dd,mm,yy,cont=0;
    do{ 
		   	
    	system("cls");
	    cout<<"\n\t\t->Please Choose one option :-\n";
	    cout<<"\n\t\t1.Issue Book\n\n\t\t2.View Issued Book\n\n\t\t3.Search student who issued books\n\n\t\t4.Reissue Book\n\n\t\t5.Return Book\n\n\t\t6.Go back to menu\n\n\t\tEnter Your Choice : ";
	    cin>>i;
	    fflush(stdin);
    	switch(i){
    		case 1:
    		{
    			system("cls");
			    b=branch(2);
			    system("cls");
			    fflush(stdin);
			    cout<<"\n\t\t->Please Enter Details :-\n";
			    cout<<"\n\t\tEnter Book Name : ";
			    cin.getline(bookname,100);
			    cout<<"\n\t\tEnter Book's ID : ";
			    cin.getline(sc,20);
			    //strcpy(st,sc);
			    der(sc,b,1);
			    cout<<"\n\t\tEnter Student Name : ";
			    cin.getline(auname,100);
			    cout<<"\n\t\tEnter Student's ID : ";
			    cin.getline(sc1,20);
			    cout<<"\n\t\tEnter date : ";
			    cin>>q>>B>>p;
			    ofstream outf("student.txt",ios::binary|ios::app);
			    outf.write((char*)this,sizeof(*this));
			    outf.close();
			    cout<<"\n\n\t\tIssue Successfully.\n";
			    getch();
			    break;
			}	
			case 2:
			{
				ifstream intf("student.txt",ios::binary);
			    system("cls");
			    cout<<"\n\t\t->The Details are :-\n";
			    intf.read((char*)this,sizeof(*this));
			    i=0;
			    while(!intf.eof())
			    {
			    i++;
			    cout<<"\n\t\t********** "<<i<<". ********** \n";
			    cout<<"\n\t\tStudent Name : "<<auname<<"\n\t\t"<<"Student's ID : "<<sc1<<"\n\t\t"<<"Book Name : "<<bookname<<"\n\t\t"<<"Book's ID : "<<sc<<"\n\t\t"<<"Date : "<<q<<"/"<<B<<"/"<<p<<"\n";
			    intf.read((char*)this,sizeof(*this));
			    }
			    intf.close();
			    cout<<"\n\n\t\tEnter any key to return...";
				getch(); 
			    break;
			}	
			case 3:
			{
				system("cls");
		        fflush(stdin);
		        cout<<"\n\t\t->Please Enter Details :-\n";
		        cout<<"\n\n\t\tEnter Student Name : ";
		        cin.getline(st,50);
		        cout<<"\n\n\t\tEnter Student's ID : ";
		        cin.getline(st1,20);
		        system("cls");
		        ifstream intf("student.txt",ios::binary);
		        intf.read((char*)this,sizeof(*this));
		        cont=0;
		        while(!intf.eof())
		        {
		              for(i=0;sc1[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc1[i];i++);
		              if(sc1[i]=='\0'&&st1[i]=='\0')
		              {
		                  cont++;
		                  if(cont==1)
		                  {
		                      cout<<"\n\t\t->The Details are :-\n";
		                      cout<<"\n\t\tStudent Name : "<<auname;
		                      cout<<"\n\t\tStudent's ID : "<<sc1;
		                  }
		                  cout<<"\n\n\t\t******* "<<cont<<". Book details *******\n";
		                  cout<<"\n\t\tBook Name : "<<bookname;
		                  cout<<"\n\t\tBook's ID : "<<sc;
		                  cout<<"\n\t\tDate : "<<q<<"/"<<B<<"/"<<p<<"\n";
		              }
		                      intf.read((char*)this,sizeof(*this));
		
		        }
		        intf.close();
		        if(cont==0)
		            cout<<"\n\t\tNo record found.";
		        cout<<"\n\n\t\tEnter any key to return...";
				getch();
		        break;
			}				
		    case 4:
		    {
		    	system("cls");
			    fflush(stdin);
			    cout<<"\n\t\t->Please Enter Details :-\n";
			    cout<<"\n\n\t\tEnter Student's ID : ";
			    cin.getline(st,50);
			    cout<<"\n\t\tEnter Book's ID : ";
			    cin.getline(st1,20);
			    fstream intf("student.txt",ios::in|ios::out|ios::ate|ios::binary);
			    intf.seekg(0);
			    intf.read((char*)this,sizeof(*this));
			    while(!intf.eof())
			        {
			            for(i=0;sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
			            for(j=0;sc1[j]!='\0'&&st[j]!='\0'&&st[j]==sc1[j];j++);
			            if(sc[i]=='\0'&&sc1[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0')
			                {
			                    d=q;
			                    m=B;
			                    y=p;
			                    cout<<"\n\t\tEnter New Date : ";
			                    cin>>q>>B>>p;
			                    fine(d,m,y,q,B,p); //fn1
			                    intf.seekp(intf.tellp()-sizeof(*this)); //fn3
			                    intf.write((char*)this,sizeof(*this)); //fn5
			                    cout<<"\n\n\t\tReissue successfully."; //fn3
			                    break;
			                }
			                   intf.read((char*)this,sizeof(*this));
			        }
			        intf.close();
			    cout<<"\n\n\t\tEnter any key to return...";
				getch();
		        break;
			}		    	
		    case 5:
		    {
		    	system("cls");
			    b=branch(2);
			    system("cls");
			    fflush(stdin);
			    cout<<"\n\t\t->Please Enter Details :-\n";
			    cout<<"\n\t\tEnter Book's ID : ";
			    cin.getline(st1,20);
			    der(st1,b,2);
			    cout<<"\n\n\t\tEnter Student's ID : ";
			    cin.getline(st,20);
			    cout<<"\n\t\tEnter Present date : ";
			    cin>>d>>m>>y;
			    ofstream outf("temp.txt",ios::app|ios::binary);
			    ifstream intf("student.txt",ios::binary);
			    intf.read((char*)this,sizeof(*this));
			    while(!intf.eof())
			        {
			            for(i=0;sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
			            for(j=0;sc1[j]!='\0'&&st[j]!='\0'&&st[j]==sc1[j];j++);
			            if(sc[i]=='\0'&&sc1[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0'&&cont==0)
			                {
			                    cont++;
			                    intf.read((char*)this,sizeof(*this));
			                    fine(q,B,p,d,m,y);
			                    cout<<"\n\t\tReturned successfully.";
			                }
			            else
			                {
			                    outf.write((char*)this,sizeof(*this));
			                    intf.read((char*)this,sizeof(*this));
			                }
			        }
			
			    intf.close();
			    outf.close();
			    remove("student.txt");
			    rename("temp.txt","student.txt");
			    cout<<"\n\n\t\tEnter any key to return...";
				getch();
		        break;
			}		    	
		    case 6:
		    {
		    	system("cls");
    			librarian();
			}		    	
    		default:
    		{
    			cout<<"\n\t\tWrong Input.\n";
				issue();
			}  
		}
	}while(i!=6);
    system("cls");
    librarian();
}
void Lib::fine(int d,int m,int y,int dd,int mm,int yy)//calculate the time borrowing and fine. d/m/y is the date which borrow book, dd/mm/yy is the date which return book 
{
    long int n1,n2;
    int years,l,i;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//day of each months
    n1 = y*365 + d;
    for (i=0; i<m - 1; i++)
        n1 += monthDays[i]; //fn1353
    years = y;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n1 += l;
    n2 = yy*365 + dd;
    for (i=0; i<mm - 1; i++)
        n2 += monthDays[i];
    years = yy;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n2 += l;
    n1=n2-n1;
    n2=n1-15;//if the borrow time > 15 day, not be fine
    if(n2>0)
    cout<<"\n\t\tThe Total Fine is : "<<n2;   
}
void Lib::der(char st[],int b,int x)//adding or minus quality of book when issue book
{
    int i,cont=0;
    fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
    {
        for(i=0;b==B&&sc[i]!='\0'&&st[i]!='\0'&&st[i]==sc[i];i++);
        if(sc[i]=='\0'&&st[i]=='\0')
        {
            cont++;
            if(x==1)
            {
                q--;
            }
            else
            {
                q++;
            }
            intf.seekp(intf.tellp()-sizeof(*this));
            intf.write((char*)this,sizeof(*this));
            break;
        }
        intf.read((char*)this,sizeof(*this));
    }
    if(cont==0)
    {
        cout<<"\n\t\tBook not found.\n";
        cout<<"\n\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        issue();
    }
    intf.close();
}
void Lib::get()//the first menu
{
   	int i;
        cout<<"\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n"<<endl;
        cout<<"\n\t\t>>Please Choose Any Option To login \n";
        cout<<"\n\t\t1.Student\n\n\t\t2.Librarian\n\n\t\t3.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
    
        if(i==1)
        {
            system("cls");
            student();
        }
        else if(i==2)
            pass();

        else if(i==3)
            exit(0);
        else
        {
            cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("CLS");
           	get();
        }
}
void Lib::student()//the student menu
{
    int i;
        cout<<"\n\t************ WELCOME STUDENT ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Go to main menu\n\n\t\t4.Book order\n\n\t\t0.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
            if(i==1)
                booklist(1);
            else if(i==2)
                see(1);
            else if(i==3)
            {
                system("cls");
                get();
            }
            else if(i==4)
            	listStuOrder();
            else if(i==0)
                exit(0);
            else
            {
                cout<<"\n\t\tPlease enter correct option :(";
                getch();
                system("cls");
                student();
            }
}
void Lib::pass()//check the password
{
    int i=0;
    char ch,st[21],ch1[21]={"1111"};
    cout<<"\n\t\tEnter Password : ";
    while(1)
    {
	    ch=getch();
	    if(ch==13)//ch==13 char: enter: check the input is 'space' or not
	    {
	        st[i]='\0';
	        break;
	    }
	    else if(ch==8&&i>0)//ch==8 delete or backspace
	    {
	        i--;
	        cout<<"\b \b";
	    }
	    else
	    {
		    cout<<"*";
		    st[i]=ch;
		    i++;
	    }
    }
    ifstream inf("password.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        librarian();
    }
    else
    {
        cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
        getch();
        system("cls");
        get();
    }
}
void Lib::librarian()//the librian menu
{
	system("cls");
    int i;
        cout<<"\n\t************ WELCOME LIBRARIAN ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Modify/Add Book\n\n\t\t4.Issue Book\n\n\t\t5.See student order\n\n\t\t6.Go to main menu\n\n\t\t7.Change Password\n\n\t\t8.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        switch(i)
        {
            case 1:booklist(2);
                     break;
            case 2:see(2);
                     	break;
            case 3:modify();
                     	break;
            case 4:issue();
                     	break;
            case 5:OutOrder();
            			break;
            case 6:system("cls");
                     	get();
                     	break;
            case 7:password();
                    	break;
            case 8:exit(0);
            default:cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            librarian();
        }
}
void Lib::password()//change the password
{
    int i=0,j=0;
    char ch,st[21],ch1[21]={"1111"};
    system("cls");
    cout<<"\n\n\t\tEnter Old Password : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream intf("password.txt");
    intf>>ch1;
    intf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        cout<<"\n\t**The Password Should be less than 20 characters & don't use spaces**\n\n";
        cout<<"\n\t\tEnter New Password : ";
        fflush(stdin);//delete the cache
        i=0;
        while(1)
        {
        j++;
        ch=getch();
        if(ch==13)
        {
            for(i=0;st[i]!=' '&&st[i]!='\0';i++);
            if(j>20 || st[i]==' ')
            {
                cout<<"\n\n\t\tYou did't follow the instruction \n\n\t\tPress any key for try again.....";
                getch();
                system("cls");
                password();
                librarian();
            }
            st[i]='\0';
            break;
        }
        else if(ch==8&&i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
        cout<<"*";
        st[i]=ch;
        i++;
        }
        }
        ofstream outf("password.txt");
        outf<<st;
        outf.close();
        cout<<"\n\n\t\tYour Password has been changed Successfully.";
        cout<<"\n\t\tPress any key to continue......";
        getch();
        system("cls");
        librarian();
    }
    else
    {
        cout<<"\n\n\t\tPassword is incorrect.....\n";
        cout<<"\n\t\tEnter 1 for retry or 2 for menu";
        cin>>i;
        if(i==1)
        {
        system("cls");
        password();
        }
        else
        {
            system("cls");
            librarian();
        }
    }
}
void Lib::OutOrder()//menu of librian which display, delete order of student
{
	system("cls");
	int i;
	cout<<"\n\t    ********* Book order option ********* \n\n";
	cout << "\n\n\t\t1.Book order list.\n\n\t\t2.Delete all order.\n\n\t\t3.Return to librarian menu.";
	cout << "\n\n\t\tEnter the option:";
	cin >> i;
	if(i == 1)
	{
		system("cls");	
		ifstream ifs("StudentOrder.txt");
		if(!ifs)
		{
	        cout << "Error: file not opened." << endl;
	        exit(101);		
		}else{
			cout << "\n\t    ********* Book order List ********* \n\n";
			while(!ifs.eof())
			{
				int n;
				ifs>> n;
				if(n!=NULL)
				{							
					cout<< "\n\t\tID: ";
					cout<< n << endl;	
				}else{
					break;
				}								
			}
		}
				
		ifs.close();
	    cout<<"\n\t\tPress any key to continue.....";
	    getch();
	    librarian();	
	}else if(i == 2){
		system("cls");
		fstream fs("StudentOrder.txt",ios::out);
		if(!fs)
		{
		    cout << "Error: file not opened." << endl;
		    exit(101);
		}else{
		    fs << '\0';
		    cout<<"\t\tDelete success!";
		    cout<<"\n\n\t\tEnter any key to return...";
		    getch();
		    librarian();
		}
		fs.close();
	}else if(i==3){
		librarian();
	}else{
		cout << "\n\t\tEnter the wrong option :(";
		cout << "\n\t\tEnter any key to choose again!";
		getch();
		OutOrder();
	}
}
///QUEUE///
typedef int item; //define the data
struct Node
{
    item Data;
    Node * Next;
};
struct Queue
{
    Node * Front, *Rear; //first node va bottom node
    int count; //count the node
};

void Init (Queue &Q); //create begin node
int Isempty(Queue Q); //check the Queue empty or not
void Push(Queue &Q, item x); //add more node at the end of Queue
int Pop(Queue &Q); //remove the first node in Queue
int Qfront (Queue Q); //xem thong tin phan tu dau hang doi 
Node *MakeNode(item x); //create one node
void Input (Queue &Q); //input 
void Output(Queue Q); //output 

void Init(Queue &Q)
{
	ofstream ofs("StudentOrder.txt");
	if(!ofs)
	{
        cout << "Error: file not opened." << endl;
        exit(101);		
	}
	ofs << '\0';
    Q.Front = Q.Rear = NULL;
    Q.count = 0;
}
int Isempty (Queue Q) 
{
    if (Q.count==0) //number of node equal 0 -> empty
        return 1;
    return 0;
}

Node *MakeNode(item x) //create a node
{
    Node *P = (Node*) malloc(sizeof(Node));
    P->Next = NULL;
    P->Data = x;
    return P;
}
 
void Push(Queue &Q, item x) //add more node at the end of Queue
{
	fstream fs("StudentOrder.txt", ios::app);
    //check opening file success or not
    if(!fs)
	{
        cout << "Error: file not opened." << endl;
        exit(101);
    }
    Node *P = MakeNode(x); //if Queue empty
    if (Isempty(Q))
    {
        Q.Front = Q.Rear = P; //first and bottom point to P 
        fs << " " << x;
    }
    else //not empty
    { 
        Q.Rear->Next = P;
        Q.Rear = P;
        fs << " " << x;
    }
    Q.count ++ ; //increase the number of node
    fs.close();
}
 
int Pop(Queue &Q) //remove the first current node in Queue
{
	int i = 0,count = 0;
	int arr[10], brr[10];
    fstream fs("StudentOrder.txt");
    if(!fs)
	{
        cout << "Error: file not opened." << endl;
        exit(101);
    }else{
		if (Isempty(Q)) 
	    {	        
	    	fs<<'\0';
	        return 0;
	    }
	    else
	    {
	        item x = Q.Front->Data;
	        if (Q.count == 1) //if Queue has only one node
	        {
	        	Init(Q);
			}else{
				Q.Front = Q.Front->Next;							
			}           
	        Q.count --;
	       	while(!fs.eof())
		    {
		    	int n;
		    	fs>>n;
		    	if(n!=NULL)
		    	{	
		    		arr[i] = n;
		    		count++;
		    		i++;
				}
			}
			for(int h = 0; h < count; h++)
			{
				brr[h] = arr[h+1];
			}
			fs.close();
			fstream fs("StudentOrder.txt",ios::out);
			for(int k = 0; k < count-1; k++)
			{
				fs << " " << brr[k]; 
			}
			fs.close();
	        return x;
	    }    		
	}	      
}
 
void Input (Queue &Q) //enter the Queue
{
	//open file
    ofstream ofs("StudentOrder.txt");
    if(!ofs)
	{
        cout << "Error: file not opened." << endl;
        exit(101);
    }
	int i = 1;
    item x;	     
    cout <<"\n\n\t\t(Enter 0 to finish adding)";
    do
    {
        cout << "\n\n\t\tEnter the "<< i << " order: ";
        cin >> x;
		if (x != 0)
		{
			ofs << " " <<x;//write data to file
			Push(Q,x);	
		}
		i++;	         
    } while(x != 0); //enter '0' to finish
    ofs.close();//close file
}
 
void Output(Queue Q)//output
{
    Node *P = Q.Front;
    while (P != NULL)
    {
    	cout << "\n\n\t\tYour order: ";
        cout << P->Data << "\t\t";
        P = P->Next;
    }
    cout << endl;   
}

void Lib::listStuOrder()//student order menu
{
	system("cls");
	Queue Q;
    Init(Q);
	system("cls");
    int choose, d = 0;
    do
    {
    	cout << "\n\n\t\t*********Enter the option*********";
    	cout << "\n\n\t\t1: Check the list";
    	cout << "\n\n\t\t2: Add order";
    	cout << "\n\n\t\t3: Delete book";
    	cout << "\n\n\t\t4: Return the mainmenu";
        cout << "\n\n\t\tYour option: ";
        cin >> choose;
        switch (choose)
        {
            case 1:
            {
                if (Isempty(Q))
				{
					system("cls");
					cout << "\n\n\t\tEmpty order !" << endl;
					cout << "\n\n\t\tEnter any key to return the menu!";
					getch();	
				}else{
					system("cls");
					cout << "\n\n\t\tThe result :";
					Output(Q);	
					cout << "\n\n\t\tEnter any key to return the menu!";
					getch();
				}
                break;
            }
            case 2:
            {
            	system("cls");
    			int i=0,b,cont=0, c = 0;
    			if(d == 0)
    			{
	    			d = 1;
	    			Input(Q);
	    			cout << "\n\n\t\tEnter '1' to add more and '0' to finish: ";
	    			cin >> c;
					if(c == 1)
					{
						system("cls");
		                item x;
		                cout<<"\n\t\tEnter Book's ID : ";
		                cin >> x;      
						Push(Q,x);					
					}
	                cout << "\n\n\t\tEnter any key to return the menu!";
					getch();	
	                break;			
				}else{
					item x;
	                cout<<"\n\t\tEnter Book's ID : ";
	                cin >> x;      
					Push(Q,x);	
				}				
                cout << "\n\n\t\tEnter any key to return the menu!";
				getch();	
                break;
            }
            case 3:
            {
            	
            	system("cls");
                int y = Pop(Q);
                if(y==0){
                	printf("\n\n\t\tEmpty order !");
				}
                cout << "\n\n\t\tEnter any key to return the menu!";
                getch();
                break;
            }
            case 4: break;
        }
        system("cls");
    }while (choose !=4);
    student(); 
}

///END///
int main()
{
    Lib obj;
    obj.get();
    getch();
    return 0;
}

