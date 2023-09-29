n, h = [int(i) for i in input().split()]

tites = [0] * h
mites = [0] * h

for i in range(n):
	size = int(input())
	if i % 2 == 0:
		mites[size - 1] += 1
	else:
		tites[h - size] += 1
	
# [0, 0, 0, 1, 0, 0, 0] -> [0, 0, 0, 1, 1, 1, 1]
# Since if a stalagmite is at height 3, then any height below 3 will also hit it
current_total = 0
for i in range(h):
	current_total += tites[i]
	tites[i] = current_total
	
# [0, 0, 0, 1, 0, 0, 0] -> [1, 1, 1, 1, 0, 0, 0]
# Same idea with a stalactite
current_total = 0
for i in range(h - 1, -1, -1):
	current_total += mites[i]
	mites[i] = current_total

# [1, 1, 1, 1, 0, 0, 0] + [0, 0, 0, 1, 1, 1, 1] = [1, 1, 1, 2, 1, 1, 1]
# The number of times a height is hit is the sum of the stalagmites and stalactites
both = [tites[i] + mites[i] for i in range(h)]
print(min(both), both.count(min(both)))


# n, h = [int(i) for i in input().split()]

# sizes = [int(input()) for _ in range(n)]

# is_stalagmite = True
# height_bucket = [0] * h
# for size in sizes:
#     if is_stalagmite:
#         for i in range(0, size):
#             height_bucket[i] += 1
#     else:
#         for i in range(h - size, h):
#             height_bucket[i] += 1
#     is_stalagmite = not is_stalagmite

# print(min(height_bucket), height_bucket.count(min(height_bucket)))
    


# is_stalagmite = True

# found = []
# curr_min = float('inf')
# for i in range(h):
#     count = 0
#     for size in sizes:
#         interval = [0, size] if is_stalagmite else [h - size, h]
#         is_stalagmite = not is_stalagmite
#         if (interval[0] <= i < interval[1]):
#             count += 1
#     if count < curr_min:
#         curr_min = count
#         found = [i]
#     elif count == curr_min:
#         found.append(i)

# print(curr_min, len(found))






