import os
import sys

from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *
from dataclasses import *

@dataclass # tương tự struct c++
class name_class:
    name_: int # name : kiểu dữ liệu
    name_1: int
    name_2: int
    name_3: int

#VD
@dataclass
class node:
   u: int
   v: int
   w: int

global n # thêm chỉ thị global để biến là biến toàn cục nếu khai báo trong hàm
# VD:
# def input_():
#     global n

# nhập bình thường
a = input() # mặc định khi nhập a là kí tự
b = int(input()) # thêm int(input()) trước thì nó thành kiểu số nguyên
c = float(input()) # thêm float(input()) trước thì nó thành kiểu số thực

# nếu muốn nhập n, q, m,...v...v... trên 1 dòng
# dạng cin >> n >> q >> m >> ...v...v...;
# thì python là
n, q, m = map(int, input().split())

# nhập struct
name_in_class_1, name_in_class_2, name_in_class_3 = map(int, input().split())
name_class_1 = name_class(
    name_1 = name_in_class_1,
    name_2 = name_in_class_2,
    name_3 = name_in_class_3
)
#VD
u_raw, v_raw, w_raw = map(int, input().split())
node_1 = node(
    u = u_raw,
    v = v_raw,
    w = w_raw
)

# nhập đặc biệt như:
# while(cin >> n) {} c++

# cách 1:
input_data = sys.stdin.read().split()
for token in input_data:
    k = int(token)
    # sol(k)

# cách 2:
while True:
    try:
        k = int(input())
        # sol(k)
    except (EOFError, ValueError):
        break

# nhập t test
    t = int(input())
    for _ in range(t):
        k = int(input())
        # sol(k)

