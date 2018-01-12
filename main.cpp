#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
#define TIME_TYPE toupper(input[input.length() - 1])

///  Prototype
/// ---------------------------------------///
/**/ string getInput();                    ///
/**/ void checkIfInpuIsExit(string input); ///
/// ---------------------------------------///

/// Main Application
/// ---------------------
int main() {
    /// ------------------///
    /// Initialization    ///
    /// ------------------///
    /**/ string input;    ///
    /**/ int n;           ///
    /**/ int w, d, h, m;  /// Week(s), Day(s), Hour(s), Minute(s)
    /// ------------------///

    /// Sets time initially to zero
    /// ----------------------------///
    /**/ w = 0;                     ///
    /**/ d = 0;                     ///
    /**/ h = 0;                     ///
    /**/ m = 0;                     ///
    /// ----------------------------///

    /// This is where the addition of things begin...
    /// -----------------------------------------------------
    do {
        input = getInput();
        n = atoi(input.c_str());
        switch (TIME_TYPE) {
        case 'W':
            w += n;
            break;
        case 'D':
            d += n;
            break;
        case 'H':
            h += n;
            break;
        case 'M':
            m += n;
            break;
        }
        w += d / 5;
        d += h / 8;
        h += m / 60;
        d = d % 5;
        h = h % 8;
        m = m % 60;
        cout << "sum: "
            << w << "w "
            << d << "d "
            << h << "h "
            << m << "m " << endl;
    } while (true);
    /// -----------------------------------------------------

    return 0; // Unreachable statement...
}

/// Gets user input
/// -------------------------
string getInput() {
    /// --------------------------///
    /// Initialization            ///
    /// --------------------------///
    /**/ string input;            ///
    /**/ bool inputIsBad = true;  ///
    /// --------------------------///

    /// Begin retrieving and validating the input ///
    /// ------------------------------------------///
    do {
        cout << "Enter a time (-1 to exit): ";
        cin >> input;
        char type = toupper(input[input.length() - 1]);
        inputIsBad = inputIsBad && type != 'W';
        inputIsBad = inputIsBad && type != 'D';
        inputIsBad = inputIsBad && type != 'H';
        inputIsBad = inputIsBad && type != 'M';
        checkIfInpuIsExit(input);
        if (inputIsBad) {
            cout << "Please enter a valid time. Valid time is: 5d or 3h or 20m, something like that..." << endl;
        }
    } while (inputIsBad);
    /// ------------------------------------------///

    return input; // Our precious input
}

/// Checks whether an input tells the program to exit.
/// -------------------------
void checkIfInpuIsExit(string input) {
    if (atoi(input.c_str()) < 0) {
        exit(0);
    }
}

