#include<stdio.h>
void SeedRandom(){
	srand(time(NULL));
	printf("Enemy Generator\n");
}
float GetRandom(float low, float high);
void ClearInputBuffer();
int main(){
	float a,b;

	SeedRandom();
	GetRandom(a,b);


}