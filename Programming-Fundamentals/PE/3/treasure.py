"""Treasure"""

def treasure(clues):
    x = (0, 0)
    while x in clues:
        y = clues[x]
        del clues[x]
        x = y
    return x
