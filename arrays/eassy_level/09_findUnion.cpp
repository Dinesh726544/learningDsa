




Input: 

n1 = 5, arr1[] = {1, 2, 3, 4, 5}  
n2 = 5, arr2 [] = {1, 2, 3, 6, 7}

Output: 
1 2 3 4 5 6 7












by using set :--
the overall time complexity of the provided function is O(n log n), where n is the total 
number of elements in vectors a and b.

EXTRA SPACE COMPLEXITY : O(K) WHERE K IS THE NO OF UNIQUE ELEMENTS. 

#include <bits/stdc++.h>

vector < int > sortedArray(vector < int > a, vector < int > b) {
    // brute approach
    set<int> st;
    
    for(int i=0;i<a.size();i++)
    {
        st.insert(a[i]);
    }
    for(int i=0;i<b.size();i++)
    {
        st.insert(b[i]);
    }
    vector<int> result(st.begin(), st.end()); // Convert set to vector
    
    return result;
}




WE CAN USE unordered_map TO DECREASE THE TIME COMPLEXITY TO O(N)



optimal solution :--
time complexity of the function is O(n1 + n2), where n1 is the size of vector a and
n2 is the size of vector b. 

EXTRA SPACE COMPLEXITY : O(K) WHERE K IS THE NO OF UNIQUE ELEMENTS. 

#include <bits/stdc++.h>

vector < int > sortedArray(vector < int > a, vector < int > b) {
   vector<int> unionArr;
   int n1= a.size();
   int n2 = b.size();
   int i=0;
   int j=0;
   while(i<n1 && j<n2)
   {
       if(a[i] <= b[j])
       {
           if(unionArr.empty() || unionArr.back() != a[i])
           {
               unionArr.push_back(a[i]);
           }
           i++;
       }
       else
       {
           if(unionArr.empty() || unionArr.back() != b[j])
           {
               unionArr.push_back(b[j]);
           }
           j++;
       }
   }

   while(i<n1)
   {
       if(unionArr.back() != a[i])
       {
           unionArr.push_back(a[i]);
       }
       i++;
   }

   while(j<n2)
   {
       if(unionArr.back() != b[j])
       {
           unionArr.push_back(b[j]);
       }
       j++;
   }
   return unionArr;
}