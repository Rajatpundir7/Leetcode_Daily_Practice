class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        /*
        brute force approch 
        linear search 
        step  1 :  i -> 0 to n;
        step 2 if arr[i] > arr[i+1] return i

        */
        /*
        optimimsed approch - > 
        binary search 
        step 1 : low = 0 , high = n-1 

        */
        int n = arr.size();
        int low = 0 , high = n-1;
        int ans = 0;
        while(low < high ){
            int mid = low + (high - low )/2;
            if(arr[mid] > arr[mid+1]){
                ans = mid ;
                high = mid;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }
};