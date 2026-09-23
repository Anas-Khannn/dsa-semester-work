/*
===========================================================

LAB 02 - WEEK 02
ARRAY OPERATIONS & DYNAMIC ARRAYS

Tasks:
Traversal, Insertion, Deletion, Copy, Merge,
Reverse, Resize, Dynamic Inventory Manager

Student Name: Anas Khan
Registration No: 25PWCS1691
Section: B
Instructor: Sir Mudasir
Lab Date: 24/09/2026

===========================================================
*/

#include <iostream>
using namespace std;


// ================= TRAVERSAL TOOLKIT =================

void displayArray(const int* a, int size)
{
    cout << "[ ";

    for(int i = 0; i < size; i++)
        cout << a[i] << " ";

    cout << "]";
}


int sum(const int* a, int size)
{
    int total = 0;

    for(int i = 0; i < size; i++)
        total += a[i];

    return total;
}


int minValue(const int* a, int size)
{
    if(size <= 0)
        return 0;

    int mn = a[0];

    for(int i = 1; i < size; i++)
    {
        if(a[i] < mn)
            mn = a[i];
    }

    return mn;
}


int maxValue(const int* a, int size)
{
    if(size <= 0)
        return 0;

    int mx = a[0];

    for(int i = 1; i < size; i++)
    {
        if(a[i] > mx)
            mx = a[i];
    }

    return mx;
}


int countEven(const int* a, int size)
{
    int count = 0;

    for(int i = 0; i < size; i++)
    {
        if(a[i] % 2 == 0)
            count++;
    }

    return count;
}



// ================= INSERTION =================


bool insertAt(int* a, int& size, int capacity, int pos, int value)
{

    if(pos < 0 || pos > size || size == capacity)
        return false;


    // Shift elements right to left
    for(int i = size; i > pos; i--)
    {
        a[i] = a[i-1];
    }


    a[pos] = value;

    size++;

    return true;
}



// ================= DELETION =================


bool deleteAt(int* a, int& size, int pos)
{

    if(pos < 0 || pos >= size)
        return false;


    // Shift elements left
    for(int i = pos; i < size-1; i++)
    {
        a[i] = a[i+1];
    }


    size--;

    return true;
}



// ================= REVERSE =================


void reverseInPlace(int* a, int size)
{

    int left = 0;
    int right = size-1;


    while(left < right)
    {

        int temp = a[left];

        a[left] = a[right];

        a[right] = temp;


        left++;
        right--;

    }

}



// ================= DEEP COPY =================


int* deepCopy(const int* source, int size)
{

    int* copy = new int[size];


    for(int i = 0; i < size; i++)
    {
        copy[i] = source[i];
    }


    return copy;
}



// ================= MERGE =================


int* mergeArrays(const int* a, int sizeA,
                 const int* b, int sizeB,
                 int& mergedSize)
{

    mergedSize = sizeA + sizeB;


    int* merged = new int[mergedSize];


    for(int i = 0; i < sizeA; i++)
        merged[i] = a[i];


    for(int i = 0; i < sizeB; i++)
        merged[sizeA+i] = b[i];


    return merged;

}



// ================= DYNAMIC ARRAY =================


struct IntBuffer
{
    int* data = nullptr;

    int size = 0;

    int capacity = 0;
};



void reserve(IntBuffer& b, int newCapacity)
{

    if(newCapacity <= b.capacity)
        return;


    int* larger = new int[newCapacity];


    for(int i = 0; i < b.size; i++)
    {
        larger[i] = b.data[i];
    }


    delete [] b.data;


    b.data = larger;

    b.capacity = newCapacity;

}



void ensureCapacity(IntBuffer& b)
{

    if(b.size < b.capacity)
        return;


    int newCapacity;


    if(b.capacity == 0)
        newCapacity = 1;

    else
        newCapacity = b.capacity * 2;


    reserve(b,newCapacity);

}




bool insertDynamic(IntBuffer& b,int pos,int value)
{

    if(pos < 0 || pos > b.size)
        return false;


    ensureCapacity(b);


    for(int i=b.size;i>pos;i--)
    {
        b.data[i]=b.data[i-1];
    }


    b.data[pos]=value;


    b.size++;


    return true;

}



bool deleteDynamic(IntBuffer& b,int pos)
{

    if(pos < 0 || pos >= b.size)
        return false;


    for(int i=pos;i<b.size-1;i++)
    {
        b.data[i]=b.data[i+1];
    }


    b.size--;


    return true;

}



bool updateAt(IntBuffer& b,int pos,int value)
{

    if(pos < 0 || pos >= b.size)
        return false;


    b.data[pos]=value;


    return true;

}



int search(IntBuffer& b,int value)
{

    for(int i=0;i<b.size;i++)
    {

        if(b.data[i]==value)
            return i;

    }


    return -1;

}



void reverseDynamic(IntBuffer& b)
{

    int left=0;

    int right=b.size-1;


    while(left<right)
    {

        int temp=b.data[left];

        b.data[left]=b.data[right];

        b.data[right]=temp;


        left++;

        right--;

    }

}



void displayBuffer(IntBuffer& b)
{

    cout<<"[ ";

    for(int i=0;i<b.size;i++)
        cout<<b.data[i]<<" ";

    cout<<"]";

}



void statistics(IntBuffer& b)
{

    if(b.size==0)
    {
        cout<<"Empty Array\n";
        return;
    }


    int total=0;

    int mn=b.data[0];

    int mx=b.data[0];

    int even=0;


    for(int i=0;i<b.size;i++)
    {

        total+=b.data[i];


        if(b.data[i]<mn)
            mn=b.data[i];


        if(b.data[i]>mx)
            mx=b.data[i];


        if(b.data[i]%2==0)
            even++;

    }


    cout<<"Sum: "<<total<<endl;

    cout<<"Minimum: "<<mn<<endl;

    cout<<"Maximum: "<<mx<<endl;

    cout<<"Even Count: "<<even<<endl;

}



void printState(IntBuffer& b)
{

    cout<<"Data: ";

    displayBuffer(b);


    cout<<"\nSize: "<<b.size;

    cout<<"\nCapacity: "<<b.capacity<<endl;

}



void destroy(IntBuffer& b)
{

    delete [] b.data;


    b.data=nullptr;

    b.size=0;

    b.capacity=0;

}



// ================= MAIN =================


int main()
{

    cout<<"===== LAB 02 ARRAY OPERATIONS =====\n";

    cout<<"Student: Anas Khan\n";

    cout<<"Registration: 25PWCS1691\n";

    cout<<"Section: B\n\n";



    // Traversal Test

    int arr[]={10,20,15,30,41,50};

    int size=6;


    cout<<"Original Array: ";

    displayArray(arr,size);


    cout<<"\nSum: "<<sum(arr,size);

    cout<<"\nMinimum: "<<minValue(arr,size);

    cout<<"\nMaximum: "<<maxValue(arr,size);

    cout<<"\nEven Count: "<<countEven(arr,size);



    // Insert

    cout<<"\n\nInsertion Example\n";


    insertAt(arr,size,10,2,99);


    displayArray(arr,size);



    // Delete

    cout<<"\n\nDeletion Example\n";


    deleteAt(arr,size,3);


    displayArray(arr,size);



    // Reverse

    cout<<"\n\nReverse Example\n";


    reverseInPlace(arr,size);


    displayArray(arr,size);



    // Deep Copy

    cout<<"\n\nDeep Copy Example\n";


    int* copy=deepCopy(arr,size);


    copy[0]=999;


    cout<<"Original: ";

    displayArray(arr,size);


    cout<<"\nCopy: ";

    displayArray(copy,size);



    delete [] copy;



    // Merge

    cout<<"\n\nMerge Example\n";


    int b[]={60,70,80};


    int mergedSize;


    int* merged=mergeArrays(arr,size,b,3,mergedSize);


    displayArray(merged,mergedSize);


    delete [] merged;



    // Dynamic Inventory Manager


    cout<<"\n\nDynamic Array Manager\n";


    IntBuffer buffer;


    insertDynamic(buffer,0,20);

    insertDynamic(buffer,1,30);

    insertDynamic(buffer,0,10);


    printState(buffer);



    cout<<"\nInsert 25 at position 2\n";


    insertDynamic(buffer,2,25);


    printState(buffer);



    cout<<"\nUpdate position 1 to 99\n";


    updateAt(buffer,1,99);


    printState(buffer);



    cout<<"\nSearch 30 Index: ";

    cout<<search(buffer,30)<<endl;



    cout<<"\nReverse Dynamic Array\n";


    reverseDynamic(buffer);


    printState(buffer);



    cout<<"\nDelete Last Element\n";


    deleteDynamic(buffer,buffer.size-1);


    printState(buffer);



    cout<<"\nStatistics\n";


    statistics(buffer);



    destroy(buffer);



    cout<<"\n\nMemory Released Successfully\n";


    return 0;
}