#**********************************************************************************************************
#   @file pil.py
#   @author Betil Olivier
#   @brief script qui récupère les données d'une image stockées dans un fichier .txt et reconstruit l'image
#   @date 21/12/2022
#**********************************************************************************************************

#utilisation des librairies:
#   Numpy: gestion de matrices
#   PIL: gestion d'images
#   Bitstring: gestion de trames de bits
import numpy as np
from PIL import Image
from bitstring import BitArray

#Fichier où se trouve les données pour l'image
doc = open("test.txt", "r", encoding='utf-8')

#création de la matrice qui représente l'image (np.uint8 car c'est le format à utiliser pour l'image)
imagearray = np.empty((120, 160, 3), dtype=np.uint8)

#Init
x=0
y=0

#Boucle qui va faire tout le fichier
for line in doc:

    #récupère en trame de bits les données de l'image
    pixel=line.split("  ")
    try:
        b=BitArray(hex="0"+pixel[1][3:6])
    except:
        b=BitArray(hex=hex(ord(pixel[1][2])))
    try:
        b+=BitArray(hex="0"+pixel[0][3:6])
    except:
        b+=BitArray(hex=hex(ord(pixel[0][2])))
    
    #récupère chaque couleur dans la trame, et passe en int
    rouge = b[:5].uint
    vert = b[5:11].uint
    bleu=b[11:].uint

    #Stocke les valeurs dans la matrice
    imagearray[y][x][0]=rouge*8
    imagearray[y][x][1]=vert*4
    imagearray[y][x][2]=bleu*8

    #Incrémentation (ligne par ligne, comme envoyé par stm)
    x+=1
    if(x==160):
        x=0
        y+=1


image=""
for y in range(120):
    for x in range(160):
        image+=str(imagearray[y][x][0])+" "+str(imagearray[y][x][1])+" "+str(imagearray[y][x][2])+"\n"

#enregistre l'image en format jpg depuis la matrice
pil_image = Image.fromarray(imagearray, mode="RGB")
pil_image.save("image.jpg")

doc = open("couleurs.txt", "w", encoding='utf-8')
doc.write(image)
doc.close()