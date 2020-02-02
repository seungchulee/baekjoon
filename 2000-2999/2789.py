n = input()
res = ""
cam = "CAMBRIDGE"
for nn in n:
    if nn not in cam:
        res+=nn
print(res)        
