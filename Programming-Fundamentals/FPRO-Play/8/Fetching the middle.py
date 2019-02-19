def mean(iterable):
	return sum(iterable)/len(iterable)

def fetch_middle(lists):
    return [mean(list[(len(list)-1)//2:len(list)//2+1]) for list in lists]
