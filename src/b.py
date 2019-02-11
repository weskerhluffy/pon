# XXX: https://stackoverflow.com/questions/13326673/is-there-a-python-library-to-list-primes
import gmpy2

def primes():
    n = 67280421310721
    while True:
        yield n
        n = gmpy2.next_prime(n)

p=primes()
for i in range(500):
	print(next(p))
