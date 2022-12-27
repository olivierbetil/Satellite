#**********************************************************************************************************
#   @file bin2txt.py
#   @author Olivier BETIL
#   @brief enregistre une image arrivant dans un port serial dans un fichier .txt
#   @date 21/12/2022
#**********************************************************************************************************

#Utilisation des librairies:
#   PySerial: Lecture des ports serial de l'ordinateur
#   Numpy: gestion de matrices
import serial
import numpy as np

#Initialisation et ouverture du port COM
ser = serial.Serial()
ser.baudrate = 115200
ser.port = 'COM15'
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
image=""
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

#transformation de la matrice en une chaine pour enregistrer dans un fichier .txt
for y in range(120):
    for x in range(160):
        if(imagearray[y][x][0]=="b''"):
            imx=0
        else:
            imx=imagearray[y][x][0]
        if(imagearray[y][x][1]=="b''"):
            imy=0
        else:
            imy=imagearray[y][x][1]
        image+=str(imx)+"  "+str(imy)+"\n"




#enregistre dans un fichier .txt les valeurs reçues
doc = open("test.txt", "w", encoding='utf-8')
doc.write(image)
doc.close()