class Solution:
    def removeDuplicates(self, nums: list[int]):
        i = 0
        while i < len(nums)-1:
            if nums[i+1] == nums[i]:
                nums.pop(i+1)
                i -= 1
            i += 1
        return len(nums)


nums = [1, 1, 2]
sol = Solution()
len = sol.removeDuplicates(nums)
for num in nums:
    print(num)
