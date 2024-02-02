first = int(input())
second = int(input())

if first > 0 and second > 0:
    print('1')
elif first > 0 and second < 0:
    print('4')
elif first < 0 and second > 0:
    print('2')
else:
    print('3')