import collections 
string=input().lower()

def f2(x):
    return x[1]

result={}
for ch in string:
    if ch not in result:
        result[ch]=1
    else:
        result[ch]+=1
result=sorted(result.items(),key=f2,reverse=True)

if len(result)==1:
    print(result[0][0].upper())
else:
    if result[0][1]==result[1][1]:
        print("?")
    else:
        print(result[0][0].upper())
