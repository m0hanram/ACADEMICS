inp = input("Enter the sentence along with line number at the starting separated with ']' : ")
sent = inp.split(". ")
ans = []
for sen in sent:
    word_and_number = sen.split("]")
    # print(word_and_number)
    word = word_and_number[1].split()
    ans.append([word_and_number[0], word])
print(ans)
