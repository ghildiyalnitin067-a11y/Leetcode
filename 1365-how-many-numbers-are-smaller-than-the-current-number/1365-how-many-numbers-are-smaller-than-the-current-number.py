class Solution:
    def smallerNumbersThanCurrent(self, nums):
        order = sorted(range(len(nums)), key=lambda i: nums[i])
        answer = [0] * len(nums)

        for place, idx in enumerate(order):
            if place > 0 and nums[idx] == nums[order[place - 1]]:
                answer[idx] = answer[order[place - 1]]
            else:
                answer[idx] = place

        return answer