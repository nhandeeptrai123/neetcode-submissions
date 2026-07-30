class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0]; 
        //cho rùa và thỏ cùng ở vạch xp

        do {
            slow = nums[slow]; //rùa nhảy 1 bước
            fast = nums[nums[fast]]; //thỏ nhảy 2 bước
        }
        while (slow != fast);

        //sau bước này thì fast đã tới vị trí xuất hiện trùng lặp
        //ta sẽ cho rùa về lại vị trí xuất phát ban đầu để tìm vị trí bắt đầu lặp
        slow = nums[0];
        while (slow != fast) {
            //ở bước này thì thỏ và rùa đều cùng đi 1 bước thôi
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
