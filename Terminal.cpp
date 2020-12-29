# include "Function.h"
# include "Base.h"
using namespace std;

Employee* Feed(){
    cout<<"ID: ";
    char id[15];
    cin>>id;
    string I_D;
    I_D = id;
    result R = searchh(I_D);
    if(R.empty()){
        cout<<"Name: ";
        string NAME;
        cin>>ws;
        getline(cin, NAME);
        cout<<"Contact: ";
        long long num;
        cin>>num;
        cout<<"Sex(Male, Female or Other): ";
        char gen[8];
        cin>>gen;
        cout<<"Date of Birth(dd:mm:yyyy): ";
        char dob[12];
        cin>>dob;
        cout<<"Salary: ";
        int sal =0;
        cin>>sal;
        cout<<"Address: ";
        string ADD;
        cin>>ws;
        getline(cin, ADD);
        string G_EN, D_OB;
        string N_UM = to_string(num);
        G_EN = gen;
        D_OB = dob;
        string S_AL = to_string(sal);
        Employee* emp = new Employee(I_D, NAME, N_UM, G_EN, D_OB, S_AL, ADD);
        return emp;
    }
    else{
        cout<<"----------Employee already exists.----------"<<endl;
        Employee* emp = NULL;
        return emp;
    }
}
void show(){
    result R = display();
    if(!R.empty()){
        cout<<"---------------E M P L O Y E E   D E T A I L S---------------"<<endl;
        for(result::const_iterator c = R.begin(); c != R.end(); ++c){
            cout<< "| ID: "<< c[0].as<string>() <<" |  ";
            cout<< "| Name: "<< c[1].as<string>() <<" |  ";
            cout<< "| Contact: "<< c[2].as<long long>() <<" |  ";
            cout<< "| Sex: "<< c[3].as<string>() <<" |  ";
            cout<< "| Date of Birth: "<< c[4].as<string>() <<" |  ";
            cout<< "| Salary: "<< c[5].as<float>() <<" |  ";
            cout<< "| Address: "<< c[6].as<string>() <<" |";
            cout<<endl<<endl;
            this_thread::sleep_for(sho);
        }
    }
    else
    cout<<"----------No records found----------"<<endl;
}
void find(){
    char id[15];
    cout<<"Employee ID: ";
    cin>>id;
    string ID;
    ID = id;
    result R = searchh(ID);
    cout<<"----------------------------------------"<<endl;
    if(!R.empty()){
        cout<<"Employee Details: "<<endl<<endl;
        for(result::const_iterator c = R.begin(); c != R.end(); ++c){
            cout<< "| ID: "<< c[0].as<string>() <<" |  ";
            cout<< "| Name: "<< c[1].as<string>() <<" |  ";
            cout<< "| Contact: "<< c[2].as<long long>() <<" |  ";
            cout<< "| Sex: "<< c[3].as<string>() <<" |  ";
            cout<< "| Date of Birth: "<< c[4].as<string>() <<" |  ";
            cout<< "| Salary: "<< c[5].as<float>() <<" |  ";
            cout<< "| Address: "<< c[6].as<string>() <<" |";
            cout<<endl<<endl;
        }
    }
    else
    cout<<"No such employee exists"<<endl;
    this_thread::sleep_for(ser);
}
void dele(){
    char id[15];
    cout<<"Employee ID: ";
    cin>>id;
    string ID;
    ID = id;
    result R = searchh(ID);
    if(R.empty()){
        cout<<"----------No such employee exists.----------"<<endl;
    }
    else{
        for(result::const_iterator c = R.begin(); c != R.end(); ++c){
            cout<<"ID: "<< c[0].as<string>() <<endl;
            cout<<"Name: "<< c[1].as<string>() <<endl;
            cout<<"Contact: "<< c[2].as<long long>() <<endl;
            cout<<"Sex: "<< c[3].as<string>() <<endl;
            cout<<"Date of Birth: "<< c[4].as<string>() <<endl;
            cout<<"Salary: "<< c[5].as<float>() <<endl;
            cout<<"Address: "<< c[6].as<string>() <<endl;
        }
        cout<<"Confirm deletion(y/n): ";
        char c;
        cin>>c;
        if(c == 'n')
        return;
        else{
            del(ID);
            cout<<"----------Deletion completed.----------"<<endl;
        }
    }
}
void alter(){
    cout<<"Employee ID: ";
    char id[15];
    cin>>id;
    string ID;
    ID = id;
    result R = searchh(ID);
    if(!R.empty()){
        string val[7];
        bool par[7];
        for(int i=0; i<7; i++)
        par[i] = 0;
        cout<<"Update ID? (y/n): ";
        char c = 'n';
        cin>>c;
        if(c == 'y'){
            par[0] = 1;
            cout<<"New ID: ";
            char id[15];
            cin>>id;
            val[0] = id;
        }
        cout<<"Update Name? (y/n): ";
        cin>>c;
        if(c == 'y'){
            par[1] = 1;
            cout<<"New Name: ";
            string name;
            cin>>ws;
            getline(cin, name);
            val[1] = name;
        }
        cout<<"Update contact? (y/n): ";
        cin>>c;
        if(c == 'y'){
            par[2] = 1;
            cout<<"New Contact: ";
            long long num;
            cin>>num;
            val[2] = to_string(num);
        }
        cout<<"Update Sex? (y/n): ";
        cin>>c;
        if(c == 'y'){
            par[3] = 1;
            cout<<"New Sex(Male, Female or Other): ";
            char gen[8];
            cin>>gen;
            val[3] = gen;
        }
        cout<<"Update Date of Birth? (y/n): ";
        cin>>c;
        if(c == 'y'){
            par[4] = 1;
            cout<<"New Date of Birth(dd:mm:yyyy): ";
            char dob[12];
            cin>>dob;
            val[4] = dob;
        }
        cout<<"Update Salary? (y/n): ";
        cin>>c;
        if(c == 'y'){
            par[5] = 1;
            cout<<"New Salary: ";
            int sal;
            cin>>sal;
            val[5] = to_string(sal);
        }
        cout<<"Update Address? (y/n): ";
        cin>>c;
        if(c == 'y'){
            par[6] = 1;
            cout<<"New Address: ";
            string add;
            cin>>ws;
            getline(cin, add);
            val[6] = add;
        }
        update(ID, val, par);
        cout<<"----------Record Updated----------"<<endl;
    }
    else cout<<"----------No such employee exists.----------"<<endl;
}
int main(){
    int t =0;
    create();
    do{
        cout<<"Enter "<<endl;
        cout<<"1 to feed an data."<<endl<<"2 to display list of employees."<<endl;
        cout<<"3 to search data."<<endl<<"4 to delete data."<<endl;
        cout<<"5 to update record."<<endl<<"6 to quit."<<endl;
        cout<<"Your choice: ";
        cin>>t;
        cout<<"----------------------------------------"<<endl;
        switch(t){
            case 1:
                {Employee* emp = Feed();
                if(emp){
                    upload(emp);
                    cout<<endl<<"Data Uploaded."<<endl;
                }
                cout<<"========================================"<<endl;
                break;}
            case 2:
                {show();
                cout<<"========================================"<<endl;
                break;}
            case 3:
                {find();
                cout<<"========================================"<<endl;
                break;}
            case 4:
                {dele();
                cout<<"========================================"<<endl;
                break;}
            case 5:
                {alter();
                cout<<"========================================"<<endl;
                break;}
            case 6:
                {cout<<"==========E X I T I N G=========="<<endl;
                break;}
            default:
                {cout<<"Enter valid choice."<<endl;
                break;}
        }
    }while(t != 6);
    return 0;
}