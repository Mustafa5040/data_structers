def find_prime_factors(n):

    prime_factors = []

    for i in range(2,n+1)

        while n % i == 0 and n > 0:
            prime_factors.append(i)
            n /= i
    return prime_factors



def list_prime_numbers_to_n(n):

    primes = 

    for i i