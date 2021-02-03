print("-- Welcome to HANGMAN --")
ans = ['_', '_', '_', '_', '_', '_', '_', '_', '_']
ques = ('E', "V", "A", 'P', 'O', 'R', 'A', 'T', 'E')
won = False
guess = []
index = set()
while not won:
    c = input("Enter your GUESS : ")
    if c not in guess:
        guess.append(c)
    else:
        print("You already tried that one and that didnt work :( ")
        continue
    if c in ques:
        print("Bravo !!!!")
        for x in range(len(ques)):
            if ques[x] == c:
                index.add(x)
        while index != set():
            ans[index.pop()] = c
        print(ans)
    else:
        print("Oops sorry , wrong guess !!")
    count = 0
    for y in ans:
        if y == "_":
            count += 1
    if count == 0:
        won = True
print("Well done CHAMP !")
