class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = 30.0 * hour + 0.5 * minutes;
        double minuteAngle = 6.0 * minutes;
        double angleDifference = abs(hourAngle - minuteAngle);
        return min(angleDifference, 360.0 - angleDifference);
    }
};