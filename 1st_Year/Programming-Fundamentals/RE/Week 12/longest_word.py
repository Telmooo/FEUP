"""
Longest word in URL
"""
def longest_word(url):
    import urllib.request as r
    with open("words") as f:
        words = frozenset(f.read().split("\n"))

    raw_html = r.urlopen(url)
    text = raw_html.read().decode()
    raw_html.close()
    text = text.split()
    words = words.intersection(text)
    return min(words, key=lambda x: (-len(x), x))
