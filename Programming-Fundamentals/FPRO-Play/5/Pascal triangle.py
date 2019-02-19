def pascal(n):
    p = []
    for i in range(n):
        if i == 0:
            p.append([1])
            continue
        if i == 1:
            p.append([1, 1])
            continue

        base = [x for x in range(i+1)]
        base[0], base[i] = 1, 1
        for j in range(1, i):
            base[j] = p[i-1][j-1] + p[i-1][j]
        p.append(base)
    return "\n".join([" ".join([str(x) for x in lines]) for lines in p])
