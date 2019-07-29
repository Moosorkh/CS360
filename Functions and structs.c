#include <stdio.h>
//Declaring string.h directive to use the strcmp fucntion
#include <string.h>
#define s 5
#define c 20

//Defining the Employee struct
struct employee {
	int i;
	char pr[20]; // Two dimentional array for storing the name of the person
	double hw;// Number of hours they worked per week
	double sr;//Salary rate
	double wp;//Weekly Payment
	double tax;
};

void read(struct employee empl1[s],int i);
void calc(struct employee empl2[s], int i);
void print(struct employee empl3[s]);

int main()
{
	int i = 0;
	/*char pr[s][c]; // Two dimentional array for storing the name of the person
	double hw[s];// Number of hours they worked per week
	double sr[s];//Salary rate
	double wp[s];//Weekly Payment
	double tax[s];
	*/


	struct employee empl4[s];

	read(empl4,i);
	calc(empl4,i);
	print(empl4);


	system("pause");
	return 0;
}
void read(struct employee empl[s],int i)
{
	//Input the person's name and number of hours of work per week plus pay rate
	for (i = 0;i < s;i++)
	{
		printf("\n");
		printf("Enter person%d's name: ", i + 1);
		scanf_s("%s", empl[i].pr, 20);
		//Using the strcmp function to compare strings
		if (strcmp(empl[i].pr, "-1") == 0)
			break;

		printf("Enter the number of hours they work weekly: ");
		scanf_s("%lf", &empl[i].hw);
		if (empl[i].hw == -1)
			break;

		printf("Enter their salary rate: ");
		scanf_s("%lf", &empl[i].sr);
		if (empl[i].sr == -1)
			break;
	}
}
void calc(struct employee empl2[s], int i)
{
	//Calculate each person's Weekly payment (wp) and tax rate
	for (i = 0;i < s;i++)
	{
		empl2[i].wp = empl2[i].hw * empl2[i].sr;
		empl2[i].tax = (empl2[i].wp * 20) / 100;
	}
}

void print(struct employee empl3[s])
{	
	//Print each person's information and clculated payment and after tax payment
	for (int j = 0;j < s;j++)
	{
			if (strcmp(empl3[j].pr, "-1") == 0)
				break;
			if (empl3[j].hw == -1)
				break;
			if (empl3[j].sr == -1)
				break;
			printf("\n");
			printf("1-%s works %.0lf hours per week\n", empl3[j].pr, empl3[j].hw);
			printf("2-Their hourly pay rate is $%.2lf\n", empl3[j].sr);
			printf("3-Weekly salary before tax is: $%.2lf\n", empl3[j].wp);
			printf("4-Tax amount paid by %s is $%.2lf\n", empl3[j].pr, empl3[j].tax);
			printf("5-Paycheck after tax is $%.2lf\n", empl3[j].wp - empl3[j].tax);
		
	}
}
