import re


# compilando la regex
patron = re.compile(r'\bfoo\b')  # busca la palabra foo

texto = """ bar foo bar
foo barbarfoo
foofoo foo bar
"""

# match nos devuelve None porque no hubo coincidencia al comienzo del texto
print(patron.match(texto))

# match encuentra una coindencia en el comienzo del texto
m = patron.match('foo bar')
print(m)

# search nos devuelve la coincidencia en cualquier ubicacion.
s = patron.search(texto)
print(s)

# findall nos devuelve una lista con todas las coincidencias
fa = patron.findall(texto)
print(fa)


# texto de entrada
becquer = """Podrá nublarse el sol eternamente; 
Podrá secarse en un instante el mar; 
Podrá romperse el eje de la tierra 
como un débil cristal. 
¡todo sucederá! Podrá la muerte 
cubrirme con su fúnebre crespón; 
Pero jamás en mí podrá apagarse 
la llama de tu amor."""

# patron para dividir donde no encuentre un caracter alfanumerico
patron = re.compile(r'\W+')

palabras = patron.split(becquer)
palabras[:10]  # 10 primeras palabras

# Cambiando "Podrá" o "podra" por "Puede"
podra = re.compile(r'\b(P|p)odrá\b')
puede = podra.sub("Puede", becquer)
print(puede)

# Ejemplo de IGNORECASE
# Cambiando "Podrá" o "podra" por "Puede"
podra = re.compile(r'podrá\b', re.I)  # el patrón se vuelve más sencillo
puede = podra.sub("puede", becquer)
print(puede)

# Ejemplo de VERBOSE
mail = re.compile(r"""
\b             # comienzo de delimitador de palabra
[\w.%+-]       # usuario: Cualquier caracter alfanumerico mas los signos (.%+-)
+@             # seguido de @
[\w.-]         # dominio: Cualquier caracter alfanumerico mas los signos (.-)
+\.            # seguido de .
[a-zA-Z]{2,6}  # dominio de alto nivel: 2 a 6 letras en minúsculas o mayúsculas.
\b             # fin de delimitador de palabra
""", re.X)


mails = """raul.lopez@relopezbriega.com, Raul Lopez Briega,
foo bar, relopezbriega@relopezbriega.com.ar, raul@github.io, 
https://relopezbriega.com.ar, https://relopezbriega.github.io, 
python@python, river@riverplate.com.ar, pythonAR@python.pythonAR
"""

# filtrando los mails con estructura válida
mail.findall(mails)



# Validando una URL
url = re.compile(r"^(https?:\/\/)?([\da-z\.-]+)\.([a-z\.]{2,6})([\/\w \.-]*)*\/?$")

# vemos que https://relopezbriega.com.ar lo acepta como una url válida.
print(url.search("https://relopezbriega.com.ar"))

# pero https://google.com/un/archivo!.html no la acepta por el carcter !
print(url.search("https://google.com/un/archivo!.html"))
