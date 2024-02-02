cost = float(input())
num = int(input())
curr_sum = 0
for i in range(num):
    first, second = [float(i) for i in input().split(" ")]
    curr_sum += first * second
print(curr_sum * cost)