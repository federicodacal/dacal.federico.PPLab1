#ifndef UTN_VALIDACIONES_H_INCLUDED
#define UTN_VALIDACIONES_H_INCLUDED

int myGets(char* str, int length);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getSexo(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int validarSexo(char* str);
int utn_getDNI(char* pResultado, char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos);
int utn_getTelefono(char* pResultado, char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos);
int utn_getChar(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);

#endif // UTN_VALIDACIONES_H_INCLUDED
