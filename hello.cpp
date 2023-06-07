#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>


class Student {
public:
    std::string lname;
    std::string fname;
    std::string oname;
    std::string email;
    int age;

    Student() {}

    Student(std::string lname, std::string fname, std::string oname, int age, std::string email)
            : lname(lname), fname(fname), oname(oname), age(age), email(email) {}
};



class Json {
public:
    void readFromJson(std::string fileName) {}
    void saveToJson(std::string fileName) {}
};

void addStudent(std::vector<Student>& students) {
    int n;
    std::cout << "Enter the number of students to add:\n";
    std::cin >> n;

    std::ofstream file("StudentJson.json", std::ios::app);
    if (file.is_open()) {
        // Add a comma if file is not empty
        if (file.tellp() != 0) {
            file << ",\n";
        }
        file << "\t[\n";
    }

    for (int i = 0; i < n; i++) {
        std::string lname, fname, oname, email;
        int age;
        std::cout << "Enter Lname" << i + 1 << ": ";
        std::cin >> lname;
        std::cout << "Enter FName" << i + 1 << ": ";
        std::cin >> fname;
        std::cout << "Enter Oname" << i + 1 << ": ";
        std::cin >> oname;
        std::cout << "Enter age" << i + 1 << ": ";
        std::cin >> age;
        std::cout << "Enter Email" << i + 1 << ": ";
        std::cin >> email;

        Student p(lname, fname, oname, age, email);
        students.push_back(p);
        if (file.is_open()) {
            file << "\t\t{\n";
            file << "\t\t\t\"lname\": \"" << p.lname << "\",\n";
            file << "\t\t\t\"fname\": \"" << p.fname << "\",\n";
            file << "\t\t\t\"oname\": \"" << p.oname << "\",\n";
            file << "\t\t\t\"age\": " << p.age << ",\n";
            file << "\t\t\t\"email\": \"" << p.email << "\"\n";
            file << "\t\t}";
            if (i != n - 1) {
                file << ",";
            }
            file << "\n";
        }
    }
    if (file.is_open()) {
        file << "\t]\n";
        file.close();
    }
}

void editStudent(std::vector<Student>& students) {
    int index;
    std::cout << "Enter the index of the student to edit: ";
    std::cin >> index;

    if (index >= 0 && index < students.size()) {
        std::string lname, fname, oname, email;
        int age;

        std::cout << "Enter Lname: ";
        std::cin >> lname;
        std::cout << "Enter FName: ";
        std::cin >> fname;
        std::cout << "Enter Oname: ";
        std::cin >> oname;
        std::cout << "Enter age: ";
        std::cin >> age;
        std::cout << "Enter Email: ";
        std::cin >> email;

        students[index].lname = lname;
        students[index].fname = fname;
        students[index].oname = oname;
        students[index].age = age;
        students[index].email = email;

        std::ofstream file("StudentJson.json");

        if (file.is_open()) {
            file << "[\n";
            for (int i = 0; i < students.size(); i++) {
                const Student& p = students[i];
                file << "\t{\n";
                file << "\t\t\"lname\": \"" << p.lname << "\",\n";
                file << "\t\t\"fname\": \"" << p.fname << "\",\n";
                file << "\t\t\"oname\": \"" << p.oname << "\",\n";
                file << "\t\t\"age\": " << p.age << ",\n";
                file << "\t\t\"email\": \"" << p.email << "\"\n";
                file << "\t}";
                if (i != students.size()-1) {
                    file << ",";
                }
                file << "\n";
            }
            file << "]";
            file.close();
        }
        std::cout << "Student edited!\n";
    } else {
        std::cout << "Invalid index, please try again.\n";
    }
}

void deleteStudent(std::vector<Student>& students) {
    int index;
    std::cout << "Enter the index of the student to delete: ";
    std::cin >> index;

    if (index >= 0 && index < students.size()) {
        students.erase(students.begin() + index);

        std::ofstream file("StudentJson.json");

        if (file.is_open()) {
            file << "[\n";
            for (int i = 0; i < students.size(); i++) {
                const Student& p = students[i];
                file << "\t{\n";
                file << "\t\t\"lname\": \"" << p.lname << "\",\n";
                file << "\t\t\"fname\": \"" << p.fname << "\",\n";
                file << "\t\t\"oname\": \"" << p.oname << "\",\n";
                file << "\t\t\"age\": " << p.age << ",\n";
                file << "\t\t\"email\": \"" << p.email << "\"\n";
                file << "\t}";
                if (i != students.size()-1) {
                    file << ",";
                }
                file << "\n";
            }
            file << "]";
            file.close();
        }
        std::cout << "Student deleted!\n";
    } else {
        std::cout << "Invalid index, please try again.\n";
    }
}

void menu() {
    std::vector<Student> students;

    while (true) {
        std::cout << "Select an option:\n";
        std::cout << "1. Add a student\n";
        std::cout << "2. Edit a student\n";
        std::cout << "3. Delete a student\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                editStudent(students);
                break;
            case 3:
                deleteStudent(students);
                break;
            case 4:
                return;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}








        //std::cin >> p.Lname;




//        for (int i = 0; i < n; i++) {
//            int studentNum;
//            std::cout << "Enter number of student " << i + 1 << " you want to delete: ";
//            std::cin >> studentNum;
//
//            if (studentNum < 1 || studentNum > sizeof(students) / sizeof(students[0])) {
//                std::cout << "Invalid student number\n";
//            } else {
//                for (int j = studentNum - 1; j < sizeof(students) / sizeof(students[0]) - 1; j++) {
//                    students[j] = students[j + 1];
//                }
//                n--;
//            }
//        }
//    }


    //getch();
//    std::cout << "Input Fname";
//    std::string s;
//     std::cin>>s;

//    int age;
//    std::cout << "Input age:";
//    std::cin >> age;


//
//@&B#&@##&@@@@@@@@@@@@@@@@#GPP5YJ????7!~::..  ...:^~!7????JJYJYYY5P7!7777777!!^^!!!!!!!!!!!!!77?B####
//@@@@#&&BB&@@@@@@@@@@@@@@@@&B5?7??7777!!!!!~~^~~~!!!!7777???????J55!~!!~~~~!77!^^!?7!!7!!!!7777?B####
//@@@@@@@@&@@@@@@@@@@@BB##&@@@&GJ?777777777777777777777????JJYYYY5Y?7!!~!!7!^~!!?J?#&#7!!7777777?G####
//@@@@@@@@@@@@@@@@@@@@&##B&@@@@@#PJJJJ?????????????????JJY555JJJ??77777777?YPGGBBBB&@&7!77777777?G####
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@GP5YYYYYJ?777777?JYYYYYY5PYJ???7777777777P&&&@@@&B&@@?!77777777?G####
//@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@P5P55PG57~!!!77!?5GGPPPGPYJJJ????7???JJJ5#&&@&#&#B&@&?777777777?G####
//@@@@@@@@@@@@@#BB#@@@@@@@@@@@@@@B5P5JPBBBBPPYJ5GBBBBGGG5YYJJJY??77GGB####&&&#&&&&B&@&?!!!!!7!77?G####
//@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@B5P5JB#5?!^^^::^~75GG5YYJJJYBY77?G&&&&&&&&&&&&#&#B&@#7!!7777!77?G####
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BPP5JBJ^::::::::::^7YYJJJ5G##?77G&&&&&#&&&&&&&&@&B&@&?~!7!!!!!7?G####
//@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@BPP5J?^^^^~:::~^::^~7JJJY####Y77P&&&&&#&&&&&&&&&&B&@@J!!!77777!?GB###
//@@@@@@@@@@#&@@@@&5##&@#&@@&&@@@BPP5J!~^~7Y!^^7Y?~^~!?J?Y#BB#577?B&#####&&&##&&&&B&@@J!7777777!?GBB#B
//@&&@@##@@@&@&&@@&G@&@@&@@@&&@@@BPP5J!~^!JP?!775?7~!!???JBBB#5777Y#B#&#BB##&#&@&&B&@@J!77777!!!?GB##B
//@@&&@&&@&@@@&&@@&&@@@@@@@@&&@@Y!75PJY!!~!!~!!!!777!7???J?!7P5777J&####&#&&&B&&&&B&@@Y!777!7!!!?GBBBB
//@@@@@@@@@@&&@@@@&#&&&@@@@&&@@5.^^~JJJ!~^~7?J????7!^!??7~^:::7?77J&&##&&&@#B&&&&&B&@@Y!777!!!!!?GBBBB
//@@@@@@@@@@@@@@@@&GB#G&@@@@@@#^^~~!~~?!!!!77?7!~!??!~!7^^!^^~:!?7J&&#B##B##B&&&&&B&@@Y!777!!!!!?PBBBB
//@@@@@@@@@@@@@@@@@&&B&@@@@@@&~^~~75G?!7?PG?~?JY!?BGG7!^~777~7^:~7J&@&&&##&&&&&&&&B&@@Y!7!!!!!!!7PBBGG
//@@@@@@@@@@@@@@@@@@@@@@@@@@&!:~!!7B&P!!7YGPG#B#BB###7?!^!7!!!^~^~J&&&&&&&&&&&&&&&B&@@5!!!!!!!!!7PBBGG
//@@@@@@@@@@@@@@@@@@@@@@@@&B~:!!!!!?5?77?P#JPBPB5J##&J77^:~7!!^7~^~B@&&&&&&&&&&&&&B&@@5!!!!!!!!!7PBGGG
//@@@@@@@@@@@@@@@@@@@@@&##P~:~~!!7!7?YJY5#&BPGPGPP&&&Y!?!::~7!!~^!~~Y&&&&&&&&&&&&&GB&&Y!!!!!!!!!7PGGGG
//@@@@@@@@@@@@@@@@@@&##BBY:^~~!~7J!~~~!?&&&&&&&&&&&&#Y~7!^~!??!!7!!~:7#&&#&&&&&&&&P#@&5!!!!!!!!!7PGGPP
//@@@@@@@@@@@@@@@@&#BBPY~:~~!?Y7J57!!:!!G&&&&&&&&&&&#?!7~^!7YYY7?~7!~^~G&#&&&&&&&&G#&&5!!!~!!!!!7PGPPP
//@@@@@@@@@@@@@&##BGPJ?^:!~~77GPP5JJJ7~7?#&&&&&&&&&&&?777^7YYYY?!!7!~~~^G#&#####&&##&@P!!!!!!!!!7PGPPP
//@@@@@@@@@@@#B#BP5JJY!:~7~JJ?GGP5PPPGG5PB###&#&&###&J7!?7JYYYY?77!~!!~~^G#&&&&&&&B#@@P!77!!!!!!?PGPP5
//@@@@@@@@&#B#&#YJ?Y55^^!?!YPPPGP5PPGBB##B#B#&##&&&&&5!!?PGGGGY7??!7!?~!^7?JG#&&###&@@P!7!7777!7?5GPP5
//@@@@@&#BB#BP5J?Y5PP57^7555PPPGPPPGB###B##B#&##&&&&&P!~!P&###P7?J?7!!?!!??77JPPPPG##BY!77777777JPG555
//@@@&BB##G5Y??Y55555PY^!5PPPPPGPPGB#&#B###B#&&##&&&&B!!77B###P7???????~7????777777777!77777777JPGP555
//&#BB#BP5J??Y55YY55555?75PPPPPGGGB#&#B#####&&&###&&&&5!!?5###P7??7JJ?77???????????JJJJ77777777YGP5555
//BB#BP5Y?JY55YYYY555555Y5PPPPPGGB&&########&&&###&&#&5!!?G##&P7?JPGG5?77?????JJY555PPP?777777?5G55555
//&BY5Y5GG5YYYYYYY555555PPPPPPPGB&&#####&###&&&####&&#P?!?#&###J75PPPG57777?Y5555555P5Y7777777Y5G5YYYY
//5Y??JYG#5YYYYYYY555555PP5PPPGB&&#####&&###&&&####&&&##B&&&&###5PPJYPGJ7777Y555555YJ?7777777J5YPP5YY5
//7?J555P#5YYYYYY55555P555PPPGB&&&####&&####&&&&###&&&&##&&&&&&#BYP5YPGY7777YY55555?!7777777777?J5PYYP
//Y5555Y5#PYYYYYYY5555555PPPGB&&&#####&&###&&&&&####&&&&##&&&&&&B?5PPPPY7777YY55P55YYJ?7777777777YP55G
//5555YY5#PYYYYYYY555555PPPGG#&&#####&&&###&&&&&#####&&&&##&&&&&&J?5GGP7777?JY5Y55YYY557!77777777YPPGB