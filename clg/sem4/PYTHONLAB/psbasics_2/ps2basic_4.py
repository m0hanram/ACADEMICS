a = set()
m = int(input("enter the number of elements : "))
for x in range(m):
    ele = int(input("enter the element : "))
    a.add(ele)
    if x == 0:
        minimum = ele
        maximum = ele
    else:
        if ele < minimum:
            minimum = ele
        if ele > maximum:
            maximum = ele
print("maximum is = ", maximum)
print("minimum is = ", minimum)
print(a)
