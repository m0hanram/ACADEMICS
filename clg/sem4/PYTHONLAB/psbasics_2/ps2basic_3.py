lst1 = [1, 3, 6, 78, 35, 55]
lst2 = [12, 24, 35, 24, 88, 120, 155]
lst3 = []
for x in lst1:
    for y in lst2:
        if x == y:
            lst3.append(x)
print(lst3)
