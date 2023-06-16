#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
#include <io.h>
class Student {
public:
    std::string lname;
    std::string fname;
    std::string oname;
    std::string email;
    int age;

    Student() {}

    Student(std::string lname, std::string fname, std::string oname, int age, std::string email)
            : lname(lname), fname(fname), oname(oname), age(age), email(email) {
    }

};

class Json {
public:
    void readFromJson(const std::string& fileName, std::vector<Student>& students) {
        std::ifstream file(fileName);
        if (file.is_open()) {
            students.clear();

            char c;
            std::string buffer;

            while (file.get(c)) {
                if (c == '{') {
                    buffer = "{";
                } else if (c == '}') {
                    buffer += "}";
                    Student s;
                    int pos = buffer.find("\"lname\":");
                    s.lname = buffer.substr(pos+9, buffer.substr(pos+9).find("\""));
                    pos = buffer.find("\"fname\":");
                    s.fname = buffer.substr(pos+9, buffer.substr(pos+9).find("\""));
                    pos = buffer.find("\"oname\":");
                    s.oname = buffer.substr(pos+9, buffer.substr(pos+9).find("\""));
                    pos = buffer.find("\"age\":");
                    s.age = std::stoi(buffer.substr(pos+6, buffer.substr(pos+6).find(",")));
                    pos = buffer.find("\"email\":");
                    s.email = buffer.substr(pos+9, buffer.substr(pos+9).find("\""));



                    students.push_back(s);
                    buffer = "";
                } else if (buffer != "") {
                    buffer += c;
                }
            }

            file.close();
        }
    }

    void saveToJson(std::string fileName, std::vector<Student> students) {
        std::ofstream file(fileName);
        if (file.is_open()) {
            file << "[";

            for (int i = 0; i < students.size(); i++) {
                Student s = students.at(i);
                file << "{";
                file << "\"lname\":\"" << s.lname << "\",";
                file << "\"fname\":\"" << s.fname << "\",";
                file << "\"oname\":\"" << s.oname << "\",";
                file << "\"age\":" << s.age << ",";
                file << "\"email\":\"" << s.email << "\"";
                file << "}";

                if (i != students.size()-1) {
                    file << ",";
                }
            }

            file << "]";
            file.close();
        }
    }

};

void loadStudent(std::string fileName, std::vector<Student>& students) {
    Json json;
    json.readFromJson(fileName, students);
}

void addStudent(std::string fileName, std::vector<Student>& students) {
    int n;
    std::cout << "Enter the number of students to add: ";
    std::cin >> n;

    std::ofstream outfile;
    outfile.open(fileName, std::ios_base::app);
    if (outfile.tellp() > 0) {
        outfile << ",";
    } else {
        outfile << "[";
    }

    for (int i = 0; i < n; i++) {
        std::string lname, fname, oname, email;
        int age;

        std::cin.ignore();
        std::cout << "Enter Lname" << i + 1 << ": ";
        std::getline(std::cin, lname);
        if (lname == "") {
            std::cout << "You have no right to miss this!\n";
            return;
        }

        std::cout << "Enter FName" << i + 1 << ": ";
        std::getline(std::cin, fname);
        if (fname == "") {
            std::cout << "You have no right to miss this!\n";
            return;
        }

        std::cout << "Enter Oname" << i + 1 << ": ";
        std::getline(std::cin, oname);

        std::cout << "Enter age" << i + 1 << ": ";
        std::cin >> age;

        std::cin.ignore();
        std::cout << "Enter Email" << i + 1 << ": ";
        std::getline(std::cin, email);

        Student p(lname, fname, oname, age, email);
        if (age >= 16 && age <= 70) {
            students.push_back(p);
            outfile << "\n\t{\n";
            outfile << "\t\t\"lname\":\"" << p.lname << "\",\n";
            outfile << "\t\t\"fname\":\"" << p.fname << "\",\n";
            outfile << "\t\t\"oname\":\"" << p.oname << "\",\n";
            outfile << "\t\t\"age\":" << p.age << ",\n";
            outfile << "\t\t\"email\":\"" << p.email << "\"\n";
            outfile << "\t}";
            if (i != n - 1) {
                outfile << ",";
            }
        } else {
            std::cout << "Error student age 16-70!!!" << std::endl;
        }
        std::cout << "\n\t{\n";
        std::cout << "\t\t\"lname\":\"" << p.lname << "\",\n";
        std::cout << "\t\t\"fname\":\"" << p.fname << "\",\n";
        std::cout << "\t\t\"oname\":\"" << p.oname << "\",\n";
        std::cout << "\t\t\"age\":" << p.age << ",\n";
        std::cout << "\t\t\"email\":\"" << p.email << "\"\n";
        std::cout << "\t}";
    }

    if (students.size() > 0) {
        outfile << "\n]";
    }

    outfile.close();
}

void editStudent(std::string fileName, std::vector<Student>& students) {
    int index;
    std::cout << "Enter the index of the student to edit: "; std::cin >> index;

    if (index >= 0 && index < students.size()) {
        std::string lname, fname, oname, email;
        int age;

        std::cin.ignore();
        std::cout << "Enter Lname: "; std::getline(std::cin, lname);
        if (lname == "") {
            std::cout << "You have no right to miss this!\n";
            return;
        }

        std::cout << "Enter FName: "; std::getline(std::cin, fname);
        if (fname == "") {
            std::cout << "You have no right to miss this!\n";
            return;
        }

        std::cout << "Enter Oname: "; std::getline(std::cin, oname);

        std::cout << "Enter age: "; std::cin >> age;

        std::cin.ignore();
        std::cout << "Enter Email: "; std::getline(std::cin, email);

        students[index].lname = lname;
        students[index].fname = fname;
        students[index].oname = oname;
        students[index].age = age;
        students[index].email = email;

        // Update JSON file
        Json json;
        json.saveToJson("StudentJson.json", students);

        std::cout << "Student edited!" << std::endl;
    } else {
        std::cout << "Invalid index, please try again." << std::endl;
    }


}






void deleteStudent(std::vector<Student>& students) {
    int index;
    std::cout << "Enter the index of the student to delete: "; std::cin >> index;

    if (index >= 0 && index < students.size()) {
        students.erase(students.begin() + index);

        // Update JSON file
        Json json;
        json.saveToJson("StudentJson.json", students);

        std::cout << "Student deleted!" << std::endl;
    } else {
        std::cout << "Invalid index, please try again." << std::endl;
    }

}

void menu() {
    std::vector<Student> students;
    loadStudent("StudentJson.json", students);

    while (true) {
        std::cout << "Welcome to the c++ menu! To select, choose what you want:\n";
        std::cout << "1. Add a student\n";
        std::cout << "2. Edit a student\n";
        std::cout << "3. Delete a student\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent("StudentJson.json", students);
                break;
            case 2:
                editStudent("StudentJson.json", students);
                break;
            case 3:
                deleteStudent(students);
                break;
            case 4:
                std::cout << "Program closed." << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

}

int main() {
    menu();
    return 0;
}

//class Student {
//public:
//    std::string lname;
//    std::string fname;
//    std::string oname;
//    std::string email;
//    int age;
//
//    Student() {}
//
//    Student(std::string lname, std::string fname, std::string oname, int age, std::string email)
//            : lname(lname), fname(fname), oname(oname), age(age), email(email) {
//
//    }
//};
//
//
//
//class Json {
//public:
//    void readFromJson(const std::string& fileName, std::vector<Student>& students) {
//        std::ifstream file(fileName);
//        if (file.is_open()) {
//            students.clear();
//
//            char c;
//            std::string buffer;
//
//            while (file.get(c)) {
//                if (c == '{') {
//                    buffer = "{";
//                } else if (c == '}') {
//                    buffer += "}";
//                    Student s;
//                    int pos = buffer.find("\"lname\":");
//                    s.lname = buffer.substr(pos+9, buffer.substr(pos+9).find("\""));
//                    pos = buffer.find("\"fname\":");
//                    s.fname = buffer.substr(pos+9, buffer.substr(pos+9).find("\""));
//                    pos = buffer.find("\"oname\":");
//                    s.oname = buffer.substr(pos+9, buffer.substr(pos+9).find("\""));
//                    pos = buffer.find("\"age\":");
//                    s.age = std::stoi(buffer.substr(pos+6, buffer.substr(pos+6).find(",")));
//                    pos = buffer.find("\"email\":");
//                    s.email = buffer.substr(pos+9, buffer.substr(pos+9).find("\""));
//
//                    students.push_back(s);
//                    buffer = "";
//                } else if (buffer != "") {
//                    buffer += c;
//                }
//            }
//            file.close();
//        }
//    }
//
////    void saveToJson(std::string fileName) {}
//void saveToJson(std::string fileName, std::vector<Student> students){
//        std::ofstream file(fileName);
//        if(file.is_open()) {
//            file << "[";
//
//            for(int i = 0; i < students.size(); i++){
//                Student s = students.at(i);
//                file << "{";
//                file << "\"lname\":\"" << s.lname << "\",";
//                file << "\"fname\":\"" << s.fname << "\",";
//                file << "\"oname\":\"" << s.oname << "\",";
//                file << "\"age\":" << s.age << ",";
//                file << "\"email\":\"" << s.email << "\"";
//                file << "}";
//
//                if (i != students.size()-1) {
//                    file << ",";
//                }
//            }
//            file << "]";
//            file.close();
//        }
//    }
//};
//
//void loadStudent(std::string fileName, std::vector<Student>& students) {
//    Json json;
//    json.readFromJson(fileName, students);
//}
//
//
//void addStudent(std::string fileName, std::vector<Student>& students) {
//    int n;
//
//    std::cout << "Enter the number of students to add: ";
//    std::cin >> n;
//
//    std::ofstream outfile;
//    outfile.open(fileName, std::ios_base::app);
//    if (outfile.tellp() > 0) {
//        outfile << ",";
//    }
//    outfile << "\n\t[\n";
//    for (int i = 0; i < n; i++) {
//        std::string lname, fname, oname, email;
//        int age;
//
//
//        std::cin.ignore();
//        std::cout << "Enter lname" << i + 1 << ": ";
//        std::getline(std::cin, lname);
//
//        if (lname == "") {
//            std::cout << "You have no right to miss this!\n";
//            return;
//        }
//
//        std::cout << "Enter FName" << i + 1 << ": ";
//        std::getline(std::cin, fname);
//
//        if (fname == "") {
//            std::cout << "You have no right to miss this!\n";
//            return;
//        }
//
//
//        std::cout << "Enter Oname" << i + 1 << ": ";
//
//        std::getline(std::cin, oname);
//
//        std::cout << "Enter age" << i + 1 << ": ";
//        std::cin >> age;
//
//        std::cin.ignore();
//        std::cout << "Enter Email" << i + 1 << ": ";
//
//        std::getline(std::cin, email);
//
//        Student p(lname, fname, oname, age, email);
//
//        if (age >= 16 && age <= 70) {
//            students.push_back(p);
//            outfile << "\n\t{\n";
//            outfile << "\t\t\"lname\": \"" << p.lname << "\",\n";
//            outfile << "\t\t\"fname\": \"" << p.fname << "\",\n";
//            outfile << "\t\t\"oname\": \"" << p.oname << "\",\n";
//            outfile << "\t\t\"age\": " << p.age << ",\n";
//            outfile << "\t\t\"email\": \"" << p.email << "\"\n";
//            outfile << "\t}";
//
//            if (i != n - 1) {
//                outfile << ",";
//            }
//        } else {
//            std::cout << "Error student age 16-70!!!" << std::endl;
//        }
//
//    }
//            outfile << "\n\t]\n";
//    outfile.close();
//}
//
//
//
//void editStudent(std::string fileName, std::vector<Student>& students) {
//    int index;
//    std::cout << "Enter the index of the student to edit: ";
//    std::cin >> index;
//
//    if (index >= 0 && index < students.size()) {
//        std::string lname, fname, oname, email;
//        int age;
//
//        std::cin.ignore();
//        std::cout << "Enter Lname: ";
//        std::getline(std::cin, lname);
//
//        if (lname == "") {
//            std::cout << "You have no right to miss this!\n";
//            return;
//        }
//
//
//        std::cout << "Enter FName: ";
//        std::getline(std::cin, fname);
//
//        if (fname == "") {
//            std::cout << "You have no right to miss this!\n";
//            return;
//        }
//
//        std::cout << "Enter Oname: ";
//        std::getline(std::cin, oname);
//        std::cout << "Enter age: ";
//        std::cin >> age;
//        std::cout << "Enter Email: ";
//        std::getline(std::cin, email);
//
//        students[index].lname = lname;
//        students[index].fname = fname;
//        students[index].oname = oname;
//        students[index].age = age;
//        students[index].email = email;
//
//        Json json;
//        json.saveToJson("StudentJson.json", students);
//    } else {
//        std::cout << "Nooo don't work ";
//    }
//}
//
////        std::ofstream file("StudentJson.json");
//
//
//
//    void deleteStudent(std::vector<Student> &students) {
//
//        int index;
//        std::cout << "Enter the index of the student to delete: ";
//        std::cin >> index;
//
//        if (index >= 0 && index < students.size()) {
//            students.erase(students.begin() + index);
//
////            std::ofstream file("StudentJson.json");
//
//            Json json;
//            json.saveToJson("studentJson.json", students);
//
//            std::cout << "Student seccest deleted!" << std::endl;
//
//
//        } else {
//            std::cout << "Nooo don't work" << std::endl;
//
//        }
//    }
//
//    void menu() {
//        std::vector<Student> students;
//        loadStudent("StudentJson.json", students);
//
//        while (true) {
//            std::cout << "Welcome to the c++ menu! To select, choose what you want:\n";
//            std::cout << "1. Add a student\n";
//            std::cout << "2. Edit a student\n";
//            std::cout << "3. Delete a student (Report of students with 0 !)\n";
//            std::cout << "4. Quit\n";
//            std::cout << "Enter your choice: ";
//
//            int choice;
//            std::cin >> choice;
//
//            switch (choice) {
//                case 1:
//                    addStudent("StudentJson.json", students);
//                    break;
//                case 2:
//                    editStudent("StudentJson.json", students);
//                    break;
//                case 3:
//                    deleteStudent(students);
//                    break;
//                case 4:
//
//                    return;
//                default:
//                    std::cout << "Invalid choice, please try again.\n";
//            }
//
//        }
//
//    }
//
//        int main() {
//            menu();
//
//            return 0;
//        }











//    int main() {
//        menu();
//
//        return 0;
//    }




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