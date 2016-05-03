#!/usr/bin/python

# Google Code Jam Entrance Test 
# (Saving the universe: https://code.google.com/codejam/contest/32013/dashboard)
# Used greedy algorithm (probably not optimal)
# Coded by isdemus (2016 05 03)

import sys

print("This is a GCJ01 problem" +
      "and this is coded in Python 3.5 environment")

def find_min_search_engine(S_list, Q_list, begin, current):
    answer_engine = current
    minimum = len(Q_list) - begin
    for search_engine in S_list:
        candidate = Q_list[begin:].count(search_engine)
        if candidate < minimum and search_engine != current:
            minimum = candidate
            answer_index = search_engine

    return answer_engine

N = int(input())

while (N>0):
    S = input()
    S_cp = int(S)
    S_list = []

    while (S_cp>0):
        S_list.append(input())
        S_cp -= 1
        
    Q = input()
    Q_cp = int(Q)
    Q_list = []
    
    while (Q_cp>0):
        Q_list.append(input())
        Q_cp -= 1

    min_switches = int(Q)-1

    current_engine = find_min_search_engine(S_list, Q_list, 0, "")
    # O(N^2), probably can improve more later
    while (Q_cp < int(Q)): # Currently Q_cp is zero
        # Finding a search engine that has the min number of queries in Q_list
        if Q_list[Q_cp] == current_engine:
            current_engine = find_min_search_engine(S_list, Q_list, Q_cp, current_engine)
            min_switches += 1
        Q_cp += 1

    print("Case #", N, ": ", min_switches)
    N -= 1
