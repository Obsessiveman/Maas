#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

enum class Level{Junior,Middle, Senior};
		
class Employee {
private:
    string name;
    Level level;
    double hourly_rate;
    double hours_worked;
    

public:
    Employee(const string& name, Level level, double hourly_rate) : name(name), level(level), hourly_rate(hourly_rate), hours_worked(0) {}

    void update_hours_worked(double hours) {
        hours_worked = hours;
    }

    double calculate_gross_pay() const {
        return hours_worked * hourly_rate;
    }

    double calculate_taxes() const {
        return calculate_gross_pay() * 0.20;  // %20 vergi oraný varsayalým
    }

    double calculate_net_pay() const {
        return calculate_gross_pay() - calculate_taxes();
    }

    const string& get_name() const {
        return name;
    }
	Level get_level() const {
        return level;
    }
    static string level_to_string(Level level) {
        switch (level) {
            case Level::Junior: return "Junior";
            case Level::Middle: return "Middle";
            case Level::Senior: return "Senior";
            default: return "Unknown";}}
};
class EmployeeManager {
private:
    vector<Employee> employees;
public:
    EmployeeManager() {
        // 30 Çalýþan, rastgele kýdem seviyeleri ve saatlik ücretlerle
        vector<string> names = {"Ali", "Ayþe", "Fatma", "Mehmet", "Zeynep", "Ahmet", "Elif", "Ömer",
                                "Beril", "Cem", "Deniz", "Ece", "Fýrat", "Gizem", "Hakan", "Iþýl",
                                "Jale", "Kemal", "Lale", "Murat", "Nevin", "Orhan", "Pelin", "Rüya",
                                "Selin", "Tayfun", "Ufuk", "Veli", "Yasemin", "Zafer"};
        vector<Level> levels = {Level::Junior, Level::Middle, Level::Senior, Level::Junior, Level::Middle,
                                Level::Senior, Level::Junior, Level::Middle, Level::Senior, Level::Junior,
                                Level::Middle, Level::Senior, Level::Junior, Level::Middle, Level::Senior,
                                Level::Junior, Level::Middle, Level::Senior, Level::Junior, Level::Middle,
                                Level::Senior, Level::Junior, Level::Middle, Level::Senior, Level::Junior,
                                Level::Middle, Level::Senior, Level::Junior, Level::Middle, Level::Senior};
        vector<double> rates = {70.0, 150.0, 200.0, 70.0, 150.0, 200.0, 70.0, 150.0, 200.0, 70.0,
                                150.0, 200.0, 70.0, 150.0, 200.0, 70.0, 150.0, 200.0, 70.0, 150.0,
                                200.0, 70.0, 150.0, 200.0, 70.0, 150.0, 200.0, 70.0, 150.0, 200.0};
 for (size_t i = 0; i < names.size(); ++i) {
            employees.emplace_back(names[i], levels[i], rates[i]);
        }
    }

    Employee* find_employee(const string& name) {
        auto it = find_if(employees.begin(), employees.end(), [&name](const Employee& emp) {
            return emp.get_name() == name;
        });
        return it != employees.end() ? &(*it) : nullptr;
    }
};

bool passwordCheck(string password, string enter) {
    return enter == password;
}
int main() {
	setlocale(LC_ALL,"Turkish"); //Türkçe karakter
	string password= "1234";
    	string enter;
    	cout << "Þifreyi giriniz: ";
    	cin >> enter;
    	EmployeeManager manager;
        string name;
	
	if (passwordCheck(password, enter)) {
        cout << "Giriþ yapýldý.\n";
        
    } else {
        cout << "Hatalý giriþ.\n";
        return 0;
    }
	
    while (true) {
        cout << "Çalýþanýn ismini giriniz (çýkmak için 'exit' yazýnýz): ";
        cin >> name;

        if (name == "exit") {
            cout << "Programdan çýkýlýyor..." << endl;
            break;
        }

        Employee* employee = manager.find_employee(name);
        if (employee) {
            double hours_worked;
            cout <<"Bu hafta kaç saat çalýþtý?: ";
            cin >> hours_worked;
				cin.ignore();  // '\n' karakterini temizlemek için

            employee->update_hours_worked(hours_worked);


		cout << employee->get_name() << " (" << Employee::level_to_string(employee->get_level()) << ") adlý çalýþanýn brüt maaþý: "<< fixed << setprecision(2) << employee->calculate_gross_pay() << " USD\n";
            cout << "Kesilen vergiler: " << employee->calculate_taxes() << " USD\n";
            cout << "Net maaþý: " << employee->calculate_net_pay() << " USD\n";		
			}
             else {
            cout << name << " adlý çalýþan þirketimizde bulunamadý." << endl;
        }
    }
    return 0;
}
