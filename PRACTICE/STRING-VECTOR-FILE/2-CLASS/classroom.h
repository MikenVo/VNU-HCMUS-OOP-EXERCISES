#ifndef STUDENT
#define STUDENT

#include <string>
#include <vector>
using namespace std;

class Student {
    public:
        string name;                                    // 20 characters including the spaces
        string pnum;                                    // 9 to 11 characters, only numbers
        float score;                                    // 0 to 10
        bool validName(string name);                    // Check the validation of the name length
        bool validNumber(string pnum);                  // Check the validation of the phone number length and characters
        bool validScore(float score);                   // Check the validation of the score
};

class Classroom {
    private:
        vector<Student> studentlist;                    // Create a list of student

    public:
        void input();                                   // Input the information
        void output();                                  // Output the list
        int checkstudent(const string& name);           // Check if the student is in the class and return its index
        void addstudent();                              // Add  student
        void delstudent();                              // Delete the student
        void sortClassroom();                           // Sort the classroom based on scores
};

#endif