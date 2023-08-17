
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

// function prototypes
unsigned long long int recursiveFactorial(unsigned long long int number);
unsigned long long  int iterativeFactorial(unsigned long long int number);
long double recursiveSeriesE();
long double iterativeSeriesE();
void repeatRecursiveE();
void repeatIterativeE();

int main(void){
	//variables
	clock_t start, end;
	double recTime, iterTime;
	


	// Question 2 repeat recurrsive series e 20 times 
	printf("Series e calculated with a recursive function is: %Lf\n", recursiveSeriesE());

	printf("\n");

	// Question 3 repeat iterative series e 20 times 
	printf("Series e calculated with a iterative function is: %Lf\n", iterativeSeriesE());


	// Question 4 & 5 - measure time of e series - looped 10k times
	start = clock();
	repeatRecursiveE();
		end = clock();
	recTime = ((double)(end - start)) / CLOCKS_PER_SEC;


	start = clock();
	repeatRecursiveE();
	end = clock();
	iterTime = ((double)(end - start)) / CLOCKS_PER_SEC;

	// print out times
	printf("\n");
	printf("Iterative e series took %f seconds to execute \n", iterTime);
	printf("Recursive e series took %f seconds to execute \n", recTime);


}// end of main


// function outside of main
// Question 1
unsigned long long int  recursiveFactorial(unsigned long long int number)
{
	//base case
	if (number <= 1) {
		return 1;
	}
	else { // recursive step
		return (number * recursiveFactorial(number - 1));
	} // end if else

}
unsigned long long int iterativeFactorial(unsigned long long int number)
{

	unsigned long long int i, factorial = 1;

	for (i = 1; i <= number; i++) {
		factorial = factorial * i;
	}

	return factorial;
}

// Question 2 repeat recurrsive series e 20 times 
long double recursiveSeriesE()
{
	long double re = 0;
	for (unsigned long long int i = 0; i <= 20; i++) {

		printf("Factorial of %llu = %llu\n", i, recursiveFactorial(i));
		re += (1.0 / recursiveFactorial(i)); // calculate series e from recursive function	
	}
	return re;
}
// Question 3 repeat iterative series e 20 times 
long double iterativeSeriesE()
{
	long double ri = 0;
	for (unsigned long long int i = 0; i <= 20; i++) {

		printf("Factorial of %llu = %llu\n", i, iterativeFactorial(i));
		ri += (1.0 / iterativeFactorial(i)); // calculate series e from iterative function
	}
	return ri;
}

// Question 4 - function loops recursive and iterative loops 10k times
void repeatRecursiveE()
{
	for (int i = 0; i <= 10000; i++) {
		printf("\n");
		printf("Series e calculated with a recursive function is: %Lf\n", recursiveSeriesE());
	}
	
}

void repeatIterativeE()
{
	for (int i = 0; i <= 10000; i++) {
		printf("\n");
		printf("Series e calculated with a recursive function is: %Lf\n", iterativeSeriesE());
	}
	
}







