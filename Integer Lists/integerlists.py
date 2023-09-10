from collections import deque

cases = int(input())

for _ in range(cases):
    command, n, arr = input(), int(input()), input()[1:-1].split(',')
    arr = [i for i in arr if i != '']
    arr = deque(arr)
    reversed = False
    error_found = False
    for letter in command:
        if letter == 'R':
            reversed = not reversed
        elif letter == 'D':
            if len(arr) == 0:
                error_found = True
                print('error')
                break
            if reversed:
                arr.pop()
            else:
                arr.popleft()
    if error_found:
        continue
    
    if reversed:
        arr.reverse()

    print('[', end='')
    print(','.join(arr), end='')
    print(']')



