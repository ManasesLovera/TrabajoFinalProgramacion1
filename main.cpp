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
        //void show_clients(){}
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
    int amount_calls;
    cout << "\nInserte la cantidad de llamadas: ";
    cin >> amount_calls;                                // Pide la cantidad de llamadas a agregar
    string phone_number, typeof_call, location,name;
    for(int j = 0; j < amount_calls; j++){
        cout << "\nLlamada "<<centralita.calls.size()+j<<": "<<endl;
        cout << "Numero de telefono: ";                 // Agrega las llamadas
        cin >> phone_number;
        cout << "Tipo de llamada (local/interprovincial): ";
        cin >> typeof_call;
        if(typeof_call == "interprovincial"){
            cout << "Region geografica (region occidental/region central/region oriental): ";
            cin >> location;
        }
        cout << "Usuario: ";
        cin >> name;
        Call cal;
        centralita.add_call(cal);
    }
}

void show_users(){
    cout << "\nUsuarios:"<<endl;
    for(int i = 0; i < centralita.clients.size(); i++){
        cout << centralita.clients[i].getID()<< ": "<<centralita.clients[i].getName()<<" - Saldo: "<<centralita.clients[i].getBalance()<<endl;
    }
}

void show_calls(){
    cout << "\nLlamadas:"<<endl;
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
            //add_calls();
            Menu();
            break;
        case 3:
            //show_users();
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
