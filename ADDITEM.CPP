#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<dos.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
struct product{
int code;
char productname[30];
float price;
int quantity;
};
int main()
{
char ans='y';
int code;
product add;
while(ans=='y'||ans=='Y')
{
exi:
cout<<"Enter the product code : ";
cin>>code;
ifstream fin;
fin.open("products.dat",ios::in);
while(!fin.eof())
{
fin.read((char*)&add,sizeof(product));
if(code==add.code)
{
cout<<"\n\nA product with similar productcode already exists ! ";
goto exi;
}
}
add.code=code;
cout<<"\n\nEnter the name of the product : ";
gets(add.productname);
cout<<"Enter the price : ";
cin>>add.price;
cout<<"Enter the quantity added : ";
cin>>add.quantity;
ofstream fout;
fout.open("products.dat",ios::out|ios::binary|ios::app);
if(!fout)
{
cout<<"An error whilst accessing the database ..... ";
return 1;
}
fout.write((char*)&add,sizeof(product));
cout<<"\n\nDo you wish to continue ? <y/n> : ";
cin>>ans;
fout.close();
}
return 0;
}