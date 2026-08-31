#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

class Student
{
    public:

    string Name;
    string UID;
    string Section; 
    float Marks[3];
    
    char GradeCalc()
    {
        float num = AvgCalc();
        if(num>=80)
        {
            return 'A';
        }
        else if(num>=70)
        {
            return 'B';
        }
        else if(num>=50)
        {
            return 'C';
        }
        else if(num>=30)
        {
            return 'D';
        }
        else
        {
            return 'F';
        }
    }

    float AvgCalc()
    {
        float sum=0;
        short i;
        for(i=0;i<3;i++)
        {
            sum += Marks[i];
        }
        float avg = sum/3.0f;
        return avg;
    }
};

int main()
{
    int num,i=0,j=0;
    cout << "Enter the number of entries you would like to make \n";
    cin >> num;
    while(j!=num)
    {
    cout << " Enter - Name - Uid - Section - Marks(3)\n"; 
    Student s1;
    cin >> s1.Name;
    cin >> s1.UID;
    cin >> s1.Section;
    for(i=0;i<3;i++)
    {
    cin >> s1.Marks[i];
    }
    ofstream outFile("Grade Tracker.csv", ios::app);
    char grade = s1.GradeCalc();
    outFile << "Student - "<< s1.Name<< "\nUID - "<< s1.UID<< "\nSection - "<<s1.Section<< "\nGrade - " <<grade <<"\n"; 
    j++;
    outFile.close();
    }
    return 0;
}