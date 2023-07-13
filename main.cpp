#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

const int AN_ABSURD_NUMBER = 9999;

void welcome();
void readScores(double scores[], int &count);
void readDouble(char prompt[], double &num);
// void calcGrade(double scores[], char grade[], int count);
// void printList(double scores[], char grades[], int count);
// void sort(double scores[], char grades[], int count);
// double median(double scores[], int count);

int main(int argc, char **argv)
{
    double scores[AN_ABSURD_NUMBER];
    char grades[AN_ABSURD_NUMBER];
    int count = 0;

    welcome();
    readScores(scores, count);

    cout << endl;
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

void readScores(double scores[], int &count){
    double score;
    
    while (count != -1){
        readDouble(">> ", score);
        if (score < -1 || score > 4){
            cout << "You have chosen poorly. Resubmit grade.\n";
        } else {
            scores[count++] = score;
        }
    }
}

void readDouble(char prompt[], double &score){
    bool loopState;
    

    int length = sizeof(prompt) / sizeof(prompt[0]),
        i;

    do{
        loopState = true;
        for (i = 0; i < length; i++){
            cout << prompt[i];
        }
        cin >> score;
        if (isnan(score)){
            cout << "You have chosen poorly. Resubmit grade.\n";
        } else {
            loopState = false;
        }
    }
}