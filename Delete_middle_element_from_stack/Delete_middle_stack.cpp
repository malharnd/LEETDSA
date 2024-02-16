#include <bits/stdc++.h> 


void solve(stack<int>&inputStack, int N,int count ){

   //base case
   if(count == N/2){
      inputStack.pop();
      return;
   }

   int top = inputStack.top();
   inputStack.pop();

   //recursion
   solve(inputStack,N,count+1);

   //
   inputStack.push(top);


}
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count = 0;
   solve(inputStack,N,count);
}