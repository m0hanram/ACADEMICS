encodedString = ""
inputString = input("Enter the string to be encoded")
i = 0
while i < len(inputString):
    count = 1
    while i+1 < len(inputString) and inputString[i] == inputString[i+1]:
        count += 1
        i += 1
    encodedString += str(count) + inputString[i]
    i += 1
print(encodedString)









