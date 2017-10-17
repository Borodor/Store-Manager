#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
struct product10{
int code;
char productname[30];
float price;
int quantity;
}search;
void status()
{
int scode;
char tryy='y';
char found = 'f';
ifstream fio("products.dat",ios::in);
while(tryy=='y')
{
cout<<"\n\nEnter the code of the product you wish to search for : ";
cin>>scode;
found = 'f';
while(!fio.eof())
{
fio.read((char*)&search,sizeof(product10));
if(scode==search.code)
{
cout<<"\n\nRequested record : \nCode : "<<search.code<<"\tName : "<<search.productname<<"\tPrice : "<<search.price<<"\tQuantity : "<<search.quantity;
found = 't';
getch();
break;
}
}
if(found!='t')
{
cout<<"Invalid product code entered ! Please recheck the values and try again ...";
}
cout<<"\n\nTry again ? <y/n> : ";
cin>>tryy;
fio.close();
}
fio.close();
}
void sort()
{
int desired;
clrscr();
cout<<"\n\nEnter the minimum desired quantity : ";
cin>>desired;
char found = 'f';
ifstream fio;
fio.open("products.dat",ios::in);
cout<<"Products with stock less than "<<desired<<" units : ";
while(!fio.eof())
{
fio.read((char*)&search,sizeof(product10));
if(search.quantity<desired)
{
cout<<"\n\n \nCode : "<<search.code<<"\tName : "<<search.productname<<"\tPrice : "<<search.price<<"\tQuantity : "<<search.quantity;
found = 't';
}
}
getch();
if(found!='t')
{
cout<<"No product's stock is below "<<desired<<" units";
}
fio.close();
}


void main()
{
int check;
clrscr();
cout<<"\t\t\t\tSTORE MANAGEMENT";
cout<<"\n\nPress : \n1.Check product status\n2.Check products with low stock\n\nYour Option : ";
cin>>check;
switch(check)
{
case 1: status();
break;
case 2: sort();
break;
default : cout<<"\nGet back to your senses idiot ...";
getch();
break;
};
}