string=input()

result={}
result['A']=3
result['B']=3
result['C']=3
result['D']=4
result['E']=4
result['F']=4
result['G']=5
result['H']=5
result['I']=5
result['J']=6
result['K']=6
result['L']=6
result['M']=7
result['N']=7
result['O']=7
result['P']=8
result['Q']=8
result['R']=8
result['S']=8
result['T']=9
result['U']=9
result['V']=9
result['W']=10
result['X']=10
result['Y']=10
result['Z']=10

res=0
for ch in string:
    res+=result[ch]
print(res)    
