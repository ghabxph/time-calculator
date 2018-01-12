/**
 * Copyright 2017 ghabxph(c)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *
 * @version 0.0.1
 * @author  ghabxph <ghabxph.official@gmail.com>
 */
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

