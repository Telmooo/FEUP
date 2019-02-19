def rec_to_base(n, base):
    chars = "0123456789ABCDEF"
    if n == 0:
        return "0"
    return  (rec_to_base(n//base, base) + f"{chars[n%base]}").lstrip("0")
