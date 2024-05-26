/*problem 01 */
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vect(nums.size(), 0);
        for(int i=0;i<=nums.size()-1;i++)
        {
                    int count =0;
            for(int j=0;j<=nums.size()-1;j++)
            {
                if(nums[i]>nums[j])
                {
                    count++;
                }
            }
            vect[i]=count;
        }
        return vect;
    }
    /*problem02*/
     int removeElement(vector<int>& nums, int val) {
        int j=0,i=nums.size()-1,count=0;
        while(j<=i)
        {
        if(nums[j]==val)
        {
            nums[j]=nums[i--];
        }
        else
        {
            j++;
            count++;
        }
        }
        return count;
    }
    /*problem03*/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) 
        return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int start=0;
        int end=(m*n)-1;
        while(start<=end)
        {
             int mid =start+ ((end-start)/2);
              int row=mid/n;  
          int col=mid%n;    
              if(matrix[row][col]==target)
              { 
                  return true;
              } 
              else if(matrix[row][col]<target)
              {
                  start=mid+1;
              }
              else
              {
                  end=mid-1;
              }
        }
        return false;
    }
    /*problem04*/
    int removeDuplicates(vector<int>& nums) {
        int j=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=nums[j])
            {
                j++;
                nums[j]=nums[i];
                
            }
        }
        return j+1;
    }
    /*problem 5*/
    int maxSubArray(vector<int>& nums) {
          int sum=0;
          int ans=nums[0];
          for(int i=0;i<nums.size();i++)
          {
              sum= sum+nums[i];
          ans=max(ans,sum);
          if(sum<0)
          {
              sum=0;
          }
          }
        return ans;
    }
    /*problem 6*/
    int firstBadVersion(int n) {
        int  minBadVersion=0;
        int start=0;
        int end=n;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(isBadVersion(mid))
            {
                minBadVersion=mid;
                end=mid-1; 
            }
            else
            {
                start=mid+1;
            }
        }
        return minBadVersion;
    }
    /*problem 7*/
    int firstMissingPositive(vector<int>& nums) {
        set<int> data;
        int n=nums.size();
        for(int x=0;x<n;x++)
        {
            data.insert(nums[x]);
        }
        int i=1;
        while(i<=n)
        {
            if(data.find(i)!=data.end()) i++;
            else return i;
        }
        return i;
    }
    