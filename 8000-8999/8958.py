n = int(input())
for i in range(n):
    st = input()
    OO = st.split('X')
    res=0
    for o in OO:
        if 'O' in o:
            res+=int(len(o)*(len(o)+1)/2)
    print(res)        
