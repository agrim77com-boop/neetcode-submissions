class Solution {
public:
    int findDays(vector<int>& weights, int cap){

        int days = 1;
        int load = 0;

        for(int i = 0; i<weights.size();i++){

            if(weights[i]+ load > cap){

                days += 1;
                load = weights[i];
            }
            else{

                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int left = *max_element(weights.begin(), weights.end());
        int sum =0;

        for(int i =0;i<weights.size();i++){

            sum += weights[i];
        }
        int right = sum;

        while(left<=right){

            int mid = left +(right-left)/2;
            int numberOfDays = findDays(weights,mid);

            if(numberOfDays <= days){

                right = mid-1;
            }
            else{

                left = mid+1;
            } 
        }
        return left;     
    }
};