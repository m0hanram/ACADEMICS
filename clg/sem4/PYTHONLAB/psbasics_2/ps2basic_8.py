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
print("intersection", a.intersection(b))
print("difference a-b", a.difference(b))
print("union", a.union(b))
print("symmetric difference", a.symmetric_difference(b))

