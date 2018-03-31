#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<string.h>
char cand[10];
void login(void);
using namespace std;
int num=0,flag=0;
struct heapdata
{
    long enrl;
    int ran,c1,c2,c3,c4,c5;
};
typedef struct heapdata myheap;
void menu(long);
struct tree
{
    long enroll;
    char name[20],pass[30];
    struct tree *lc,*rc;
};
typedef struct tree tree;
char institutes[8][30],branches[4][15];
tree *temp;
void bg(void)
{
    system("CLS");
    cout<<"\t\t\t\t\t     ******************** WELCOME TO AIEEE SEAT ALLOCATION SYSTEM ********************"<<endl;
}

tree * insertnode(tree *root,tree *temp)
{
    if(root==NULL)
     root=temp;
    else
    {
        if(temp->enroll<root->enroll)
        root->lc=insertnode(root->lc,temp);
            else
            root->rc=insertnode(root->rc,temp);
    }
    return root;
}

void enter(long enrl)
{
FILE *fp1,*fp2;
char clg[25],brnch[25];
int icode,bcode,i,ic[5],bc[5],ran;
        system("color f3");
bg();
cout<<"\n\n\n\n\n\n\n\t\t\t\tENTER YOUR JEE MAIN RANK :  ";
cin>>ran;
bg();
cout<<"\n\n \t\tCOLLEGE CODES\t\t\t\t\t\t\tBRANCH CODES\n\n\n\n";
fp1=fopen("file1.txt","r");
fp2=fopen("file2.txt","r");
while((fscanf(fp1,"%s%d",clg,&icode))!=EOF)
{
cout<<"\n\n\t\t"<<clg<<"\t"<<icode;
if((fscanf(fp2,"%s%d",brnch,&bcode)!=EOF))
    cout<<"\t\t\t\t"<<brnch<<"\t"<<bcode<<endl;
else
    cout<<endl;
}
fclose(fp1);
fclose(fp2);
cout<<"\n\n\n\n\n\n\t\t\t\tPLEASE ENTER THE CHOICES BELOW AS INSTITUTE CODE <space> BRANCH CODE........"<<endl;
for(i=0;i<5;i++)
{
    if(i==0)
    cout<<"\n\n\t\t\t\tENTER YOUR "<<i+1<<"st choice  ";

    else if(i==1)
    cout<<"\n\n\t\t\t\tENTER YOUR "<<i+1<<"nd choice  ";

    else if(i==2)
    cout<<"\n\n\t\t\t\tENTER YOUR "<<i+1<<"rd choice  ";

    else
    cout<<"\n\n\t\t\t\tENTER YOUR "<<i+1<<"th choice  ";
    cin>>ic[i]>>bc[i];
}
fp1=fopen("choices.txt","a");
    fprintf(fp1,"\n%ld %d %d %d %d %d %d",enrl,ran,(ic[0]%100)*10+(bc[0]%10),(ic[1]%100)*10+(bc[1]%10),(ic[2]%100)*10+(bc[2]%10),(ic[3]%100)*10+(bc[3]%10),(ic[4]%100)*10+(bc[4]%10));
fclose(fp1);
cout<<"\n\n\n\n\n\t\t\t\tCHOICE FILLING COMPLETED SUCCESSFULLY. WAIT WHILE WE REDIRECT YOU TO HOMEPAGE.";
 delay(500);cout<<".";delay(500);cout<<".";delay(500);cout<<".";delay(500);cout<<".";
        delay(500);cout<<".";delay(500);cout<<".";delay(500);cout<<".";
       menu(enrl);
return;
}

void view(long x)
{
    FILE *fp1,*fp2,*fp3;
int r,c1,c2,c3,c4,c5,c;
long enrl;
 system("color f1");
fp3=fopen("choices.txt","r");
while(fscanf(fp3,"%ld%d%d%d%d%d%d",&enrl,&r,&c1,&c2,&c3,&c4,&c5)!=EOF)
{
    if(enrl==x)
    {
        bg();
            cout<<"\n\n\n\n";
            cout<<"\n\n\t\t\t\tChoice 1"<<" "<<institutes[c1/10]<<" "<<branches[c1%10];
            cout<<"\n\n\t\t\t\tChoice 2"<<" "<<institutes[c2/10]<<" "<<branches[c2%10];
            cout<<"\n\n\t\t\t\tChoice 3"<<" "<<institutes[c3/10]<<" "<<branches[c3%10];
            cout<<"\n\n\t\t\t\tChoice 4"<<" "<<institutes[c4/10]<<" "<<branches[c4%10];
            cout<<"\n\n\t\t\t\tChoice 5"<<" "<<institutes[c5/10]<<" "<<branches[c5%10];
            cout<<"\n\n\n\n";
    }
}
fclose(fp3);
cout<<"\n\n\n\n\t\t\t\t1. BACK\n\n\t\t\t\t2.EXIT\n\n\t\t\t\t";
cin>>c;
if(c==1)
    menu(x);
else
    exit(0);
}

void hinsert(myheap heap[],myheap temp2,int i)
{
heap[i]=temp2;
myheap temp3;
while(i!=0&&heap[(i-1)/2].ran>heap[i].ran)
{
temp3=heap[(i-1)/2];
heap[(i-1)/2]=heap[i];
heap[i]=temp3;
i=(i-1)/2;
}
}

myheap extractmin(myheap heap[],int i)
{
    int sizeh=num-i;
    int j;
    myheap temp,temp2;
    temp=heap[0];
    heap[0]=heap[sizeh-1];
    heap[sizeh-1]=temp;
    sizeh=sizeh-1;
    j=0;
while(j<sizeh)
{
    if((2*j+1)>=sizeh)
        break;
    if((2*j+2)>=sizeh)
    {
        if(heap[j].ran<heap[2*j+1].ran)
         break;
         else
        {
            temp2=heap[j];
            heap[j]=heap[2*j+1];
            heap[2*j+1]=temp2;
            break;
        }
    }
    else
    {
    if(heap[j].ran<heap[2*j+1].ran&&heap[j].ran<heap[2*j+2].ran)
        break;
    if(heap[j].ran>heap[2*j+1].ran&&heap[j].ran>heap[2*j+2].ran)
    {
        if(heap[2*j+1].ran<heap[2*j+2].ran)
        {
            temp2=heap[j];
            heap[j]=heap[2*j+1];
            heap[2*j+1]=temp2;
            j=2*j+1;
        }
        else
        {
            temp2=heap[j];
            heap[j]=heap[2*j+2];
            heap[2*j+2]=temp2;
            j=2*j+2;
        }
    }
    else
    {
if(heap[j].ran>heap[2*j+1].ran)
{
        temp2=heap[j];
            heap[j]=heap[2*j+1];
            heap[2*j+1]=temp2;
            j=2*j+1;
}
else
    {
            temp2=heap[j];
            heap[j]=heap[2*j+2];
            heap[2*j+2]=temp2;
            j=2*j+2;
    }
    }
    }
}
return temp;
}

void allocate(int ***avail,myheap temp,int i)
{
    int choice;
    cout<<"\n";
    choice=temp.c1;
   if(avail[choice/10][choice%10][0])
    {
       avail[choice/10][choice%10][0]--;
       cout<<"\t\t\t\t"<<temp.enrl<<" "<<temp.ran<<" "<<institutes[choice/10]<<" "<<branches[choice%10]<<endl;
    }
    else
    {
     choice=temp.c2;
   if(avail[choice/10][choice%10][0])
    {
       avail[choice/10][choice%10][0]--;
       cout<<"\t\t\t\t"<<temp.enrl<<" "<<temp.ran<<" "<<institutes[choice/10]<<" "<<branches[choice%10]<<endl;
    }
    else
    {
    choice=temp.c3;
   if(avail[choice/10][choice%10][0])
    {
       avail[choice/10][choice%10][0]--;
   cout<<"\t\t\t\t"<<temp.enrl<<" "<<temp.ran<<" "<<institutes[choice/10]<<" "<<branches[choice%10]<<endl;
     }
    else
    {
    choice=temp.c4;
   if(avail[choice/10][choice%10][0])
    {
       avail[choice/10][choice%10][0]--;
       cout<<"\t\t\t\t"<<temp.enrl<<" "<<temp.ran<<" "<<institutes[choice/10]<<" "<<branches[choice%10]<<endl;
    }
    else
    {
    choice=temp.c5;
   if(avail[choice/10][choice%10][0])
    {
       avail[choice/10][choice%10][0]--;
     cout<<"\t\t\t\t"<<temp.enrl<<" "<<temp.ran<<" "<<institutes[choice/10]<<" "<<branches[choice%10]<<endl;
    }
    else
    cout<<"\t\t\t\t"<<temp.enrl<<" "<<temp.ran<<"SORRY NO SEATS LEFT AS PER YOUR CHOICES";
    }
    }
    }
    }
 }

void result(int ***avail,long x)
{
    system("color fc");
    bg();
    cout<<"\n\n";
    int i,j,c;
myheap temp2;
int choices[5];
    FILE *fp=fopen("choices.txt","r");
    while(fscanf(fp,"%ld%d%d%d%d%d%d",&temp2.enrl,&temp2.ran,&choices[0],&choices[1],&choices[2],&choices[3],&choices[4])!=EOF)
            num++;
            myheap heap[num];
    fclose(fp);
    fp=fopen("choices.txt","r");
for(i=0;i<num;i++)
{
    fscanf(fp,"%ld%d%d%d%d%d%d",&temp2.enrl,&temp2.ran,&temp2.c1,&temp2.c2,&temp2.c3,&temp2.c4,&temp2.c5);
    hinsert(heap,temp2,i);
}
fclose(fp);
for(i=0;i<num;i++)
{
    temp2=extractmin(heap,i);
    allocate(avail,temp2,i);
}
cout<<"\n\n\n\n\t\t\t\tSEATS LEFT ARE AS FOLLOWS:";
        for(i=0;i<8;i++)
        {
            cout<<"\n\n\t\t\t\t"<<institutes[i];
            for(j=0;j<4;j++)
            {
            cout<<"\t"<<branches[j]<<" "<<avail[i][j][0];
            }
        }
        cout<<"\n\n\n\n\n\t\t\t\t1. BACK\n\n\t\t\t\t2.EXIT\n\n\t\t\t";
        cin>>c;
if(c==1)
    menu(x);
else
    exit(0);
        }

void menu(long x)
{
        system("color f5");
int res,i,j;
    char clg[25],brnch[25];
int icode,bcode;
 int ***avail=new int**[8];
    for(i=0;i<8;i++)
        avail[i]=new int*[4];
    for(i=0;i<8;i++)
    {
        for(j=0;j<4;j++)
        {
            avail[i][j]=new int;
        }
    }
    for(i=0;i<8;i++)
    {
         for(j=0;j<4;j++)
    {
        if(j==0)
            avail[i][j][0]=2;
        else if(j==1)
            avail[i][j][0]=3;
        else if(j==2)
            avail[i][j][0]=4;
        else
            avail[i][j][0]=1;
    }
    }
FILE *fp1,*fp2;
    fp1=fopen("file1.txt","r");
fp2=fopen("file2.txt","r");
while((fscanf(fp1,"%s%d",clg,&icode))!=EOF)
{
strcpy(institutes[icode%10],clg);
if((fscanf(fp2,"%s%d",brnch,&bcode)!=EOF))
{
strcpy(branches[bcode%10],brnch);
}
   else
    continue;
}
fclose(fp1);
fclose(fp2);
bg();
cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tWELCOME  "<<cand;
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tChoose from the menu:";
cout<<"\n\n\t\t\t\t1.FILL YOUR CHOICES.";
cout<<"\n\n\t\t\t\t2.VIEW YOUR CHOICES.";
cout<<"\n\n\t\t\t\t3.SEE RESULTS.";
cout<<"\n\n\t\t\t\t4.LOGOUT.\n\n\n\n\t\t";
cin>>res;
switch(res)
{
case 1:
    {
enter(x);
break;
    }
case 2:
    {
        view(x);
        break;
    }

case 3:
    {
      result(avail,x);
        break;
    }

case 4:
    {
        login();
        break;
    }
}
}

tree* createbst(tree *root)
{
    long x;
    char a[20],b[30],d[10];
FILE *fp;
fp=fopen("id.txt","r");
while(fscanf(fp,"%s %ld %s",a,&x,b)!=EOF)
{
temp=new tree;
temp->enroll=x;
strcpy(temp->pass,b);
strcpy(temp->name,a);
temp->lc=NULL;
temp->rc=NULL;
root=insertnode(root,temp);
}
fclose(fp);
return root;
}

bool search(long x,char a[],tree *root)
{
    tree *temp=root;
    while(temp!=NULL)
    {
        if(x<temp->enroll)
            temp=temp->lc;
        else if(x>temp->enroll)
            temp=temp->rc;
        else
            {
            if(strcmp(a,temp->pass)==0)
               {
                strcpy(cand,temp->name);
                 return true;
               }
            else
                return false;
        }
    }
    return false;
}

void login(void)
{
    int res,w;
    long x;
    char a[20],b[30];
    tree *root=NULL;
     root=createbst(root);
         system("color f2");
   while(1)
    {
        bg();
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\tPlease Choose From the options below:\n\n\n\n\t\t1. Already an account. Sign in!!\n\n\n\n\t\t";
    cout<<"2.Don't Have an account. Sign up!!\n\n\n\n\t\t";
    cout<<"3.GO BACK\n\n\n\n\t\t";
    cin>>res;
    bg();
    if(res==1)
    {
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER JEE ENROLLMENT NUMBER :  ";
        cin>>x;
        cout<<"\n\n\n\n\t\t\t\t\t\t\t\tENTER PASSWORD :  ";
        cin>>b;
        if(search(x,b,root))
        {
            bg();
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tACCOUNT LOGGED IN SUCCESSFULLY ! !";
           delay(2000);
           menu(x);
            break;
        }
        else
        {
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tSORRY....INVALID USERNAME OR PASSWORD !";
        delay(1000);
        continue;
        }
    }
    if(res==2)
    {
        bg();
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER YOUR NAME : ";
        cin>>a;
        cout<<"\n\n\t\t\t\t\t\t\t\tENTER YOUR ENROLLMENT NUMBER : ";
        cin>>x;
        cout<<"\n\n\t\t\t\t\t\t\t\tCHOOSE YOUR PASSWORD : ";
        cin>>b;
        FILE * fp=fopen("id.txt","a");
        fprintf(fp,"\n%s %ld %s",a,x,b);
        fclose(fp);
        bg();
        cout<<"\n\n\n\n\n\n\n\n\t\t\t\tPlease wait while we sign you up";
        delay(500);cout<<".";delay(500);cout<<".";delay(500);cout<<".";delay(500);cout<<".";
        delay(500);cout<<".";delay(500);cout<<".";delay(500);cout<<".";
        bg();
temp=new tree;
temp->enroll=x;
strcpy(temp->pass,b);
strcpy(temp->name,a);
temp->lc=NULL;
temp->rc=NULL;
root=insertnode(root,temp);
            strcpy(cand,a);
           menu(x);
            break;
    }
    if(res==3)
    {
        bg();
        flag=1;
        return;
    }
        else
        cout<<"/n/n/n/n/t/tINVALID CHOICE.";
    }
    return;
}

int main()
{
    char r;
    int i,j,z;
    system("color f1");
    if(flag==0)
    {
    cout<<"\t\t\t\t\t    ";
    delay(300);
    for(z=0;z<20;z++)
    {
    cout<<"*";
    delay(200);
    }
    cout<<" W";delay(100);cout<<"E";delay(100);cout<<"L";delay(100);cout<<"C";delay(100);

    cout<<"O";delay(100);cout<<"M";delay(100);cout<<"E ";delay(100);cout<<"T";delay(100);

    cout<<"O ";delay(100);cout<<"A";delay(100);cout<<"I";delay(100);cout<<"E";delay(100);

    cout<<"E";delay(100);cout<<"E ";delay(100);cout<<"S";delay(100);cout<<"E";delay(100);

    cout<<"A";delay(100);cout<<"T ";delay(100);cout<<"A";delay(100);cout<<"L";delay(100);

    cout<<"L";delay(100);cout<<"O";delay(100);cout<<"C";delay(100);cout<<"A";delay(100);

    cout<<"T";delay(100);cout<<"I";delay(100);cout<<"O";delay(100);cout<<"N ";delay(100);

    cout<<"S";delay(100);cout<<"Y";delay(100);cout<<"S";delay(100);cout<<"T";delay(100);

    cout<<"E";delay(100);cout<<"M ";delay(100);

    for(z=0;z<20;z++)
    {
    cout<<"*";
    delay(200);
    }
    }
while(1)
 {
 cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t       Please Login To Continue The Counselling Process......";
 cout<<"\n\n\n\n\n\n\n\n\n\n";
 delay(100);
  cout<<"\t\t\t\t\t\t       Press Y to Login or Press E to exit :      ";
    cin>>r;
    if(r=='E'||r=='e')
    {
         system("CLS");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t  ";
    system("color fc");
    cout<<"T";delay(100);cout<<"H";delay(100);cout<<"A";delay(100);cout<<"N";delay(100);

    cout<<"K";delay(100);cout<<"S ";delay(100);cout<<"F";delay(100);cout<<"O";delay(100);

    cout<<"R ";delay(100);cout<<"V";delay(100);cout<<"I";delay(100);cout<<"S";delay(100);

    cout<<"I";delay(100);cout<<"T";delay(100);cout<<"I";delay(100);cout<<"N";delay(100);

    cout<<"G ";delay(100);cout<<"!";delay(100);cout<<"! ";delay(100);
    cout<<"H";delay(100);cout<<"A";delay(100);cout<<"V";delay(100);

    cout<<"E ";delay(100);cout<<"A ";delay(100);cout<<"N";delay(100);cout<<"I";delay(100);

    cout<<"C";delay(100);cout<<"E ";delay(100);cout<<"D";delay(100);cout<<"A";delay(100);

    cout<<"Y ";delay(100);cout<<".";
    delay(500);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
        exit(0);
    }
    else if(r=='Y'||r=='y')
{
login();
}
else
    {
         cout<<"\n\n\n\n\n\t\t\t\t\t\tInvalid Choice......Please choose the correct choice!!\n\n\t\t\t\t\t";
         delay(1000);
         bg();
    }
       }
    return 0;
}
