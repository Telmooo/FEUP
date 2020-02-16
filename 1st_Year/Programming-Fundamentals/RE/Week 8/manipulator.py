'''
List manipulation
Commands:
1. insert i e: Insert integer e at position i.
2. print: Save list to result string.
3. remove e: Delete the first occurrence of integer e.
4. append e: Insert integer e at the end of the list.
5. sort: Sort the list in ascending order.
6. pop: Remove the last element from the list.
7. reverse: Reverse the list.
'''
def manipulator(l, cmds):
    out = ""
    for instr in cmds:
        dec = instr.split()
        if dec[0] == "insert":
            l.insert(int(dec[1]), int(dec[2]))
            continue
        if dec[0] == "print":
            out += str(l) + " "
            continue
        if dec[0] == "remove":
            l.remove(int(dec[1]))
            continue
        if dec[0] == "append":
            l.append(int(dec[1]))
            continue
        if dec[0] == "sort":
            l.sort()
            continue
        if dec[0] == "pop":
            l.pop()
            continue
        if dec[0] == "reverse":
            l.reverse()
            continue
    return out[:-1]
