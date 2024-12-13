#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <graphics.h>
#include <stdlib.h>
#include <ctype.h>

int menu, menu2, menu3, menu4;
int contador = 1;
int totalproducto = 0;
int totalcliente = 0;
int totalmembresia = 0;
int ingresar = 0, a = 0;
int encontrar;
int i;
int volvermenu, volvermenu2, volvermenu3, volvermenu4;

struct UsuaContra {
    char contrasena[20];
    char usuario[20];
};

struct Producto {
    int cantidad;
    char codigo[6];
    int precio;
    char nombre[12];
    char descripcion[50];
};

struct Cliente {
    char nombre[20];
    char codigo[20];
    char telefono[20];
};

struct membresia{
    char nombre[20];
    char codigo[20];
    int telefono[20];
    int precio[20];
};

struct Producto inventario[100];
struct Cliente usuarios[100];
struct membresia meber[100];

void AgregarProducto(void);
void buscar(void);
void EliminarProducto(void);
void ActualizarProducto(void);
void venderproducto(void);

void AgregarCliente(void);
void BuscarCliente(void);
void eliminarcliente(void);
void actualizacliente(void);
void uni(void);

void Agregarmembresia(void);
void vermembresia(void);
void actualizamembresia(void);
void eliminarmebresia(void);

void mostrarPagina(const char *texto);

void GuardarProductosTXT(void);
void GuardarClientesTXT(void);
void GuardarMembresiasTXT(void);

void ActualizarArchivoProductos(void);
void ActualizarArchivoClientes(void);
void ActualizarArchivoMembresias(void);

void LeerProductosTXT(void);
void LeerClientesTXT(void);
void LeerMembresiasTXT(void);

int main() {

char caracter;
    const char *pagina1 = "Manual de uso del programa:\n\n"
                          "Hola querido trabajador, en esta opcion de \"Manual\" podras guiarte...\n"
                          "Al entrar al menu tendras tres opciones:\n"
                          "1. Inventario\n"
                          "2. Clientes\n"
                          "3. Salir\n";

    const char *pagina2 = "1. En la opcion \"Inventario\" podras realizar varias acciones:\n"
                          "   - Agregar: Implementa nuevos productos ingresando datos como nombre, codigo,\n"
                          "     descripcion, precio y cantidad.\n"
                          "   - Buscar: Encuentra un producto por nombre o codigo.\n"
                          "   - Eliminar: Borra un producto del inventario.\n"
                          "   - Ver Inventario: Muestra todos los productos registrados.\n"
                          "   - Actualizar: Modifica los datos de un producto existente.\n"
                          "   - Vender: Registra una venta con datos del producto y cliente.\n";

    const char *pagina3 = "2. En la opcion \"Clientes\" podras realizar estas acciones:\n"
                          "   - Agregar cliente: Registra nombre, codigo y telefono del cliente.\n"
                          "   - Buscar cliente: Encuentra un cliente por codigo.\n"
                          "   - Eliminar cliente: Borra un cliente del programa.\n"
                          "   - Actualizar informacion: Modifica datos de un cliente registrado.\n"
                          "   - Ver cliente: Muestra toda la informacion de los clientes registrados.\n";

    const char *pagina4 = "3. En la opcion \"Membresias\" podras hacer las mismas funciones similares que\n"
        "haz utilizando anteriormente, podras ver los miembros, actualizarlos, eliminarlos y poder volver al menu\n\n"

        "5. Salir del programa: Cierra el sistema.\n\n"
        "Esperamos que este manual haya sido de ayuda.\n"
        "Gracias por utilizar nuestro programa!\n";

    struct UsuaContra sesion;
    clrscr();
    uni();

    LeerProductosTXT();
    LeerClientesTXT();
    LeerMembresiasTXT();

    do {
        contador = 1;
        while (contador <= 3) {

			printf("Buen dia estimado Trabajor!, Por favor ingresar su usuario.\n");
			scanf("%s", sesion.usuario);
			printf("Favor ingresar su contrasena\n");
			i = 0;

            while ((caracter = getch()) != 13) {
                if (caracter == 8 && i > 0) { i--; printf("\b \b"); }
                else if (caracter >= 33 && i < 15) { sesion.contrasena[i++] = caracter; printf("*"); }
            }
			sesion.contrasena[i] = '\0';
            if (strcmp(sesion.usuario, "fabri2024") == 0 && strcmp(sesion.contrasena, "1234") == 0) {

                clrscr();
                printf("Bienvenido al menú\n");
                printf("1-Inventario\n");
                printf("2- Clientes\n");
                printf("3-membresias\n");
                printf("4-Manual de ayuda\n");
                printf("5-Salir\n");
                scanf("%d", &menu);

                switch (menu) {
                    case 1:
                        do {
                            clrscr();
                            printf("\nInventario a dia de hoy\n");
                            printf("1. Agregar\n");
                            printf("2. Buscar\n");
                            printf("3. Eliminar\n");
                            printf("4. Ver Inventario\n");
                            printf("5. Actualizar\n");
                            printf("6. Vender\n");
                            printf("7. Volver al menu principal\n");
                            scanf("%d", &menu2);

                            switch (menu2) {
                                case 1:
                                    AgregarProducto();
                                    GuardarProductosTXT();
                                    break;
                                case 2:
                                    buscar();
                                    break;
                                case 3:
                                    EliminarProducto();
                                    ActualizarArchivoProductos();
                                    break;
                                case 4:
                                    if (totalproducto == 0) {
                                        printf("No hay productos en el inventario.\n");
                                    } else {
                                        for (i = 0; i < totalproducto; i++) {
                                            printf("Codigo: %s, Nombre: %s, Precio: %d, Cantidad: %d, Descripcion: %s\n",
                                                inventario[i].codigo, inventario[i].nombre, inventario[i].precio,
                                                inventario[i].cantidad, inventario[i].descripcion);
                                        }
                                    }
                                    ActualizarArchivoProductos();
                                    break;
                                case 5:
                                    ActualizarProducto();
                                    ActualizarArchivoProductos();
									
                                    break;
                                case 6:
                                    venderproducto();
                                    ActualizarArchivoProductos();
                                    break;
                                case 7:
                                    volvermenu2 = 0;
                                    break;
                                default:
                                    printf("Opcion no valida.\n");
                                    break;
                            }
                        } while (volvermenu2 == 1);
                        break;

                    case 2:
                        do {
                            clrscr();
                            printf("Bienvenido al apartado del cliente!\n");
                            printf("1. Agregar cliente\n");
                            printf("2. Buscar cliente\n");
                            printf("3. Eliminar cliente\n");
                            printf("4. Actualizar informacion del cliente\n");
                            printf("5. Ver cliente\n");
                            printf("6. Volver al menu\n");
                            scanf("%d", &menu3);

                            switch (menu3) {
                                case 1:
                                    AgregarCliente();
                                    GuardarClientesTXT();
                                    break;
                                case 2:
                                    BuscarCliente();
                                    break;
                                case 3:
                                    eliminarcliente();
                                    ActualizarArchivoClientes();
                                    break;
                                case 4:
                                    actualizacliente();
                                    ActualizarArchivoClientes();
                                    break;
                                case 5:
                                    if (totalcliente == 0) {
                                        printf("No hay clientes registrados.\n");
                                    } else {
                                        for (i = 0; i < totalcliente; i++) {
                                            printf("Codigo: %s, Nombre: %s, telefono: %s\n",
                                                usuarios[i].codigo, usuarios[i].nombre, usuarios[i].telefono);
                                        }
                                    }
                                    ActualizarArchivoClientes();
                                    break;
                                case 6:
                                    volvermenu3 = 0;
                                    break;
                                default:
                                    printf("No hay opcion disponible.\n");
                                    break;
                            }
                        } while (volvermenu3 == 1);
                        break;

                    case 3:
                        printf("1-Agregar membresia\n");
                        printf("2-Ver miembros\n");
                        printf("3-Actualizar miembros\n");
                        printf("4-Eliminar miembros\n");
                        printf("5-Volver al menu\n");
                        scanf("%d", &menu4);

                        switch (menu4)
                        {
                        case 1:
                            Agregarmembresia();
                            GuardarMembresiasTXT();
                            break;
                        case 2:
                            vermembresia();
                            ActualizarArchivoMembresias();
                            break;
                        case 3:
                            actualizamembresia();
                            ActualizarArchivoMembresias();
                            break;
                        case 4:
                            eliminarmebresia();
                            ActualizarArchivoMembresias();
                            break;
                        default:
                            break;
                        }
                        break;
                    
                    case 4: 
                        printf("Mostrando el manual del programa:\n\n");

                        mostrarPagina(pagina1);
                        mostrarPagina(pagina2);
                        mostrarPagina(pagina3);
                        mostrarPagina(pagina4);

                    case 5:
                        printf("Ten buen dia estimado %s\n", sesion.usuario);
                        return 0;
                        break;

                    default:
                        printf("Opcion no valida\n");
                        break;
                }
            } else {
                if (contador == 3) {
                    printf("Lamentamos informarle que fallo los 3 intentos\n\n");
                } else {
                    printf("Ingrese los datos nuevamente\n");
                }
                contador++;
            }
        }
    } while (menu != 3);
    getch();
    return 0;
}

void LeerProductosTXT() {
    FILE *archivo = fopen("C:\\TC20\\archivo\\productos.TXT", "rt");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de productos.\n");
        return;
    }
    fscanf(archivo, "%d", &totalproducto);
    for (i = 0; i < totalproducto; i++) {
        fscanf(archivo, "%s %s %s %d %d", 
               inventario[i].codigo, inventario[i].nombre, inventario[i].descripcion,
               &inventario[i].precio, &inventario[i].cantidad);
    }
    fclose(archivo);
    printf("Productos cargados exitosamente.\n");
}

void LeerClientesTXT() {
    FILE *archivo = fopen("C:\\TC20\\archivo\\clientes.TXT", "rt");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de clientes.\n");
        return;
    }
    fscanf(archivo, "%d", &totalcliente);
    for (i = 0; i < totalcliente; i++) {
        fscanf(archivo, "%s %s %s", 
               usuarios[i].codigo, usuarios[i].nombre, usuarios[i].telefono);
    }
    fclose(archivo);
    printf("Clientes cargados exitosamente.\n");
}

void LeerMembresiasTXT() {
    FILE *archivo = fopen("C:\\TC20\\archivo\\membresias.TXT", "rt");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de membresías.\n");
        return;
    }
    fscanf(archivo, "%d", &totalmembresia);
    for (i = 0; i < totalmembresia; i++) {
        fscanf(archivo, "%s %s %d %d", 
               meber[i].codigo, meber[i].nombre, meber[i].telefono, &meber[i].precio);
    }
    fclose(archivo);
    printf("Membresías cargadas exitosamente.\n");
}
void AgregarProducto() {
    
    if (totalproducto < 100) {
        printf("Ingrese el nombre del producto: ");
        scanf("%s", inventario[totalproducto].nombre);
        printf("Ingrese el codigo del producto: ");
        scanf("%s", inventario[totalproducto].codigo);
        printf("Ingrese la descripcion del producto: ");
        scanf("%s", inventario[totalproducto].descripcion);
        printf("Ingrese el precio del producto: ");
        scanf("%d", &inventario[totalproducto].precio);
        if(inventario[totalproducto].precio > 0){
            printf("Ingrese la cantidad del producto: ");
            scanf("%d", &inventario[totalproducto].cantidad);
            if(inventario[totalproducto].cantidad > 0){
            totalproducto++;
            printf("Producto agregado exitosamente.\n");
            }
        }
    } else {
        printf("Inventario lleno. No se pueden agregar más productos.\n");
    }
}
void buscar() {
    char nombre[12];
    char codigo[6];
    int encontrado = 0;
    printf("1. Buscar por nombre\n");
    printf("2. Buscar por codigo\n");
    scanf("%d", &encontrar);

    switch (encontrar) {
        case 1:
            printf("Ingrese el nombre del producto: ");
            scanf("%s", nombre);
            for (i = 0; i < totalproducto; i++) {
                if (strcmp(inventario[i].nombre, nombre) == 0) {
                    printf("Producto encontrado:\n");
                    printf("Codigo: %s, Nombre: %s, Precio: %d, Cantidad: %d, Descripcion: %s\n",
                           inventario[i].codigo, inventario[i].nombre, inventario[i].precio,
                           inventario[i].cantidad, inventario[i].descripcion);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                printf("Producto no encontrado.\n");
            }
            break;

        case 2:
            printf("Ingrese el codigo del producto: ");
            scanf("%s", codigo);
            for (i = 0; i < totalproducto; i++) {
                if (strcmp(inventario[i].codigo, codigo) == 0) {
                    printf("Producto encontrado:\n");
                    printf("Codigo: %s, Nombre: %s, Precio: %d, Cantidad: %d, Descripcion: %s\n",
                           inventario[i].codigo, inventario[i].nombre, inventario[i].precio,
                           inventario[i].cantidad, inventario[i].descripcion);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                printf("Producto no encontrado.\n");
            }
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }
}

void EliminarProducto() {
    char codigo[6];
    int encontrado = 0;
	int j;
    printf("Ingrese el codigo del producto a eliminar: ");
    scanf("%s", codigo);
    for (i = 0; i < totalproducto; i++) {
        if (strcmp(inventario[i].codigo, codigo) == 0) {
			for (j = i; j < totalproducto - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            totalproducto--;
            printf("Producto eliminado exitosamente.\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Producto no encontrado para eliminar.\n");
    }
}

void ActualizarProducto() {
    char codigo[6];
    printf("Ingrese el codigo del producto a actualizar: ");
    scanf("%s", codigo);
    for (i = 0; i < totalproducto; i++) {
        if (strcmp(inventario[i].codigo, codigo) == 0) {
            printf("Actualizar el nombre del producto (actual: %s): ", inventario[i].nombre);
            scanf("%s", inventario[i].nombre);
            printf("Actualizar la descripcion del producto (actual: %s): ", inventario[i].descripcion);
            scanf("%s", inventario[i].descripcion);
            printf("Actualizar el precio del producto (actual: %d): ", inventario[i].precio);
            scanf("%d", &inventario[i].precio);
            if(inventario[i].precio >= 0){
                printf("Actualizar la cantidad del producto (actual: %d): ", inventario[i].cantidad);
                scanf("%d", &inventario[i].cantidad);
				if(inventario[i].cantidad > 0){
                printf("Producto actualizado exitosamente.\n");
                }else{
                    printf("como vas a meter menos un producto ._.");
                }
            }
        }
		
    }
	
    printf("Producto no encontrado.\n");
}

void venderproducto() {
    char codigo[6];
    int cantidad, dinero;
	int encontrado = 0; /*si el producto se encontro*/
    int tieneMembresia, aniosMembresia;
    float descuento, total;

    printf("Ingrese el codigo del producto a vender: ");
    scanf("%s", codigo);

    for (i = 0; i < totalproducto; i++) {
        if (strcmp(inventario[i].codigo, codigo) == 0) {
			encontrado = 1;
            printf("Ingrese la cantidad a vender: ");
            scanf("%d", &cantidad);

            if (cantidad > inventario[i].cantidad) {
                printf("No hay suficiente cantidad en inventario.\n");
            } else {
                total = inventario[i].precio * cantidad;

               
                printf("El cliente tiene una membresia activa mayor a un anio? (1: Si, 0: No): ");
                scanf("%d", &tieneMembresia);

                if (tieneMembresia == 1) {
                    printf("Cuantos anios tiene con la membresia?: ");
                    scanf("%d", &aniosMembresia);

            
                    descuento = (aniosMembresia * 10) / 100.0;
                    if (descuento > 0.5) {
                        descuento = 0.5;
                    }
                    total -= total * descuento; 
                    printf("Se aplico un descuento del %.0f%%. Total con descuento: %.2f\n", descuento * 100, total);
                } else {
                    printf("No se aplica descuento. Total: %.2f\n", total);
                }


                printf("Ingrese la cantidad de dinero del cliente: ");
                scanf("%d", &dinero);

                if (dinero < total) {
                    printf("Dinero insuficiente para realizar la compra.\n");
                } else {
                    inventario[i].cantidad -= cantidad;
                    printf("Venta realizada. Total vendido: %.2f\n", total);
                    printf("Cambio devuelto: %.2f\n", dinero - total);
                }
            }
            break; 
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}


void AgregarCliente() {
    if (totalcliente < 100) {
        do
        {


        printf("Ingrese el nombre de usuario: ");
        scanf("%s", usuarios[totalcliente].nombre);
        if (strlen(usuarios[totalcliente].nombre) < 3) {
			printf( "Error: Nombre demasiado corto.\n");


        }
        } while (strlen(usuarios[totalcliente].nombre) < 3);



        do
        {
            
        
        printf("Ingrese el codigo del cliente: ");
        scanf("%s", usuarios[totalcliente].codigo);

        } while (strlen(usuarios[totalcliente].codigo) < 2 || 
            !isdigit(usuarios[totalcliente].codigo[0]) || 
            !isdigit(usuarios[totalcliente].codigo[1])||
            !isdigit(usuarios[totalcliente].codigo[2])||
            strlen(usuarios[totalcliente].codigo) > 3);


        
        do
        {
    
    
        printf("Ingrese el telefono del cliente: ");
        scanf("%s", usuarios[totalcliente].telefono); 
            if (strlen(usuarios[totalcliente].telefono) != 8 || 
            strspn(usuarios[totalcliente].telefono, "0123456789") != 8) {
            printf("Error: Numero de telefono invalido. Debe tener 8 digitos.\n");
            continue;
        }
        } while (strlen(usuarios[totalcliente].telefono) != 8 || strlen(usuarios[totalcliente].telefono < 0));

        totalcliente++;
        printf("Cliente agregado exitosamente.\n");
    } else {
        printf("No se puede agregar más clientes.\n");
    }
}

void BuscarCliente(void) {
    char codigo[6];
    int encontrado = 0;

    printf("Ingrese el codigo del cliente a buscar: ");
    scanf("%s", codigo);
    for (i = 0; i < totalcliente; i++) {
        if (strcmp(usuarios[i].codigo, codigo) == 0) {
            printf("Cliente encontrado:\n");
            printf("Codigo: %s, Nombre: %s, telefono: %d\n", usuarios[i].codigo, usuarios[i].nombre, usuarios[i].telefono);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Cliente no encontrado.\n");
    }
}

void eliminarcliente(){
    char codigo[6];
    int encontrado = 0;
	int j;
    printf("Ingrese el codigo del cliente a eliminar: ");
    scanf("%s", codigo);
    for (i = 0; i < totalcliente; i++) {
        if (strcmp(usuarios[i].codigo, codigo) == 0) {
			for (j = i; j < totalcliente - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            totalcliente--;
            printf("Cliente eliminado exitosamente.\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Cliente no encontrado para eliminar.\n");
    }
}

void actualizacliente() {
    char codigo[6];
    printf("Ingrese el codigo del cliente a actualizar: ");
    scanf("%s", codigo);
    
    for (i = 0; i < totalcliente; i++) {
        if (strcmp(usuarios[i].codigo, codigo) == 0) {
            printf("Actualizar el nombre del cliente (actual: %s): ", usuarios[i].nombre);
            scanf("%s", usuarios[i].nombre);
            printf("Actualizar el telefono del cliente (actual: %s): ", usuarios[i].telefono);
            scanf("%d", usuarios[i].telefono);
		 if( usuarios[i].telefono >= 0000 &&  usuarios[i].telefono <= 9999){
            printf("Cliente actualizado exitosamente.\n");

			ActualizarArchivoClientes();
            return;
            }
        }else{
        printf("Cliente no encontrado.\n");
        }
    }
}


void uni(){
    int driver=DETECT,modo;
	initgraph(&driver,&modo," ");
	cleardevice();

	/*Color de fondo*/
	setcolor(WHITE);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);

	/*Letra U*/
	setcolor(BLUE);
	setfillstyle(1,BLUE);
	bar(53,88,147,338);
	delay(300);
	bar(137,250,323,338);
	delay(300);
	bar(235,150,323,338);
	delay(300);

	/*letra N*/
	bar(153,242,230,88);
	delay(300);
	bar(230,88,425,144);
	delay(300);
	bar(331,144,425,338);

	/*letra i*/
	bar(423,258,504,338);
	delay(300);
	bar(504,338,433,161);
	delay(300);
	bar(433,88,502,151);

	setcolor(0);
	outtextxy(380,400, "Fabrizio Lopez Mejia");
    settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
	outtextxy(380,410, "Bismarck Santana Bermudez");
    settextstyle(DEFAULT_FONT, HORIZ_DIR,1);

	for(i = 0; i < 16; i++){
	delay(300);
	setcolor(0+i);
	outtextxy(380,400, "Fabrizio Lopez Mejia");
    settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
	outtextxy(380,410, "Bismarck Santana Bermudez");
    settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
	}
    getch();
    closegraph();
}

void Agregarmembresia(){
   int vuelto;
   if (totalmembresia < 100) {
        do
        {


        printf("Ingrese el nombre de usuario: ");
        scanf("%s", usuarios[totalmembresia].nombre);
        if (strlen(usuarios[totalmembresia].nombre) < 3) {
			printf( "Error: Nombre demasiado corto.\n");


        }
        } while (strlen(usuarios[totalmembresia].nombre) < 3);



        do
        {


        printf("Ingrese el codigo del cliente: ");
        scanf("%s", usuarios[totalmembresia].codigo);

        } while (strlen(usuarios[totalmembresia].codigo) < 2 ||
            !isdigit(usuarios[totalmembresia].codigo[0]) ||
            !isdigit(usuarios[totalmembresia].codigo[1])||
            !isdigit(usuarios[totalmembresia].codigo[2])||
            strlen(usuarios[totalmembresia].codigo) > 3);



        do
        {


        printf("Ingrese el telefono del cliente: ");
        scanf("%s", usuarios[totalmembresia].telefono);
            if (strlen(usuarios[totalmembresia].telefono) != 8 ||
            strspn(usuarios[totalmembresia].telefono, "0123456789") != 8) {
            printf("Error: Numero de telefono invalido. Debe tener 8 digitos.\n");
            continue;
        }
        } while (strlen(usuarios[totalmembresia].telefono) != 8 || strlen(usuarios[totalcliente].telefono < 0));



		printf("Ingresa el dinero para pagar: ");
        scanf("%d", &meber[totalmembresia].precio);

        if(meber[totalmembresia].precio >= 100){
            vuelto = meber[totalmembresia].precio - 100;

            totalmembresia++;





        printf("Obtuviste la membresia.\n");
    } else {
        printf("No se puede agregar más clientes.\n");
    }
}
}

void vermembresia(){
   char codigo[6];
	int encontrado = 0;

    printf("Ingrese el codigo del cliente a buscar: ");
    scanf("%s", codigo);
    for (i = 0; i < totalmembresia; i++) {
        if (strcmp(meber[i].codigo, codigo) == 0) {
            printf("Cliente encontrado:\n");
            printf("Codigo: %s, Nombre: %s, telefono: %d\n", meber[i].codigo, meber[i].nombre, meber[i].telefono);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Cliente no encontrado.\n");
    }

}

void actualizamembresia(){
    char codigo[6];
    printf("Ingrese el codigo del cliente a actualizar: ");
    scanf("%s", codigo);
    for (i = 0; i < totalmembresia; i++) {
        if (strcmp(meber[i].codigo, codigo) == 0) {
            printf("Actualizar el nombre del cliente (actual: %s): ", meber[i].nombre);
            scanf("%s", meber[i].nombre);
            printf("Actualizar el telefono del cliente (actual: %s): ", meber[i].telefono);
            scanf("%d", meber[i].telefono);
		 if( meber[i].telefono >= 0000 &&  meber[i].telefono <= 9999){
            printf("Cliente actualizado exitosamente.\n");

			ActualizarArchivoMembresias();
            return;
            }
        }else{
        printf("Cliente no encontrado.\n");
        }
    }
}

void eliminarmebresia(){
    char codigo[6];
    int encontrado = 0;
	int j;
    printf("Ingrese el codigo del cliente a eliminar: ");
    scanf("%s", codigo);
    for (i = 0; i < totalmembresia; i++) {
        if (strcmp(meber[i].codigo, codigo) == 0) {
			for (j = i; j < totalmembresia - 1; j++) {
                meber[j] = meber[j + 1];
            }
            totalmembresia--;
            printf("Cliente eliminado exitosamente.\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Cliente no encontrado para eliminar.\n");
    }
}

void mostrarPagina(const char *texto) {
	clrscr();
    printf("%s\n", texto);
	printf("\nPresiona cualquier tecla para siguiente pagina.\n");
    getch();
}

void GuardarProductosTXT() {
int i;
    FILE *archivo = fopen("C:\\TC20\\archivo\\productos.TXT", "at");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    fprintf(archivo, "%d\n", totalproducto);
	for (i = 0; i < totalproducto; i++) {
        fprintf(archivo, "%s %s %s %d %d\n",
                inventario[i].codigo, inventario[i].nombre, inventario[i].descripcion,
                inventario[i].precio, inventario[i].cantidad);
    }
    fclose(archivo);
    printf("Productos guardados exitosamente.\n");
}

void GuardarClientesTXT() {
    int i;
    FILE *archivo = fopen("C:\\TC20\\archivo\\clientes.TXT", "wt");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar clientes.\n");
        return;
    }
    fprintf(archivo, "%d\n", totalcliente);
    for (i = 0; i < totalcliente; i++) {
        fprintf(archivo, "%s %s %s\n", 
                usuarios[i].codigo, usuarios[i].nombre, usuarios[i].telefono); 
    }
    fclose(archivo);
    printf("Clientes guardados exitosamente.\n");
}
void GuardarMembresiasTXT() {
int i;
    FILE *archivo = fopen("C:\\TC20\\archivo\\membresias.TXT", "at");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    fprintf(archivo, "%d\n", totalmembresia); 
    for (i = 0; i < totalmembresia; i++) {
        fprintf(archivo, "%s %s %s %d\n", 
                meber[i].codigo, meber[i].nombre, meber[i].telefono, meber[i].precio);
    }
    fclose(archivo);
    printf("Membresias guardadas exitosamente.\n");
}

void ActualizarArchivoProductos() {
int i;
	FILE *archivo = fopen("C:\\TC20\\archivo\\productos.TXT", "wt");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de productos.\n");
        return;
    }

    fprintf(archivo, "%d\n", totalproducto);
	for (i = 0; i < totalproducto; i++) {
        fprintf(archivo, "%s %s %s %d %d\n",
                inventario[i].codigo,
                inventario[i].nombre,
                inventario[i].descripcion,
                inventario[i].precio,
                inventario[i].cantidad);
    }

    fclose(archivo);
    printf("Archivo de productos actualizado correctamente.\n");
}

void ActualizarArchivoClientes() {
int i;
	
    FILE *archivo = fopen("C:\\TC20\\archivo\\clientes.TXT", "wt");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de clientes.\n");
        return;
    }

    fprintf(archivo, "%d\n", totalcliente);
	for (i = 0; i < totalcliente; i++) {
        fprintf(archivo, "%s %s %d\n",
                usuarios[i].codigo,
                usuarios[i].nombre,
                usuarios[i].telefono);
    }

    fclose(archivo);
    printf("Archivo de clientes actualizado correctamente.\n");
}

void ActualizarArchivoMembresias() {
int i;
    FILE *archivo = fopen("C:\\TC20\\archivo\\membresias.TXT", "wt");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de membresias.\n");
        return;
    }

    fprintf(archivo, "%d\n", totalmembresia);
	for (i = 0; i < totalmembresia; i++) {
        fprintf(archivo, "%s %s %d %d\n",
                meber[i].codigo,
                meber[i].nombre,
                meber[i].telefono,
                meber[i].precio);
    }

    fclose(archivo);
    printf("Archivo de membresias actualizado correctamente.\n");
}

