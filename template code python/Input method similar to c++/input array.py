import os
import sys

from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *
from dataclasses import *

# khi sử lí mảng thì truy cập a[idx] như bình thường

# cách 1 nhập như c++
n = int(input()) # kích thước mảng
a = [] # mảng trong python không đước khai bảo kiểu int a[1e5 + 7] như c++
# do for trong python chạy mặc định là range(start, stop) chạy đén stop - 1, không lấy stop
for i in range(n): # for này chạy từ 0 đến n - 1
    val = int(input())
    a.append(val)
for i in range(1, n + 1): # for này chayj từ 1 đến n
    val = int(input())
    a.append(val)
# chú ý: cách này mảng a chỉ nhập được mỗi giá trị trên 1 dòng

# cách 2 thông dụng hơn
# đây là cách nhập mảng đơn giản trên 1 dòng
arr_1 = list(map(int, input().split())) # mảng số nguyên
arr_2 = list(map(float, input().split())) # mảng số thức
arr_3 = input().split() # chuỗi kí tự tự động tác dấu " " rồi không cấn stringstream nữa

# cách in mảng
for i in range(n):
    print(a[i])
print(a) # mặc định in là [val_1, val_2,...v...v..., val_n]
print(*a, sep = ' ') # in ra a theo ý mình " ", '\n',...v...v...


# cánh nhập mảng 2 chiều tương tự c  int a[n][m]
n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)] # Truy cập: matrix[r][c]
arr_ = []
for i in range(n):
    val = list(map(int, input().split()))
    arr.append(val)

# nhập chuỗi kí tự
n = int(input())
char_grid = [list(input().strip()) for _ in range(n)]

# cách in ma trận
# VD:
# 3 4
# 1 2 3 4
# 5 6 7 8
# 9 10 11 12

# cách 1 in ra
for i in range(n):
    print(*arr[i], " ")
# 1 2 3 4
# 5 6 7 8
# 9 10 11 12

# cách 2 in ra
for i in range(n):
    for j in range(m):
        print(arr[i][j], end=" ")
    print()
# 1 2 3 4
# 5 6 7 8
# 9 10 11 12

# cách 3 in ra
print(arr)
# [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]