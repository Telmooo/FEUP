def summary(text):
    words = text.split()
    return (len(words), sum("e" in word.lower() for word in words))
