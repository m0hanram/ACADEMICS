print("enter for set a")
a = set()
m = int(input("enter the number of elements : "))
for x in range(m):
    ele = int(input("enter the element : "))
    a.add(ele)
print("enter for set b")
b = set()
n = int(input("enter the number of elements : "))
for y in range(n):
    ele = int(input("enter the element : "))
    b.add(ele)
print(a)
print(b)
if a.difference(b) == set():
    print('The two sets A and B are equal')
else:
    b1 = b.difference(a)
    b2 = a.difference(b)
    print("The elements in b1 = ", b1)
    print("The elements in b2 = ", b2)
