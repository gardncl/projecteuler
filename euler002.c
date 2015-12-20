#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//https://www.hackerrank.com/contests/projecteuler/challenges/euler002
//December 19th, 2015

unsigned long sumEvenFibonacci(long number){
    long f0=1;
    long f1=2;
    unsigned long evens=0;
    while (f1 < number) {
    	if (f1%2==0)
    		evens+=f1;
    	f1 = f1+f0;
    	f0 = f1-f0;
    }
    return evens;
}

int main() {
	int count, i;
	scanf("%d\n", &count);
	for (i = 0; i < count; i++){
		unsigned long n; 
		unsigned long total;
		scanf("%ld\n", &n);
   	 	total = sumEvenFibonacci(n);
		printf("%lu\n", total);
    }
	return 0;
}