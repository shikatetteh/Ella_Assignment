#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

const int TOTAL = 5;

struct studentDetail{
   int ID_Number, age;
   char gender, scoreGrade;
   string fullName;
   float cplusScore;
};

studentDetail studentTotal[TOTAL];


int main()
{
    int number, maleCount = 0, femaleCount = 0, averageAge, sumAge = 0, sumMale = 0, sumFemale = 0, count = 0;
    double averageScore, sumScore = 0.0;


    ofstream mydata;
    mydata.open("Student data.txt");

    cout << "\n Enter five student to record data: ";
    cin >> number;


    if (number > TOTAL)
      cout << "\n Enter between 1 - 5" << endl;

    else
      for(int i = 0; i < number; i++){
         cout << endl << "\n Enter fullname for student " << i + 1 << ": ";
         cin >> studentTotal[i].fullName;
         cout << "\n ID number for student " << i + 1 << ": ";
         cin >> studentTotal[i].ID_Number;
         cout << "\n Age for student " << i + 1 << ": ";
         cin >> studentTotal[i].age;
         cout << "\n Gender (M or F) for student " << i + 1 << ": ";
         cin >> studentTotal[i].gender;
         cout << "\n Enter C++ score for student " << i + 1 << ": ";
         cin >> studentTotal[i].cplusScore;

         if(studentTotal[i].cplusScore > 80 && studentTotal[i].cplusScore <= 100)
            studentTotal[i].scoreGrade = 'A';

         else if(studentTotal[i].cplusScore > 70 && studentTotal[i].cplusScore <= 79)
            studentTotal[i].scoreGrade = 'B';

         else if (studentTotal[i].cplusScore > 60 && studentTotal[i].cplusScore <= 69)
            studentTotal[i].scoreGrade = 'C';

         else if (studentTotal[i].cplusScore > 50 && studentTotal[i].cplusScore <= 59)
            studentTotal[i].scoreGrade = 'D';

         else if (studentTotal[i].cplusScore > 40 && studentTotal[i].cplusScore <= 49)
            studentTotal[i].scoreGrade = 'E';

         else
            studentTotal[i].scoreGrade = 'F';

      sumScore += studentTotal[i].cplusScore;
      averageScore =  sumScore / static_cast<double>(number);

      sumAge += studentTotal[i].age;
      averageAge = sumAge / number;
      }

      //Count for the number of male and female
      for(int j = 0; j < number; j++){
            if(studentTotal[j].gender == 'M' || studentTotal[j].gender == 'm')
                maleCount++;

            else if(studentTotal[j].gender == 'F' || studentTotal[j].gender == 'f')
                femaleCount++;

            else
               count;

        }

      //Output to file
      mydata  << "No." << "\t\t " << "ID Number"  << "\t\t " << "Full Name" << "\t\t " << "Age" << "\t\t " << "Gender" << "\t\t " << "Score" << "\t\t " << "Grade" << endl;
      mydata << "**************************************************************************************************************************" << endl;
      for(int j = 0; j < number; j++){
        mydata << j + 1 << ". " << "\t\t " << studentTotal[j].ID_Number << "\t\t " << studentTotal[j].fullName << "\t\t " << studentTotal[j].age << "\t\t " << studentTotal[j].gender << "\t\t " << studentTotal[j].cplusScore << "\t\t " << studentTotal[j].scoreGrade << endl;

      }

      mydata << endl << "\n\t Average Score: " << averageScore << endl << "\n\t Average Age: " << averageAge << endl;
      mydata << "\n\t Male Count: " << maleCount << endl << "\n\t Female count: " << femaleCount << endl;

      mydata << "**************************************************************************************************************************" << endl;

      mydata.close();


    return 0;
}


a5_indexNmber.cc
