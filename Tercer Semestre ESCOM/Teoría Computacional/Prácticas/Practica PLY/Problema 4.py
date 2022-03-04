#{ a^i b^j c^k | i=j ó j=k }
tokens = ('a', 'b', 'c'); 
t_a = r'a'; 
t_b = r'b';
t_c = r'c'

def t_error(t): 
    print("Caracter ilegal ", t.value[0]) 
    t.lexer.skip(1)
    
import ply.lex as lex 
lex.lex() 

def p_S(p): 
    ''' S : X
          | Y
        X : Z T
        Z : a Z b
          | empty
        T : c T
          | empty
        Y : F W
        F : a F
          | empty
        W : b W c
          | empty'''
        
    pass 

def p_empty(p): 
    'empty :' 
    pass 

s = ''; 
def p_error(p): 
    global s 
    if p: 
        print("Error de sintaxis en ", p.value) 
    else: 
        print("Error de sintaxis en EOF") 
    print(s, "no está en el lenguaje") 

import ply.yacc as yacc

yacc.yacc() 
while 1: 
    try: 
        s = input('> ') 
    except EOFError: 
        break 
    t = yacc.parse(s) 
