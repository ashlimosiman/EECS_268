/**
*File: main.cpp
*Author: Ashli Mosiman
*KUID Number: 2819456
*Date Last Updated: April 18,2016
*Purpose: calling five different sorting methods on three different order types of an array of assigned value
*           will take in the size, order type, and sort type from the command line
*           Times the length of time to fully sort the array given
*           Prints size, order type, sort type, and resulting time length
**/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "bubbleSort.cpp"
#include "insertionSort.cpp"
#include "mergesort.cpp"
#include "quicksort.cpp"
#include "selectionSort.cpp"

int main(int argc, char* argv[])
{
    int size=atoi(argv[1]);//size of the array
    std::string initOrder=argv[2];//original order of the array
    std::string sortType=argv[3];//sort type to use

    //throws error and ends the program when the size is not large enough
    if(size < 50000)
    {
        std::cout<<"Error: Size Too Small.\n";
        return(0);
    }
    else if((size < 500000) && ((sortType == "quick") || (sortType == "merge")))
    {
        std::cout<<"Error: Size Too Small.\n";
        return(0);
    }
    else if((size < 500000) && (((sortType == "bubble") || (sortType == "insertion")) && ((initOrder == "ascend"))))
    {
        std::cout<<"Error: Size Too Small.\n";
        return(0);
    }



    double* mainStan=new double[size];//array filled with values and sorted
    double* tempTammy=new double[size];//temporary array for merge
    int x=0;//for the for loops
    clock_t timeVal;//variable to time the sort
    double length;//final time after conversion


    std::cout<<"size: "<<size<<"\nOrder: "<<initOrder<<"\nType: "<<sortType<<'\n';

    if(initOrder == "random")//original order is random
    {
        //populating array with random values
        srand48(1);
        for(x=0; x < size; x++)
        {
            mainStan[x]=(drand48()*100000);
        }

        if(sortType == "bubble")//use bubble sort
        {
            timeVal=clock();
            bubbleSort(mainStan, size);//call sort
            timeVal=clock()-timeVal;
            length=timeVal/(double) CLOCKS_PER_SEC;//converting
            std::cout<<"Result: "<<length<<"\n";//prints final time value
        }
        else if(sortType == "insertion")//use insertion sort
        {
            timeVal=clock();
            insertionSort(mainStan, size);//call sort
            timeVal=clock()-timeVal;
            length=timeVal/(double) CLOCKS_PER_SEC;//converting
            std::cout<<"Result: "<<length<<"\n";//prints final time value
        }
        else if(sortType == "merge")//use merge sort
        {
            timeVal=clock();
            merge(mainStan, 0, (size/2), (size-1), tempTammy);//calls sort
            timeVal=clock()-timeVal;
            length=timeVal/(double) CLOCKS_PER_SEC;//converting
            std::cout<<"Result: "<<length<<"\n";//prints final time value
        }
        else if(sortType == "quick")//use quick sort
        {
            timeVal=clock();
            quickSort(mainStan, 0, (size-1));//call sort
            timeVal=clock()-timeVal;
            length=timeVal/(double) CLOCKS_PER_SEC;//converting
            std::cout<<"Result: "<<length<<"\n";//prints final time value
        }
        else if(sortType == "selection")//use selection sort
        {
            timeVal=clock();
            selectionSort(mainStan, size);//call sort
            timeVal=clock()-timeVal;
            length=timeVal/(double) CLOCKS_PER_SEC;//converting
            std::cout<<"Result: "<<length<<"\n";//prints final time value
        }
        else//prints error if not one of the five sorts
        {
            std::cout<<"Error: Unknown Sort Type.\n";
        }

    }//end random
    else if(initOrder == "ascend")
    {
        for(x=0; x < size; x++)//populate array with values in ascending order
        {
            mainStan[x]=0.001*static_cast<double>(x);
        }

        if(sortType == "bubble")//use bubble sort
        {
            timeVal=clock();
            bubbleSort(mainStan, size);//call sort
            timeVal=clock()-timeVal;
            length=timeVal/(double) CLOCKS_PER_SEC;//converting
            std::cout<<"Result: "<<length<<"\n";//prints final time value
        }
        else if(sortType == "insertion")//use insertion sort
        {
            timeVal=clock();
            insertionSort(mainStan, size);//call sort
            timeVal=clock()-timeVal;
            length=timeVal/(double) CLOCKS_PER_SEC;//converting
            std::cout<<"Result: "<<length<<"\n";//prints final time value
        }
        else if(sortType == "merge")//use merge sort
        {
            timeVal=clock();
            merge(mainStan, 0, (size/2), (size-1), tempTammy);//calls sort
            timeVal=clock()-timeVal;
            length=timeVal/(double) CLOCKS_PER_SEC;//converting
            std::cout<<"Result: "<<length<<"\n";//prints final time value
        }
        else if(sortType == "quick")//use quick sort
        {
            timeVal=clock();
            quickSort(mainStan, 0, (size-1));//call sort
            timeVal=clock()-timeVal;
            length=timeVal/(double) CLOCKS_PER_SEC;//converting
            std::cout<<"Result: "<<length<<"\n";//prints final time value
        }
        else if(sortType == "selection")//use selection sort
        {
            timeVal=clock();
            selectionSort(mainStan, size);//call sort
            timeVal=clock()-timeVal;
            length=timeVal/(double) CLOCKS_PER_SEC;//converting
            std::cout<<"Result: "<<length<<"\n";//prints final time value
        }
        else//prints error if not one of the five sorts
        {
            std::cout<<"Error: Unknown Sort Type.\n";
        }
    }//end ascend
    else if(initOrder == "descend")
    {
        for(x=0; x< size; x++)//filling array with descending values
        {
            mainStan[x]=0.001*static_cast<double>(size - x - 1);
        }

        if(sortType == "bubble")//use bubble sort
        {
            timeVal=clock();
            bubbleSort(mainStan, size);//call sort
            timeVal=clock()-timeVal;
            length=timeVal/(double) CLOCKS_PER_SEC;//converting
            std::cout<<"Result: "<<length<<"\n";//prints final time value
        }
        else if(sortType == "insertion")//use insertion sort
        {
            timeVal=clock();
            insertionSort(mainStan, size);//call sort
            timeVal=clock()-timeVal;
            length=timeVal/(double) CLOCKS_PER_SEC;//converting
            std::cout<<"Result: "<<length<<"\n";//prints final time value
        }
        else if(sortType == "merge")//use merge sort
        {
            timeVal=clock();
            merge(mainStan, 0, (size/2), (size-1), tempTammy);//calls sort
            timeVal=clock()-timeVal;
            length=timeVal/(double) CLOCKS_PER_SEC;//converting
            std::cout<<"Result: "<<length<<"\n";//prints final time value
        }
        else if(sortType == "quick")//use quick sort
        {
            timeVal=clock();
            quickSort(mainStan, 0, (size-1));//call sort
            timeVal=clock()-timeVal;
            length=timeVal/(double) CLOCKS_PER_SEC;//converting
            std::cout<<"Result: "<<length<<"\n";//prints final time value
        }
        else if(sortType == "selection")//use selection sort
        {
            timeVal=clock();
            selectionSort(mainStan, size);//call sort
            timeVal=clock()-timeVal;
            length=timeVal/(double) CLOCKS_PER_SEC;//converting
            std::cout<<"Result: "<<length<<"\n";//prints final time value
        }
        else//prints error if not one of the five sorts
        {
            std::cout<<"Error: Unknown Sort Type.\n";
        }
    }//end descend
    else//prnts error if not one of the following order types
    {
        std::cout<<"Error: Unknown Order Type.\n";
    }



    //for(x=0; x<size; x++)//deleting arrays
    //{
        delete[] mainStan;
        delete[] tempTammy;
    //}


    return(0);//end program
}//end main
