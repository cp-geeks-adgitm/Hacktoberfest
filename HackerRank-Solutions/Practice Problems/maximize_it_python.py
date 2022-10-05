from itertools import product

K, M = map(int, input().split())

# [1:] in below command will skip the first value from the enter values
N = (list(map(int, input().split()))[1:] for _ in range(K))

# It uses the lambda function which takes function as a first argument then applies to iterable item
# *N is known as unpacking of items from the list
results = map(lambda x: sum(i ** 2 for i in x) % M, product(*N))
print(max(results))