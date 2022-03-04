# a^n b^n 

tokens = ('a', 'b'); 
t_a = r'a'; 
t_b = r'b'; 

def t_error(t): 
    print("Caracter ilegal ", t.value[0]) 
    t.lexer.skip(1) 

import ply.lex as lex 
lex.lex() 

def p_S(p): 
    ''' S : a S b 
          | a b''' 
    pass 

##def p_empty(p): 

##    'empty :' 

##    pass 

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
