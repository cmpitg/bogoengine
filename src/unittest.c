/*

  This file is a part of bogoengine project.

  Copyright (C) 2012-2013 Duong H. Nguyen <cmpitgATgmaildotcom>

  bogoengine is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  bogoengine is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "unittest.h"

/* ----------------------------------------------------------------------- */
/* Helpers */

void toStrLower (const char *source, char *output) {
    int i, len;
    len = strlen (source);
    for(i = 0; i < len; i++) {
        output[i] = tolower (source[i]);
    }
    output[len] = 0;
}

/* ----------------------------------------------------------------------- */
/* Main */

void addTest (testcase_t *testcase) {
    _tests_[_nTests_++] = testcase;
}

void removeLastTest (void) {
    if (_nTests_ > 0) {
        _nTests_--;
    }
}

int runTest (testcase_t *testcase) {
    static int i;
    for (i = 0; i < _nTests_; i++)
        if (_tests_[i] == testcase) {
            return _tests_[i] ();
        }
    return 0;
}

int runTestNth (int pos) {
    if (_nTests_ <= pos) {
        return 0;
    } else {
        return _tests_[pos] ();
    }
}

int runAllTests (void) {
    static int i;
    int allRes = 0;
    int res;

    for (i = 0; i < _nTests_; i++) {
        res = _tests_[i] ();
        allRes += res;
        if (res == 0) {
            fprintf (stderr, "> Failed!\n");
            return allRes;
        }
    }

    printf ("> All passed!\n");
    return allRes;
}

void initTestCase (const char *testName) {
    strcpy (_currentTestName_, testName);
    _currentRes_ = 1;
    fprintf (stdout, ">> Testing '%s'\n", _currentTestName_);
}

int finishTestCase (void) {
    if (_currentRes_ == 1) {
        fprintf (stdout, ">> Passed!\n\n");
    } else {
        fprintf (stderr, ">> Failed!\n\n");
    }
    return _currentRes_;
}

void assertInt (int expected, int expr) {
    /* Skip if there is a failed test already */
    if (_currentRes_ == 0) {
        return;
    }

    _currentRes_ = (expected == expr) ? 1 : 0;
    if (_currentRes_ == 0) {
        fprintf (stderr, "[failed] assertInt\n\texpected: %i\n\tactual: %i\n",
                 expected, expr);
    }
}

void assertIntDescription (int expected, int expr, const char *descr) {
    /* Skip if there is a failed test already */
    if (_currentRes_ == 0) {
        return;
    }

    _currentRes_ = (expected == expr) ? 1 : 0;
    if (_currentRes_ == 0) {
        fprintf (stderr,
                 "[failed] assertInt: %s\n\texpected: %i\n\tactual: %i\n",
                 descr,
                 expected,
                 expr);
    }
}

void assertStr (const char *expected, const char *expr) {
    /* Skip if there is a failed test already */
    if (_currentRes_ == 0) {
        return;
    }

    _currentRes_ = (strcmp (expected, expr) == 0) ? 1 : 0;
    if (_currentRes_ == 0) {
        fprintf (stderr, "[failed] assertInt\n\texpected: %s\n\tactual: %s\n",
                 expected, expr);
    }
}

void assertStrDescription
(const char *expected, const char *expr, const char *descr) {
    /* Skip if there is a failed test already */
    if (_currentRes_ == 0) {
        return;
    }

    _currentRes_ = (strcmp (expected, expr) == 0) ? 1 : 0;
    if (_currentRes_ == 0) {
        fprintf (stderr,
                 "[failed] assertInt: %s\n\texpected: %s\n\tactual: %s\n",
                 descr,
                 expected,
                 expr);
    }
}

void assertStrI (const char *expected, const char *expr) {
    /* Skip if there is a failed test already */
    if (_currentRes_ == 0) {
        return;
    }

    char lowerExpected[_MAX_STRLEN];
    char lowerexpr[_MAX_STRLEN];

    toStrLower (expected, lowerExpected);
    toStrLower (expr, lowerexpr);

    _currentRes_ = (strcmp (lowerExpected, lowerexpr) == 0) ? 1 : 0;
    if (_currentRes_ == 0) {
        fprintf (stderr, "[failed] assertInt\n\texpected: %s\n\tactual: %s\n",
                 expected, expr);
    }
}
