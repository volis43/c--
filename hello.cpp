#include
#include
#include

class student {
public:
    std::string Lname;
    std::string Fname;
    std::string Oname;
    std::string Email;
    int age;

};

//student students[100];
int main() {

    student p;
    int choice;
    int choice2;
    int n;

    std::cout << "I LOVE C++" << '\n';

    std::cout << "Welcome to the c++ menu! To select, choose what you want"
                 "\n 1) creating a list of students"
                 "\n 2) adding students"
                 "\n 3) editing students"
                 "\n 4) deleting a student\n";

    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter the number of users!" << '\n';

        std::cin >> n;

        student students[n];

        for (int i = 0; i < n; i++) {
            std::cout << "Enter Lname" << i + 1 << ": ";
            std::cin >> students[i].Lname;
            std::cout << "Enter Fname" << i + 1 << ": ";
            std::cin >> students[i].Fname;
            std::cout << "Enter Oname" << i + 1 << ": ";
            std::cin >> students[i].Oname;
            std::cout << "Enter age" << i + 1 << ": ";
            std::cin >> students[i].age;
            std::cout << "Enter Email" << i + 1 << ": ";
            std::cin >> students[i].Email;
        }


        std::cout << "List student is\n";
        for (int i = 0; i < n; i++) {

            student p = students[i];
            if (p.age >= 16 && p.age <= 70) {
                std::cout << p.Lname << ", " << p.Fname << ": " << students[i].Oname << ": " ", " << p.age << ": "
                          << students[i].Email << "\n";
            } else {
                std::cout << students[i].Lname << ", " << students[i].Fname << ", " << students[i].Oname << ": "
                          << p.age << "No" << students[i].Email << "\n"; // тут надо будет удалить
            }
            std::cout << "Welcome to the c++ menu! To select, choose what you want"
                         "\n "
                         "\n 2) adding students"
                         "\n 3) editing students"
                         "\n 4) deleting a student\n";
            std::cin >> choice;

            if(choice == 2){
                std::cout << "Hola";
                student *students = new student[size];
            }

        }
    }

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