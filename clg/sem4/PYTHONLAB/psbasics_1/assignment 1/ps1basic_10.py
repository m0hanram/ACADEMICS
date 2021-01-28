def has22(lst, no):
    for i in range(no):
        # print(i," ",i+1)
        if lst[i] == 2 and i < len(lst)-1:
            if lst[i+1] == 2:
                return True
    return False


x = []
n = int(input("Enter the number of elements : "))
for j in range(n):
    x.append(int(input("Enter the element : ")))
if has22(x, n):
    print("true")
else:
    print("false")
