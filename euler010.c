#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


/* 
Project Euler: Problem 7
December 20th, 2015
Clay Gardner

https://projecteuler.net/problem=10
Solved the above problem.
Input: 1 2000000
Output: 62260698721
Time: sys	0m0.004s

https://www.hackerrank.com/contests/projecteuler/challenges/euler010
Solved for full points.
*/
//Creates an array of primes using bsmooth technique
void bsmooth(unsigned long *primes, unsigned long n){
	unsigned long i,c=1,num=3;
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
//Sums primes up until n
unsigned long sumPrimes(unsigned long *primes, long n) {
	unsigned long sum=0;
	int i = 0;
	while (primes[i] <= n) {	
		sum=sum+primes[i];
		i++;
	}
	return sum;
}
//Create array of primes
//Pick from them
int main() {
	int count, i;
	unsigned long n,p;
	unsigned long primes[100000];
	bsmooth(&primes[0],100000);
	scanf("%d\n", &count);
	for (i = 0; i < count; i++){
		scanf("%lu\n", &n);
		p = sumPrimes(primes,n);
		printf("%lu\n", p);
    }
	return 0;
}