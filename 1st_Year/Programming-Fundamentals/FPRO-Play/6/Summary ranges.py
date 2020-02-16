def summary_ranges(astring):
    ls = astring.split(",")
    r = []
    while ls:
        i = 0
        if len(ls) > 1:
            while eval(f"{ls[i+1]} == int({ls[i]})+1"):
                i += 1
                if i == len(ls)-1: break
        if i == 0:
            r.append(ls[i])
        else:
            r.append(f"{ls[0]}->{ls[i]}")
        ls = ls[i+1:]
    return ",".join(r)
