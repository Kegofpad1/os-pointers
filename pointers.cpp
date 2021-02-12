// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average = 0.0;
    student.f_name = new char[128];
    student.l_name = new char[128];
    student.grades = new double[134217728];
    int i=0;

    // Sequence of user input -> store in fields of `student`
    student.id = promptInt("Please enter the student's id number: ", 0, 999999999);
    std::cout << "Please enter the student's first name: ";
    std::cin >> student.f_name;
    std::cout << "Please enter the student's last name: ";
    std::cin >> student.l_name;
    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 134217727);  
    std::cout << "\n";
    std::string s = "";

    while(i < student.n_assignments)
    {
        s = std::to_string(i);
        student.grades[i] = promptDouble("Please enter grade for assignment " + s + ": ", 0, 999.999999);
        average = average + student.grades[i];
        i++;
    }
    std::cout << "\n";
    std:: cout << "Student: " << student.f_name << " " << student.l_name << " [" << student.id << "]\n";
    // Call `CalculateStudentAverage(???, ???)`
    calculateStudentAverage(&student.n_assignments, &average);
    // Output `average`
    std::cout.precision(1);
    std::cout << std::fixed;
    std::cout << "  Average grade: " << average <<"\n";

    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
    int answer = 0;
    int flag=0;
    std::cout << message;
    std::cin >> answer;



    while(flag==0)
    {
        if(std::cin.fail() || answer < min || answer > max)
        {
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout << "Sorry, I cannot understand your answer\n";
            std::cout << message;
            std::cin >> answer;
        }
        else
        {
            flag=1;
        }
    }
    return answer;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    double answer;
    int flag=0;
    std::cout << message;
    std::cin >> answer;

    while(flag==0)
    {
        if(std::cin.fail() || answer < min || answer > max)
        {
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout << "Sorry, I cannot understand your answer\n";
            std::cout << message;
            std::cin >> answer;
        }
        else
        {
            flag=1;
        }
    }
    return answer;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    int temp=0;
    int roundFlag;
    int *intTotal = (int*)object;
    double total = *intTotal + 0.0;
    *avg = *avg / total;
}
