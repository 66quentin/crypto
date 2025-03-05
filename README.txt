Projet de cryptographie réalisé par QG (quentin.guardia@protonmail.com) à l'aide d'enseignants de l'UPVD

Dans le dossier courant:
"make" pour compiler
"./huffman" donne les prérequis pour donner l'arbre de huffman d'une chaîne (voir fichier)
"./enigma" crypte une phrase avec des clés sur le modèle de la machine enigma (voir fichier)
"make clean" pour nettoyer

Dans le dossier Vigenere:
"make"
"./analyse_vigenere fichier-chiffré.txt" Avec un fichier comme chiffre-court-vigenere.txt ou chiffre-long-vigenere.txt
Appuyer sur entrée. Suivre les commandes pour déchiffrer avec les méthodes de vigenere. On peut voir les commandes avec "help".
Afin de trouver la bonne clé de cryptage il faut avoir connaissance des fréquences des lettres et bigrammes, dans la langue française en l'occurence.
Il vérifier que la fréquence des lettres décryptées correspond bien à la fréquence des lettres en français

Lettre: Fréquence (en %)
a:8,25
b:1,25
c:3,25
d:3,75
e:17,75
f:1,25
g:1,25
h:1,25
i:7,25
j:0,75
k:0,00
l:5,75
m:3,25
n:7,25
o:5,75
p:3,75
q:1,25
r:7,25
s:8,25
t:7,25
u:6,25
v:1,75
w:0,00
x:0,00
y:0,75
z:0,00

Bigramme: fréquence (en nombre d'apparition sur 10 000 lettres)
es 305
le 246
en 242
de 215
re 209
nt 197
on 164
er 163
te 163
se 155
et 143
el 141
qu 134
an 130
ne 124
ou 118
ai 117
em 113
it 112
me 104
is 103
la 101
ec 100
ti 98
ce 98
ed 96
ie 94
ra 92
in 90
eu 89
ur 88
co 87
ar 86
tr 86
ue 85
ta 85 
ep 82
nd 80
ns 79
pa 78
us 76
sa 75
ss 73

A noter, que les bigrammes, constitués par deux consonnes, les plus fréquents sont : nt(197) tr(86) ns(79) st(61).
Ceux constitués de deux voyelles sont : ou(118) ai(117) ie(94) eu(89) ue(85) ui(68) au(64) oi(52) io(49)

Les bigrammes formés de deux lettres identiques les plus fréquents sont:
ss ee ll tt nn mm rr pp ff cc aa uu ii
73 66 29 24 20 17 16 10 8  3  3  2  1


"make clean" pour nettoyer



