#include<iostream>
using namespace std;
int main()
{
	char name[25];
	int salary,exp;
	cout<<"Enter employee name : ";
	cin>>name;
	cout<<"Enter Basic salary : ";
	cin>>salary;
	cout<<"Enter experience : ";
	cin>>exp;
	cout<<"Name    Salary    Increment\n";
	
	if(exp<=3)
	{
		
		cout<< name<<"  "<< salary<<"     "<< 1000+salary*(10/100);
	}
	else if(exp>3 && exp<=5)
	{
		cout<< name<<"  "<< salary<<"     "<< 3000+(12*salary)/100;		
	}
    else if(exp>5 && exp<=10)
	{
		cout<< name<<"  "<< salary<<"     "<< 5000+(15*salary)/100;		
	}
	else if(exp>10)
	{
		cout<< name<<"  "<< salary<<"     "<< 8000+(20*salary)/100;				
	}
	return 0;
}
