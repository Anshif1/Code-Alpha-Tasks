#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>

/*Function declarations*/
int userExists(char username[]);
void registerUser();
void loginUser();

int main()
{
int choice;
clrscr();

printf("\n=====LOGIN & REGISTRATION SYSTEM=====\n");
printf("1.Register\n");
printf("2.Login\n");
printf("Enter choice:");
scanf("%d",&choice);

switch(choice)
{
case 1:
registerUser();
break;
case 2:
loginUser();
break;
default:
printf("Invalid choice!\n");
}
getch();
return 0;
}
/*Check if username already exists*/
int userExists(char username[])
{
char u[50],p[50];
ifstream file("user.dat");
if(!file)
return 0;

while(file>>u>>p)
{
if(strcmp(u,username)==0)
{
file.close();
return 1;
}
}
file.close();
return 0;
}
/*Registration function*/
void registerUser()
{
char username[50],password[50];
ofstream file;

printf("\n---USER REGISTRATION---\n");
printf("Enter username:");
scanf("%s",username);

printf("Enter password:");
scanf("%s",password);

/*validation*/
if(strlen(username)<3 || strlen(password)<3)
{
printf("Error:Username&password must be at least 3 characters!\n");
return;
}

/*Duplicate username check*/
if(userExists(username))
{

printf("Error:Username already exists!\n");
return;
}
file.open("user.dat",ios::app);
file<<username<<""<<password<<endl;
file.close();

printf("Registration successful!\n");
}

/*Login fuction*/
void loginUser()
{
char username[50],password[50];
char u[50],p[50];
int success=0;
ifstream file;

printf("\n---USER LOGIN--\n");
printf("Enter username:");
scanf("%s",username);

printf("Enter password:");
scanf("%s",password);
file.open("user.dat");

if(!file)
{
printf("no users registered yet!\n");
return;
}

while(file>>u>>p)
{
if(strcmp(u,username)==0&&strcmp(p,password)==0)
{
success=1;
break;
}
}
file.close();

if(success)

printf("Login successfull! Welcome%s\n",username);

else

printf("Login failed! Invalid username or password.\n");
}
