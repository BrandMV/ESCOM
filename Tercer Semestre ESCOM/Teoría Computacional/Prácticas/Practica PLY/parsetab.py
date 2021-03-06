
# parsetab.py
# This file is automatically generated. Do not edit.
# pylint: disable=W,C,R
_tabversion = '3.10'

_lr_method = 'LALR'

_lr_signature = 'a b S : a a a T\n        T : a T b\n          | emptyempty :'
    
_lr_action_items = {'a':([0,2,3,4,5,],[2,3,4,5,5,]),'$end':([1,4,6,7,9,],[0,-4,-1,-3,-2,]),'b':([5,7,8,9,],[-4,-3,9,-2,]),}

_lr_action = {}
for _k, _v in _lr_action_items.items():
   for _x,_y in zip(_v[0],_v[1]):
      if not _x in _lr_action:  _lr_action[_x] = {}
      _lr_action[_x][_k] = _y
del _lr_action_items

_lr_goto_items = {'S':([0,],[1,]),'T':([4,5,],[6,8,]),'empty':([4,5,],[7,7,]),}

_lr_goto = {}
for _k, _v in _lr_goto_items.items():
   for _x, _y in zip(_v[0], _v[1]):
       if not _x in _lr_goto: _lr_goto[_x] = {}
       _lr_goto[_x][_k] = _y
del _lr_goto_items
_lr_productions = [
  ("S' -> S","S'",1,None,None,None),
  ('S -> a a a T','S',4,'p_S','Problema 3.py',14),
  ('T -> a T b','T',3,'p_S','Problema 3.py',15),
  ('T -> empty','T',1,'p_S','Problema 3.py',16),
  ('empty -> <empty>','empty',0,'p_empty','Problema 3.py',21),
]
