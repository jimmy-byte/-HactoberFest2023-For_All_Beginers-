def gap(g, m, n):
    solved = []
    for i in range(m,n):
        isprime = True
        for j in range(2,i):
            if i % j == 0:
                isprime = False
                break
        if isprime:
            solved.append(i)
    print(solved)
    if len(solved) == g:
        return solved 
    else:
        return None
    
print(gap(4,100,110))