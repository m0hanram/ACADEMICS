def most_frequent(string):
    array = []
    frequency = []
    dic = {}
    for i in range(len(string)):
        if string[i] == " ":
            continue
        if string[i] in array:                  # skip if already counted
            continue
        array.append(string[i])                 # character to count the number of appearances
        count = 1
        for j in range(i+1, len(string)):
            if string[i] == string[j]:
                count += 1
        frequency.append(count)
    for k in range(len(frequency)):             # writing into a dictionary
        dic.update({array[k]: frequency[k]})
    return dic


inp = input("enter the string : ")
print("The dictionary :")
print(most_frequent(inp))
