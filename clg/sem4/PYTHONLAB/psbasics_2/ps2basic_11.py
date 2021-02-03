import re

cmd1 = input("Enter the command : ")
if re.search("^let [a-z] = ([-+/*]\d+(\.\d+)?)*", cmd1):
    split_cmd = cmd1.partition("=")
    exp = split_cmd[2]
cmd2 = input("Enter the command : ")
if re.search("^print expression", cmd2):
    print(exp)
