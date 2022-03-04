import re

expresion=('^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}'
                 '([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$')
ipv4= re.compile(expresion)

#la ip 152.323.32.1442 no es valida

print(ipv4.search("152.323.32.1442"))

#pero la ip 172.168.124.136 si es valida
print(ipv4.search("172.168.124.136"))


exp=('^([A-ZÑ&]{3,4})([0-9]{2}(0[0-9]|1[0-2])(0[1-9]|[12][0-9]|3[01]))'
     '([A-Z0-9]{3})')

rfc= re.compile(exp)

#El RFC MELM8305281H0 es valido
print(rfc.search("MELM8305281H0"))

#Pero el RFC MELM0583281H0
print(rfc.search("MELM0583281H0"))
