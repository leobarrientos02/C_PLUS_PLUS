#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

void performaceTime(clock_t bc) {
    // Performance time
    std::cout << "\nPerformance time:" << std::endl;
    std::cout << float(clock() - bc) / CLOCKS_PER_SEC << " seconds\n";
}

void printUnsortedArray(int numbers[]) {

    std::cout << "UNSORTED ARRAY" << std::endl;
    std::cout << "--------------" << std::endl;

    for (int i = 0; i < 25; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

void printSortedArray(int numbers[]) {

    std::cout << "SORTED ARRAY" << std::endl;
    std::cout << "------------" << std::endl;

    for (int i = 0; i < 25; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}


void random_shuffle(int numbers[], int numbersSize) {
    
    int temp;
    srand(time(0));
    
    for (int i = numbersSize -1; i > 0; i--) {
        
        // Pick a random index
        int j = rand() % (i + 1);

        // Swap numbers[i] with a random array position
        temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}

void selectionSort(int numbers[], int numbersSize) {

    printUnsortedArray(numbers);

    std::cout << std::endl;

    int i = 0;
    int j = 0;
    int indexSmallest = 0;

    // Temp variable for swap
    int temp = 0;

    for (; i < numbersSize - 1; i++) {

        // Find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < numbersSize; ++j) {

            if (numbers[j] < numbers[indexSmallest]) {
                indexSmallest = j;
            }
        }

        // Swap numbers[i] and numbers[indexSmallest]
        temp = numbers[i];
        numbers[i] = numbers[indexSmallest];
        numbers[indexSmallest] = temp;
    }

    printSortedArray(numbers);
}

void insertionSort(int numbers[], int numbersSize) {

    printUnsortedArray(numbers);

    std::cout << std::endl;

    int i = 0;
    int temp = 0;
    int j = 0;

    for (i = 1; i < numbersSize; i++) {
        j = i;
        // Insert numbers[i] into sorted part
        // stopping once numbers[i] in correct position
        while (j > 0 && numbers[j] < numbers[j - 1]) {

            // Swap numbers
            temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            --j;
        }
    }
    printSortedArray(numbers);
}


void bubbleSort(int numbers[], int numbersSize) {
    
    printUnsortedArray(numbers);
    std::cout << std::endl;

    int temp=0;

    for (int i = 0; i < numbersSize-1; i++) {
        for (int j = 0; j < numbersSize - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    printSortedArray(numbers);

}

void mergeSort();

//QuickSort
int Partition(int numbers[], int lowIndex, int highIndex) {

    // Pick middle elememt
    int midPoint = lowIndex + (highIndex - lowIndex) / 2;
    int pivot = numbers[midPoint];
    int temp;

    bool done = false;

    while (!done) {
        // Increment lowIndex while numbers[lowIndex] < pivot
        while (numbers[lowIndex] < pivot) {
            lowIndex += 1;
        }

        // Decrement highIndex while pivot < numbers[highIndex]
        while (pivot < numbers[highIndex]) {
            highIndex -= 1;
        }

        // If zero or one elements remain, then all numbers are 
        // partitioned. Return highIndex.
        if (lowIndex >= highIndex) {
            done = true;
        }
        else {
            // Swap numbers[lowIndex] and numbers[highIndex]
            temp = numbers[lowIndex];
            numbers[lowIndex] = numbers[highIndex];
            numbers[highIndex] = temp;
        
            // Update lowIndex and highIndex
            lowIndex += 1;
            highIndex -= 1;
        }
    }
    return highIndex;
}

int * quickSort(int numbers[], int lowIndex, int highIndex) {

    // Base case: If the partition size is 1 or zero 
    // elements, then the partition is already sorted
    if (lowIndex >= highIndex) {
        return numbers;
    }

    int lowEndIndex = Partition(numbers, lowIndex, highIndex);

    quickSort(numbers, lowIndex, lowEndIndex);
    quickSort(numbers, lowEndIndex + 1, highIndex);

}


//Heap Sort
int* MaxHeapPercolateDown(int nodeIndex, int numbers[], int numbersSize) {

    int childIndex = 2 * nodeIndex + 1;
    int value = numbers[nodeIndex];
    int maxValue;
    int maxIndex;
    int temp;

    while (childIndex < numbersSize) {
        maxValue = value;
        maxIndex = -1;
        for (int i = 0; i < 2 && i + childIndex < numbersSize; i++) {
            if (numbers[i + childIndex] > maxValue) {
                maxValue = numbers[i + childIndex];
                maxIndex = i + childIndex;
            }
        }
        if (maxValue == value) {
            return numbers;
        }
        else {
            temp = numbers[nodeIndex];
            numbers[nodeIndex] = numbers[maxIndex];
            numbers[maxIndex] = temp;
            nodeIndex = maxIndex;
            childIndex = 2 * nodeIndex + 1;
        }
    }
}
void heapSort(int numbers[], int numbersSize) {
    int temp;

    // Heapify numbers array
    for (int i = numbersSize / 2 - 1; i >= 0; i--) {
        MaxHeapPercolateDown(i, numbers, numbersSize);
    }

    for (int i = numbersSize - 1; i > 0; i--) {
   
        temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        MaxHeapPercolateDown(0, numbers, i);
    }
}

void menu() {

    int choice;

    // For new numbers
    /* srand(time(0)); */

    int numbers[1000] = {};

    // Populates numbers with random numbers
    for (int i = 0; i < 1000; i++) {
        // Random numbers between 0 and 1000
        numbers[i] = (rand() % 1000 + 1);
    }

    // Get numbers size
    int numbersSize = sizeof(numbers) / sizeof(numbers[0]);

    do {

        std::cout << std::endl;
        std::cout << "Please choose from the following options - \n";
        std::cout << " 1. Selection Sort. \n";
        std::cout << " 2. Insertion Sort. \n";
        std::cout << " 3. Bubble Sort. \n";
        std::cout << " 4. Merge Sort. \n";
        std::cout << " 5. Quick Sort. \n";
        std::cout << " 6. Heap Sort. \n";
        std::cout << " 7. Exit. \n";
        std::cout << "\nEnter Choice:";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 1) {

            random_shuffle(numbers, numbersSize);
            std::cout << "SELECTION SORT\n";
            std::cout << "--------------\n";
            std::cout << "" << std::endl;

            const clock_t ac = clock();
            selectionSort(numbers, numbersSize);

            performaceTime(ac);
        }

        else if (choice == 2) {
            random_shuffle(numbers, numbersSize);
            std::cout << "INSERTION SORT\n";
            std::cout << "--------------\n";
            std::cout << "" << std::endl;

            const clock_t bc = clock();
            insertionSort(numbers, numbersSize);
            performaceTime(bc);
        }
        else if (choice == 3) {
            
            random_shuffle(numbers, numbersSize);
            std::cout << "BUBBLE SORT\n";
            std::cout << "-----------\n";
            std::cout << "" << std::endl;

            const clock_t cc = clock();
            bubbleSort(numbers, numbersSize);
            performaceTime(cc);
        }
        else if (choice == 4) {
            random_shuffle(numbers, numbersSize);
            std::cout << "MERGE SORT\n";
            std::cout << "----------\n";
            std::cout << "" << std::endl;
            const clock_t dc = clock();
            performaceTime(dc);
        }
        else if (choice == 5) {
            
            random_shuffle(numbers, numbersSize);
            std::cout << "QUICK SORT\n";
            std::cout << "----------\n";
            std::cout << "" << std::endl;

            const clock_t ec = clock();
            printUnsortedArray(numbers);
            std::cout << std::endl;

            quickSort(numbers, 0, numbersSize - 1);

            printSortedArray(numbers);
            performaceTime(ec);
        }
        else if (choice == 6) {
           
            random_shuffle(numbers, numbersSize);
            std::cout << "HEAP SORT\n";
            std::cout << "---------\n";
            std::cout << "" << std::endl;

            const clock_t fc = clock();
            printUnsortedArray(numbers);
            std::cout << std::endl;

            heapSort(numbers, numbersSize);

            printSortedArray(numbers);
            performaceTime(fc);
        }
        else if (choice == 7) {

            std::cout << "EXIT" << std::endl;
            std::cout << std::endl;
        }
        else {
            // Test if the user enter valid choices
            std::cout << "Invalid Choice, Try Again" << std::endl;
            std::cout << std::endl;
        }

    } while (choice != 7);
}

int main() {

    menu();

    // Program time
    /* const clock_t bc = clock(); */
    /* std::cout << float(clock() - bc) / CLOCKS_PER_SEC << "sec"; */

    return 0;
}