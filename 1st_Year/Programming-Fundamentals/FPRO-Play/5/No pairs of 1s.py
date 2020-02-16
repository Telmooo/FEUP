def no_consecutives1(n):
   if n==1: return 2
   if n==2: return 1 + no_consecutives1(n-1)
   return no_consecutives1(n-1) + no_consecutives1(n-2)
