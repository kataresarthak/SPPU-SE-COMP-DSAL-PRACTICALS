#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct stud
{
	int rno;
	char nm[10];
}s;

void create()
{
	ofstream fout;
	fout.open("stud.txt",ios::out);
	int n;
	cout<<"\nENTER THE NUMBER OF RECORDS :";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nENTER ROLLNO & NAME :";
		cin>>s.rno>>s.nm;
		fout<<endl<<s.rno<<s.nm;
	}
	fout.close();
}


void display()
{
	ifstream fin;
	fin.open("stud.txt",ios::in);
	while(!fin.eof())
	{
		fin>>s.rno>>s.nm;
		cout<<"\n"<<s.rno<<"\t"<<s.nm;
	}
	fin.close();
}

void search()
{
	ifstream fin;
	int key,flag=0;

	cout<<"\nENTER THE ROLLNO OF RECORD TO SEARCH :";
	cin>>key;
	fin.open("stud.txt",ios::in);
	while(!fin.eof())
	{
		fin>>s.rno>>s.nm;
		if(key==s.rno)
		{
			flag=1;
			break;
		}
	}

	if(flag==1)
		cout<<"\nRECORD FOUND : "<<s.rno<<"\t"<<s.nm<<"\t";
	else
		cout<<"\nRECORD NOT FOUND";
	fin.close();
}


void del()
{
	ifstream fin,fin1;
	ofstream fout,fout1;
	int key,flag=0;
	cout<<"\nENTER THE ROLLNO OF RECORD TO DELETE :";
	cin>>key;

	fin.open("stud.txt",ios::in);
	fout.open("temp.txt",ios::out);
	while(!fin.eof())
	{
		fin>>s.rno>>s.nm;
		if(key==s.rno)
		{
			flag=1;
		}
		else
			fout<<endl<<s.rno<<s.nm;
	}
	fin.close();
	fout.close();

	fin1.open("temp.txt",ios::in);
	fout1.open("stud.txt",ios::out);
	while(!fin1.eof())
	{
		fin1>>s.rno>>s.nm;
		fout1<<endl<<s.rno<<s.nm;
	}
	fin1.close();
	fout1.close();

	if(flag!=1)
		cout<<"\nRECORD NOT FOUND !!";
}

void update()
{
	ifstream fin,fin1;
	ofstream fout,fout1;
	int key,flag=0;
	cout<<"\nENTER THE ROLLNO OF RECORD TO UPDATE :";
	cin>>key;

	fin.open("stud.txt",ios::in);
	fout.open("temp.txt",ios::out);
	while(!fin.eof())
	{
		fin>>s.rno>>s.nm;
		if(key==s.rno)
		{
			flag=1;
			cout<<"\nENTER NEW RECORD(ROLLNO,NAME) :";
			cin>>s.rno>>s.nm;
			fout<<endl<<s.rno<<s.nm;
		}
		else
			fout<<endl<<s.rno<<s.nm;
	}
	fin.close();
	fout.close();

	fin1.open("temp.txt",ios::in);
	fout1.open("stud.txt",ios::out);
	while(!fin1.eof())
	{
		fin1>>s.rno>>s.nm;
		fout1<<endl<<s.rno<<s.nm;
	}
	fin1.close();
	fout1.close();

	if(flag!=1)
		cout<<"\nRECORD NOT FOUND !!";
}


int main()
{
	int ch;
	do
	{
		cout<<"\n\n1.CREATE\n2.DISPLAY\n3.SEARCH\n4.DELETE RECORD\n5.UPDATE\n6.EXIST";
		cout<<"\nENTER YOUR CHOICE :";
		cin>>ch;
		switch(ch)
		{
		    case 1:
                		create();
				break;
		    case 2:
                		display();
			    	break;
		    case 3:
                		search();
				break;
		    case 4:
                		del();
				break;
		    case 5:
                		update();
				break;
            	    case 6:
		                break;
		}
	}while(ch!=6);
}
