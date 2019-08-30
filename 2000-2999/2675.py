n=input();
for i in range(int(n)):
    num,st=input().split()
    num=int(num)
    for ch in st:
        print(num*ch, end='')
    print()    
