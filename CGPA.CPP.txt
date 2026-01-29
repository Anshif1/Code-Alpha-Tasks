#include<iostream.h>
#include<iomanip.h>
#include<conio.h>

int main()
{
int n,i;
float grade,credit;
float totalCredits=0,totalGradePoints=0;

clrscr();

cout<<"ENTER NO.OF COURSES:";
cin>>n;

cout<<"\nENTER COURSE DETAILES\n";

for(i=1;i<=n;i++)
{
cout<<"\nCourse"<<i<<"\n";
cout<<"ENTER GRADE(OUT OF 10):";
cin>>grade;
cout<<"ENTER CREDIT HOURS:";
cin>>credit;

totalCredits += credit;
totalGradePoints += grade*credit;
}

float gpa=totalGradePoints/totalCredits;

cout<<"\nTotalCredits:"<<totalCredits;
cout<<"\nTotal Grade Points:"<<totalGradePoints;
cout<<"\nFinal CGPA:"<<setprecision(2)<<gpa;

getch();
return 0;
}
