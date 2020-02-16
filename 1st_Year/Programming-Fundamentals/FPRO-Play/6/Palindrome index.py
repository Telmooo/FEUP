def palindrome_index(s):
    if s != s[::-1]:
        for i in range(len(s)):
            ts = s[:i] + s[i+1:]
            if ts == ts[::-1]:
                return i
    return -1
