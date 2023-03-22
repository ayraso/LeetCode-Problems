class Solution {
public:
    int rotatedDigits(int n) {
        // valid digits representation
        std::unordered_map<int, int> validDigits;
        validDigits.insert(make_pair(0,0));
        validDigits.insert(make_pair(1,1));
        validDigits.insert(make_pair(2,5));
        validDigits.insert(make_pair(5,2));
        validDigits.insert(make_pair(6,9));
        validDigits.insert(make_pair(8,8));
        validDigits.insert(make_pair(9,6));
        // counter for the number of good numbers
        int numOfGoods = 0;

        for(int i=n; i>=2; i--){
            // find the number of digits
            int j=i;
            std::stack<int> digits; // representing the number of digits with a FIFO queue.
            while(j>0){
                digits.push(j % 10);
                j = (int)(j / 10);
            }
            bool rotateCheck = true;
            // digit check
            int rotatedNumber = 0;
            while(!digits.empty()){
                int digit = digits.top();
                auto it = validDigits.find(digit);
                if(it == validDigits.end()){
                    rotateCheck = false;
                    break;
                }
                else{
                    rotatedNumber += (std::pow(10, digits.size()-1) * validDigits.at(digit));
                    digits.pop();
                }
            }
            // rotated number check
            if(rotateCheck==true && i!=8){
                if(i!=rotatedNumber) numOfGoods++;
            }
        }

        return numOfGoods;
    }
};