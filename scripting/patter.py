def print_sandwatch(n):
    #upper half
    for i in range(1,n+1): #5 times
        
        print( " " * (i-1),end='' ) # spaces

        for j in range(i,n+1):
            print(str(j) + " ",end='')
        print()

    for i in reversed(range(1,n)):
        print( " " * (i-1),end='' ) # spaces

        for j in range(i,n+1):
            print(str(j) + " ",end='')
        print()

def patternA(n):

    for i in range(1,n+1):
        print( '*' * (n-i),end='')
        print(str(i) * i)
patternA(5)

