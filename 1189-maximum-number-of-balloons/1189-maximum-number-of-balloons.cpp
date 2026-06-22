class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(5,0);
        int n =  text.length();
        for(int i =0 ;i < n ;i++ ){
            if(text[i] == 'b') freq[0]++;
            else if(text[i] == 'a')freq[1]++;
            else if(text[i] == 'l')freq[2]++;
            else if(text[i] == 'o')freq[3]++;
            else if(text[i] == 'n')freq[4]++;

        }
        freq[2] /=2 ;
        freq[3] /= 2;
        return *min_element(freq.begin(),freq.end());

    }
};