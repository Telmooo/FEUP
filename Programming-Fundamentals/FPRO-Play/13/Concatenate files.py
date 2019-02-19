def concatenate_all(alist):
	s = sorted(alist, key = lambda x: x.split("/")[-1])
	st = ""
	for file in alist:
		try:
			with open(file) as f:
				st += f.read()
		except:
			pass
	return st
