//NAME : NURIN HAZWANI BINTI HUSSIN
// MATRIC NUMBER : A24CS0171
// DATE : 8/1/2025
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int SIZE =20;

//TASK 1
void getInput(string universities[], int numStudent[], int enrolment[], int output[], int &count )
{
    ifstream inFile;
    inFile.open("input.txt");

    if(!inFile)
    {
        cout << "Error! Unable to open the input file 'input.txt'. " << endl;
        exit (1);
    
    }
 
   count=0;

    
       while ( count < SIZE && inFile >> universities[count] >> numStudent[count] >> enrolment[count] >> output[count])
       {
        count++;
       }
    
    


//close the file.
inFile.close();
    
}

//TASK 2
int calTotal(int array[], int count)
{
 int total=0;
for(int i=0; i<count; i++)
{
    total+=array[i];
}
return total;
}

//TASK 3
int getLowest (int array[], int SIZE)
{
 int lowest=0;
 for(int i=1; i<SIZE; i++)
 { if(array[i]<array[lowest])
  {
    lowest = i;
  }
 }
 return lowest;
}

//TASK 4
int getHighest(int array[], int SIZE)
{
    int highest=0;
    for (int i=1; i<SIZE; i++)
    {
        if(array[i]>array[highest])
        {
            highest = i;
        }
    }
    return highest;
}




int main()
{
  string universities[SIZE];
  int count=0;
  int numStudent[SIZE], enrolment[SIZE], output[SIZE];
  int totalIntake, totalEnrolment, totalOutput;
  double averageIntake, averageEnrolment, averageOutput;
  int lowestIntake, lowestEnrolment, lowestOutput;
  int highestIntake, highestEnrolment, highestOutput;
  int rangeIntake, rangeEnrolment, rangeOutput;

 getInput(universities, numStudent, enrolment, output, count);
 
 //TASK 6 - CALCULATE TOTAL AND AVERAGE STUDENT INTAKE, ENROLMENT, AND OUTPUT.
 totalIntake = calTotal(numStudent, count);
 totalEnrolment = calTotal(enrolment, count);
 totalOutput = calTotal(output, count);

 averageIntake= totalIntake / static_cast<double>(count);
 averageEnrolment = totalEnrolment / static_cast<double>(count);
 averageOutput= totalOutput / static_cast<double>(count);

 //TASK 6 - FIND HIGHEST AND LOWEST STUDENT INTAKE, ENROLMENT, AND OUTPUT. THEN RANGE
 lowestIntake= getLowest(numStudent, count);
 lowestEnrolment = getLowest(enrolment, count);
 lowestOutput = getLowest(output, count);

 highestIntake = getHighest(numStudent, count);
 highestEnrolment = getHighest(enrolment, count);
 highestOutput = getHighest(output, count);

 rangeIntake = numStudent[highestIntake] - numStudent[lowestIntake];
 rangeEnrolment = enrolment[highestEnrolment] - enrolment[lowestEnrolment];
 rangeOutput = output[highestOutput] - output[lowestOutput]; 

ofstream outputFile("output.txt");
	if(!outputFile)
	{	
        cout<<"Error opening output file!"<< endl;
        return 1;
    }

    outputFile << right;
    outputFile << setw(55) << "NUMBER OF STUDENTS' INTAKE, ENROLMENT AND OUTPUT " << endl;
    outputFile << setw(45) << "IN PUBLIC UNIVERSITIES (2023)" << endl;
    outputFile << "---------------------------------------------------------------" << endl;
    outputFile << "UNIVERSITY   \t  INTAKE     \t ENROLMENT     \t    OUTPUT   \t" << endl;
    outputFile << "---------------------------------------------------------------" << endl;
    
    //DISPLAY UNI NAME INTAKE ENROLMENT AND OUTPUT.
    for(int i=0; i<count; i++)
    {
        outputFile << left;
        outputFile << setw(18) << universities[i] << setw(15) << numStudent[i] << setw(20) << enrolment[i] << setw(25) << output[i] << endl;
    }
    
    outputFile << "---------------------------------------------------------------" << endl;
    outputFile << left;
    outputFile << setw(15) << "TOTAL" <<setw(17) << totalIntake << setw(19) << totalEnrolment << setw(20) << totalOutput << endl;
    outputFile << setw(15) << "AVERAGE" <<setw(15) << fixed << setprecision(2) << averageIntake << setw(20) << averageEnrolment << setw(20) << averageOutput <<endl;
    outputFile << "---------------------------------------------------------------" << endl;

    //DISPLAY THE LOWEST AND THE HIGHEST FOR ALL ASPECTS
    outputFile << "THE LOWEST NUMBER OF STUDENTS' INTAKE  = " << numStudent[lowestIntake] << "(" << universities[lowestIntake] << ")" << endl;
    outputFile << "THE LOWEST NUMBER OF STUDENTS' ENROLMENT  = " << enrolment[lowestEnrolment] << "(" << universities[lowestEnrolment] << ")" << endl;
    outputFile << "THE LOWEST NUMBER OF STUDENTS' OUTPUT  = " << output[lowestOutput] << "(" << universities[lowestOutput] << ")" << endl;
    outputFile << endl;

    outputFile << "THE HIGHEST NUMBER OF STUDENTS' INTAKE  = " << numStudent[highestIntake] << "(" << universities[highestIntake] << ")" << endl;
    outputFile << "THE HIGHEST NUMBER OF STUDENTS' ENROLMENT  = " << enrolment[highestEnrolment] << "(" << universities[highestEnrolment] << ")" << endl;
    outputFile << "THE HIGHEST NUMBER OF STUDENTS' OUTPUT  = " << output[highestOutput] << "(" << universities[highestOutput] << ")" << endl;
    outputFile << endl;

    //DISPLAY RANGE OF ALL ASPECTS
    outputFile << "THE RANGE OF NUMBER OF STUDENTS' INTAKE  = " << rangeIntake << endl;
    outputFile << "THE RANGE OF NUMBER OF STUDENTS' ENROLMENT  = " << rangeEnrolment<< endl;
    outputFile << "THE RANGE OF NUMBER OF STUDENTS' OUTPUT  = " << rangeOutput << endl;
    outputFile << "---------------------------------------------------------------" << endl;

    //CLOSE THE FILE
    outputFile.close();
    
   
    return 0;

}