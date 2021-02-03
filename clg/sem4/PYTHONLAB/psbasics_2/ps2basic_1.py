inp = input("enter the words separated by whitespaces : ")
lst = inp.split()
lst.sort()
length = len(lst)
for x in range(length):
    if x < length-1:
        if lst[x] == lst[x+1]:
            del lst[x+1]
            x -= 1
            length -= 1
print(' '.join(lst))
