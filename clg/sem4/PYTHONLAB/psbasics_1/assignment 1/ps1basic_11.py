def keprekar(n):
    sqr = int(n)*int(n)
    l = len(n)
    if len(str(sqr)) % 2 == 0:
        q = str(sqr)[:int(l)]
        r = str(sqr)[int(l):]
    else:
        q = str(sqr)[:int(l)-1]
        r = str(sqr)[int(l)-1:]
    print(q, r)
    num = int(q)+int(r)
    print(num)
    if num == int(n):
        return "true"
    else:
        return "false"


x = input("enter the number : ")
if keprekar(x) == "true":
    print("yes it is a keprekar number")
else:
    print("no it is not a keprekar number")