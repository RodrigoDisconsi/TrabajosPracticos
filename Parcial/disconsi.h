
float getFloat(char mensaje[]);
int getInt(char mensaje[]);
char getChar(char mensaje[]);

int esNumerico(char str[]);
int esSoloLetras (char str[]);
int esAlfaNumerico(char str[]);
int esTelefono(char str[]);

void getString(char mensaje[], char input[]);
int getStringLetras(char mensaje[], char input[], char msgError[]);
int getStringNumeros(char mensaje[], char input[], char msgError[]);
int getStringAlfaNumerico(char mensaje[], char input[]);

int esPatente(char str[]);
int validarInt(int desde, int hasta, char* numero, char* msgError);
int confirma(char* mensaje);
