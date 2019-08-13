#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<graphics.h>
#include<ctype.h>
#include<dos.h>
#include<stdlib.h>

struct studentinfo
{
 char name[20];
 char clas[20];
 int roll;
 char father[20];
}st;

FILE *fp;

//Start of function declaration

void welcome();
void insertrec();
void display();
void search();
void searchroll();
void searchname();
void searchclass();
void modify();
void modifyname();
void modifyclass();
void modifyroll();
void Deleted();
void deletename();
void deleteroll();
void deleteclas();
void sort();
void sortname();
void sortroll();
void sortclas();
//End of function declaration

//Start of variable declaration
int wel=0; //It is Global variable
long si=sizeof(st);
//End of variable declaration

void main()
{
    int choice;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"..\\bgi"); //initilizing graphics
    welcome();
    while(2)
     {
	initgraph(&gd,&gm,"..\\bgi");
	cleardevice();
	setcolor(11);
	settextstyle(6,0,4);
	outtextxy(230,10,"M E N U");
	outtextxy(230,26,"=====");
	settextstyle(2,0,6);
	outtextxy(10,400,"Press 0 For Exit..");
	outtextxy(100,106,"1 ->> Insert Student Record");
	outtextxy(100,126,"2 ->> Display Student Record");
	outtextxy(100,150,"3 ->> Search Student Record");
	outtextxy(100,170,"4 ->> Modify Student Record");
	outtextxy(100,190,"5 ->> Delete Student Record");
	outtextxy(100,210,"6 ->> Sort Student Record");
	outtextxy(100,314,"Enter Your Choice : ");
	cprintf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\n\n\n\n : ");
	cprintf("                                ");
	scanf("%d",&choice);
	switch(choice)
	{
	  case 1:
	   insertrec();
	   break;
	  case 2:
	   display();
	   break;
	  case 3:
	    search();
	    break;
	  case 4:
	    modify();
	    break;
	  case 5:
	     Deleted();
	     break;
	  case 6:
	     sort();
	     break;
	  case 0:
	   exit(0);
	  default:
	  printf("\n\t\t Invalid Choice");
	 }
	printf("\n\n\nPress any key to continue..");
	getch();
    }
}

void welcome()
{
  int rv=0,i;
  static int f=0;
  if(f==0)
  {
  for(i=0;i<230;i++)
  {
  rv=random(i)-20;
  setcolor(4);
  cleardevice();
  circle(320,230,8+i);
  circle(320,230,10+i);
  circle(320,230,12+i);
  setcolor(2);
  circle(320,230,0+i);
  circle(320,230,2+i);
  circle(320,230,4+i);
  setcolor(rv);
  circle(320,230,0+rv);
  circle(320,230,2+rv);
  circle(320,230,4+rv);
  delay(6);
  }
  f=1;
  }
  cleardevice();
  circle(320,230,8+i);
  circle(320,230,10+i);
  circle(320,230,12+i);
  setcolor(2);
  circle(320,230,0+i);
  circle(320,230,2+i);
  circle(320,230,4+i);


  char ch;
  settextstyle(4,0,4);
  setcolor(12);
  outtextxy(126,130,"School Management System");
  setcolor(10);
  outtextxy(126,150,"*****************************");
  settextstyle(8,0,4);
  setcolor(14);
  outtextxy(190,200,"DEVELOPED BY ");
  outtextxy(190,220,"===========");
  setcolor(13);
  settextstyle(8,0,5);
  outtextxy(130,250,"Md.Usman Ansari ");
  settextstyle(2,0,6);
  setcolor(2);
  setcolor(4);
  outtextxy(200,60,"Press ESC Close Program");
  setcolor(10);
  outtextxy(180,350,"Press ENTER For Menu Program");

  if((ch=getch())==13)
  return;
  else if(ch=='\033')
  exit(0);
  else
  welcome(); //using recursion
}


void insertrec()
{
  char con='Y';
  closegraph();
  clrscr();
  fp=fopen("Student12.txt","ab");
  fflush(stdin);
  while(toupper(con)=='Y')
  {
    clrscr();
    fflush(stdin);
    printf("\nEnter Student's Name : ");
    gets(st.name);
    printf("\nEnter Student's Class : ");
    scanf("%s",st.clas);
    printf("\nEnter Student's Roll No. : ");
    scanf("%d",&st.roll);
    fflush(stdin);
    printf("\nEnter Father's Name : ");
    gets(st.father);
    fwrite(&st,sizeof(st),1,fp);
    printf("\nRecord Insert Successfully\n");
    printf("Do you wish to enter more record (Y/N) : ");
    scanf(" %c",&con);
  }

   fclose(fp);
}
void display()
{
   closegraph();
   clrscr();
   textcolor(11);
   gotoxy(26,1);
   cprintf("Display Record of Student\n ");
   gotoxy(26,2);
   cprintf("-------------------------");
   fp=fopen("student12.txt","rb");
   printf("\nName \t\t        Class \t    Roll \t Father's Name");
   printf("\n================================================================");
   while(fread(&st,sizeof(st),1,fp)==1)
   printf("\n%s\t\t\t %s \t     %d \t     %s",st.name,st.clas,st.roll,st.father);
   fclose(fp);
   fflush(stdin);

}


void search()
{
  int ch=0;
 closegraph();
 textcolor(13);
 while(ch!=4)
 {
      clrscr();
      gotoxy(26,2);
      cprintf("Search Option");
      gotoxy(26,3);
      cprintf("-------------\n");
      cprintf("\r 1 -> Name\n");
      cprintf("\r 2 -> Roll\n");
      cprintf("\r 3 -> Class\n");
      cprintf("\r 4 -> Back\n");
      cprintf("\r Enetr Your Your Choice : ");
      scanf("%d",&ch);
      switch(ch)
      {
       case 1:
       searchname();
       break;
       case 2:
       searchroll();
       break;
       case 3:
       searchclass();
       break;
       case 4:
       break;
       default:
       cprintf("\r Invalid Choice Try Again");
       getch();
      }
 };
}

void searchroll()
{
      clrscr();
      int r,flag=0,c=0;
      fp=fopen("student12.txt","rb");
      printf("\nEnter Student Roll No. :");
      scanf("%d",&r );
      while(fread(&st,sizeof(st),1,fp)==1)
      {
       if(st.roll==r)
       {
      printf("\n--------------------------------------------------------------------");
      printf("\n Student's Name = %s",st.name);
      printf("\n Class = %s",st.clas);
      printf("\n Roll No. = %d",st.roll);
      printf("\n Father Name = %s",st.father);
      printf("\n--------------------------------------------------------------------");
      flag=1;
      c++;
       if(c==3)
      {
	printf("\nPress Any key For Next Page..");
	getch();
	c=0;
	clrscr();
      }

     }
     }
    if(flag==0)
    printf("\nRoll Not Found");
    else
    printf("\n\nRecord Found Successfully");
    fclose(fp);
    getch();
}

void searchname()
{
      clrscr();
      char n[26], flag=0;
      int c=0;
      fp=fopen("student12.txt","rb");
      printf("\nEnter Student's Name :");
      fflush(stdin);
      gets(n);
      while(fread(&st,sizeof(st),1,fp)==1)
      {
       if((strcmpi(st.name,n)==0))
       {
      printf("\n--------------------------------------------------------------------");
      printf("\n Student's Name = %s",st.name);
      printf("\n Class = %s",st.clas);
      printf("\n Roll No. = %d",st.roll);
      printf("\n Father Name = %s",st.father);
      printf("\n--------------------------------------------------------------------");
      flag=1;
      c++;
	if(c==3)
      {
	printf("\nPress Any key For Next Page..");
	getch();
	c=0;
	clrscr();
      }
     }
     }
    if(flag==0)
    printf("\nName Not Found");
    else
    printf("\n\nName Found Successfully");
    fclose(fp);
    getch();
}

void searchclass()
{
      clrscr();
      char cl[26], flag=0;
      int c=0;
      fp=fopen("student12.txt","rb");
      printf("\nEnter Student Class :");
      fflush(stdin);
      gets(cl);
      while(fread(&st,sizeof(st),1,fp)==1)
      {
       if((strcmpi(st.clas,cl)==0))
       {
      printf("\n--------------------------------------------------------------------");
      printf("\n Student's Name = %s",st.name);
      printf("\n Class = %s",st.clas);
      printf("\n Roll No. = %d",st.roll);
      printf("\n Father Name = %s",st.father);
      printf("\n--------------------------------------------------------------------");
      flag=1;
      c++;
      if(c==3)
      {
	printf("\nPress Any key For Next Page..");
	getch();
	c=0;
	clrscr();
      }

     }
     }
    if(flag==0)
    printf("\nClass Not Found");
    else
    printf("\n\Class Found Successfully");
    fclose(fp);
    getch();
}




void modify()
{
  int ch=0;
 closegraph();
 textcolor(2);
 while(ch!=4)
 {
      clrscr();
      gotoxy(26,2);
      cprintf("Modification Option");
      gotoxy(26,3);
      cprintf("---------------\n");
      cprintf("\r 1 -> Name\n");
      cprintf("\r 2 -> Roll\n");
      cprintf("\r 3 -> Class\n");
      cprintf("\r 4 -> Back\n");
      cprintf("\r Enetr Your Your Choice : ");
      scanf("%d",&ch);
      switch(ch)
      {
       case 1:
       modifyname();
       break;
       case 2:
       modifyroll();
       break;
       case 3:
       modifyclass();
       break;
       case 4:
       break;
       default:
       cprintf("\r Invalid Choice Try Again");
       getch();
      }
 };
}



void modifyname()
{

 char n[26],flag=0;
 closegraph();
 fp=fopen("student12.txt","rb+");
 printf("\nEnter Student's Name :");
 scanf("%s",n);
 while(fread(&st,sizeof(st),1,fp)==1)
 {
   if((strcmpi(st.name,n)==0))
   {
    fflush(stdin);
    printf("\nEnter Student's Name : ");
    gets(st.name);
    fseek(fp,-si,1);
    fwrite(&st,sizeof(st),1,fp);
    fclose(fp);
    flag=1;
    break;
   }
}
   if(flag==0)
    printf("\nName Not Found");
   else
    printf("\n\nRecord Modified Successfully");
     getch();
}

void modifyroll()
{
 int r,flag=0;
 closegraph();
 fp=fopen("student12.txt","rb+");
 printf("\nEnter Student Roll No. :");
 scanf("%d",&r );
 while(fread(&st,sizeof(st),1,fp)==1)
 {
   if(st.roll==r)
   {
    fflush(stdin);
    printf("\nEnter Student's Roll No. : ");
    scanf("%d",&st.roll);
    fseek(fp,-si,1);
    fwrite(&st,sizeof(st),1,fp);
    fclose(fp);
    flag=1;
    break;
   }
}
   if(flag==0)
    printf("\nRoll Not Found");
   else
    printf("\n\nRecord Modified Successfully");
   getch();
}
void modifyclass()
{

 char cl[26];
 int flag=0;
 closegraph();
 fp=fopen("student12.txt","rb+");
 printf("\nEnter Student's Class :");
 scanf("%s",cl);
 while(fread(&st,sizeof(st),1,fp)==1)
 {
   if(strcmpi(st.clas,cl)==0)
   {
    printf("\nEnter Student's Class. : ");
    fflush(stdin);
    scanf("%s",st.clas);
    fseek(fp,-si,1);
    fwrite(&st,sizeof(st),1,fp);
    flag=1;
    break;
   }
 }
    fclose(fp);
   if(flag==0)
    printf("\nClass Not Found");
   else
    printf("\n\nRecord Modified Successfully");
   getch();
}




void deleteroll()
{
  FILE *tmp;
 int r,flag=0;
 closegraph();
 fp=fopen("student12.txt","rb");
 tmp=fopen("temp.txt","ab");
 printf("\nEnter Student Roll No. :");
 scanf("%d",&r );
 while(fread(&st,sizeof(st),1,fp)==1)
 {
   if(st.roll!=r)
   fwrite(&st,sizeof(st),1,tmp);
   else
   flag=1;
}
  fclose(fp);
  fclose(tmp);
  remove("student12.txt");
  rename("temp.txt","student12.txt");

   if(flag==0)
    printf("\nRoll Not Found");
   else
    printf("\n\nRecord Delete Successfully");

     getch();
}
void deleteclas()
{
  FILE *tmp;
 char cl[20],flag=0;
 closegraph();
 fp=fopen("student12.txt","rb");
 tmp=fopen("temp.txt","ab");
 printf("\nEnter Student Class :");
 scanf("%s",cl );
 while(fread(&st,sizeof(st),1,fp)==1)
 {
   if((!(strcmpi(st.clas,cl)==0)))
   fwrite(&st,sizeof(st),1,tmp);
   else
   flag=1;
}
  fclose(fp);
  fclose(tmp);
  remove("student12.txt");
  rename("temp.txt","student12.txt");

   if(flag==0)
    printf("\nClass Not Found");
   else
    printf("\n\nRecord Delete Successfully");

    getch();
}

void deletename()
{
 FILE *tmp;
 char na[20],flag=0;
 closegraph();
 fp=fopen("student12.txt","rb");
 tmp=fopen("temp.txt","ab");
 printf("\nEnter Student Class :");
 scanf("%s",na);
 while(fread(&st,sizeof(st),1,fp)==1)
 {
   if(!(strcmpi(st.name,na)==0))
   fwrite(&st,sizeof(st),1,tmp);
   else
   flag=1;
}
  fclose(fp);
  fclose(tmp);
  remove("student12.txt");
  rename("temp.txt","student12.txt");

   if(flag==0)
    printf("\nName Not Found");
   else
    printf("\n\nRecord Delete Successfully");

   getch();
}


void sort()
{
  int ch=0;
 closegraph();
 textcolor(4);
 while(ch!=4)
 {
      clrscr();
      gotoxy(26,2);
      cprintf("Sorting Option");
      gotoxy(26,3);
      cprintf("---------------\n");
      cprintf("\r 1 -> Name\n");
      cprintf("\r 2 -> Roll\n");
      cprintf("\r 3 -> Class\n");
      cprintf("\r 4 -> Back\n");
      cprintf("\r Enetr Your Your Choice : ");
      scanf("%d",&ch);
      switch(ch)
      {
       case 1:
       sortname();
       break;
       case 2:
       sortroll();
       break;
       case 3:
       sortclas();
       break;
       case 4:
       break;
       default:
       cprintf("\r Invalid Choice Try Again");
       getch();
      }
 };
}


void Deleted()
{
  int ch=0;
 closegraph();
 textcolor(14);
 while(ch!=4)
 {
      clrscr();
      gotoxy(26,2);
      cprintf("Delete Option");
      gotoxy(26,3);
      cprintf("---------------\n");
      cprintf("\r 1 -> Name\n");
      cprintf("\r 2 -> Roll\n");
      cprintf("\r 3 -> Class\n");
      cprintf("\r 4 -> Back\n");
      cprintf("\r Enetr Your Your Choice : ");
      scanf("%d",&ch);
      switch(ch)
      {
       case 1:
       deletename();
       break;
       case 2:
       deleteroll();
       break;
       case 3:
       deleteclas();
       break;
       case 4:
       break;
       default:
       cprintf("\r Invalid Choice Try Again");
       getch();
      }
 };
}

void sortname()
{
closegraph();
clrscr();
 struct studentinfo s[50],temp;
 int a=0,i,j;
 fp=fopen("student12.txt","rb");
 while(fread(&st,sizeof(st),1,fp)==1)
  s[a++]=st;
  for(i=0;i<a-1;i++)
  {
   for(j=i+1;j<a;j++)
   {
    if(strcmpi(s[i].name,s[j].name)>1)
    {
     temp=s[i];
     s[i]=s[j];
     s[j]=temp;
    }
   }
 }
  printf("\nName \t\t        Class \t    Roll \t Father's Name");
  printf("\n================================================================");
  for(i=0;i<a;i++)
  printf("\n%s\t\t\t %s \t     %d \t     %s",s[i].name,s[i].clas,s[i].roll,s[i].father);
  fclose(fp);
  getch();
}


void sortroll()
{
closegraph();
clrscr();
 struct studentinfo s[50],temp;
 int a=0,i,j;
 fp=fopen("student12.txt","rb");
 while(fread(&st,sizeof(st),1,fp)==1)
  s[a++]=st;
  for(i=0;i<a-1;i++)
  {
   for(j=i+1;j<a;j++)
   {
    if(s[i].roll>s[j].roll)
    {
     temp=s[i];
     s[i]=s[j];
     s[j]=temp;
    }
   }
 }
  printf("\nName \t\t        Class \t    Roll \t Father's Name");
  printf("\n================================================================");
  for(i=0;i<a;i++)
  printf("\n%s\t\t\t %s \t     %d \t     %s",s[i].name,s[i].clas,s[i].roll,s[i].father);
  fclose(fp);
  getch();
}

void sortclas()
{
closegraph();
clrscr();
 struct studentinfo s[50],temp;
 int a=0,i,j;
 fp=fopen("student12.txt","rb");
 while(fread(&st,sizeof(st),1,fp)==1)
  s[a++]=st;
  for(i=0;i<a-1;i++)
  {
   for(j=i+1;j<a;j++)
   {
    if(strcmpi(s[i].clas,s[j].clas)>1)
    {
     temp=s[i];
     s[i]=s[j];
     s[j]=temp;
    }
   }
 }
  printf("\nName \t\t        Class \t    Roll \t Father's Name");
  printf("\n================================================================");
  for(i=0;i<a;i++)
  printf("\n%s\t\t\t %s \t     %d \t     %s",s[i].name,s[i].clas,s[i].roll,s[i].father);
  fclose(fp);
  getch();
}






