/*
 * Course: COEN 2220 - Programming 2
 * Name: [Jose A Vera Guagua]
 * Lab: Lab 6 - Class Templates
 * Description: Generic metric log practice and ADT contract
 * Due date: [9/24/2026]
 */

#include <iostream>
using namespace std;

/*
 * MetricLog ADT
 *
 * Data:
 * [Complete in Part E: describe the values managed by this log.]
 *
 * Operations:
 * [Complete in Part E: describe add(value).]
 * [Complete in Part E: describe get(index) and its precondition.]
 * [Complete in Part E: describe contains(target).]
 * [Complete in Part E: describe size() and isEmpty().]
 */

template <typename T>
class MetricLog
{
private:
    // ===== Resolve these TODOs now (Part C) =====

    // TODO (Part C): Add a constant for a fixed capacity of four values.
    // TODO (Part C): Add an array that stores values of the generic type.
    // TODO (Part C): Add an int that tracks how many values are stored.
    static const int CAPACITY = 4;
    T values[CAPACITY];
    int count;

public:
    // TODO (Part C): Write a constructor that creates an empty log.
    MetricLog(){
        count = 0;
    }

    // TODO (Part C): Write add. It receives one generic value by const reference.
    // Return false when the log has no remaining capacity.
    bool add(const T& value){
        if (count == CAPACITY) {
            return false; // Reject a value when the fixed array is full.
        }
        values[count] = value;
        count++;
        return true;
    }

    // TODO (Part C): Write get. It receives a valid index and returns its stored value.
    T get(int index) const {
        // Precondition: index is between 0 and count - 1.
        return values[index];
    }
    // TODO (Part C): Write size as a const member function.
    int size() const {
        return count;
    }

    // TODO (Part C): Write isEmpty as a const member function.
    bool isEmpty() const {
        return count == 0;
    }

    bool contains(const T& target) const;
};

// ===== Do not resolve these TODOs yet (Part D) =====

// TODO (Part D): Define MetricLog<T>::contains outside the class.
// It receives a generic target by const reference.
// Return true when an equal stored value exists; otherwise return false.

template <typename T>
bool MetricLog<T>::contains(const T& target) const
{
    for (int i = 0; i < count; i++)
    {
        if (values[i] == target)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    MetricLog<int> waitlistCounts;

    waitlistCounts.add(6);
    waitlistCounts.add(11);

    cout << "First waitlist count: "
         << waitlistCounts.get(0) << endl;
    cout << "Stored waitlist counts: "
         << waitlistCounts.size() << endl;

    // ===== Do not resolve these TODOs yet (Part E) =====

    // TODO (Part E): Create a MetricLog<double> for session durations.
    // TODO (Part E): Add two dummy duration values to that log.
    // TODO (Part E): Use contains with one value that exists and one that does not exist.
    // TODO (Part E): Print descriptive English labels for all results.

    return 0;
}