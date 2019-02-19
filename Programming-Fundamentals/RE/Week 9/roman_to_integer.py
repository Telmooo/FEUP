"""
Roman to integer
"""
def roman_to_integer(astring):
    ri = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100,
          "D": 500, "M": 1000}
    control = False
    i = 0
    for c1, c2 in zip(astring, astring[1:]+"Null"):
        if control:
            control = False
            continue

        if ri[c1] >= ri.get(c2, 0):
            i += ri[c1]

        else:
            control = True
            i += ri[c2] - ri[c1]
    return i
