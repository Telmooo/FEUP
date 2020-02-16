'''
Anagrams
'''
def anagrams(alist):
    ang = []
    #converts to lowercase and removes whitespaces
    low = [obj.lower().replace(" ", "") for obj in alist]    
    for idx, obj in enumerate(low):
        #gets all the anagrams for an element
        l = [alist[idx]] + [alist[i] for i, word in enumerate(low) if word!=obj and sorted(word)==sorted(obj)]
        #checks if it's a duplicate
        if not any(x in y for x in l for y in ang):
            l.sort()
            ang.append(l)
    return sorted(ang, key = lambda x: x[0].lower())
