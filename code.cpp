#include<bits/stdc++.h>
using namespace std;

int pid; // < - patient ID
int did; // < - Doctor ID


class Patient{
    public :
    string name;
    string gender;
    int age;
    int ID;
    string bloodgr;
    string problem;

    Patient(string n , int a , string g ,string gr ,string pro){
        ID = pid++;
        name = n ;
        age = a; 
        gender = g;
        bloodgr = gr;
        problem = pro;
    }
};

class Doctor{
    public :
    string name;
    string gender;
    int age;
    int ID;
    string expert;

    Doctor(string n , int a , string g , string exp){
        ID = did++;
        name = n ;
        age = a; 
        gender = g;
        expert = exp;
    }
};

class Appointments{
    public:
    int patientID;
    int doctorID;
    string Date;

    Appointments(int pID , int dID , string date){
        Date = date;
        patientID = pID;
        doctorID = dID;
    }
};

vector<Patient>allPatients;
vector<Doctor>allDoctors;
vector<Appointments>allAppointments;

bool isPatientPresent(int id){
    bool ans = false;
    for(int i=0; i < allPatients.size() ;i++){
        if(allPatients[i].ID == id) ans = true;
    }
    return ans;
}

bool isDoctortPresent(int id){
    bool ans = false;
    for(int i=0; i < allDoctors.size() ;i++){
        if(allDoctors[i].ID == id) ans = true;
    }
    return ans;
}

void addPaitient(){
    string n , g ,gr,prob;
    int a;
    cout<<"Add Patient Details : "<<endl;
    cout<<"Give me the Patient Name : ";
    cin>>n;
    cout<<"Give me the Patient Age : ";
    cin>>a;
    cout<<"Give me the Patient Gender : ";
    cin>>g;
    cout<<"Give me the Patient Blood group : ";
    cin>>gr;
    cout<<"Give me the Patient Problem : ";
    cin>>prob;


    Patient temp(n , a ,g ,gr, prob);
    allPatients.push_back(temp);
}

void addDoctor(){
    string n , g,exp;
    int a;
    cout<<"Doctor Details : "<<endl;
    cout<<"Give me the Doctor Name : ";
    cin>>n;
    cout<<"Give me the Doctor Age : ";
    cin>>a;
    cout<<"Give me the Doctor Gender : ";
    cin>>g;
    cout<<"Give me the Doctor Experties : ";
    cin>>exp;

    Doctor temp(n , a ,g , exp);
    allDoctors.push_back(temp);
}

void ScheduleAppointments(){
    int patientID;
    int doctorID;
    string Date;

    cout<<"Give me the Patient ID : ";
    cin>>patientID;
    cout<<"Give me the Doctor ID : ";
    cin>>doctorID;
    cout<<"Give me the Date (DD-MM-YYYY) : ";
    cin>>Date;

    if(isPatientPresent(patientID) == false){
        cout<<"Invalid Patient ID please recheck again..."<<endl;
        cout<<"\n\nAppointment Schedule Unsuccessful.."<<endl;
        return;
    }else if(isDoctortPresent(doctorID)){
        cout<<"Invalid Doctor ID please recheck again..."<<endl;
        cout<<"\n\nAppointment Schedule Unsuccessful.."<<endl;
        return;
    }
    Appointments temp(patientID , doctorID ,Date);
    allAppointments.push_back(temp);

}

void viewPaitient(){

    cout<<endl;
    for(int i=0; i < allPatients.size() ; i++){
        cout<<"Patient ID : "<<allPatients[i].ID<<" , Name : "<<allPatients[i].name<<" , Age  :"<<allPatients[i].age<< " , Blood Group : "<<allPatients[i].bloodgr<<" , problem : "<<allPatients[i].problem<<endl;
    }
    cout<<"\n\n\n";
}

void viewDoctor(){

    cout<<endl;
     for(int i=0; i < allDoctors.size() ; i++){
        cout<<"Doctor ID :"<<allDoctors[i].ID<<" , Doctor Name : "<<allDoctors[i].name<<" , Doctor Experties : "<<allDoctors[i].expert<<endl;
    }
    cout<<"\n\n\n";
}

void viewAppointments(){
    cout<<endl;
    for(int i=0; i < allAppointments.size() ; i++){
        cout<<"Patients ID : "<<allAppointments[i].patientID <<" has Appointment With Doctor ID : "<<allAppointments[i].doctorID<<" On Date : "<<allAppointments[i].Date<<endl;
    }
    cout<<"\n\n\n\n";
}

int main(){
    pid = 1;
    did = 1;

    int choice;

    do{
        cout<<"1. Add Patient"<<endl;
        cout<<"2. Add Doctor"<<endl;
        cout<<"3. Schedule Appointment"<<endl;
        cout<<"4. View Patients"<<endl;
        cout<<"5. View Doctors"<<endl;
        cout<<"6. View Appointments "<<endl;
        cout<<"0. Exit..."<<endl;

        cout<<"\nGive your Choice : ";
        cin>>choice;

        switch(choice){
            case 1 :
                addPaitient();
                break;
            case 2 :
                addDoctor();
                break;
            case 3 :
                ScheduleAppointments();
                break;
            case 4 :
                viewPaitient();
                break;
            case 5 :
                viewDoctor();
                break;
            case 6 :
                viewAppointments();
                break;
            default :
                cout<<"\nInvalid Choice !!."<<endl;
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"Thank You Visit Again.."<<endl;;
                cout<<endl;
                cout<<endl;
                cout<<endl;
        }

    }while( choice != 0);

    return 0;
}