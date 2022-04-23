#include <iostream>
#include <stdlib.h>
#include <mysql.h>

using namespace std;

void menu();
void menuRegistro();
void menuActualizar();
void menuBorrar();
void menuConsultar();

char serverdb[] = "localhost";
char userdb[] = "umg";
char passworddb[] = "Umg$2019";
char database[] = "colegio";

int main() {
	char opcion;
	MYSQL * connection;
	connection = mysql_init(0);
	if (connection){
		cout<<"La biblioteca Mysql se ha iniciado correctamente"<<endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection){
			
			cout<<"Conexion exitosa a la base de datos"<<endl;
			
			do{
		menu();
		cin>>opcion;
		
		switch(opcion){
			case '1':
				menuRegistro();
				break;
				
			case '2':
				menuActualizar();
				break;
				
			case '3':
				menuBorrar();
				break;
				
			case '4':
				menuConsultar();
				break;
				
			case '5':
				cout<<"\nFin del programa"<<endl;
				system("pause");
				break;
				
			default:
				cout<<"\nNumero de opcion no valido"<<endl;
				break;
		}
		
	}while (opcion != '5');
		}
		else{
			cout<<"No se pudo conectar a la base de datos: "<<mysql_error(connection)<<endl;
		}
		
	}
	else{
		
		cout<<"No es posible iniciar la biblioteca de Mysql"<<endl;
	}
	
	
	
	return 0;
}

void menu(){
	
	cout<<"\n\t***Ingrese el numero de opcion***"<<endl;
	cout<<"\n\t***1. Insertar registro***"<<endl;
	cout<<"\t***2. Actualizar registro***"<<endl;
	cout<<"\t***3. Borrar registro***"<<endl;
	cout<<"\t***4. Consultar/buscar registro***"<<endl;
	cout<<"\t***5. Sair del programa**"<<endl;
}

void menuRegistro(){
	char opcion;
	MYSQL * connection;
	string claveAlumno;
	string claveBimestre;
	string nota;
	string invalid;
	string nombreAlumno;
	string correoAlumno;
	string claveGrado;
	string nombreGrado;
	string seccion;
	string sql;
	int result;
	const char* query;
	connection = mysql_init(0);
	if (connection){
		cout<<"La biblioteca Mysql se ha iniciado correctamente"<<endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection){
			
			cout<<"Conexion exitosa a la base de datos"<<endl;
	
	do{
		cout<<"\n\t***Ingrese el numero de opcion***"<<endl;
		cout<<"\n\t***1. Agregar alumno***"<<endl;
		cout<<"\t***2. Agregar grado***"<<endl;
		cout<<"\t***3. Agregar nota***"<<endl;
		cout<<"\t***4. Regresar al menu principal**"<<endl;
	
	cin>>opcion;
	
		switch(opcion){
			case '1':
				cout<<"";
				getline(cin, invalid);
				cout<<"Ingrese el nombre del alumno: ";
				getline(cin, nombreAlumno);
				cout<<"Ingrese el correo electronico: ";
				getline(cin, correoAlumno);
				cout<<"Ingrese le codigo del grado: ";
				getline(cin, claveGrado);
				sql = "INSERT INTO alumno(nombre_alumno, correo_alumno, codigo_grado) VALUES ('"+nombreAlumno+"','"+correoAlumno+"', '"+claveGrado+"')" ;
				query = sql.c_str();
				result = mysql_query(connection, query);
				if (result == 0){
					cout<<"Registro guardado";
				}
				else{
					cout<<"No se agrego ningun registro"<<mysql_error(connection)<<endl;
				}
				break;
			
			case '2':
				cout<<"";
				getline(cin, invalid);
				cout<<"Ingrese el nombre del grado: ";
				getline(cin, nombreGrado);
				cout<<"Ingrese la seccion: ";
				getline(cin, seccion);
				sql = "INSERT INTO grado(nombre_grado, seccion) VALUES ('"+nombreGrado+"', '"+seccion+"')";
				query = sql.c_str();
				result = mysql_query(connection, query);
				if (result == 0){
					cout<<"Registro guardado";
				}
				else{
					cout<<"No se agrego ningun registro"<<mysql_error(connection)<<endl;
				}
				break;
			
			case '3':
				cout<<"";
				getline(cin, invalid);
				cout<<"Ingrese la clave del alumno: ";
				getline(cin, claveAlumno);
				cout<<"Ingrese la clave del bimestre: ";
				getline(cin, claveBimestre);
				cout<<"Ingresar la nota: ";
				getline(cin, nota);
				sql = "INSERT INTO notas(clave_alumno, clave_bimestre, nota) VALUES ('"+claveAlumno+"', '"+claveBimestre+"', '"+nota+"')";
				query = sql.c_str();
				result = mysql_query(connection, query);
				if (result == 0){
					cout<<"Registro guardado";
				}
				else{
					cout<<"No se agrego ningun registro"<<mysql_error(connection)<<endl;
				}
				break;
				
			case '4':
				system("CLS");
				break;
			
			default:
				cout<<"Opcion invalida"<<endl;
				break;
		}
	
	}while(opcion != '4' );
		}
		else{
			cout<<"No se pudo conectar a la base de datos: "<<mysql_error(connection)<<endl;
		}
		
	}
	else{
		
		cout<<"No es posible iniciar la biblioteca de Mysql"<<endl;
	}
}

void menuActualizar(){
	
	char opcion;
	MYSQL* connection;
	long claveAlumno;
	string clave;
	string invalid;
	string nombreAlumno;
	string correoAlumno;
	string nombreGrado;
	string seccion;
	string sql;
	int result;
	MYSQL_ROW row;
	MYSQL_RES* data;
	const char* query;
	connection = mysql_init(0);
	if (connection){
		cout<<"La biblioteca Mysql se ha iniciado correctamente"<<endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection){
			
			cout<<"Conexion exitosa a la base de datos"<<endl;
	
	
	do{
		
		cout<<"\n\t***Ingrese el numero de opcion***"<<endl;
		cout<<"\n\t***1. Modificar los datos de un alumno***"<<endl;
		cout<<"\t***2. Modificar los datos de un grado***"<<endl;
		cout<<"\t***3. Regresar al menu principal**"<<endl;
		
		cin>>opcion;
		
		switch(opcion){
			case '1':
				cout<<"";
				getline(cin, invalid);
				cout<<"Ingrese el No. carne: ";
				getline(cin, clave);
				cout<<"Ingrese el nombre del alumno: ";
				getline(cin, nombreAlumno);
				cout<<"Ingrese el correo del alumno: ";
				getline(cin, correoAlumno);
				sql = "UPDATE alumno SET nombre_alumno='"+nombreAlumno+"', correo_alumno='"+correoAlumno+"' WHERE clave_alumno='"+clave+"'";
				query = sql.c_str();
				result = mysql_query(connection, query);
				if (result == 0){
					cout<<"Actualizacion exitosa"<<endl;
				}
				else{
					cout<<"Actualizacion sin exito"<<endl;
				}
				break;
				
			case '2':
				cout<<"";
				getline(cin, invalid);
				cout<<"Ingrese el codigo del grado: ";
				getline(cin, clave);
				cout<<"Ingrese el nuevo nombre del grado: ";
				getline(cin, nombreGrado);
				cout<<"Ingrese la nueva seccion: ";
				getline(cin, seccion);
				sql = "UPDATE grado SET nombre_grado='"+nombreGrado+"', seccion='"+seccion+"' WHERE codigo_grado='"+clave+"'";
				query = sql.c_str();
				result = mysql_query(connection, query);
				if (result == 0){
					cout<<"Actualizacion exitosa"<<endl;
				}
				else{
					cout<<"Actualizacion sin exito"<<endl;
				}
				break;
				break;
				
			case '3':
				system("CLS");
				break;
				
			default:
				cout<<"Opcion invalida"<<endl;
				break;
		}
		
	}while(opcion != '3');
		}
		else{
			cout<<"No se pudo conectar a la base de datos: "<<mysql_error(connection)<<endl;
		}
		
	}
	else{
		
		cout<<"No es posible iniciar la biblioteca de Mysql"<<endl;
	}
}

void menuBorrar(){
	char opcion;
	MYSQL* connection;
	long claveAlumno;
	string clave;
	string invalid;
	string nombreAlumno;
	string correoAlumno;
	string nombreGrado;
	string seccion;
	string sql;
	int result;
	MYSQL_ROW row;
	MYSQL_RES* data;
	const char* query;
	connection = mysql_init(0);
	if (connection){
		cout<<"La biblioteca Mysql se ha iniciado correctamente"<<endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection){
			
			cout<<"Conexion exitosa a la base de datos"<<endl;
	
	do{
		cout<<"\n\t***Ingrese el numero de opcion***"<<endl;
		cout<<"\n\t***1. Borrar un alumno***"<<endl;
		cout<<"\t***2. Borrar un grado***"<<endl;
		cout<<"\t***3. Sair del programa**"<<endl;
		
		cin>>opcion;
		
		switch(opcion){
			case '1':
				cout<<"Ingrese el No. carne: ";
				cin>>clave;
				sql = "DELETE FROM alumno WHERE clave_alumno='"+clave+"'";
				query = sql.c_str();
				result = mysql_query(connection, query);
				if (result == 0){
					cout<<"Eliminado exitosamente"<<endl;
				}
				else{
					cout<<"No se elimino el elemento"<<endl;
				}
				break;
				
			case '2':
				cout<<"Ingrese el codigo del grado: ";
				cin>>clave;
				sql = "DELETE FROM grado WHERE codigo_grado='"+clave+"'";
				query = sql.c_str();
				result = mysql_query(connection, query);
				if (result == 0){
					cout<<"Eliminado exitosamente"<<endl;
				}
				else{
					cout<<"No se elimino el elemento"<<endl;
				}
				break;
				
			case '3':
				break;
				
			default:
				cout<<"Opcion invalida"<<endl;
				break;
		}
		
	}while(opcion != '3');
		}
		else{
			cout<<"No se pudo conectar a la base de datos: "<<mysql_error(connection)<<endl;
		}
		
	}
	else{
		
		cout<<"No es posible iniciar la biblioteca de Mysql"<<endl;
	}
}

void menuConsultar(){
	
	char opcion;
	MYSQL* connection;
	long claveAlumno;
	string clave;
	string invalid;
	string nombreAlumno;
	string correoAlumno;
	string nombreGrado;
	string seccion;
	string sql;
	int result;
	MYSQL_ROW row;
	MYSQL_RES* data;
	const char* query;
	connection = mysql_init(0);
	if (connection){
		cout<<"La biblioteca Mysql se ha iniciado correctamente"<<endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection){
			
			cout<<"Conexion exitosa a la base de datos"<<endl;
	
	do{
		cout<<"\n\t***Ingrese el numero de opcion***"<<endl;
		cout<<"\n\t***1. Buscar un alumno***"<<endl;
		cout<<"\t***2. Buscar un grado***"<<endl;
		cout<<"\t***3. Notas por alumno"<<endl;
		cout<<"\t***4. Consultar promedio del alumno"<<endl;
		cout<<"\t***5. Listar los alumnos de un grado por seccion***"<<endl;
		cout<<"\t***6. Todos los alumno"<<endl;
		cout<<"\t***7. Todos los bimestres"<<endl;
		cout<<"\t***8. Volver al menu principal**"<<endl;
		
		cin>>opcion;
		
		switch(opcion){
			case '1':
				cout<<"Ingrese el No. carne: ";
				cin>>clave;
				sql = "SELECT * FROM alumno where clave_alumno='"+ clave +"'";
				query = sql.c_str();
				result = mysql_query(connection, query);
				if (result == 0){
					cout<<"Busqueda exitosa"<<endl;
					data = mysql_store_result(connection);
					int countColumns = mysql_num_fields(data);
					while(row = mysql_fetch_row(data)){
						for(int i = 0; i < countColumns; i++ ){
							cout<<row[i]<<"\t";
						}
						cout<<endl;
					}
				}
				else{
					cout<<"Busqueda sin exito"<<endl;
				}
				cout<<"\n";
				system("pause");
				system("CLS");
				break;
				
			case '2':
				cout<<"Ingrese el Id del grado: ";
				cin>>clave;
				sql = "SELECT * FROM grado where codigo_grado='"+ clave +"'";
				query = sql.c_str();
				result = mysql_query(connection, query);
				if (result == 0){
					cout<<"Busqueda exitosa"<<endl;
					data = mysql_store_result(connection);
					int countColumns = mysql_num_fields(data);
					while(row = mysql_fetch_row(data)){
						for(int i = 0; i < countColumns; i++ ){
							cout<<row[i]<<"\t";
						}
						cout<<endl;
					}
				}
				else{
					cout<<"Busqueda sin exito"<<endl;
				}
				cout<<"\n";
				system("pause");
				system("CLS");
					break;
					
			case '3':
				cout<<"Ingrese el No. carne: ";
				cin>>clave;
				sql = "SELECT * FROM notas where clave_alumno='"+ clave +"'";
				query = sql.c_str();
				result = mysql_query(connection, query);
				if (result == 0){
					cout<<"Busqueda exitosa"<<endl;
					data = mysql_store_result(connection);
					int countColumns = mysql_num_fields(data);
					while(row = mysql_fetch_row(data)){
						for(int i = 0; i < countColumns; i++ ){
							cout<<row[i]<<"\t";
						}
						cout<<endl;
					}
				}
				else{
					cout<<"Busqueda sin exito"<<endl;
				}
				break;
				
			case '4':
				cout<<"Ingrese el No. carne: ";
				cin>>clave;
				sql = "SELECT AVG(nota) AS MEDIA FROM notas where clave_alumno='"+ clave +"'";
				query = sql.c_str();
				result = mysql_query(connection, query);
				if (result == 0){
					cout<<"Busqueda exitosa"<<endl;
					data = mysql_store_result(connection);
					int countColumns = mysql_num_fields(data);
					while(row = mysql_fetch_row(data)){
						for(int i = 0; i < countColumns; i++ ){
							cout<<"El promedio del alumno con el carnet No. "+clave+" es de: "<<row[i]<<"\t";
						}
						cout<<endl;
					}
				}
				else{
					cout<<"Busqueda sin exito"<<endl;
				}
				cout<<"\n";
				system("pause");
				system("CLS");
				break;
				
			case '5':
				cout<<"Ingrese la seccion: ";
				cin>>seccion;
				sql = "SELECT * FROM grado where seccion='"+seccion+"'";
				query = sql.c_str();
				result = mysql_query(connection, query);
				if (result == 0){
					cout<<"Busqueda exitosa"<<endl;
					data = mysql_store_result(connection);
					int countColumns = mysql_num_fields(data);
					while(row = mysql_fetch_row(data)){
						for(int i = 0; i < countColumns; i++ ){
							cout<<row[i]<<"\t";
						}
						cout<<endl;
					}
				}
				else{
					cout<<"Busqueda sin exito"<<endl;
				}
				cout<<"\n";
				system("pause");
				system("CLS");
				
				break;
				
			case '6':
				sql = "SELECT * FROM alumno";
				query = sql.c_str();
				result = mysql_query(connection, query);
				if (result == 0){
					cout<<"Busqueda exitosa"<<endl;
					data = mysql_store_result(connection);
					int countColumns = mysql_num_fields(data);
					while(row = mysql_fetch_row(data)){
						for(int i = 0; i < countColumns; i++ ){
							cout<<row[i]<<"\t";
						}
						cout<<endl;
					}
				}
				else{
					cout<<"Busqueda sin exito"<<endl;
				}
				cout<<"\n";
				system("pause");
				system("CLS");
				break;
				
			case '7':
				sql = "SELECT * FROM bimestre";
				query = sql.c_str();
				result = mysql_query(connection, query);
				if (result == 0){
					cout<<"Busqueda exitosa"<<endl;
					data = mysql_store_result(connection);
					int countColumns = mysql_num_fields(data);
					while(row = mysql_fetch_row(data)){
						for(int i = 0; i < countColumns; i++ ){
							cout<<row[i]<<"\t";
						}
						cout<<endl;
					}
				}
				else{
					cout<<"Busqueda sin exito"<<endl;
				}
				cout<<"\n";
				system("pause");
				system("CLS");
				break;
				
			case '8':
				break;
				
			default:
				cout<<"Opcion invalida"<<endl;
				break;
		}
	}while(opcion != '8');
		}
		else{
			cout<<"No se pudo conectar a la base de datos: "<<mysql_error(connection)<<endl;
		}
		
	}
	else{
		
		cout<<"No es posible iniciar la biblioteca de Mysql"<<endl;
	}
}
