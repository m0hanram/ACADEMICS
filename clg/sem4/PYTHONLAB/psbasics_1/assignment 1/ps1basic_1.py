ans = []
for x in range(2000, 3501):
    if (x % 7 == 0) and (x % 5 != 0):
        ans.append(str(x))
print(','.join(ans))




