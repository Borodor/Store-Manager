#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
struct pro{
int code;
char productname[30];
float price;
int quantity;
}product;
void modify()
{
int ccode;
char pproductname[30];
float pprice;
int qquantity;
cout<<"\nPresent values : ";
cout<<"\tCode : "<<product.code<<"\tName :"<<product.productname<<"\tPrice : "<<product.price<<"\tQuantity : "<<product.quantity;
cout<<"\n\nEnter the new details : ";
cout<<"\nNew code : ";
cin>>ccode;
cout<<"\nNew name : ";
gets(pproductname);
cout<<"\nNew price : ";
cin>>pprice;
cout<<"\nNew quantity : ";
cin>>qquantity;
if(ccode!=0)
{
product.code=ccode;
}
if(strcmp(pproductname,".")!=0)
{
strcpy(product.productname,pproductname);
}
if(pprice!=0)
{
product.price=pprice;
}
if(qquantity!=-1)
{
product.quantity=qquantity;
}
}
int main()
{
clrscr();
fstream fio("products.dat",ios::in|ios::out|ios::binary);
int productno;
long pos;
char found = 'f';
cout<<"\n\nEnter the product code : ";
cin>>productno;
while(!fio.eof())
{
pos = fio.tellg();
fio.read((char*)&product,sizeof(pro));
if(product.code==productno)
{
modify();
fio.seekg(pos);
fio.write((char*)&product,sizeof(pro));
found = 't';
break;
}
}
if(found == 'f')
{
cout<<"\nRecord not found !";
}
fio.seekg(0);
cout<<"\nNow the file contains : ";
while(!fio.eof())
{
fio.read((char*)&product,sizeof(product));
cout<<"\nCode : "<<product.code<<"\nName : "<<product.productname<<"\nPrice : "<<product.price<<"\nQuantity : "<<product.quantity;
}
fio.close();
return 0;
}