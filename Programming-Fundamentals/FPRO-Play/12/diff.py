def diff(filename1, filename2):
    with open(filename1) as f1, open(filename2) as f2:
        f1lines = f1.readlines()
        f2lines = f2.readlines()
    
    difference = ""
    equal = []
    for i, line in enumerate(f1lines):
        if line in f2lines: equal.append((i, f2lines.index(line)))
    
    starti, startj = 0, 0
    for i, j in equal:
        for line in f1lines[starti:i]:
            difference += f"- {line}"+"\n"*(not line.endswith("\n"))
        for line in f2lines[startj:j]:
            difference += f"+ {line}"+"\n"*(not line.endswith("\n"))
        starti, startj = i+1, j+1
    for line in f1lines[starti:]:
        difference += f"- {line}"+"\n"*(not line.endswith("\n"))
    for line in f2lines[startj:]:
            difference += f"+ {line}"+"\n"*(not line.endswith("\n"))
    return difference
