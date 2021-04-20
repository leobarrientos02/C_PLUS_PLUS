// Algorithm_HW10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>
 
using namespace std;

int findWays(int steps) {
    int* result = new int[steps + 1];
    int f = 0;
    // BASE CASES
    // Went up to three becasue the cat can hop up to three steps
    if (steps == 0) {
        f = 0;
    }
    else if (steps == 1) {
        f = 1;
    }
    else if (steps == 2) {
        f = 2;
    }
    else if (steps == 3) {
        f = 4;
    }
    else {
        // Recursively call findWays three times bc the cat can jump up to three steps
        f = findWays(steps - 1) + findWays(steps - 2) + findWays(steps - 3);
    }
    return result[steps] = f;
}

void Question_1() {
    int steps;
    std::cout << "Write a DP recursive solution to the following :\nA little kitten can hop a staircase either 1, 2, or 3 jumps at a time.\nWrite an algorithm that computes how many possible ways the kitten can hop up the stairs of size n.\nAnalyze the time complexity of your proposed solution.\n";
    std::cout << "\n";
    std::cout << "Stair's size:";
    std::cin >> steps;
    
    // See above to see the findWays algorithm
    std:: cout << "\nThere are " << findWays(steps) << " ways a kitten can hop " << steps << " steps.\n";
    std::cout << "Time Complexity: O(n)";
}

char findChar(string &str) {

    unordered_set<char>hash;
    
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (hash.find(c) != hash.end()) {
            return c;
        }
        else {
            hash.insert(c);
        }
    }
}


void Question_2() {
    std::cout << "Implement an efficient algorithm to check the first repeated character in a string.\nInput example: str1 = ABBFSA, or in  str2 = FEARE.\n";
    
    string str1 = "ABBFSA";
    string str2 = "FEARE";
    std::cout << "\nUsing str1 above the first repeated character is: ";
    std::cout << findChar(str1)<< "\n";
}

void findPair(int num[], int numSize) {
    int search = 21;
    for (int i = 0; i < numSize; i++) {
        for (int j = 1; j < numSize; j++) {
            int total = num[i] + num[j];

            if (total == search) {
                std::cout << num[i] << " + " << num[j] << " = " << search << "\n";
                return;
            }
        }
    }
    std::cout << "NO PAIRS\n";
}

void Question_3() {
   std::cout << "We have an array of numbers such as[-5, -2, 1, 3, 7, 9, 12, 17].\nWe need to find in this array a pair of numbers that have a certain sum such as  21.\nDiscuss the time complexity of your solution.\n\n";
    
   // NOTE: The array is already sorted
   int num[] = { -5, -2, 1, 3, 7, 9, 12, 17 };
   int size = sizeof(num) / sizeof(num[0]);

   // Please check the findPair function above for algorithm
   findPair(num, size);

   std::cout << "Time Complexity: O(n^2)\n";
  
}

// Created a class to make events
class event {
public:
    int startH;
    int endH;

    void setStartTime(int H) {
        startH = H;
    }
    void setEndTime(int H) {
        endH = H;
    }

    int getStartTimeH() {
        return startH;
    }
    int getEndTimeH() {
        return endH;
    }
    void print() {
        std::cout << startH << ": 00";
        std::cout << "     " << endH << ": 00";
    }
};


void Bonus() {
    std::cout << "Microsoft Booking is a popular software that can take two people's calendars and find the slots that are free between them\n during which both can have a meeting.\n";
    std::cout << "Write a program that reports the available times and analyzes the proposed solution.\n";
    std::cout << "Please note that O(n^2) is not an acceptable solution\n";
    std::cout << "You may assume that the calenders are like :\n";
    std::cout << "Calender1 = ['10:00, 11 : 00','13 : 00, 14 : 00']\n";
    std::cout << "Calender2 = ['09:00, 11 : 00', '12 : 00, 13 : 00','14:00, 15:00']\n";
    std::cout << "Daily bounds from 8 to 19\n";
    std::cout << "A meeting duration can be like 1 : 00\n";
    std::cout << "Return a list of availability in which the two can meet.\n\n";
    
    std::cout << "\nWORK IN PROGRESS";
}


void menu() {
    int choice;

    do {

        std::cout << std::endl;
        std::cout << "Please choose from the following options - \n";
        std::cout << " 1. QUESTION 1. \n";
        std::cout << " 2. QUESTION 2. \n";
        std::cout << " 3. QUESTION 3. \n";
        std::cout << " 4. BONUS QUESTION. \n";
        std::cout << " 5. Exit. \n";
        std::cout << "\nEnter Choice:";
        std::cin >> choice;
        std::cout << std::endl;
        if (choice == 1) {
            std::cout << "QUESTION 1\n";
            std::cout << "----------\n";
            Question_1();
            std::cout << "\n";
        }

        else if (choice == 2) {
            std::cout << "QUESTION 2\n";
            std::cout << "----------\n";
            Question_2();
            std::cout << "\n";
        }
        else if (choice == 3) {
            std::cout << "QUESTION 3\n";
            std::cout << "----------\n";
            Question_3();
            std::cout << "\n";

        }
        else if (choice == 4) {
            std::cout << "BONUS QUESTION\n";
            std::cout << "--------------\n";
            Bonus();
            std::cout << "\n";
        }
        else if (choice == 5) {
            std::cout << "EXIT" << std::endl;
            std::cout << std::endl;
        }
        else {
            // Test if the user enter valid choices
            std::cout << "Invalid Choice, Try Again" << std::endl;
            std::cout << std::endl;
        }
    } while (choice != 5);
}

int main()
{
 
    //std::cout << "Hello World!\n";
    menu();
}