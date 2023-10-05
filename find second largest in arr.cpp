int print2largest(int arr[], int n) {
	    // code here
	    int largest=arr[0];
	    int slargest=INT_MIN;
	    
	    for(int i=1;i<n;i++){
	        if(arr[i]>largest){
	            int temp=largest;
	            largest=arr[i];
	            slargest=temp;
	        }
	        
	        else if(arr[i]<largest && arr[i]>slargest){
	            slargest=arr[i];
	        }
	    }
	   
	    if(slargest>INT_MIN){
	        return slargest;
	    }
	    else{
	        return -1;
	    }   
	}
