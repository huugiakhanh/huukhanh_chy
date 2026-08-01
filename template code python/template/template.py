import os
import sys

from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *
from dataclasses import *

MOD1 = 1000000007
MOD2 = 1000000009
MOD3 = 2147483647
INF = 1000000000000000000
base1 = 310
base2 = 256

def cin(): return int(input())
def in_all(): return map(int, input().split())
def cin_arr(): return list(map(int, input().split()))
def inv(a, mod): return pow(a, mod - 2, mod)
def fac(a): return factorial(a)
def fac_mod(a, mod): return factorial(a) % mod
def pow_mod(a, b, mod):
    res = 1
    a = a % mod
    while b > 0:
        if b & 1 : res = (res * a) % mod
        a = a * a % mod
        b >>= 1
    return res
def file_io(task):
    folder = os.path.dirname(os.path.abspath(__file__))
    inp = os.path.join(folder, f"{task}.INP")
    out = os.path.join(folder, f"{task}.OUT")
    if os.path.exists(inp):
        sys.stdin = open(inp, "r")
        sys.stdout = open(out, "w")
    global input
    input = sys.stdin.readline


def input_():


def output_():


def main():
    file_io("name")
    input_()
    output_()


if __name__ == "__main__":
    main()