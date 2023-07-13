#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

const int AN_ABSURD_NUMBER = 9999;

void welcome();
void readScores(double scores[], int &count);
void readDouble(char prompt[], double &num);
void calcGrades(double scores[], char grade[], int count);
void printList(double scores[], char grades[], int count);
void sort(double scores[], char grades[], int count);
// double median(double scores[], int count);

int main(int argc, char **argv)
{
    double scores[AN_ABSURD_NUMBER];
    char grades[AN_ABSURD_NUMBER];
    int count = 0;

    welcome();
    readScores(scores, count);
    calcGrades(scores, grades, count);

    cout << endl;

    cout << "Your stats are as below:\n"
         << endl
         << "The list of scores and their grades are:\n";
    printList(scores, grades, count);
    cout << endl
         << "The list sorted by scores in ascending order:\n";
    sort(scores, grades, count);
    printList(scores, grades, count);


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
    double score = 0;
    count = 0;
    
    while (score != -1){
        readDouble(">> ", score);
        if (score < -1 || score > 4){
            cout << "You have chosen poorly. Resubmit grade.\n";
        } else if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "You have chosen poorly. Resubmit grade.\n";
        } else if (score == -1){
            //do nothing
        } else {
            if( count >= 0 && count < AN_ABSURD_NUMBER){
                scores[count] = score;
                count++;
            } else {
                cout << "Array bounds exceeded.\n";
                break;
            }
        }
    }
}

void readDouble(char prompt[], double &num){
    bool loopState;
    int i;
    int length = sizeof(prompt) / sizeof(prompt[0]);

    for ( i  = 0; i < length; i++){
        cout << prompt[i];
    }
    cin >> num;
}

void calcGrades(double scores[], char grade[], int count){
    int i;

    for (i = 0; i < count; i++){
        if(scores[i] > 3.3 && scores[i] <= 4.0){
            grade[i] = 'A';
        } else if(scores[i] > 2.8 && scores[i] <= 3.3){
            grade[i] = 'B';
        } else if(scores[i] > 2.0 && scores[i] <= 2.8){
            grade[i] = 'C';
        } else if(scores[i] > 1.2 && scores[i] <= 2.0){
            grade[i] = 'D';
        } else {
            grade[i] = 'F';
        } 
    }
}

void printList(double scores[], char grades[], int count){
    int i;

    for (i = 0; i < count; i++){
        cout << fixed << setprecision(1) << scores[i] << " " << grades[i] << endl;
    }
}


