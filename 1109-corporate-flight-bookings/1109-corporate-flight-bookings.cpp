class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>totalseats(n+2,0);
        /*for(int i =0 ; i< bookings.size() ;i++){
            int first = bookings[i][0];
            int last  = bookings[i][1];
            int seats = bookings[i][2];

            for(int j =  first ; j<= last;j++){
                totalseats[j-1] += seats;
            }
        }
        return totalseats;*/
        for(int i =0 ;i < bookings.size();i++){
             int first = bookings[i][0];
            int last  = bookings[i][1];
            int seats = bookings[i][2];
            totalseats[first] += seats;
            totalseats[last+1] -= seats;
        }
        vector<int>result;
        int cumSum = 0;
        for(int i = 1; i<=n; i++){
            cumSum += totalseats[i];
            result.push_back(cumSum);
        }
        return result;

    }
};