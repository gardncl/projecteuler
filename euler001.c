#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


/* 
Project Euler: Problem 1
December 19th, 2015
Clay Gardner

https://projecteuler.net/problem=1
Solved the above problem.
Input: 1 1000 
Output: 233168
Time: sys	0m0.003s

https://www.hackerrank.com/contests/projecteuler/challenges/euler124
Solved for full points.
*/

//Finds sum of all multiples of r under number
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