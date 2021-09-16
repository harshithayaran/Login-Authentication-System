#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int log() //  ----------   Login Page ----------------
{
	string name,username,passward;
	cout<<"\n Enter your name = ";
	cin>>name;
	cout<<" Enter user name = ";
	cin>>username;
	cout<<" Enter passward = ";
	cin>>passward;
	string n,un,p;
	int flag=0;
	ifstream fin("record.txt", ios::app);
	while(fin>>n>>un>>p)
	{
		if( n == name && un == username && p == passward )
		flag=1;
	}
	if(flag==1)
	{
		cout<<"\n Login Successfull";
		return 1;
	}
	else 
	{
		cout<<"\n Wrong Details";
		return 0;
	}
}
int account()  // -------------- Create Account -------------
{
	string name,username,passward;
	int check = 1;
	cout<<"\n Enter your name = ";
	cin>>name;
	cout<<"\n Enter user name = ";
	cin>>username;
	
	ifstream fin("record.txt");
	string n,u,p;
	while(fin>>n>>u>>p)
	{
		if( username == u )
		break; 
	}
	if( u == username )
	{
		cout<<"\n\tUser with this username already exist.\n";
		check = 0;
	}
	if(check == 0)
	{
		return 0;
	}
	cout<<"\n Enter passward = ";
	cin>>passward;
	ofstream fout("record.txt", ios::app);
	fout<<name<<" "<<username<<" "<<passward<<endl;
	fout.close();
	cout<<"\n\n Account created successfully......";
	return 1;
}

void admin()
{
	string name = "harshit", pass = "harsh100",a_name,a_pass;
	cout<<"\nEnter user name = ";
	cin>>a_name;
	cout<<"\nEnter passward = ";
	cin>>a_pass;
	if(name == a_name && pass == a_pass)
	{
		string name,user,pass;
		cout<<"\n\n\t\t\tWELCOME ADMIN TO LOGIN AUTHENTICATION SYSTEM\n\n";
		ifstream fin;
		cout<<"\t\t\tUSER DETAILS\n\n";
		cout<<"NAME \t\tUSER NAME\n";
		fin.open("record.txt");
		while(fin>>name>>user>>pass)
		{
			cout<<name<<" \t\t"<<user<<endl;
		}
	}
	else 
	cout<<"\n\n\t\tWRONG ADMIN DETAILS\n";
}

int main()
{	cout<<"\n\n\n----------------------------------------------  LOGIN AUTHENTICATION SYSTEM  -------------------------------------------\n\n\n";
	int login,x,a;
	cout<<"Press .........................\n\n";
	cout<<"1: Login\n2: Create Account\n3: Exit\n4: Admin Login\n";
	cout<<"\n Your Choice = ";
	cin>>login;
	switch(login){
		case 1: x=log();
		break;
		case 2: x=account();
		break;
		case 3: exit(1);
		break;
		case 4: admin();
		default: cout<<"\n Wrong Choice";
		exit(1);
	}
	if(x==1)
	{
		cout<<"\n\n\t\tLogin Successfull";
	}
	return 0;
}
