def academy_awards(alist):
    movies = {}
    for i in alist:
        movies[i[1]] = movies.get(i[1], 0) + 1
    return movies
