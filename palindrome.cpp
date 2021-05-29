#include <iostream>

template <typename t>
int findPalindromeAtIndex(t *arr, int index, int lengthOfArray) {
    bool someCondition = true;
    int beginIndex = index;
    int endIndex = index;
    int lengthOfPalindrome = 1;
    while(someCondition) {
        beginIndex--;
        endIndex++;
        someCondition = (beginIndex >= 0 && endIndex < lengthOfArray);
        someCondition = someCondition && arr[beginIndex] == arr[endIndex];
        if (someCondition) {
            lengthOfPalindrome += 2;
        }
    }
    return lengthOfPalindrome;
}


template <typename t>
// sencond index is = firstIndex + 1;
int findPalindromeBetweenIndexex(t *arr, int firstIndex, int lengthOfArray) {
    if (firstIndex+1 >= lengthOfArray){
        return 0;
    }
    
    bool someCondition = true;
    int beginIndex = firstIndex;
    int endIndex = firstIndex + 1;;
    if (arr[beginIndex] != arr[endIndex]){
        return 0;
    }
    int lengthOfPalindrome = 2;
    while(someCondition) {
        beginIndex--;
        endIndex++;
        someCondition = (beginIndex >= 0 && endIndex < lengthOfArray);
        someCondition = someCondition && arr[beginIndex] == arr[endIndex];
        if (someCondition) {
            lengthOfPalindrome += 2;
        }
    }
    return lengthOfPalindrome;
}

template <typename t>
    //// solve this used indexes only// no for loops
int findLongestPalindrome(t *array,int lengthOfArray){
    int longestPal = 0;
    int currentPal = 0;
    int indexThroughArray = 0;
    while(indexThroughArray < lengthOfArray){
        currentPal = findPalindromeAtIndex(array,indexThroughArray,lengthOfArray);
        // std::cout << "Currrent  palindrome at index " << indexThroughArray << " is " << currentPal << std::endl;
        if (currentPal > longestPal) {
            longestPal = currentPal;
        }
        currentPal = findPalindromeBetweenIndexex(array,indexThroughArray,lengthOfArray);
        // std::cout << "Currrent  palindrome after index " << indexThroughArray << " is " << currentPal << std::endl;
        if (currentPal > longestPal) {
            longestPal = currentPal;
        }
        indexThroughArray++;
    }
    return longestPal;
}



int main(){
            //   1,2,3,4,5,6,7,8,9,10
    int arr[] = {1,3,1,4,1,3,3,1,4,1};
    std::cout << "longest  palindrome in this array is " << findLongestPalindrome<int>(arr,10) << std::endl;
}