##def B(n):
##    b = []
##    for i in range(len(a)):
##        if int(n[i]) % 2 != 0:
##            b.append(n[i])
##    return b
##
##a = input().split()
##print(B(a))

def absol(a,b):
    return {i for i in a & b if i >0}

A = input().split()
sA = set(map(int, A))
B = input().split()
sB = set(map(int, B))
AiB = absol(sA, sB)
print(AiB)
