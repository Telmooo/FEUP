def grep(pattern, files_list, flags=""):
    result = ""
    case = "-i" in flags
    match_all = "-x" in flags
    invert = "-v" in flags
    file_only = "-l" in flags
    count_only = "-c" in flags
    if case: pattern = pattern.lower()
    for file in files_list:
        temp, count = "", 0
        with open(file) as f:
            for i, line in enumerate(f):
                linex = line.lower() if case else line
                if not invert:
                    if match_all: temp += (f"{file}:{i+1}:{line}"+"\n"*(not line.endswith("\n")))*(linex.rstrip("\n")==pattern); count+=1*(linex.rstrip("\n")==pattern)
                    else:
                        if pattern in linex: temp += f"{file}:{i+1}:{line}"; count+=1
                else:
                    if match_all: temp += (f"{file}:{i+1}:{line}"+"\n"*(not line.endswith("\n")))*(linex.rstrip("\n")!=pattern); count+=1*(linex.rstrip("\n")==pattern)
                    else: 
                        if pattern not in linex: temp += f"{file}:{i+1}:{line}"+"\n"*(not line.endswith("\n")); count+=1
        if count_only: temp = f"{file}:{count}\n"
        if file_only: temp = f"{file}\n"
        result += temp*(count!=0)
    return result.rstrip("\n")
