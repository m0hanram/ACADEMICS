def most_frequent(string):
    array = []
    frequency = []
    for i in range(len(string)):
        if string[i] == " ":
            continue
        if string[i] in array:              # skip if already counted
            continue
        array.append(string[i])             # character added to count the appearances
        count = 1
        for j in range(i+1, len(string)):   # counting number of appearances
            if string[i] == string[j]:
                count += 1
        frequency.append(count)
    print(array, frequency)                 # testing purpose
    k = 0
    while k < len(frequency):               # descending ordering
        maximum = max(frequency)
        for m in range(len(array)):
            if maximum == frequency[m]:
                print(array.pop(m) + " : " + str(frequency.pop(m)))
                break
        if len(frequency) > 0:
            k -= 1
        else:
            break


inp = input("enter the string : ")
print("The frequency in descending order : ")
most_frequent(inp)




