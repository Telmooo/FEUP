"""
Cut
"""
def cut(filename, delimiter, field):
    with open(filename) as file:
        lines = file.readlines()
                
    lines_filt = [line.rstrip("\n").split(delimiter) for line in lines]
    if isinstance(field, int): fieldx = [field]
    else: fieldx = field
    ls = []
    for line in lines_filt:
        ls.append(f"{delimiter}".join(line[i-1] for i in fieldx))
    return "\n".join(ls)
