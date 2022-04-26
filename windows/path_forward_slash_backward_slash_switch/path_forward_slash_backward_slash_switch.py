# -*- coding: utf-8 -*-
"""
Other ways: some software(aim for better daily use of computer), shortkey ; ditto, script post-operation

Created on Tue Apr 26 20:28:54 2022

@author: cgb

E:/scientific/sci_study_vessel/work_recurrent/Reichold, 2009, Boas, 2008/data/data_2
E:\scientific\sci_study_vessel\work_recurrent\Reichold, 2009, Boas, 2008\data\data_2
"""

import win32clipboard
import win32con

# data = ""

try:
    win32clipboard.OpenClipboard()
    data = win32clipboard.GetClipboardData(win32clipboard.CF_UNICODETEXT)
finally:
    win32clipboard.CloseClipboard()

# print('data=', data)

if data.find("\\")!=-1:
    data = data.replace('\\','/')    
else:
    data = data.replace('/','\\')

print(data)

try:
    win32clipboard.OpenClipboard()
    win32clipboard.EmptyClipboard() ## 需要加这句话
    win32clipboard.SetClipboardText(data)
    
    # win32clipboard.SetClipboardData(win32clipboard.CF_TEXT, data)
    # win32clipboard.SetClipboardData(win32clipboard.CF_UNICODETEXT, unicode(data))
finally:
    win32clipboard.CloseClipboard()

check = 0
if check:
    try:
        win32clipboard.OpenClipboard()
        data = win32clipboard.GetClipboardData(win32clipboard.CF_UNICODETEXT)
    finally:
        win32clipboard.CloseClipboard()
    print('CHECK data ', data)
# print('data=', data)

print('code end')
