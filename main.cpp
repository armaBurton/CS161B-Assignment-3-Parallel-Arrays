#include <iostream>
// #include <cctype>
// #include <cstdlib>
// #include <cstring>

using namespace std;

const int AN_ABSURD_NUMBER = 9999;

void welcome();
// void readScores(double scores[], int &count);
// void readDouble(char prompt[], double &num);
// void calcGrade(double scores[], char grade[], int count);
// void printList(double scores[], char grades[], int count);
// void sort(double scores[], char grades[], int count);
// double median(double scores[], int count);

int main(int argc, char **argv)
{
    double scores[AN_ABSURD_NUMBER];
    char grades[AN_ABSURD_NUMBER];
    int count;

    welcome();

    system("pause");

    return 0;
}

void welcome()
{
    cout << endl
         << "Welcome to my Parallel Arrays program!\n"
         << "Please enter the list of scores (-1 to end the input): \n"
         << "Valid scores are between 0 and 4 inclusive.\n";
}