#include<stdio.h>
int main()
{
	int s = 0;
	int sp = 0;
	int d = 0;
	int i = 0;
	int sum = 0;
	double l = 0;
	printf("Please enter your desired stats for your character:\n");
	printf("Enter strength : ");
	scanf_s("%d", &s);
	printf("Enter speed: ");
	scanf_s("%d", &sp);
	printf("Enter defense: ");
	scanf_s("%d", &d);
	printf("Enter intelligence: ");
	scanf_s("%d", &i);
	sum = s + sp + d + i;

	float m1, m2, m3, m4;
	m1 = (float)s / sum;
	m2 = (float)sp / sum;
	m3 = (float)d / sum;
	m4 = (float)i / sum;
	int s1, sp1, d1, i1;
	s1 = (double)m1 * 100;
	sp1 = (double)m2 * 100;
	d1 = (double)m3 * 100;
	i1 = (double)m4 * 100;
	l = (int)sum % 30;
	printf("Your player's final states are:\n");
	printf(" Strength: %d\n", s1);
	printf("Speed:%d\n", sp1);
	printf(" Defense:%d\n ", d1);
	printf("Intelligence: %d\n", i1);
	printf("Luck: %d\n", l);


}
