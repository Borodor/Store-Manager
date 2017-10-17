#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<dos.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<additem.cpp>
#include<purnew.cpp>
#include<modify.cpp>
#include<delete.cpp>
#include<manageme.cpp>
class functions{
	struct product{
		int code;
		char productname[30];
		float price;
		int quantity;
	};
public :
	struct acces{
		char accname[30];
		int access;
	}levels;
public :
int password();
};

int functions::password()
{
	struct newuser{
		char newusername[30];
		char newpassword[6];
		int level;
	}user;
	clrscr();
	int logfound = 3;
	char username[30];
	char password[6];
	long double master;
	char permission;
	int opt;
	char verifypassword[6];
	user.level=0;
	int flag = 0;
	int len;
	ret:
	clrscr();
	cout<<"\t\t\t\tSTORE MANAGER PRO ";
	cout<<"\n\nWelcome aboard user. Please login to continue .... ";
	cout<<"\n\nPress : \n1. Create a new account\n2. Login to an existing account\n";
	cout<<"\nYour option : ";
	cin>>opt;
	if(opt==1)
	{
	levels.access=0;
	cout<<"\n\nEnter your desired username ; ";
	gets(user.newusername);
	cout<<"\nEnter your password : ";
	int l = 0;
	int k = 0;
	while((k = getch())!=13&&l<6 )
	  {

	 user.newpassword[l] = k;
	  cout << "*";
	  l++;

	  }
	cout<<"\nConfirm your password : ";
	int x = 0;
	int z = 0;
	while((z = getch())!=13&&x<6 )
	  {

	 verifypassword[x] = z;
	  cout << "*";
	  x++;

	  }
	for(int u = 0;u<l;u++)
	{
	if(user.newpassword[u]!=verifypassword[u])
	{
	flag = 1;
		}
	}
	if(flag==0)
	{
	cout<<"\nAccount creation successful !!";
	strcpy(levels.accname,user.newusername);
	cout<<"\nGive administrator privileges to "<<user.newusername<<" ? <y/n> : ";
	cin>>permission;
	if(permission=='y')
	{
	cout<<"\n\nEnter the master password : ";
	cin>>master;
	if(master==112345)
	{
		cout<<"\n\n"<<user.newusername<<" is now an admin ! ";
		getch();
		levels.access=1;
	}
	else
	{
		cout<<"\nSorry wrong master password entered ! ";
	}
	}
	ofstream fout;
	fout.open("Accounts.dat",ios::in|ios::binary|ios::app);
	if(!fout)
	{
		cout<<"\nAn error whilst accessing the database ..... ";
		return 1;
	}
	ofstream fileout;
	cout<<"\n\n"<<levels.access;
	fileout.open("access.dat",ios::binary|ios::app);
	fileout.write((char*)&levels,sizeof(acces));
	fileout.close();
	fout.write((char*)&user,sizeof(newuser));
	fout.close();
	goto ret;
	}
	else
	{
		cout<<"\nPasswords do not match ! ";
	}
	exit(0);
	}
	else
	{
	char ppassword[6];
	retry:
	logfound = 0;
	cout<<"\n\nUSERNAME : ";
	gets(username);
	cout<<"\n\nPassword : ";
	int l = 0;
	int k = 0;
	while((k = getch())!=13 )
	  {

	 ppassword[l] = k;
	  cout << "*";
	  l++;

	  }
	ifstream fin;
	fin.open("Accounts.dat",ios::in);
	while(!fin.eof())
	{
		fin.read((char*)&user,sizeof(newuser));
		if(strcmp(username,user.newusername)==0)
		{
			logfound=1;
			break;
		}
	}
	if(strcmp(ppassword,user.newpassword)==0)
	{
		logfound+=1;
	}
	fin.close();
	}
	if(logfound==2)
	{
		cout<<"\n\nLogin successfull ! Welcome ";
		puts(user.newusername);
		getch();
		ifstream fin2;
		fin2.open("Access.dat",ios::in);
		while(!fin2.eof())
		{
			fin2.read((char*)&levels,sizeof(acces));
			if(strcmp(username,levels.accname)==0)
			{
				break;
			}
		}

		return 0;
	}
	else
	if(logfound==1||logfound==0)
	{
		char ry;
		cout<<"\nSorry invalid credentials entered .....";
		cout<<"\nTry again ? <y/n> : ";
		cin>>ry;
		if(ry=='y')
		{
			goto retry;
		}
	}
	exit(1);
	return 0;
}

void main()
{
	functions store;
	int opt;
	store.password();
	clrscr();
	gty:
	clrscr();
	cout<<"\t\t\t\tSTORE MANAGER PRO";
	cout<<store.levels.access;
	if(store.levels.access==1)
	{
	cout<<"\n\nPress : \n1. New purchase\n2. Add product\n3. Edit product details\n4. Delete product\n5. Store Management\n6. About\n0. Exit";
	cout<<"\n\nEnter your option : ";
	cin>>opt;

	switch(opt)
	{
	case 1: purr();
	break;
	case 2: add();
	break;
	case 3: mod();
	break;
	case 4: del();
	break;
	case 5: manage();
	break;
	case 6: clrscr();
	cout<<"\t\t\t\tABOUT";
	cout<<"\n\nSTORE MANAGER PRO is a copyright product of Deepanshu Wadhwa.\n\nAny unauthorized copying / editing / sale / redistribution of this product is a punishable offence.\n\nFor instructions on how to use this program , kindly refer to the dicumentation provided.\n\nContact me in case of any further queries / suggestions / bug fixing ,\n\nEmail ID : deepanshuwadhwa97@gmail.com";
	getch();
	clrscr();
	break;
	case 0: exit(0);
	default: cout<<"Invalid option ! ";
	break;
	};
	goto gty;

	}
	else
	{
	gtty :
	cout<<"\n\nPress : \n1. New Purchase\n2. About\n0. Exit \n\n Your Option : ";
	cin>>opt;
	while(opt!=0)
	{
	switch(opt)
	{
	case 1:purr();
	break;
	case 2:cout<<"\n\nSTORE MANAGER PRO is a copyright product of Deepanshu Wadhwa.\n\nAny unauthorized copying / editing / sale / redistribution of this product is a punishable offence.\n\nFor instructions on how to use this program , kindly refer to the documentation provided.\n\nContact me in case of any further queries / suggestions / bug fixing \n\nEmail ID : deepanshuwadhwa97@gmail.com";
	getch();
	clrscr();
	break;
	case 0: exit(0);
	break;
	};
	goto gtty;
	}
	}

}