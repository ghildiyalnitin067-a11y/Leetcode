class Solution:
    def minSumOfLengths(self, arr: list[int], target: int) -> int:
        n = len(arr)
        best = [float('inf')] * n 
        ans = float('inf') 
        left = 0
        curr_sum = 0 
        for right in range(n):
            curr_sum += arr[right]
            while curr_sum > target:
                curr_sum -= arr[left]
                left += 1
            if curr_sum == target:
                curr_len = right - left + 1
                if left > 0 and best[left - 1] != float('inf'):
                    ans = min(ans, curr_len + best[left - 1])
                best[right] = min(best[right - 1] if right > 0 else float('inf'), curr_len)
            else:
                best[right] = best[right - 1] if right > 0 else float('inf')
        return ans if ans != float('inf') else -1