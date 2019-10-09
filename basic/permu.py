import itertools
result="1234"

print('product')
per=list(itertools.product(result,repeat=2))
for dat in per:
    print(dat)

per=list(itertools.permutations(result,2))
print('permutation')
for dat in per:
    print(dat)

print('combination')
per=list(itertools.combinations(result,2))
for dat in per:
    print(dat)

print('combination_replacement')
per=list(itertools.combinations_with_replacement(result,2))
for dat in per:
    print(dat)
