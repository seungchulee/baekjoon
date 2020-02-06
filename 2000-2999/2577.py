a=int(input())
b=int(input())
c=int(input())
nn = a*b*c
nn=str(nn)
dd={'0':0,'1':0,'2':0,'3':0,'4':0,'5':0,'6':0,'7':0,'8':0,'9':0}
for i in nn:
    dd[i]+=1
for i in dd: 
    print(dd[i])
