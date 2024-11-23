#include <iostream>
#include <string>

using namespace std;

// write a function to print the contents of your array
//   bonus! try to implement your function so that it can accept
//     many types of data (int, char, string, etc.)
template <typename flexibleType> // ???
void printArray(flexibleType arr[], int n) {
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Implement a sequential search algorithm
// your function should search for a target value (target)
//    within the indices of "start" to "end"
// return true if target exists in the array within this range,
//    return false otherwise
bool seqSearch(string target, string arr[], int start, int end) {
    for(int i = start; i <= end; i++){
        if(arr[i] == target){
            return true;
        }
      
    }
    return false; //target is not in array
}

// Implement an iterative binary search 
// Return true if target exists in the array with size n,
//    return false otherwise 
bool binSearch(float target, float arr[], int n) {
    int left = 0;
    int right = n-1;

   while(left<=right){
    int mid = left +(right-left)/2;

    if(arr[mid] == target){
        return true;
    }else if(arr[mid]< target){
        left = mid+1;
    }else{
        right = mid -1;
    }
    
    }
return false;	
}
// Implement a recursive binary search 
// Return true if target exists in the array with size n
//   return false otherwise
bool binSearchR(char target, char charray[], int n) {
    //base 
    //find middle
    
    if(n<=0){
        return false; //the array is empty
    }
    int mid = n/2;
    
     if(target == charray[mid]){
        return true; 
    }

    //recursive
     //if target is greater the middle, search the "right"
  
    if(target> charray[mid]){
       // char *start = &charray[mid+1];
        return binSearchR(target, charray + mid +1, n-mid-1);
    //if target is greater the middle, search the "right"

    //if target is smaller than middle, search the "left"
    }
      return binSearchR(target, charray, mid);
    
}

// Implement a brand new sorting algorithm
//    Don't use a reference for this!
//    Be sure to do your best to implement the algorithm's logical steps
// Step 1: implement a function swap() that will swap any two elements in an array,
//          given their indices
// Step 2: implement a function minFind() that will find and return 
//          the **index** of the smallest element in an array
/*
Step 3: Finally, use your two functions above to complete the following in newSort():
        1 - search through the array to find the location of the smallest value
        2 - swap this value with the value at the start of the array
        3 - the first element is now sorted! 
            Redo your sort on the remaining elements (from index 1 to end)
            On the next iteration, you should be swapping the smallest remaining value 
                with the second index value in the array
            ...then swapping the smallest remaining value with the third indexed value... etc.
            
        4 - continue iterating until you reach the end of the list
        *** You can make this recursive, if you wish!
*/

// Step 1: implement a function swap() that will swap any two elements in an array,
//          given their indices
void swap(double darray[], int index1, int index2) {
    double temp = darray[index1]; // copy first number to temp
    darray[index1] = darray[index2]; // copy 2nd number to first index
    darray[index2] = temp; // copy temp value(index1) to index 2
}

// Step 2: implement a function minFind() that will find and return 
//          the **index** of the smallest element in an array

int minFind(double darray[], int length) {
  
    int smallest = 0;
    for(int i = 1; i < length; i++){
        if(darray[smallest]>darray[i]){
            smallest = i; //update smallest to be i(the smaller value in this case)
        }
    
    }
    return smallest;
}

// Step 3: Finally, use your two functions above to complete the following in newSort():
//         1 - search through the array to find the location of the smallest value
//         2 - swap this value with the value at the start of the array
//         3 - the first element is now sorted! 
//             Redo your sort on the remaining elements (from index 1 to end)
//             On the next iteration, you should be swapping the smallest remaining value 
//                 with the second index value in the array
//             ...then swapping the smallest remaining value with the third indexed value... etc.
            
//         4 - continue iterating until you reach the end of the list
//         *** You can make this recursive, if you wish!
// */

void newSort(double darray[], int n) {
    //BASE
  
    if(1>= n){
        return;
    }

    //recursive
        //find index of smallest element
    int smallest = minFind(darray,n);

    //swap smallest element with first index
    swap(darray, 0, smallest);
    newSort(darray +1,n -1); // increment array index to next one and length to be one less
  
}
