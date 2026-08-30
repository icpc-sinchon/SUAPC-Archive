import sys
input = sys.stdin.readline

def suap(a, b):
    ca = ord(s[a]) - 65
    cb = ord(s[b]) - 65
    if ca != cb:
        pos[ca].remove(a)
        pos[cb].remove(b)
        pos[ca].add(b)
        pos[cb].add(a)
    s[a], s[b] = s[b], s[a]
    ans.append((a+1, b+1))

n = int(input())
s = [*input().rstrip()]
t = [*input().rstrip()]
if s == t:
    print("YES")
    print(0)
    sys.exit(0)
cnts = [0]*26
cntt = [0]*26
pos = [set() for _ in range(26)]
for i in range(n):
    cnts[ord(s[i])-65] += 1
    pos[ord(s[i])-65].add(i)
    cntt[ord(t[i])-65] += 1
if cnts != cntt or cnts[2] == 0:
    print("NO")
    sys.exit(0)
ans = []
p = s.index("C")
for i in range(n):
    x = ord(t[i]) - 65
    if t[i] == "C": continue
    if s[i] == t[i]:
        pos[x].remove(i)
        continue
    j = next(iter(pos[x]))
    if s[i] == 'C':
        suap(i, j)
        if p == i:
            p = j
    else:
        suap(i, p)
        suap(i, j)
        p = j
    pos[x].remove(i)
print("YES")
print(len(ans))
for x, y in ans:
    print(x, y)