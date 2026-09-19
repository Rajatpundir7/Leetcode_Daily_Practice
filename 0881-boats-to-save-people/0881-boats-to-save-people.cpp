class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();

        int left = 0;
        int right  = n-1;
        int count =0;
       /* for(int i =0;i<n;i++){
            sum += people[i];
            if(sum > limit){
                sum = 0;
                count++;
                sum += people[i];
            }
        }*/
        while(left <= right){
            if(people[left] + people[right] <= limit){
                left++;


            
            }
            right--;
            count++;
        }

        return count;
    }
};