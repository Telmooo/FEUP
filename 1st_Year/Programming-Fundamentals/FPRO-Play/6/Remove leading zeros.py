def remove_leading(ip):
    ls = ip.split(".")
    return ".".join("0" if all(c=="0" for c in x) else x.lstrip("0") for x in ls)
