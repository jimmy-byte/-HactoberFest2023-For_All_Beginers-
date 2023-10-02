#include <stdio.h>

int main() {

  int n, i, flag = 0;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  // 0 and 1 are not prime numbers
  // change flag to 1 for non-prime number
  if (n == 0 || n == 1)
    flag = 1;

  for (i = 2; i <= n / 2; ++i) {

    // if n is divisible by i, then n is not prime
    // change flag to 1 for non-prime number
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }

  // flag is 0 for prime numbers
  if (flag == 0)
    printf("%d is a prime number.", n);
  else
    printf("%d is not a prime number.", n);

  return 0;
}

   ///*********************Efficient Code to check Prime or not****************************//

   #include <stdio.h>
#include <stdbool.h>

#define MAX 10000 // Define the maximum number you want to check for primes

void sieveOfEratosthenes(bool isPrime[], int n) {
    // Initialize all numbers as prime
    for (int i = 2; i <= n; i++) {
        isPrime[i] = true;
    }

    for (int p = 2; p * p <= n; p++) {
        // If isPrime[p] is not changed, then it's a prime
        if (isPrime[p]) {
            // Mark all multiples of p as not prime
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
}

int main() {
    bool isPrime[MAX + 1];
    int n;

    printf("Enter a number to check if it's prime: ");
    scanf("%d", &n);

    if (n < 2 || n > MAX) {
        printf("Number out of range or less than 2.\n");
        return 1;
    }

    sieveOfEratosthenes(isPrime, MAX);

    if (isPrime[n]) {
        printf("%d is a prime number.\n", n);
    } else {
        printf("%d is not a prime number.\n", n);
    }

    return 0;
}
