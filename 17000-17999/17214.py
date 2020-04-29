import operator
string = input()
if string[0] != '-':
    string = '+' + string
lists = []
data=""
for i in range(len(string)):
    if i==len(string)-1:
        data+=string[i]
        lists.append(data)
    elif string[i+1]=='-' or string[i+1]=='+':
        data+=string[i]
        lists.append(data)
        data=""
    else:
        data+=string[i]
dic = {}        
for data in lists:
    num=""
    count=0
    for x in data:
        if x=='+' or x=='-':
            continue
        if x=='x':
            count+=1
            continue
        num+=x
  
    if num=="":
        num+='1'
    d=int(num)
    if data[0]=='-':
        d=-d
    if str(count) in dic:
        dic[str(count)]+=d
    else:
        dic[str(count)]=d
sorted_dic = sorted(dic.items(),key=operator.itemgetter(0), reverse = True) 
idx=0
if string=='+0':
    print('W')
else:    
    for key,value  in sorted_dic:
        coeff = int(value/(int(key)+1))
        if idx!=0:
            if coeff>0:
                print('+',end="")
        if coeff==0:

            continue
        if coeff != 1:         
            if coeff==-1:
                print('-',end='')
            else:    
                print(coeff,end="")
        print('x'*(int(key)+1),end="")
        idx=1

    print('+W')
