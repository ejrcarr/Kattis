def find_batteries(n, packs):
    res = []
    found = set()

    def dfs(n, ans):
        if n < 0 or tuple(ans[:]) in found:
            return
        if n == 0:
            res.append(ans[:])
            found.add(tuple(ans[:]))
            return
        for i in range(len(packs)):
            ans[i] += 1
            dfs(n - packs[i], ans)
            ans[i] -= 1
    dfs(n, [0] * len(packs))
    return res
