#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Client {
    private:
        short ID;
        string name;
        int balance;
    public:
        Client(short ID, string Name, int Balance){
            this->ID = ID;
            this->name = Name;
            this->balance = balance;
        }
        //Getters
        short getID(){
        return ID;
        }
        string getName(){
            return name;
        }
        int getBalance(){
            return balance;
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
};
class Centralita {
    public:
        vector<Client> clients;    //Esta es la centralita, contiene clientes y llamadas
        vector<Call> calls;
        //Setters
        void add_client(Client cl){
            this->clients.push_back(cl);
        }
        void add_call(Call ca){
            this->calls.push_back(ca);
        }
};

Centralita centralita;

void add_clients(Centralita,vector<Client>&);

//void show_last_registers();
//void show_calls_by_location();
void Menu();

int main(){

    Menu();

    return 0;
};

void add_users(Centralita& central,vector<Client>& clients){
    short ID;
    string name;
    int balance;
    int amount_users;
    cout<< "\nInserte la cantidad de usuarios: ";
    cin >> amount_users;                                      // Pide una cantidad de usuarios a agregar
    for(int i = 0; i < amount_users; i++){

        cout << "\nUsuario "<<clients.size()+1<<": "<<endl;
        cout << "Identificador: ";
        cin >> ID;                                              // Agrega los usuarios
        cout << "Nombre: ";
        cin >> name;
        cout << "Saldo: ";
        cin >> balance;
        Client client(ID,name,balance);
        central.add_client(client);
    }
}

void add_calls(){
    int amount_calls, minutes,  balance, finalbal, option;
	string phone_number, location, typeof_call, name;
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
        cout << "\nLlamada "<<centralita.calls.size()+j<<": "<<endl;
        cout << "\nNúmero de telefono: ";                 // Agrega las llamadas
        cin >> phone_number;
        cout << "Usuario: ";
        cin >> name;
		cout << "Tipo de llamada (local/interprovincial): ";
        cin >> typeof_call;
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

                Call cal;
                centralita.add_call(cal);
            }
        }
    }

}

void show_users(){
    for(int i = 0; i < centralita.clients.size(); i++){
        cout << "\nUsuarios:"<<endl;
        cout<< "Usuario: " <<centralita.clients[i].getName();
        cout<<"Identificador: "<<centralita.clients[i].getID();
        cout<<"Saldo: "<<centralita.clients[i].getBalance();
	}
}

void show_calls(){  //Registro de Llamada (mostrar llamadas)
    
    cout<<":\n Mostrar  Llamadas:  "<<endl;
    for (int i=0; i< centralita.calls.size(); i++){
        cout << "\nLlamada "<<i+1<<":"<<endl;
        cout << "Numero de telefono:"<<centralita.calls[i].phone_number<<endl;
        cout << "Tipo de llamada: "<<centralita.calls[i].typeof_call<<endl;
        cout << "Tipo de llamada: "<<centralita.calls[i].location<<endl;
        cout << "Tipo de llamada: "<<centralita.calls[i].begin_time<<endl;
        cout << "Tipo de llamada: "<<centralita.calls[i].minutes<<endl;
        cout << "Tipo de llamada: "<<centralita.calls[i].name<<endl;
        cout << "Tipo de llamada: "<<centralita.calls[i].cost<<endl;     
    }    
}

void show_last_registers(){
    cout << "Working in progress..."<<endl;
}

void show_calls_by_location(){
    cout<< "Calls on THAT place"<<endl;
}

void exit(){
    system("clear");
    cout << "Gracias por usar la app!"<<endl;
}

void Menu(){
    system("clear");
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
            //show_calls();
            Menu();
            break;
        case 5:
            //show_last_registers();
            Menu();
            break;
        case 6:
            //show_calls_by_location();
            Menu();
            break;
        case 0:
            exit();
            break;
    }
}
