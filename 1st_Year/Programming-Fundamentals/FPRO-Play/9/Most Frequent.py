def most_frequent(alist):
    freq_table = {}
    for i in alist:
        freq_table[i] = freq_table.get(i, 0) + 1
    return max(freq_table, key = lambda x: (freq_table[x], x == max(freq_table)))
