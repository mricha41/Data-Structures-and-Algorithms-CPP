#include <iostream>
#include <algorithm>
#include "Array.hpp"
#include "Algorithms.hpp"

int main()
{
    Array<10, const char*> myArray = {"a", "b", "c", "d", "e"};

    DisplayArray(myArray);

    myArray.Append("f");

    DisplayArray(myArray);

    myArray.Append("g");

    DisplayArray(myArray);

    myArray.Append("h");

    DisplayArray(myArray);

    myArray.Append("i");

    DisplayArray(myArray);

    myArray.Insert(2, "j");

    DisplayArray(myArray);

    //myArray.Append("k"); //fails assertion

    //DisplayArray(myArray);

    //myArray.Insert(-1, "k"); //fails assertion

    //DisplayArray(myArray);

    //myArray.Insert(99, "k"); //fails assertion

    //DisplayArray(myArray);

    myArray.clear();

    //DisplayArray(myArray); //fails assertion

    //std::cout<<"Found key? "<<
    //    LinearSearch<10, const char*>(myArray, "f")<<
    //    "\n\n"; // fails assertion

    myArray = {"h", "e", "l", "l", "o", "", "!"};

    DisplayArray(myArray);

    myArray.Remove(2);

    DisplayArray(myArray);

    //myArray[-1] = "m"; //fails assertion

    myArray[0] = "m";

    std::cout<<"front value: "<<myArray.Front()<<"\n\n";
    std::cout<<"back value: "<<myArray.Back()<<"\n\n";

    std::cout<<"Found key? "<<LinearSearch<10, const char*>(myArray, "h")<<"\n\n";

    std::cout<<"Found key? "<<LinearSearch<10, const char*>(myArray, "m")<<"\n\n";

    std::cout<<"Found key? "<<LinearSearchWithTransposition<10, const char*>(myArray, "h")<<"\n\n";

    std::cout<<"Found key? "<<LinearSearchWithTransposition<10, const char*>(myArray, "o")<<"\n\n";

    DisplayArray(myArray);

    std::cout<<"Found key? "<<LinearSearchMoveToFront<10, const char*>(myArray, "h")<<"\n\n";

    std::cout<<"Found key? "<<LinearSearchMoveToFront<10, const char*>(myArray, "l")<<"\n\n";

    DisplayArray(myArray);

    myArray = {"a", "b", "c", "d", "e", "f", "g"};

    DisplayArray(myArray);

    std::cout<<"Found key? "<<BinarySearch<10, const char*>(myArray, "f")<<"\n\n";

    DisplayArray(myArray);

    std::cout<<"Found key? "<<RecursiveBinarySearch<10, const char*>(myArray, 0, myArray.Size(), "f")<<"\n\n";

    DisplayArray(myArray);

    Array<12, int> myArray2 {4,1,8,3,9,2};

    DisplayArray(myArray2);

    myArray2.Insert(2, 5);

    DisplayArray(myArray2);

    myArray2.Append(0);

    DisplayArray(myArray2);

    myArray2.Append(23);

    DisplayArray(myArray2);

    myArray2.Append(55);

    DisplayArray(myArray2);

    myArray2.Insert(0, 35);

    DisplayArray(myArray2);

    myArray2.Append(99);

    DisplayArray(myArray2);

    //myArray2.Insert(4, 2000); //fails assertion
    //myArray2.Append(2000); //fails assertion

    //DisplayArray(myArray2);

    myArray2.clear();

    //DisplayArray(myArray2); //fails assertion

    myArray2 = {55, 9, 0, 37, 1000};

    DisplayArray(myArray2);

    //myArray2[-1] = 3254; //fails assertion

    myArray2[0] = 3254;

    DisplayArray(myArray2);

    std::cout<<"front value: "<<myArray2.Front()<<"\n\n";
    std::cout<<"back value: "<<myArray2.Back()<<"\n\n";

    std::cout<<"Found key? "<<LinearSearch<12, int>(myArray2, 55)<<"\n\n";

    std::cout<<"Found key? "<<LinearSearch<12, int>(myArray2, 1000)<<"\n\n";

    std::cout<<"Found key? "<<LinearSearchWithTransposition<12, int>(myArray2, 55)<<"\n\n";

    std::cout<<"Found key? "<<LinearSearchWithTransposition<12, int>(myArray2, 1000)<<"\n\n";

    DisplayArray(myArray2);

    std::cout<<"Found key? "<<LinearSearchMoveToFront<12, int>(myArray2, 55)<<"\n\n";

    std::cout<<"Found key? "<<LinearSearchMoveToFront<12, int>(myArray2, 1000)<<"\n\n";

    DisplayArray(myArray2);

    myArray2 = {0, 1, 2, 3, 4, 5, 6, 7};

    DisplayArray(myArray2);

    std::cout<<"Found key? "<<BinarySearch<12, int>(myArray2, 3)<<"\n\n";

    DisplayArray(myArray2);

    std::cout<<"Found key? "<<RecursiveBinarySearch<12, int>(myArray2, 0, myArray2.Size(), 3)<<"\n\n";

    DisplayArray(myArray2);

    auto minimum = myArray2.Min();
    std::cout<<"Min: "<<minimum<<"\n\n";

    auto maximum = myArray2.Max();
    std::cout<<"Max: "<<maximum<<"\n\n";

    auto [m,n] = myArray2.MinMax();
    std::cout<<"Min/Max: "<<m<<", "<<n<<"\n\n";

    Reverse(myArray);

    DisplayArray(myArray);

    Reverse(myArray2);

    DisplayArray(myArray2);

    myArray2 = {1, 3, 7, 10, 12, 16, 20, 26};

    DisplayArray(myArray2);

    myArray2.InsertionSort(8);

    DisplayArray(myArray2);

    std::cout<<"Sorted? "<<myArray2.IsSorted()<<"\n"<<std::endl;

    Reverse(myArray2);

    DisplayArray(myArray2);

    std::cout<<"Sorted? "<<myArray2.IsSorted()<<"\n"<<std::endl;

    myArray2 = {-1, 33, 7, -10, 2, 16, -20, 26};

    DisplayArray(myArray2);

    Rearrange(myArray2);

    DisplayArray(myArray2);

    std::cout<<"Sorted? "<<myArray2.IsSorted()<<"\n"<<std::endl;

    //merging...
    //all elements copied over
    Array<10, const char*> myArray3 = { "a", "b", "c", "d", "e" };
    //Array<10, int> myArray3 = { 2, 6, 10, 15, 25 };

    Array<20, const char*> myArray4 = {"f", "u", "c", "k"};
    //Array<10, int> myArray4 = { 3, 4, 7, 18, 20 };
    //Array<20, int> myArray5 = { 0, 0, 0, 0 };

    DisplayArray(myArray3);
    DisplayArray(myArray4);
    //DisplayArray(myArray5);

    myArray4 = Merge<20, 10, 10, const char*>(myArray, myArray3);
    //myArray5 = Merge<20, 10, 10, int>(myArray3, myArray4);

    DisplayArray(myArray4);
    //DisplayArray(myArray5);

    //demonstrate that Array.data() works...
    //int* ap = myArray5.data();
    const char** ap = myArray4.data();
    //for (std::size_t i = 0; i < myArray5.Size(); ++i)
    for (std::size_t i = 0; i < myArray4.Size(); ++i)
        std::cout << ap[i] << " ";
    
    std::cout << "\n" << std::endl;

    //only unique elements copied over
    Array<10, int> myArray6 = { 3, 4, 7, 18, 20 };
    Array<10, int> myArray7 = { 2, 4, 10, 18, 25 };
    Array<20, int> myArray8 = Union<20, 10, 10, int>(myArray6, myArray7);

    DisplayArray(myArray8);

    //only common elements copied over
    Array<10, int> myArray9 = { 2, 6, 10, 15, 25 };
    Array<10, int> myArray10 = { 3, 6, 7, 15, 20 };
    Array<20, int> myArray11 = Intersection<20, 10, 10, int>(myArray9, myArray10);

    DisplayArray(myArray11);

    //only unique elements of first array
    //in the comparison is copied over
    Array<10, int> myArray12 = { 2, 6, 10, 15, 25 };
    Array<10, int> myArray13 = { 3, 6, 7, 15, 20 };
    Array<20, int> myArray14 = Difference<20, 10, 10, int>(myArray12, myArray13);

    DisplayArray(myArray14);

    return 0;
}
