#include<iostream>
#include "tienda.h"

using namespace std;

int main(){
    system("chcp 65001"); // UTF-8
    Tienda Amazon("Amazon MX");
    Amazon.cargarCatalogos();

    int opcion, subOpcion, optionProducto;
    string email, contrasena, telefono, nombre, apellido, direccion, metodoPago;
    bool respuesta = false;


    do{
        cout<<"Bienvenido a "<<Amazon.getNombre()<<endl;
        cout<<"Por favor seleccione una opcion:"<<endl;
        cout<<"1. Iniciar sesion"<<endl;
        cout<<"2. Registrarse"<<endl;
        cout<<"0. Salir"<<endl;
        cin>>opcion;

        if(opcion == 1){
            bool respuestaId = 0;
            do{
                cout<<"Por favor, ingrese sus credenciales para iniciar sesion."<<endl;
                cout<<"Email: ";
                cin>>email;
                cout<<"Contraseña: ";
                cin>>contrasena;
                respuestaId = Amazon.iniciarSesion(email, contrasena);
            }while(respuestaId == 0);

            cout<<"Seleccione otra opción que desea hacer";
            cout<<"1. Hacer una pedido"<<endl;
            cout<<"2. Agregar producto"<<endl;

            cout<<"4. Cerrar sesión"<<endl;

            cin>>subOpcion;

            if(subOpcion == 1){
                cout<<"Selecciona una opción<<"<<endl;
                cout<<"1. Mostrar productos"<<endl;
                cout<<"2. Agregar producto al carrito"<<endl;
                cin>>optionProducto;

                if(optionProducto == 1){
                    
                }else if(optionProducto == 2){
                    //Lógica para agregar producto al carrito 
                }

            }else if(subOpcion == 2){
                cout<<"Sesión cerrada exitosamente."<<endl;
            }


        }else if(opcion == 2){
            do{
                cout<<"Por favor, ingrese los siguientes datos"<<endl;
                cout<<"Email: ";
                cin>>email;
                cout<<"Contraseña: ";
                cin>>contrasena;
                cout<<"Teléfono: ";
                cin>>telefono;
                respuesta = Amazon.registrarse(email, contrasena, telefono);
            }while(respuesta == false);
                cout<<"Por favor, complete la información: "<<endl; //Pide completar información para crear cliente
                cout<<"Nombre: ";
                cin>>nombre;
                cout<<"Apellido: ";
                cin>>apellido;
                cout<<"Dirección: ";
                cin>>direccion;
                cout<<"Método de pago: ";
                cin>>metodoPago;
                Amazon.registrarCliente(nombre, apellido, direccion, metodoPago);

            opcion = 1; //Después de registrarse, redirige a iniciar sesión
        }
        else if(opcion == 0){
            cout<<"Gracias por visitar "<<Amazon.getNombre()<<". ¡Hasta luego!"<<endl;
        }
        else{
            cout<<"Opcion invalida. Por favor intente de nuevo."<<endl;
        }
    }while(opcion != 0);

    return 0;
}