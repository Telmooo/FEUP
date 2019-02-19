def interleave(f1, f2):
    with open(f1) as file1, open(f2) as file2:
        lines1 = file1.readlines()
        lines2 = file2.readlines()

    st = ""
    for l1, l2 in zip(lines1, lines2):
        st += l1 + l2
    return st
