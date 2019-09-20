string=input()
basic=['c=','c-','dz=','d-','lj','nj','s=','z=']

for ch in basic:
    string=string.replace(ch,'*')
print(len(string))    
