def minion(astring):
    v = "AEIOU"
    st = {}
    ke = {}
    for c, i in zip(astring, range(len(astring))):
        if c in v:
            if c not in ke:
                ke[c] = 1
            else: ke[c] += 1
            s = c
            for ac in astring[i+1:]:
                s += ac
                if s not in ke:
                    ke[s] = 1
                else: ke[s] += 1
        if c not in v:
            if c not in st:
                st[c] = 1
            else: st[c] += 1
            s = c
            for ac in astring[i+1:]:
                s += ac
                if s not in st:
                    st[s] = 1
                else: st[s] += 1
    pst = sum(st.values())
    pke = sum(ke.values())
    if pst == pke:
        res = "It was a draw!"
    elif pst > pke:
        ls = sorted(list(st.items()), key = lambda x: (len(x[0]), astring.find(x[0])))
        l = f"The winner was Stuart with a total of {pst} points:"
        d = "\n".join(f"- {obj[0]}: {obj[1]}" for obj in ls)
        res = "\n".join((l, d))
    else:
        ls = sorted(list(ke.items()), key = lambda x: (len(x[0]), astring.find(x[0])))
        l = f"The winner was Kevin with a total of {pke} points:"
        d = "\n".join(f"- {obj[0]}: {obj[1]}" for obj in ls)
        res = "\n".join((l, d))
    return res
