#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


/* 
Project Euler: Problem 6
December 20th, 2015
Clay Gardner

https://projecteuler.net/problem=6
Solved the above problem.
Input: 1 10
Output: 2640
Time: sys	0m0.003s

https://www.hackerrank.com/contests/projecteuler/challenges/euler006
Solved for full points.
*/

long sum(long n) {
    return (n*(n+1))/2;
}
long squaredSum(long n){
	return (n*(n+1)*(2*n+1))/6;
}
long squaredDifference(long n) {
	return pow(sum(n),2)-squaredSum(n);
}

int main() {
	int count, i;
	long n, sd;
	scanf("%d\n", &count);
	for (i = 0; i < count; i++){
		scanf("%lu\n", &n);
   	 	sd = squaredDifference(n);
		printf("%lu\n", sd);
    }
	return 0;
}