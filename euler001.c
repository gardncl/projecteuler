#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//https://www.hackerrank.com/contests/projecteuler/challenges/euler001
//December 19th, 2015

unsigned long repeats(int r, unsigned long number){
    number = number - (number%r);
    unsigned long t = number/r;
    return (t*(number+r))/2;
}
unsigned long multi3and5(unsigned long number) {
	number = number - 1;
	return repeats(3,number)+repeats(5,number)-repeats(15,number);
}
int main() {
	int count, i;
	scanf("%d\n", &count);
	for (i = 0; i < count; i++){
		unsigned long limit; 
		unsigned long total;
		scanf("%ld\n", &limit);
   	 	total = multi3and5(limit);
		printf("%lu\n", total);
    }
	return 0;
}