import os
import shutil

# Ruta donde están los archivos 
ruta = os.getcwd()

# Creamos carpetas en destino según tipo
tipos = [
	"Imagenes", "Documentos_excel", "Documentos_3mf", "PDF's",
	"Videos", "Documentos_Word", "Documentos_txt", "ZIP", "RAR"
]

for carpeta in tipos:
	ruta_carpeta = os.path.join(ruta, carpeta)
	if not os.path.exists(ruta_carpeta):
		os.makedirs(ruta_carpeta)

# Recorremos archivos y los movemos según su tipo
for archivo in os.listdir(ruta):
	archivo_lower = archivo.lower()
	origen = os.path.join(ruta, archivo)

	try:
		if archivo_lower.endswith(".jpg") or archivo_lower.endswith(".png"):
			shutil.move(origen, os.path.join(ruta, "Imagenes", archivo))

		elif archivo_lower.endswith(".pdf"):
			shutil.move(origen, os.path.join(ruta, "PDF's", archivo))

		elif archivo_lower.endswith(".mp4"):
			shutil.move(origen, os.path.join(ruta, "Videos", archivo))

		elif archivo_lower.endswith(".doc") or archivo_lower.endswith(".docx"):
			shutil.move(origen, os.path.join(ruta, "Documentos_Word", archivo))

		elif archivo_lower.endswith(".txt"):
			shutil.move(origen, os.path.join(ruta, "Documentos_txt", archivo))

		elif archivo_lower.endswith(".zip"):
			shutil.move(origen, os.path.join(ruta, "ZIP", archivo))

		elif archivo_lower.endswith(".rar"):
			shutil.move(origen, os.path.join(ruta, "RAR", archivo))

		elif archivo_lower.endswith(".xls") or archivo_lower.endswith(".xlsx"):
			shutil.move(origen, os.path.join(ruta, "Documentos_excel", archivo))

		elif archivo_lower.endswith(".3mf"):
			shutil.move(origen, os.path.join(ruta, "Documentos_3mf", archivo))

	except Exception as e:
		print(f" No se pudo mover '{archivo}': {e}")
