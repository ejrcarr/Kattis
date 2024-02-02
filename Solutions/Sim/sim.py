n = int(input())

for _ in range(n):
    str_input = input()
    out = []
    i = 0

    for c in str_input:
        if c == '<':
            if i > 0:
                out.pop(i - 1)
                i -= 1
        elif c == '[':
            i = 0
        elif c == ']':
            i = len(out)
        else:
            out.insert(i, c)
            i += 1

    print("".join(out))
