n,m=input().split()
n=int(n)
m=int(m)
D={}
for i in range(n):
    st=input()
    if st not in D:
        D[st]=1
    else:
        D[st]=D[st]+1
for i in range(m):
    st=input()
    if st not in D:
        D[st]=1
    else:
        D[st]=D[st]+1
lists=[]        
for word in D:
    if D[word]==2:
        lists.append(word)
lists.sort()
print(len(lists))
for wor in lists:
    print(wor)
