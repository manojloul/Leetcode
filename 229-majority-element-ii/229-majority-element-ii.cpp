class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
      int num1=-1,num2=-1,c1=0,c2=0;

   for(int i=0;i<arr.size();++i)
   {
       if(num1==arr[i]) c1++;
       else if(num2==arr[i]) c2++;
       else if(c1==0)
       {
           num1=arr[i];
           c1=1;
       }
       else if(c2==0)
       {
           num2=arr[i];
           c2=1;
       }
       else
       {
           c1--;
           c2--;
       }
   }
cout<<num1<<" "<<num2<<endl;
   c1=0,c2=0;
   for(int i=0;i<arr.size();++i)
   {
       if(num1==arr[i]) c1++;
       else if(num2==arr[i]) c2++;
   }
   
   if(c1>arr.size()/3 && c2>arr.size()/3) return {num1,num2};
   else if(c1>arr.size()/3) return {num1};
   else if(c2>arr.size()/3) return {num2};
   return {};
    }
};