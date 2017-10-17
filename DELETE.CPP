#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<stdlib.h>
struct product{
int code;
char productname[30];
float price;
int quantity;
};
int main()
{
clrscr();
product del;
ifstream fio("products.dat",ios::in);
ofstream file("temp.dat",ios::out|ios::binary);
int cno;
char found = 'f',confirm = 'n';
cout<<"Enter product number of the product to be deleted : ";
cin>>cno;
while(!fio.eof())
{
fio.read((char*)&del,sizeof(product));
if(cno==del.code)
{
cout<<"\n\nPresent record : \nCode : "<<del.code<<"\tName : "<<del.productname<<"\tPrice : "<<del.price<<"\tQuantity : "<<del.quantity;
found = 't';
cout<<"\n\nAre you absolutely sure you wish to remove this product from the database ? <y/n> : ";
cin>>confirm;
if(confirm=='n')
file.write((char*)&del,sizeof(product));
}
else
file.write((char*)&del,sizeof(product));
}
if(found=='y')
cout<<"\nRecord not found ! ";
fio.close();
file.close();
remove("products.dat");
rename("temp.dat", "products.dat");
fio.open("products.dat",ios::in);
cout<<"\n\nNow the product database contains : \n";
while(!fio.eof())
{
fio.read((char*)&del,sizeof(product));
if(fio.eof())break;
cout<<"\nCode : "<<del.code<<"\tName : "<<del.productname<<"\tPrice : "<<del.price<<"\tQuantity : "<<del.quantity;
}
fio.close();
return 0;
}
