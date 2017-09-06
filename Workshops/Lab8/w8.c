#include <stdio.h>
//#include<Fraction.h>
struct Fraction
{
	int  numerator;
	int denominator;
};
void enter(struct Fraction*far); 
void simplify(struct Fraction*); 
void display(const struct Fraction*);
int main(void)
{
	struct Fraction f; //abc 
	//int num;

	printf("Fraction Simplifier\n");
	printf("===================\n");

	 enter(&f);
	 simplify(&f);
	 display(&f);
	 return 0;
}
void enter(struct Fraction* f){
	//int numerator, denominatore;  
	printf("Enter Numerator :");
	scanf_s("%d", (&f->numerator));// avi rite
	printf("\nEnter denominators:");
	scanf_s("%d", (&f->denominator));
}
void simplify(struct Fraction* f){

	int i,gcd;
    for (i = 1; i <= (f->numerator) && i <= (f->denominator); ++i)                              //http://www.programiz.com/c-programming/examples/hcf-gcd
	{
		// Checks if i is factor of both integers
		if ((f->numerator) % i == 0 && (f->denominator) % i == 0)
			gcd = i;
	}
	// Find  Fraction

	f->numerator = (f -> numerator) / gcd;
	f->denominator = (f -> denominator) / gcd;
}
void display(const struct Fraction* f){
	printf("\n\n%d/%d", f->numerator, f->denominator);
}
