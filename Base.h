#ifndef BASE_H
#define BASE_H
# include <pqxx/pqxx>
# include "Function.h"
using namespace std;
using namespace pqxx;
connection C("dbname = dvdrental user = postgres password = postgres hostaddr = 127.0.0.1 port = 5432");
void create(){
    work W(C);
    string quer;
    quer = "CREATE TABLE IF NOT EXISTS EMPLOYEES("\
    "ID CHAR(15) PRIMARY KEY NOT NULL,"\
    "NAME TEXT NOT NULL,"\
    "CONTACT BIGINT,"\
    "SEX CHAR(8),"\
    "DOB CHAR(12),"\
    "SALARY REAL,"\
    "ADDRESS TEXT);";
    W.exec(quer);
    W.commit();

}
void upload(Employee* emp){
    work W(C);
    string quer;
    quer = "INSERT INTO EMPLOYEES(ID,NAME,CONTACT,SEX,DOB,SALARY,ADDRESS)"\
    "VALUES('" + emp->id + "', '" + emp->name + "', " + emp->num + ", '" + emp->gen + "', '" + emp->dob + "', " + emp->sal + ", '" + emp->add + "');";
    W.exec(quer);
    W.commit();

}
result display(){
    nontransaction N(C);
    string quer;
    quer = "SELECT * FROM EMPLOYEES ORDER BY ID ASC;";
    result R(N.exec(quer));
    return R;
}
result searchh(string ID){
    nontransaction N(C);
    string quer = "SELECT * FROM EMPLOYEES WHERE ID = '" + ID + "' ;";
    result R(N.exec(quer));
    return R;
}
void del(string ID){
    work W(C);
    string quer;
    quer = "DELETE FROM EMPLOYEES WHERE ID = '" + ID + "' ;";
    W.exec(quer);
    W.commit();
}
void update(string id, string vals[], bool pars[]){
    if(pars[1]){
        work W(C);
        string quer;
        quer = "UPDATE EMPLOYEES SET NAME = '" + vals[1] + "' WHERE ID = '" + id + "' ;";
        W.exec(quer);
        W.commit();
    }
    if(pars[2]){
        work W(C);
        string quer;
        quer = "UPDATE EMPLOYEES SET CONTACT = " + vals[2] + " WHERE ID = '" + id + "' ;";
        W.exec(quer);
        W.commit();
    }
    if(pars[3]){
        work W(C);
        string quer;
        quer = "UPDATE EMPLOYEES SET SEX = '" + vals[3] + "' WHERE ID = '" + id + "' ;";
        W.exec(quer);
        W.commit();
    }
    if(pars[4]){
        work W(C);
        string quer;
        quer = "UPDATE EMPLOYEES SET DOB = '" + vals[4] + "' WHERE ID = '" + id + "' ;";
        W.exec(quer);
        W.commit();
    }
    if(pars[5]){
        work W(C);
        string quer;
        quer = "UPDATE EMPLOYEES SET SALARY = " + vals[5] + " WHERE ID = '" + id + "' ;";
        W.exec(quer);
        W.commit();
    }
    if(pars[6]){
        work W(C);
        string quer;
        quer = "UPDATE EMPLOYEES SET ADDRESS = '" + vals[6] + "' WHERE ID = '" + id + "' ;";
        W.exec(quer);
        W.commit();
    }
    if(pars[0]){
        work W(C);
        string quer;
        quer = "UPDATE EMPLOYEES SET ID = '" + vals[0] + "' WHERE ID = '" + id + "' ;";
        W.exec(quer);
        W.commit();
    }
}
#endif