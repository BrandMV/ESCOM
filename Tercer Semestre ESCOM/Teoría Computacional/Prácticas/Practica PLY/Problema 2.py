#{w ϵ {a,b,c}*| w no tiene la subcadena ac} 
tokens = ('a', 'b', 'c'); 
t_a = r'a'; 
t_b = r'b';
t_c = r'c';


def t_error(t): 
    print("Caracter ilegal ", t.value[0]) 
    t.lexer.skip(1)
    
import ply.lex as lex 
lex.lex() 

def p_S(p): 
    ''' S : S a
          | S b S
          | c X
          | empty
        X : c X
          | S'''
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
