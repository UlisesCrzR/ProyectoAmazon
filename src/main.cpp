#include <iostream>
#include "tienda.h"

using namespace std;

int main(){
    system("chcp 65001 > nul"); // UTF-8

    Tienda Amazon("Amazon MX");
    Amazon.cargarCatalogos();

    int opcion;
    bool salir = false;

    do {
        cout << "\n--- Bienvenido a " << Amazon.getNombre() << " ---\n";
        cout << "1. Iniciar sesión\n";
        cout << "2. Registrarse\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        switch(opcion) {
        case 1: {
            string email, contrasena;
            int idUsuarioLogueado = 0;

            cout << "Email: ";
            cin >> email;
            cout << "Contraseña: ";
            cin >> contrasena;

            idUsuarioLogueado = Amazon.iniciarSesion(email, contrasena);

            if (idUsuarioLogueado != -1 && idUsuarioLogueado != 0) {
                bool enSesion = true;
                int subOpcion;

                while(enSesion) {
                    cout << "\n--- Menú de usuario ---\n";
                    cout << "1. Ver productos\n";
                    cout << "2. Agregar producto al carrito\n";
                    cout << "3. Realizar pedido\n";
                    cout << "4. Agregar producto a la tienda\n";
                    cout << "5. Mostrar Pedidos\n";
                    cout << "0. Cerrar sesión\n";
                    cout << "Opción: ";
                    cin >> subOpcion;

                    vector<Cliente> clientes = Amazon.getClientes(); 
                    int indiceCliente = -1;
                    
                    for(size_t k=0; k<clientes.size(); k++) {
                        if(clientes[k].getIdUsuario() == idUsuarioLogueado) {
                            indiceCliente = k;
                            break;
                        }
                    }

                    if(indiceCliente == -1 && subOpcion != 4 && subOpcion != 1 && subOpcion != 0) {
                        cout << "Error: No se encontró el cliente\n";
                        continue;
                    }

                    switch(subOpcion) {
                        case 1:{
                           Amazon.mostrarProductos();
                           break;
                        }
                        case 2: 
                        {
                            string email, pass, tel;
                            string nombre, apellido;
                            string calle, colonia, ciudad, estado, pais, referencias;
                            int numero, codigoPostal;
                            string numeroTarjeta, vencimiento;

                            cout << "Email: "; 
                            cin >> email;
                            cout << "Contraseña: "; 
                            cin >> pass;
                            cout << "Teléfono: "; 
                            cin >> tel;

                            if (Amazon.registrarse(email, pass, tel)) 
                            {
                                cout << "\n--- Datos del Cliente ---\n";

                                cout << "Nombre: "; 
                                cin >> nombre;
                                cout << "Apellido: "; 
                                cin >> apellido;

                                // Dirección
                                cout << "Calle: "; 
                                cin >> calle;
                                cout << "Colonia: "; 
                                cin >> colonia;
                                cout << "Número: "; 
                                cin >> numero;
                                cout << "Ciudad: "; 
                                cin >> ciudad;
                                cout << "Estado: "; 
                                cin >> estado;
                                cout << "Código Postal: "; 
                                cin >> codigoPostal;
                                cout << "País: "; 
                                cin >> pais;
                                cout << "Referencias: "; 
                                cin >> referencias;

                                // Método de pago
                                cout << "Número de Tarjeta: "; 
                                cin >> numeroTarjeta;
                                cout << "Fecha de vencimiento: "; 
                                cin >> vencimiento;

                                // Crear cliente en Amazon
                                Amazon.registrarCliente(nombre, apellido, calle, numeroTarjeta);

                                vector<Cliente> clientes = Amazon.getClientes();

                                for (size_t i = 0; i < clientes.size(); i++) 
                                {
                                    if (clientes[i].getIdUsuario() == idUsuarioLogueado) 
                                    {
                                        clientes[i].agregarDireccion(calle, colonia, numero, ciudad, estado, codigoPostal, pais, referencias);
                                        clientes[i].agregarMetodoPago(numeroTarjeta, vencimiento);
                                        break;
                                    }
                                }
                                cout << "Registro completado con dirección y método de pago.\n";
                            }
                            break;
                        }


                        case 3: {
                            if(clientes[indiceCliente].getMetodosPago().empty() || clientes[indiceCliente].getDirecciones().empty()) {
                                cout << "Necesitas tener al menos una dirección y un método de pago.\n";
                                break;
                            }

                            cout << "Selecciona método de pago (ID):\n";
                            clientes[indiceCliente].mostrarMetodosPago();
                            int idMetodo;
                            cin >> idMetodo;

                            cout << "Selecciona dirección de envío (ID):\n";
                            clientes[indiceCliente].mostrarDirecciones();
                            int idDir;
                            cin >> idDir;

                            string fecha;
                            cout << "Fecha (DD/MM/AAAA): ";
                            cin >> fecha;

                            if(idMetodo > 0 && idDir > 0) {
                                try {
                                    clientes[indiceCliente].realizarPedido(fecha, 
                                        clientes[indiceCliente].getDirecciones()[idDir-1], 
                                        clientes[indiceCliente].getMetodosPago()[idMetodo-1]);
                                    cout << "Pedido realizado con éxito.\n";
                                } catch (...) {
                                    cout << "Error al procesar el pedido. Intèntalo de nuevo :)\n";
                                }
                            }
                            break;
                        }

                        case 4: {
                            int _stock, _idCategoria;
                            string _nombre, _descripcion, _estado;
                            double _precio;
                            float _peso, _calificacion;

                            cin.ignore(); // Limpiar
                            cout << "Nombre: "; getline(cin, _nombre);
                            cout << "Descripción: "; getline(cin, _descripcion);
                            cout << "Precio: "; cin >> _precio;
                            cout << "Stock: "; cin >> _stock;
                            cout << "ID Categoría: "; cin >> _idCategoria;
                            cout << "Peso: "; cin >> _peso;
                            cin.ignore();
                            cout << "Estatus: "; getline(cin, _estado);
                            cout << "Calificación: "; cin >> _calificacion;

                            Amazon.agregarProducto(_nombre, _descripcion, _precio, _stock, _idCategoria, _peso, _estado, _calificacion);
                            cout << "Producto agregado al catálogo.\n";
                            break;
                        }

                        case 5: {
                            vector<Pedido> pedidos = clientes[indiceCliente].getPedidos();
                            if(pedidos.empty()){
                                cout << "No hay pedidos registrados.\n";
                            } else {
                                for(const auto& ped : pedidos) {
                                    cout << ped.obtenerDetalle() << "\n----------------\n";
                                }
                            }
                            break;
                        }

                        case 0:
                            enSesion = false;
                            cout << "Cerrando sesión...\n";
                            break;

                        default:
                            cout << "Opción no válida.\n";
                    }
                }
            }
            break;
        }

        case 2: {
            string email, pass, tel, nom, ape, dir, pago;
            
            cout << "Email: "; cin >> email;
            cout << "Contraseña: "; cin >> pass;
            cout << "Teléfono: "; cin >> tel;

            if(Amazon.registrarse(email, pass, tel)) {
                cout << "\n--- Datos del Cliente ---\n";
                cout << "Nombre: "; cin >> nom;
                cout << "Apellido: "; cin >> ape;
                cin.ignore(); // limpia del buferr 
                cout << "Dirección completa: "; 
                cin.ignore();
                getline(cin, dir);
                cout << "Nùmero de Tarjeta (Tarjeta): "; 
                cin.ignore();
                getline(cin, pago);

                Amazon.registrarCliente(nom, ape, dir, pago);
                cout << "Registro completado. Por favor inicia sesión.\n";
            }
            break;
        }

        case 0:
            salir = true;
            cout << "Hasta luego.\n";
            break;

        default:
            cout << "Opción incorrecta.\n";
            cin.clear();
        }

    } while(!salir);

    return 0;
}