def prime_function(x):
    f = 0
    for i in range(2, x):
        if x % i == 0:
            f = 1
            break
    if f == 0:
        print("it is a prime number")
    else:
        print("it is not a prime number")

y = int(input("enter the number to be checked"))
prime_function(y)
for x in range(2,51):
    print(x)
    prime_function(x)



