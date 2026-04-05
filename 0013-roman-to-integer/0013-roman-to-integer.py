class Solution(object):
    def romanToInt(self, s):

        r = {
            'I' :1,
            'V' :5,
            'X' :10,
            'L' :50,
            'C' :100,
            'D' :500,
            'M' :1000
        }
        t = 0
        for i in range(len(s) -1):
            if r[s[i]] < r[s[i+1]]:
                t -= r[s[i]]
            else:
                t += r[s[i]]
        return t + r[s[-1]]
        