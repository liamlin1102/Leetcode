# 把0往右移，兩個做法
# 方法1，遍歷，我們假設0的指數在0的位置(不管他是不是0)，反正我就下去裡面找，找到任何非0的數值都跟0指針交換位置，並且把0指針加1，如果遇到0那就啥都不幹，這樣可以確保0指針留在並跟下個數字交換
class Solution:
# in-place
    def moveZeroes(self, nums):
        # 假設0指針在0的位置
        zero_index = 0  # records the position of "0"
        for index in range(len(nums)):
            # 如果數字是非0，那我就交換位置並且讓0指針加1
            # 會有兩種情況，第一個數字是0，第一個不是
            # ex1: [0,1,0,0,4,3],ex2:[2,0,0,1,4,6]
            # 迴圈1,此時ex1不進入判斷式，zero_index=0,index=1,[0,1,0,0,4,3],ex2進入判斷式2跟2換位置(因為zero_index,index相同),zero_index=1,index=1,[2,0,0,1,4,6] 
            # 迴圈2,ex1進入判斷式，zero_index=1,index=2,[1,0,0,0,4,3] ex2不進入判斷式，zero_index=1,index=2,[2,0,0,1,4,6] 
            # 迴圈3,ex1不進入,zero_index =1 ,index=3,[1,0,0,0,4,3],ex2不進入判斷式圈,zero_index=1,index=3,[2,0,0,1,4,6] 
            # 迴圈4,ex1不進入,zero_index =1 ,index=4,[1,0,0,0,4,3],ex2進入判斷式,zero_index=2,index=4,[2,1,0,0,4,6] 
            # 迴圈5,ex1進入判斷,zero_index =2 ,index=5,[1,4,0,0,0,3],ex2進入判斷式,zero_index=3,index=5,[2,1,4,0,0,6] 
            # 迴圈6,ex1進入判斷,zero_index =3 ,index=6,[1,4,3,0,0,0],ex2進入判斷式,zero_index=4,index=6,[2,1,4,6,0,0] 
            if nums[index] != 0:
                nums[index], nums[zero_index] = nums[zero_index], nums[index]
                zero_index += 1



# 比較直觀
# 方法2快慢指針
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        zero_index = 0 ;nozero_index=1
        for index in range(len(nums)-1):
            if nums[zero_index]==0 and nums[nozero_index]!=0:
                nums[zero_index],nums[nozero_index] = nums[nozero_index],nums[zero_index]
            if nums[zero_index]!=0:
                zero_index+=1
            nozero_index+=1
        return nums