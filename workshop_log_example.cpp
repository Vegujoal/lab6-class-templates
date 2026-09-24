/*
 * Course: COEN 2220 - Programming 2
 * Name: [Jose A Vera Guagua]
 * Lab: Lab 6 - Class Templates
 * Description: Guided example - a generic workshop metric log
 * Due date: [9/24/2026]
 */

#include <iostream>
using namespace std;

template <typename T>
class WorkshopLog
{
private:
    static const int CAPACITY = 4;
    T values[CAPACITY];       // Store values of the selected type.
    int count;                // Track how many positions contain data.

public:
    WorkshopLog()
    {
        count = 0;            // A new log starts with no stored values.
    }

    int size() const
    {
        return count;         // Report how many values are currently stored.
    }

    bool isEmpty() const
    {
        return count == 0;    // A log is empty only when it stores no values.
    }

    // --- STEP 2: Add a generic value ---
    // TODO (Step 2): Paste the add member function here.
    bool add(const T& value)
    {
        if (count == CAPACITY)
        {
        return false;     // Reject a value when the fixed array is full.
        }

        values[count] = value;
        count++;
        return true;
    }
    // --- STEP 3: Store a second metric type ---
    // TODO (Step 3): Paste the get member function here.
    T get(int index) const
    {
        // Precondition: index is between 0 and count - 1.
        return values[index];
    }

};

int main()
{
    cout << boolalpha;        // Print bool values as true or false.

    WorkshopLog<int> attendanceCounts;

    cout << "Attendance records: " << attendanceCounts.size() << endl;
    cout << "Log is empty: " << attendanceCounts.isEmpty() << endl;

    // --- STEP 2: Add attendance counts ---
    // TODO (Step 2): Paste the attendance test code here.
    attendanceCounts.add(32);
    attendanceCounts.add(47);

    cout << "Attendance records: " << attendanceCounts.size() << endl;
    // --- STEP 3: Create a log for ratings ---
    // TODO (Step 3): Paste the rating test code here.
    WorkshopLog<double> workshopRatings;

    workshopRatings.add(4.25);
    workshopRatings.add(4.75);

    cout << "First workshop rating: "
    << workshopRatings.get(0) << endl;
    cout << "Second workshop rating: "
    << workshopRatings.get(1) << endl;

    return 0;
}