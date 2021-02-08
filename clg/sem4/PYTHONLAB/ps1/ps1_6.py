def metathesis_pair(word1, word2):
    swap = []
    if len(word1) != len(word2):                # words should be same length
        return False
    else:
        for i in range(len(word1)):             # record the positions of inequality
            if word1[i] != word2[i]:
                swap.append(i)
        if len(swap) != 2:                      # number of characters displaced must be 2
            return False
        else:                                   # checking if the 2 displaced characters on swapping matches
            list1 = []                          # swapping
            list1[:0] = word2
            temp = list1[swap[0]]
            list1[swap[0]] = list1[swap[1]]
            list1[swap[1]] = temp
            word2 = "".join(list1)
            if word1 == word2:
                return True
            else:
                return False


w1 = input("Enter the word 1 :")
w2 = input("Enter the word 2 :")
if metathesis_pair(w1, w2):
    print("They are a metathesis pair")
else:
    print("They are not a metathesis pair")
