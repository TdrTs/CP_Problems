#include <stdio.h>

int recFunction(int value, int power);
int nonRecFunction(int value, int power);

int main(){

	printf("Give the value of the function \n");
	int x;
	scanf("%d",&x);

	printf("Give the maximum power of the function \n");
	int pow;
	scanf("%d",&pow);

	printf("The value of the recursive function is %d \n",recFunction(x, pow));
	printf("The value of the NON recursive function is %d \n",nonRecFunction(x, pow));
	return 0;
}


int recFunction(int value, int power){
	
	if (power == 0) {
		return 1;
	} else 
		if (power == 1) {
			return 2 * value;
		} else {
			return (2*power*recFunction(value, power - 1) - 2 * (power - 1) * recFunction(value, power - 2));
		}
}

int nonRecFunction(int value, int power){
	
	int result, hn1, hn2;

	hn2 = 1;
	hn1 = 2 * value;
		
	if (power == 0) 
		return hn2;
	if (power == 1)
		return hn1;
	
	for (int i = 2; i <= power; i++){	
		result = 2*i*hn1 - 2 * (i - 1) * hn2;
		hn2 = hn1;
		hn1 = result;
	}
	
	return result;
}

