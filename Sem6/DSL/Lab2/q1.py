a, b = 0, 1
max_fib = 100

while a <= max_fib:
    print(a, end=' ')
    a, b = b, a + b
else:
    print("\nThe Fibonacci sequence has ended.")