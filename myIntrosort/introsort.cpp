#include <iostream>

//includes all necesarry algorithms for introsort
namespace is
{
    //returns lower integer of log n base 2
    int log2(const int& n)
    {
        if(n > 1) return 1 + log2(n/2);
        return 0;
    }
    //for coping contents of A to B and B to A
    void swap(int &A, int &B)
    {
        int temp = A;
        A = B;
        B = temp;
    }

    //function to perform insertion sort on array a from index begin to end
    void insertionSort(int *arr,const int &begin,const int &end)
    {
        //assume element at begin index is sorted
        //start from index begin+1 ... to end
        for(int i=begin+1, temp, j; i <= end; i++)
        {
            temp = arr[i];
            j=i;
            //find a position for temp by moving numbers greater to the right
            while(j>begin && (temp < arr[j-1]))
            {
                arr[j] = arr[j-1];
                j--;
            }
            //copy temp to a sorted position in a subarray from index begin..i
            arr[j] = temp;
        }
    }
    //inserts a node in a heap so that the node not less than child nodes
    void arrangeInMaxHeap(int *arr,const int &node,const int& begin,const int& end)
    {
        int child = (((node-begin)+1) * 2)-1;
        //check if array not excided
        if(child > end) return;

        //get the index of greatest of the parent node and the child nodes
        int temp = node;
        if(arr[node] < arr[child]) temp = child;
        //also check if parent has right child
        if(((child+1) <= end)&& (arr[temp] < arr[child+1]))
                temp = child+1;
        if(temp != node)
        {
            swap(arr[node],arr[temp]);
            arrangeInMaxHeap(arr,temp,begin,end);
        }
    }
    //finds the index of the last parent node in the subarray
    //iteriate from last node to begin node to create a max heap
    void heapify(int * arr,const int& begin,const  int& end)
    {
        //subarray has atleast a parent node
        if (begin == end) return;
        
        //find the last parent node
        //go through all the parent nodes and arrenge them to create max heap
        for(int node = begin - 1 + ((end - begin + 1)/2); node >=begin ; node--)
        {
            arrangeInMaxHeap(arr,node,begin,end);
        }
    }
    //sorts a max heap
    void sortHeap(int *arr,const int& begin,const int& end)
    {
        while(end > begin)
        {
            swap(arr[begin],arr[end]);
            int newEnd = end-1;
            arrangeInMaxHeap(arr,begin,begin,newEnd);
        }
    }
    void heapSort(int *arr,const int& begin,const int& end)
    {
        heapify( arr, begin, end);
        sortHeap( arr, begin, end);
    }
    //using hoare's partition
    //partition a given array so that all numbers to the left
    //of th partion is less than the value of the partition
    //and all those to its right are greater
    int partition(int *arr,const int& begin,const int& end)
    {
        int tempEnd = end;
        //select value of middle index as pivot
        swap(arr[begin],arr[begin+((tempEnd-begin)/2)]);
        int start = begin+1;
        //find the sorted position for pivot value
        while(start <= tempEnd)
        {
            if((arr[start] > arr[begin]) && (arr[tempEnd] <= arr[begin]))
                {
                    swap(arr[start++],arr[tempEnd--]);
                }
            while(arr[start] <= arr[begin] && start <= tempEnd) start++;
            while(arr[tempEnd] > arr[begin] && start <= tempEnd) tempEnd--;
        }
        swap(arr[begin],arr[tempEnd]);
        return tempEnd;
    }
    //hybrid of 3 sorts
    void introSortInterface(int * arr,const int begin,const int end,const int& depth)
    {
        if(end <= begin) return;
        //sort with insertion sort if there are 16 or less elements
        if(end < (begin+15))
        {
            insertionSort(arr,begin,end);
        }
        //sort with heap sort when depth excedes 2 * log2(n)
        else if(depth == 0)
        {
            heapSort(arr,begin,end);
        }
        //else sort using quick sort
        else
        {
            int splitIndex = partition(arr, begin, end);
            introSortInterface(arr,splitIndex+1,end,depth-1);
            //check partiton value has similar values to its left
            while(arr[splitIndex] == arr[splitIndex-1]&&(splitIndex > begin)) splitIndex--;
            introSortInterface(arr, begin, splitIndex-1,depth-1);
        }
    }
    //intro sort from begin index to end index
    void introSort(int *arr,const int &begin,const int &end)
    {
        //to avoid worst case scenario, sex max depth to use quick sort
        int controlDepth = 2 * is::log2(end-begin+1);
        introSortInterface(arr, begin, end, controlDepth);
    }

}






