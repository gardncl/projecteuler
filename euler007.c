#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


/* 
Project Euler: Problem 7
December 20th, 2015
Clay Gardner

https://projecteuler.net/problem=7
Solved the above problem.
Input: 1 10001
Output: 140734703483928
Time: sys	0m0.004s

https://www.hackerrank.com/contests/projecteuler/challenges/euler007
Solved for full points.
*/
//Creates an array of primes using bsmooth technique
void bsmooth(long *primes, long n){
	long i,c=1,num=3;
	int p;
	double sqrtN;
	primes[0]=2;
	while(c<n){
		sqrtN = sqrt(num);
		p=1;
		i=0;
		while(primes[i] <= sqrtN) {
			if (num%primes[i]==0){
				p=0;
				break;
			}
			i++;
		}
		if(p){
			primes[c]=num;
			c++;
			num++;
		} else {
			num++;
		}
	}
}

//Create array of primes
//Pick from them
int main() {
	int count, i;
	long n,p;
	long primes[10000];
	bsmooth(&primes[0],10000);
	scanf("%d\n", &count);
	for (i = 0; i < count; i++){
		scanf("%lu\n", &n);
		printf("%lu\n", primes[n-1]);
    }
	return 0;
}