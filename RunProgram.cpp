#include "RunProgram.h"
#include <iostream>

using namespace std;

RunProgram::RunProgram()
{

}

void RunProgram::getUserOption()
{
    char ch = '\0';
    while (ch != 'q') {
        printMenu();
        dashed_line();
        cout << "Choose from 1 to 6 or 'q' to exit: ";
        cin >> ch;
        dashed_line();
        switch (ch) {
        case '1':
            printAllDates();
            break;
        case '2':
            addDate();
            break;
        case '3':
            substractDate();
            break;
        case'4':
            compareDate();
            break;
        case '5':
            assignDate();
            break;
        case '6':
            addTwoDates();
            break;
        default:
            if (ch == 'q') cout << "\n" << "Leaving the Program, thank you! " << endl;
            else cout << "Invalid input, please try again. " << endl;
            dashed_line();
        }
    }
}

void RunProgram::dashed_line()
{

    cout << "----------------------------------------" << endl;
}


void RunProgram::addDate()
{
    if (numofelems < 10)
    {
        int day, month, year;

        do
        {
            cout << "Enter day: ";
            cin >> day;

            if (cin.fail() || day < 0 || day > 31)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Invalid input. Please enter a non-negative integer for day." << endl;
            }
            else
            {
                break;
            }
        } while (true);

        do
        {
            cout << "Enter month: ";
            cin >> month;

            if (cin.fail() || month < 0 || month > 12)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Invalid input. Please enter an integer between 1 and 12 for month." << endl;
            }
            else
            {
                break;
            }
        } while (true);

        do
        {
            cout << "Enter year: ";
            cin >> year;

            if (cin.fail() || year < 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Invalid input. Please enter an integer number." << endl;
            }
            else
            {
                break;
            }
        } while (true);

        Date newDate(day, month, year);

        dateArr[numofelems++] = newDate;
        cout << "Date added successfully." << endl;
        dashed_line();
    }
    else
    {
        cerr << "Maximum number of dates reached (10). Cannot add more dates." << endl;
    }
}


void RunProgram::printMenu()
{
    cout << "1. Print all dates. " << endl;
    cout << "2. Add new date. " << endl;
    cout << "3. Subtract date from date. " << endl;
    cout << "4. Compare dates. " << endl;
    cout << "5. Assing dates. " << endl;
    cout << "6. Add two dates. " << endl;
}

void RunProgram::printAllDates()
{
    if (numofelems == 0)
    {
        cout << "No date added." << endl;
    }
    else
    {
        cout << "List of all Dates:\n";
        for (int i = 0; i < numofelems; i++) {
            cout << "Date " << i + 1 << ": " << endl;
            cout << "Day - " << dateArr[i].getDay() << endl;
            cout << "Month - " << dateArr[i].getMonth() << endl;
            cout << "Year - " << dateArr[i].getYear() << endl;
            dashed_line();
        }
    }
}

void RunProgram::substractDate()
{
    if (numofelems < 2)
    {
        cout << "Insufficient dates to perform subtraction. Please add at least two dates." << endl;
        return;
    }

    int date1Index, date2Index;


    do
    {
        cout << "Enter the index of the first date to subtract from (1 - " << numofelems << "): ";
        cin >> date1Index;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please enter an integer index." << endl;
        }
        else
        {
            break;
        }
    } while (true);


    do
    {
        cout << "Enter the index of the second date to subtract (1 - " << numofelems << "): ";
        cin >> date2Index;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please enter an integer index." << endl;
        }
        else
        {
            break;
        }
    } while (true);

    if (date1Index >= 1 && date1Index <= numofelems && date2Index >= 1 && date2Index <= numofelems)
    {
        Date result = dateArr[date1Index - 1] - dateArr[date2Index - 1];

        cout << "Result of subtraction:" << endl;
        cout << "Days - " << result.getDay() << endl;
        cout << "Month - " << result.getMonth() << endl;
        cout << "Years - " << result.getYear() << endl;
        dashed_line();
    }
    else
    {
        cerr << "Invalid indices entered. Please enter indices between 1 and " << numofelems << "." << endl;
    }
}


void RunProgram::compareDate()
{
    if (numofelems == 0)
    {
        cout << "No date added. Cannot compare dates." << endl;
        return;
    }

    int date1Index, date2Index;

    do
    {
        cout << "Enter the index of the first date (1 - " << numofelems << "): ";
        cin >> date1Index;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please enter an integer index." << endl;
        }
        else
        {
            break;
        }
    } while (true);



    do
    {
        cout << "Enter the index of the second date (1 - " << numofelems << "): ";
        cin >> date2Index;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please enter an integer index." << endl;
        }
        else
        {
            break;
        }
    } while (true);

    if (date1Index >= 1 && date1Index <= numofelems && date2Index >= 1 && date2Index <= numofelems)
    {
        if (dateArr[date1Index - 1] == dateArr[date2Index - 1])
        {
            cout << "The dates are equal." << endl;
        }
        else
        {
            cout << "The dates are not equal." << endl;
        }
    }
    else
    {
        cerr << "Invalid indices entered. Please enter indices between 1 and " << numofelems << "." << endl;
    }
}



void RunProgram::assignDate()
{
    if (numofelems < 2)
    {
        cout << "Insufficient dates to perform assignment. Please add at least two dates." << endl;
        return;
    }

    int sourceIndex, destinationIndex;

    do
    {
        cout << "Enter the index of the source date (1 - " << numofelems << "): ";
        cin >> sourceIndex;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please enter an integer index." << endl;
        }
        else
        {
            break;
        }
    } while (true);

    do
    {
        cout << "Enter the index of the destination date (1 - " << numofelems << "): ";
        cin >> destinationIndex;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please enter an integer index." << endl;
        }
        else
        {
            break;
        }
    } while (true);


    if (sourceIndex >= 1 && sourceIndex <= numofelems && destinationIndex >= 1 && destinationIndex <= numofelems)
    {
        dateArr[destinationIndex - 1] = dateArr[sourceIndex - 1];

        cout << "date assigned successfully." << endl;
        dashed_line();
    }
    else
    {
        cerr << "Invalid indices entered. Please enter indices between 1 and " << numofelems << "." << endl;
    }
}


void RunProgram::addTwoDates()
{
    if (numofelems < 2)
    {
        cout << "Insufficient dates to perform addition. Please add at least two dates." << endl;
        return;
    }

    int date1Index, date2Index;

    do
    {
        cout << "Enter the index of the source date (1 - " << numofelems << "): ";
        cin >> date1Index;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please enter an integer index." << endl;
        }
        else
        {
            break;
        }
    } while (true);

    do
    {
        cout << "Enter the index of the destination date (1 - " << numofelems << "): ";
        cin >> date2Index;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please enter an integer index." << endl;
        }
        else
        {
            break;
        }
    } while (true);

    if (date1Index >= 1 && date1Index <= numofelems && date2Index >= 1 && date2Index <= numofelems)
    {
        Date result = dateArr[date1Index - 1] + dateArr[date2Index - 1];

        cout << "Result of addition:" << endl;
        cout << "Day - " << result.getDay() << endl;
        cout << "Month - " << result.getMonth() << endl;
        cout << "Years - " << result.getYear() << endl;
        dashed_line();
    }
    else
    {
        cerr << "Invalid indices entered. Please enter indices between 1 and " << numofelems << "." << endl;
    }
}
