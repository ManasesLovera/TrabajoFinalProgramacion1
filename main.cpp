#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Client {
    private:
        string ID;
        string name;
        int balance;
    public:
        Client(string ID, string Name, int Balance){
            this->ID = ID;
            this->name = Name;
            this->balance = balance;
        }
        //Getters
        string getID(){
        return this->ID;
        }
        string getName(){
            return this->name;
        }
        int getBalance(){
            return this->balance;
        }
};
class Call {
    public:
        string phone_number;
        string typeof_call;
        string location = " ";
        // local o interprovincial
        // local : $0.15
        // region ocidental : $0.20
        // region central : $0.25         PRECIOS POR MINUTO
        // region oriental : $0.30

        // IMPORTANTE = despues de las 18 horas las llamadas locales cuestan $0.5 y las interprovinciales $0.10
        string begin_time;
        int minutes = 0;
        string name;
        short cost;
        Call(string phone_number, string typeof_call, string location, string begin_time, int minutes, string name, short cost){
            this->phone_number = phone_number;
            this->typeof_call = typeof_call;
            this->location = location;
            this->begin_time = begin_time;
            this->minutes = minutes;
            this->name = name;
            this->cost = cost;
        }
};
class Centralita {
    public:
        vector<Client> clients;    //Esta es la centralita, contiene clientes y llamadas
        vector<Call> calls;
};

Centralita centralita;

void add_users(Centralita& central,vector<Client>& clients){

    string ID;
    string name;
    int balance;
    int amount_users;
    cout<< "\nInserte la cantidad de usuarios: "; // Pide una cantidad de usuarios a agregar
    cin >> amount_users; 

    for(int i = 0; i < amount_users; i++){
        cout << "\nUsuario "<<clients.size()+1<<": "<<endl;
        cout << "Identificador: ";
        cin >> ID;                                              // Agrega los usuarios
        cout << "Nombre: ";
        cin >> name;
        cout << "Saldo: ";
        cin >> balance;
        Client client(ID,name,balance);
        central.clients.push_back(client);

    }
}

void add_calls(){
    int amount_calls, minutes,  balance, finalbal, option;
	string phone_number, location, typeof_call, name, begin_time;
	float local=0.15, occidental=0.20, central=0.25, oriental=0.30, cost, time;
	
	cout << "\nInserte la hora: (formato 24 horas)";
	cin >> time;
    cout << "\nInserte la cantidad de llamadas: ";
    cin >> amount_calls;                                // Pide la cantidad de llamadas a agregar
  
    if (time>18){
    	 local=0.5;
		 occidental=0.10;
		 central=0.10;
		 oriental=0.10;	  
		}

    for(int j = 0; j < amount_calls; j++){
        cout << "\nLlamada "<<centralita.calls.size()+j+1<<": "<<endl;
        cout << "\nNúmero de telefono: ";                 // Agrega las llamadas
        cin >> phone_number;
        cout << "Usuario: ";
        cin >> name;
		cout << "Tipo de llamada (local/interprovincial): ";
        cin >> typeof_call;
        cout << "Digite el tiempo de inicio: ";
        cin >> begin_time;
        cout << "Digite duracion de la llamada (minutos): ";
        cin >> minutes;
        cout << "Digite su saldo actual: $";
        cin >> balance;  
				
        if(typeof_call == "interprovincial"){ 
        cout << "Region geografica [1]Region occidental [2]region central [3]Region oriental " << endl;
        cin >> option;

            if(option==1){
                cost = minutes*occidental;
                finalbal= balance-cost;
            }

            if(option==2){
                cost = minutes*central;
                finalbal= balance-cost;
            }

            if(option==3){
                cost = minutes*oriental;
                finalbal= balance-cost;
            } 
            
            if(cost>balance){
                cout<<"Su saldo es insuficiente para relizar la llamada"<<endl;
            }
            else{
                cout<< "Duracion llamada: " <<minutes<< " minutos";
                cout<< "\nCosto llamada: $" <<cost<<endl;
                cout<< "\nSu llamada ha sido guardada"<<endl;
                cout << "\nSu nuevo saldo es de: $";
                cout << finalbal<<endl;; 
            }
        }
        Call cal(phone_number,typeof_call,location,begin_time,minutes,name,cost);
        centralita.calls.push_back(cal);
    }
}

void show_users(){
    for(int i = 0; i < centralita.clients.size(); i++){
        cout << "\nUsuarios:"<<endl;
        cout<< "\nUsuario: " <<centralita.clients[i].getName()<<endl;
        cout<<"Identificador: "<<centralita.clients[i].getID()<<endl;
        cout<<"Saldo: "<<centralita.clients[i].getBalance()<<endl;
	}
}

void show_calls(){  //Registro de Llamada (mostrar llamadas)
    
    int i = 0;
    cout<<"\n Mostrar  Llamadas:  "<<endl;
    for (Call c : centralita.calls){
        cout << "\nLlamada "<<i+1<<":"<<endl;
        cout << "Numero de telefono:"<<c.phone_number<<endl;
        cout << "Tipo de llamada: "<<c.typeof_call<<endl;
        cout << "Tipo de llamada: "<<c.location<<endl;
        cout << "Tipo de llamada: "<<c.begin_time<<endl;
        cout << "Tipo de llamada: "<<c.minutes<<endl;
        cout << "Tipo de llamada: "<<c.name<<endl;
        cout << "Tipo de llamada: "<<c.cost<<endl;  
        i++;   
    }    
}

void show_last_registers(vector<Call>& calls){
    cout << "\nEscribe la cantidad de los ultimos registros de llamada que quiere ver: "<<endl;
    int amount;
    cin >> amount;
    int p = calls.size()-1; // Posicion del vector ubicado desde el ultimo elemento
    for(int i = 0; i < amount; i++){
        cout << "Numero de telefono: "<<calls[p].phone_number<<endl;
        cout << "Tipo de llamada: "<<calls[p].typeof_call<<endl;
        cout << "Ubicacion: "<<calls[p].location<<endl;
        cout << "Usuario: "<<calls[p].name<<endl;
        cout << "Tiempo de inicio: "<<calls[p].begin_time<<endl;
        cout << "Minutos: "<<calls[p].minutes<<endl;
        cout << "Precio: "<<calls[p].cost<<endl;
        p--;
    }

}

void show_calls_by_location(vector<Call>& calls){
    string location;
    cout << "\nIngrese la ubicacion que quiere encontrar: ";
    cin >> location;
    for (Call call : calls){
        if (call.location == location){
            cout << "\nNombre: "<<call.name<<endl;
            cout << "Numero de telefono: "<<call.phone_number<<endl;
            cout << "Ubicacion: "<<call.location<<endl;
            cout << "Costo llamada: "<<call.cost<<endl;
            cout << "Inicio de llamada: "<<call.begin_time<<endl; 
        }
    }
}

void exit(){
    system("clear");
    cout << "Gracias por usar la app!"<<endl;
}

void Menu(){
    cout << "\n"<<endl;
    cout << "Menu:\n"<<endl;
    cout << "0. Salir" <<endl;
    cout << "1. Agregar usuarios" <<endl;
    cout << "2. Agregar llamadas" <<endl;
    cout << "3. Mostrar usuarios" <<endl;
    cout << "4. Mostrar llamadas" <<endl;
    cout << "5. Mostrar ultimos registros" <<endl;
    cout << "6. Mostrar llamadas por provincia" <<endl;
    int option;
    cin >> option;

    switch(option){
        case 1:
            add_users(centralita,centralita.clients);
            Menu();
            break;
        case 2:
            add_calls();
            Menu();
            break;
        case 3:
            show_users();
            Menu();
            break;
        case 4:
            show_calls();
            Menu();
            break;
        case 5:
            show_last_registers(centralita.calls);
            Menu();
            break;
        case 6:
            show_calls_by_location(centralita.calls);
            Menu();
            break;
        case 0:
            exit();
            break;
    }
}

int main(){

    Menu();

    return 0;
};