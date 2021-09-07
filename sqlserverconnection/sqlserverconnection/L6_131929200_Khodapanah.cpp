
//Nasim Khodapanah
//ID : 131929200
//Email: nkhodapanah@myseneca.ca
//Lab 6

#include <iostream>
#include <occi.h>

using namespace oracle::occi;
using namespace std;
using std::left;


int main() {
    Environment* env = nullptr;
    Connection* conn = nullptr;

    string usr = "dbs211_212c10";
    string pass = "13393142";
    string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
    Statement* stmt = nullptr;
    Statement* stmt2 = nullptr;
    try {
        env = Environment::createEnvironment(Environment::DEFAULT);
        conn = env->createConnection(usr, pass, srv);
        //cout << "Connection is successful!" << endl;

        Statement* stmt = conn->createStatement();
        Statement* stmt2 = conn->createStatement();

        ResultSet* rs = stmt->executeQuery("SELECT e.employeenumber, e.firstname,e.lastname,o.phone,e.extension FROM dbs211_employees e JOIN dbs211_offices o ON e.officecode = o.officecode WHERE o.officecode = 1 ");

        ResultSet* rs2 = stmt2->executeQuery("SELECT DISTINCT e1.employeenumber, e1.firstname,e1.lastname,o.phone,e1.extension FROM dbs211_employees e JOIN dbs211_employees e1 ON e1.employeenumber = e.reportsto JOIN dbs211_offices o ON e1.officecode = o.officecode ORDER BY employeenumber");

        cout << "------------------------- Report 1 (Employee Report) -------------------------" << endl;
        if (rs->next()) {
            cout.width(15);
            cout << "Employee Number";
            cout.width(15);
            cout << "First Name";
            cout.width(15);
            cout << "Last Name";
            cout.width(15);
            cout << "Phone";
            cout.width(24);
            cout << "Extension" << endl;

        }
        do {
            int id = rs->getInt(1);
            string f_name = rs->getString(2);
            string l_name = rs->getString(3);
            string phone = rs->getString(4);
            string ext = rs->getString(5);
            cout << left;
            cout.width(20);
            cout << id;
            cout.width(15);
            cout << f_name;
            cout.width(20);
            cout << l_name;
            cout.width(20);
            cout << phone;
            cout.width(20);
            cout << ext << endl;
        } while (rs->next());
        cout << "\n------------------------- Report 2 (Manger Report) -------------------------" << endl;
        if (rs2->next()) {
            cout.width(20);
            cout << "Employee Number";
            cout.width(15);
            cout << "First Name";
            cout.width(20);
            cout << "Last Name";
            cout.width(20);
            cout << "Phone";
            cout.width(20);
            cout << "Extension" << endl;

        }
        do{

            int m_id = rs2->getInt(1);
            string mf_name = rs2->getString(2);
            string ml_name = rs2->getString(3);
            string m_phone = rs2->getString(4);
            string m_ext = rs2->getString(5);

            cout << left;
            cout.width(20);
            cout << m_id;
            cout.width(15);
            cout << mf_name;
            cout.width(20);
            cout << ml_name;
            cout.width(20);
            cout << m_phone;
            cout.width(20);
            cout << m_ext << endl;
        } while (rs2->next());

        conn->terminateStatement(stmt);
        conn->terminateStatement(stmt2);
        env->terminateConnection(conn);
        Environment::terminateEnvironment(env);
    }
    catch (SQLException& sqlExcp) {
        cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
    }
    return 0;
}


