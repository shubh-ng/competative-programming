

#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;


// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(long arr[], int n, int i) 
{ 
    long smallest = i; // Initialize smalles as root 
    long l = 2 * i + 1; // left = 2*i + 1 
    long r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is smaller than root 
    if (l < n && arr[l] < arr[smallest]) 
        smallest = l; 
  
    // If right child is smaller than smallest so far 
    if (r < n && arr[r] < arr[smallest]) 
        smallest = r; 
  
    // If smallest is not root 
    if (smallest != i) { 
        swap(arr[i], arr[smallest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, smallest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(long arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 


int main() {
	// your code goes here
	// added the two lines below 
    
	long t,n,k,count;
	long arr[100000];
	cin>>t;
	while(t--){
	    count=0;
	    cin>>n>>k; --k;
	    for(int i=0; i<n; i++){
	       cin>>arr[i];
	    }
	    heapSort(arr, n);
        for(int i=0; i<n; i++){
            if(arr[i]>=arr[k])
                count++;
        }
        
        printf("%d\n", count);
	}
	return 0;
}
