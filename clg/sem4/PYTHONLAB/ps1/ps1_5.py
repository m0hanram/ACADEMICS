def function(dic):
    lst = dic.keys()                            # making the key values into a list
    ranking = [0, 0, 0, 0]
    for x in lst:                               # counting and recording the votes
        if x != "alice":
            ranking[0] += dic[x]["alice"]
        if x != "bob":
            ranking[1] += dic[x]["bob"]
        if x != "alonzo":
            ranking[2] += dic[x]["alonzo"]
        if x != "turing":
            ranking[3] += dic[x]["turing"]
    for y in range(len(ranking)):
        if ranking[y] == max(ranking):          # least popular will be maximum
            return list(lst)[y]


alice_ratings = {"alonzo": 1, "bob": 3, "turing": 2}
bob_ratings = {"alice": 1, "alonzo": 2, "turing": 3}
alonzo_ratings = {"alice": 3, "bob": 2, "turing": 1}
turing_ratings = {"alice": 2, "alonzo": 1, "bob": 3}
friends = {"alice": alice_ratings, "bob": bob_ratings, "alonzo": alonzo_ratings, "turing": turing_ratings}
print("The least favourite is : ", function(friends))
