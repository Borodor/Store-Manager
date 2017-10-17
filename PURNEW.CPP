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
struct customer{
char customername[30];
char contact[10];
};
struct bill{
int code;
char productname[30];
float price;
int quantity;
float total;
}billdet[80];
int main()
{
clrscr();
float tot=0, tend;
int i=-1;
char found = 'n';
char con = 'y';
int prod;
char ans = 'y';
customer neww;
product purchase;
cuser:
while(con=='y')
{
i = -1;
ans = 'y';
cout<<"\t\t\t\tNEW PURCHASE";
cout<<"\n\nEnter the name of the customer : ";
gets(neww.customername);
cout<<"\nEnter the contact number : ";
gets(neww.contact);
stocklow :
while(ans=='y')
{
cout<<"Enter the product code : ";
cin>>prod;
fstream fin;
fin.open("products.dat",ios::in);
while(!fin.eof())
{
fin.read((char*)&purchase,sizeof(product));
if(prod==purchase.code)
{
cout<<"\n";
puts(purchase.productname);
int ppurchase;
cout<<"Enter the quantity : ";
cin>>ppurchase;
if(purchase.quantity<ppurchase)
{
cout<<"\n\nERROR : Not enough products in the stock ! ";
goto stocklow;
}
i++;
billdet[i].code=purchase.code;
strcpy(billdet[i].productname,purchase.productname);
billdet[i].price=purchase.price;
billdet[i].quantity = ppurchase;
billdet[i].total = billdet[i].price*billdet[i].quantity;
found = 'y';
fstream fio("products.dat",ios::in|ios::out|ios::binary);
long pos;
while(!fio.eof())
{
pos = fio.tellg();
fio.read((char*)&purchase,sizeof(product));
if(purchase.code==prod)
{
purchase.quantity=purchase.quantity-ppurchase;
fio.seekg(pos);
fio.write((char*)&purchase,sizeof(product));
found = 't';
break;
}
}


cout<<"\n";
break;
}
}
if(found == 'n')
{
cout<<"Please enter a valid product code ! ";
}
fin.close();
cout<<"\nAdd more ? <y/n> : ";
cin>>ans;
}
clrscr();
cout<<"\t\t\t\tRECEIPT";
cout<<"\n\nCustomer's Name : ";
puts(neww.customername);
cout<<"\nContact Number : ";
puts(neww.contact);
cout<<"________________________________________";
cout<<"\n\n";
tot = 0;
for(int j = 0;j<=i;j++)
{
puts(billdet[j].productname);
cout<<"\n"<<billdet[j].quantity<<" x "<<billdet[j].price<<" = "<<billdet[j].total<<"\n\n";
tot = tot + billdet[j].total;
}
cout<<"\n\nTotal : "<<tot;
user:
char crd;
cout<<"\n\nPrepaid card user ? : ";
cin>>crd;
if(crd=='y')
{
struct holder{
char customer[30];
int uid;
int pin;
float balance;
}details;
fstream fio("card.dat",ios::in|ios::out|ios::binary);
int id;
long pos;
char found = 'f';
cout<<"\n\nEnter the customer ID : ";
cin>>id;
while(!fio.eof())
{
pos = fio.tellg();
fio.read((char*)&details,sizeof(holder));
if(details.uid==id)
{
int npin;
cout<<"Enter the PIN : ";
cin>>npin;
if(npin==details.pin)
{
if(details.balance<(tot-(tot*0.10)))
{
cout<<"\n\nNot enough balance in the card ! ";
goto user;
}
details.balance=details.balance-(tot-(tot*0.10));
fio.seekg(pos);
fio.write((char*)&details,sizeof(holder));
found = 't';
break;
}
else
{
cout<<"\n\nPIN does not match ! ";
getch();
goto user;
}
}
}
if(found == 'f')
{
cout<<"\nNo such customer not found !";
goto user;
}
fio.close();
cout<<"\nTotal : "<<tot-(tot*0.10);
cout<<"\n\nTransaction succesful ! ";
cout<<"\nContinue ? <y/n> : ";
cin>>con;
goto cuser;
}







int rec=1;
while(rec==1)
{
cout<<"\nCash Tendered : ";
cin>>tend;
if(tend==100000)
{
return 0;
}
if(tend<tot)
{
cout<<"\nTendered amount is lower than total ! Please re check the values ....";
rec = 1;
}
else
{
rec = 0;
}
}
cout<<"Cash Returned : "<<tend-tot;
getch();
cout<<"\n\nContinue ? <y/n> : " ;
cin>>con;
}
return 0;
}