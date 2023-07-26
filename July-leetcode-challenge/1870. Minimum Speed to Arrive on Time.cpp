class Solution {
private:
    // Helper function to check if it is possible to complete the journey with a given speed within the target time (hour)
    int isValid(vector<int> &dist, int speed, double hour) {
        double time = 0; // Initialize the total time taken to complete the journey
        for(int i=0; i<dist.size(); i++) {
            time = ceil(time); // Round up the time to the nearest integer (this ensures the driver waits for the next hour if needed)
            time += (double)dist[i] / speed; // Calculate the time taken to travel the current distance at the given speed
            if(time > hour) return false; // If the total time exceeds the target hour, return false (journey cannot be completed within the target time)
        }
        return true; // If the loop finishes without returning false, it means the journey can be completed within the target time with the given speed
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1, right = 1e9; // Initialize the search space for the speed using binary search
        while(left <= right) {
            long long mid = left + (right - left)/2; // Calculate the mid-point of the current search space
            if(isValid(dist, mid, hour)) {
                right = mid - 1; // If it's possible to complete the journey with the current speed, update the right boundary to search for a lower speed
            }
            else {
                left = mid + 1; // If it's not possible to complete the journey with the current speed, update the left boundary to search for a higher speed
            }
        }
        return left > 1e9 ? -1 : left; // If the loop finishes without finding a valid speed, return -1; otherwise, return the minimum valid speed
    }
};
