#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Date {
public:
    int year, month, day;

    Date() {
        year = 0;
        month = 0;
        day = 0;
    }

    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
};

class Student {
private:
    string name;
    string address;
    Date birthdate;
    string cccd;

public:
    // ===== Constructors =====

    Student() {
        name = "";
        address = "";
        birthdate = Date();
        cccd = "";
    }

    Student(string n) {
        name = n;
        address = "";
        birthdate = Date();
        cccd = "";
    }

    Student(string n, string addr) {
        name = n;
        address = addr;
        birthdate = Date();
        cccd = "";
    }

    Student(string n, string addr, Date d) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = "";
    }

    Student(string n, string addr, Date d, string id) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = id;
    }

    // ===== Set Student Info =====

    void setStudentInfo(string n) {
        name = n;
    }

    void setStudentInfo(string n, string addr) {
        name = n;
        address = addr;
    }

    void setStudentInfo(string n, string addr, Date d) {
        name = n;
        address = addr;
        birthdate = d;
    }

    void setStudentInfo(string n, string addr, Date d, string id) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = id;
    }

    // ===== Get Student Info =====

    void getStudentInfo() {
        cout << "====================" << endl;
        cout << "=== Student Info ===" << endl;
        cout << "====================" << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birthdate: "
             << birthdate.year << "/"
             << birthdate.month << "/"
             << birthdate.day << endl;
        cout << "CCCD: " << cccd << endl;
    }

    // ===== Search by CCCD =====

    static Student findStudentByCCCD(vector<Student> students, string id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].cccd == id) {
                return students[i];
            }
        }

        return Student();
    }

    // ===== Search by Name =====

    static vector<Student> findStudentsByName(vector<Student> students, string key) {
        vector<Student> result;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].name.find(key) != string::npos) {
                result.push_back(students[i]);
            }
        }

        return result;
    }

    // ===== Search by Age =====

    static vector<Student> findStudentsByAge(vector<Student> students, int age) {
        vector<Student> result;

        int currentYear = 2026;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].birthdate.year != 0) {
                int studentAge = currentYear - students[i].birthdate.year;

                if (studentAge == age) {
                    result.push_back(students[i]);
                }
            }
        }

        return result;
    }

    // ===== Statistics by Birth Year =====

    static void statisticByYear(vector<Student> students, vector<int> years) {
        cout << endl;
        cout << "===== Statistics by Birth Year =====" << endl;

        for (int i = 0; i < years.size(); i++) {
            int count = 0;

            for (int j = 0; j < students.size(); j++) {
                if (students[j].birthdate.year == years[i]) {
                    count++;
                }
            }

            cout << "Year " << years[i] << ": "
                 << count << " student(s)" << endl;
        }
    }

    // ===== Statistics by Province =====

    static void statisticByProvince(vector<Student> students,
                                    vector<string> provinces) {
        cout << endl;
        cout << "===== Statistics by Province =====" << endl;

        for (int i = 0; i < provinces.size(); i++) {
            int count = 0;

            for (int j = 0; j < students.size(); j++) {
                if (students[j].address.find(provinces[i]) != string::npos) {
                    count++;
                }
            }

            cout << provinces[i] << ": "
                 << count << " student(s)" << endl;
        }
    }

    // ===== Print List =====

    static void printList(vector<Student> students) {
        for (int i = 0; i < students.size(); i++) {
            students[i].getStudentInfo();
            cout << endl;
        }
    }
};

int main() {

    // ===== Create Students =====

    Student student1;

    Student student2("Huong");

    Student student3("An", "Vo Van Ngan");

    Date d(1989, 9, 12);
    Student student4("DoMIXI", "Ha Noi", d, "0007777056");

    Date d2(1996, 10, 26);
    Student student5("DungSenpai", "Da Nang", d2, "999993884");

    Date d3(2000, 5, 15);
    Student student6("Nguyen Van A",
                     "Thu Duc, Ho Chi Minh",
                     d3,
                     "123456789");

    Date d4(2001, 8, 20);
    Student student7("Tran Van B",
                     "Bien Hoa, Dong Nai",
                     d4,
                     "987654321");

    Date d5(2000, 11, 10);
    Student student8("Le Van C",
                     "Thu Dau Mot, Binh Duong",
                     d5,
                     "111222333");

    // ===== Put Students into Vector =====

    vector<Student> students;

    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);
    students.push_back(student4);
    students.push_back(student5);
    students.push_back(student6);
    students.push_back(student7);
    students.push_back(student8);

    // ===== Display Students =====

    cout << "========== ALL STUDENTS ==========" << endl;
    Student::printList(students);

    // ===== Search by CCCD =====

    cout << endl;
    cout << "========== SEARCH BY CCCD ==========" << endl;

    Student result = Student::findStudentByCCCD(
        students,
        "123456789"
    );

    result.getStudentInfo();

    // ===== Search by Name =====

    cout << endl;
    cout << "========== SEARCH BY NAME ==========" << endl;

    vector<Student> nameResult =
        Student::findStudentsByName(students, "Van");

    Student::printList(nameResult);

    // ===== Search by Age =====

    cout << endl;
    cout << "========== SEARCH BY AGE ==========" << endl;

    vector<Student> ageResult =
        Student::findStudentsByAge(students, 26);

    Student::printList(ageResult);

    // ===== Statistics by Birth Year =====

    vector<int> years;

    years.push_back(2000);
    years.push_back(2001);

    Student::statisticByYear(students, years);

    // ===== Statistics by Province =====

    vector<string> provinces;

    provinces.push_back("Ho Chi Minh");
    provinces.push_back("Dong Nai");
    provinces.push_back("Binh Duong");
    provinces.push_back("Ha Noi");
    provinces.push_back("Da Nang");

    Student::statisticByProvince(students, provinces);

    return 0;
}