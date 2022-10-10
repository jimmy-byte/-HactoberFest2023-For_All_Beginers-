    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i = 0 , j = 0;
        int curr = 0;
        
        while(k > 0){
            if(i<n && j<m){
                if(arr1[i] < arr2[j]){
                    curr = arr1[i];
                    i++;
                }
                else{
                    curr = arr2[j];
                    j++;
                }
            }
            else{
                if(i<n){
                    curr = arr1[i];
                    i++;
                }
                if(j < m){
                    curr = arr2[j];
                    j++;
                }
            }
            k--;
        }
        
        return (long)curr;
    
    }
    
};

/***********************geeksforgeeks problem link - https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1***********/
