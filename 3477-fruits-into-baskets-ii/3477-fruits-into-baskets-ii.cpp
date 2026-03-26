class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        int unplaced = 0;

        for(int i =0; i< n;i++){
            bool paced = false;
            for(int j =0 ;j <n;j++){
                if(fruits[i] <= baskets[j]){
                    baskets[j] = -1;
                    paced = true;
                    break;
                }
            }
            if(paced == false){
                unplaced++;
            }
        }
        return unplaced;
    }
};