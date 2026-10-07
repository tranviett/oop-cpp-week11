#include <iostream>
#include <string>
#include <vector>
#include <optional>

using namespace std;

//--- Simple Date class ---------------------------------------------
class Date {
public:
    int year, month, day;
    Date() : year(0), month(0), day(0) {}
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    string toString() const {
        char buf[11];
        sprintf(buf, "%04d/%02d/%02d", year, month, day);
        return string(buf);
    }
};

//--- Student class ---------------------------------------------
class Student {
private:
    // Thuộc tính
    string name;
    string address;
    optional<Date> birthdate;   // optional để thể hiện có/không có ngày sinh
    string cccd;                // căn cước công dân

public:
    /* ---------- Constructors (1-4 tham số) ---------- */
    Student()
        : name(""), address(""), birthdate(std::nullopt), cccd("") {}

    explicit Student(const string& n)
        : name(n), address(""), birthdate(std::nullopt), cccd("") {}

    explicit Student(const Date& d)
        : name(""), address(""), birthdate(d), cccd("") {}

    Student(const string& n, const string& a)
        : name(n), address(a), birthdate(std::nullopt), cccd("") {}

    Student(const string& n, const string& a, const Date& d)
        : name(n), address(a), birthdate(d), cccd("") {}

    Student(const string& n, const string& a, const Date& d, const string& cc)
        : name(n), address(a), birthdate(d), cccd(cc) {}

    /* ---------- Methods --------------------------------- */
    void setStudentInfo() {
        cout << "Nhap ten: ";  getline(cin, name);
        cout << "Nhap dia chi: "; getline(cin, address);

        int y, m, d;
        cout << "Nhap ngay sinh (yyyy mm dd): ";
        cin >> y >> m >> d;
        birthdate = Date(y, m, d);
        cin.ignore(); // xóa newline

        cout << "Nhap cccd: ";
        getline(cin, cccd);
    }