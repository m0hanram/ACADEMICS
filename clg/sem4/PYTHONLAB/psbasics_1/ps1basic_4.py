S = list(input("enter the string"))
s = input("enter the no. as char separated by space")
lst = s.split(" ")
i = int(lst[0])
c = lst[1]
S[i] = c
print("".join(S))
