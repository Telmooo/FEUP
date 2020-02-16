def tfidf(documents):
    from math import log
    freq = {}
    for doc in documents:
        for word in doc.split():
            if word.lower() not in freq:
                occurence = sum(1*(word.lower() in docu.lower().split()) for docu in documents)
                freq[word.lower()] = [round(docu.lower().split().count(word.lower())*log(len(documents)/occurence), 3) for docu in documents]
    return freq
