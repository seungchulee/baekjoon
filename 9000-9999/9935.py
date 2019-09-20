basic=input()
boom=input()

boom_len=len(boom)
index=0
new_len=0
basic_new=[]
while index<len(basic):
    basic_new.append(basic[index])
    new_len+=1

    if new_len>=boom_len:
        for j in range(-1,-boom_len-1,-1):
            if basic_new[j]!=boom[j]:
                break
        else:    
            a=0
            while a < boom_len:
                basic_new.pop()
                new_len-=1
                a+=1
        
    

    index+=1
answer=''.join(basic_new)
if answer=="":
    print("FRULA")
else:
    print(answer)

