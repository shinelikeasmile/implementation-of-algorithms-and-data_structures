//we need to find an element in an array of size n which occurs more than n/2 times, it is also called as majority element.
//atmost only one majority element can be present in an array.
//Algorithm :
// step 1 : find a candidate for majority element.
// step 2 : check if it is the majority element or not.
// Time complexity : O(n) 
// Space complexity : O(1)
// steps for finding candidate :
//    step 1 : initialize count of current candidate as 0 -> count = 0
//    step 2 : iterate over the array and do following steps :
//             a) if count == 0 , set the current element as candidate i.e candidate = array[i] and count = 1
//             b) else 
//                        if candidate ==  array[i]
//                           set count = count+1
//                        else 
//                           set count = count-1
