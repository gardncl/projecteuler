#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* 
Project Euler: Problem 124
December 20th, 2015
Clay Gardner

https://projecteuler.net/problem=124
Solved the above problem.
Input: 1 100000 10000
Output: 21417
Time: sys 0m0.019s

https://www.hackerrank.com/contests/projecteuler/challenges/euler124
Still not solved; time limit exceeded. Probably need an analytical solution. 
*/

int isPrime(long n) {
    long i;
    double sqrtN = sqrt((double)n);
    if(n<2) return 0;
    if(n <=3) {
        return n>1;
    } else if(n%2==0 || n%3 ==0) {
        return 0;
    } else {
        for(i = 6; i <= sqrtN+1; i+=6) {
           if(n%(i-1)==0 || n%(i+1)==0)
            return 0;
        }
    }
    return 1;
}

long rad(long n) {
    //Creates a product of unique 
    //primes for a number
    long product=1,i;
    if(isPrime(n)){
        return n;
    }
    i=2;
    while(n!=1){
        if(n%i==0){
            product*=i;
            while(n%i==0){
                n=n/i;
            }
        }
        i++;
    }
    return product;
}

void fillArray(long *array,long *indices,long l) {
    long i;
    for(i=0;i<l;i++){
        array[i]=rad(i+1);
        indices[i]=i+1;
    }
}

void insertionSort(long *array,long *indices,long l) {
    int i,d,t1,t2,j;
    for(i=1;i<l;i++){
        d=i;
        while (d > 0 && array[d] < array[d-1]) {
            t1          = array[d];
            t2 = indices[d];
            array[d]   = array[d-1];
            indices[d] = indices[d-1];
            array[d-1] = t1;
            indices[d-1] = t2;

            d--;
        }
    }
    

}
int main() {
	int count, i,j;
	scanf("%d\n", &count);
	for (i = 0; i < count; i++){
		long l; 
		long k;
		scanf("%lu %lu\n", &l, &k);
        long array[l];
        long indices[l]; 
        //Fill an array with the radical numbers and
        //a corresponding array with indices.
   	 	fillArray(&array[0],&indices[0],l); 
        //Since the array is mostly sorted and we want a
        //stable sorting algorithm I chose insertion sort.
        insertionSort(&array[0],&indices[0],l);
        //Now we print the index of the kth radical number
        printf("%lu\n",indices[k-1]);
		
    }
	return 0;
}