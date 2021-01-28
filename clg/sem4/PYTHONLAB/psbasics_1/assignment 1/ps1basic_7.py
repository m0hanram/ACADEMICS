def panagram_func(sentence):
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    for i in alphabet:
        if i not in sentence.lower():
            return "false"
    return "true"


sen = input("enter the sentence : ")
if (panagram_func(sen) == "true"):
    print("it is a panagram")
else:
    print("it is not a panagram")

