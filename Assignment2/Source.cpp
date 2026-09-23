    #include <iostream>
    #include <fstream>
    #include <sstream>
    #include <string>
    #include <vector>

    using namespace std;

    struct STUDENT_DATA
    {
        string firstName;
        string lastName;
        string email;
    };

    int main()
    {
        vector<STUDENT_DATA> students;

        string fileName = "StudentData.txt";

    #ifdef PRE_RELEASE
        fileName = "StudentData_Emails.txt";
        cout << "PRE-RELEASE VERSION" << endl;
    #else
        cout << "STANDARD VERSION" << endl;
    #endif

        ifstream inputFile(fileName);

        if (!inputFile.is_open())
        {
            cout << "Error opening file: " << fileName << endl;
            return 1;
        }

        string line;

        while (getline(inputFile, line))
        {
            stringstream ss(line);
            STUDENT_DATA student;

            getline(ss, student.firstName, ',');
            getline(ss, student.lastName, ',');

    #ifdef PRE_RELEASE
            getline(ss, student.email, ',');
    #endif

            students.push_back(student);
        }

        inputFile.close();

    #ifdef _DEBUG

        cout << endl;
        cout << "DEBUG MODE" << endl;
        cout << "------------------------" << endl;

        for (const auto& student : students)
        {
            cout << "First Name: " << student.firstName << endl;
            cout << "Last Name: " << student.lastName << endl;

    #ifdef PRE_RELEASE
            cout << "Email: " << student.email << endl;
    #endif

            cout << endl;
        }

    #endif

        return 0;
    }