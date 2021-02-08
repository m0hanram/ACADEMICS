def function(dic, val):
    lst = dic.keys()                                        # making the key values into a list
    ret_dic = {}
    for x in lst:
        if dic[x]["instrument"] == val:
            ret_dic.update({str(x).capitalize(): dic[x]})   # adding to the new dictionary
    return ret_dic


alonzo = {"age": 10, "height": 42, "weight": 175, "instrument": "fiddle"}
turing = {"age": 41, "height": 70, "weight": 160, "instrument": "theremin"}
bertha = {"age": 32, "height": 97, "weight": 587, "instrument": "cello"}
tinkerB = {"age": 100, "height": 4, "weight": 0.5, "instrument": "cello"}
banditos = {"Alonzo": alonzo, "Turing": turing, "Bertha": bertha, "TinkerB": tinkerB}
inst = input("Enter the instrument that you want to group by : ")
new_dic = function(banditos, inst)
print(new_dic)
