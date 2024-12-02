#include <stdio.h>
#include <conio.h>
#include <string.h>

int menu, menu2, menu3;
int contador = 1;
int totalproducto = 0;
int totalcliente = 0;
int ingresar = 0, a = 0;
int encontrar; 
int i;
int volvermenu, volvermenu2, volvermenu3;

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
    char codigo[6];
    int telefono[10];
};

struct Producto inventario[100];
struct Cliente usuarios[100];

void AgregarProducto(void);
void buscar(void);
void EliminarProducto(void);
void ActualizarProducto(void);
void venderproducto(void);

void AgregarCliente(void);
void BuscarCliente(void);
void eliminarcliente(void);
void actualizacliente(void);

int main() {
    struct UsuaContra sesion;
    clrscr();

    do {
        contador = 1;
        while (contador <= 3) {
            printf("Buen dia estimado Trabajor!, Por favor ingresar su usuario.\n");
            scanf("%s", sesion.usuario);
            printf("Favor ingresar su contrasena\n");
            scanf("%s", sesion.contrasena);

            if (strcmp(sesion.usuario, "fabri2024") == 0 && strcmp(sesion.contrasena, "12") == 0) {
                clrscr();
                printf("Bienvenido al menú\n");
                printf("1-Inventario\n");
                printf("2- Clientes\n");
                printf("3-Salir\n");
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
                                    break;
                                case 2:
                                    buscar();
                                    break;
                                case 3:
                                    EliminarProducto();
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
                                    break;
                                case 5:
                                    ActualizarProducto();
                                    break;
                                case 6:
                                    venderproducto();
                                    break;
                                case 7:
                                    volvermenu2 = 0;
                                    break;
                                default:
                                    printf("Opción no válida.\n");
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
                            printf("4. Actualizar información del cliente\n");
                            printf("5. Ver cliente\n");
                            printf("6. Volver al menú\n");
                            scanf("%d", &menu3);

                            switch (menu3) {
                                case 1:
                                    AgregarCliente();
                                    break;
                                case 2:
                                    BuscarCliente();
                                    break;
                                case 3:
                                    eliminarcliente();
                                    break;
                                case 4:
                                    actualizacliente();
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
                                    break;
                                case 6:
                                    volvermenu3 = 0;
                                    break;
                                default:
                                    printf("No hay opción disponible.\n");
                                    break;
                            }
                        } while (volvermenu3 == 1);
                        break;

                    case 3:
                        printf("Ten buen dia estimado %s\n", sesion.usuario);
                        return 0;

                    default:
                        printf("Opción no válida\n");
                        break;
                }
            } else {
                if (contador == 3) {
                    printf("Lamentamos informarle que falló los 3 intentos\n\n");
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
    int encontrado = 0; /*controlar si el producto se encontro*/
	int total;

    printf("Ingrese el codigo del producto a vender: ");
    scanf("%s", codigo);

    for (i = 0; i < totalproducto; i++) {
        if (strcmp(inventario[i].codigo, codigo) == 0) {
            encontrado = 1; /*Producto encontrado*/
            printf("Ingrese la cantidad a vender: ");
            scanf("%d", &cantidad);

            if (cantidad > inventario[i].cantidad) {
                printf("No hay suficiente cantidad en inventario.\n");
            } else {
                printf("Ingrese la cantidad de dinero del usuario: ");
                scanf("%d", &dinero);

				total = inventario[i].precio * cantidad;
                if (dinero < total) {
                    printf("Dinero insuficiente para realizar la compra.\n");
                } else {
                    inventario[i].cantidad -= cantidad;
                    printf("Venta realizada. Total vendido: %d\n", total);
                    printf("Cambio devuelto: %d\n", dinero - total);
                }
            }
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}


void AgregarCliente() 
{
    if (totalcliente < 100) {
        printf("Ingrese el nombre del cliente: ");
        scanf("%s", usuarios[totalcliente].nombre);
        printf("Ingrese el codigo del cliente: ");
        scanf("%s", usuarios[totalcliente].codigo);
        printf("Ingrese el telefono del cliente: ");
        scanf("%d", usuarios[totalcliente].telefono);
		if( usuarios[totalcliente].telefono >= 0000 &&  usuarios[totalcliente].telefono <= 9999){
            totalcliente++;
            printf("Cliente agregado exitosamente.\n");
        }
    } else {
        printf("Registro de clientes lleno.\n");
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

void actualizacliente(){
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
            return;
            }
        }else{ 
        printf("Cliente no encontrado.\n");
        }
    }
}
