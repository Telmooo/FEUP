"""
File Finder
"""
def file_finder(dirs, file_name):
    if file_name in dirs and file_name != dirs[0]:
        return f"{dirs[0]}/{file_name}"
    else:
        for subd in dirs:
            if isinstance(subd, list):
                searcher = file_finder(subd, file_name)
                if searcher:
                    return f"{dirs[0]}/{searcher}"
