n,m=input().split()
n=int(n)
m=int(m)
check=False
if m>=45:
    m-=45
else:
    check=True
    m+=15
if check==True:
    if n==0:
        n=23
    else:
        n-=1
print(n,m)        
