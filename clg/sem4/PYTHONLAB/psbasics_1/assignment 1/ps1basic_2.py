lst = []
n = int(input("enter the number of elements "))
for i in range(n):
    element = input("enter the element")
    lst.append(element)
print(lst)
for ele in lst:
    splitString = ele.split('.')
    print(splitString[2])
