n = int(input())
for i in range(n):
    k = int(input())
    string = input()
    lis = set()
    for j in range(1,len(string)+1):
        for t in range(len(string)):
            lis.add(string[t:t+j])
    lis=list(lis)        
      
    lis.sort()
    #print(lis)
    if k > len(lis):
        print("#%d none"%(i+1))
    else:    
        print("#%d %s"%(i+1,lis[k-1]))
