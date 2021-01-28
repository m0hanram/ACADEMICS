def dic_func(x):
    dic = {}
    for i in range(1, x+1):
        dic[i] = i*i
    return dic

y = int(input("enter the number : "))
ans = dic_func(y)
print(ans)
