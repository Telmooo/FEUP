def longest(filename):
    with open(filename) as file:
        text = file.read()
    words = text.split()
    return max(words, key=lambda x: len(x))
