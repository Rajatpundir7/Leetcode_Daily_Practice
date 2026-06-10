class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        /*int left =0 , right = n-1;
        int score =0;
        while(k > 0){
            if(cardPoints[left] > cardPoints[right]){
                score += cardPoints[left];
                left++;
            }
            else {
                score += cardPoints[right];
                right--;
            }
            k--;
        }
        return score ;-*/

        int total =0;
        for(int i=0;i<n;i++){
            total += cardPoints[i];
        }
        if(n == k) return total;


        int curr =0;
        int window = n-k;
        int minwindow =0;
        for(int i =0; i<window;i++ ){
            curr += cardPoints[i];

        }

        minwindow = curr;

        for(int i = window ; i < n;i++){
            curr += cardPoints[i] - cardPoints[i-window];

            minwindow = min(minwindow, curr);
        }
        return total-minwindow;
    }
};