/*Problem 01*/
class Solution {
public:
    bool isValid(string s) {
        stack<char>stack;
        for(int i=0;i<s.length();i++)
        {
           if(s[i]=='('||s[i]=='{'||s[i]=='[')
           {
               stack.push(s[i]);
           }
           else
           {
               if(stack.empty()) return false; 
                if(s[i] == ')' && stack.top() != '(') return false;
                if(s[i] == '}' && stack.top() != '{') return false;
                if(s[i] == ']' && stack.top() != '[') return false;
                stack.pop();
           }
         }
          return stack.empty();
    }
   
};
/*problem 02*/
class MinStack {
public:
int size;
int capacity;
stack <int> DSV,min;
    MinStack() {
    }
    
    void push(int val) {
        DSV.push(val);
        if(min.empty()||val<=min.top())
        {
            min.push(val);
        }
    }
    
    void pop() {
     if(min.top()==DSV.top())
     {
         min.pop();
     }
     DSV.pop();
    }
    
    int top() {
     return  DSV.top();
    }
    
    int getMin() {
      return min.top();
    }
};
/*problem03*/
class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxLeft=height[0];
        int MaxRight=height[right];
        int water=0;
        while(left<=right)
        {
           if(height[left]<=height[right])
           {
               if(height[left]>=maxLeft)
               {
                   maxLeft=height[left];
               }
               else
               {
                   water+=maxLeft-height[left];
               }
                                   left++;
           }
           else
           {
               if(height[right]>=MaxRight)
               {
                   MaxRight=height[right];
               }
               else
               {
                   water+=MaxRight-height[right];
               }
                   right--;
           }
        }return water;
    }
};
/*problem 05*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int leftMax=0;
        int left=0,maxx=0;
        int right=height.size()-1;
        int water=0;
       while(left<=right)
        {
            int dif=right-left;
            int minn=min(height[left],height[right]);
            maxx=max(maxx,(minn*dif));
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
            return maxx;
    }
};
/*problem 04*/
 string decodeString(string s) {
        stack<string>str;
        stack<int>count;
        string ans="";
        int num=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                num=10*num+s[i]-'0';
            }
            else if(s[i]=='[')
            {
                str.push(ans);
                ans="";
                count.push(num);
                num=0;
            }
            else if(s[i]==']')
            {
                string temp=ans;
               ans=str.top();
               str.pop();
               int times=count.top();
               count.pop();
               while (times--){
                   ans+=temp;
               }
            }
            else
            {
                ans+=s[i];
            }
        }
        return ans;
    }
    /*problem 06*/
    class MyStack {
public:
 queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int v=q.size()-1;
        int i=0;
        while(i<v)
        {
            q.push(q.front());
            i++;
            q.pop();
        }
    }
    
    int pop() {
        int p=q.front();
        q.pop();
        return p;
    }
    
    int top() {
         return q.front();  
    }
    
    bool empty() {
        return q.size()==0;
    }
};
/*problen 07*/
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int i=0,count=0,j=0,n=students.size()-1;
        queue<int>dq;
        for(int i=0;i<=students.size()-1;i++)
        {
            dq.push(students[i]);
        }
        while(!dq.empty()&&j<n*n)
        {
            if(dq.front()==sandwiches[i])
            {
                i++;
                dq.pop();
            }
            else
            {
                int t=dq.front();
                dq.pop();
                dq.push(t);
            }
            j++;
        }
        if(dq.empty())return 0;
        else return dq.size();
    }
};
/*problem 08*/
class FrontMiddleBackQueue {
public:
deque<int> dq;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        dq.push_front(val);
    }
    
    void pushMiddle(int val) {
        int m=dq.size()/2;
        auto it=dq.begin();
        it=it+m;
        dq.insert(it,val);
    }
    
    void pushBack(int val) {
        dq.push_back(val);
    }
    
    int popFront() {
        if(dq.empty())
        {
            return-1;
        }
        int k=dq.front();
        dq.pop_front();
        return k;
    }
    
    int popMiddle() {
        if(dq.empty())
        {
            return-1;
        }
        int m=dq.size()/2;
        if(dq.size()%2==0)
        {
            m--;
        }
        auto it= dq.begin();
        it=it+m;
        int k= *it;
        dq.erase(it);
        return k;
    }
    
    int popBack() {
        if(dq.empty())
        {
            return-1;
        }
        int k=dq.back();
        dq.pop_back();
        return k;
    }
};
/*PRONLEM 09*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSubarrySum=INT_MAX,preMinSum=0;
        int totalSum=0;
        int maxSubarraySum=INT_MIN,preMaxSum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]+preMinSum>0)
            {
                preMinSum=0;
            }
            else
            {
                preMinSum+=nums[i];
            }
            minSubarrySum=min(minSubarrySum,preMinSum);
            if(nums[i]+preMaxSum<nums[i])
            {
                preMaxSum=nums[i];
            }
            else
            {
                preMaxSum+=nums[i];
            }
            maxSubarraySum=max(maxSubarraySum,preMaxSum);
            totalSum+=nums[i];
        }
        if(minSubarrySum==0)
        {
            return totalSum;
        }
        if(totalSum==minSubarrySum)
        {
            return maxSubarraySum;
        }
        return max(totalSum-minSubarrySum,maxSubarraySum);
    }
};
/*problm 10*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int> ans;

        for(int i=0;i<asteroids.size();i++){
            
            if(asteroids[i]>0||ans.empty())
                ans.push_back(asteroids[i]);
            else {
                while(!ans.empty()&&ans.back()>0 &&ans.back()<abs(asteroids[i])){
                    ans.pop_back();
                }
               if(!ans.empty()&& ans.back()==abs(asteroids[i]))
                    ans.pop_back();
            
            else{
                 if(ans.empty()||ans.back()<0)
                ans.push_back(asteroids[i]);
            } 
        }
    }
    
        return ans;
    }
};