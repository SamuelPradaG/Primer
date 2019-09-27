//Fuentes:
// 1. https://www.youtube.com/watch?v=izSFtOKiU60
// 2. https://www.youtube.com/watch?v=sviXvTOHr8A
// 3. https://www.youtube.com/watch?v=ouu7lIBTUvw

#include <iostream>
using namespace std;

//Creamos la primera clase base en donde almacenaremos los datos básicos de una persona (nombre, edad, apellido)
class persona
{
    //Encapsulamos los atributos
private:
    string nombre;
    string apellido;
    int edad;
    //En la "pública" haremos los métodos getter´s y setter´s de los atributos anteriormente definidos
public:
    //Método para fijar el nombre
    void setNombre(string sNombre)
    {
        nombre = sNombre;
    }
    //Método para fijar apellido
    void setApellido(string sApellido)
    {
        apellido = sApellido;
    }
    //Método para fijar la edad
    void setEdad(int sEdad)
    {
        edad = sEdad;
    }
    //Método para obtener el nombre
    string getNombre()
    {
        return nombre;
    }
    //Método para obtener el apellido
    string getApellido()
    {
        return apellido;
    }
    //Método para obtener la edad
    int getEdad()
    {
        return edad;
    }
    //El método personas muestra en pantalla unos mensajes con la información que se almacenan en las variables o atributos.
    void Personas()
    {
        cout << "Mi nombre es: " << nombre << endl;
        cout << "Mi apellido es: " << apellido << endl;
        cout << "Mi edad es: " << edad << endl;
    }
};
/*Creamos la segunda clase base en donde estarán los datos generales de un 
    estudiante como lo es el código, el semestre que está cursandoactualmente, 
    la universidad o centro de estudios en el que está y la carrera que está cursando.
    */
class estudiante
{
    //Encapsulamos los parametros de la clase.
private:
    int code;
    int semestre;
    string univ;
    string carrera;
    //Como hicimos en la clase anterior creamos los métodos setter´s y getter´s de los parametros.
public:
    //Método para fijar el código del estudiante
    void setCode(int sCode)
    {
        code = sCode;
    }
    //Método para fijar el semestre que está cursando el estudiante
    void setSemestre(int sSemestre)
    {
        semestre = sSemestre;
    }
    //Método para fijar el nombre de la universidad en la que está el estudiante
    void setUniv(string sUniv)
    {
        univ = sUniv;
    }
    //Método para fijar la carrera del estudiante
    void setCarrera(string sCarrera)
    {
        carrera = sCarrera;
    }
    //Método para obtener el código del estudiante
    int getCode()
    {
        return code;
    }
    //Método para obtener el semestre en el que está el estudiante
    int getSemestre()
    {
        return semestre;
    }
    //Método para obtener el nombre de la universidad en la que estudia el alumno
    string getUniv()
    {
        return univ;
    }
    //Método para obtener la carrera que cursa el estudiante
    string getCarrera()
    {
        return carrera;
    }
    //Método que muestra en pantalla toda la información almacenada en los parametros de la clase
    void Estudiantes()
    {
        cout << "Mi código es: " << code << endl;
        cout << "Voy en el semestre: " << semestre << endl;
        cout << "Estudio en: " << univ << endl;
        cout << "Estudio: " << carrera << endl;
    }
};
/*En la siguiente linea se aprecia la forma en la que se ejecuta la herencia en c++, al crear una nueva clase "empleado"
        le decimos a la clase nueva que debe heredar los parámetros y métodos públicos tanto de la clase "persona" como de la
        clase "estudiante", pero de igual forma vemos que esta nueva clase cuenta con parametros y Métodos totalmente independientes a las 
        otras 2 clases anteriormente creadas.
        Tambien cabe resaltar que anteriormente decidimos encapsular los parametros de las clases como privadas, pero al hacer los Métodos
        getter´s y setter´s publicos, la clase nueva podrá tener acceso a estos.
*/
class empleado : public persona, public estudiante
{
private:
    //En esta nueva clase almacenaremos 2 datos muy basicos de cualquier trabajador como lo es el área en el que trabaja y tambien el
    //dinero que cobra por desempeñar esta labor.
    string area;
    int salario;

public:
    //Métodod que fija el area el la que trabaja la persona
    void setArea(string sArea)
    {
        area = sArea;
    }
    //Método que fija el monto economico que cobra la persona al desempesañr su labor
    void setSalario(int sSalario)
    {
        salario = sSalario;
    }
    //Método para obtener el area en el que trabaja la persona
    string getArea()
    {
        return area;
    }
    //Método para obtener el salario de la persona
    int getSalario()
    {
        return salario;
    }
    //Método que muestra en pantalla la totalidad de la informació que hemos venido guardando en las diferentes clases,
    //ya que dentro de este metodo estamos invocando los metodos creados en las clases anteriores por medio de la herencia
    void Empleados()
    {
        Personas();
        Estudiantes();
        cout << "Trabajo en el area de : " << area << endl;
        cout << "Gano: " << salario << " pesos " << endl;
    }
};
//Metodo main o principal desde el cual podremos crear los objetos pertenecientes a las clases.
int main()
{
    /*En el main del programa creamos un objeto llamado prim perteneciente a la clase empleado e inicializamos todas las variables
        o parametros que hemos venido creando a lo largo de todo el programa, gracias a los metodos getter´s y setter´s que se van herendando 
        entre lass diferentes clases, debemos tener en cuenta que la mayoría de metodos que usamos en la declaración en la parte de abajo 
        no se encuentran implementados en la clase empleado, ya que estos se encuentran en las diferetnes clases
        pero se pueden invocar desde la clase empleado gracias a la herencia. 
        */
    empleado prim;
    prim.setNombre("Samuel");
    prim.setApellido("García");
    prim.setEdad(17);
    prim.setCode(20191);
    prim.setUniv("Eafit");
    prim.setSemestre(2);
    prim.setCarrera("Ing. de Sistemas");
    prim.setArea("Informática");
    prim.setSalario(0);

    cout << "Información" << endl;
    //Si observamos de forma correcta el codigo en su totalidad caemos en cuenta de que el método Empleados nos dará toda la información
    //Almacenada ya que este  metodo llama o utiliza a los otros 2 (Estudiantes y Personas) que se encuentran en las otras clases,
    //de esta forma tenemos la posibilidad de veer toda la informacion almacenada en las 3 clases.
    prim.Empleados();

    return 0;
}
