def maximum(lst):
    if len(lst) == 1:               # return when its the only element
        return lst[0]
    else:
        m = maximum(lst[1:])        # recursive call
        if m > lst[0]:              # returns the greater element
            return m
        else:
            return lst[0]


def main():
    inp = []
    n = int(input("enter the number of elements in the list"))
    for i in range(n):
        ele = int(input("enter the element : "))
        inp.append(ele)
    print("the maximum element is : "+str(maximum(inp)))


if __name__ == '__main__':
    main()
