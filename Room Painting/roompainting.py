n, m = [int(i) for i in input().split()]

sizes_in_microliters = [int(input()) for _ in range(n)]
microliters = [int(input()) for _ in range(m)]

sizes_in_microliters.sort()

wasted = 0
for microliter in microliters:
    for size in sizes_in_microliters:
        if size >= microliter:
            wasted += size - microliter
            break

print(wasted)