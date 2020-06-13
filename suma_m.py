l = [31,-41,59,26,-53,58,97,-93,-23,84]

def sm(l):
    sum_M = temp = 0
    for i in l:
        temp = max(temp + i, 0)
        sum_M = max(sum_M, temp)
    return sum_M

print(sm(l))
