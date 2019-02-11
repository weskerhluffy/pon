#!/Library/Frameworks/Python.framework/Versions/3.7/bin/python3
# XXX: https://www.geeksforgeeks.org/prime-functions-python-sympy/
import sympy 
t=int(input())
for _ in range(t):
	n=int(input())
	if sympy.isprime(n):
		print("YES")
	else:
		print("NO")
