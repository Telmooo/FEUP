def wc(filename):
    with open(filename) as file:
        lines = file.readlines()

    text = "".join(lines)
    chars = list(text)
    words = text.split()
    return (len(lines), len(words), len(chars))
