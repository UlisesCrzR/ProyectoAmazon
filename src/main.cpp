#include<iostream>
#include "tienda.h"

using namespace std;

int main(){
    system("chcp 65001"); // UTF-8

    Tienda Amazon("Amazon MX");
    Amazon.cargarCatalogos();

    int opcion, subOpcion;
    string email, contrasena, telefono;
    string nombre, apellido, direccion, metodoPago;
    vector<Cliente> clientes;

    bool sesionIniciada = false;

    do{
        cout << "\n--- Bienvenido a " << Amazon.getNombre() << " ---\n";
        cout << "1. Iniciar sesión\n";
        cout << "2. Registrarse\n";
        cout << "0. Salir\n";
        cin >> opcion;

        switch(opcion){

        // Iniciar Sesion
        case 1:{
            int idUsuarioLogueado = 0;

            do{
                cout << "Email: ";
                cin >> email;
                cout << "Contraseña: ";
                cin >> contrasena;

                idUsuarioLogueado = Amazon.iniciarSesion(email, contrasena);
            }while(idUsuarioLogueado == 0);

            sesionIniciada = true;

            //Menu usuario Logueado
            do{
                cout << "\n--- Menú de usuario ---\n";
                cout << "1. Ver productos\n";
                cout << "2. Agregar producto al carrito\n";
                cout << "3. Realizar pedido\n";
                cout << "4. Agregar producto\n";
                cout << "0. Cerrar sesión\n";
                cin >> subOpcion;

                switch(subOpcion){

                case 1:
                    Amazon.mostrarProductos();
                    break;

                case 2:
                    Amazon.mostrarProductos();
                    clientes = Amazon.getClientes();

                    for(int i = 0; i < clientes.size(); i++){
                        if(clientes[i].getIdUsuario() == idUsuarioLogueado){
                            
                            cout << "Hola " << clientes[i].getNombre() << "!\n";
                            cout << "Selecciona el ID del producto a agregar al carrito: ";

                            int idProducto;
                            cin >> idProducto;
                        }
                    }
                    break;

                case 3:
                    //Amazon.realizarPedido();
                    break;

                case 4:{
                    int id, stock, idCategoria;
                    string nombre, descripcion, estatus;
                    double precio;
                    float peso, calificacion;

                    cout << "ID del producto: ";
                    cin >> id;
                    cout << "Nombre: ";
                    cin >> nombre;
                    cout << "Descripción: ";
                    cin >> descripcion;
                    cout << "Precio: ";
                    cin >> precio;
                    cout << "Stock: ";
                    cin >> stock;
                    cout << "ID de categoría: ";
                    cin >> idCategoria;
                    cout << "Peso: ";
                    cin >> peso;
                    cout << "Estatus: ";
                    cin >> estatus;
                    cout << "Calificación promedio: ";
                    cin >> calificacion;

                    Amazon.agregarProducto(
                        id, nombre, descripcion, precio,
                        stock, idCategoria, peso, estatus,
                        calificacion
                    );
                    break;
                }

                case 0:
                    cout << "Sesión cerrada.\n";
                    sesionIniciada = false;
                    break;

                default:
                    cout << "Opción inválida.\n";
                }

            }while(sesionIniciada != 0);

        } break;


        //Registrarse
        case 2:{
            bool registroCorrecto = false;

            do{
                cout << "Email: ";
                cin >> email;
                cout << "Contraseña: ";
                cin >> contrasena;
                cout << "Teléfono: ";
                cin >> telefono;

                registroCorrecto = Amazon.registrarse(email, contrasena, telefono);

            }while(registroCorrecto == false);

            cout << "\n--- Completa tu información ---\n";
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Apellido: ";
            cin >> apellido;
            cout << "Dirección: ";
            cin >> direccion;
            cout << "Método de pago: ";
            cin >> metodoPago;

            Amazon.registrarCliente(nombre, apellido, direccion, metodoPago);

            cout << "\nRegistro completo. Ahora inicia sesión.\n";
        } break;


        //Salir
        case 0:
            cout << "Gracias por visitar " << Amazon.getNombre() << ". ¡Hasta luego!\n";
            break;

        default:
            cout << "Opción inválida, intente de nuevo.\n";
        }

    }while(opcion != 0);

    return 0;
}
