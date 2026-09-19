class Solution(object):
    def checkOverlap(self, radius, xCenter, yCenter, x1, y1, x2, y2):
        magnetX = max(x1, min(xCenter, x2))
        magnetY = max(y1, min(yCenter, y2))

        gapX = xCenter - magnetX
        gapY = yCenter - magnetY

        return gapX * gapX + gapY * gapY <= radius * radius