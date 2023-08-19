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
void readDouble(const char prompt[], double &num);
void calcGrades(double scores[], char grade[], int count);
void printList(double scores[], char grades[], int count);
void sort(double scores[], char grades[], int count);
double median(double scores[], int count);

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
    cout << endl
         << "The median score is: " << median(scores, count) << endl;

    system("pause");
    return 0;
}

// prints welcome message
void welcome()
{
    cout << endl
         << "Welcome to my Parallel Arrays program!\n"
         << "Please enter the list of scores (-1 to end the input): \n"
         << "Valid scores are between 0 and 4 inclusive.\n";
}

// read in score values as double and stores them in an array
// increments count as a pointer to the array
void readScores(double scores[], int &count)
{
    double score;
    count = 0;

    // loop until user enters -1
    while (score != -1)
    {
        readDouble(">> ", score);
        if (score < -1 || score > 4)
        {
            // display error is score is < -1 or > 4
            cout << "You have chosen poorly. Resubmit grade.\n";
        }
        else if (cin.fail())
        {
            // if user enters anything that isn't a number
            // clear and ignore input
            cin.clear();
            cin.ignore();
            cout << "You have chosen poorly. Resubmit grade.\n";
        }
        else if (score == -1)
        {
            // do nothing
        }
        else
        {
            // while count is between 0 and AN_ABSURD_NUMBER
            // add number to the array and increment count
            if (count >= 0 && count < AN_ABSURD_NUMBER)
            {
                scores[count] = score;
                count++;
            }
            else
            {
                // error out of bounds
                cout << "Array bounds exceeded.\n";
                break;
            }
        }
    }
}

void readDouble(const char prompt[], double &num)
{
    cout << prompt;
    cin >> num;
}

void calcGrades(double scores[], char grade[], int count)
{
    int i;

    // basic grading rubric, read the data in the score array
    // and then save the letter grade in the corrisponding location
    // in the grade array
    for (i = 0; i < count; i++)
    {
        if (scores[i] > 3.3 && scores[i] <= 4.0)
        {
            grade[i] = 'A';
        }
        else if (scores[i] > 2.8 && scores[i] <= 3.3)
        {
            grade[i] = 'B';
        }
        else if (scores[i] > 2.0 && scores[i] <= 2.8)
        {
            grade[i] = 'C';
        }
        else if (scores[i] > 1.2 && scores[i] <= 2.0)
        {
            grade[i] = 'D';
        }
        else
        {
            grade[i] = 'F';
        }
    }
}

void printList(double scores[], char grades[], int count)
{
    int i;

    // print scores and grades arrays in parallel
    // set precision to 1 floating point.
    for (i = 0; i < count; i++)
    {
        cout << fixed << setprecision(1) << scores[i] << " " << grades[i] << endl;
    }
}

void sort(double scores[], char grades[], int count)
{
    int i, j;

    // sorts array from least to greatest
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            // if score[j] is less than score[j+1]
            if (scores[j] > scores[j + 1])
            {
                // set tempScore = to scores[j] and tempGrade = grades[j]
                double tempScore = scores[j];
                char tempGrade = grades[j];

                scores[j] = scores[j + 1];
                grades[j] = grades[j + 1];

                scores[j + 1] = tempScore;
                grades[j + 1] = tempGrade;
            }
        }
        // repeat until sorted
    }
}

double median(double scores[], int count)
{
    return scores[count / 2];
}
