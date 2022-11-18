//merge sort program that show the fastest way to sort a large array of numbers

#include <iostream>


//this function sort a single array by breaking into 2 from the middle
//and handling each half like a seperate array
//note each half must be sorted
//first half: startIndex to midIndex
//second half: midIndex+1 to endIndex
void merge(int *arr,int startIndex, int endIndex,int midIndex)
{
    int indexFromStrat = startIndex;
    int indexToEnd = midIndex+1;
    
    int tempArr[(endIndex - startIndex)+1];
    int indexTempArr = 0;
    //loop starts from the top of each halp to compare values
    //then copies the smaller value to tempArr
    //after copy the next value of that half is compared
    //this is done untill any of the halves is finished 
    while((indexFromStrat <= midIndex) && (indexToEnd <= endIndex))
    {
        if(arr[indexFromStrat] < arr[indexToEnd])
        {
            tempArr[indexTempArr++] = arr[indexFromStrat++];
        }
        else
        {
            tempArr[indexTempArr++] = arr[indexToEnd++];
        }
    }
    //loop copies any values left in the first half to tempArr
    while (indexFromStrat<=midIndex)
    {
        tempArr[indexTempArr++] = arr[indexFromStrat++];
    }
    //loop copies back sorted vaules in array tempArr back array arr 
    for(int indexFromStrat = startIndex, copyIndexTempArr = 0;
             copyIndexTempArr < indexTempArr;
                indexFromStrat++,copyIndexTempArr++)
    {
        arr[indexFromStrat] = tempArr[copyIndexTempArr];
    }
}
//this function breaks down any array into small parts with only 2 elements
//then sorts and merges, repeats the process until the origil array is sorted
void mergeSort(int *arr, int startIndex, int endIndex)
{
    std::cout << "i was here merge\n";
    if(startIndex<endIndex)
    {
        int midIndex = (startIndex +((endIndex - startIndex)/2));
        mergeSort(arr,startIndex,midIndex);
        mergeSort(arr,(midIndex+1),endIndex);
        merge(arr,startIndex,endIndex,midIndex);
    }
    return;
}
void bubbleSort(int *arr, int endIndex)
{
    for(int last = endIndex; last > 0; last-- )
    {
        bool sortOccured = false;
        for(int i = 0; i < last; i++)
        {
            if(arr[i] > arr[i+1])
            {
                arr[i+1] += arr[i];
                arr[i] = arr[i+1] - arr[i];
                arr[i+1] -= arr[i];
                sortOccured = true;
            }
        }
        if(!sortOccured)
        {
            std::cout << "last: " << last << "\n";
            return;
        }
    }
}
void sort(int *arr, int endIndex)
{
    if(endIndex < 15) bubbleSort(arr, endIndex);
    else mergeSort(arr, 0, endIndex);
}