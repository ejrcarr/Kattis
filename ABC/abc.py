arr = [int(i) for i in input().split(" ")]
arr.sort()

temp = ""
for letter in input():
    if letter == "C":
        temp += str(arr[-1]) + " "
    elif letter == "B":
        temp += str(arr[1]) + " "
    else:
        temp += str(arr[0]) + " "

print(temp[:-1])