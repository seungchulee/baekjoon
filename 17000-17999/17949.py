string = input()
N = int(input())
form = input().split()
dd = []
i = 0
for data in form:
    if data == 'int':
        dd.append(string[i:i+8])
        i+=8
    elif data == 'char':
        dd.append(string[i:i+2])
        i+=2
    else:
        dd.append(string[i:i+16])
        i+=16
      
dic={'a' : 10, 'b' : 11, 'c' : 12, 'd' : 13, 'e' : 14, 'f' : 15}
for data in dd:
    x=0
    po=1
    for i in range(len(data)-1,-1,-1):
        if data[i] in dic:
            x+=dic[data[i]]*po
        else:
            x+=int(data[i])*po
        po=po*16
    print(x, end=' ')        
