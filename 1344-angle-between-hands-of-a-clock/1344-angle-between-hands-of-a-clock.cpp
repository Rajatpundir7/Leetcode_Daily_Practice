class Solution {
public:
    double angleClock(int hour, int minutes) {
      hour %= 12;
      double hourangle = hour*30 + (minutes*0.5);
      double minangle = minutes*6;
     // hourangle = hourangle - minan
     double diff = abs(minangle - hourangle);
      return min(diff, 360-diff);
    }
};