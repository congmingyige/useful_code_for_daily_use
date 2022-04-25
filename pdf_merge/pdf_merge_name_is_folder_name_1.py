# -*- coding: utf-8 -*-
"""
Created on Mon Apr 18 23:25:57 2022

@author: cgb

E:\scientific\sci_code\python\pdf_merge_name_is_folder_name_with_input.py
"""


import os

#path = os.path.dirname(path)
# print(path)

# print(os.getcwd())
'''
在cmd中运行，就是输出对应路径
'''

path = os.getcwd()
# name = os.path.dirname( os.getcwd() )
# print(path.rfind('\\'))
name = path[path.rfind('\\')+1:]
# print(name)
op = "pdftk.exe *.pdf cat output " + name + ".pdf"
print(op)
os.system(op)

# abspath 上一级路径