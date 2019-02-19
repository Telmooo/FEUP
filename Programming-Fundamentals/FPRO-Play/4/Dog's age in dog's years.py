def dogs(h_age):
    d_age = 0
    for i in range(h_age):
        if i < 2:
            d_age += 10.5
        else: d_age += 4
    return d_age
