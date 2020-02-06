n=int(input())
ll = []
for i in range(n):
    cmd = input()
    if cmd=="all":
        ll=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
    elif cmd=='empty':
        ll=[]
    else:
        cc,num=cmd.split()
        num=int(num)
        if cc=='add':
            if num not in ll:
                ll.append(num)
        elif cc=='remove':
            if num in ll:
                ll.remove(num)
        elif cc=='check':
            if num in ll:
                print(1)
            else:
                print(0)
        elif cc=='toggle':
            if num in ll:
                ll.remove(num)
            else:
                ll.append(num)
              
                
