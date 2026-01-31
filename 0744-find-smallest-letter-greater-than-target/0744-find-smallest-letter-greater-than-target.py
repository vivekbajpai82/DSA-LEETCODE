class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        left=0
        right=len(letters)-1
        while left<=right:
            mid=(left+right)//2
            if letters[mid]==target:
                for i in range(mid+1,len(letters)):
                    if letters[i]>target:
                        return letters[i]
                return letters[0]
            elif letters[mid]<target:
                left=mid+1
            else:
                right=mid-1
        for i in range(len(letters)):
            if letters[i]>target:
                return letters[i]
        return letters[0]

