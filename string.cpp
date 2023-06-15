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
//    }
//
//};
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
//
//            file.close();
//        }
//    }
//
//    void saveToJson(std::string fileName, std::vector<Student> students) {
//        std::ofstream file(fileName);
//        if (file.is_open()) {
//            file << "[";
//
//            for (int i = 0; i < students.size(); i++) {
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
//
//            file << "]";
//            file.close();
//        }
//    }
//
//};
//
//void loadStudent(std::string fileName, std::vector<Student>& students) {
//    Json json;
//    json.readFromJson(fileName, students);
//}
//
//void addStudent(std::string fileName, std::vector<Student>& students) {
//    int n;
//
//    std::cout << "Enter the number of students to add: "; std::cin >> n;
//
//    std::ofstream outfile;
//    outfile.open(fileName, std::ios_base::app);
//    if (outfile.tellp() > 0) {
//        outfile << ",";
//    }
//
//    for (int i = 0; i < n; i++) {
//        std::string lname, fname, oname, email;
//        int age;
//
//        std::cin.ignore();
//        std::cout << "Enter Lname" << i + 1 << ": ";
//        std::getline(std::cin, lname);
//        if (lname == "") {
//            std::cout << "You have no right to miss this!\n";
//            return;
//        }
//
//        std::cout << "Enter FName" << i + 1 << ": ";
//        std::getline(std::cin, fname);
//        if (fname == "") {
//            std::cout << "You have no right to miss this!\n";
//            return;
//        }
//
//        std::cout << "Enter Oname" << i + 1 << ": ";
//        std::getline(std::cin, oname);
//
//        std::cout << "Enter age" << i + 1 << ": ";
//        std::cin >> age;
//
//        std::cin.ignore();
//        std::cout << "Enter Email" << i + 1 << ": ";
//        std::getline(std::cin, email);
//
//        Student p(lname, fname, oname, age, email);
//        if (age >= 16 && age <= 70) {
//            students.push_back(p);
//            outfile << "{";
//            outfile << "\"lname\":\"" << p.lname << "\",";
//            outfile << "\"fname\":\"" << p.fname << "\",";
//            outfile << "\"oname\":\"" << p.oname << "\",";
//            outfile << "\"age\":" << p.age << ",";
//            outfile << "\"email\":\"" << p.email << "\"";
//            outfile << "}";
//
//            if (i != n-1) {
//                outfile << ",";
//            }
//        } else {
//            std::cout << "Error student age 16-70!!!" << std::endl;
//        }
//    }
//
//    outfile.close();
//}
//
//void editStudent(std::string fileName, std::vector<Student>& students) {
//    int index;
//    std::cout << "Enter the index of the student to edit: "; std::cin >> index;
//
//    if (index >= 0 && index < students.size()) {
//        std::string lname, fname, oname, email;
//        int age;
//
//        std::cin.ignore();
//        std::cout << "Enter Lname: "; std::getline(std::cin, lname);
//        if (lname == "") {
//            std::cout << "You have no right to miss this!\n";
//            return;
//        }
//
//        std::cout << "Enter FName: "; std::getline(std::cin, fname);
//        if (fname == "") {
//            std::cout << "You have no right to miss this!\n";
//            return;
//        }
//
//        std::cout << "Enter Oname: "; std::getline(std::cin, oname);
//
//        std::cout << "Enter age: "; std::cin >> age;
//
//        std::cin.ignore();
//        std::cout << "Enter Email: "; std::getline(std::cin, email);
//
//        students[index].lname = lname;
//        students[index].fname = fname;
//        students[index].oname = oname;
//        students[index].age = age;
//        students[index].email = email;
//
//        // Update JSON file
//        Json json;
//        json.saveToJson("StudentJson.json", students);
//
//        std::cout << "Student edited!" << std::endl;
//    } else {
//        std::cout << "Invalid index, please try again." << std::endl;
//    }
//
//}
//
//void deleteStudent(std::vector<Student>& students) {
//    int index;
//    std::cout << "Enter the index of the student to delete: "; std::cin >> index;
//
//    if (index >= 0 && index < students.size()) {
//        students.erase(students.begin() + index);
//
//        // Update JSON file
//        Json json;
//        json.saveToJson("StudentJson.json", students);
//
//        std::cout << "Student deleted!" << std::endl;
//    } else {
//        std::cout << "Invalid index, please try again." << std::endl;
//    }
//
//}
//
//void menu() {
//    std::vector<Student> students;
//    loadStudent("StudentJson.json", students);
//
//    while (true) {
//        std::cout << "Welcome to the c++ menu! To select, choose what you want:\n";
//        std::cout << "1. Add a student\n";
//        std::cout << "2. Edit a student\n";
//        std::cout << "3. Delete a student\n";
//        std::cout << "4. Quit\n";
//        std::cout << "Enter your choice: ";
//
//        int choice;
//        std::cin >> choice;
//
//        switch (choice) {
//            case 1:
//                addStudent("StudentJson.json", students);
//                break;
//            case 2:
//                editStudent("StudentJson.json", students);
//                break;
//            case 3:
//                deleteStudent(students);
//                break;
//            case 4:
//                std::cout << "Program closed." << std::endl;
//                return;
//            default:
//                std::cout << "Invalid choice. Please try again." << std::endl;
//                break;
//        }
//    }
//
//}
//
//int main() {
//    menu();
//    return 0;
//}
