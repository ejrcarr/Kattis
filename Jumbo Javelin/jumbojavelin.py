number = int(input())
sum = 0
for i in range(number):
    newNum = int(input())
    sum += newNum
    
print(sum - number + 1)