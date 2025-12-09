# 📘 Proyecto en C++ — Organización, Estilo y Convenciones

**Descripción breve**  
Proyecto en C++ basado en Programación Orientada a Objetos (POO). El código se organiza en archivos de cabecera (.h) y fuente (.cpp) siguiendo buenas prácticas de estilo, revisión y control de versiones.


## Acuerdos del equipo

**Objetivo:** mantener un repositorio claro, legible y con historial coherente para facilitar el trabajo en equipo.

- Revisión por el coordinador antes de merge a la rama principal.
- Cada cambio significativo debe acompañarse de pruebas o verificación local.
- Comunicación clara en las issues y pull requests (PRs).

---

## Roles

- **Coordinador**
  - Supervisar avances.
  - Asignar responsabilidades.
  - Revisar código antes de integración.
- **Responsables por clase**
  - Diseñar, implementar y mantener la clase asignada.
  - Documentar decisiones de diseño importantes en la PR.

---

## Responsables por clase

- Cada clase tendrá un integrante asignado para:
  - **Diseño** (interfaz y relaciones).
  - **Implementación** (.h y .cpp).
  - **Mantenimiento** y corrección de errores.

---

## Estándar de Estilo del Código

- **Clases:** PascalCase  
  Ej.: `Producto`, `Cliente`, `CategoriaProducto`.

- **Métodos y funciones:** camelCase (inician con minúscula)  
  Ej.: `calcularPrecio()`, `mostrarInfo()`, `actualizarStock()`.

- **Atributos privados:** camelCase  
  Ej.: `id`, `precioUnitario`, `nombreProducto`.

- **Archivos:** mismo nombre que la clase  
  Ej.: `Producto.h` y `Producto.cpp`.

- **Indentación:** 4 espacios (no tabs) — consistente en todo el repositorio.

- **Comentarios:** claros y útiles. Preferir comentarios que expliquen el "porqué", no el "qué" trivial.

---

## Validaciones antes de subir cambios

Antes de realizar un `git push`:

- **Compilar** y verificar que no haya warnings importantes.
- **Ejecutar pruebas locales** si las hay.
- **Verificar** que los cambios no rompan funcionalidades existentes.
- **Realizar code review** con el coordinador (o asignado).
- Acompañar cambios grandes con ejemplos de uso o pruebas.

---

## Estándar de Commits — Conventional Commits

Se usará Conventional Commits para mantener un historial claro.

- **Formato general:** `tipo(alcance): descripción breve`  
- **Documentación:** https://www.conventionalcommits.org/en/v1.0.0/

**Ejemplos:**
- `feat(producto): agregar método calcularTotal`
- `fix(cliente): corregir validación de edad`
- `docs: actualizar README con convenciones`

**Tipos comunes:**
- `feat` — nueva funcionalidad  
- `fix` — corrección de errores  
- `docs` — documentación  
- `style` — formato/estilo (sin cambios funcionales)  
- `refactor` — reescritura sin cambiar comportamiento  
- `test` — pruebas  
- `chore` — tareas menores

**Ejemplos reales:**
- `feat(cliente): implementar cálculo de puntos`
- `fix(producto): corregir precio negativo`
- `style: estandarizar llaves en Cliente.cpp`

---

## Cómo compilar

Este repositorio incluye un `Makefile` en la raíz. Para compilar:

```sh
make
```

- El ejecutable resultante es `main` (según `Makefile`).
- Para limpiar binarios:
```sh
make clean
```

---

## Estructura básica del proyecto

Proyecto/
│
├── src/
│   ├── main.cpp
│   ├── Producto.cpp
│   └── Cliente.cpp
│   └── ...
│
├── include/
│   ├── Producto.h
│   └── Cliente.h
│   └── ...
│
└── README.md

---

## Checklist rápido antes de PR
- [ ] Compila sin errores.
- [ ] Pruebas relevantes pasadas.
- [ ] Convencional commit correcto.
- [ ] PR con descripción y referencia a la issue (si aplica).
- [ ] Asignado revisión por el coordinador.

---

## Recursos y archivos importantes

- Archivo principal: `main.cpp`  
- Makefile: `Makefile`  
- README: `README.md` (este documento)  
- Notas del repositorio: `Readme.txt`

---

Gracias por mantener el proyecto ordenado y documentado. Siguiendo estas pautas el equipo trabajará más eficientemente y evitará conflictos recurrentes.