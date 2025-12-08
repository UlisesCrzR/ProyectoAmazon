#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Usuario{
    private:
        int idUsuario;
        string email;
        string contrasena;
        string telefono;

        static int contadorID;
    public:
        Usuario();
        Usuario(string _email, string _contrasena, string _telefono);

        static vector<Usuario> cargarCatalogo();
        
        int getIdUsuario();
        string getEmail();
        string getContrasena();
        string getTelefono();

        void setIdUsuario(int _idUsuario);
        void setEmail(string _email);
        void setContrasena(string _contrasena);
        void setTelefono(string _telefono);
};

#endif // USUARIO_H