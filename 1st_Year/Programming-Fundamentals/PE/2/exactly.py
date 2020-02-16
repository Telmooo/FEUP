def exactly(s):
	ok = ()
	for i in range(len(s)-1):
		for j in range(i+1, len(s)):
			if s[i].isdigit() and s[j].isdigit() and int(s[i]) + int(s[j]) == 10:
				temp = s[i+1:j]
				if temp.count("?") == 3:
					ok += (s[i] + s[j],)
				else:
					violation = (s[i] + s[j],)
					return f"The sequence {s} is NOT OK with first violation with pair: {violation}"
	return f"The sequence {s} is OK with the pairs: {ok}"
