def Fibonacci(n):
	if n <= 0:
		return 0
	if n == 1:
		return 1
	return Fibonacci(n - 1) + Fibonacci(n - 2);

def Fibonacci_1(n):
	result = [0, 1]
	if n < 2:
		return result[n]
		
	FibmOne = 1
	FibmTwo = 0
	Fib = 0
	for i in range(n - 1):
		Fib = FibmOne + FibmTwo
		FibmTwo = FibmOne
		FibmOne = Fib
	return Fib	
	
def Fibonacci_2(n):
	
print Fibonacci_1(1000000)