n = int(input())
jumsoo = input()
bonus = 0
res = 0
idx = 1
for wo in jumsoo:
    if wo == "X":
        bonus=0
    elif wo == 'O':
        res+=idx
        res+=bonus
        bonus+=1
    idx+=1
print(res)    

