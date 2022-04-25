# -*- coding: utf-8 -*-
"""
Created on Fri Apr 22 15:50:07 2022

@author: cgb

E:\scientific\sci_code\python\pdf_merge_name_is_folder_name_1.py
"""

import os
import sys





path = input()

# print(path)
# sys.exit(1)

# path = sys.argv[1]
# path = os.getcwd()
# name = os.path.dirname( os.getcwd() )
# print(path.rfind('\\'))
name = path[path.rfind('\\')+1:]
# print(name)

# op  = "cd /d \"" + path + "\""
# print(op)
# os.system(op)

path_dir = os.path.dirname(path)

op = "pdftk.exe %s\*.pdf cat output %s\%s.pdf"%(path_dir, path_dir, name)
print(op)
os.system(op)