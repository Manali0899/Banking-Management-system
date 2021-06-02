PBL.C
Earlier this week
May 31
R
RIA SINGH shared an item
C
PBL.C

Can view
You
Last year
Jul 19, 2020
R
RIA SINGH added an item to
Google Drive Folder
Bank Management System
C
PBL.C
Long ago
Jun 22, 2019

Ria Singh uploaded an item
C
PBL.C
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>

struct transaction
	{char accnt[10],type,date[11];
	 float amt,cb,fb;
	}t,t1;

struct customer
	{char name[50],accp[10],accn[10];
	 float s;
	}cus,g,h;

struct staff
	{char id[30],nam[50],pass[30];
	 int d,m,y;
	 float sal;
	}sta,e,b,bn,stv;

void main()
{void admin();
void staff();
void staffa();
void stafft();
char u;
int gd=DETECT,gm;
clrscr();
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
setbkcolor(BROWN);
printf("\n\t\t\t\tGRINGOTTS BANK !!!");
printf("\n\n\t\t\t\tSwitch user :- \n\n\t\t\t\tAdmin : \"A\"\n\t\t\t\tStaff : \"S\"\n\t\t\t\t");
scanf("%c",&u);
closegraph();
if(u=='a'||u=='A')
	admin();
else if(u=='s'||u=='S')
	staff();
else
	exit(0);
getch();
}

void viewc()
{void staffa();
int i=1;
FILE *v;
clrscr();
v=fopen("customer.dat","r");
printf("\n\t\t\t\t\tSTAFF\n\n\t\t\t\tViewing customer list");
fread(&h,sizeof(h),1,v);
do
  {printf("\n\n%d\. Name : ",i);
   fflush(stdout);
   puts(h.name);
   fflush(stdout);
   printf("  Account no. : ");
   fflush(stdout);
   puts(h.accn);
   printf("  Account password : ");
   fflush(stdout);
   puts(h.accp);
   fflush(stdout);
   printf("  Savings : %f",h.s);
   ++i;
   fread(&h,sizeof(h),1,v);
  }while(!feof(v));
fclose(v);
getch();
staffa();
}

void editc()
{void staffa();
char d[10];
int flag=0;
char ch;
FILE *fr,*fw;
fr=fopen("customer.dat","r");
fw=fopen("temp.dat","w");
clrscr();
printf("\n\t\t\t\t\tSTAFF\n\n\t\t\tEditing/Viewing customer account\n\nEnter customer account no. to be edited/viewed : ");
fflush(stdin);
gets(d);
fread(&h,sizeof(h),1,fr);
do
  {if(strcmp(h.accn,d)==0)
	{flag=1;
	 printf("\n\nDetails are :-\n\tName : ");
	 fflush(stdout);
	 puts(h.name);
	 fflush(stdout);
	 printf("\tAccount no. : ");
	 fflush(stdout);
	 puts(h.accn);
	 printf("\tAccount password : ");
	 fflush(stdout);
	 puts(h.accp);
	 fflush(stdout);
	 printf("\tSavings : %f",h.s);
	 printf("\n\nProceed with editing the account(Y/N) ? : ");
	 scanf("%c",&ch);
	 if(ch=='y'||ch=='Y')
		{printf("\n\nEnter new details :-\n\tName : ");
		 fflush(stdin);
		 gets(g.name);
		 strcpy(g.accn,d);
		 printf("\tAccount password : ");
		 fflush(stdin);
		 gets(g.accp);
		 g.s=h.s;
		 fwrite(&g,sizeof(g),1,fw);
		}
	 else if(ch=='n'||ch=='N')
		fwrite(&h,sizeof(h),1,fw);
	 else
		printf("\ninvalid!!!");
	}
   else
	fwrite(&h,sizeof(h),1,fw);
   fread(&h,sizeof(h),1,fr);
  }while(!feof(fr));
if(flag==0)
	printf("\n\nAccount no. doesn\'t exist!!!");
else
	printf("\n\nEdited the account!!!");
fclose(fr);
fclose(fw);
remove("customer.dat");
rename("temp.dat","customer.dat");
getch();
staffa();
}

void delc()
{void staffa();
int flag=0;
char c,dm[10];
FILE *fc,*ft;
fc=fopen("customer.dat","r");
ft=fopen("temp.dat","w");
clrscr();
printf("\n\t\t\t\t\tSTAFF\n\n\t\t\t\tDeleting customer account\n\nEnter account no. of customer to be deleted : ");
fflush(stdin);
gets(dm);
fread(&g,sizeof(g),1,fc);
while(!feof(fc))
	{if(strcmp(dm,g.accn)==0)
		{flag=1;
		 printf("\n\nDetails are :-\nName : ");
		 fflush(stdout);
		 puts(g.name);
		 fflush(stdout);
		 printf("Account no. : ");
		 fflush(stdout);
		 puts(g.accn);
		 printf("Account password : ");
		 fflush(stdout);
		 puts(g.accp);
		 fflush(stdout);
		 printf("Savings : %f",g.s);
		 printf("\n\nProceed with deleting the account (Y/N) ? : ");
		 scanf("%c",&c);
		 if(c=='y'||c=='Y')
			{fread(&g,sizeof(g),1,fc);
			 continue;
			}
		 else if(c=='n'||c=='N')
			fwrite(&g,sizeof(g),1,ft);
		 else
			printf("\ninvalid");
		}
	 else
			fwrite(&g,sizeof(g),1,ft);
	 fread(&g,sizeof(g),1,fc);
	}
if(flag==1)
	printf("\n\nDeleted the account!!!");
else
	printf("\n\nAccount no. doesn\'t exist!!!");
fclose(fc);
fclose(ft);
remove("customer.dat");
rename("temp.dat","customer.dat");
getch();
staffa();
}

void addc()
{void staffa();
long int k;
int i,n;
FILE *f;
clrscr();
f=fopen("customer.dat","a");
fseek(f,0,SEEK_END);
k=(ftell(f))/sizeof(cus);
printf("\n\t\t\t\t\tSTAFF\n\n\t\t\t\tAdding customer account\n\nEnter no. of customers : ");
fflush(stdin);
scanf("%d",&n);
for(i=k+1;i<=k+n;++i)
	{fflush(stdin);
	 printf("\n\nEnter details for customer : %d",i);
	 printf("\nName : ");
	 fflush(stdin);
	 gets(cus.name);
	 printf("Account no. : ");
	 fflush(stdin);
	 gets(cus.accn);
	 printf("Account password : ");
	 fflush(stdin);
	 gets(cus.accp);
	 printf("Savings : ");
	 fflush(stdin);
	 scanf("%f",&cus.s);
	 fwrite(&cus,sizeof(cus),1,f);
	}
fclose(f);
getch();
staffa();
}

void staffa()
{void staff();
char ch;
clrscr();
printf("\n\t\t\t\t\tSTAFF\n\n\t\t\t\tWelcome Staff !!!\n\nChoose function to be performed :-");
printf("\n\nAdding customer account : \"A\"\nDeleting customer account : \"D\"\nEditing/Viewing customer account : \"E\"\nViewing customer list : \"V\"\nBack : \"B\"");
printf("\n\nEnter option : ");
scanf("%c",&ch);
ch=getchar();
if(ch=='a'||ch=='A')
	addc();
else if(ch=='d'||ch=='D')
	delc();
else if(ch=='e'||ch=='E')
	editc();
else if(ch=='v'||ch=='V')
	viewc();
else
	staff();
getch();
}

void viewt()
{void stafft();
void dummy(float *a);
int i=0;
char acn[10];
FILE *ft,*fc;
clrscr();
ft=fopen("transaction.dat","r");
fc=fopen("customer.dat","r");
printf("\n\t\t\t\t\tSTAFF\n\n\t\t\t\tViewing transaction details");
printf("\n\nEnter customer account no. : ");
fflush(stdin);
gets(acn);
fread(&cus,sizeof(cus),1,fc);
while(!feof(fc))
	{if(strcmp(cus.accn,acn)==0)
		{printf("\nAccount no. : ");
		 fflush(stdout);
		 puts(cus.accn);
		 printf("Name : ");
		 fflush(stdout);
		 puts(cus.name);
		}
	 fread(&cus,sizeof(cus),1,fc);
	}
fclose(fc);
printf("\nTransaction details are :-");
printf("\n(Deposited:D, Recieved:R, Sent:S, Withdrawn:W)");
printf("\n\nSr.no.\tDate\t\tSaving\t\tType\tAmount\t\tBalance");
while(!feof(ft))
	{fread(&t,sizeof(t),1,ft);
	 if(strcmp(t.accnt,acn)==0)
		{++i;
		 printf("\n%d\t%s\t%.2f\t\t%c\t%.2f\t\t%.2f",i,t.date,t.cb,t.type,t.amt,t.fb);
		}
	 fread(&t,sizeof(t),1,ft);
	}
fclose(ft);
getch();
stafft();
}

void addt()
{void stafft();
void dummy(float *a);
char rec[10];
long int k;
float tempv,tem;
int i,j,n;
FILE *fw,*fr,*ft;
clrscr();
fw=fopen("transaction.dat","a");
fseek(fw,0,SEEK_END);
k=(ftell(fw)-sizeof(t))/sizeof(t);
printf("\n\t\t\t\t\tSTAFF\n\n\t\t\t\tAdding transaction details\n\nEnter no. of transactions : ");
scanf("%d",&n);
for(j=k+1;j<=k+n;++j)
	{strcpy(t1.accnt,"buffer");
	 tempv=0;
	 printf("\n\nEnter details for transaction : ");
	 printf("\nAccount no. : ");
	 fflush(stdin);
	 gets(t.accnt);
	 fr=fopen("customer.dat","r");
	 fread(&cus,sizeof(cus),1,fr);
	 do
	   {if(strcmp(cus.accn,t.accnt)==0)
		tempv=cus.s;
	    fread(&cus,sizeof(cus),1,fr);
	   }while(!feof(fr));
	 fclose(fr);
	 printf("Type (D/W/S): ");
	 fflush(stdin);
	 scanf("%c",&t.type);
	 printf("Amount : ");
	 fflush(stdin);
	 scanf("%f",&t.amt);
	 printf("Date : ");
	 fflush(stdin);
	 gets(t.date);
	 t.cb=tempv;
	 if(t.type=='d'||t.type=='D')
		{t.fb=t.cb+t.amt;
		 tempv=t.fb;
		}
	 else if(t.type=='w'||t.type=='W')
		{t.fb=t.cb-t.amt;
		 tempv=t.fb;
		}
	 else if(t.type=='s'||t.type=='S')
		{t.fb=t.cb-t.amt;
		 tempv=t.fb;
		 printf("Reciever account no. : ");
		 fflush(stdin);
		 gets(rec);
		 strcpy(t1.accnt,rec);
		 strcpy(t1.date,t.date);
		 t1.type='R';
		 t1.amt=t.amt;
		 fr=fopen("customer.dat","r");
		 fread(&cus,sizeof(cus),1,fr);
		 tem=0;
		 do
		   {if(strcmp(cus.accn,t1.accnt)==0)
			tem=cus.s;
		    fread(&cus,sizeof(cus),1,fr);
		   }while(!feof(fr));
		 fclose(fr);
		 t1.cb=tem;
		 t1.fb=t1.cb+t1.amt;
		 tem=t1.fb;
		 fwrite(&t1,sizeof(t1),1,fw);
		}
	 fwrite(&t,sizeof(t),1,fw);
	 ft=fopen("temp.dat","w");
	 fr=fopen("customer.dat","r");
	 fread(&cus,sizeof(cus),1,fr);
	 do
	   {if(strcmp(cus.accn,t.accnt)==0||strcmp(cus.accn,t1.accnt)==0)
		{strcpy(g.name,cus.name);
		 strcpy(g.accn,cus.accn);
		 strcpy(g.accp,cus.accp);
		 if(strcmp(cus.accn,t.accnt)==0)
			g.s=tempv;
		 else
			g.s=tem;
		 fwrite(&g,sizeof(g),1,ft);
		}
	    else
		fwrite(&cus,sizeof(cus),1,ft);
	    fread(&cus,sizeof(cus),1,fr);
	   }while(!feof(fr));
	 fclose(fr);
	 fclose(ft);
	 remove("customer.dat");
	 rename("temp.dat","customer.dat");
	 fwrite(&t,sizeof(t),1,fw);
	}
fclose(fw);
getch();
stafft();
}

void stafft()
{void staff();
char ch;
clrscr();
printf("\n\t\t\t\t\tSTAFF\n\n\t\t\t\tWelcome Staff !!!\n\nChoose function to be performed :-");
printf("\n\nAdding transaction detail : \"A\"\nViewing transaction list : \"V\"\nBack : \"B\"");
printf("\n\nEnter option : ");
//fflush(stdin);
scanf("%c",ch);
ch=getchar();
if(ch=='a'||ch=='A')
	addt();
else if(ch=='v'||ch=='V')
	viewt();
else
	staff();
getch();
}

void staff()
{
char ch,un[30];
char *password;
FILE *fr;
clrscr();
fr=fopen("staff.dat","r");
printf("\n\t\t\t\t\tSTAFF\n\n\t\t\tEnter username : ");
fflush(stdin);
gets(un);
password=getpass("\n\t\t\tEnter password: ");
fread(&e,sizeof(e),1,fr);
while(!feof(fr))
	{if(strcmp(e.id,un)==0)
		{if(strcmp(password,e.pass)==0)
			{clrscr();
			 printf("\n\t\t\t\t\tSTAFF\n\n\t\t\t\tWelcome Staff !!!\n\nChoose function to be performed :-");
			 printf("\n\nCustomer Details : \"C\"\nTransaction Details : \"T\"\nBack to switch user : \"B\"");
			 printf("\n\nEnter option : ");
			 scanf("%c",&ch);
			 if(ch=='c'||ch=='C')
				staffa();
			 else if(ch=='t'||ch=='T')
				stafft();
			 else
				main();
			}
		 else
			printf("\nWrong password");
		}
	 fread(&e,sizeof(e),1,fr);
	}
fclose(fr);
getch();
}

void views()
{void admin();
void dummy(float *a);
int i=1;
FILE *v;
clrscr();
v=fopen("staff.dat","r");
printf("\n\t\t\t\t\tADMIN\n\n\t\t\t\tViewing staff list");
fread(&stv,sizeof(stv),1,v);
while(!feof(v))
	{fflush(stdout);
	 printf("\n\n%d\. ID : ",i);
	 fflush(stdout);
	 puts(stv.id);
	 printf("  Name : ");
	 fflush(stdout);
	 puts(stv.nam);
	 printf("  Password : ");
	 fflush(stdout);
	 puts(stv.pass);
	 fflush(stdout);
	 printf("  Date of joining : %d/%d/%d",stv.d,stv.m,stv.y);
	 fflush(stdout);
	 printf("\n  Salary : %f",stv.sal);
	 ++i;
	 fread(&stv,sizeof(stv),1,v);
	}
fclose(v);
getch();
admin();
}

void edits()
{void admin();
int flag=0;
char ch,D[30];
FILE *fr,*fw;
void dummy(float *a);
fr=fopen("staff.dat","r");
fw=fopen("temp.dat","w");
clrscr();
printf("\n\t\t\t\t\tADMIN\n\n\t\t\tEditing/Viewing staff account\n\nEnter staff ID to be edited/viewed : ");
fflush(stdin);
gets(D);
fread(&b,sizeof(b),1,fr);
while(!feof(fr))
	{if(strcmp(b.id,D)==0)
		{flag=1;
		 printf("\n\nThe details are :-\n\tID : ");
		 fflush(stdout);
		 puts(b.id);
		 printf("\tName : ");
		 fflush(stdout);
		 puts(b.nam);
		 printf("\tPassword : ");
		 fflush(stdout);
		 puts(b.pass);
		 fflush(stdout);
		 printf("\tDate of joining : %d/%d/%d",b.d,b.m,b.y);
		 fflush(stdout);
		 printf("\n\tSalary : %f",b.sal);
		 printf("\n\nProceed with editing the account(Y/N) ? : ");
		 scanf("%c",&ch);
		 if(ch=='y'||ch=='Y')
			{printf("\n\nEnter new details :- ");
			 strcpy(e.id,D);
			 printf("\n\tName : ");
			 fflush(stdin);
			 gets(e.nam);
			 printf("\tPassword : ");
			 fflush(stdin);
			 gets(e.pass);
			 printf("\tDate of joining :\n\t\tDate : ");
			 fflush(stdin);
			 scanf("%d",&e.d);
			 printf("\t\tMonth : ");
			 fflush(stdin);
			 scanf("%d",&e.m);
			 printf("\t\tYear : ");
			 fflush(stdin);
			 scanf("%d",&e.y);
			 printf("\tSalary : ");
			 fflush(stdin);
			 scanf("%f",&e.sal);
			 fwrite(&e,sizeof(e),1,fw);
			}
		 else if(ch=='n'||ch=='N')
			fwrite(&b,sizeof(b),1,fw);
		 else
			printf("\ninvalid!!!");
		}
	 else
		fwrite(&b,sizeof(b),1,fw);
	 fread(&b,sizeof(b),1,fr);
	}
if(flag==0)
	printf("\n\nId doesn\'t exist!!!");
else
	printf("\n\nEdited the account!!!");
fclose(fr);
fclose(fw);
remove("staff.dat");
rename("temp.dat","staff.dat");
getch();
admin();
}

void dels()
{void admin();
int flag=0;
char dm[30],c;
FILE *fs,*ft;
fs=fopen("staff.dat","r");
ft=fopen("temp.dat","w");
clrscr();
printf("\n\t\t\t\t\tADMIN\n\n\t\t\t\tDeleting staff account\n\nEnter ID of staff member to be deleted : ");
fflush(stdin);
gets(dm);
fread(&e,sizeof(e),1,fs);
while(!feof(fs))
	{if(strcmp(e.id,dm)==0)
		{flag=1;
		 printf("\n\nThe details are :-\nID : ");
		 fflush(stdout);
		 puts(e.id);
		 printf("Name : ");
		 fflush(stdout);
		 puts(e.nam);
		 printf("Password : ");
		 fflush(stdout);
		 puts(e.pass);
		 fflush(stdout);
		 printf("Date of joining : %d/%d/%d",e.d,e.m,e.y);
		 fflush(stdout);
		 printf("\nSalary : %f",e.sal);
		 printf("\n\nProceed with deleting the account (Y/N) ? : ");
		 fflush(stdout);
		 scanf("%c",&c);
		 if(c=='y'||c=='Y')
			{fread(&e,sizeof(e),1,fs);
			 continue;
			}
		 else if(c=='n'||c=='N')
			fwrite(&e,sizeof(e),1,ft);
		 else
			printf("\ninvalid!!!!!");
		}
	 else
		fwrite(&e,sizeof(e),1,ft);
	 fread(&e,sizeof(e),1,fs);
	}
if(flag==1)
	printf("\n\nDeleted the account!!!");
else
	printf("\n\nID doesn\'t exist!!!");
fclose(fs);
fclose(ft);
remove("staff.dat");
rename("temp.dat","staff.dat");
getch();
admin();
}

void adds()
{void admin();
void dummy(float *a);
long int k;
int i,n;
FILE *f;
clrscr();
f=fopen("staff.dat","a");
fseek(f,0,SEEK_END);
k=(ftell(f))/sizeof(sta);
printf("\n\t\t\t\t\tADMIN\n\n\t\t\t\tAdding staff account\n\nEnter no. of staff members :");
fflush(stdin);
scanf("%d",&n);
for(i=k+1;i<=k+n;++i)
	{printf("\n\nEnter details for staff no. : %d",i);
	 printf("\nID : ");
	 fflush(stdin);
	 gets(sta.id);
	 printf("Name : ");
	 fflush(stdin);
	 gets(sta.nam);
	 printf("Password : ");
	 fflush(stdin);
	 gets(sta.pass);
	 printf("Date of joining :-\n\tDate :");
	 fflush(stdin);
	 scanf("%d",&sta.d);
	 printf("\tMonth : ");
	 fflush(stdin);
	 scanf("%d",&sta.m);
	 printf("\tYear : ");
	 fflush(stdin);
	 scanf("%d",&sta.y);
	 printf("Salary : ");
	 fflush(stdin);
	 scanf("%f",&sta.sal);
	 fwrite(&sta,sizeof(sta),1,f);
	}
fclose(f);
getch();
admin();
}

void admin()
{
char ch;
char *password;
clrscr();
printf("\n\t\t\t\t\tADMIN");
password=getpass("\n\n\t\t\t\tEnter the password: ");
if(strcmp(password,"admin")==0)
	{clrscr();
	 printf("\n\t\t\t\t\tADMIN\n\n\t\t\t\tWelcome Admin !!!\n\nChoose function to be performed :-");
	 printf("\n\nAdding staff account : \"A\"\nDeleting staff account : \"D\"\nEditing staff account : \"E\"\nViewing staff list : \"V\"\nBack to switch user : \"B\"");
	 printf("\n\nEnter option : ");
	 scanf("%c",&ch);
	 ch=getchar();
	 if(ch=='a'||ch=='A')
		adds();
	 else if(ch=='d'||ch=='D')
		dels();
	 else if(ch=='e'||ch=='E')
		edits();
	 else if(ch=='v'||ch=='V')
		views();
	 else
		main();

	}
else
	printf("\nWrong password");

getch();
}

void dummy(float *a)
{
float bzs;
bzs=*a;
dummy(&bzs);
}
