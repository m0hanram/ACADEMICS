n = int(input("enter the number of elements : "))
array = []
for i in range(n):
    array.append(int(input("Enter the element : ")))
array.sort()
sumEle = 0
for i in range(1, n-1):
    sumEle += array[i]
centeredAvg = sumEle/(len(array)-2)
print(centeredAvg)