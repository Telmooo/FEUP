"""
Isomorphic strings
"""
def isomorphic(astring1, astring2):
    maps = {}
    valid = True
    if not (astring1 and astring2):
        valid = False
    for c1, c2 in zip(astring1, astring2):
        if c1 not in maps and c2 not in maps.values():
            maps[c1] = c2
        else:
            if maps.get(c1, None) == c2:
                continue
            else:
                valid = False
                break
    if valid:
        return f"'{astring1}' and '{astring2}' are isomorphic because we can map: {list(maps.items())}"
    return f"'{astring1}' and '{astring2}' are not isomorphic"
