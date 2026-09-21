class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        answer = [0] * k
        ending_here = [0] * k

        for value in nums:
            updated = [0] * k
            updated[value % k] += 1
            for rem, cnt in enumerate(ending_here):
                if cnt:
                    updated[(rem * value) % k] += cnt
            ending_here = updated
            for rem in range(k):
                answer[rem] += ending_here[rem]

        return answer