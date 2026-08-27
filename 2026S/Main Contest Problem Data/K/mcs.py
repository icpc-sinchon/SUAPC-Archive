N = int(input())

k = 1
while k * k + k < N:
    k += 1
print(k)
print(k, k + 1)