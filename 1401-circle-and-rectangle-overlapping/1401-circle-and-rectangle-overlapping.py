class Solution(object):
    def checkOverlap(self, radius, xCenter, yCenter, x1, y1, x2, y2):
        """
        :type radius: int
        :type xCenter: int
        :type yCenter: int
        :type x1: int
        :type y1: int
        :type x2: int
        :type y2: int
        :rtype: bool"""
        magnetX = max(x1, min(xCenter, x2))
        magnetY = max(y1, min(yCenter, y2))

        gapX = xCenter - magnetX
        gapY = yCenter - magnetY

        return gapX * gapX + gapY * gapY <= radius * radius