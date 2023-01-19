#**********************************************************************************************************
#   @file bin2img.py
#   @author Olivier BETIL
#   @brief enregistre une image arrivant dans un port serial en un fichier jpg
#   @date 21/12/2022
#**********************************************************************************************************

#Utilisation des librairies:
#   PySerial: Lecture des ports serial de l'ordinateur
#   Numpy: gestion de matrices
import serial
import numpy as np
from PIL import Image
from bitstring import BitArray

#Initialisation et ouverture du port COM
ser = serial.Serial()
ser.baudrate = 115200
ser.port = 'COM14'
ser.open()

#boucle pour trouver le début d'une image (la stm envoie "helloworldhelloworldhelloworldxx" entre chaque image)
test=1
while(test==1):
    temp = str(ser.read(20))
    if "helloworld" in temp:
        test=0

#on s'assure de terminer le message inter-image avant de stocker l'image
test=1
while(test==1):
    temp=ser.read(1)
    if(str(temp)=="b'd'"):
        if(str(ser.read(1))=="b'x'"):
            if(str(ser.read(1))=="b'x'"):
                test=0

#création de la matrice qui représente les deux octets pour un pixel
imagearray = np.empty((120, 160, 2), dtype=bytes)

#init
compteur = 0

#On préviens l'utilisateur qu' l'on commence à enregistrer une image
print("Enregistrement d'une image")

#on lit chaque pixel reçu dans le port serial
for y in range(120):
    for x in range(160):
        imagearray[y][x][0]=ser.read(1)
        imagearray[y][x][1]=ser.read(1)

#fermeture du port COM
ser.close()       

print("Conversion vers un fichier .jpg")

#creation d'une matrice pour chaque couleur des pixel
imagearrayRGB = np.empty((120, 160, 3), dtype=np.uint8)

#Init
x=0
y=0

for y in range(120):
    for x in range(160):
        try:
            b=BitArray(hex="0"+str(imagearray[y][x][1])[3:6])
        except:
            b=BitArray(hex=hex(ord(str(imagearray[y][x][1])[2])))
        try:
            b+=BitArray(hex="0"+str(imagearray[y][x][0])[3:6])
        except:
            b+=BitArray(hex=hex(ord(str(imagearray[y][x][0])[2])))

        #récupère chaque couleur dans la trame, et passe en int
        rouge = b[:5].uint
        vert = b[5:11].uint
        bleu=b[11:].uint

        #Stocke les valeurs dans la matrice
        imagearrayRGB[y][x][0]=rouge*8
        imagearrayRGB[y][x][1]=vert*4
        imagearrayRGB[y][x][2]=bleu*8

pil_image = Image.fromarray(imagearrayRGB, mode="RGB")
pil_image.save("image.jpg")