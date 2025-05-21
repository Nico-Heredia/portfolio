import os
import shutil

#Ruta donde estan los archivos 

ruta = os.getcwd()

#Creamos carpetas en destino segun tipo

tipos = ["Imagenes", "Documentos_excel","Documentos_3mf", "PDF's", "Videos", "Documentos_Word", "Documentos_txt", "ZIP", "RAR"]

for carpeta in tipos:

    ruta_carpeta = os.path.join(ruta,carpeta)

    if not os.path.exists(ruta_carpeta):
        os.makedirs(ruta_carpeta)

for archivo in os.listdir(ruta):
    if archivo.endswith(".jpg") or archivo.endswith(".png"):
        shutil.move(os.path.join(ruta,archivo), os.path.join(ruta,"Imagenes", archivo))

    elif archivo.endswith(".pdf"):
        shutil.move(os.path.join(ruta,archivo), os.path.join(ruta,"PDF's", archivo))

    elif archivo.endswith(".mp4"):
        shutil.move(os.path.join(ruta,archivo), os.path.join(ruta,"Videos", archivo))

    elif archivo.endswith(".doc") or archivo.endswith(".docx"):
        shutil.move(os.path.join(ruta,archivo), os.path.join(ruta,"Domucmentos_Word", archivo))

    elif archivo.endswith(".txt"):
        shutil.move(os.path.join(ruta,archivo), os.path.join(ruta,"Documentos_txt", archivo))

    elif archivo.endswith(".zip"):
        shutil.move(os.path.join(ruta,archivo), os.path.join(ruta,"ZIP", archivo))

    elif archivo.endswith(".rar"):
        shutil.move(os.path.join(ruta,archivo), os.path.join(ruta,"RAR", archivo))

    elif archivo.endswith(".xls"):
        shutil.move(os.path.join(ruta,archivo), os.path.join(ruta,"Documentos_excel", archivo))
    
    elif archivo.endswith(".3mf"):
        shutil.move(os.path.join(ruta,archivo), os.path.join(ruta,"Documentos_3mf", archivo))



# Para empaquetar en .exe
#pip install pyinstaller
#pyinstaller --onefile OrdenaArchivoEnCarpeta.py

