"""
Sort by field
"""
def sort_by_field(filename, field):
    with open(filename) as f:
        cont = f.readlines()
    
    fields = cont[0].rstrip("\n").split(",")
    data = [line.rstrip("\n").split(",") for line in cont[1:]]
    index = fields.index(field)
    sorted_data = sorted(data, key=lambda x: (x[index], data.index(x)))
    ls = [",".join(fields)]
    for line in sorted_data:
        ls.append(",".join(line))
    return "\n".join(ls)
