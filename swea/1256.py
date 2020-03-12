n = int(input())
for i in range(n):
    k = int(input())
    string = input()
    lis = []
    for j in range(len(string)):
        lis.append(string[j:])
    lis.sort()
    if k > len(lis):
        print("#%d none"%(i+1))
    else:    
        print("#%d %s"%(i+1,lis[k-1]))
