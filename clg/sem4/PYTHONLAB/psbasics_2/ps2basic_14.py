def function(lst):
    length = len(lst)
    for x in range(length):
        i = x+1
        while i < length:
            if lst[x] == lst[i]:
                del lst[i]
                length -= 1
                i -= 1
            i += 1


a = []
m = int(input("enter the number of elements : "))
for y in range(m):
    ele = int(input("enter the element : "))
    a.append(ele)
print(a)
function(a)
print(a)
