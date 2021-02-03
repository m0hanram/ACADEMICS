import random


def main():
    uppercase = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'M', 'N', 'O', 'p', 'Q', 'R', 'S', 'T', 'U',
                 'V',
                 'W', 'X', 'Y', 'Z']
    lowercase = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
                 'v',
                 'w', 'x', 'y', 'z']
    special = ['@', '#', '$', '%', '=', ':', '?', '.', '/', '|', '~', '>', '*', '(', ')']
    number = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    collab = uppercase + lowercase + special + number
    must = []
    must.append(random.choice(uppercase))
    must.append(random.choice(lowercase))
    must.append(random.choice(special))
    must.append(random.choice(number))
    n = int(input("Enter the size of password : "))
    pswd = []
    password = ""
    for i in range(n - 4):
        pswd.append(random.choice(collab))
        print(i)
    pswd += must
    print(must)
    for j in pswd:
        password += str(j)
    print("The strongly recommended password is : " + password)


if __name__ == '__main__':
    main()
