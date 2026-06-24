class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>totalseats(n,0);
        for(int i =0 ; i< bookings.size() ;i++){
            int first = bookings[i][0];
            int last  = bookings[i][1];
            int seats = bookings[i][2];

            for(int j =  first ; j<= last;j++){
                totalseats[j-1] += seats;
            }
        }
        return totalseats;
    }
};