#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author  : yuhao
# @File    : main.py
# @Software: vim

import time
import unittest
import codewars_test as test
def josephus(items,k):
    content = []
    outputcontent = []
    for index in range(len(items)):
        content.append(0)
    total = 0
    i = 0
    j = 1
    while total < len(items):
        if content[i] == 0 :
            if j == k:
                content[i] = 1
                j = 1
                total +=1
                outputcontent.append(items[i])
                if total == len(items):
                    return outputcontent
            else:
                j+=1
        i+=1
        if i > len(items)-1:
            i = 0
    return []

test.assert_equals(josephus([1,2,3,4,5,6,7,8,9,10],1),[1,2,3,4,5,6,7,8,9,10])
test.assert_equals(josephus([1,2,3,4,5,6,7,8,9,10],2),[2, 4, 6, 8, 10, 3, 7, 1, 9, 5])
test.assert_equals(josephus(["C","o","d","e","W","a","r","s"],4),['e', 's', 'W', 'o', 'C', 'd', 'r', 'a'])
test.assert_equals(josephus([1,2,3,4,5,6,7],3),[3, 6, 2, 7, 5, 1, 4])
test.assert_equals(josephus([],3),[])
