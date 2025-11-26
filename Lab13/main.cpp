#include <iostream>
#include <vector>

// BUGGY VERSION from the lab
bool fail_lecture_buggy(const std::vector<int>& attendance_records) {
    int absent_count = 0;
    for (int i = 1; i < (int)attendance_records.size(); ++i) {
        absent_count += (attendance_records[i] == 0);
    }
    return absent_count >= 3;
}

// CORRECT VERSION for comparison
bool fail_lecture_correct(const std::vector<int>& attendance_records) {
    int absent_count = 0;
    for (int i = 0; i < (int)attendance_records.size(); ++i) {
        if (attendance_records[i] == 0) {
            ++absent_count;
        }
    }
    return absent_count >= 3;
}

void run_test(const std::string& name, const std::vector<int>& attendance) {
    bool expected = fail_lecture_correct(attendance);
    bool actual   = fail_lecture_buggy(attendance);

    std::cout << name << ":\n  Attendance: ";
    for (int v : attendance) std::cout << v << " ";
    std::cout << "\n  Expected (correct): " << (expected ? "FAIL" : "PASS")
              << "\n  Buggy function:     " << (actual   ? "FAIL" : "PASS")
              << "\n\n";
}

int main() {
    // Q3 test: executes fault, no error state, no failure
    std::vector<int> tc3 = {1, 0, 0, 0, 1, 1, 1, 1, 1, 1};

    // Q4 test: error state but no failure
    std::vector<int> tc4 = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1};

    // Q5 test: failure
    std::vector<int> tc5 = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1};

    run_test("Q3 test", tc3);
    run_test("Q4 test", tc4);
    run_test("Q5 test", tc5);

    return 0;
}